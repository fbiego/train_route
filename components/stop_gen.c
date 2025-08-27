/**
 * @file stop_gen.c
 * @description Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/
#include "stop_gen.h"
#include "ui.h"

/*********************
 *      DEFINES
 *********************/



/**********************
 *      TYPEDEFS
 **********************/

/***********************
 *  STATIC VARIABLES
 **********************/

/***********************
 *  STATIC PROTOTYPES
 **********************/



/**********************
 *   GLOBAL FUNCTIONS
 **********************/

lv_obj_t * stop_create(lv_obj_t * parent, const char * station)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_cont;
    static lv_style_t style_stop;
    static lv_style_t style_cont_checked;

    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&style_cont);
        lv_style_set_width(&style_cont, lv_pct(100));
        lv_style_set_height(&style_cont, 50);
        lv_style_set_radius(&style_cont, 0);
        lv_style_set_bg_opa(&style_cont, 0);
        lv_style_set_border_width(&style_cont, 0);
        lv_style_set_pad_all(&style_cont, 0);
        lv_style_set_layout(&style_cont, LV_LAYOUT_FLEX);
        lv_style_set_flex_track_place(&style_cont, LV_FLEX_ALIGN_CENTER);
        lv_style_set_flex_cross_place(&style_cont, LV_FLEX_ALIGN_CENTER);
        lv_style_set_pad_column(&style_cont, 10);
        lv_style_set_text_font(&style_cont, nn_bold_30);
        lv_style_set_text_color(&style_cont, lv_color_hex(0x5c5a5a));

        lv_style_init(&style_stop);
        lv_style_set_width(&style_stop, 30);
        lv_style_set_height(&style_stop, 30);
        lv_style_set_radius(&style_stop, 15);
        lv_style_set_border_width(&style_stop, 0);
        lv_style_set_bg_color(&style_stop, lv_color_hex(0x5c5a5a));
        lv_style_set_bg_opa(&style_stop, 255);

        lv_style_init(&style_cont_checked);
        lv_style_set_text_color(&style_cont_checked, lv_color_hex(0x286af9));
        lv_style_set_bg_color(&style_cont_checked, lv_color_hex(0x286af9));

        style_inited = true;
    }

    lv_obj_t * lv_obj_0 = lv_obj_create(parent);
    lv_obj_set_flag(lv_obj_0, LV_OBJ_FLAG_CHECKABLE, true);
    lv_obj_set_flag(lv_obj_0, LV_OBJ_FLAG_CLICKABLE, false);
    lv_obj_set_flag(lv_obj_0, LV_OBJ_FLAG_STATE_TRICKLE, true);
    lv_obj_add_style(lv_obj_0, &style_cont, 0);

    lv_obj_t * lv_obj_1 = lv_obj_create(lv_obj_0);
    lv_obj_set_flag(lv_obj_1, LV_OBJ_FLAG_CLICKABLE, false);
    lv_obj_set_flag(lv_obj_1, LV_OBJ_FLAG_CHECKABLE, true);
    lv_obj_add_style(lv_obj_1, &style_stop, 0);
    lv_obj_add_style(lv_obj_1, &style_cont_checked, LV_STATE_CHECKED);


    lv_obj_t * lv_label_0 = lv_label_create(lv_obj_0);
    lv_label_set_text(lv_label_0, station);
    lv_obj_set_flag(lv_label_0, LV_OBJ_FLAG_CHECKABLE, true);
    lv_obj_add_style(lv_label_0, &style_cont_checked, LV_STATE_CHECKED);



    LV_TRACE_OBJ_CREATE("finished");

    lv_obj_set_name(lv_obj_0, "stop_#");

    return lv_obj_0;
}



/**********************
 *   STATIC FUNCTIONS
 **********************/

