/**
 * @file wifi_manager.c
 * @author Mubariz Ahmed (mubariz@mubariz.me)
 * @brief 	Controller for WiFi connection and event handling.
 * @version 0.1
 * @date 2025-04-09
 *
 */

/* ------------------------------------------------------ */
/*                        INCLUDES                        */
/* ------------------------------------------------------ */

#include "esp_crt_bundle.h"
#include "esp_err.h"
#include "esp_http_client.h"
#include "esp_log.h"
#include "esp_tls.h"
#include "esp_wifi.h"
#include "nvs_flash.h"
#include <stdio.h>

#include "wifi_manager.h"

/* ------------------------------------------------------ */
/*                    PRIVATE VARIABLES                   */
/* ------------------------------------------------------ */

static const char *TAG = "WIFI_MANAGER";

static EventGroupHandle_t s_wifi_event_group; // FreeRTOS event group to signal when we are connected

static int s_retry_num = 0; // Variable to track the number of connection retries

/* ------------------------------------------------------ */
/*                    PUBLIC VARIABLES                    */
/* ------------------------------------------------------ */

int8_t wifi_connected = 0; // Global variable to track WiFi connection status
esp_ip4_addr_t ip_addr;    // Variable to store the IP address

/* ------------------------------------------------------ */
/*               PRIVATE FUNCTION PROTOTYPES              */
/* ------------------------------------------------------ */

static void wifi_event_handler(void *arg, esp_event_base_t event_base,
                               int32_t event_id, void *event_data);

/* ------------------------------------------------------ */
/*                    PRIVATE FUNCTIONS                   */
/* ------------------------------------------------------ */

/**
 * @brief WiFi event handler function. Handles WiFi events such as connection, disconnection, and IP assignment.
 *
 *
 * @param arg 			unused
 * @param event_base 	WiFi event base
 * @param event_id 		WiFi event ID
 * @param event_data 	Pointer to event data
 */
static void wifi_event_handler(void *arg, esp_event_base_t event_base,
                               int32_t event_id, void *event_data) {
    if (event_base == WIFI_EVENT && event_id == WIFI_EVENT_STA_START) {
        esp_wifi_connect();
    } else if (event_base == WIFI_EVENT && event_id == WIFI_EVENT_STA_DISCONNECTED) {
        ESP_LOGI(TAG, "connect to the AP fail");
        // log the error message
        ESP_LOGI(TAG, "Reason: %d", ((wifi_event_sta_disconnected_t *)event_data)->reason);
        // if (((wifi_event_sta_disconnected_t *)event_data)->reason == WIFI_REASON_AUTH_EXPIRE) {
        //     esp_wifi_stop();
        //     wifi_init_sta();
        // }
        if (s_retry_num < ESP_MAXIMUM_RETRY) {
            esp_wifi_connect();
            s_retry_num++;
            ESP_LOGI(TAG, "retry to connect to the AP");
        } else {
            xEventGroupSetBits(s_wifi_event_group, WIFI_FAIL_BIT);
        }

        wifi_connected = 0;
    } else if (event_base == IP_EVENT && event_id == IP_EVENT_STA_GOT_IP) {
        ip_event_got_ip_t *event = (ip_event_got_ip_t *)event_data;
        ESP_LOGI(TAG, "got ip:" IPSTR, IP2STR(&event->ip_info.ip));
        ip_addr = event->ip_info.ip;
        s_retry_num = 0;
        xEventGroupSetBits(s_wifi_event_group, WIFI_CONNECTED_BIT);

        wifi_connected = 1;
    }
}

/* ------------------------------------------------------ */
/*                    PUBLIC FUNCTIONS                    */
/* ------------------------------------------------------ */

/**
 * @brief Initialize WiFi in station mode. Connects to the specified WiFi network and handles events.
 *
 */
void wifi_init_sta(void) {
    s_wifi_event_group = xEventGroupCreate();

    wifi_country_t wifi_country = {
        .cc = "DE",  // Country code for Germany
        .schan = 1,  // Start channel
        .nchan = 13, // Number of channels (Germany allows 1–13)
        .policy = WIFI_COUNTRY_POLICY_AUTO};
    esp_wifi_set_country(&wifi_country);

    ESP_ERROR_CHECK(esp_netif_init());

    ESP_ERROR_CHECK(esp_event_loop_create_default());
    esp_netif_create_default_wifi_sta();

    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    ESP_ERROR_CHECK(esp_wifi_init(&cfg));

    esp_event_handler_instance_t instance_any_id;
    esp_event_handler_instance_t instance_got_ip;
    ESP_ERROR_CHECK(esp_event_handler_instance_register(WIFI_EVENT,
                                                        ESP_EVENT_ANY_ID,
                                                        &wifi_event_handler,
                                                        NULL,
                                                        &instance_any_id));
    ESP_ERROR_CHECK(esp_event_handler_instance_register(IP_EVENT,
                                                        IP_EVENT_STA_GOT_IP,
                                                        &wifi_event_handler,
                                                        NULL,
                                                        &instance_got_ip));

    wifi_config_t wifi_config = {
        .sta = {
            .ssid = ESP_WIFI_SSID,
            .password = ESP_WIFI_PASS,
            /* Authmode threshold resets to WPA2 as default if password matches WPA2 standards (password len => 8).
             * If you want to connect the device to deprecated WEP/WPA networks, Please set the threshold value
             * to WIFI_AUTH_WEP/WIFI_AUTH_WPA_PSK and set the password with length and format matching to
             * WIFI_AUTH_WEP/WIFI_AUTH_WPA_PSK standards.
             */
            .threshold.authmode = WIFI_AUTH_WPA2_PSK,
            .pmf_cfg = {
                .capable = true,
                .required = false,
            },
            // .threshold.authmode = ESP_WIFI_SCAN_AUTH_MODE_THRESHOLD,
            // .sae_pwe_h2e = ESP_WIFI_SAE_MODE,
            // .sae_h2e_identifier = H2E_IDENTIFIER,
        },
    };

    ESP_LOGI(TAG, "Setting WiFi configuration SSID %s...", ESP_WIFI_SSID);
    ESP_LOGI(TAG, "Setting WiFi configuration password %s...", ESP_WIFI_PASS);
    ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_STA));
    ESP_ERROR_CHECK(esp_wifi_set_config(WIFI_IF_STA, &wifi_config));
    ESP_ERROR_CHECK(esp_wifi_start());

    ESP_LOGI(TAG, "wifi_init_sta finished.");

    /* Waiting until either the connection is established (WIFI_CONNECTED_BIT) or connection failed for the maximum
     * number of re-tries (WIFI_FAIL_BIT). The bits are set by event_handler() (see above) */
    EventBits_t bits = xEventGroupWaitBits(s_wifi_event_group,
                                           WIFI_CONNECTED_BIT | WIFI_FAIL_BIT,
                                           pdFALSE,
                                           pdFALSE,
                                           portMAX_DELAY);

    /* xEventGroupWaitBits() returns the bits before the call returned, hence we can test which event actually
     * happened. */
    if (bits & WIFI_CONNECTED_BIT) {
        ESP_LOGI(TAG, "connected to ap SSID:%s password:%s",
                 ESP_WIFI_SSID, ESP_WIFI_PASS);
    } else if (bits & WIFI_FAIL_BIT) {
        ESP_LOGI(TAG, "Failed to connect to SSID:%s, password:%s",
                 ESP_WIFI_SSID, ESP_WIFI_PASS);
    } else {
        ESP_LOGE(TAG, "UNEXPECTED EVENT");
    }
}
