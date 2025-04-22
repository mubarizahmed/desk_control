/**
 * @file todoist_serv.c
 * @author Mubariz Ahmed (mubariz@mubariz.me)
 * @brief Todoist service for handling Todoist tasks and authentication.
 * @version 0.1
 * @date 2025-04-21
 *
 */

/* ------------------------------------------------------ */
/*                        INCLUDES                        */
/* ------------------------------------------------------ */
#include "cJSON.h"
#include "esp_crt_bundle.h"
#include "esp_err.h"
#include "esp_http_client.h"
#include "esp_log.h"
#include "esp_tls.h"
#include "mbedtls/base64.h"
#include "nvs_flash.h"
#include "string.h"
#include <sys/param.h>

#include "app_events.h"
#include "display_manager.h"
#include "secret_conf.h"
#include "ui.h"
#include "wifi_manager.h"

#include "todoist_serv.h"
/* ------------------------------------------------------ */
/*                      CONFIG MACROS                     */
/* ------------------------------------------------------ */

#define TD_MAX_HTTP_OUTPUT_BUFFER 4024

/* ------------------------------------------------------ */
/*                    PRIVATE VARIABLES                   */
/* ------------------------------------------------------ */

static const char *TAG = "TODOIST_SERV";

static char td_response_buffer[TD_MAX_HTTP_OUTPUT_BUFFER] = {0};

static TodoistTaskData td_tasks[4] = {0};

static bool td_tasks_loaded = false;

/* ------------------------------------------------------ */
/*              PRIVATE FUNCTION DECLARATIONS             */
/* ------------------------------------------------------ */
/* ------------------------- API ------------------------ */

esp_err_t td_get_today_tasks(int *out_delay_ms);
/* ----------------------- Utility ---------------------- */

esp_err_t td_http_event_handler(esp_http_client_event_t *evt);
void sort_tasks(TodoistTaskData *tasks, int count);
void strncpy_with_dots(char *dest, const char *src, size_t max_len);

/* ------------------------------------------------------ */
/*                    PRIVATE FUNCTIONS                   */
/* ------------------------------------------------------ */

/**
 * @brief Get the tasks for today from Todoist API.
 *
 * @return esp_err_t - ESP_OK on success, or an error code on failure
 */
esp_err_t td_get_today_tasks(int *out_delay_ms) {
    esp_err_t ret = ESP_OK;

    ESP_LOGI(TAG, "Getting tasks");

    esp_http_client_config_t config = {
        .url = "https://todoist.com/api/v1/tasks/filter?query=today&limit=4",
        .method = HTTP_METHOD_GET,
        .transport_type = HTTP_TRANSPORT_OVER_SSL,
        .crt_bundle_attach = esp_crt_bundle_attach,
        .event_handler = td_http_event_handler,
        .user_data = td_response_buffer,
        .timeout_ms = 25000,
    };

    // Clear the buffer before request
    memset(td_response_buffer, 0, MAX_HTTP_OUTPUT_BUFFER);

    esp_http_client_handle_t client = esp_http_client_init(&config);

    char auth_header[308];
    snprintf(auth_header, sizeof(auth_header), "Bearer %s", TODOIST_API_TOKEN);
    ret = esp_http_client_set_header(client, "Authorization", auth_header);
    if (ret != ESP_OK) {
        ESP_LOGE(TAG, "Failed to set Authorization header: %s", esp_err_to_name(ret));
        goto cleanup;
    }

    ESP_LOGD(TAG, "Authorization: %s", auth_header);

    esp_err_t err = esp_http_client_perform(client);

    if (err == ESP_OK) {
        int status = esp_http_client_get_status_code(client);
        ESP_LOGI(TAG, "HTTP Status Code: %d", status);
        if (status == 200) {
            ESP_LOGD(TAG, "Current task: %s", td_response_buffer);
            // ESP_LOG_BUFFER_HEX_LEVEL(TAG, td_response_buffer, strlen(td_response_buffer), ESP_LOG_INFO);

            // Parse the response and extract relevant information
            cJSON *json = cJSON_Parse(td_response_buffer);
            if (json) {
                // Extract information from JSON
                const cJSON *item = cJSON_GetObjectItem(json, "results");
                if (cJSON_IsArray(item)) {
                    ESP_LOGI(TAG, "Number of tasks: %d", cJSON_GetArraySize(item));
                    int count = cJSON_GetArraySize(item);
                    for (int i = 0; (i < count) && (i < 4); i++) {
                        const cJSON *task = cJSON_GetArrayItem(item, i);
                        const cJSON *task_name = cJSON_GetObjectItem(task, "content");
                        const cJSON *task_id = cJSON_GetObjectItem(task, "id");
                        const cJSON *task_priority = cJSON_GetObjectItem(task, "priority");
                        if (cJSON_IsString(task_name) && task_name->valuestring != NULL) {
                            ESP_LOGD(TAG, "Task %d: %s", i + 1, task_name->valuestring);
                            strncpy_with_dots(td_tasks[i].task_name, task_name->valuestring, sizeof(td_tasks[i].task_name));

                            if (cJSON_IsString(task_id) && task_id->valuestring != NULL) {
                                ESP_LOGD(TAG, "Task ID %d: %s", i + 1, task_id->valuestring);
                                strncpy_with_dots(td_tasks[i].task_id, task_id->valuestring, sizeof(td_tasks[i].task_id));
                            }

                            if (cJSON_IsNumber(task_priority)) {
                                ESP_LOGD(TAG, "Task Priority %d: %d", i + 1, task_priority->valueint);
                                td_tasks[i].task_priority = task_priority->valueint;
                            }
                        }
                    }
                    sort_tasks(td_tasks, count);
                }

                cJSON_Delete(json);

                _lock_acquire(&lvgl_api_lock);
                setTodoistData(td_tasks, 4);
                _lock_release(&lvgl_api_lock);
                td_tasks_loaded = true;
                *out_delay_ms = 2000; // Set delay to 2 seconds after data is loaded
            }
        } else {
            ESP_LOGE(TAG, "Error: %d", status);
            goto cleanup;
        }
    } else {
        ESP_LOGE(TAG, "HTTP request failed: %s", esp_err_to_name(err));
        ESP_LOGE(TAG, "Response: %s", td_response_buffer);
        goto cleanup;
    }

cleanup:
    // heap information
    size_t free_heap = esp_get_free_heap_size();
    size_t min_free_heap = esp_get_minimum_free_heap_size();
    ESP_LOGD("MEMORY", "td_get_today_tasks heap: %zu bytes, Minimum free heap: %zu bytes", free_heap, min_free_heap);

    // // task memory
    // size_t task_stack = uxTaskGetStackHighWaterMark(NULL);
    // ESP_LOGD("STACK", "todoist_task stackHighWatermark: %zu bytes", task_stack);

    esp_http_client_cleanup(client);
    return ret;
}
/* ----------------------- Utility ---------------------- */
/**
 * @brief HTTP event handler for handling HTTP events.
 *
 * @param evt - Pointer to the HTTP event structure
 * @return ESP_OK on success, or an error code on failure
 */
esp_err_t td_http_event_handler(esp_http_client_event_t *evt) {
    static char *output_buffer; // Buffer to store response of http request from event handler
    static int output_len;      // Stores number of bytes read

    switch (evt->event_id) {
    case HTTP_EVENT_ERROR:
        ESP_LOGD(TAG, "HTTP_EVENT_ERROR");
        break;
    case HTTP_EVENT_ON_CONNECTED:
        ESP_LOGD(TAG, "HTTP_EVENT_ON_CONNECTED");
        break;
    case HTTP_EVENT_HEADER_SENT:
        ESP_LOGD(TAG, "HTTP_EVENT_HEADER_SENT");
        break;
    case HTTP_EVENT_ON_HEADER:
        ESP_LOGD(TAG, "HTTP_EVENT_ON_HEADER, key=%s, value=%s", evt->header_key, evt->header_value);
        break;
    case HTTP_EVENT_ON_DATA:
        ESP_LOGD(TAG, "HTTP_EVENT_ON_DATA, len=%d", evt->data_len);
        // Clean the buffer in case of a new request
        if (output_len == 0 && evt->user_data) {
            // we are just starting to copy the output data into the use
            memset(evt->user_data, 0, TD_MAX_HTTP_OUTPUT_BUFFER);
        }
        /*
         *  Check for chunked encoding is added as the URL for chunked encoding used in this example returns binary data.
         *  However, event handler can also be used in case chunked encoding is used.
         */
        if (!esp_http_client_is_chunked_response(evt->client)) {
            // If user_data buffer is configured, copy the response into the buffer
            int copy_len = 0;
            if (evt->user_data) {
                // The last byte in evt->user_data is kept for the NULL character in case of out-of-bound access.
                copy_len = MIN(evt->data_len, (TD_MAX_HTTP_OUTPUT_BUFFER - output_len));
                if (copy_len) {
                    memcpy(evt->user_data + output_len, evt->data, copy_len);
                }
            } else {
                int content_len = esp_http_client_get_content_length(evt->client);
                if (output_buffer == NULL) {
                    // We initialize output_buffer with 0 because it is used by strlen() and similar functions therefore should be null terminated.
                    output_buffer = (char *)calloc(content_len + 1, sizeof(char));
                    output_len = 0;
                    if (output_buffer == NULL) {
                        ESP_LOGE(TAG, "Failed to allocate memory for output buffer");
                        return ESP_FAIL;
                    }
                }
                copy_len = MIN(evt->data_len, (content_len - output_len));
                if (copy_len) {
                    memcpy(output_buffer + output_len, evt->data, copy_len);
                }
            }
            output_len += copy_len;
        } else {
            // If chunked response, we can directly print the data
            // ESP_LOGI(TAG, "HTTP_EVENT_ON_DATA chunked: data: %.*s", evt->data_len, (char *)evt->data);
            int copy_len = 0;
            if (evt->user_data) {
                // The last byte in evt->user_data is kept for the NULL character in case of out-of-bound access.
                copy_len = MIN(evt->data_len, (TD_MAX_HTTP_OUTPUT_BUFFER - output_len));
                if (copy_len) {
                    memcpy(evt->user_data + output_len, evt->data, copy_len);
                }
            }
            output_len += copy_len;
        }

        break;
    case HTTP_EVENT_ON_FINISH:
        ESP_LOGD(TAG, "HTTP_EVENT_ON_FINISH");
        // ESP_LOGI(TAG, "Output buffer length: %d", strlen(output_buffer));
        if (output_buffer != NULL) {
            ESP_LOGI(TAG, "Output buffer: %s", output_buffer);

            free(output_buffer);
            output_buffer = NULL;
        }
        output_len = 0;
        break;
    case HTTP_EVENT_DISCONNECTED:
        ESP_LOGD(TAG, "HTTP_EVENT_DISCONNECTED");
        int mbedtls_err = 0;
        esp_err_t err = esp_tls_get_and_clear_last_error((esp_tls_error_handle_t)evt->data, &mbedtls_err, NULL);
        if (err != 0) {
            ESP_LOGW(TAG, "Last esp error code: 0x%x", err);
            ESP_LOGW(TAG, "Last mbedtls failure: 0x%x", mbedtls_err);
        }
        if (output_buffer != NULL) {
            free(output_buffer);
            output_buffer = NULL;
        }
        output_len = 0;
        break;
    case HTTP_EVENT_REDIRECT:
        ESP_LOGD(TAG, "HTTP_EVENT_REDIRECT");
        esp_http_client_set_header(evt->client, "From", "user@example.com");
        esp_http_client_set_header(evt->client, "Accept", "text/html");
        esp_http_client_set_redirection(evt->client);
        break;
    }
    return ESP_OK;
}

/**
 * @brief Sort tasks based on priority.
 *
 * @param tasks - Pointer to the array of TodoistTaskData
 * @param count - Number of tasks in the array
 */
void sort_tasks(TodoistTaskData *tasks, int count) {
    // Sort tasks based on priority (1 = highest, 4 = lowest)
    if (count <= 0) {
        return;
    }
    if (tasks == NULL) {
        ESP_LOGE(TAG, "Tasks array is NULL");
        return;
    }
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (tasks[i].task_priority < tasks[j].task_priority) {
                TodoistTaskData temp = tasks[i];
                tasks[i] = tasks[j];
                tasks[j] = temp;
            }
        }
    }
}

/**
 * @brief Copy a string with a maximum length and add ellipses if it exceeds the length.
 *
 * @param dest - Destination string
 * @param src - Source string
 * @param max_len - Maximum length of the destination string
 */
void strncpy_with_dots(char *dest, const char *src, size_t max_len) {
    if (strlen(src) < max_len) {
        strncpy(dest, src, max_len);
        dest[max_len - 1] = '\0';
    } else {
        strncpy(dest, src, max_len - 3); // leave space for '..\0'
        dest[max_len - 3] = '.';
        dest[max_len - 2] = '.';
        dest[max_len - 1] = '\0';
    }
}

/* ------------------------------------------------------ */
/*                    PUBLIC FUNCTIONS                    */
/* ------------------------------------------------------ */

/**
 * @brief Task to handle Todoist tasks and update task information.
 *
 * @param pvParameters - Pointer to task parameters (not used)
 */
void todoist_task(void *pvParameters) {
    ESP_LOGI(TAG, "Todoist task started");

    // Initialize the Todoist API client and fetch tasks
    while (1) {
        // Check if WiFi is connected
        if (wifi_connected) {
            ESP_LOGD(TAG, "WiFi connected, fetching Todoist tasks.");
            break;
        }
        vTaskDelay(pdMS_TO_TICKS(1000)); // 1 second delay
    }

    while (!td_tasks_loaded) {
        int delay = 30000;
        esp_err_t ret = td_get_today_tasks(&delay);
        if (ret != ESP_OK) {
            ESP_LOGE(TAG, "Failed to get Todoist tasks: %s", esp_err_to_name(ret));
        }
        // Wait for a while before fetching tasks again
        vTaskDelay(pdMS_TO_TICKS(delay));
    }

    ESP_LOGI(TAG, "Todoist tasks loaded successfully! Deleting task.");

    xEventGroupSetBits(app_event_group, TODOIST_SET_EVENT);

    vTaskDelete(NULL);
}