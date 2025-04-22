/**
 * @file spotify_serv.h
 * @author Mubariz Ahmed (mubariz@mubariz.me)
 * @brief Header - Spotify service for handling Spotify authentication and token management.
 * @version 0.1
 * @date 2025-04-17
 *
 */

#ifndef SPOTIFY_SERV_H
#define SPOTIFY_SERV_H

/* ------------------------------------------------------ */
/*                        INCLUDES                        */
/* ------------------------------------------------------ */

#include "esp_http_server.h"

/* ------------------------------------------------------ */
/*                        TYPEDEFS                        */
/* ------------------------------------------------------ */

typedef struct {
    char client_id[100];
    char client_secret[100];
    char refresh_token[300];
    char access_token[300];
    char auth_code[512];
    char redirect_uri[100];
    bool debug_on;
    int port;
    int retry;
    int max_retry;
    bool no_credentials;
    httpd_handle_t server;
} SpotifyContext;

typedef struct {
    char name[100];
    char artists[100];
    int32_t duration_ms;
    int32_t progress_ms;
    char album_name[100];
    char album_image_url[100];
    bool is_playing;
} CurrentlyPlayingData;

/* ------------------------------------------------------ */
/*                    PUBLIC VARIABLES                    */
/* ------------------------------------------------------ */

extern SpotifyContext g_spotify_ctx;
extern EventGroupHandle_t spotify_event_group;

/* ------------------------------------------------------ */
/*                      PUBLIC MACROS                     */
/* ------------------------------------------------------ */

#define SPOTIFY_CMD_RESUME BIT0
#define SPOTIFY_CMD_PAUSE BIT1
#define SPOTIFY_CMD_PREV BIT2
#define SPOTIFY_CMD_NEXT BIT3

/* ------------------------------------------------------ */
/*                    PUBLIC FUNCTIONS                    */
/* ------------------------------------------------------ */
void spotify_task(void *pvParameters);

#endif /* SPOTIFY_SERV_H */