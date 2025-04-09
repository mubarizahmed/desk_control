idf_component_register(SRCS "main.c" "weather_serv.c" "weather_serv.h"
  "wifi_manager.c" "wifi_manager.h" "display_manager.c" "display_manager.h"
  "ui.c" "ui.h"
  PRIV_REQUIRES esp_wifi nvs_flash esp_http_client mbedtls esp-tls
  INCLUDE_DIRS ".")
