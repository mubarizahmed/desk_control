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

#include "esp_http_server.h"

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

extern SpotifyContext g_spotify_ctx;

void get_access_token(SpotifyContext *ctx);
void spotify_task(void *pvParameters);

#endif /* SPOTIFY_SERV_H */