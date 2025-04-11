/*******************************************************************************
 * Size: 10 px
 * Bpp: 1
 * Opts: --bpp 1 --size 10 --no-compress --font JetBrainsMono-Bold.ttf --symbols a bcdefghijklmnopqrstuvwxyz.,-öäü+#´ß?ÄÖÜ<>|;:_{[]}\@€ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890^!"§$%&/()=?*-/+░❱◎↘◌◩«■»°← → ↔ ↑ ↓ , ↕ , ↖ ↗ ↘ ↙ , ⤡ ⤢ --format lvgl -o jetbrains_mono_bold_10.c
 ******************************************************************************/

#include "lvgl.h"

#ifndef JETBRAINS_MONO_BOLD_10
#define JETBRAINS_MONO_BOLD_10 1
#endif

#if JETBRAINS_MONO_BOLD_10

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+0021 "!" */
    0xf9,

    /* U+0022 "\"" */
    0xb6, 0x80,

    /* U+0023 "#" */
    0x28, 0xa7, 0xd2, 0x4b, 0xe5, 0x14,

    /* U+0024 "$" */
    0x23, 0x3f, 0x5a, 0x38, 0xb5, 0x79, 0x8,

    /* U+0025 "%" */
    0xe6, 0xab, 0xbc, 0x3d, 0xd5, 0x67,

    /* U+0026 "&" */
    0x72, 0x90, 0xca, 0xce, 0x4d,

    /* U+0028 "(" */
    0x2e, 0x49, 0x24, 0x4c,

    /* U+0029 ")" */
    0x98, 0x92, 0x49, 0x58,

    /* U+002A "*" */
    0x25, 0x7e, 0xc5, 0x28,

    /* U+002B "+" */
    0x21, 0x3e, 0x42, 0x0,

    /* U+002C "," */
    0x69, 0x0,

    /* U+002D "-" */
    0xe0,

    /* U+002E "." */
    0xf0,

    /* U+002F "/" */
    0x11, 0x32, 0x24, 0x4c, 0x88,

    /* U+0030 "0" */
    0x74, 0x63, 0x58, 0xc6, 0x2e,

    /* U+0031 "1" */
    0x67, 0x8, 0x42, 0x10, 0x9f,

    /* U+0032 "2" */
    0x69, 0x11, 0x26, 0xcf,

    /* U+0033 "3" */
    0x78, 0xc4, 0x60, 0x85, 0x2e,

    /* U+0034 "4" */
    0x22, 0x44, 0x9f, 0x11,

    /* U+0035 "5" */
    0xf8, 0x8e, 0x91, 0x9e,

    /* U+0036 "6" */
    0x31, 0x11, 0xe8, 0xc6, 0x2e,

    /* U+0037 "7" */
    0xfc, 0xc4, 0x23, 0x11, 0x88,

    /* U+0038 "8" */
    0x74, 0x62, 0xe5, 0x46, 0x2e,

    /* U+0039 "9" */
    0x74, 0x63, 0x17, 0x88, 0x8c,

    /* U+003A ":" */
    0xf0, 0xf0,

    /* U+003B ";" */
    0x6c, 0x0, 0xd2,

    /* U+003C "<" */
    0x1b, 0x20, 0xc1, 0x80,

    /* U+003D "=" */
    0xf0, 0xf,

    /* U+003E ">" */
    0xc3, 0x86, 0xec, 0x0,

    /* U+003F "?" */
    0xe1, 0x11, 0x64, 0x4,

    /* U+0040 "@" */
    0x76, 0x63, 0x7a, 0xd6, 0xb7, 0xc3, 0x0,

    /* U+0041 "A" */
    0x30, 0xc3, 0x1e, 0x49, 0xe4, 0xb3,

    /* U+0042 "B" */
    0xf4, 0x63, 0xe8, 0xc6, 0x3e,

    /* U+0043 "C" */
    0x74, 0xa1, 0x8, 0x42, 0x4e,

    /* U+0044 "D" */
    0xe9, 0x99, 0x99, 0x9e,

    /* U+0045 "E" */
    0xf8, 0x8f, 0x88, 0x8f,

    /* U+0046 "F" */
    0xf8, 0x88, 0xf8, 0x88,

    /* U+0047 "G" */
    0x74, 0x61, 0xb, 0xc6, 0x2e,

    /* U+0048 "H" */
    0x99, 0x9f, 0x99, 0x99,

    /* U+0049 "I" */
    0xf2, 0x22, 0x22, 0x2f,

    /* U+004A "J" */
    0x38, 0x42, 0x10, 0x85, 0x2e,

    /* U+004B "K" */
    0x94, 0xa9, 0xca, 0x5a, 0x52,

    /* U+004C "L" */
    0x88, 0x88, 0x88, 0x8f,

    /* U+004D "M" */
    0xde, 0xf7, 0xda, 0xc6, 0x31,

    /* U+004E "N" */
    0xce, 0x7b, 0x5a, 0xde, 0x73,

    /* U+004F "O" */
    0x69, 0x99, 0x99, 0x96,

    /* U+0050 "P" */
    0xf4, 0x63, 0x1f, 0x42, 0x10,

    /* U+0051 "Q" */
    0x74, 0x63, 0x18, 0xc6, 0x2e, 0x10, 0x40,

    /* U+0052 "R" */
    0xf4, 0x63, 0x1f, 0x5a, 0x71,

    /* U+0053 "S" */
    0x74, 0x61, 0xc3, 0x86, 0x2e,

    /* U+0054 "T" */
    0xf9, 0x8, 0x42, 0x10, 0x84,

    /* U+0055 "U" */
    0x99, 0x99, 0x99, 0x96,

    /* U+0056 "V" */
    0xcd, 0x24, 0x92, 0x78, 0xc3, 0xc,

    /* U+0057 "W" */
    0xd5, 0x57, 0x5d, 0x75, 0xd6, 0x9a,

    /* U+0058 "X" */
    0x49, 0x23, 0xc, 0x30, 0xe4, 0x92,

    /* U+0059 "Y" */
    0x8e, 0xd4, 0xa2, 0x10, 0x84,

    /* U+005A "Z" */
    0xf3, 0x22, 0x44, 0xcf,

    /* U+005B "[" */
    0xf2, 0x49, 0x24, 0x9c,

    /* U+005C "\\" */
    0x88, 0xc4, 0x42, 0x23, 0x11,

    /* U+005D "]" */
    0xe4, 0x92, 0x49, 0x3c,

    /* U+005E "^" */
    0x66, 0x99,

    /* U+005F "_" */
    0xf8,

    /* U+0061 "a" */
    0x74, 0x5f, 0x18, 0xbc,

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
    0x79, 0x99, 0x97, 0x16,

    /* U+0068 "h" */
    0x88, 0xe9, 0x99, 0x99,

    /* U+0069 "i" */
    0x21, 0x1, 0xc2, 0x10, 0x84, 0xf8,

    /* U+006A "j" */
    0x11, 0x7, 0x11, 0x11, 0x11, 0xe0,

    /* U+006B "k" */
    0x84, 0x25, 0x6e, 0x52, 0x52,

    /* U+006C "l" */
    0xe0, 0x82, 0x8, 0x20, 0x82, 0x7,

    /* U+006D "m" */
    0xfd, 0x6b, 0x5a, 0xd4,

    /* U+006E "n" */
    0xe9, 0x99, 0x99,

    /* U+006F "o" */
    0x69, 0x99, 0x96,

    /* U+0070 "p" */
    0xe9, 0x99, 0x9e, 0x88,

    /* U+0071 "q" */
    0x79, 0x99, 0x97, 0x11,

    /* U+0072 "r" */
    0xf9, 0x88, 0x88,

    /* U+0073 "s" */
    0x72, 0x5c, 0x3c, 0xb8,

    /* U+0074 "t" */
    0x21, 0x3e, 0x42, 0x10, 0x87,

    /* U+0075 "u" */
    0x99, 0x99, 0x96,

    /* U+0076 "v" */
    0x49, 0x24, 0x9e, 0x30, 0xc0,

    /* U+0077 "w" */
    0xb6, 0xd7, 0x9e, 0x79, 0x20,

    /* U+0078 "x" */
    0x49, 0xe3, 0xc, 0x79, 0x20,

    /* U+0079 "y" */
    0x49, 0x26, 0x8c, 0x30, 0xc2, 0x8,

    /* U+007A "z" */
    0xf3, 0x24, 0xcf,

    /* U+007B "{" */
    0x39, 0x8, 0x4c, 0x10, 0x84, 0x20, 0xc0,

    /* U+007C "|" */
    0xff, 0xc0,

    /* U+007D "}" */
    0xc4, 0x44, 0x34, 0x44, 0x4c,

    /* U+00A7 "§" */
    0x74, 0x70, 0xf8, 0xc9, 0xf1, 0x70,

    /* U+00AB "«" */
    0x29, 0x6d, 0x16, 0x28,

    /* U+00B0 "°" */
    0xf7, 0x80,

    /* U+00B4 "´" */
    0xc0,

    /* U+00BB "»" */
    0x51, 0xa2, 0xda, 0x50,

    /* U+00C4 "Ä" */
    0x48, 0x3, 0x1e, 0x79, 0x24, 0x9e, 0x4a, 0x10,

    /* U+00D6 "Ö" */
    0x50, 0x69, 0x99, 0x99, 0x96,

    /* U+00DC "Ü" */
    0x50, 0x99, 0x99, 0x99, 0x96,

    /* U+00DF "ß" */
    0x74, 0x63, 0x68, 0xc6, 0x36,

    /* U+00E4 "ä" */
    0x52, 0x80, 0xe8, 0xbe, 0x31, 0x78,

    /* U+00F6 "ö" */
    0x55, 0x6, 0x99, 0x99, 0x60,

    /* U+00FC "ü" */
    0x55, 0x9, 0x99, 0x99, 0x60,

    /* U+20AC "€" */
    0x39, 0x34, 0x7c, 0xf1, 0x14, 0xce,

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
    {.bitmap_index = 1, .adv_w = 96, .box_w = 1, .box_h = 8, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 2, .adv_w = 96, .box_w = 3, .box_h = 3, .ofs_x = 1, .ofs_y = 5},
    {.bitmap_index = 4, .adv_w = 96, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 10, .adv_w = 96, .box_w = 5, .box_h = 11, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 17, .adv_w = 96, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 23, .adv_w = 96, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 28, .adv_w = 96, .box_w = 3, .box_h = 10, .ofs_x = 2, .ofs_y = -1},
    {.bitmap_index = 32, .adv_w = 96, .box_w = 3, .box_h = 10, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 36, .adv_w = 96, .box_w = 5, .box_h = 6, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 40, .adv_w = 96, .box_w = 5, .box_h = 5, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 44, .adv_w = 96, .box_w = 3, .box_h = 3, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 46, .adv_w = 96, .box_w = 3, .box_h = 1, .ofs_x = 1, .ofs_y = 3},
    {.bitmap_index = 47, .adv_w = 96, .box_w = 2, .box_h = 2, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 48, .adv_w = 96, .box_w = 4, .box_h = 10, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 53, .adv_w = 96, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 58, .adv_w = 96, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 63, .adv_w = 96, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 67, .adv_w = 96, .box_w = 5, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 72, .adv_w = 96, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 76, .adv_w = 96, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 80, .adv_w = 96, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 85, .adv_w = 96, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 90, .adv_w = 96, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 95, .adv_w = 96, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 100, .adv_w = 96, .box_w = 2, .box_h = 6, .ofs_x = 2, .ofs_y = 0},
    {.bitmap_index = 102, .adv_w = 96, .box_w = 3, .box_h = 8, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 105, .adv_w = 96, .box_w = 5, .box_h = 5, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 109, .adv_w = 96, .box_w = 4, .box_h = 4, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 111, .adv_w = 96, .box_w = 5, .box_h = 5, .ofs_x = 1, .ofs_y = 1},
    {.bitmap_index = 115, .adv_w = 96, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 119, .adv_w = 96, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 126, .adv_w = 96, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 132, .adv_w = 96, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 137, .adv_w = 96, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 142, .adv_w = 96, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 146, .adv_w = 96, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 150, .adv_w = 96, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 154, .adv_w = 96, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 159, .adv_w = 96, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 163, .adv_w = 96, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 167, .adv_w = 96, .box_w = 5, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 172, .adv_w = 96, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 177, .adv_w = 96, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 181, .adv_w = 96, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 186, .adv_w = 96, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 191, .adv_w = 96, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 195, .adv_w = 96, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 200, .adv_w = 96, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 207, .adv_w = 96, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 212, .adv_w = 96, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 217, .adv_w = 96, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 222, .adv_w = 96, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 226, .adv_w = 96, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 232, .adv_w = 96, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 238, .adv_w = 96, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 244, .adv_w = 96, .box_w = 5, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 249, .adv_w = 96, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 253, .adv_w = 96, .box_w = 3, .box_h = 10, .ofs_x = 2, .ofs_y = -1},
    {.bitmap_index = 257, .adv_w = 96, .box_w = 4, .box_h = 10, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 262, .adv_w = 96, .box_w = 3, .box_h = 10, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 266, .adv_w = 96, .box_w = 4, .box_h = 4, .ofs_x = 1, .ofs_y = 4},
    {.bitmap_index = 268, .adv_w = 96, .box_w = 5, .box_h = 1, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 269, .adv_w = 96, .box_w = 5, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 273, .adv_w = 96, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 277, .adv_w = 96, .box_w = 5, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 281, .adv_w = 96, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 285, .adv_w = 96, .box_w = 4, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 288, .adv_w = 96, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 293, .adv_w = 96, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 297, .adv_w = 96, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 301, .adv_w = 96, .box_w = 5, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 307, .adv_w = 96, .box_w = 4, .box_h = 11, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 313, .adv_w = 96, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 318, .adv_w = 96, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 324, .adv_w = 96, .box_w = 5, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 328, .adv_w = 96, .box_w = 4, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 331, .adv_w = 96, .box_w = 4, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 334, .adv_w = 96, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 338, .adv_w = 96, .box_w = 4, .box_h = 8, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 342, .adv_w = 96, .box_w = 4, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 345, .adv_w = 96, .box_w = 5, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 349, .adv_w = 96, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 354, .adv_w = 96, .box_w = 4, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 357, .adv_w = 96, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 362, .adv_w = 96, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 367, .adv_w = 96, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 372, .adv_w = 96, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 378, .adv_w = 96, .box_w = 4, .box_h = 6, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 381, .adv_w = 96, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 388, .adv_w = 96, .box_w = 1, .box_h = 10, .ofs_x = 2, .ofs_y = -1},
    {.bitmap_index = 390, .adv_w = 96, .box_w = 4, .box_h = 10, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 395, .adv_w = 96, .box_w = 5, .box_h = 9, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 401, .adv_w = 96, .box_w = 6, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 405, .adv_w = 96, .box_w = 3, .box_h = 3, .ofs_x = 1, .ofs_y = 5},
    {.bitmap_index = 407, .adv_w = 96, .box_w = 2, .box_h = 1, .ofs_x = 2, .ofs_y = 7},
    {.bitmap_index = 408, .adv_w = 96, .box_w = 6, .box_h = 5, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 412, .adv_w = 96, .box_w = 6, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 420, .adv_w = 96, .box_w = 4, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 425, .adv_w = 96, .box_w = 4, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 430, .adv_w = 96, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 435, .adv_w = 96, .box_w = 5, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 441, .adv_w = 96, .box_w = 4, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 446, .adv_w = 96, .box_w = 4, .box_h = 9, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 451, .adv_w = 96, .box_w = 6, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 457, .adv_w = 96, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 463, .adv_w = 96, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 468, .adv_w = 96, .box_w = 6, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 474, .adv_w = 96, .box_w = 5, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 479, .adv_w = 96, .box_w = 8, .box_h = 7, .ofs_x = -1, .ofs_y = 0},
    {.bitmap_index = 486, .adv_w = 96, .box_w = 5, .box_h = 11, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 493, .adv_w = 96, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 498, .adv_w = 96, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 503, .adv_w = 96, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 508, .adv_w = 96, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 513, .adv_w = 96, .box_w = 6, .box_h = 13, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 523, .adv_w = 96, .box_w = 6, .box_h = 6, .ofs_x = 0, .ofs_y = 1},
    {.bitmap_index = 528, .adv_w = 96, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 535, .adv_w = 96, .box_w = 7, .box_h = 7, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 542, .adv_w = 96, .box_w = 7, .box_h = 7, .ofs_x = -1, .ofs_y = 0},
    {.bitmap_index = 549, .adv_w = 96, .box_w = 4, .box_h = 7, .ofs_x = 1, .ofs_y = 0}};

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
const lv_font_t jetbrains_mono_bold_10 = {
#else
lv_font_t jetbrains_mono_bold_10 = {
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

#endif /*#if JETBRAINS_MONO_BOLD_10*/
