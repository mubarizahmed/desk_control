/*******************************************************************************
 * Size: 18 px
 * Bpp: 1
 * Opts: --bpp 1 --size 18 --no-compress --font JetBrainsMono-Light.ttf --symbols abcdefghijklmnopqrstuvwxyz.,-öäü+#´ß?ÄÖÜ<>|;:_{[]}\@€ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890^!"§$%&/()=?░❱◎↘◌◩«■» --format lvgl -o jetbrains_mono_light_18.c
 ******************************************************************************/

#include "lvgl.h"

#ifndef JETBRAINS_MONO_LIGHT_18
#define JETBRAINS_MONO_LIGHT_18 1
#endif

#if JETBRAINS_MONO_LIGHT_18

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0021 "!" */
    0x49, 0x24, 0x92, 0x40, 0x7e,

    /* U+0022 "\"" */
    0x8c, 0x63, 0x18, 0x80,

    /* U+0023 "#" */
    0x8, 0x84, 0x41, 0x11, 0xff, 0x11, 0x4, 0x42,
    0x20, 0x88, 0xff, 0x88, 0x82, 0x21, 0x88, 0x44,
    0x0,

    /* U+0024 "$" */
    0x8, 0x8, 0x1c, 0x3e, 0x49, 0x49, 0x48, 0x68,
    0x3c, 0xe, 0xb, 0x9, 0x89, 0xc9, 0x7e, 0x18,
    0x8, 0x8,

    /* U+0025 "%" */
    0x70, 0x62, 0x28, 0x92, 0x24, 0x8a, 0x1d, 0x0,
    0xc0, 0x2e, 0x14, 0x49, 0x12, 0x45, 0x11, 0x83,
    0x80,

    /* U+0026 "&" */
    0x3c, 0x23, 0x10, 0x88, 0x6, 0x1, 0x1, 0xc1,
    0x33, 0x8d, 0x43, 0xa1, 0x91, 0xe7, 0x98,

    /* U+0028 "(" */
    0xc, 0xe6, 0x10, 0x82, 0x8, 0x20, 0x82, 0x8,
    0x20, 0x81, 0x6, 0xe, 0xc,

    /* U+0029 ")" */
    0x87, 0xc, 0x20, 0x84, 0x21, 0x8, 0x42, 0x10,
    0x88, 0xcc, 0xc0,

    /* U+002B "+" */
    0x8, 0x8, 0x8, 0xff, 0x8, 0x8, 0x8, 0x8,

    /* U+002C "," */
    0x76, 0x64, 0xcc,

    /* U+002D "-" */
    0xfc,

    /* U+002E "." */
    0xff, 0x80,

    /* U+002F "/" */
    0x1, 0x3, 0x2, 0x2, 0x6, 0x4, 0xc, 0xc,
    0x8, 0x18, 0x10, 0x30, 0x30, 0x20, 0x60, 0x60,
    0x40,

    /* U+0030 "0" */
    0x3c, 0x42, 0x81, 0x81, 0x81, 0x99, 0x99, 0x81,
    0x81, 0x81, 0x81, 0x42, 0x3c,

    /* U+0031 "1" */
    0x18, 0x78, 0xc8, 0x88, 0x8, 0x8, 0x8, 0x8,
    0x8, 0x8, 0x8, 0x8, 0xff,

    /* U+0032 "2" */
    0x3c, 0x42, 0x81, 0x81, 0x1, 0x3, 0x2, 0x4,
    0x8, 0x30, 0x60, 0xc0, 0xff,

    /* U+0033 "3" */
    0xfe, 0x2, 0x4, 0x8, 0x18, 0x3c, 0x2, 0x1,
    0x1, 0x1, 0x81, 0x42, 0x3c,

    /* U+0034 "4" */
    0x4, 0x18, 0x20, 0x83, 0x4, 0x10, 0xe1, 0x83,
    0xfc, 0x8, 0x10, 0x20,

    /* U+0035 "5" */
    0xff, 0x2, 0x4, 0xb, 0xd8, 0xa0, 0x81, 0x2,
    0x6, 0xe, 0x27, 0x80,

    /* U+0036 "6" */
    0xc, 0x18, 0x10, 0x30, 0x20, 0x7c, 0xc2, 0x81,
    0x81, 0x81, 0x81, 0x42, 0x3c,

    /* U+0037 "7" */
    0xff, 0x83, 0x82, 0x6, 0x6, 0x4, 0xc, 0x8,
    0x18, 0x18, 0x10, 0x30, 0x20,

    /* U+0038 "8" */
    0x7d, 0x8e, 0xc, 0x1c, 0x6d, 0x8e, 0x22, 0x83,
    0x6, 0xe, 0x33, 0xc0,

    /* U+0039 "9" */
    0x3c, 0x42, 0x81, 0x81, 0x81, 0x81, 0x43, 0x3e,
    0x4, 0xc, 0x8, 0x18, 0x30,

    /* U+003A ":" */
    0xfc, 0x0, 0x0, 0xfc,

    /* U+003B ";" */
    0x77, 0x0, 0x0, 0x3, 0x66, 0x64, 0xc0,

    /* U+003C "<" */
    0x1, 0x7, 0xc, 0x30, 0xc0, 0xc0, 0x70, 0x1c,
    0x7, 0x1,

    /* U+003D "=" */
    0xff, 0x0, 0x0, 0x0, 0xff,

    /* U+003E ">" */
    0x0, 0xc0, 0x70, 0x1c, 0x7, 0x3, 0xc, 0x30,
    0xc0, 0x80,

    /* U+003F "?" */
    0xf0, 0x20, 0x41, 0x4, 0x33, 0x88, 0x20, 0x0,
    0x1c, 0x70,

    /* U+0040 "@" */
    0x3e, 0x30, 0xb0, 0x30, 0x18, 0x7c, 0x46, 0x23,
    0x11, 0x88, 0xc4, 0x62, 0x30, 0xf8, 0x2, 0x1,
    0x80, 0x38,

    /* U+0041 "A" */
    0x1c, 0xe, 0x5, 0x2, 0x83, 0x61, 0x30, 0x88,
    0xc4, 0x7f, 0x20, 0x90, 0x58, 0x2c, 0x18,

    /* U+0042 "B" */
    0xf8, 0x84, 0x82, 0x82, 0x82, 0x86, 0xfc, 0x82,
    0x81, 0x81, 0x81, 0x82, 0xfc,

    /* U+0043 "C" */
    0x38, 0x8a, 0xc, 0x18, 0x10, 0x20, 0x40, 0x81,
    0x6, 0xa, 0x23, 0x80,

    /* U+0044 "D" */
    0xf9, 0xa, 0xc, 0x18, 0x30, 0x60, 0xc1, 0x83,
    0x6, 0xc, 0x2f, 0x80,

    /* U+0045 "E" */
    0xff, 0x2, 0x4, 0x8, 0x10, 0x3f, 0x40, 0x81,
    0x2, 0x4, 0xf, 0xe0,

    /* U+0046 "F" */
    0xff, 0x2, 0x4, 0x8, 0x10, 0x3f, 0xc0, 0x81,
    0x2, 0x4, 0x8, 0x0,

    /* U+0047 "G" */
    0x3c, 0x8e, 0xc, 0x8, 0x10, 0x27, 0xc1, 0x83,
    0x6, 0xa, 0x23, 0x80,

    /* U+0048 "H" */
    0x83, 0x6, 0xc, 0x18, 0x30, 0x7f, 0xc1, 0x83,
    0x6, 0xc, 0x18, 0x20,

    /* U+0049 "I" */
    0xfe, 0x20, 0x40, 0x81, 0x2, 0x4, 0x8, 0x10,
    0x20, 0x40, 0x8f, 0xe0,

    /* U+004A "J" */
    0x1f, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1, 0x1,
    0x1, 0x81, 0x81, 0x42, 0x3c,

    /* U+004B "K" */
    0x82, 0x86, 0x84, 0x8c, 0x88, 0x98, 0xf0, 0x98,
    0x88, 0x8c, 0x86, 0x86, 0x83,

    /* U+004C "L" */
    0x81, 0x2, 0x4, 0x8, 0x10, 0x20, 0x40, 0x81,
    0x2, 0x4, 0xf, 0xe0,

    /* U+004D "M" */
    0xc3, 0xc3, 0xe7, 0xa5, 0xa5, 0x9d, 0x99, 0x81,
    0x81, 0x81, 0x81, 0x81, 0x81,

    /* U+004E "N" */
    0xc3, 0x87, 0x8d, 0x1a, 0x36, 0x64, 0xcd, 0x8b,
    0x16, 0x3c, 0x38, 0x60,

    /* U+004F "O" */
    0x38, 0x8a, 0xc, 0x18, 0x30, 0x60, 0xc1, 0x83,
    0x6, 0xa, 0x27, 0x80,

    /* U+0050 "P" */
    0xfc, 0x82, 0x81, 0x81, 0x81, 0x82, 0xfc, 0x80,
    0x80, 0x80, 0x80, 0x80, 0x80,

    /* U+0051 "Q" */
    0x38, 0x8a, 0xc, 0x18, 0x30, 0x60, 0xc1, 0x83,
    0x6, 0xa, 0x33, 0xc1, 0x81, 0x1,

    /* U+0052 "R" */
    0xfc, 0x82, 0x81, 0x81, 0x81, 0x82, 0xfc, 0x8c,
    0x84, 0x86, 0x82, 0x83, 0x81,

    /* U+0053 "S" */
    0x1e, 0x63, 0x41, 0x40, 0x40, 0x30, 0x1e, 0x6,
    0x1, 0x1, 0x81, 0x42, 0x3c,

    /* U+0054 "T" */
    0xff, 0x84, 0x2, 0x1, 0x0, 0x80, 0x40, 0x20,
    0x10, 0x8, 0x4, 0x2, 0x1, 0x0, 0x80,

    /* U+0055 "U" */
    0x83, 0x6, 0xc, 0x18, 0x30, 0x60, 0xc1, 0x83,
    0x6, 0xe, 0x27, 0x80,

    /* U+0056 "V" */
    0xc1, 0xe0, 0x90, 0x48, 0x66, 0x33, 0x10, 0x88,
    0x4c, 0x36, 0xa, 0x5, 0x3, 0x81, 0x80,

    /* U+0057 "W" */
    0x88, 0xcc, 0x65, 0x32, 0x99, 0x5c, 0xaf, 0x57,
    0xaa, 0x65, 0x32, 0x99, 0x4c, 0x66, 0x30,

    /* U+0058 "X" */
    0xc1, 0xa1, 0x98, 0x86, 0xc1, 0x40, 0xe0, 0x60,
    0x38, 0x34, 0x13, 0x18, 0xc8, 0x2c, 0x18,

    /* U+0059 "Y" */
    0xc1, 0xa0, 0x98, 0xc4, 0x43, 0x60, 0xa0, 0x50,
    0x10, 0x8, 0x4, 0x2, 0x1, 0x0, 0x80,

    /* U+005A "Z" */
    0xfe, 0xc, 0x10, 0x60, 0x83, 0x4, 0x18, 0x20,
    0xc1, 0x6, 0xf, 0xe0,

    /* U+005B "[" */
    0xf8, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88, 0x88,
    0xf0,

    /* U+005C "\\" */
    0x40, 0x60, 0x60, 0x20, 0x30, 0x10, 0x10, 0x18,
    0x8, 0xc, 0xc, 0x4, 0x6, 0x2, 0x2, 0x3,
    0x1,

    /* U+005D "]" */
    0xf1, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11, 0x11,
    0xf0,

    /* U+005E "^" */
    0x10, 0x50, 0xa2, 0x64, 0x58, 0xe0, 0x80,

    /* U+005F "_" */
    0xff, 0x80,

    /* U+0061 "a" */
    0x3c, 0x43, 0x1, 0x1, 0x7f, 0xc1, 0x81, 0x81,
    0xc3, 0x7d,

    /* U+0062 "b" */
    0x81, 0x2, 0x5, 0xec, 0x50, 0x60, 0xc1, 0x83,
    0x6, 0xe, 0x3b, 0xc0,

    /* U+0063 "c" */
    0x3c, 0x8e, 0xc, 0x8, 0x10, 0x20, 0x41, 0x46,
    0x78,

    /* U+0064 "d" */
    0x2, 0x4, 0xb, 0xdc, 0x70, 0x60, 0xc1, 0x83,
    0x6, 0xe, 0x37, 0xa0,

    /* U+0065 "e" */
    0x38, 0x8e, 0xc, 0x1f, 0xf0, 0x20, 0x41, 0x46,
    0x78,

    /* U+0066 "f" */
    0xf, 0x10, 0x10, 0x10, 0xff, 0x10, 0x10, 0x10,
    0x10, 0x10, 0x10, 0x10, 0x10,

    /* U+0067 "g" */
    0x7b, 0x8e, 0xc, 0x18, 0x30, 0x60, 0xe3, 0x7a,
    0x4, 0x8, 0x17, 0xc0,

    /* U+0068 "h" */
    0x81, 0x2, 0x5, 0xec, 0x70, 0x60, 0xc1, 0x83,
    0x6, 0xc, 0x18, 0x20,

    /* U+0069 "i" */
    0x18, 0x18, 0x0, 0x0, 0xf8, 0x8, 0x8, 0x8,
    0x8, 0x8, 0x8, 0x8, 0x8, 0xff,

    /* U+006A "j" */
    0xc, 0x30, 0x0, 0xfc, 0x10, 0x41, 0x4, 0x10,
    0x41, 0x4, 0x10, 0x42, 0xf0,

    /* U+006B "k" */
    0x80, 0x80, 0x80, 0x82, 0x86, 0x8c, 0x98, 0xf0,
    0x98, 0x8c, 0x84, 0x86, 0x82,

    /* U+006C "l" */
    0xf0, 0x8, 0x4, 0x2, 0x1, 0x0, 0x80, 0x40,
    0x20, 0x10, 0x8, 0x4, 0x2, 0x0, 0xf8,

    /* U+006D "m" */
    0xb6, 0xc9, 0x89, 0x89, 0x89, 0x89, 0x89, 0x89,
    0x89, 0x89,

    /* U+006E "n" */
    0xbd, 0x8e, 0xc, 0x18, 0x30, 0x60, 0xc1, 0x83,
    0x4,

    /* U+006F "o" */
    0x38, 0x8a, 0xc, 0x18, 0x30, 0x60, 0xc1, 0x44,
    0x70,

    /* U+0070 "p" */
    0xbd, 0x8e, 0xc, 0x18, 0x30, 0x60, 0xc1, 0xc5,
    0x7a, 0x4, 0x8, 0x0,

    /* U+0071 "q" */
    0x7b, 0x8e, 0xc, 0x18, 0x30, 0x60, 0xc1, 0xc6,
    0xf4, 0x8, 0x10, 0x20,

    /* U+0072 "r" */
    0xbd, 0x8e, 0xc, 0x18, 0x10, 0x20, 0x40, 0x81,
    0x0,

    /* U+0073 "s" */
    0x7d, 0xe, 0x4, 0x7, 0x83, 0xc0, 0x81, 0x82,
    0xf8,

    /* U+0074 "t" */
    0x10, 0x10, 0x10, 0xff, 0x10, 0x10, 0x10, 0x10,
    0x10, 0x10, 0x10, 0x10, 0xf,

    /* U+0075 "u" */
    0x83, 0x6, 0xc, 0x18, 0x30, 0x60, 0xc1, 0x44,
    0x70,

    /* U+0076 "v" */
    0xc1, 0xa0, 0x90, 0xcc, 0x62, 0x21, 0x30, 0xd8,
    0x28, 0x14, 0xe, 0x0,

    /* U+0077 "w" */
    0x88, 0xcc, 0x66, 0x7a, 0xbd, 0x52, 0xa9, 0x54,
    0xca, 0x65, 0x31, 0x80,

    /* U+0078 "x" */
    0x41, 0x31, 0x8d, 0x82, 0x81, 0xc0, 0xe0, 0xd0,
    0x4c, 0x63, 0x60, 0x80,

    /* U+0079 "y" */
    0xc1, 0xa0, 0x98, 0xcc, 0x42, 0x21, 0xb0, 0x50,
    0x28, 0x1c, 0x4, 0x6, 0x2, 0x3, 0x0,

    /* U+007A "z" */
    0xfe, 0xc, 0x30, 0x41, 0x86, 0x8, 0x30, 0xc1,
    0xfc,

    /* U+007B "{" */
    0x7, 0x8, 0x8, 0x8, 0x8, 0x8, 0x8, 0x8,
    0xf0, 0x8, 0x8, 0x8, 0x8, 0x8, 0x8, 0x8,
    0x7,

    /* U+007C "|" */
    0xff, 0xff, 0x80,

    /* U+007D "}" */
    0xe0, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10,
    0xf, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10,
    0xe0,

    /* U+00A7 "§" */
    0x7d, 0x8e, 0x4, 0xe, 0xf, 0xa0, 0xc1, 0x83,
    0xcd, 0xe0, 0x70, 0x30, 0x71, 0xbe,

    /* U+00AB "«" */
    0x19, 0x99, 0x99, 0x99, 0x8c, 0xc3, 0x30, 0xcc,
    0x33,

    /* U+00B4 "´" */
    0x2f, 0x0,

    /* U+00BB "»" */
    0xcc, 0x33, 0xc, 0xc3, 0x31, 0x99, 0x99, 0x99,
    0x98,

    /* U+00C4 "Ä" */
    0x66, 0x66, 0x0, 0x0, 0x18, 0x18, 0x3c, 0x24,
    0x24, 0x24, 0x66, 0x42, 0x7e, 0x42, 0xc3, 0x81,
    0x81,

    /* U+00D6 "Ö" */
    0x66, 0xcc, 0x0, 0x3, 0x88, 0xa0, 0xc1, 0x83,
    0x6, 0xc, 0x18, 0x30, 0x60, 0xa2, 0x78,

    /* U+00DC "Ü" */
    0x66, 0xcc, 0x0, 0x8, 0x30, 0x60, 0xc1, 0x83,
    0x6, 0xc, 0x18, 0x30, 0x60, 0xe2, 0x78,

    /* U+00DF "ß" */
    0x38, 0x8a, 0xc, 0x18, 0x30, 0xe7, 0x43, 0x83,
    0x6, 0xc, 0x2b, 0x80,

    /* U+00E4 "ä" */
    0x66, 0x66, 0x0, 0x0, 0x3c, 0x43, 0x1, 0x1,
    0x7f, 0xc1, 0x81, 0x81, 0xc3, 0x7d,

    /* U+00F6 "ö" */
    0x66, 0xcc, 0x0, 0x3, 0x88, 0xa0, 0xc1, 0x83,
    0x6, 0xc, 0x14, 0x47, 0x0,

    /* U+00FC "ü" */
    0x66, 0xcc, 0x0, 0x8, 0x30, 0x60, 0xc1, 0x83,
    0x6, 0xc, 0x14, 0x47, 0x0,

    /* U+20AC "€" */
    0xf, 0x18, 0xc8, 0x24, 0xf, 0xc1, 0x0, 0x81,
    0xf8, 0x20, 0x10, 0x48, 0x22, 0x30, 0xf0,

    /* U+2198 "↘" */
    0xc0, 0x70, 0x1c, 0x27, 0x11, 0xc8, 0x74, 0x1e,
    0x7, 0x3f, 0x80,

    /* U+2591 "░" */
    0xaa, 0x40, 0xa, 0xa4, 0x0, 0xaa, 0x40, 0xa,
    0xa4, 0x0, 0xaa, 0x40, 0xa, 0xa4, 0x0, 0x0,
    0x2a, 0x90, 0x2, 0xa9, 0x0, 0x2a, 0x90, 0x2,
    0xa9, 0x0, 0x2a, 0x90,

    /* U+25A0 "■" */
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80,

    /* U+25CC "◌" */
    0xe, 0x4, 0x11, 0x1, 0x0, 0x8, 0x3, 0x0,
    0x60, 0x8, 0x0, 0x40, 0x44, 0x10, 0x38, 0x0,

    /* U+25CE "◎" */
    0x1f, 0x4, 0x11, 0x1, 0x47, 0x19, 0x13, 0x22,
    0x64, 0x4c, 0x71, 0x40, 0x44, 0x10, 0x7c, 0x0,

    /* U+25E9 "◩" */
    0xff, 0xff, 0xff, 0xfe, 0xff, 0x9f, 0xe3, 0xf8,
    0x7e, 0xf, 0x81, 0xe0, 0x38, 0x7, 0xff, 0x80,

    /* U+2771 "❱" */
    0xf9, 0xf1, 0xe3, 0xe3, 0xc7, 0x8f, 0x9e, 0x3c,
    0xf9, 0xe7, 0xcf, 0x80
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 173, .box_w = 3, .box_h = 13, .ofs_x = 4, .ofs_y = 0},
    {.bitmap_index = 5, .adv_w = 173, .box_w = 5, .box_h = 5, .ofs_x = 3, .ofs_y = 8},
    {.bitmap_index = 9, .adv_w = 173, .box_w = 10, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 26, .adv_w = 173, .box_w = 8, .box_h = 18, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 44, .adv_w = 173, .box_w = 10, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 61, .adv_w = 173, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 76, .adv_w = 173, .box_w = 6, .box_h = 17, .ofs_x = 3, .ofs_y = -2},
    {.bitmap_index = 89, .adv_w = 173, .box_w = 5, .box_h = 17, .ofs_x = 2, .ofs_y = -2},
    {.bitmap_index = 100, .adv_w = 173, .box_w = 8, .box_h = 8, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 108, .adv_w = 173, .box_w = 4, .box_h = 6, .ofs_x = 3, .ofs_y = -3},
    {.bitmap_index = 111, .adv_w = 173, .box_w = 6, .box_h = 1, .ofs_x = 3, .ofs_y = 5},
    {.bitmap_index = 112, .adv_w = 173, .box_w = 3, .box_h = 3, .ofs_x = 4, .ofs_y = 0},
    {.bitmap_index = 114, .adv_w = 173, .box_w = 8, .box_h = 17, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 131, .adv_w = 173, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 144, .adv_w = 173, .box_w = 8, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 157, .adv_w = 173, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 170, .adv_w = 173, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 183, .adv_w = 173, .box_w = 7, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 195, .adv_w = 173, .box_w = 7, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 207, .adv_w = 173, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 220, .adv_w = 173, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 233, .adv_w = 173, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 245, .adv_w = 173, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 258, .adv_w = 173, .box_w = 3, .box_h = 10, .ofs_x = 4, .ofs_y = 0},
    {.bitmap_index = 262, .adv_w = 173, .box_w = 4, .box_h = 13, .ofs_x = 3, .ofs_y = -3},
    {.bitmap_index = 269, .adv_w = 173, .box_w = 8, .box_h = 10, .ofs_x = 2, .ofs_y = 1},
    {.bitmap_index = 279, .adv_w = 173, .box_w = 8, .box_h = 5, .ofs_x = 2, .ofs_y = 3},
    {.bitmap_index = 284, .adv_w = 173, .box_w = 8, .box_h = 10, .ofs_x = 2, .ofs_y = 1},
    {.bitmap_index = 294, .adv_w = 173, .box_w = 6, .box_h = 13, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 304, .adv_w = 173, .box_w = 9, .box_h = 16, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 322, .adv_w = 173, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 337, .adv_w = 173, .box_w = 8, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 350, .adv_w = 173, .box_w = 7, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 362, .adv_w = 173, .box_w = 7, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 374, .adv_w = 173, .box_w = 7, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 386, .adv_w = 173, .box_w = 7, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 398, .adv_w = 173, .box_w = 7, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 410, .adv_w = 173, .box_w = 7, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 422, .adv_w = 173, .box_w = 7, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 434, .adv_w = 173, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 447, .adv_w = 173, .box_w = 8, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 460, .adv_w = 173, .box_w = 7, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 472, .adv_w = 173, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 485, .adv_w = 173, .box_w = 7, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 497, .adv_w = 173, .box_w = 7, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 509, .adv_w = 173, .box_w = 8, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 522, .adv_w = 173, .box_w = 7, .box_h = 16, .ofs_x = 2, .ofs_y = -3},
    {.bitmap_index = 536, .adv_w = 173, .box_w = 8, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 549, .adv_w = 173, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 562, .adv_w = 173, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 577, .adv_w = 173, .box_w = 7, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 589, .adv_w = 173, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 604, .adv_w = 173, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 619, .adv_w = 173, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 634, .adv_w = 173, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 649, .adv_w = 173, .box_w = 7, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 661, .adv_w = 173, .box_w = 4, .box_h = 17, .ofs_x = 4, .ofs_y = -2},
    {.bitmap_index = 670, .adv_w = 173, .box_w = 8, .box_h = 17, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 687, .adv_w = 173, .box_w = 4, .box_h = 17, .ofs_x = 3, .ofs_y = -2},
    {.bitmap_index = 696, .adv_w = 173, .box_w = 7, .box_h = 7, .ofs_x = 2, .ofs_y = 6},
    {.bitmap_index = 703, .adv_w = 173, .box_w = 9, .box_h = 1, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 705, .adv_w = 173, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 715, .adv_w = 173, .box_w = 7, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 727, .adv_w = 173, .box_w = 7, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 736, .adv_w = 173, .box_w = 7, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 748, .adv_w = 173, .box_w = 7, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 757, .adv_w = 173, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 770, .adv_w = 173, .box_w = 7, .box_h = 13, .ofs_x = 2, .ofs_y = -3},
    {.bitmap_index = 782, .adv_w = 173, .box_w = 7, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 794, .adv_w = 173, .box_w = 8, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 808, .adv_w = 173, .box_w = 6, .box_h = 17, .ofs_x = 2, .ofs_y = -3},
    {.bitmap_index = 821, .adv_w = 173, .box_w = 8, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 834, .adv_w = 173, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 849, .adv_w = 173, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 859, .adv_w = 173, .box_w = 7, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 868, .adv_w = 173, .box_w = 7, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 877, .adv_w = 173, .box_w = 7, .box_h = 13, .ofs_x = 2, .ofs_y = -3},
    {.bitmap_index = 889, .adv_w = 173, .box_w = 7, .box_h = 13, .ofs_x = 2, .ofs_y = -3},
    {.bitmap_index = 901, .adv_w = 173, .box_w = 7, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 910, .adv_w = 173, .box_w = 7, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 919, .adv_w = 173, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 932, .adv_w = 173, .box_w = 7, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 941, .adv_w = 173, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 953, .adv_w = 173, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 965, .adv_w = 173, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 977, .adv_w = 173, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 992, .adv_w = 173, .box_w = 7, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1001, .adv_w = 173, .box_w = 8, .box_h = 17, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 1018, .adv_w = 173, .box_w = 1, .box_h = 17, .ofs_x = 5, .ofs_y = -2},
    {.bitmap_index = 1021, .adv_w = 173, .box_w = 8, .box_h = 17, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 1038, .adv_w = 173, .box_w = 7, .box_h = 16, .ofs_x = 2, .ofs_y = -3},
    {.bitmap_index = 1052, .adv_w = 173, .box_w = 9, .box_h = 8, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 1061, .adv_w = 173, .box_w = 3, .box_h = 3, .ofs_x = 4, .ofs_y = 12},
    {.bitmap_index = 1063, .adv_w = 173, .box_w = 9, .box_h = 8, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 1072, .adv_w = 173, .box_w = 8, .box_h = 17, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1089, .adv_w = 173, .box_w = 7, .box_h = 17, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1104, .adv_w = 173, .box_w = 7, .box_h = 17, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1119, .adv_w = 173, .box_w = 7, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1131, .adv_w = 173, .box_w = 8, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1145, .adv_w = 173, .box_w = 7, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1158, .adv_w = 173, .box_w = 7, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1171, .adv_w = 173, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1186, .adv_w = 173, .box_w = 9, .box_h = 9, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 1197, .adv_w = 173, .box_w = 10, .box_h = 22, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 1225, .adv_w = 173, .box_w = 11, .box_h = 11, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 1241, .adv_w = 173, .box_w = 11, .box_h = 11, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 1257, .adv_w = 173, .box_w = 11, .box_h = 11, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 1273, .adv_w = 173, .box_w = 11, .box_h = 11, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 1289, .adv_w = 173, .box_w = 7, .box_h = 13, .ofs_x = 2, .ofs_y = 0}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint8_t glyph_id_ofs_list_0[] = {
    0, 1, 2, 3, 4, 5, 0, 6,
    7
};

static const uint16_t unicode_list_3[] = {
    0x0, 0x4, 0xd, 0x14, 0x1d, 0x2f, 0x35, 0x38,
    0x3d, 0x4f, 0x55, 0x2005, 0x20f1, 0x24ea, 0x24f9, 0x2525,
    0x2527, 0x2542, 0x26ca
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 33, .range_length = 9, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = glyph_id_ofs_list_0, .list_length = 9, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_FULL
    },
    {
        .range_start = 43, .range_length = 53, .glyph_id_start = 9,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 97, .range_length = 29, .glyph_id_start = 62,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 167, .range_length = 9931, .glyph_id_start = 91,
        .unicode_list = unicode_list_3, .glyph_id_ofs_list = NULL, .list_length = 19, .type = LV_FONT_FMT_TXT_CMAP_SPARSE_TINY
    }
};



/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LVGL_VERSION_MAJOR == 8
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
#endif

#if LVGL_VERSION_MAJOR >= 8
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = NULL,
    .kern_scale = 0,
    .cmap_num = 4,
    .bpp = 1,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LVGL_VERSION_MAJOR == 8
    .cache = &cache
#endif
};

extern const lv_font_t lv_font_montserrat_12;


/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LVGL_VERSION_MAJOR >= 8
const lv_font_t jetbrains_mono_light_18 = {
#else
lv_font_t jetbrains_mono_light_18 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 22,          /*The maximum line height required by the font*/
    .base_line = 4,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -3,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
#if LV_VERSION_CHECK(8, 2, 0) || LVGL_VERSION_MAJOR >= 9
    .fallback = &lv_font_montserrat_12,
#endif
    .user_data = NULL,
};



#endif /*#if JETBRAINS_MONO_LIGHT_18*/

