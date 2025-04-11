/*******************************************************************************
 * Size: 8 px
 * Bpp: 1
 * Opts: --bpp 1 --size 8 --no-compress --font JetBrainsMono-Bold.ttf --symbols a bcdefghijklmnopqrstuvwxyz.,-öäü+#´ß?ÄÖÜ<>|;:_{[]}\@€ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890^!"§$%&/()=*?/-+░❱◎↘◌◩«■»°← → ↔ ↑ ↓ , ↕ , ↖ ↗ ↘ ↙ , ⤡ ⤢ --format lvgl -o jetbrains_mono_bold_8.c
 ******************************************************************************/

#include "lvgl.h"

#ifndef JETBRAINS_MONO_BOLD_8
#define JETBRAINS_MONO_BOLD_8 1
#endif

#if JETBRAINS_MONO_BOLD_8

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+0021 "!" */
    0xf2,

    /* U+0022 "\"" */
    0xb4,

    /* U+0023 "#" */
    0x52, 0xbe, 0xaf, 0x32, 0x80,

    /* U+0024 "$" */
    0x4e, 0xdc, 0xe5, 0xde, 0x40,

    /* U+0025 "%" */
    0xce, 0xb5, 0xc7, 0xb6, 0xe0,

    /* U+0026 "&" */
    0x69, 0x44, 0xba, 0xf0,

    /* U+0028 "(" */
    0x2e, 0x49, 0x26, 0x60,

    /* U+0029 ")" */
    0x98, 0x92, 0x4b, 0xc0,

    /* U+002A " * " */
    0x27, 0xd8, 0xa0,

    /* U+002B "+" */
    0x4f, 0x44,

    /* U+002C "," */
    0x58,

    /* U+002D "-" */
    0xe0,

    /* U+002E "." */
    0x80,

    /* U+002F "/" */
    0x11, 0x12, 0x22, 0x44, 0x40,

    /* U+0030 "0" */
    0x69, 0x9d, 0x99, 0x60,

    /* U+0031 "1" */
    0x6e, 0x22, 0x22, 0x70,

    /* U+0032 "2" */
    0x69, 0x13, 0x6c, 0xf0,

    /* U+0033 "3" */
    0x72, 0x27, 0x19, 0x70,

    /* U+0034 "4" */
    0x22, 0x4d, 0x9f, 0x10,

    /* U+0035 "5" */
    0xf8, 0x8f, 0x19, 0xe0,

    /* U+0036 "6" */
    0x24, 0x4f, 0x99, 0x60,

    /* U+0037 "7" */
    0xf9, 0x22, 0x24, 0x40,

    /* U+0038 "8" */
    0x69, 0x96, 0x99, 0x60,

    /* U+0039 "9" */
    0x69, 0x99, 0x62, 0x40,

    /* U+003A ":" */
    0x88,

    /* U+003B ";" */
    0x8e,

    /* U+003C "<" */
    0x3c, 0xc3, 0x10,

    /* U+003D "=" */
    0xe3, 0x80,

    /* U+003E ">" */
    0xc3, 0x3c, 0x0,

    /* U+003F "?" */
    0xc4, 0xa0, 0x30,

    /* U+0040 "@" */
    0x69, 0x9f, 0xdd, 0xf8, 0x40,

    /* U+0041 "A" */
    0x23, 0x14, 0xa7, 0x2a, 0x40,

    /* U+0042 "B" */
    0xe9, 0x9e, 0x99, 0xe0,

    /* U+0043 "C" */
    0x6a, 0x88, 0x8a, 0x60,

    /* U+0044 "D" */
    0xe9, 0x99, 0x99, 0xe0,

    /* U+0045 "E" */
    0xf8, 0x8e, 0x88, 0xf0,

    /* U+0046 "F" */
    0xf8, 0x8e, 0x88, 0x80,

    /* U+0047 "G" */
    0x69, 0x8b, 0x99, 0x60,

    /* U+0048 "H" */
    0x99, 0x9f, 0x99, 0x90,

    /* U+0049 "I" */
    0xe9, 0x24, 0xb8,

    /* U+004A "J" */
    0x31, 0x11, 0x19, 0x60,

    /* U+004B "K" */
    0x9a, 0xae, 0xaa, 0x90,

    /* U+004C "L" */
    0x92, 0x49, 0x38,

    /* U+004D "M" */
    0x9f, 0xff, 0x99, 0x90,

    /* U+004E "N" */
    0xdd, 0xdd, 0xbb, 0xb0,

    /* U+004F "O" */
    0x69, 0x99, 0x99, 0x60,

    /* U+0050 "P" */
    0xe9, 0x9e, 0x88, 0x80,

    /* U+0051 "Q" */
    0x69, 0x99, 0x99, 0x62, 0x10,

    /* U+0052 "R" */
    0xe9, 0x9e, 0xab, 0x90,

    /* U+0053 "S" */
    0x69, 0x86, 0x19, 0xe0,

    /* U+0054 "T" */
    0xf2, 0x22, 0x22, 0x20,

    /* U+0055 "U" */
    0x99, 0x99, 0x99, 0x60,

    /* U+0056 "V" */
    0x92, 0x94, 0xa5, 0x30, 0x80,

    /* U+0057 "W" */
    0xdf, 0xff, 0xff, 0xf0,

    /* U+0058 "X" */
    0x52, 0x98, 0x46, 0x2b, 0x40,

    /* U+0059 "Y" */
    0xd2, 0x94, 0x42, 0x10, 0x80,

    /* U+005A "Z" */
    0xe5, 0x25, 0x38,

    /* U+005B "[" */
    0xea, 0xab,

    /* U+005C "\\" */
    0xc4, 0x46, 0x22, 0x21, 0x10,

    /* U+005D "]" */
    0xd5, 0x57,

    /* U+005E "^" */
    0x4a, 0xd0,

    /* U+005F "_" */
    0xf0,

    /* U+0061 "a" */
    0x79, 0xf9, 0xf0,

    /* U+0062 "b" */
    0x88, 0xf9, 0x99, 0xf0,

    /* U+0063 "c" */
    0xe8, 0x88, 0xe0,

    /* U+0064 "d" */
    0x11, 0xf9, 0x99, 0xf0,

    /* U+0065 "e" */
    0x69, 0xf8, 0x60,

    /* U+0066 "f" */
    0x74, 0x4f, 0x44, 0x40,

    /* U+0067 "g" */
    0x79, 0x99, 0xf1, 0x70,

    /* U+0068 "h" */
    0x88, 0xf9, 0x99, 0x90,

    /* U+0069 "i" */
    0x4, 0xe, 0x22, 0x2f,

    /* U+006A "j" */
    0x0, 0x72, 0x49, 0x38,

    /* U+006B "k" */
    0x88, 0xba, 0xea, 0xb0,

    /* U+006C "l" */
    0xc4, 0x44, 0x44, 0x70,

    /* U+006D "m" */
    0xfd, 0xdd, 0xd0,

    /* U+006E "n" */
    0xf9, 0x99, 0x90,

    /* U+006F "o" */
    0x69, 0x99, 0x60,

    /* U+0070 "p" */
    0xf9, 0x99, 0xf8, 0x80,

    /* U+0071 "q" */
    0xf9, 0x99, 0xf1, 0x10,

    /* U+0072 "r" */
    0xf9, 0x88, 0x80,

    /* U+0073 "s" */
    0xe8, 0x62, 0xe0,

    /* U+0074 "t" */
    0x44, 0xf4, 0x44, 0x70,

    /* U+0075 "u" */
    0x99, 0x99, 0x60,

    /* U+0076 "v" */
    0x95, 0x56, 0x20,

    /* U+0077 "w" */
    0xad, 0xbd, 0xa5, 0x0,

    /* U+0078 "x" */
    0x53, 0x88, 0xa5, 0x0,

    /* U+0079 "y" */
    0xd2, 0x94, 0xc2, 0x11, 0x80,

    /* U+007A "z" */
    0xf2, 0x4c, 0xf0,

    /* U+007B "{" */
    0x32, 0x2c, 0x22, 0x23,

    /* U+007C "|" */
    0xff,

    /* U+007D "}" */
    0xc4, 0x43, 0x44, 0x4c,

    /* U+00A7 "§" */
    0xe8, 0xef, 0x97, 0x9f,

    /* U+00AB "«" */
    0x53, 0x9c, 0xa0,

    /* U+00B0 "°" */
    0xf7, 0x80,

    /* U+00B4 "´" */
    0x80,

    /* U+00BB "»" */
    0x72, 0x94, 0xe0,

    /* U+00C4 "Ä" */
    0x51, 0x18, 0xa5, 0x39, 0x52,

    /* U+00D6 "Ö" */
    0xa6, 0x99, 0x99, 0x96,

    /* U+00DC "Ü" */
    0xa9, 0x99, 0x99, 0x96,

    /* U+00DF "ß" */
    0x69, 0x9b, 0x99, 0xa0,

    /* U+00E4 "ä" */
    0x44, 0x7, 0x9f, 0x9f,

    /* U+00F6 "ö" */
    0x80, 0x6, 0x99, 0x96,

    /* U+00FC "ü" */
    0x80, 0x9, 0x99, 0x96,

    /* U+20AC "€" */
    0x32, 0x78, 0x8e, 0x24, 0xc0,

    /* U+2190 "←" */
    0x22, 0x3e, 0x82, 0x0,

    /* U+2191 "↑" */
    0x23, 0x88, 0x42, 0x10,

    /* U+2192 "→" */
    0x20, 0xbe, 0x22, 0x0,

    /* U+2193 "↓" */
    0x21, 0x8, 0x4b, 0x30,

    /* U+2194 "↔" */
    0x29, 0x1f, 0xd1, 0x28,

    /* U+2195 "↕" */
    0x27, 0xc8, 0x42, 0x12, 0xae,

    /* U+2196 "↖" */
    0xf6, 0x29, 0x20, 0x0,

    /* U+2197 "↗" */
    0x78, 0xca, 0x90, 0x0,

    /* U+2198 "↘" */
    0x2, 0x4a, 0x37, 0x80,

    /* U+2199 "↙" */
    0x4, 0xa9, 0x8f, 0x0,

    /* U+2591 "░" */
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfe,

    /* U+25A0 "■" */
    0xff, 0xff, 0xff, 0x80,

    /* U+25CC "◌" */
    0x31, 0x28, 0x61, 0x48, 0xc0,

    /* U+25CE "◎" */
    0x7d, 0xf7, 0xd7, 0x0,

    /* U+25E9 "◩" */
    0xff, 0x73, 0x1f, 0x80,

    /* U+2771 "❱" */
    0xd9, 0xbd, 0x80};

/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 77, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 77, .box_w = 1, .box_h = 7, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 2, .adv_w = 77, .box_w = 3, .box_h = 2, .ofs_x = 1, .ofs_y = 5},
    {.bitmap_index = 3, .adv_w = 77, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 8, .adv_w = 77, .box_w = 4, .box_h = 9, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 13, .adv_w = 77, .box_w = 5, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 18, .adv_w = 77, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 22, .adv_w = 77, .box_w = 3, .box_h = 9, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 26, .adv_w = 77, .box_w = 3, .box_h = 9, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 30, .adv_w = 77, .box_w = 5, .box_h = 4, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 33, .adv_w = 77, .box_w = 4, .box_h = 4, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 35, .adv_w = 77, .box_w = 2, .box_h = 3, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 36, .adv_w = 77, .box_w = 3, .box_h = 1, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 37, .adv_w = 77, .box_w = 1, .box_h = 1, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 38, .adv_w = 77, .box_w = 4, .box_h = 9, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 43, .adv_w = 77, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 47, .adv_w = 77, .box_w = 4, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 51, .adv_w = 77, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 55, .adv_w = 77, .box_w = 4, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 59, .adv_w = 77, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 63, .adv_w = 77, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 67, .adv_w = 77, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 71, .adv_w = 77, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 75, .adv_w = 77, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 79, .adv_w = 77, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 83, .adv_w = 77, .box_w = 1, .box_h = 5, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 84, .adv_w = 77, .box_w = 1, .box_h = 7, .ofs_x = 2, .ofs_y = -2},
    {.bitmap_index = 85, .adv_w = 77, .box_w = 4, .box_h = 5, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 88, .adv_w = 77, .box_w = 3, .box_h = 3, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 90, .adv_w = 77, .box_w = 4, .box_h = 5, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 93, .adv_w = 77, .box_w = 3, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 96, .adv_w = 77, .box_w = 4, .box_h = 9, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 101, .adv_w = 77, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 106, .adv_w = 77, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 110, .adv_w = 77, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 114, .adv_w = 77, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 118, .adv_w = 77, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 122, .adv_w = 77, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 126, .adv_w = 77, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 130, .adv_w = 77, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 134, .adv_w = 77, .box_w = 3, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 137, .adv_w = 77, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 141, .adv_w = 77, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 145, .adv_w = 77, .box_w = 3, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 148, .adv_w = 77, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 152, .adv_w = 77, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 156, .adv_w = 77, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 160, .adv_w = 77, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 164, .adv_w = 77, .box_w = 4, .box_h = 9, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 169, .adv_w = 77, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 173, .adv_w = 77, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 177, .adv_w = 77, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 181, .adv_w = 77, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 185, .adv_w = 77, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 190, .adv_w = 77, .box_w = 4, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 194, .adv_w = 77, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 199, .adv_w = 77, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 204, .adv_w = 77, .box_w = 3, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 207, .adv_w = 77, .box_w = 2, .box_h = 8, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 209, .adv_w = 77, .box_w = 4, .box_h = 9, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 214, .adv_w = 77, .box_w = 2, .box_h = 8, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 216, .adv_w = 77, .box_w = 3, .box_h = 4, .ofs_x = 1, .ofs_y = 3},
    {.bitmap_index = 218, .adv_w = 77, .box_w = 4, .box_h = 1, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 219, .adv_w = 77, .box_w = 4, .box_h = 5, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 222, .adv_w = 77, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 226, .adv_w = 77, .box_w = 4, .box_h = 5, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 229, .adv_w = 77, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 233, .adv_w = 77, .box_w = 4, .box_h = 5, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 236, .adv_w = 77, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 240, .adv_w = 77, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 244, .adv_w = 77, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 248, .adv_w = 77, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 252, .adv_w = 77, .box_w = 3, .box_h = 10, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 256, .adv_w = 77, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 260, .adv_w = 77, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 264, .adv_w = 77, .box_w = 4, .box_h = 5, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 267, .adv_w = 77, .box_w = 4, .box_h = 5, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 270, .adv_w = 77, .box_w = 4, .box_h = 5, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 273, .adv_w = 77, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 277, .adv_w = 77, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 281, .adv_w = 77, .box_w = 4, .box_h = 5, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 284, .adv_w = 77, .box_w = 4, .box_h = 5, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 287, .adv_w = 77, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 291, .adv_w = 77, .box_w = 4, .box_h = 5, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 294, .adv_w = 77, .box_w = 4, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 297, .adv_w = 77, .box_w = 5, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 301, .adv_w = 77, .box_w = 5, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 305, .adv_w = 77, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 310, .adv_w = 77, .box_w = 4, .box_h = 5, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 313, .adv_w = 77, .box_w = 4, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 317, .adv_w = 77, .box_w = 1, .box_h = 8, .ofs_x = 2, .ofs_y = -1},
    {.bitmap_index = 318, .adv_w = 77, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 322, .adv_w = 77, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 326, .adv_w = 77, .box_w = 5, .box_h = 4, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 329, .adv_w = 77, .box_w = 3, .box_h = 3, .ofs_x = 1, .ofs_y = 4},
    {.bitmap_index = 331, .adv_w = 77, .box_w = 1, .box_h = 1, .ofs_x = 2, .ofs_y = 6},
    {.bitmap_index = 332, .adv_w = 77, .box_w = 5, .box_h = 4, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 335, .adv_w = 77, .box_w = 5, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 340, .adv_w = 77, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 344, .adv_w = 77, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 348, .adv_w = 77, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 352, .adv_w = 77, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 356, .adv_w = 77, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 360, .adv_w = 77, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 364, .adv_w = 77, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 369, .adv_w = 77, .box_w = 5, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 373, .adv_w = 77, .box_w = 5, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 377, .adv_w = 77, .box_w = 5, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 381, .adv_w = 77, .box_w = 5, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 385, .adv_w = 77, .box_w = 6, .box_h = 5, .ofs_x = -1, .ofs_y = 0},
    {.bitmap_index = 389, .adv_w = 77, .box_w = 5, .box_h = 8, .ofs_x = 0, .ofs_y = -1},
    {.bitmap_index = 394, .adv_w = 77, .box_w = 5, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 398, .adv_w = 77, .box_w = 5, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 402, .adv_w = 77, .box_w = 5, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 406, .adv_w = 77, .box_w = 5, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 410, .adv_w = 77, .box_w = 5, .box_h = 11, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 417, .adv_w = 77, .box_w = 5, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 421, .adv_w = 77, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 426, .adv_w = 77, .box_w = 5, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 430, .adv_w = 77, .box_w = 5, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 434, .adv_w = 77, .box_w = 3, .box_h = 6, .ofs_x = 1, .ofs_y = 0}};

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
const lv_font_t jetbrains_mono_bold_8 = {
#else
lv_font_t jetbrains_mono_bold_8 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt, /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt, /*Function pointer to get glyph's bitmap*/
    .line_height = 11,                              /*The maximum line height required by the font*/
    .base_line = 2,                                 /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -1,
    .underline_thickness = 0,
#endif
    .dsc = &font_dsc, /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
#if LV_VERSION_CHECK(8, 2, 0) || LVGL_VERSION_MAJOR >= 9
    .fallback = NULL,
#endif
    .user_data = NULL,
};

#endif /*#if JETBRAINS_MONO_BOLD_8*/
