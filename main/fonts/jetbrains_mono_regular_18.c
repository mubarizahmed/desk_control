/*******************************************************************************
 * Size: 18 px
 * Bpp: 1
 * Opts: --bpp 1 --size 18 --no-compress --font JetBrainsMono-Regular.ttf --symbols abcdefghijklmnopqrstuvwxyz.,-öäü+#´ß?ÄÖÜ<>|;:_{[]}\@€ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890^!"§$%&/()=?░❱◎↘◌◩«■» --format lvgl -o jetbrains_mono_regular_18.c
 ******************************************************************************/


#include "lvgl.h"


#ifndef JETBRAINS_MONO_REGULAR_18
#define JETBRAINS_MONO_REGULAR_18 1
#endif

#if JETBRAINS_MONO_REGULAR_18

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0021 "!" */
    0xff, 0xff, 0xc3, 0xc0,

    /* U+0022 "\"" */
    0xde, 0xf7, 0xbd, 0x80,

    /* U+0023 "#" */
    0x19, 0x84, 0x41, 0x11, 0xff, 0x11, 0xc, 0xc3,
    0x30, 0x88, 0xff, 0x88, 0x82, 0x21, 0x98, 0x66,
    0x0,

    /* U+0024 "$" */
    0x8, 0x8, 0x8, 0x7e, 0xeb, 0xcb, 0xc8, 0xe8,
    0x7c, 0xe, 0xb, 0xb, 0xcb, 0xeb, 0x7e, 0x18,
    0x8, 0x8,

    /* U+0025 "%" */
    0x70, 0x7b, 0x1b, 0x66, 0x6c, 0xcd, 0xb0, 0xec,
    0x3, 0x80, 0x7e, 0x1e, 0x66, 0xcc, 0xd9, 0xb3,
    0x3c, 0x3c,

    /* U+0026 "&" */
    0x3c, 0x31, 0x18, 0x8c, 0x7, 0x1, 0x81, 0xe1,
    0x93, 0xcd, 0x63, 0xb0, 0x98, 0xe7, 0x98,

    /* U+0028 "(" */
    0xc, 0xf7, 0x18, 0xc3, 0xc, 0x30, 0xc3, 0xc,
    0x30, 0xc1, 0x87, 0xe, 0xc,

    /* U+0029 ")" */
    0xc3, 0x83, 0x6, 0xc, 0x30, 0xc3, 0xc, 0x30,
    0xc3, 0xc, 0x63, 0xbc, 0xc0,

    /* U+002B "+" */
    0x18, 0x18, 0x18, 0xff, 0x18, 0x18, 0x18, 0x18,

    /* U+002C "," */
    0x76, 0x64, 0xcc,

    /* U+002D "-" */
    0xfc,

    /* U+002E "." */
    0xff, 0x80,

    /* U+002F "/" */
    0x1, 0x3, 0x3, 0x6, 0x6, 0x4, 0xc, 0xc,
    0x8, 0x18, 0x18, 0x30, 0x30, 0x20, 0x60, 0x60,
    0x40,

    /* U+0030 "0" */
    0x3c, 0x66, 0xc3, 0xc3, 0xc3, 0xdb, 0xdb, 0xc3,
    0xc3, 0xc3, 0xc3, 0x66, 0x3c,

    /* U+0031 "1" */
    0x38, 0x78, 0xd8, 0x98, 0x18, 0x18, 0x18, 0x18,
    0x18, 0x18, 0x18, 0x18, 0xff,

    /* U+0032 "2" */
    0x3c, 0x66, 0xc3, 0xc3, 0x3, 0x7, 0x6, 0xc,
    0x1c, 0x38, 0x70, 0xe0, 0xff,

    /* U+0033 "3" */
    0x7f, 0x7, 0x6, 0xc, 0x18, 0x1c, 0x6, 0x3,
    0x3, 0xc3, 0xc3, 0x66, 0x3c,

    /* U+0034 "4" */
    0x6, 0xc, 0xc, 0x18, 0x30, 0x30, 0x63, 0xe3,
    0xc3, 0xff, 0x3, 0x3, 0x3,

    /* U+0035 "5" */
    0xfe, 0xc0, 0xc0, 0xc0, 0xdc, 0xe6, 0xc3, 0x3,
    0x3, 0x3, 0xc3, 0xc6, 0x7c,

    /* U+0036 "6" */
    0xc, 0x6, 0x6, 0x6, 0x3, 0x3, 0xf3, 0x8d,
    0x83, 0xc1, 0xe0, 0xf0, 0x6c, 0x63, 0xe0,

    /* U+0037 "7" */
    0xff, 0xc3, 0xc3, 0x2, 0x6, 0x4, 0x4, 0xc,
    0x8, 0x18, 0x18, 0x10, 0x30,

    /* U+0038 "8" */
    0x3c, 0xe6, 0xc3, 0xc3, 0xe7, 0x7e, 0x3c, 0x7e,
    0xc3, 0xc3, 0xc3, 0x66, 0x3c,

    /* U+0039 "9" */
    0x3e, 0x31, 0xb0, 0x78, 0x3c, 0x1e, 0xd, 0x8e,
    0x7e, 0x6, 0x3, 0x3, 0x3, 0x1, 0x80,

    /* U+003A ":" */
    0xfc, 0x0, 0x0, 0xfc,

    /* U+003B ";" */
    0x77, 0x0, 0x0, 0x7, 0x66, 0x64, 0xc0,

    /* U+003C "<" */
    0x1, 0x7, 0x1c, 0x70, 0xc0, 0xc0, 0x70, 0x1c,
    0x7, 0x1,

    /* U+003D "=" */
    0xff, 0x0, 0x0, 0x0, 0x0, 0xff,

    /* U+003E ">" */
    0x0, 0xc0, 0x70, 0x1c, 0x7, 0x3, 0xe, 0x38,
    0xe0, 0x80,

    /* U+003F "?" */
    0xf8, 0x18, 0x18, 0x30, 0x61, 0x9e, 0x30, 0x60,
    0x0, 0x3, 0x6, 0x0,

    /* U+0040 "@" */
    0x1f, 0x18, 0x66, 0xf, 0x3, 0xcf, 0xf6, 0x3d,
    0x8f, 0x63, 0xd8, 0xf6, 0x3d, 0x8f, 0x3f, 0xc0,
    0x18, 0x7, 0x0, 0x70,

    /* U+0041 "A" */
    0x1c, 0xe, 0x5, 0x6, 0x83, 0x61, 0x30, 0x88,
    0xc4, 0x7f, 0x21, 0x90, 0x58, 0x3c, 0x18,

    /* U+0042 "B" */
    0xfc, 0xc6, 0xc3, 0xc3, 0xc3, 0xc7, 0xfe, 0xc7,
    0xc3, 0xc3, 0xc3, 0xc6, 0xfc,

    /* U+0043 "C" */
    0x3c, 0x66, 0xc3, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0,
    0xc0, 0xc0, 0xc3, 0x66, 0x3c,

    /* U+0044 "D" */
    0xfc, 0xc6, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3,
    0xc3, 0xc3, 0xc3, 0xc6, 0xfc,

    /* U+0045 "E" */
    0xff, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xfe, 0xc0,
    0xc0, 0xc0, 0xc0, 0xc0, 0xff,

    /* U+0046 "F" */
    0xff, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xff, 0xc0,
    0xc0, 0xc0, 0xc0, 0xc0, 0xc0,

    /* U+0047 "G" */
    0x3c, 0x67, 0xc3, 0xc0, 0xc0, 0xc0, 0xcf, 0xc3,
    0xc3, 0xc3, 0xc3, 0x66, 0x3c,

    /* U+0048 "H" */
    0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xff, 0xc3,
    0xc3, 0xc3, 0xc3, 0xc3, 0xc3,

    /* U+0049 "I" */
    0xfe, 0x30, 0x60, 0xc1, 0x83, 0x6, 0xc, 0x18,
    0x30, 0x60, 0xcf, 0xe0,

    /* U+004A "J" */
    0x1f, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3,
    0x3, 0xc3, 0xc3, 0x66, 0x3c,

    /* U+004B "K" */
    0xc1, 0x61, 0xb0, 0x98, 0xcc, 0x46, 0x63, 0xe1,
    0x98, 0xc4, 0x63, 0x30, 0x98, 0x6c, 0x18,

    /* U+004C "L" */
    0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0,
    0xc0, 0xc0, 0xc0, 0xc0, 0xff,

    /* U+004D "M" */
    0xe7, 0xe5, 0xe7, 0xe7, 0xdf, 0xdb, 0xdb, 0xc3,
    0xc3, 0xc3, 0xc3, 0xc3, 0xc3,

    /* U+004E "N" */
    0xe3, 0xe3, 0xe3, 0xf3, 0xd3, 0xd3, 0xdb, 0xcb,
    0xcb, 0xcf, 0xc7, 0xc7, 0xc7,

    /* U+004F "O" */
    0x3c, 0x66, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3,
    0xc3, 0xc3, 0xc3, 0x66, 0x3c,

    /* U+0050 "P" */
    0xfc, 0xc6, 0xc3, 0xc3, 0xc3, 0xc6, 0xfc, 0xc0,
    0xc0, 0xc0, 0xc0, 0xc0, 0xc0,

    /* U+0051 "Q" */
    0x3c, 0x66, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3,
    0xc3, 0xc3, 0xc3, 0x66, 0x3c, 0x4, 0x6, 0x3,

    /* U+0052 "R" */
    0xfc, 0xc6, 0xc3, 0xc3, 0xc3, 0xc6, 0xfc, 0xcc,
    0xcc, 0xc4, 0xc6, 0xc6, 0xc3,

    /* U+0053 "S" */
    0x3c, 0x67, 0xc3, 0xc0, 0xe0, 0x78, 0x7e, 0xf,
    0x3, 0x3, 0xc3, 0xe6, 0x3c,

    /* U+0054 "T" */
    0xff, 0x8c, 0x6, 0x3, 0x1, 0x80, 0xc0, 0x60,
    0x30, 0x18, 0xc, 0x6, 0x3, 0x1, 0x80,

    /* U+0055 "U" */
    0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3,
    0xc3, 0xc3, 0xc3, 0x66, 0x3c,

    /* U+0056 "V" */
    0xc1, 0xe0, 0xd0, 0x48, 0x66, 0x33, 0x10, 0x88,
    0x4c, 0x36, 0x1a, 0x5, 0x3, 0x81, 0xc0,

    /* U+0057 "W" */
    0x44, 0x53, 0x14, 0xa5, 0x2b, 0x4a, 0xda, 0xb6,
    0xad, 0xaa, 0x6a, 0x8c, 0xa3, 0x38, 0xc6, 0x31,
    0x80,

    /* U+0058 "X" */
    0xc1, 0xb1, 0x98, 0x86, 0xc3, 0x40, 0xe0, 0x60,
    0x38, 0x36, 0x13, 0x18, 0xc8, 0x6c, 0x18,

    /* U+0059 "Y" */
    0xc0, 0xd0, 0x26, 0x18, 0xcc, 0x33, 0x7, 0x81,
    0xe0, 0x30, 0xc, 0x3, 0x0, 0xc0, 0x30, 0xc,
    0x0,

    /* U+005A "Z" */
    0xff, 0x3, 0x6, 0x6, 0xc, 0xc, 0x18, 0x30,
    0x30, 0x60, 0x60, 0xc0, 0xff,

    /* U+005B "[" */
    0xfe, 0x31, 0x8c, 0x63, 0x18, 0xc6, 0x31, 0x8c,
    0x63, 0x18, 0xf8,

    /* U+005C "\\" */
    0x40, 0x60, 0x60, 0x20, 0x30, 0x30, 0x18, 0x18,
    0x8, 0xc, 0xc, 0x4, 0x6, 0x6, 0x3, 0x3,
    0x1,

    /* U+005D "]" */
    0xf8, 0xc6, 0x31, 0x8c, 0x63, 0x18, 0xc6, 0x31,
    0x8c, 0x63, 0xf8,

    /* U+005E "^" */
    0x18, 0x14, 0x34, 0x26, 0x22, 0x63, 0x41,

    /* U+005F "_" */
    0xff, 0x80,

    /* U+0061 "a" */
    0x3e, 0x67, 0x3, 0x3, 0x7f, 0xc3, 0xc3, 0xc3,
    0xe7, 0x7b,

    /* U+0062 "b" */
    0xc0, 0xc0, 0xc0, 0xde, 0xe6, 0xc3, 0xc3, 0xc3,
    0xc3, 0xc3, 0xc3, 0xe7, 0xde,

    /* U+0063 "c" */
    0x3c, 0x67, 0xc3, 0xc0, 0xc0, 0xc0, 0xc0, 0xc3,
    0x67, 0x3c,

    /* U+0064 "d" */
    0x3, 0x3, 0x3, 0x7b, 0xe7, 0xc3, 0xc3, 0xc3,
    0xc3, 0xc3, 0xc3, 0xe7, 0x7b,

    /* U+0065 "e" */
    0x3c, 0x66, 0xc3, 0xc3, 0xff, 0xc0, 0xc0, 0xc3,
    0x67, 0x3c,

    /* U+0066 "f" */
    0xf, 0x8c, 0x6, 0x3, 0xf, 0xf8, 0xc0, 0x60,
    0x30, 0x18, 0xc, 0x6, 0x3, 0x1, 0x80,

    /* U+0067 "g" */
    0x7b, 0xe7, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xe7,
    0x7b, 0x3, 0x3, 0x3, 0x3e,

    /* U+0068 "h" */
    0xc0, 0xc0, 0xc0, 0xde, 0xe7, 0xc3, 0xc3, 0xc3,
    0xc3, 0xc3, 0xc3, 0xc3, 0xc3,

    /* U+0069 "i" */
    0x18, 0x18, 0x0, 0x0, 0xf8, 0x18, 0x18, 0x18,
    0x18, 0x18, 0x18, 0x18, 0x18, 0xff,

    /* U+006A "j" */
    0xc, 0x30, 0x0, 0x7c, 0x30, 0xc3, 0xc, 0x30,
    0xc3, 0xc, 0x30, 0xc6, 0xf0,

    /* U+006B "k" */
    0xc0, 0x60, 0x30, 0x18, 0x6c, 0x36, 0x33, 0x31,
    0xf0, 0xcc, 0x63, 0x31, 0x98, 0x6c, 0x10,

    /* U+006C "l" */
    0xf8, 0xc, 0x6, 0x3, 0x1, 0x80, 0xc0, 0x60,
    0x30, 0x18, 0xc, 0x6, 0x3, 0x0, 0xf8,

    /* U+006D "m" */
    0xd7, 0x7c, 0xf6, 0x7b, 0x3d, 0x9e, 0xcf, 0x67,
    0xb3, 0xd9, 0xec, 0xc0,

    /* U+006E "n" */
    0xde, 0xe7, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3,
    0xc3, 0xc3,

    /* U+006F "o" */
    0x3c, 0x66, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3,
    0x66, 0x3c,

    /* U+0070 "p" */
    0xde, 0xe7, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3,
    0xe6, 0xde, 0xc0, 0xc0, 0xc0,

    /* U+0071 "q" */
    0x7b, 0xe7, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3,
    0xe7, 0x7b, 0x3, 0x3, 0x3,

    /* U+0072 "r" */
    0xde, 0xe7, 0xc3, 0xc3, 0xc0, 0xc0, 0xc0, 0xc0,
    0xc0, 0xc0,

    /* U+0073 "s" */
    0x7e, 0xc3, 0xc0, 0xe0, 0xfe, 0x3f, 0x3, 0x3,
    0xc3, 0x7e,

    /* U+0074 "t" */
    0x18, 0x18, 0x18, 0xff, 0x18, 0x18, 0x18, 0x18,
    0x18, 0x18, 0x18, 0x18, 0xf,

    /* U+0075 "u" */
    0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3,
    0x66, 0x3c,

    /* U+0076 "v" */
    0xc1, 0xe0, 0x90, 0xcc, 0x66, 0x21, 0x30, 0xd8,
    0x68, 0x1c, 0xe, 0x0,

    /* U+0077 "w" */
    0x88, 0xcc, 0x65, 0x7a, 0xbd, 0x52, 0xa9, 0x54,
    0xca, 0x65, 0x31, 0x80,

    /* U+0078 "x" */
    0xc3, 0x31, 0x8d, 0x86, 0x81, 0xc0, 0xe0, 0xd8,
    0x4c, 0x63, 0x60, 0xc0,

    /* U+0079 "y" */
    0xc1, 0xa0, 0x98, 0xcc, 0x62, 0x61, 0xb0, 0x50,
    0x38, 0x1c, 0x4, 0x6, 0x3, 0x3, 0x0,

    /* U+007A "z" */
    0xfe, 0xc, 0x30, 0x41, 0x86, 0x8, 0x30, 0xc1,
    0xfc,

    /* U+007B "{" */
    0x7, 0xc, 0xc, 0xc, 0xc, 0xc, 0xc, 0x8,
    0xf8, 0xc, 0xc, 0xc, 0xc, 0xc, 0xc, 0xc,
    0x7,

    /* U+007C "|" */
    0xff, 0xff, 0xff, 0xff, 0xc0,

    /* U+007D "}" */
    0xf0, 0xc, 0x6, 0x3, 0x1, 0x80, 0xc0, 0x60,
    0x30, 0xf, 0x84, 0x6, 0x3, 0x1, 0x80, 0xc0,
    0x60, 0x30, 0xf0, 0x0,

    /* U+00A7 "§" */
    0x7e, 0xc7, 0xc0, 0xe0, 0x7c, 0x7e, 0xc3, 0xc3,
    0xc3, 0x74, 0x1e, 0x3, 0x3, 0xc3, 0x7e,

    /* U+00AB "«" */
    0x19, 0x99, 0x99, 0x99, 0x8c, 0xc3, 0x30, 0xcc,
    0x33,

    /* U+00B4 "´" */
    0x2f, 0x0,

    /* U+00BB "»" */
    0xcc, 0x33, 0xc, 0xc3, 0x31, 0x99, 0x99, 0x99,
    0x98,

    /* U+00C4 "Ä" */
    0x66, 0x66, 0x0, 0x0, 0x18, 0x3c, 0x3c, 0x2c,
    0x24, 0x66, 0x66, 0x42, 0x7e, 0xc3, 0xc3, 0xc3,
    0x81,

    /* U+00D6 "Ö" */
    0x66, 0x66, 0x0, 0x0, 0x3c, 0x66, 0xc3, 0xc3,
    0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0x66,
    0x3c,

    /* U+00DC "Ü" */
    0x66, 0x66, 0x0, 0x0, 0xc3, 0xc3, 0xc3, 0xc3,
    0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0x66,
    0x3c,

    /* U+00DF "ß" */
    0x3c, 0x66, 0xc3, 0xc3, 0xc3, 0xc7, 0xde, 0xc7,
    0xc3, 0xc3, 0xc3, 0xc6, 0xdc,

    /* U+00E4 "ä" */
    0x66, 0x66, 0x0, 0x0, 0x3c, 0x67, 0x3, 0x3,
    0x7f, 0xc3, 0xc3, 0xc3, 0xe7, 0x7b,

    /* U+00F6 "ö" */
    0x66, 0x66, 0x0, 0x0, 0x3c, 0x66, 0xc3, 0xc3,
    0xc3, 0xc3, 0xc3, 0xc3, 0x66, 0x3c,

    /* U+00FC "ü" */
    0x66, 0x66, 0x0, 0x0, 0xc3, 0xc3, 0xc3, 0xc3,
    0xc3, 0xc3, 0xc3, 0xc3, 0x66, 0x3c,

    /* U+20AC "€" */
    0x1f, 0x18, 0xd8, 0x2c, 0xf, 0xc3, 0x1, 0x81,
    0xf8, 0x60, 0x30, 0x58, 0x66, 0x31, 0xe0,

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
    {.bitmap_index = 0, .adv_w = 173, .box_w = 2, .box_h = 13, .ofs_x = 4, .ofs_y = 0},
    {.bitmap_index = 4, .adv_w = 173, .box_w = 5, .box_h = 5, .ofs_x = 3, .ofs_y = 8},
    {.bitmap_index = 8, .adv_w = 173, .box_w = 10, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 25, .adv_w = 173, .box_w = 8, .box_h = 18, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 43, .adv_w = 173, .box_w = 11, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 61, .adv_w = 173, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 76, .adv_w = 173, .box_w = 6, .box_h = 17, .ofs_x = 3, .ofs_y = -2},
    {.bitmap_index = 89, .adv_w = 173, .box_w = 6, .box_h = 17, .ofs_x = 2, .ofs_y = -2},
    {.bitmap_index = 102, .adv_w = 173, .box_w = 8, .box_h = 8, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 110, .adv_w = 173, .box_w = 4, .box_h = 6, .ofs_x = 3, .ofs_y = -3},
    {.bitmap_index = 113, .adv_w = 173, .box_w = 6, .box_h = 1, .ofs_x = 3, .ofs_y = 5},
    {.bitmap_index = 114, .adv_w = 173, .box_w = 3, .box_h = 3, .ofs_x = 4, .ofs_y = 0},
    {.bitmap_index = 116, .adv_w = 173, .box_w = 8, .box_h = 17, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 133, .adv_w = 173, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 146, .adv_w = 173, .box_w = 8, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 159, .adv_w = 173, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 172, .adv_w = 173, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 185, .adv_w = 173, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 198, .adv_w = 173, .box_w = 8, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 211, .adv_w = 173, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 226, .adv_w = 173, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 239, .adv_w = 173, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 252, .adv_w = 173, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 267, .adv_w = 173, .box_w = 3, .box_h = 10, .ofs_x = 4, .ofs_y = 0},
    {.bitmap_index = 271, .adv_w = 173, .box_w = 4, .box_h = 13, .ofs_x = 3, .ofs_y = -3},
    {.bitmap_index = 278, .adv_w = 173, .box_w = 8, .box_h = 10, .ofs_x = 2, .ofs_y = 1},
    {.bitmap_index = 288, .adv_w = 173, .box_w = 8, .box_h = 6, .ofs_x = 2, .ofs_y = 3},
    {.bitmap_index = 294, .adv_w = 173, .box_w = 8, .box_h = 10, .ofs_x = 2, .ofs_y = 1},
    {.bitmap_index = 304, .adv_w = 173, .box_w = 7, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 316, .adv_w = 173, .box_w = 10, .box_h = 16, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 336, .adv_w = 173, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 351, .adv_w = 173, .box_w = 8, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 364, .adv_w = 173, .box_w = 8, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 377, .adv_w = 173, .box_w = 8, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 390, .adv_w = 173, .box_w = 8, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 403, .adv_w = 173, .box_w = 8, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 416, .adv_w = 173, .box_w = 8, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 429, .adv_w = 173, .box_w = 8, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 442, .adv_w = 173, .box_w = 7, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 454, .adv_w = 173, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 467, .adv_w = 173, .box_w = 9, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 482, .adv_w = 173, .box_w = 8, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 495, .adv_w = 173, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 508, .adv_w = 173, .box_w = 8, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 521, .adv_w = 173, .box_w = 8, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 534, .adv_w = 173, .box_w = 8, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 547, .adv_w = 173, .box_w = 8, .box_h = 16, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 563, .adv_w = 173, .box_w = 8, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 576, .adv_w = 173, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 589, .adv_w = 173, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 604, .adv_w = 173, .box_w = 8, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 617, .adv_w = 173, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 632, .adv_w = 173, .box_w = 10, .box_h = 13, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 649, .adv_w = 173, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 664, .adv_w = 173, .box_w = 10, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 681, .adv_w = 173, .box_w = 8, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 694, .adv_w = 173, .box_w = 5, .box_h = 17, .ofs_x = 4, .ofs_y = -2},
    {.bitmap_index = 705, .adv_w = 173, .box_w = 8, .box_h = 17, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 722, .adv_w = 173, .box_w = 5, .box_h = 17, .ofs_x = 2, .ofs_y = -2},
    {.bitmap_index = 733, .adv_w = 173, .box_w = 8, .box_h = 7, .ofs_x = 1, .ofs_y = 6},
    {.bitmap_index = 740, .adv_w = 173, .box_w = 9, .box_h = 1, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 742, .adv_w = 173, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 752, .adv_w = 173, .box_w = 8, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 765, .adv_w = 173, .box_w = 8, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 775, .adv_w = 173, .box_w = 8, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 788, .adv_w = 173, .box_w = 8, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 798, .adv_w = 173, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 813, .adv_w = 173, .box_w = 8, .box_h = 13, .ofs_x = 2, .ofs_y = -3},
    {.bitmap_index = 826, .adv_w = 173, .box_w = 8, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 839, .adv_w = 173, .box_w = 8, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 853, .adv_w = 173, .box_w = 6, .box_h = 17, .ofs_x = 2, .ofs_y = -3},
    {.bitmap_index = 866, .adv_w = 173, .box_w = 9, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 881, .adv_w = 173, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 896, .adv_w = 173, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 908, .adv_w = 173, .box_w = 8, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 918, .adv_w = 173, .box_w = 8, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 928, .adv_w = 173, .box_w = 8, .box_h = 13, .ofs_x = 2, .ofs_y = -3},
    {.bitmap_index = 941, .adv_w = 173, .box_w = 8, .box_h = 13, .ofs_x = 2, .ofs_y = -3},
    {.bitmap_index = 954, .adv_w = 173, .box_w = 8, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 964, .adv_w = 173, .box_w = 8, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 974, .adv_w = 173, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 987, .adv_w = 173, .box_w = 8, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 997, .adv_w = 173, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1009, .adv_w = 173, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1021, .adv_w = 173, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1033, .adv_w = 173, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 1048, .adv_w = 173, .box_w = 7, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1057, .adv_w = 173, .box_w = 8, .box_h = 17, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 1074, .adv_w = 173, .box_w = 2, .box_h = 17, .ofs_x = 5, .ofs_y = -2},
    {.bitmap_index = 1079, .adv_w = 173, .box_w = 9, .box_h = 17, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 1099, .adv_w = 173, .box_w = 8, .box_h = 15, .ofs_x = 2, .ofs_y = -2},
    {.bitmap_index = 1114, .adv_w = 173, .box_w = 9, .box_h = 8, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 1123, .adv_w = 173, .box_w = 3, .box_h = 3, .ofs_x = 4, .ofs_y = 12},
    {.bitmap_index = 1125, .adv_w = 173, .box_w = 9, .box_h = 8, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 1134, .adv_w = 173, .box_w = 8, .box_h = 17, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1151, .adv_w = 173, .box_w = 8, .box_h = 17, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1168, .adv_w = 173, .box_w = 8, .box_h = 17, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1185, .adv_w = 173, .box_w = 8, .box_h = 13, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1198, .adv_w = 173, .box_w = 8, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1212, .adv_w = 173, .box_w = 8, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1226, .adv_w = 173, .box_w = 8, .box_h = 14, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 1240, .adv_w = 173, .box_w = 9, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 1255, .adv_w = 173, .box_w = 9, .box_h = 9, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 1266, .adv_w = 173, .box_w = 10, .box_h = 22, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 1294, .adv_w = 173, .box_w = 11, .box_h = 11, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 1310, .adv_w = 173, .box_w = 11, .box_h = 11, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 1326, .adv_w = 173, .box_w = 11, .box_h = 11, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 1342, .adv_w = 173, .box_w = 11, .box_h = 11, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 1358, .adv_w = 173, .box_w = 7, .box_h = 13, .ofs_x = 2, .ofs_y = 0}
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
const lv_font_t jetbrains_mono_regular_18 = {
#else
lv_font_t jetbrains_mono_regular_18 = {
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



#endif /*#if JETBRAINS_MONO_REGULAR_18*/

