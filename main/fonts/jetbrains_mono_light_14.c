/*******************************************************************************
 * Size: 14 px
 * Bpp: 1
 * Opts: --bpp 1 --size 14 --no-compress --font JetBrainsMono-Light.ttf --symbols a bcdefghijklmnopqrstuvwxyz.,-öäü+#´ß?ÄÖÜ<>|;:_{[]}\@€ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890^!"§$%&/()=?*-/+░❱◎↘◌◩«■»°← → ↔ ↑ ↓ , ↕ , ↖ ↗ ↘ ↙ , ⤡ ⤢ --format lvgl -o jetbrains_mono_light_14.c
 ******************************************************************************/

#include "lvgl.h"

#ifndef JETBRAINS_MONO_LIGHT_14
#define JETBRAINS_MONO_LIGHT_14 1
#endif

#if JETBRAINS_MONO_LIGHT_14

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+0021 "!" */
    0xaa, 0xa8, 0x30,

    /* U+0022 "\"" */
    0x99, 0x99,

    /* U+0023 "#" */
    0x12, 0x12, 0x7f, 0x24, 0x24, 0x24, 0xfe, 0x24,
    0x44, 0x48,

    /* U+0024 "$" */
    0x10, 0x43, 0x97, 0x96, 0x4d, 0x1e, 0x1c, 0x59,
    0x65, 0x78, 0x41, 0x0,

    /* U+0025 "%" */
    0xf1, 0x92, 0x94, 0xf4, 0x8, 0x16, 0x29, 0x29,
    0x49, 0x86,

    /* U+0026 "&" */
    0x38, 0x91, 0x2, 0x6, 0x12, 0xe7, 0x44, 0x8c,
    0xec,

    /* U+0028 "(" */
    0x16, 0x48, 0x88, 0x88, 0x88, 0xc4, 0x31,

    /* U+0029 ")" */
    0x86, 0x21, 0x11, 0x11, 0x11, 0x32, 0xc8,

    /* U+002A "*" */
    0x10, 0x23, 0x59, 0xc2, 0x8d, 0x91, 0x0,

    /* U+002B "+" */
    0x10, 0x23, 0xf8, 0x81, 0x2, 0x0,

    /* U+002C "," */
    0x6d, 0x24,

    /* U+002D "-" */
    0xf0,

    /* U+002E "." */
    0xf0,

    /* U+002F "/" */
    0x4, 0x10, 0xc2, 0x8, 0x41, 0x4, 0x20, 0x86,
    0x10, 0x42, 0x0,

    /* U+0030 "0" */
    0x7b, 0x38, 0x61, 0x96, 0x18, 0x61, 0xcd, 0xe0,

    /* U+0031 "1" */
    0x33, 0x49, 0x4, 0x10, 0x41, 0x4, 0x13, 0xf0,

    /* U+0032 "2" */
    0x7b, 0x38, 0x41, 0xc, 0x63, 0x18, 0xc3, 0xf0,

    /* U+0033 "3" */
    0x7c, 0x21, 0xe, 0xc, 0x10, 0x61, 0xcd, 0xe0,

    /* U+0034 "4" */
    0x8, 0x41, 0x8, 0x47, 0x18, 0x7f, 0x4, 0x10,

    /* U+0035 "5" */
    0xfe, 0x8, 0x3e, 0xcc, 0x10, 0x41, 0x8d, 0xe0,

    /* U+0036 "6" */
    0x10, 0x82, 0x1e, 0x4e, 0x18, 0x61, 0xcd, 0xe0,

    /* U+0037 "7" */
    0xff, 0xa, 0x10, 0x40, 0x83, 0x4, 0x8, 0x20,
    0x40,

    /* U+0038 "8" */
    0x7a, 0x18, 0x61, 0x79, 0x28, 0x61, 0x85, 0xe0,

    /* U+0039 "9" */
    0x7b, 0x38, 0x61, 0xcd, 0xe0, 0x84, 0x30, 0x80,

    /* U+003A ":" */
    0xf0, 0xf,

    /* U+003B ";" */
    0x6c, 0x0, 0x1a, 0x49, 0x0,

    /* U+003C "<" */
    0xc, 0xcc, 0x20, 0x60, 0x60, 0x40,

    /* U+003D "=" */
    0xfc, 0x0, 0x3f,

    /* U+003E ">" */
    0xc0, 0xc1, 0xc1, 0x19, 0x88, 0x0,

    /* U+003F "?" */
    0xf0, 0x42, 0x37, 0x21, 0x0, 0x3, 0x0,

    /* U+0040 "@" */
    0x3c, 0x8a, 0xc, 0x79, 0x32, 0x64, 0xc9, 0x93,
    0x1e, 0x2, 0x3, 0x80,

    /* U+0041 "A" */
    0x30, 0x60, 0xa1, 0x44, 0x89, 0x1f, 0x42, 0x85,
    0x8,

    /* U+0042 "B" */
    0xfa, 0x18, 0x61, 0xfa, 0x38, 0x61, 0x8f, 0xe0,

    /* U+0043 "C" */
    0x7b, 0x38, 0x60, 0x82, 0x8, 0x21, 0xcd, 0xe0,

    /* U+0044 "D" */
    0xfa, 0x38, 0x61, 0x86, 0x18, 0x61, 0x8f, 0xe0,

    /* U+0045 "E" */
    0xfe, 0x8, 0x20, 0xfa, 0x8, 0x20, 0x83, 0xf0,

    /* U+0046 "F" */
    0xfe, 0x8, 0x20, 0xfa, 0x8, 0x20, 0x82, 0x0,

    /* U+0047 "G" */
    0x7b, 0x38, 0x60, 0x82, 0x78, 0x61, 0xcd, 0xe0,

    /* U+0048 "H" */
    0x86, 0x18, 0x61, 0xfe, 0x18, 0x61, 0x86, 0x10,

    /* U+0049 "I" */
    0xf9, 0x8, 0x42, 0x10, 0x84, 0x27, 0xc0,

    /* U+004A "J" */
    0x3c, 0x10, 0x41, 0x4, 0x10, 0x61, 0xcd, 0xe0,

    /* U+004B "K" */
    0x86, 0x28, 0xa4, 0xf2, 0x49, 0xa2, 0x8e, 0x10,

    /* U+004C "L" */
    0x82, 0x8, 0x20, 0x82, 0x8, 0x20, 0x83, 0xf0,

    /* U+004D "M" */
    0xcf, 0x3c, 0xed, 0xb6, 0xd8, 0x61, 0x86, 0x10,

    /* U+004E "N" */
    0xc7, 0x1c, 0x69, 0xa6, 0x59, 0x63, 0x8e, 0x30,

    /* U+004F "O" */
    0x7b, 0x38, 0x61, 0x86, 0x18, 0x61, 0xcd, 0xe0,

    /* U+0050 "P" */
    0xfa, 0x38, 0x61, 0x8f, 0xe8, 0x20, 0x82, 0x0,

    /* U+0051 "Q" */
    0x7b, 0x38, 0x61, 0x86, 0x18, 0x61, 0xcd, 0xe0,
    0x82, 0x4,

    /* U+0052 "R" */
    0xfa, 0x18, 0x61, 0xfa, 0x49, 0xa2, 0x8e, 0x10,

    /* U+0053 "S" */
    0x7a, 0x38, 0x60, 0x60, 0x60, 0x61, 0xc5, 0xe0,

    /* U+0054 "T" */
    0xfe, 0x20, 0x40, 0x81, 0x2, 0x4, 0x8, 0x10,
    0x20,

    /* U+0055 "U" */
    0x86, 0x18, 0x61, 0x86, 0x18, 0x61, 0x8d, 0xe0,

    /* U+0056 "V" */
    0x85, 0xb, 0x12, 0x24, 0x89, 0x1a, 0x14, 0x30,
    0x60,

    /* U+0057 "W" */
    0xc9, 0x59, 0x59, 0x59, 0x5a, 0x56, 0x56, 0x66,
    0x66, 0x26,

    /* U+0058 "X" */
    0x84, 0x89, 0x21, 0xc3, 0x6, 0xa, 0x24, 0xc5,
    0xc,

    /* U+0059 "Y" */
    0x82, 0x89, 0x11, 0x42, 0x82, 0x4, 0x8, 0x10,
    0x20,

    /* U+005A "Z" */
    0xfc, 0x10, 0x86, 0x10, 0x86, 0x10, 0x83, 0xf0,

    /* U+005B "[" */
    0xf2, 0x49, 0x24, 0x92, 0x4e,

    /* U+005C "\\" */
    0x83, 0x4, 0x10, 0x20, 0x83, 0x4, 0x10, 0x60,
    0x82, 0x4, 0x10,

    /* U+005D "]" */
    0xe4, 0x92, 0x49, 0x24, 0x9e,

    /* U+005E "^" */
    0x10, 0xc2, 0x92, 0x46, 0x10,

    /* U+005F "_" */
    0xfe,

    /* U+0061 "a" */
    0x7b, 0x10, 0x5f, 0x86, 0x18, 0xdd,

    /* U+0062 "b" */
    0x82, 0xf, 0xb3, 0x86, 0x18, 0x61, 0xce, 0xe0,

    /* U+0063 "c" */
    0x7b, 0x18, 0x60, 0x82, 0x1c, 0x5e,

    /* U+0064 "d" */
    0x4, 0x17, 0xf3, 0x86, 0x18, 0x61, 0xcd, 0xd0,

    /* U+0065 "e" */
    0x7a, 0x18, 0x7f, 0x82, 0xc, 0xde,

    /* U+0066 "f" */
    0x1e, 0x40, 0x87, 0xf2, 0x4, 0x8, 0x10, 0x20,
    0x40,

    /* U+0067 "g" */
    0x77, 0x38, 0x61, 0x86, 0x1c, 0xdd, 0x4, 0x17,
    0x80,

    /* U+0068 "h" */
    0x82, 0xb, 0xb1, 0x86, 0x18, 0x61, 0x86, 0x10,

    /* U+0069 "i" */
    0x0, 0xc0, 0x3c, 0x10, 0x41, 0x4, 0x10, 0x4f,
    0xc0,

    /* U+006A "j" */
    0x0, 0xc1, 0xf0, 0x84, 0x21, 0x8, 0x42, 0x11,
    0xf8,

    /* U+006B "k" */
    0x82, 0x8, 0xe2, 0x93, 0xc9, 0x26, 0x8a, 0x10,

    /* U+006C "l" */
    0xf0, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10, 0x10,
    0x10, 0xf,

    /* U+006D "m" */
    0xfe, 0x59, 0x65, 0x96, 0x59, 0x65,

    /* U+006E "n" */
    0xbb, 0x18, 0x61, 0x86, 0x18, 0x61,

    /* U+006F "o" */
    0x7b, 0x38, 0x61, 0x86, 0x1c, 0xde,

    /* U+0070 "p" */
    0xbb, 0x38, 0x61, 0x86, 0x1c, 0x6e, 0x82, 0x8,
    0x0,

    /* U+0071 "q" */
    0x77, 0x38, 0x61, 0x86, 0x1c, 0xdd, 0x4, 0x10,
    0x40,

    /* U+0072 "r" */
    0xbb, 0x38, 0x60, 0x82, 0x8, 0x20,

    /* U+0073 "s" */
    0x7a, 0x18, 0x3c, 0x1c, 0x18, 0x5e,

    /* U+0074 "t" */
    0x20, 0x8f, 0xc8, 0x20, 0x82, 0x8, 0x20, 0x70,

    /* U+0075 "u" */
    0x86, 0x18, 0x61, 0x86, 0x1c, 0xde,

    /* U+0076 "v" */
    0x85, 0x9, 0x12, 0x44, 0x85, 0xc, 0x18,

    /* U+0077 "w" */
    0x93, 0x66, 0xd5, 0xab, 0x59, 0xb3, 0x26,

    /* U+0078 "x" */
    0xc4, 0x90, 0xa1, 0x83, 0xd, 0x13, 0x42,

    /* U+0079 "y" */
    0x85, 0x89, 0x12, 0x42, 0x85, 0xc, 0x8, 0x30,
    0x40, 0x80,

    /* U+007A "z" */
    0xfc, 0x31, 0x84, 0x21, 0xc, 0x3f,

    /* U+007B "{" */
    0xc, 0x41, 0x4, 0x10, 0x4e, 0x4, 0x10, 0x41,
    0x4, 0xc,

    /* U+007C "|" */
    0xff, 0xfc,

    /* U+007D "}" */
    0xc0, 0x82, 0x8, 0x20, 0x81, 0xc8, 0x20, 0x82,
    0x8, 0xc0,

    /* U+00A7 "§" */
    0x7a, 0x18, 0x30, 0xba, 0x18, 0x7f, 0x70, 0x30,
    0x61, 0x78,

    /* U+00AB "«" */
    0x12, 0x26, 0x64, 0xc8, 0x64, 0x26, 0x13,

    /* U+00B0 "°" */
    0x69, 0x96,

    /* U+00B4 "´" */
    0x58,

    /* U+00BB "»" */
    0x48, 0x24, 0x12, 0x19, 0x12, 0x24, 0x48,

    /* U+00C4 "Ä" */
    0x49, 0x20, 0x0, 0x30, 0xc7, 0x92, 0x49, 0x27,
    0xa1, 0x86, 0x10,

    /* U+00D6 "Ö" */
    0x49, 0x20, 0x0, 0x7b, 0x38, 0x61, 0x86, 0x18,
    0x61, 0xcd, 0xe0,

    /* U+00DC "Ü" */
    0x49, 0x20, 0x0, 0x86, 0x18, 0x61, 0x86, 0x18,
    0x61, 0x8d, 0xe0,

    /* U+00DF "ß" */
    0x7b, 0x18, 0x61, 0xba, 0x38, 0x61, 0x8e, 0xe0,

    /* U+00E4 "ä" */
    0x49, 0x24, 0x9e, 0x44, 0x17, 0xe1, 0x86, 0x37,
    0x40,

    /* U+00F6 "ö" */
    0x49, 0x24, 0x9e, 0xce, 0x18, 0x61, 0x87, 0x37,
    0x80,

    /* U+00FC "ü" */
    0x49, 0x24, 0xa1, 0x86, 0x18, 0x61, 0x87, 0x37,
    0x80,

    /* U+20AC "€" */
    0x3c, 0x85, 0x7, 0xc4, 0x1f, 0x10, 0x21, 0x66,
    0x78,

    /* U+2190 "←" */
    0x10, 0x41, 0x86, 0xf, 0xf8, 0x18, 0x10, 0x10,

    /* U+2191 "↑" */
    0x18, 0xfb, 0x5c, 0x91, 0x2, 0x4, 0x8, 0x10,
    0x20,

    /* U+2192 "→" */
    0x30, 0x30, 0x20, 0x2f, 0xe0, 0x82, 0xc, 0x30,

    /* U+2193 "↓" */
    0x10, 0x20, 0x40, 0x81, 0x2, 0x24, 0xeb, 0x38,
    0x20,

    /* U+2194 "↔" */
    0x1a, 0x6, 0x21, 0x86, 0x20, 0x6f, 0xfe, 0x81,
    0x98, 0x61, 0x88, 0x1a, 0x0,

    /* U+2195 "↕" */
    0x10, 0x71, 0xf6, 0xb9, 0x22, 0x4, 0x8, 0x10,
    0x20, 0x44, 0x9d, 0x6f, 0x86, 0x0,

    /* U+2196 "↖" */
    0xfc, 0xc0, 0xa0, 0x90, 0x88, 0x84, 0x2, 0x0,

    /* U+2197 "↗" */
    0x3f, 0x3, 0x5, 0x9, 0x11, 0x21, 0x40, 0x0,

    /* U+2198 "↘" */
    0x0, 0x40, 0x21, 0x11, 0x9, 0x5, 0x3, 0x3f,

    /* U+2199 "↙" */
    0x0, 0x2, 0x84, 0x88, 0x90, 0xa0, 0xc0, 0xfc,

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
    0x71, 0xe7, 0x8e, 0x3c, 0xf3, 0x9e, 0x79, 0xc0};

/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 134, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 134, .box_w = 2, .box_h = 10, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 4, .adv_w = 134, .box_w = 4, .box_h = 4, .ofs_x = 2, .ofs_y = 6},
    {.bitmap_index = 6, .adv_w = 134, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 16, .adv_w = 134, .box_w = 6, .box_h = 15, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 28, .adv_w = 134, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 38, .adv_w = 134, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 47, .adv_w = 134, .box_w = 4, .box_h = 14, .ofs_x = 3, .ofs_y = -2},
    {.bitmap_index = 54, .adv_w = 134, .box_w = 4, .box_h = 14, .ofs_x = 2, .ofs_y = -2},
    {.bitmap_index = 61, .adv_w = 134, .box_w = 7, .box_h = 7, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 68, .adv_w = 134, .box_w = 7, .box_h = 6, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 74, .adv_w = 134, .box_w = 3, .box_h = 5, .ofs_x = 2, .ofs_y = -3},
    {.bitmap_index = 76, .adv_w = 134, .box_w = 4, .box_h = 1, .ofs_x = 2, .ofs_y = 4},
    {.bitmap_index = 77, .adv_w = 134, .box_w = 2, .box_h = 2, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 78, .adv_w = 134, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 89, .adv_w = 134, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 97, .adv_w = 134, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 105, .adv_w = 134, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 113, .adv_w = 134, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 121, .adv_w = 134, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 129, .adv_w = 134, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 137, .adv_w = 134, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 145, .adv_w = 134, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 154, .adv_w = 134, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 162, .adv_w = 134, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 170, .adv_w = 134, .box_w = 2, .box_h = 8, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 172, .adv_w = 134, .box_w = 3, .box_h = 11, .ofs_x = 2, .ofs_y = -3},
    {.bitmap_index = 177, .adv_w = 134, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 183, .adv_w = 134, .box_w = 6, .box_h = 4, .ofs_x = 1, .ofs_y = 3},
    {.bitmap_index = 186, .adv_w = 134, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 192, .adv_w = 134, .box_w = 5, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 199, .adv_w = 134, .box_w = 7, .box_h = 13, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 211, .adv_w = 134, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 220, .adv_w = 134, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 228, .adv_w = 134, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 236, .adv_w = 134, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 244, .adv_w = 134, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 252, .adv_w = 134, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 260, .adv_w = 134, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 268, .adv_w = 134, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 276, .adv_w = 134, .box_w = 5, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 283, .adv_w = 134, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 291, .adv_w = 134, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 299, .adv_w = 134, .box_w = 6, .box_h = 10, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 307, .adv_w = 134, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 315, .adv_w = 134, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 323, .adv_w = 134, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 331, .adv_w = 134, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 339, .adv_w = 134, .box_w = 6, .box_h = 13, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 349, .adv_w = 134, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 357, .adv_w = 134, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 365, .adv_w = 134, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 374, .adv_w = 134, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 382, .adv_w = 134, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 391, .adv_w = 134, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 401, .adv_w = 134, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 410, .adv_w = 134, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 419, .adv_w = 134, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 427, .adv_w = 134, .box_w = 3, .box_h = 13, .ofs_x = 3, .ofs_y = -2},
    {.bitmap_index = 432, .adv_w = 134, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 443, .adv_w = 134, .box_w = 3, .box_h = 13, .ofs_x = 2, .ofs_y = -2},
    {.bitmap_index = 448, .adv_w = 134, .box_w = 6, .box_h = 6, .ofs_x = 1, .ofs_y = 5},
    {.bitmap_index = 453, .adv_w = 134, .box_w = 7, .box_h = 1, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 454, .adv_w = 134, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 460, .adv_w = 134, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 468, .adv_w = 134, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 474, .adv_w = 134, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 482, .adv_w = 134, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 488, .adv_w = 134, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 497, .adv_w = 134, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 506, .adv_w = 134, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 514, .adv_w = 134, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 523, .adv_w = 134, .box_w = 5, .box_h = 14, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 532, .adv_w = 134, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 540, .adv_w = 134, .box_w = 8, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 550, .adv_w = 134, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 556, .adv_w = 134, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 562, .adv_w = 134, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 568, .adv_w = 134, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 577, .adv_w = 134, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 586, .adv_w = 134, .box_w = 6, .box_h = 8, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 592, .adv_w = 134, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 598, .adv_w = 134, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 606, .adv_w = 134, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 612, .adv_w = 134, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 619, .adv_w = 134, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 626, .adv_w = 134, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 633, .adv_w = 134, .box_w = 7, .box_h = 11, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 643, .adv_w = 134, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 649, .adv_w = 134, .box_w = 6, .box_h = 13, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 659, .adv_w = 134, .box_w = 1, .box_h = 14, .ofs_x = 4, .ofs_y = -2},
    {.bitmap_index = 661, .adv_w = 134, .box_w = 6, .box_h = 13, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 671, .adv_w = 134, .box_w = 6, .box_h = 13, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 681, .adv_w = 134, .box_w = 8, .box_h = 7, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 688, .adv_w = 134, .box_w = 4, .box_h = 4, .ofs_x = 2, .ofs_y = 6},
    {.bitmap_index = 690, .adv_w = 134, .box_w = 3, .box_h = 2, .ofs_x = 3, .ofs_y = 9},
    {.bitmap_index = 691, .adv_w = 134, .box_w = 8, .box_h = 7, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 698, .adv_w = 134, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 709, .adv_w = 134, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 720, .adv_w = 134, .box_w = 6, .box_h = 14, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 731, .adv_w = 134, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 739, .adv_w = 134, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 748, .adv_w = 134, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 757, .adv_w = 134, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 766, .adv_w = 134, .box_w = 7, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 775, .adv_w = 134, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 783, .adv_w = 134, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 792, .adv_w = 134, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 800, .adv_w = 134, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 809, .adv_w = 134, .box_w = 11, .box_h = 9, .ofs_x = -1, .ofs_y = 0},
    {.bitmap_index = 822, .adv_w = 134, .box_w = 7, .box_h = 15, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 836, .adv_w = 134, .box_w = 8, .box_h = 8, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 844, .adv_w = 134, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 852, .adv_w = 134, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 860, .adv_w = 134, .box_w = 8, .box_h = 8, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 868, .adv_w = 134, .box_w = 8, .box_h = 17, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 885, .adv_w = 134, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 893, .adv_w = 134, .box_w = 9, .box_h = 9, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 904, .adv_w = 134, .box_w = 9, .box_h = 9, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 915, .adv_w = 134, .box_w = 9, .box_h = 9, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 926, .adv_w = 134, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0}};

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
const lv_font_t jetbrains_mono_light_14 = {
#else
lv_font_t jetbrains_mono_light_14 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt, /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt, /*Function pointer to get glyph's bitmap*/
    .line_height = 17,                              /*The maximum line height required by the font*/
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

#endif /*#if JETBRAINS_MONO_LIGHT_14*/
