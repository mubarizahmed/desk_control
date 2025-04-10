/*******************************************************************************
 * Size: 12 px
 * Bpp: 1
 * Opts: --bpp 1 --size 12 --no-compress --font JetBrainsMono-Bold.ttf --symbols abcdefghijklmnopqrstuvwxyz.,-öäü+#´ß?ÄÖÜ<>|;:_{[]}\@€ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890^!"§$%&/()=?░❱◎↘◌◩«■»° --format lvgl -o jetbrains_mono_bold_12.c
 ******************************************************************************/

#include "lvgl.h"

#ifndef JETBRAINS_MONO_BOLD_12
#define JETBRAINS_MONO_BOLD_12 1
#endif

#if JETBRAINS_MONO_BOLD_12

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0021 "!" */
    0xff, 0xf0, 0xc0,

    /* U+0022 "\"" */
    0xff, 0xff,

    /* U+0023 "#" */
    0x24, 0xaf, 0xd2, 0x49, 0x2f, 0xd4, 0x90,

    /* U+0024 "$" */
    0x20, 0x8f, 0xbb, 0xe3, 0xc7, 0x8b, 0xef, 0xf7,
    0x88, 0x20,

    /* U+0025 "%" */
    0xe3, 0x4a, 0xa7, 0x41, 0x7, 0xcc, 0xa9, 0x9e,

    /* U+0026 "&" */
    0x79, 0x93, 0x3, 0x6, 0x1e, 0xb7, 0x64, 0x74,

    /* U+0028 "(" */
    0x3, 0x6c, 0xcc, 0xcc, 0xcc, 0x63, 0x0,

    /* U+0029 ")" */
    0x87, 0xc, 0x31, 0x8c, 0x63, 0x18, 0xdd, 0xc8,
    0x0,

    /* U+002B "+" */
    0x30, 0xc3, 0x3f, 0x30, 0xc0,

    /* U+002C "," */
    0x5b, 0x40,

    /* U+002D "-" */
    0xf0,

    /* U+002E "." */
    0xf0,

    /* U+002F "/" */
    0x8, 0xc6, 0x23, 0x18, 0x8c, 0x62, 0x31, 0x0,

    /* U+0030 "0" */
    0x7b, 0x3c, 0xf3, 0xff, 0x3c, 0xf3, 0x78,

    /* U+0031 "1" */
    0x73, 0xcb, 0xc, 0x30, 0xc3, 0xc, 0xfc,

    /* U+0032 "2" */
    0x7a, 0x38, 0xc3, 0x18, 0xe6, 0x30, 0xfc,

    /* U+0033 "3" */
    0x7c, 0x63, 0xe, 0xc, 0x34, 0xd3, 0x78,

    /* U+0034 "4" */
    0x18, 0x63, 0x18, 0xef, 0x3f, 0xc3, 0xc,

    /* U+0035 "5" */
    0xff, 0xc, 0x3e, 0xcc, 0x30, 0xf3, 0x78,

    /* U+0036 "6" */
    0x10, 0x86, 0x16, 0xef, 0x3c, 0xf3, 0x78,

    /* U+0037 "7" */
    0xff, 0x30, 0x82, 0x18, 0x43, 0xc, 0x20,

    /* U+0038 "8" */
    0x7b, 0x3c, 0xff, 0x7b, 0xfc, 0xf3, 0x78,

    /* U+0039 "9" */
    0x7b, 0x3c, 0xf3, 0x7c, 0x61, 0x8c, 0x20,

    /* U+003A ":" */
    0xf0, 0x3c,

    /* U+003B ";" */
    0x6c, 0x0, 0xd2, 0xc0,

    /* U+003C "<" */
    0x4, 0x77, 0x30, 0xe0, 0xe0, 0xc0,

    /* U+003D "=" */
    0xf8, 0x1, 0xf0,

    /* U+003E ">" */
    0x3, 0x7, 0x7, 0x1d, 0xcc, 0x0,

    /* U+003F "?" */
    0xf0, 0xc6, 0x37, 0x30, 0x0, 0x60,

    /* U+0040 "@" */
    0x7b, 0x38, 0x6f, 0xa6, 0x9a, 0x6f, 0x83, 0x7,
    0x0,

    /* U+0041 "A" */
    0x38, 0x70, 0xa1, 0x42, 0xcd, 0x9f, 0x22, 0x46,

    /* U+0042 "B" */
    0xfb, 0x3c, 0xf3, 0xf3, 0x3c, 0xf3, 0xf8,

    /* U+0043 "C" */
    0x7b, 0x2c, 0x30, 0xc3, 0xc, 0x32, 0x78,

    /* U+0044 "D" */
    0xfb, 0x3c, 0xf3, 0xcf, 0x3c, 0xf3, 0xf8,

    /* U+0045 "E" */
    0xff, 0xc, 0x30, 0xfb, 0xc, 0x30, 0xfc,

    /* U+0046 "F" */
    0xff, 0xc, 0x30, 0xff, 0xc, 0x30, 0xc0,

    /* U+0047 "G" */
    0x7b, 0x3c, 0x30, 0xdf, 0x3c, 0xf3, 0x78,

    /* U+0048 "H" */
    0xcf, 0x3c, 0xf3, 0xff, 0x3c, 0xf3, 0xcc,

    /* U+0049 "I" */
    0xf9, 0x8c, 0x63, 0x18, 0xc6, 0xf8,

    /* U+004A "J" */
    0x1c, 0x30, 0xc3, 0xc, 0x3c, 0xf3, 0x78,

    /* U+004B "K" */
    0xcf, 0x3c, 0xb6, 0xf3, 0x6c, 0xb3, 0xc4,

    /* U+004C "L" */
    0xc3, 0xc, 0x30, 0xc3, 0xc, 0x30, 0xfc,

    /* U+004D "M" */
    0xcf, 0xff, 0xff, 0xff, 0x3c, 0xf3, 0xcc,

    /* U+004E "N" */
    0xcf, 0xbe, 0xfb, 0xdf, 0x7d, 0xf7, 0xcc,

    /* U+004F "O" */
    0x7b, 0x3c, 0xf3, 0xcf, 0x3c, 0xf3, 0x78,

    /* U+0050 "P" */
    0xfb, 0x3c, 0xf3, 0xfb, 0xc, 0x30, 0xc0,

    /* U+0051 "Q" */
    0x7b, 0x3c, 0xf3, 0xcf, 0x3c, 0xf3, 0x78, 0x60,
    0xc0,

    /* U+0052 "R" */
    0xfb, 0x3c, 0xf3, 0xfb, 0x4d, 0xb2, 0xcc,

    /* U+0053 "S" */
    0x7b, 0x3c, 0x38, 0x78, 0x70, 0xf3, 0x78,

    /* U+0054 "T" */
    0xfc, 0xc3, 0xc, 0x30, 0xc3, 0xc, 0x30,

    /* U+0055 "U" */
    0xcf, 0x3c, 0xf3, 0xcf, 0x3c, 0xf3, 0x78,

    /* U+0056 "V" */
    0x46, 0x89, 0x93, 0x62, 0xc5, 0xa, 0x1c, 0x38,

    /* U+0057 "W" */
    0x93, 0xef, 0xdf, 0x76, 0xcd, 0x9b, 0x36, 0x6c,

    /* U+0058 "X" */
    0x44, 0xd8, 0xa1, 0xc1, 0x87, 0xb, 0x36, 0x46,

    /* U+0059 "Y" */
    0x42, 0x66, 0x24, 0x3c, 0x3c, 0x18, 0x18, 0x18,
    0x18,

    /* U+005A "Z" */
    0xf8, 0xc4, 0x62, 0x31, 0x18, 0xf8,

    /* U+005B "[" */
    0xfc, 0xcc, 0xcc, 0xcc, 0xcc, 0xcf,

    /* U+005C "\\" */
    0x86, 0x10, 0xc6, 0x10, 0xc6, 0x10, 0xc6, 0x10,

    /* U+005D "]" */
    0xf3, 0x33, 0x33, 0x33, 0x33, 0x3f,

    /* U+005E "^" */
    0x33, 0x95, 0xb8, 0x80,

    /* U+005F "_" */
    0xfc,

    /* U+0061 "a" */
    0x79, 0x30, 0xdf, 0xcf, 0x37, 0xc0,

    /* U+0062 "b" */
    0xc3, 0xf, 0xb3, 0xcf, 0x3c, 0xf3, 0xf8,

    /* U+0063 "c" */
    0x7b, 0x2c, 0x30, 0xc3, 0x27, 0x80,

    /* U+0064 "d" */
    0xc, 0x37, 0xf3, 0xcf, 0x3c, 0xf3, 0x7c,

    /* U+0065 "e" */
    0x7b, 0x3c, 0xff, 0xc3, 0x37, 0x80,

    /* U+0066 "f" */
    0x1c, 0xc3, 0x3f, 0x30, 0xc3, 0xc, 0x30,

    /* U+0067 "g" */
    0x6f, 0x7c, 0xf3, 0xcd, 0xf0, 0xc3, 0x78,

    /* U+0068 "h" */
    0xc3, 0xd, 0xbb, 0xcf, 0x3c, 0xf3, 0xcc,

    /* U+0069 "i" */
    0x0, 0xc0, 0x3c, 0x30, 0xc3, 0xc, 0x33, 0xf0,

    /* U+006A "j" */
    0x0, 0xc0, 0xf1, 0x8c, 0x63, 0x18, 0xc7, 0xe0,

    /* U+006B "k" */
    0xc3, 0xc, 0xf3, 0xdb, 0xcd, 0xb3, 0xcc,

    /* U+006C "l" */
    0xf0, 0x60, 0xc1, 0x83, 0x6, 0xc, 0x18, 0x1e,

    /* U+006D "m" */
    0xff, 0xbe, 0xfb, 0xef, 0xbe, 0xc0,

    /* U+006E "n" */
    0xdb, 0xbc, 0xf3, 0xcf, 0x3c, 0xc0,

    /* U+006F "o" */
    0x7b, 0x3c, 0xf3, 0xcf, 0x37, 0x80,

    /* U+0070 "p" */
    0xfb, 0x3c, 0xf3, 0xcf, 0x3f, 0xb0, 0xc0,

    /* U+0071 "q" */
    0x7f, 0x3c, 0xf3, 0xcf, 0x37, 0xc3, 0xc,

    /* U+0072 "r" */
    0xfb, 0x3c, 0xf0, 0xc3, 0xc, 0x0,

    /* U+0073 "s" */
    0x7b, 0x3e, 0x1f, 0xf, 0x37, 0x80,

    /* U+0074 "t" */
    0x30, 0xcf, 0xcc, 0x30, 0xc3, 0xc, 0x1c,

    /* U+0075 "u" */
    0xcf, 0x3c, 0xf3, 0xcf, 0x37, 0x80,

    /* U+0076 "v" */
    0x46, 0x89, 0xb1, 0x62, 0x87, 0xe, 0x0,

    /* U+0077 "w" */
    0xd3, 0xa5, 0xbb, 0x66, 0xcd, 0x9b, 0x0,

    /* U+0078 "x" */
    0x64, 0x58, 0xe0, 0xc3, 0x8d, 0x91, 0x0,

    /* U+0079 "y" */
    0x46, 0xc9, 0xb1, 0x63, 0x83, 0x4, 0x8, 0x30,

    /* U+007A "z" */
    0xf8, 0xcc, 0x46, 0x63, 0xe0,

    /* U+007B "{" */
    0xc, 0x61, 0x86, 0x18, 0x6f, 0x6, 0x18, 0x61,
    0x83,

    /* U+007C "|" */
    0xff, 0xff, 0xff,

    /* U+007D "}" */
    0xe0, 0xc3, 0xc, 0x30, 0xc0, 0xcc, 0x30, 0xc3,
    0x38,

    /* U+00A7 "§" */
    0x7b, 0x3c, 0x1e, 0x4f, 0x3f, 0x9e, 0xf, 0x37,
    0x80,

    /* U+00AB "«" */
    0x36, 0xd9, 0x22, 0x46, 0xc6, 0xc0,

    /* U+00B0 "°" */
    0x69, 0x96,

    /* U+00B4 "´" */
    0x68,

    /* U+00BB "»" */
    0x48, 0xd8, 0xd9, 0xb6, 0xc9, 0x0,

    /* U+00C4 "Ä" */
    0x6c, 0xd8, 0x1, 0xc3, 0x85, 0xa, 0x36, 0x6c,
    0xf9, 0x16, 0x30,

    /* U+00D6 "Ö" */
    0xdb, 0x60, 0x1e, 0xcf, 0x3c, 0xf3, 0xcf, 0x3c,
    0xde,

    /* U+00DC "Ü" */
    0xdb, 0x60, 0x33, 0xcf, 0x3c, 0xf3, 0xcf, 0x3c,
    0xde,

    /* U+00DF "ß" */
    0x7b, 0x3c, 0xf3, 0xdb, 0x3c, 0xf3, 0xd8,

    /* U+00E4 "ä" */
    0x1, 0xe0, 0x1e, 0x4c, 0x37, 0xf3, 0xcd, 0xf0,

    /* U+00F6 "ö" */
    0x3, 0x60, 0x1e, 0xcf, 0x3c, 0xf3, 0xcd, 0xe0,

    /* U+00FC "ü" */
    0x3, 0x60, 0x33, 0xcf, 0x3c, 0xf3, 0xcd, 0xe0,

    /* U+20AC "€" */
    0x38, 0xc9, 0x97, 0x86, 0x1e, 0x19, 0xb2, 0x3c,

    /* U+2198 "↘" */
    0x0, 0x80, 0x88, 0x90, 0xa0, 0xcf, 0x80,

    /* U+2591 "░" */
    0xdb, 0x27, 0x68, 0x9, 0x3b, 0x40, 0x49, 0xda,
    0x2, 0x4e, 0xd0, 0x12, 0x76, 0x80,

    /* U+25A0 "■" */
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x80,

    /* U+25CC "◌" */
    0x18, 0x42, 0x0, 0x81, 0x81, 0x0, 0x42, 0x18,

    /* U+25CE "◎" */
    0x3c, 0x42, 0x99, 0xa5, 0xbd, 0x81, 0x42, 0x3c,

    /* U+25E9 "◩" */
    0xff, 0xfd, 0xfd, 0xf9, 0xf1, 0xe1, 0xc1, 0xff,

    /* U+2771 "❱" */
    0xe3, 0x9c, 0xf3, 0x9d, 0xce, 0xe0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 115, .box_w = 2, .box_h = 9, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 3, .adv_w = 115, .box_w = 4, .box_h = 4, .ofs_x = 2, .ofs_y = 5},
    {.bitmap_index = 5, .adv_w = 115, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 12, .adv_w = 115, .box_w = 6, .box_h = 13, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 22, .adv_w = 115, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 30, .adv_w = 115, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 38, .adv_w = 115, .box_w = 4, .box_h = 13, .ofs_x = 2, .ofs_y = -2},
    {.bitmap_index = 45, .adv_w = 115, .box_w = 5, .box_h = 13, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 54, .adv_w = 115, .box_w = 6, .box_h = 6, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 59, .adv_w = 115, .box_w = 3, .box_h = 4, .ofs_x = 2, .ofs_y = -2},
    {.bitmap_index = 61, .adv_w = 115, .box_w = 4, .box_h = 1, .ofs_x = 2, .ofs_y = 4},
    {.bitmap_index = 62, .adv_w = 115, .box_w = 2, .box_h = 2, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 63, .adv_w = 115, .box_w = 5, .box_h = 12, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 71, .adv_w = 115, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 78, .adv_w = 115, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 85, .adv_w = 115, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 92, .adv_w = 115, .box_w = 6, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 99, .adv_w = 115, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 106, .adv_w = 115, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 113, .adv_w = 115, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 120, .adv_w = 115, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 127, .adv_w = 115, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 134, .adv_w = 115, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 141, .adv_w = 115, .box_w = 2, .box_h = 7, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 143, .adv_w = 115, .box_w = 3, .box_h = 9, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 147, .adv_w = 115, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 153, .adv_w = 115, .box_w = 5, .box_h = 4, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 156, .adv_w = 115, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 162, .adv_w = 115, .box_w = 5, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 168, .adv_w = 115, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 177, .adv_w = 115, .box_w = 7, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 185, .adv_w = 115, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 192, .adv_w = 115, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 199, .adv_w = 115, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 206, .adv_w = 115, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 213, .adv_w = 115, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 220, .adv_w = 115, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 227, .adv_w = 115, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 234, .adv_w = 115, .box_w = 5, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 240, .adv_w = 115, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 247, .adv_w = 115, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 254, .adv_w = 115, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 261, .adv_w = 115, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 268, .adv_w = 115, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 275, .adv_w = 115, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 282, .adv_w = 115, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 289, .adv_w = 115, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 298, .adv_w = 115, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 305, .adv_w = 115, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 312, .adv_w = 115, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 319, .adv_w = 115, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 326, .adv_w = 115, .box_w = 7, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 334, .adv_w = 115, .box_w = 7, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 342, .adv_w = 115, .box_w = 7, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 350, .adv_w = 115, .box_w = 8, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 359, .adv_w = 115, .box_w = 5, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 365, .adv_w = 115, .box_w = 4, .box_h = 12, .ofs_x = 2, .ofs_y = -1},
    {.bitmap_index = 371, .adv_w = 115, .box_w = 5, .box_h = 12, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 379, .adv_w = 115, .box_w = 4, .box_h = 12, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 385, .adv_w = 115, .box_w = 5, .box_h = 5, .ofs_x = 1, .ofs_y = 4},
    {.bitmap_index = 389, .adv_w = 115, .box_w = 6, .box_h = 1, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 390, .adv_w = 115, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 396, .adv_w = 115, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 403, .adv_w = 115, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 409, .adv_w = 115, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 416, .adv_w = 115, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 422, .adv_w = 115, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 429, .adv_w = 115, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 436, .adv_w = 115, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 443, .adv_w = 115, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 451, .adv_w = 115, .box_w = 5, .box_h = 12, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 459, .adv_w = 115, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 466, .adv_w = 115, .box_w = 7, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 474, .adv_w = 115, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 480, .adv_w = 115, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 486, .adv_w = 115, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 492, .adv_w = 115, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 499, .adv_w = 115, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 506, .adv_w = 115, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 512, .adv_w = 115, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 518, .adv_w = 115, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 525, .adv_w = 115, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 531, .adv_w = 115, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 538, .adv_w = 115, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 545, .adv_w = 115, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 552, .adv_w = 115, .box_w = 7, .box_h = 9, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 560, .adv_w = 115, .box_w = 5, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 565, .adv_w = 115, .box_w = 6, .box_h = 12, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 574, .adv_w = 115, .box_w = 2, .box_h = 12, .ofs_x = 3, .ofs_y = -1},
    {.bitmap_index = 577, .adv_w = 115, .box_w = 6, .box_h = 12, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 586, .adv_w = 115, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 595, .adv_w = 115, .box_w = 7, .box_h = 6, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 601, .adv_w = 115, .box_w = 4, .box_h = 4, .ofs_x = 2, .ofs_y = 5},
    {.bitmap_index = 603, .adv_w = 115, .box_w = 3, .box_h = 2, .ofs_x = 2, .ofs_y = 8},
    {.bitmap_index = 604, .adv_w = 115, .box_w = 7, .box_h = 6, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 610, .adv_w = 115, .box_w = 7, .box_h = 12, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 621, .adv_w = 115, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 630, .adv_w = 115, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 639, .adv_w = 115, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 646, .adv_w = 115, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 654, .adv_w = 115, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 662, .adv_w = 115, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 670, .adv_w = 115, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 678, .adv_w = 115, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 685, .adv_w = 115, .box_w = 7, .box_h = 15, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 699, .adv_w = 115, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 706, .adv_w = 115, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 714, .adv_w = 115, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 722, .adv_w = 115, .box_w = 8, .box_h = 8, .ofs_x = -1, .ofs_y = 1},
    {.bitmap_index = 730, .adv_w = 115, .box_w = 5, .box_h = 9, .ofs_x = 1, .ofs_y = 0}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint8_t glyph_id_ofs_list_0[] = {
    0, 1, 2, 3, 4, 5, 0, 6,
    7
};

static const uint16_t unicode_list_3[] = {
    0x0, 0x4, 0x9, 0xd, 0x14, 0x1d, 0x2f, 0x35,
    0x38, 0x3d, 0x4f, 0x55, 0x2005, 0x20f1, 0x24ea, 0x24f9,
    0x2525, 0x2527, 0x2542, 0x26ca
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
        .unicode_list = unicode_list_3, .glyph_id_ofs_list = NULL, .list_length = 20, .type = LV_FONT_FMT_TXT_CMAP_SPARSE_TINY
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
const lv_font_t jetbrains_mono_bold_12 = {
#else
lv_font_t jetbrains_mono_bold_12 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 15,          /*The maximum line height required by the font*/
    .base_line = 3,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -2,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
// #if LV_VERSION_CHECK(8, 2, 0) || LVGL_VERSION_MAJOR >= 9
//     .fallback = &lv_font_montserrat_12,
// #endif
    .user_data = NULL,
};



#endif /*#if JETBRAINS_MONO_BOLD_12*/

