/*******************************************************************************
 * Size: 10 px
 * Bpp: 1
 * Opts: --bpp 1 --size 10 --no-compress --font JetBrainsMono-Regular.ttf --symbols a bcdefghijklmnopqrstuvwxyz.,-öäü+#´ß?ÄÖÜ<>|;:_{[]}\@€ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890^!"§$%&/()=?*-/+░❱◎↘◌◩«■»°← → ↔ ↑ ↓ , ↕ , ↖ ↗ ↘ ↙ , ⤡ ⤢ --format lvgl -o jetbrains_mono_regular_10.c
 ******************************************************************************/

#include "lvgl.h"

#ifndef JETBRAINS_MONO_REGULAR_10
#define JETBRAINS_MONO_REGULAR_10 1
#endif

#if JETBRAINS_MONO_REGULAR_10

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+0021 "!" */
    0xaa, 0x83,

    /* U+0022 "\"" */
    0xb6, 0x80,

    /* U+0023 "#" */
    0x28, 0xa7, 0xd2, 0x53, 0xe5, 0x14,

    /* U+0024 "$" */
    0x22, 0xfb, 0xe7, 0x3b, 0xb2, 0x20,

    /* U+0025 "%" */
    0xe6, 0xab, 0x3c, 0x3c, 0xd5, 0x67,

    /* U+0026 "&" */
    0xe4, 0xa0, 0x8a, 0xda, 0xdd,

    /* U+0028 "(" */
    0x2a, 0x49, 0x24, 0x4c,

    /* U+0029 ")" */
    0x88, 0x92, 0x49, 0x58,

    /* U+002A "*" */
    0x21, 0x3e, 0xc5, 0x0,

    /* U+002B "+" */
    0x21, 0x3e, 0x42, 0x0,

    /* U+002C "," */
    0xea,

    /* U+002D "-" */
    0xf0,

    /* U+002E "." */
    0xc0,

    /* U+002F "/" */
    0x11, 0x22, 0x24, 0x44, 0x88,

    /* U+0030 "0" */
    0x69, 0x9f, 0x99, 0x96,

    /* U+0031 "1" */
    0x65, 0x8, 0x42, 0x10, 0x9f,

    /* U+0032 "2" */
    0x69, 0x11, 0x24, 0xcf,

    /* U+0033 "3" */
    0xf2, 0x26, 0x11, 0x96,

    /* U+0034 "4" */
    0x22, 0x44, 0x9f, 0x11,

    /* U+0035 "5" */
    0xf8, 0x8e, 0x91, 0x9e,

    /* U+0036 "6" */
    0x21, 0x11, 0xe8, 0xc6, 0x2e,

    /* U+0037 "7" */
    0xfc, 0x84, 0x22, 0x10, 0x88,

    /* U+0038 "8" */
    0x69, 0x96, 0x69, 0x96,

    /* U+0039 "9" */
    0x74, 0x63, 0x17, 0x88, 0x84,

    /* U+003A ":" */
    0x84,

    /* U+003B ";" */
    0x8f,

    /* U+003C "<" */
    0x1b, 0x20, 0xc1, 0x80,

    /* U+003D "=" */
    0xf0, 0xf0,

    /* U+003E ">" */
    0xc1, 0x82, 0x6c, 0x0,

    /* U+003F "?" */
    0xe1, 0x11, 0x64, 0x4,

    /* U+0040 "@" */
    0x76, 0x63, 0x7a, 0xd6, 0xb7, 0xc3, 0x0,

    /* U+0041 "A" */
    0x30, 0xc3, 0x14, 0x49, 0xe4, 0x92,

    /* U+0042 "B" */
    0xe9, 0x9f, 0x99, 0x9e,

    /* U+0043 "C" */
    0x69, 0x88, 0x88, 0x96,

    /* U+0044 "D" */
    0xe9, 0x99, 0x99, 0x9e,

    /* U+0045 "E" */
    0xf8, 0x8f, 0x88, 0x8f,

    /* U+0046 "F" */
    0xf8, 0x88, 0xf8, 0x88,

    /* U+0047 "G" */
    0x69, 0x88, 0xb9, 0x96,

    /* U+0048 "H" */
    0x99, 0x9f, 0x99, 0x99,

    /* U+0049 "I" */
    0xf9, 0x8, 0x42, 0x10, 0x9f,

    /* U+004A "J" */
    0x38, 0x42, 0x10, 0x86, 0x2e,

    /* U+004B "K" */
    0x94, 0xa9, 0xca, 0x4a, 0x51,

    /* U+004C "L" */
    0x88, 0x88, 0x88, 0x8f,

    /* U+004D "M" */
    0xde, 0xf7, 0xd8, 0xc6, 0x31,

    /* U+004E "N" */
    0x9d, 0xdd, 0xdb, 0xb9,

    /* U+004F "O" */
    0x69, 0x99, 0x99, 0x96,

    /* U+0050 "P" */
    0xf4, 0x63, 0x1f, 0x42, 0x10,

    /* U+0051 "Q" */
    0x69, 0x99, 0x99, 0x96, 0x21,

    /* U+0052 "R" */
    0xe9, 0x99, 0xea, 0xa9,

    /* U+0053 "S" */
    0x69, 0x8c, 0x31, 0x96,

    /* U+0054 "T" */
    0xf9, 0x8, 0x42, 0x10, 0x84,

    /* U+0055 "U" */
    0x99, 0x99, 0x99, 0x96,

    /* U+0056 "V" */
    0x49, 0x24, 0x92, 0x50, 0xc3, 0xc,

    /* U+0057 "W" */
    0xb6, 0xdb, 0x6e, 0x79, 0xa4, 0x92,

    /* U+0058 "X" */
    0x49, 0x23, 0xc, 0x30, 0xc4, 0x92,

    /* U+0059 "Y" */
    0x8c, 0x54, 0xa2, 0x10, 0x84,

    /* U+005A "Z" */
    0xf1, 0x22, 0x44, 0x8f,

    /* U+005B "[" */
    0xf2, 0x49, 0x24, 0x9c,

    /* U+005C "\\" */
    0x88, 0x44, 0x42, 0x22, 0x11,

    /* U+005D "]" */
    0xe4, 0x92, 0x49, 0x3c,

    /* U+005E "^" */
    0x66, 0x99,

    /* U+005F "_" */
    0xf0,

    /* U+0061 "a" */
    0x61, 0xf9, 0x9f,

    /* U+0062 "b" */
    0x88, 0xe9, 0x99, 0x9e,

    /* U+0063 "c" */
    0x74, 0xa1, 0x9, 0x38,

    /* U+0064 "d" */
    0x11, 0x79, 0x99, 0x97,

    /* U+0065 "e" */
    0x69, 0xf8, 0x96,

    /* U+0066 "f" */
    0x39, 0x9, 0xf2, 0x10, 0x84,

    /* U+0067 "g" */
    0x79, 0x99, 0x97, 0x17,

    /* U+0068 "h" */
    0x88, 0xf9, 0x99, 0x99,

    /* U+0069 "i" */
    0x21, 0x0, 0xc2, 0x10, 0x84, 0xf8,

    /* U+006A "j" */
    0x24, 0x72, 0x49, 0x27, 0x0,

    /* U+006B "k" */
    0x84, 0x25, 0x6e, 0x52, 0x52,

    /* U+006C "l" */
    0xe1, 0x8, 0x42, 0x10, 0x87,

    /* U+006D "m" */
    0xfd, 0x6b, 0x5a, 0xd4,

    /* U+006E "n" */
    0xf9, 0x99, 0x99,

    /* U+006F "o" */
    0x69, 0x99, 0x96,

    /* U+0070 "p" */
    0xe9, 0x99, 0x9e, 0x88,

    /* U+0071 "q" */
    0x79, 0x99, 0x9f, 0x11,

    /* U+0072 "r" */
    0xe9, 0x98, 0x88,

    /* U+0073 "s" */
    0xe9, 0xc3, 0x9f,

    /* U+0074 "t" */
    0x21, 0x3e, 0x42, 0x10, 0x87,

    /* U+0075 "u" */
    0x99, 0x99, 0x96,

    /* U+0076 "v" */
    0x99, 0x96, 0x66,

    /* U+0077 "w" */
    0xa6, 0xeb, 0x9e, 0x49, 0x20,

    /* U+0078 "x" */
    0x48, 0xc3, 0xc, 0x49, 0x20,

    /* U+0079 "y" */
    0x99, 0x96, 0x62, 0x44,

    /* U+007A "z" */
    0xf1, 0x24, 0x8f,

    /* U+007B "{" */
    0x32, 0x22, 0xc2, 0x22, 0x23,

    /* U+007C "|" */
    0xff, 0xc0,

    /* U+007D "}" */
    0xc4, 0x44, 0x34, 0x44, 0x4c,

    /* U+00A7 "§" */
    0xe9, 0x86, 0x99, 0x61, 0x96,

    /* U+00AB "«" */
    0x29, 0x49, 0x14, 0x28,

    /* U+00B0 "°" */
    0xf7, 0x80,

    /* U+00B4 "´" */
    0x60,

    /* U+00BB "»" */
    0x50, 0xa2, 0x4a, 0x50,

    /* U+00C4 "Ä" */
    0x50, 0x8, 0xc5, 0x29, 0x4e, 0x94, 0x40,

    /* U+00D6 "Ö" */
    0x50, 0x69, 0x99, 0x99, 0x96,

    /* U+00DC "Ü" */
    0x90, 0x99, 0x99, 0x99, 0x96,

    /* U+00DF "ß" */
    0x69, 0x99, 0xa9, 0x9a,

    /* U+00E4 "ä" */
    0x55, 0x7, 0x1f, 0x99, 0xf0,

    /* U+00F6 "ö" */
    0x55, 0x6, 0x99, 0x99, 0x60,

    /* U+00FC "ü" */
    0x99, 0x9, 0x99, 0x99, 0x60,

    /* U+20AC "€" */
    0x39, 0x24, 0x3c, 0xf1, 0x4, 0x8e,

    /* U+2190 "←" */
    0x10, 0x84, 0x3f, 0x40, 0x81, 0x0,

    /* U+2191 "↑" */
    0x75, 0x6a, 0x42, 0x10, 0x80,

    /* U+2192 "→" */
    0x20, 0x40, 0xbf, 0x8, 0x42, 0x0,

    /* U+2193 "↓" */
    0x21, 0x8, 0x4a, 0xb8, 0x80,

    /* U+2194 "↔" */
    0x3c, 0x24, 0x42, 0xff, 0x42, 0x24, 0x3c,

    /* U+2195 "↕" */
    0x23, 0xaa, 0x42, 0x10, 0x84, 0xab, 0x88,

    /* U+2196 "↖" */
    0xf3, 0xa, 0x24, 0x8, 0x0,

    /* U+2197 "↗" */
    0x3c, 0x31, 0x49, 0x40, 0x0,

    /* U+2198 "↘" */
    0x1, 0x2, 0x45, 0xc, 0xf0,

    /* U+2199 "↙" */
    0x0, 0x29, 0x28, 0xc3, 0xc0,

    /* U+2591 "░" */
    0xef, 0xae, 0xfa, 0xec, 0xa, 0xbb, 0xeb, 0xb0,
    0x2a, 0xec,

    /* U+25A0 "■" */
    0xff, 0xff, 0xff, 0xff, 0xf0,

    /* U+25CC "◌" */
    0x10, 0x88, 0x4, 0x10, 0x8, 0x84, 0x0,

    /* U+25CE "◎" */
    0x38, 0x8a, 0x6d, 0x59, 0xa8, 0x8e, 0x0,

    /* U+25E9 "◩" */
    0xff, 0xff, 0xef, 0x9e, 0x38, 0x7f, 0x80,

    /* U+2771 "❱" */
    0xe6, 0x77, 0x76, 0xe0};

/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 96, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 96, .box_w = 2, .box_h = 8, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 3, .adv_w = 96, .box_w = 3, .box_h = 3, .ofs_x = 2, .ofs_y = 5},
    {.bitmap_index = 5, .adv_w = 96, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 11, .adv_w = 96, .box_w = 4, .box_h = 11, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 17, .adv_w = 96, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 23, .adv_w = 96, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 28, .adv_w = 96, .box_w = 3, .box_h = 10, .ofs_x = 2, .ofs_y = -1},
    {.bitmap_index = 32, .adv_w = 96, .box_w = 3, .box_h = 10, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 36, .adv_w = 96, .box_w = 5, .box_h = 6, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 40, .adv_w = 96, .box_w = 5, .box_h = 5, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 44, .adv_w = 96, .box_w = 2, .box_h = 4, .ofs_x = 2, .ofs_y = -2},
    {.bitmap_index = 45, .adv_w = 96, .box_w = 4, .box_h = 1, .ofs_x = 1, .ofs_y = 3},
    {.bitmap_index = 46, .adv_w = 96, .box_w = 1, .box_h = 2, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 47, .adv_w = 96, .box_w = 4, .box_h = 10, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 52, .adv_w = 96, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 56, .adv_w = 96, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 61, .adv_w = 96, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 65, .adv_w = 96, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 69, .adv_w = 96, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 73, .adv_w = 96, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 77, .adv_w = 96, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 82, .adv_w = 96, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 87, .adv_w = 96, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 91, .adv_w = 96, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 96, .adv_w = 96, .box_w = 1, .box_h = 6, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 97, .adv_w = 96, .box_w = 1, .box_h = 8, .ofs_x = 2, .ofs_y = -2},
    {.bitmap_index = 98, .adv_w = 96, .box_w = 5, .box_h = 5, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 102, .adv_w = 96, .box_w = 4, .box_h = 3, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 104, .adv_w = 96, .box_w = 5, .box_h = 5, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 108, .adv_w = 96, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 112, .adv_w = 96, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 119, .adv_w = 96, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 125, .adv_w = 96, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 129, .adv_w = 96, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 133, .adv_w = 96, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 137, .adv_w = 96, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 141, .adv_w = 96, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 145, .adv_w = 96, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 149, .adv_w = 96, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 153, .adv_w = 96, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 158, .adv_w = 96, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 163, .adv_w = 96, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 168, .adv_w = 96, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 172, .adv_w = 96, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 177, .adv_w = 96, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 181, .adv_w = 96, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 185, .adv_w = 96, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 190, .adv_w = 96, .box_w = 4, .box_h = 10, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 195, .adv_w = 96, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 199, .adv_w = 96, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 203, .adv_w = 96, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 208, .adv_w = 96, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 212, .adv_w = 96, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 218, .adv_w = 96, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 224, .adv_w = 96, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 230, .adv_w = 96, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 235, .adv_w = 96, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 239, .adv_w = 96, .box_w = 3, .box_h = 10, .ofs_x = 2, .ofs_y = -1},
    {.bitmap_index = 243, .adv_w = 96, .box_w = 4, .box_h = 10, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 248, .adv_w = 96, .box_w = 3, .box_h = 10, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 252, .adv_w = 96, .box_w = 4, .box_h = 4, .ofs_x = 1, .ofs_y = 4},
    {.bitmap_index = 254, .adv_w = 96, .box_w = 4, .box_h = 1, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 255, .adv_w = 96, .box_w = 4, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 258, .adv_w = 96, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 262, .adv_w = 96, .box_w = 5, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 266, .adv_w = 96, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 270, .adv_w = 96, .box_w = 4, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 273, .adv_w = 96, .box_w = 5, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 278, .adv_w = 96, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 282, .adv_w = 96, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 286, .adv_w = 96, .box_w = 5, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 292, .adv_w = 96, .box_w = 3, .box_h = 11, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 297, .adv_w = 96, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 302, .adv_w = 96, .box_w = 5, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 307, .adv_w = 96, .box_w = 5, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 311, .adv_w = 96, .box_w = 4, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 314, .adv_w = 96, .box_w = 4, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 317, .adv_w = 96, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 321, .adv_w = 96, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 325, .adv_w = 96, .box_w = 4, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 328, .adv_w = 96, .box_w = 4, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 331, .adv_w = 96, .box_w = 5, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 336, .adv_w = 96, .box_w = 4, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 339, .adv_w = 96, .box_w = 4, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 342, .adv_w = 96, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 347, .adv_w = 96, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 352, .adv_w = 96, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 356, .adv_w = 96, .box_w = 4, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 359, .adv_w = 96, .box_w = 4, .box_h = 10, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 364, .adv_w = 96, .box_w = 1, .box_h = 10, .ofs_x = 3, .ofs_y = -1},
    {.bitmap_index = 366, .adv_w = 96, .box_w = 4, .box_h = 10, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 371, .adv_w = 96, .box_w = 4, .box_h = 10, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 376, .adv_w = 96, .box_w = 6, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 380, .adv_w = 96, .box_w = 3, .box_h = 3, .ofs_x = 1, .ofs_y = 5},
    {.bitmap_index = 382, .adv_w = 96, .box_w = 2, .box_h = 2, .ofs_x = 2, .ofs_y = 7},
    {.bitmap_index = 383, .adv_w = 96, .box_w = 6, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 387, .adv_w = 96, .box_w = 5, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 394, .adv_w = 96, .box_w = 4, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 399, .adv_w = 96, .box_w = 4, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 404, .adv_w = 96, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 408, .adv_w = 96, .box_w = 4, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 413, .adv_w = 96, .box_w = 4, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 418, .adv_w = 96, .box_w = 4, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 423, .adv_w = 96, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 429, .adv_w = 96, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 435, .adv_w = 96, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 440, .adv_w = 96, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 446, .adv_w = 96, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 451, .adv_w = 96, .box_w = 8, .box_h = 7, .ofs_x = -1, .ofs_y = 0},
    {.bitmap_index = 458, .adv_w = 96, .box_w = 5, .box_h = 11, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 465, .adv_w = 96, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 470, .adv_w = 96, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 475, .adv_w = 96, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 480, .adv_w = 96, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 485, .adv_w = 96, .box_w = 6, .box_h = 13, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 495, .adv_w = 96, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 500, .adv_w = 96, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 507, .adv_w = 96, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 514, .adv_w = 96, .box_w = 7, .box_h = 7, .ofs_x = -1, .ofs_y = 0},
    {.bitmap_index = 521, .adv_w = 96, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = 0}};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint16_t unicode_list_3[] = {
    0x0, 0x4, 0x9, 0xd, 0x14, 0x1d, 0x2f, 0x35,
    0x38, 0x3d, 0x4f, 0x55, 0x2005, 0x20e9, 0x20ea, 0x20eb,
    0x20ec, 0x20ed, 0x20ee, 0x20ef, 0x20f0, 0x20f1, 0x20f2, 0x24ea,
    0x24f9, 0x2525, 0x2527, 0x2542, 0x26ca};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
    {
        {.range_start = 32, .range_length = 7, .glyph_id_start = 1, .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY},
        {.range_start = 40, .range_length = 56, .glyph_id_start = 8, .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY},
        {.range_start = 97, .range_length = 29, .glyph_id_start = 64, .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY},
        {.range_start = 167, .range_length = 9931, .glyph_id_start = 93, .unicode_list = unicode_list_3, .glyph_id_ofs_list = NULL, .list_length = 29, .type = LV_FONT_FMT_TXT_CMAP_SPARSE_TINY}};

/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LVGL_VERSION_MAJOR == 8
/*Store all the custom data of the font*/
static lv_font_fmt_txt_glyph_cache_t cache;
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

/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LVGL_VERSION_MAJOR >= 8
const lv_font_t jetbrains_mono_regular_10 = {
#else
lv_font_t jetbrains_mono_regular_10 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt, /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt, /*Function pointer to get glyph's bitmap*/
    .line_height = 13,                              /*The maximum line height required by the font*/
    .base_line = 3,                                 /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -2,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc, /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
#if LV_VERSION_CHECK(8, 2, 0) || LVGL_VERSION_MAJOR >= 9
    .fallback = NULL,
#endif
    .user_data = NULL,
};

#endif /*#if JETBRAINS_MONO_REGULAR_10*/
