idf_component_register(SRCS "main.c" "lvgl_demo_ui.c"
  PRIV_REQUIRES esp_wifi nvs_flash esp_http_client mbedtls esp-tls
  INCLUDE_DIRS ".")
