/*******************************************************************************
 * Size: 12 px
 * Bpp: 1
 * Opts: --bpp 1 --size 12 --no-compress --font JetBrainsMono-Light.ttf --symbols abcdefghijklmnopqrstuvwxyz.,-öäü+#´ß?ÄÖÜ<>|;:_{[]}\@€ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890^!"§$%&/()=?░❱◎↘◌◩«■»°← → ↔ ↑ ↓ , ↕ , ↖ ↗ ↘ ↙ , ⤡ ⤢ --format lvgl -o jetbrains_mono_light_12.c
 ******************************************************************************/

#include "lvgl.h"

#ifndef JETBRAINS_MONO_LIGHT_12
#define JETBRAINS_MONO_LIGHT_12 1
#endif

#if JETBRAINS_MONO_LIGHT_12

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+0021 "!" */
    0xfc, 0x80,

    /* U+0022 "\"" */
    0xb6, 0xd0,

    /* U+0023 "#" */
    0x24, 0x49, 0xf9, 0x22, 0x89, 0x3f, 0x24, 0x48,

    /* U+0024 "$" */
    0x21, 0x1d, 0x5a, 0xd1, 0xc7, 0x2d, 0x7e, 0x42,
    0x0,

    /* U+0025 "%" */
    0xe3, 0x4a, 0xa7, 0x41, 0x7, 0xcc, 0xa9, 0x9e,

    /* U+0026 "&" */
    0x72, 0x28, 0x30, 0xe2, 0x99, 0xa6, 0x64,

    /* U+0028 "(" */
    0x12, 0x48, 0x88, 0x88, 0x88, 0x42, 0x10,

    /* U+0029 ")" */
    0x84, 0x21, 0x11, 0x11, 0x11, 0x24, 0x80,

    /* U+002B "+" */
    0x21, 0x9, 0xf2, 0x10,

    /* U+002C "," */
    0x5a,

    /* U+002D "-" */
    0xf0,

    /* U+002E "." */
    0xf0,

    /* U+002F "/" */
    0x8, 0x44, 0x21, 0x10, 0x84, 0x42, 0x31, 0x0,

    /* U+0030 "0" */
    0x74, 0x63, 0x1a, 0xc6, 0x31, 0x70,

    /* U+0031 "1" */
    0x31, 0x49, 0x4, 0x10, 0x41, 0x4, 0xfc,

    /* U+0032 "2" */
    0x74, 0x62, 0x11, 0x19, 0x88, 0xf8,

    /* U+0033 "3" */
    0xf8, 0x88, 0x60, 0x86, 0x31, 0x70,

    /* U+0034 "4" */
    0x10, 0x88, 0x84, 0xc7, 0xe1, 0x8,

    /* U+0035 "5" */
    0xfc, 0x21, 0xe8, 0x84, 0x31, 0x70,

    /* U+0036 "6" */
    0x21, 0x10, 0xe8, 0xc6, 0x31, 0x70,

    /* U+0037 "7" */
    0xfe, 0x20, 0x82, 0x10, 0x42, 0x8, 0x20,

    /* U+0038 "8" */
    0x74, 0x62, 0xa2, 0x6e, 0x31, 0x70,

    /* U+0039 "9" */
    0x74, 0x63, 0x18, 0xb8, 0x44, 0x20,

    /* U+003A ":" */
    0xf0, 0x3c,

    /* U+003B ";" */
    0x6c, 0x0, 0xd2, 0x40,

    /* U+003C "<" */
    0x19, 0x31, 0x83, 0x4,

    /* U+003D "=" */
    0xf8, 0x1, 0xf0,

    /* U+003E ">" */
    0xc1, 0x6, 0x36, 0x40,

    /* U+003F "?" */
    0xe1, 0x11, 0x64, 0x40, 0x40,

    /* U+0040 "@" */
    0x7b, 0x38, 0x6f, 0xa6, 0x9a, 0x6f, 0x83, 0x7,
    0x0,

    /* U+0041 "A" */
    0x21, 0x45, 0x14, 0x51, 0x2f, 0xa2, 0x88,

    /* U+0042 "B" */
    0xf4, 0x63, 0x1f, 0x46, 0x31, 0xf0,

    /* U+0043 "C" */
    0x74, 0x63, 0x8, 0x42, 0x31, 0x70,

    /* U+0044 "D" */
    0xf4, 0x63, 0x18, 0xc6, 0x31, 0xf0,

    /* U+0045 "E" */
    0xfc, 0x21, 0xf, 0xc2, 0x10, 0xf8,

    /* U+0046 "F" */
    0xfc, 0x21, 0xf, 0xc2, 0x10, 0x80,

    /* U+0047 "G" */
    0x74, 0x61, 0xb, 0xc6, 0x31, 0x70,

    /* U+0048 "H" */
    0x8c, 0x63, 0x1f, 0xc6, 0x31, 0x88,

    /* U+0049 "I" */
    0xf9, 0x8, 0x42, 0x10, 0x84, 0xf8,

    /* U+004A "J" */
    0x38, 0x42, 0x10, 0x86, 0x31, 0x70,

    /* U+004B "K" */
    0x8a, 0x29, 0x24, 0xe2, 0x49, 0x22, 0x88,

    /* U+004C "L" */
    0x84, 0x21, 0x8, 0x42, 0x10, 0xf8,

    /* U+004D "M" */
    0xce, 0xf7, 0xda, 0xc6, 0x31, 0x88,

    /* U+004E "N" */
    0xce, 0x73, 0x5a, 0xd6, 0x73, 0x98,

    /* U+004F "O" */
    0x74, 0x63, 0x18, 0xc6, 0x31, 0x70,

    /* U+0050 "P" */
    0xf4, 0x63, 0x1f, 0x42, 0x10, 0x80,

    /* U+0051 "Q" */
    0x74, 0x63, 0x18, 0xc6, 0x31, 0x70, 0x82,

    /* U+0052 "R" */
    0xf4, 0x63, 0x1f, 0x4a, 0x52, 0x88,

    /* U+0053 "S" */
    0x74, 0x61, 0x83, 0x4, 0x31, 0x70,

    /* U+0054 "T" */
    0xf9, 0x8, 0x42, 0x10, 0x84, 0x20,

    /* U+0055 "U" */
    0x8c, 0x63, 0x18, 0xc6, 0x31, 0x70,

    /* U+0056 "V" */
    0x8a, 0x28, 0x92, 0x51, 0x45, 0x14, 0x20,

    /* U+0057 "W" */
    0x93, 0x25, 0xcb, 0x66, 0xcd, 0x9b, 0x36, 0x64,

    /* U+0058 "X" */
    0x8b, 0x25, 0xc, 0x21, 0x45, 0x22, 0x88,

    /* U+0059 "Y" */
    0x44, 0x88, 0xa1, 0x42, 0x82, 0x4, 0x8, 0x10,

    /* U+005A "Z" */
    0xf8, 0x44, 0x22, 0x21, 0x10, 0xf8,

    /* U+005B "[" */
    0xf2, 0x49, 0x24, 0x92, 0x70,

    /* U+005C "\\" */
    0x86, 0x10, 0x82, 0x10, 0x82, 0x10, 0x82, 0x10,

    /* U+005D "]" */
    0xe4, 0x92, 0x49, 0x24, 0xf0,

    /* U+005E "^" */
    0x22, 0x94, 0x98, 0x80,

    /* U+005F "_" */
    0xf8,

    /* U+0061 "a" */
    0x76, 0x42, 0xf8, 0xc5, 0xe0,

    /* U+0062 "b" */
    0x84, 0x3d, 0x18, 0xc6, 0x31, 0xf0,

    /* U+0063 "c" */
    0x74, 0x61, 0x8, 0x45, 0xc0,

    /* U+0064 "d" */
    0x8, 0x5f, 0x18, 0xc6, 0x31, 0x78,

    /* U+0065 "e" */
    0x74, 0x63, 0xf8, 0x45, 0xc0,

    /* U+0066 "f" */
    0x3c, 0x82, 0x3f, 0x20, 0x82, 0x8, 0x20,

    /* U+0067 "g" */
    0x6c, 0xe3, 0x18, 0xbc, 0x21, 0x70,

    /* U+0068 "h" */
    0x84, 0x2d, 0x98, 0xc6, 0x31, 0x88,

    /* U+0069 "i" */
    0x21, 0x1, 0xc2, 0x10, 0x84, 0x27, 0xc0,

    /* U+006A "j" */
    0x11, 0x7, 0x11, 0x11, 0x11, 0x1e,

    /* U+006B "k" */
    0x84, 0x23, 0x29, 0x72, 0x53, 0x88,

    /* U+006C "l" */
    0xe0, 0x82, 0x8, 0x20, 0x82, 0x8, 0x3c,

    /* U+006D "m" */
    0xfd, 0x6b, 0x5a, 0xd6, 0xa0,

    /* U+006E "n" */
    0xb6, 0x63, 0x18, 0xc6, 0x20,

    /* U+006F "o" */
    0x74, 0x63, 0x18, 0xc5, 0xc0,

    /* U+0070 "p" */
    0xf4, 0x63, 0x18, 0xc7, 0xd0, 0x80,

    /* U+0071 "q" */
    0x7c, 0x63, 0x18, 0xc5, 0xe1, 0x8,

    /* U+0072 "r" */
    0xf6, 0x63, 0x8, 0x42, 0x0,

    /* U+0073 "s" */
    0x74, 0x60, 0xe0, 0xc5, 0xc0,

    /* U+0074 "t" */
    0x20, 0x8f, 0xc8, 0x20, 0x82, 0x8, 0x3c,

    /* U+0075 "u" */
    0x8c, 0x63, 0x18, 0xc5, 0xc0,

    /* U+0076 "v" */
    0x8c, 0x62, 0xa5, 0x28, 0x80,

    /* U+0077 "w" */
    0x92, 0xe5, 0xd3, 0x66, 0xcd, 0x9b, 0x0,

    /* U+0078 "x" */
    0x89, 0x45, 0x8, 0x51, 0x68, 0x80,

    /* U+0079 "y" */
    0x8c, 0x52, 0xa5, 0x10, 0x84, 0x40,

    /* U+007A "z" */
    0xf8, 0xc4, 0x44, 0x43, 0xe0,

    /* U+007B "{" */
    0x19, 0x8, 0x42, 0x13, 0x4, 0x21, 0x8, 0x30,

    /* U+007C "|" */
    0xff, 0xf0,

    /* U+007D "}" */
    0xc1, 0x8, 0x42, 0x10, 0x64, 0x21, 0x9, 0x80,

    /* U+00A7 "§" */
    0x74, 0x60, 0xe8, 0xc7, 0x26, 0xc, 0x5c,

    /* U+00AB "«" */
    0x34, 0x59, 0x22, 0x42, 0xc6, 0x80,

    /* U+00B0 "°" */
    0x69, 0x96,

    /* U+00B4 "´" */
    0x60,

    /* U+00BB "»" */
    0x48, 0x58, 0xd1, 0xa2, 0xc9, 0x0,

    /* U+00C4 "Ä" */
    0x48, 0x0, 0xc, 0x31, 0xe4, 0x92, 0x49, 0xe8,
    0x61,

    /* U+00D6 "Ö" */
    0x50, 0x0, 0xe8, 0xc6, 0x31, 0x8c, 0x62, 0xe0,

    /* U+00DC "Ü" */
    0x50, 0x1, 0x18, 0xc6, 0x31, 0x8c, 0x62, 0xe0,

    /* U+00DF "ß" */
    0x74, 0x63, 0x1b, 0x46, 0x31, 0xb0,

    /* U+00E4 "ä" */
    0x4a, 0x40, 0xe0, 0x85, 0xf1, 0x8b, 0xc0,

    /* U+00F6 "ö" */
    0x52, 0x80, 0xe8, 0xc6, 0x31, 0x8b, 0x80,

    /* U+00FC "ü" */
    0x52, 0x81, 0x18, 0xc6, 0x31, 0x8b, 0x80,

    /* U+20AC "€" */
    0x39, 0x14, 0x3c, 0x43, 0xc4, 0x11, 0x38,

    /* U+2190 "←" */
    0x10, 0x41, 0x7, 0xf4, 0x4, 0x4, 0x0,

    /* U+2191 "↑" */
    0x10, 0x71, 0x54, 0x91, 0x2, 0x4, 0x8, 0x10,

    /* U+2192 "→" */
    0x18, 0x10, 0x17, 0xf0, 0x41, 0x6, 0x0,

    /* U+2193 "↓" */
    0x10, 0x20, 0x40, 0x81, 0x12, 0x75, 0x9c, 0x10,

    /* U+2194 "↔" */
    0x32, 0x11, 0x90, 0x5f, 0xf4, 0x11, 0x18, 0xc8,

    /* U+2195 "↕" */
    0x10, 0x71, 0x54, 0x91, 0x2, 0x4, 0x8, 0x11,
    0x25, 0x51, 0xc1, 0x0,

    /* U+2196 "↖" */
    0xf9, 0x82, 0x84, 0x88, 0x80, 0x80, 0x0,

    /* U+2197 "↗" */
    0x3e, 0xc, 0x28, 0x92, 0x28, 0x0, 0x0,

    /* U+2198 "↘" */
    0x0, 0x80, 0x88, 0x90, 0xa0, 0xcf, 0x80,

    /* U+2199 "↙" */
    0x0, 0xa, 0x24, 0x8a, 0x18, 0x3e, 0x0,

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
    {.bitmap_index = 0, .adv_w = 115, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 115, .box_w = 1, .box_h = 9, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 3, .adv_w = 115, .box_w = 3, .box_h = 4, .ofs_x = 2, .ofs_y = 5},
    {.bitmap_index = 5, .adv_w = 115, .box_w = 7, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 13, .adv_w = 115, .box_w = 5, .box_h = 13, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 22, .adv_w = 115, .box_w = 7, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 30, .adv_w = 115, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 37, .adv_w = 115, .box_w = 4, .box_h = 13, .ofs_x = 2, .ofs_y = -2},
    {.bitmap_index = 44, .adv_w = 115, .box_w = 4, .box_h = 13, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 51, .adv_w = 115, .box_w = 5, .box_h = 6, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 55, .adv_w = 115, .box_w = 2, .box_h = 4, .ofs_x = 2, .ofs_y = -2},
    {.bitmap_index = 56, .adv_w = 115, .box_w = 4, .box_h = 1, .ofs_x = 2, .ofs_y = 4},
    {.bitmap_index = 57, .adv_w = 115, .box_w = 2, .box_h = 2, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 58, .adv_w = 115, .box_w = 5, .box_h = 12, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 66, .adv_w = 115, .box_w = 5, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 72, .adv_w = 115, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 79, .adv_w = 115, .box_w = 5, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 85, .adv_w = 115, .box_w = 5, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 91, .adv_w = 115, .box_w = 5, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 97, .adv_w = 115, .box_w = 5, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 103, .adv_w = 115, .box_w = 5, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 109, .adv_w = 115, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 116, .adv_w = 115, .box_w = 5, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 122, .adv_w = 115, .box_w = 5, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 128, .adv_w = 115, .box_w = 2, .box_h = 7, .ofs_x = 3, .ofs_y = 0},
    {.bitmap_index = 130, .adv_w = 115, .box_w = 3, .box_h = 9, .ofs_x = 2, .ofs_y = -2},
    {.bitmap_index = 134, .adv_w = 115, .box_w = 5, .box_h = 6, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 138, .adv_w = 115, .box_w = 5, .box_h = 4, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 141, .adv_w = 115, .box_w = 5, .box_h = 6, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 145, .adv_w = 115, .box_w = 4, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 150, .adv_w = 115, .box_w = 6, .box_h = 11, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 159, .adv_w = 115, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 166, .adv_w = 115, .box_w = 5, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 172, .adv_w = 115, .box_w = 5, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 178, .adv_w = 115, .box_w = 5, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 184, .adv_w = 115, .box_w = 5, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 190, .adv_w = 115, .box_w = 5, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 196, .adv_w = 115, .box_w = 5, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 202, .adv_w = 115, .box_w = 5, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 208, .adv_w = 115, .box_w = 5, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 214, .adv_w = 115, .box_w = 5, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 220, .adv_w = 115, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 227, .adv_w = 115, .box_w = 5, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 233, .adv_w = 115, .box_w = 5, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 239, .adv_w = 115, .box_w = 5, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 245, .adv_w = 115, .box_w = 5, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 251, .adv_w = 115, .box_w = 5, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 257, .adv_w = 115, .box_w = 5, .box_h = 11, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 264, .adv_w = 115, .box_w = 5, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 270, .adv_w = 115, .box_w = 5, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 276, .adv_w = 115, .box_w = 5, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 282, .adv_w = 115, .box_w = 5, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 288, .adv_w = 115, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 295, .adv_w = 115, .box_w = 7, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 303, .adv_w = 115, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 310, .adv_w = 115, .box_w = 7, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 318, .adv_w = 115, .box_w = 5, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 324, .adv_w = 115, .box_w = 3, .box_h = 12, .ofs_x = 3, .ofs_y = -1},
    {.bitmap_index = 329, .adv_w = 115, .box_w = 5, .box_h = 12, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 337, .adv_w = 115, .box_w = 3, .box_h = 12, .ofs_x = 2, .ofs_y = -1},
    {.bitmap_index = 342, .adv_w = 115, .box_w = 5, .box_h = 5, .ofs_x = 1, .ofs_y = 4},
    {.bitmap_index = 346, .adv_w = 115, .box_w = 5, .box_h = 1, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 347, .adv_w = 115, .box_w = 5, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 352, .adv_w = 115, .box_w = 5, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 358, .adv_w = 115, .box_w = 5, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 363, .adv_w = 115, .box_w = 5, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 369, .adv_w = 115, .box_w = 5, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 374, .adv_w = 115, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 381, .adv_w = 115, .box_w = 5, .box_h = 9, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 387, .adv_w = 115, .box_w = 5, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 393, .adv_w = 115, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 400, .adv_w = 115, .box_w = 4, .box_h = 12, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 406, .adv_w = 115, .box_w = 5, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 412, .adv_w = 115, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 419, .adv_w = 115, .box_w = 5, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 424, .adv_w = 115, .box_w = 5, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 429, .adv_w = 115, .box_w = 5, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 434, .adv_w = 115, .box_w = 5, .box_h = 9, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 440, .adv_w = 115, .box_w = 5, .box_h = 9, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 446, .adv_w = 115, .box_w = 5, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 451, .adv_w = 115, .box_w = 5, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 456, .adv_w = 115, .box_w = 6, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 463, .adv_w = 115, .box_w = 5, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 468, .adv_w = 115, .box_w = 5, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 473, .adv_w = 115, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 480, .adv_w = 115, .box_w = 6, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 486, .adv_w = 115, .box_w = 5, .box_h = 9, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 492, .adv_w = 115, .box_w = 5, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 497, .adv_w = 115, .box_w = 5, .box_h = 12, .ofs_x = 2, .ofs_y = -1},
    {.bitmap_index = 505, .adv_w = 115, .box_w = 1, .box_h = 12, .ofs_x = 3, .ofs_y = -1},
    {.bitmap_index = 507, .adv_w = 115, .box_w = 5, .box_h = 12, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 515, .adv_w = 115, .box_w = 5, .box_h = 11, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 522, .adv_w = 115, .box_w = 7, .box_h = 6, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 528, .adv_w = 115, .box_w = 4, .box_h = 4, .ofs_x = 2, .ofs_y = 5},
    {.bitmap_index = 530, .adv_w = 115, .box_w = 2, .box_h = 2, .ofs_x = 3, .ofs_y = 8},
    {.bitmap_index = 531, .adv_w = 115, .box_w = 7, .box_h = 6, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 537, .adv_w = 115, .box_w = 6, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 546, .adv_w = 115, .box_w = 5, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 554, .adv_w = 115, .box_w = 5, .box_h = 12, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 562, .adv_w = 115, .box_w = 5, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 568, .adv_w = 115, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 575, .adv_w = 115, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 582, .adv_w = 115, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 589, .adv_w = 115, .box_w = 6, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 596, .adv_w = 115, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 603, .adv_w = 115, .box_w = 7, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 611, .adv_w = 115, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 618, .adv_w = 115, .box_w = 7, .box_h = 9, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 626, .adv_w = 115, .box_w = 9, .box_h = 7, .ofs_x = -1, .ofs_y = 0},
    {.bitmap_index = 634, .adv_w = 115, .box_w = 7, .box_h = 13, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 646, .adv_w = 115, .box_w = 7, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 653, .adv_w = 115, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 660, .adv_w = 115, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 667, .adv_w = 115, .box_w = 7, .box_h = 7, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 674, .adv_w = 115, .box_w = 7, .box_h = 15, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 688, .adv_w = 115, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 695, .adv_w = 115, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 703, .adv_w = 115, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 711, .adv_w = 115, .box_w = 8, .box_h = 8, .ofs_x = -1, .ofs_y = 1},
    {.bitmap_index = 719, .adv_w = 115, .box_w = 5, .box_h = 9, .ofs_x = 1, .ofs_y = 0}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint8_t glyph_id_ofs_list_0[] = {
    0, 1, 2, 3, 4, 5, 6, 0,
    7, 8
};

static const uint16_t unicode_list_3[] = {
    0x0, 0x4, 0x9, 0xd, 0x14, 0x1d, 0x2f, 0x35,
    0x38, 0x3d, 0x4f, 0x55, 0x2005, 0x20e9, 0x20ea, 0x20eb,
    0x20ec, 0x20ed, 0x20ee, 0x20ef, 0x20f0, 0x20f1, 0x20f2, 0x24ea,
    0x24f9, 0x2525, 0x2527, 0x2542, 0x26ca
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 10, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = glyph_id_ofs_list_0, .list_length = 10, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_FULL
    },
    {
        .range_start = 43, .range_length = 53, .glyph_id_start = 10,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 97, .range_length = 29, .glyph_id_start = 63,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 167, .range_length = 9931, .glyph_id_start = 92,
        .unicode_list = unicode_list_3, .glyph_id_ofs_list = NULL, .list_length = 29, .type = LV_FONT_FMT_TXT_CMAP_SPARSE_TINY
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
const lv_font_t jetbrains_mono_light_12 = {
#else
lv_font_t jetbrains_mono_light_12 = {
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



#endif /*#if JETBRAINS_MONO_LIGHT_12*/

