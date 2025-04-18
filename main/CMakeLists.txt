idf_component_register(
  SRCS
  "main.c"
  "weather_serv.c" "weather_serv.h"
  "wifi_manager.c" "wifi_manager.h"
  "display_manager.c" "display_manager.h"
  "time_serv.c" "time_serv.h"
  "ui.c" "ui.h"
  "pomodoro.c" "pomodoro.h"
  "calendar_serv.c" "calendar_serv.h"
  "spotify_serv.c" "spotify_serv.h"
  # "SpotifyEsp32.cpp" "SpotifyEsp32.h"
  "fonts/jetbrains_mono_bold_8.c"
  "fonts/jetbrains_mono_bold_10.c"
  "fonts/jetbrains_mono_bold_12.c"
  "fonts/jetbrains_mono_bold_14.c"
  "fonts/jetbrains_mono_bold_18.c"
  "fonts/jetbrains_mono_bold_46.c"
  "fonts/jetbrains_mono_bold_50.c"
  "fonts/jetbrains_mono_regular_8.c"
  "fonts/jetbrains_mono_regular_10.c"
  "fonts/jetbrains_mono_regular_12.c"
  "fonts/jetbrains_mono_regular_14.c"
  "fonts/jetbrains_mono_regular_18.c"
  "fonts/jetbrains_mono_light_10.c"
  "fonts/jetbrains_mono_light_12.c"
  "fonts/jetbrains_mono_light_14.c"
  "fonts/jetbrains_mono_light_18.c"
  "fonts/jetbrains_mono_light_50.c"
  "fonts/noto_color_emoji_50.c"
  "fonts/noto_emoji_50.c"
  PRIV_REQUIRES esp_wifi nvs_flash esp_http_client mbedtls esp-tls esp_netif lwip json esp_https_server
  INCLUDE_DIRS "." "fonts"
)

set(embed_txt_files "server_cert.pem" "server_key.pem")
foreach(file IN LISTS embed_txt_files)
  target_add_binary_data(${COMPONENT_LIB} "certs/${file}" TEXT)
endforeach()
