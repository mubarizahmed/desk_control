/*******************************************************************************
 * Size: 50 px
 * Bpp: 1
 * Opts: --bpp 1 --size 50 --no-compress --font NotoColorEmoji-Regular.ttf --symbols ☀️⛅ 🌧 ☔ ☀ ☁ ☂ ☃ ☄ ⛄⛆ ⛇ ⛈🌀🌣 🌢 🌡🌅🌄🌂🌥🌦🌨🌩🌪🌤🌫🌬 --format lvgl -o noto_color_emoji_50.c
 ******************************************************************************/

#include "lvgl.h"

#ifndef NOTO_COLOR_EMOJI_50
#define NOTO_COLOR_EMOJI_50 1
#endif

#if NOTO_COLOR_EMOJI_50

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+2600 "☀" */
    0x0,

    /* U+2601 "☁" */
    0x0,

    /* U+2602 "☂" */
    0x0,

    /* U+2603 "☃" */
    0x0,

    /* U+2604 "☄" */
    0x0,

    /* U+2614 "☔" */
    0x0,

    /* U+26C4 "⛄" */
    0x0,

    /* U+26C5 "⛅" */
    0x0,

    /* U+26C8 "⛈" */
    0x0,

    /* U+1F300 "🌀" */
    0x0,

    /* U+1F302 "🌂" */
    0x0,

    /* U+1F304 "🌄" */
    0x0,

    /* U+1F305 "🌅" */
    0x0,

    /* U+1F321 "🌡" */
    0x0,

    /* U+1F324 "🌤" */
    0x0,

    /* U+1F325 "🌥" */
    0x0,

    /* U+1F326 "🌦" */
    0x0,

    /* U+1F327 "🌧" */
    0x0,

    /* U+1F328 "🌨" */
    0x0,

    /* U+1F329 "🌩" */
    0x0,

    /* U+1F32A "🌪" */
    0x0,

    /* U+1F32B "🌫" */
    0x0,

    /* U+1F32C "🌬" */
    0x0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 996, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 996, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 2, .adv_w = 996, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 3, .adv_w = 996, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 4, .adv_w = 996, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 5, .adv_w = 996, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 6, .adv_w = 996, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 7, .adv_w = 996, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 8, .adv_w = 996, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 9, .adv_w = 996, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 10, .adv_w = 996, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 11, .adv_w = 996, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 12, .adv_w = 996, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 13, .adv_w = 996, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 14, .adv_w = 996, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 15, .adv_w = 996, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 16, .adv_w = 996, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 17, .adv_w = 996, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 18, .adv_w = 996, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 19, .adv_w = 996, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 20, .adv_w = 996, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 21, .adv_w = 996, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 22, .adv_w = 996, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 23, .adv_w = 996, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint16_t unicode_list_0[] = {
    0x0, 0x25e0, 0x25e1, 0x25e2, 0x25e3, 0x25e4, 0x25f4, 0x26a4,
    0x26a5, 0x26a8
};

static const uint16_t unicode_list_1[] = {
    0x0, 0x2, 0x4, 0x5, 0x21
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 9897, .glyph_id_start = 1,
        .unicode_list = unicode_list_0, .glyph_id_ofs_list = NULL, .list_length = 10, .type = LV_FONT_FMT_TXT_CMAP_SPARSE_TINY
    },
    {
        .range_start = 127744, .range_length = 34, .glyph_id_start = 11,
        .unicode_list = unicode_list_1, .glyph_id_ofs_list = NULL, .list_length = 5, .type = LV_FONT_FMT_TXT_CMAP_SPARSE_TINY
    },
    {
        .range_start = 127780, .range_length = 9, .glyph_id_start = 16,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
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
    .cmap_num = 3,
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
const lv_font_t noto_color_emoji_50 = {
#else
lv_font_t noto_color_emoji_50 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 1,          /*The maximum line height required by the font*/
    .base_line = 0,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -4,
    .underline_thickness = 2,
#endif
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
#if LV_VERSION_CHECK(8, 2, 0) || LVGL_VERSION_MAJOR >= 9
    .fallback = NULL,
#endif
    .user_data = NULL,
};



#endif /*#if NOTO_COLOR_EMOJI_50*/

