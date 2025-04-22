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

#define PIN_NUM_SCLK 14     // GPIO14 (SCLK) - SPI2 Clock
#define PIN_NUM_MOSI 13     // GPIO13 (MOSI) - SPI2 Master Out Slave In
#define PIN_NUM_MISO 12     // GPIO12 (MISO) - SPI2 Master In Slave Out
#define PIN_NUM_LCD_DC 26   // GPIO26 (DC) - LCD Data/Command
#define PIN_NUM_LCD_RST 25  // GPIO25 (RST) - LCD Reset
#define PIN_NUM_LCD_CS 33   // GPIO33 (CS) - LCD Chip Select
#define PIN_NUM_BK_LIGHT 27 // GPIO27 (BL) - LCD Backlight
#define PIN_NUM_TOUCH_CS 32 // GPIO32 (CS) - Touch Chip Select

#endif // PIN_DEFINITIONS_H