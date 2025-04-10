/*******************************************************************************
 * Size: 14 px
 * Bpp: 1
 * Opts: --bpp 1 --size 14 --no-compress --font JetBrainsMono-Bold.ttf --symbols abcdefghijklmnopqrstuvwxyz.,-öäü+#´ß?ÄÖÜ<>|;:_{[]}\@€ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890^!"§$%&/()=?░❱◎↘◌◩«■» --format lvgl -o jetbrains_mono_bold_14.c
 ******************************************************************************/

#include "lvgl.h"

#ifndef JETBRAINS_MONO_BOLD_14
#define JETBRAINS_MONO_BOLD_14 1
#endif

#if JETBRAINS_MONO_BOLD_14

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0021 "!" */
    0xff, 0xfc, 0x30,

    /* U+0022 "\"" */
    0xde, 0xf7, 0xb0,

    /* U+0023 "#" */
    0x12, 0x14, 0x7f, 0x24, 0x24, 0x24, 0xfe, 0x2c,
    0x68, 0x48,

    /* U+0024 "$" */
    0x10, 0x21, 0xf7, 0xfd, 0x7a, 0x1c, 0x1c, 0x17,
    0xaf, 0xfb, 0xe1, 0x2, 0x0,

    /* U+0025 "%" */
    0xf1, 0x92, 0x94, 0xf4, 0x8, 0x16, 0x29, 0x29,
    0x49, 0x86,

    /* U+0026 "&" */
    0x79, 0x9b, 0x3, 0x6, 0x1e, 0xf7, 0x66, 0xcc,
    0xec,

    /* U+0028 "(" */
    0x19, 0xd9, 0x8c, 0x63, 0x18, 0xc6, 0x38, 0xe3,
    0x84,

    /* U+0029 ")" */
    0xc7, 0xc, 0x31, 0x8c, 0x63, 0x18, 0xce, 0xee,
    0x40,

    /* U+002B "+" */
    0x30, 0x60, 0xc7, 0xf3, 0x6, 0xc, 0x0,

    /* U+002C "," */
    0x6d, 0x60,

    /* U+002D "-" */
    0xf0,

    /* U+002E "." */
    0xc0,

    /* U+002F "/" */
    0x6, 0x18, 0x30, 0x41, 0x83, 0x4, 0x18, 0x30,
    0xc1, 0x83, 0xc, 0x18, 0x0,

    /* U+0030 "0" */
    0x7d, 0x8f, 0x1e, 0x3f, 0x78, 0xf1, 0xe3, 0xc6,
    0xf8,

    /* U+0031 "1" */
    0x39, 0xf3, 0x60, 0xc1, 0x83, 0x6, 0xc, 0x19,
    0xfc,

    /* U+0032 "2" */
    0x7b, 0x3c, 0xc3, 0x1c, 0x63, 0x9c, 0xe3, 0xf0,

    /* U+0033 "3" */
    0xfc, 0x18, 0x41, 0xe0, 0x60, 0xc1, 0xe3, 0xc6,
    0xf8,

    /* U+0034 "4" */
    0x18, 0x63, 0x1c, 0x6f, 0x3c, 0xff, 0xc, 0x30,

    /* U+0035 "5" */
    0xff, 0x83, 0x7, 0xec, 0x60, 0xc1, 0x83, 0xc6,
    0xf8,

    /* U+0036 "6" */
    0x18, 0x60, 0xc3, 0x7, 0xd9, 0xf1, 0xe3, 0xc6,
    0x78,

    /* U+0037 "7" */
    0xff, 0x8f, 0x10, 0x60, 0xc3, 0x6, 0x8, 0x30,
    0x60,

    /* U+0038 "8" */
    0x7d, 0x8f, 0x1f, 0x77, 0xcf, 0xb1, 0xe3, 0xc6,
    0xf8,

    /* U+0039 "9" */
    0x7d, 0x9f, 0x1e, 0x3c, 0x6f, 0x83, 0xc, 0x18,
    0x60,

    /* U+003A ":" */
    0xc0, 0x3,

    /* U+003B ";" */
    0x60, 0x0, 0x3, 0x6b, 0x0,

    /* U+003C "<" */
    0x2, 0x1c, 0xe7, 0xc, 0xe, 0x7, 0x3,

    /* U+003D "=" */
    0xfc, 0x0, 0x0, 0xfc,

    /* U+003E ">" */
    0x1, 0x81, 0xe0, 0xf0, 0x67, 0xbc, 0x60,

    /* U+003F "?" */
    0xf8, 0x30, 0xc3, 0x79, 0x86, 0x0, 0x1, 0x80,

    /* U+0040 "@" */
    0x3c, 0x66, 0xc3, 0xdf, 0xf3, 0xf3, 0xf3, 0xf3,
    0xf3, 0xdf, 0xc0, 0x60, 0x38,

    /* U+0041 "A" */
    0x18, 0x1c, 0x3c, 0x34, 0x34, 0x26, 0x7e, 0x62,
    0x63, 0x43,

    /* U+0042 "B" */
    0xfd, 0x8f, 0x1e, 0x3f, 0x98, 0xf1, 0xe3, 0xc7,
    0xf8,

    /* U+0043 "C" */
    0x7d, 0x8f, 0x1e, 0xc, 0x18, 0x30, 0x63, 0xc6,
    0xf8,

    /* U+0044 "D" */
    0xf9, 0x8f, 0x1e, 0x3c, 0x78, 0xf1, 0xe3, 0xc7,
    0xf0,

    /* U+0045 "E" */
    0xff, 0xc, 0x30, 0xff, 0xc, 0x30, 0xc3, 0xf0,

    /* U+0046 "F" */
    0xff, 0x83, 0x6, 0xf, 0xd8, 0x30, 0x60, 0xc1,
    0x80,

    /* U+0047 "G" */
    0x7d, 0x8f, 0x1e, 0xc, 0x1b, 0xf1, 0xe3, 0xc6,
    0xf8,

    /* U+0048 "H" */
    0xcf, 0x3c, 0xf3, 0xff, 0x3c, 0xf3, 0xcf, 0x30,

    /* U+0049 "I" */
    0xfc, 0xc3, 0xc, 0x30, 0xc3, 0xc, 0x33, 0xf0,

    /* U+004A "J" */
    0x1e, 0xc, 0x18, 0x30, 0x60, 0xc1, 0xe3, 0xc6,
    0xf8,

    /* U+004B "K" */
    0xc7, 0x9b, 0x36, 0xcf, 0x9b, 0x33, 0x66, 0xc5,
    0x8c,

    /* U+004C "L" */
    0xc3, 0xc, 0x30, 0xc3, 0xc, 0x30, 0xc3, 0xf0,

    /* U+004D "M" */
    0xef, 0xdf, 0xbf, 0x7f, 0x7a, 0xf1, 0xe3, 0xc7,
    0x8c,

    /* U+004E "N" */
    0xe7, 0xcf, 0x9f, 0xbd, 0x7a, 0xf7, 0xe7, 0xcf,
    0x9c,

    /* U+004F "O" */
    0x7b, 0x3c, 0xf3, 0xcf, 0x3c, 0xf3, 0xcd, 0xe0,

    /* U+0050 "P" */
    0xfd, 0x8f, 0x1e, 0x3c, 0x7f, 0xb0, 0x60, 0xc1,
    0x80,

    /* U+0051 "Q" */
    0x7d, 0x8f, 0x1e, 0x3c, 0x78, 0xf1, 0xe3, 0xc6,
    0xf8, 0x30, 0x60, 0x60,

    /* U+0052 "R" */
    0xfd, 0x8f, 0x1e, 0x3c, 0x7f, 0xb6, 0x66, 0xcd,
    0x8c,

    /* U+0053 "S" */
    0x7d, 0x8f, 0x7, 0xf, 0xcf, 0xc3, 0x83, 0xc6,
    0xf8,

    /* U+0054 "T" */
    0xfe, 0x30, 0x60, 0xc1, 0x83, 0x6, 0xc, 0x18,
    0x30,

    /* U+0055 "U" */
    0xcf, 0x3c, 0xf3, 0xcf, 0x3c, 0xf3, 0xcd, 0xe0,

    /* U+0056 "V" */
    0x43, 0x63, 0x62, 0x66, 0x26, 0x36, 0x34, 0x3c,
    0x1c, 0x18,

    /* U+0057 "W" */
    0x9b, 0x9b, 0xda, 0xda, 0xea, 0xea, 0xea, 0x6e,
    0x66, 0x66,

    /* U+0058 "X" */
    0x63, 0x66, 0x34, 0x3c, 0x18, 0x1c, 0x3c, 0x36,
    0x66, 0x63,

    /* U+0059 "Y" */
    0xc3, 0x66, 0x66, 0x34, 0x3c, 0x18, 0x18, 0x18,
    0x18, 0x18,

    /* U+005A "Z" */
    0xfc, 0x31, 0x86, 0x30, 0xc6, 0x18, 0xc3, 0xf0,

    /* U+005B "[" */
    0xfc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcc, 0xf0,

    /* U+005C "\\" */
    0xc1, 0x81, 0x3, 0x6, 0x4, 0xc, 0x18, 0x18,
    0x30, 0x60, 0x60, 0xc0, 0x80,

    /* U+005D "]" */
    0xf3, 0x33, 0x33, 0x33, 0x33, 0x33, 0xf0,

    /* U+005E "^" */
    0x30, 0xc7, 0x9a, 0x4f, 0x10,

    /* U+005F "_" */
    0xfe,

    /* U+0061 "a" */
    0x3c, 0xcc, 0x1b, 0xfc, 0x78, 0xf1, 0xbf,

    /* U+0062 "b" */
    0xc3, 0xf, 0xb3, 0xcf, 0x3c, 0xf3, 0xcf, 0xe0,

    /* U+0063 "c" */
    0x79, 0x8b, 0x16, 0xc, 0x18, 0xf1, 0x3c,

    /* U+0064 "d" */
    0xc, 0x37, 0xf3, 0xcf, 0x3c, 0xf3, 0xcd, 0xf0,

    /* U+0065 "e" */
    0x7d, 0x8f, 0x1f, 0xfc, 0x18, 0x31, 0xbe,

    /* U+0066 "f" */
    0x1e, 0x60, 0xc7, 0xf3, 0x6, 0xc, 0x18, 0x30,
    0x60,

    /* U+0067 "g" */
    0x6f, 0x7c, 0xf3, 0xcf, 0x3c, 0xdf, 0xc, 0x37,
    0x80,

    /* U+0068 "h" */
    0xc3, 0xd, 0xbb, 0xcf, 0x3c, 0xf3, 0xcf, 0x30,

    /* U+0069 "i" */
    0x30, 0x0, 0x7, 0x83, 0x6, 0xc, 0x18, 0x30,
    0x63, 0xf8,

    /* U+006A "j" */
    0x18, 0x3e, 0x31, 0x8c, 0x63, 0x18, 0xc6, 0x3f,
    0x0,

    /* U+006B "k" */
    0xc1, 0x83, 0x1e, 0x6c, 0x9f, 0x36, 0x66, 0xcd,
    0x8c,

    /* U+006C "l" */
    0xf8, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18, 0x18,
    0x18, 0xf,

    /* U+006D "m" */
    0xfd, 0xaf, 0x5e, 0xbd, 0x7a, 0xf5, 0xeb,

    /* U+006E "n" */
    0xdb, 0xbc, 0xf3, 0xcf, 0x3c, 0xf3,

    /* U+006F "o" */
    0x7d, 0x8f, 0x1e, 0x3c, 0x78, 0xf1, 0xbe,

    /* U+0070 "p" */
    0xdb, 0xbc, 0xf3, 0xcf, 0x3c, 0xfe, 0xc3, 0xc,
    0x0,

    /* U+0071 "q" */
    0x77, 0x5c, 0xf1, 0xc7, 0x1c, 0xdd, 0x4, 0x10,
    0x40,

    /* U+0072 "r" */
    0xdd, 0xdf, 0x1e, 0x3c, 0x18, 0x30, 0x60,

    /* U+0073 "s" */
    0x7b, 0x3c, 0x3e, 0x7c, 0x3c, 0xde,

    /* U+0074 "t" */
    0x30, 0x63, 0xf9, 0x83, 0x6, 0xc, 0x18, 0x30,
    0x3c,

    /* U+0075 "u" */
    0xcf, 0x3c, 0xf3, 0xcf, 0x3c, 0xde,

    /* U+0076 "v" */
    0xc7, 0x8b, 0x32, 0x66, 0x8f, 0xe, 0x1c,

    /* U+0077 "w" */
    0xd9, 0xdb, 0x5b, 0x5b, 0x56, 0x56, 0x66, 0x66,

    /* U+0078 "x" */
    0x66, 0x36, 0x3c, 0x18, 0x1c, 0x3c, 0x66, 0x63,

    /* U+0079 "y" */
    0xc7, 0x8b, 0x33, 0x66, 0x87, 0xe, 0x18, 0x30,
    0x61, 0x80,

    /* U+007A "z" */
    0xfc, 0x31, 0x8c, 0x31, 0x8c, 0x3f,

    /* U+007B "{" */
    0xe, 0x30, 0x60, 0xc1, 0x83, 0x3c, 0xc, 0x18,
    0x30, 0x60, 0xc0, 0xe0,

    /* U+007C "|" */
    0xff, 0xff, 0xff, 0xc0,

    /* U+007D "}" */
    0xe0, 0x60, 0xc1, 0x83, 0x6, 0x7, 0x98, 0x30,
    0x60, 0xc1, 0x8e, 0x0,

    /* U+00A7 "§" */
    0x7d, 0x8f, 0x3, 0xc6, 0xf8, 0xf1, 0xfe, 0x3c,
    0xf, 0x1b, 0xe0,

    /* U+00AB "«" */
    0x33, 0x36, 0x6c, 0xcc, 0x6c, 0x36, 0x33,

    /* U+00B4 "´" */
    0xc0,

    /* U+00BB "»" */
    0x6c, 0x66, 0x32, 0x1b, 0x32, 0x66, 0x6c,

    /* U+00C4 "Ä" */
    0x6c, 0x0, 0x1, 0xc3, 0x85, 0xa, 0x36, 0x6c,
    0xf9, 0x16, 0x3c, 0x60,

    /* U+00D6 "Ö" */
    0x6c, 0x0, 0x1e, 0xcf, 0x3c, 0xf3, 0xcf, 0x3c,
    0xf3, 0x78,

    /* U+00DC "Ü" */
    0x6c, 0x0, 0x33, 0xcf, 0x3c, 0xf3, 0xcf, 0x3c,
    0xf3, 0x78,

    /* U+00DF "ß" */
    0x7d, 0x8f, 0x1e, 0x3d, 0xd8, 0xf1, 0xe3, 0xc7,
    0xb8,

    /* U+00E4 "ä" */
    0x6c, 0x0, 0x1, 0xe6, 0x60, 0xdf, 0xe3, 0xc7,
    0x8d, 0xf8,

    /* U+00F6 "ö" */
    0x6c, 0x0, 0x3, 0xec, 0x78, 0xf1, 0xe3, 0xc7,
    0x8d, 0xf0,

    /* U+00FC "ü" */
    0x6c, 0x0, 0x33, 0xcf, 0x3c, 0xf3, 0xcf, 0x37,
    0x80,

    /* U+20AC "€" */
    0x3e, 0x63, 0x63, 0xf8, 0x60, 0xf8, 0x60, 0x63,
    0x37, 0x1e,

    /* U+2198 "↘" */
    0x0, 0x40, 0x21, 0x11, 0x9, 0x5, 0x3, 0x3f,

    /* U+2591 "░" */
    0xd5, 0x0, 0x95, 0xd5, 0x0, 0xd5, 0x0, 0x95,
    0xd5, 0x0, 0xd5, 0x0, 0x95, 0xd5, 0x0, 0x95,
    0xd5,

    /* U+25A0 "■" */
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,

    /* U+25CC "◌" */
    0x1c, 0x31, 0x90, 0x50, 0x18, 0xc, 0x5, 0x4,
    0xc6, 0x1c, 0x0,

    /* U+25CE "◎" */
    0x3e, 0x31, 0xb0, 0x73, 0x19, 0x4c, 0xa7, 0x76,
    0xc6, 0x3e, 0x0,

    /* U+25E9 "◩" */
    0xff, 0xff, 0xff, 0xbf, 0x9f, 0x8f, 0x87, 0x83,
    0x81, 0xff, 0x80,

    /* U+2771 "❱" */
    0x71, 0xe7, 0x8e, 0x3c, 0xf3, 0x9e, 0x79, 0xc0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 134, .box_w = 2, .box_h = 10, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 3, .adv_w = 134, .box_w = 5, .box_h = 4, .ofs_x = 2, .ofs_y = 6},
    {.bitmap_index = 6, .adv_w = 134, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 16, .adv_w = 134, .box_w = 7, .box_h = 14, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 29, .adv_w = 134, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 39, .adv_w = 134, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 48, .adv_w = 134, .box_w = 5, .box_h = 14, .ofs_x = 2, .ofs_y = -2},
    {.bitmap_index = 57, .adv_w = 134, .box_w = 5, .box_h = 14, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 66, .adv_w = 134, .box_w = 7, .box_h = 7, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 73, .adv_w = 134, .box_w = 3, .box_h = 4, .ofs_x = 2, .ofs_y = -3},
    {.bitmap_index = 75, .adv_w = 134, .box_w = 4, .box_h = 1, .ofs_x = 2, .ofs_y = 4},
    {.bitmap_index = 76, .adv_w = 134, .box_w = 2, .box_h = 1, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 77, .adv_w = 134, .box_w = 7, .box_h = 14, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 90, .adv_w = 134, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 99, .adv_w = 134, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 108, .adv_w = 134, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 116, .adv_w = 134, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 125, .adv_w = 134, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 133, .adv_w = 134, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 142, .adv_w = 134, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 151, .adv_w = 134, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 160, .adv_w = 134, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 169, .adv_w = 134, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 178, .adv_w = 134, .box_w = 2, .box_h = 8, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 180, .adv_w = 134, .box_w = 3, .box_h = 11, .ofs_x = 2, .ofs_y = -3},
    {.bitmap_index = 185, .adv_w = 134, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 192, .adv_w = 134, .box_w = 6, .box_h = 5, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 196, .adv_w = 134, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 203, .adv_w = 134, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 211, .adv_w = 134, .box_w = 8, .box_h = 13, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 224, .adv_w = 134, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 234, .adv_w = 134, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 243, .adv_w = 134, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 252, .adv_w = 134, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 261, .adv_w = 134, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 269, .adv_w = 134, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 278, .adv_w = 134, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 287, .adv_w = 134, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 295, .adv_w = 134, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 303, .adv_w = 134, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 312, .adv_w = 134, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 321, .adv_w = 134, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 329, .adv_w = 134, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 338, .adv_w = 134, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 347, .adv_w = 134, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 355, .adv_w = 134, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 364, .adv_w = 134, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 376, .adv_w = 134, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 385, .adv_w = 134, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 394, .adv_w = 134, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 403, .adv_w = 134, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 411, .adv_w = 134, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 421, .adv_w = 134, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 431, .adv_w = 134, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 441, .adv_w = 134, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 451, .adv_w = 134, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 459, .adv_w = 134, .box_w = 4, .box_h = 13, .ofs_x = 3, .ofs_y = -1},
    {.bitmap_index = 466, .adv_w = 134, .box_w = 7, .box_h = 14, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 479, .adv_w = 134, .box_w = 4, .box_h = 13, .ofs_x = 2, .ofs_y = -1},
    {.bitmap_index = 486, .adv_w = 134, .box_w = 6, .box_h = 6, .ofs_x = 1, .ofs_y = 5},
    {.bitmap_index = 491, .adv_w = 134, .box_w = 7, .box_h = 1, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 492, .adv_w = 134, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 499, .adv_w = 134, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 507, .adv_w = 134, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 514, .adv_w = 134, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 522, .adv_w = 134, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 529, .adv_w = 134, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 538, .adv_w = 134, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 547, .adv_w = 134, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 555, .adv_w = 134, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 565, .adv_w = 134, .box_w = 5, .box_h = 13, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 574, .adv_w = 134, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 583, .adv_w = 134, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 593, .adv_w = 134, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 600, .adv_w = 134, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 606, .adv_w = 134, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 613, .adv_w = 134, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 622, .adv_w = 134, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 631, .adv_w = 134, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 638, .adv_w = 134, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 644, .adv_w = 134, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 653, .adv_w = 134, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 659, .adv_w = 134, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 666, .adv_w = 134, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 674, .adv_w = 134, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 682, .adv_w = 134, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 692, .adv_w = 134, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 698, .adv_w = 134, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 710, .adv_w = 134, .box_w = 2, .box_h = 13, .ofs_x = 3, .ofs_y = -2},
    {.bitmap_index = 714, .adv_w = 134, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 726, .adv_w = 134, .box_w = 7, .box_h = 12, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 737, .adv_w = 134, .box_w = 8, .box_h = 7, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 744, .adv_w = 134, .box_w = 3, .box_h = 1, .ofs_x = 3, .ofs_y = 10},
    {.bitmap_index = 745, .adv_w = 134, .box_w = 8, .box_h = 7, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 752, .adv_w = 134, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 764, .adv_w = 134, .box_w = 6, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 774, .adv_w = 134, .box_w = 6, .box_h = 13, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 784, .adv_w = 134, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 793, .adv_w = 134, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 803, .adv_w = 134, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 813, .adv_w = 134, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 822, .adv_w = 134, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 832, .adv_w = 134, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 840, .adv_w = 134, .box_w = 8, .box_h = 17, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 857, .adv_w = 134, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 865, .adv_w = 134, .box_w = 9, .box_h = 9, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 876, .adv_w = 134, .box_w = 9, .box_h = 9, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 887, .adv_w = 134, .box_w = 9, .box_h = 9, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 898, .adv_w = 134, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0}
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
const lv_font_t jetbrains_mono_bold_14 = {
#else
lv_font_t jetbrains_mono_bold_14 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 17,          /*The maximum line height required by the font*/
    .base_line = 3,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -2,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
#if LV_VERSION_CHECK(8, 2, 0) || LVGL_VERSION_MAJOR >= 9
    .fallback = &lv_font_montserrat_12,
#endif
    .user_data = NULL,
};



#endif /*#if JETBRAINS_MONO_BOLD_14*/

