/**
 * @file pin_definitions.h
 * @author Mubariz Ahmed (mubariz@mubariz.me)
 * @brief Pin definitions for the ESP32-S3-DevKitC-1
 * @version 0.1
 * @date 2025-04-09
 *
 */

#ifndef PIN_DEFINITIONS_H
#define PIN_DEFINITIONS_H

/* ------------------------------------------------------ */
/*      GPIO pin definitions for the ESP32-DevKitC-v4     */
/* ------------------------------------------------------ */

#ifdef ESP32_DEVKIT_C_V4

#define PIN_NUM_SCLK 14     // GPIO14 (SCLK) - SPI2 Clock
#define PIN_NUM_MOSI 13     // GPIO13 (MOSI) - SPI2 Master Out Slave In
#define PIN_NUM_MISO 12     // GPIO12 (MISO) - SPI2 Master In Slave Out
#define PIN_NUM_LCD_DC 26   // GPIO26 (DC) - LCD Data/Command
#define PIN_NUM_LCD_RST 25  // GPIO25 (RST) - LCD Reset
#define PIN_NUM_LCD_CS 33   // GPIO33 (CS) - LCD Chip Select
#define PIN_NUM_BK_LIGHT 27 // GPIO27 (BL) - LCD Backlight
#define PIN_NUM_TOUCH_CS 32 // GPIO32 (CS) - Touch Chip Select

#endif // ESP32_DEVKIT_C_V4

/* ------------------------------------------------------ */
/*  GPIO pin definitions for the PCB with ESP32-WROOM32-U */
/* ------------------------------------------------------ */

#define PIN_NUM_SCLK 35     // GPIO35 (SCLK) - SPI Clock
#define PIN_NUM_MOSI 32     // GPIO32 (MOSI) - SPI Master Out Slave In
#define PIN_NUM_MISO 34     // GPIO34 (MISO) - SPI Master In Slave Out
#define PIN_NUM_LCD_DC 14   // GPIO14 (DC) - LCD Data/Command
#define PIN_NUM_LCD_RST 12  // GPIO12 (RST) - LCD Reset
#define PIN_NUM_LCD_CS 13   // GPIO13 (CS) - LCD Chip Select
#define PIN_NUM_BK_LIGHT 27 // GPIO27 (BL) - LCD Backlight
#define PIN_NUM_TOUCH_CS 13 // GPIO13 (CS) - Touch Chip Select

#define PIN_NUM_ROT_1 24   // GPIO24 (ROT1) - Rotary Encoder 1
#define PIN_NUM_ROT_2 26   // GPIO26 (ROT2) - Rotary Encoder 2
#define PIN_NUM_ROT_BTN 23 // GPIO23 (ROT_BTN) - Rotary Encoder Button

#endif // PIN_DEFINITIONS_H