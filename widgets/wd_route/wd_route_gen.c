/**
 * @file wd_route_gen.c
 *
 */

/*********************
 *      INCLUDES
 *********************/
#include "wd_route_private_gen.h"
#include "lvgl/src/core/lv_obj_class_private.h"
#include "ui.h"

/*********************
 *      DEFINES
 *********************/



/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  GLOBAL PROTOTYPES
 **********************/

void wd_route_constructor_hook(lv_obj_t * obj);
void wd_route_destructor_hook(lv_obj_t * obj);
void wd_route_event_hook(lv_event_t * e);

/**********************
 *  STATIC PROTOTYPES
 **********************/

static void wd_route_constructor(const lv_obj_class_t * class_p, lv_obj_t * obj);
static void wd_route_destructor(const lv_obj_class_t * class_p, lv_obj_t * obj);
static void wd_route_event(const lv_obj_class_t * class_p, lv_event_t * e);



/**********************
 *  STATIC VARIABLES
 **********************/

const lv_obj_class_t wd_route_class = {
    .base_class = &lv_obj_class,
    .constructor_cb = wd_route_constructor,
    .destructor_cb = wd_route_destructor,
    .event_cb = wd_route_event,
    .instance_size = sizeof(wd_route_t),
    .editable = 1,
    .name = "wd_route"
};

/**********************
 *   GLOBAL FUNCTIONS
 **********************/


lv_obj_t * wd_route_create(lv_obj_t * parent)
{
    LV_LOG_INFO("begin");
    lv_obj_t * obj = lv_obj_class_create_obj(&wd_route_class, parent);
    lv_obj_class_init_obj(obj);
    return obj;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/


static void wd_route_constructor(const lv_obj_class_t * class_p, lv_obj_t * obj)
{
    LV_UNUSED(class_p);
    LV_TRACE_OBJ_CREATE("begin");

    wd_route_t * widget = (wd_route_t *)obj;
    static lv_style_t style_route;
static lv_style_t cont;
static lv_style_t stop;
static lv_style_t style_slider;
static lv_style_t style_indicator;
static lv_style_t clear;
    static bool style_inited = false;

    if (!style_inited) {
        lv_style_init(&style_route);
        lv_style_set_width(&style_route, 400);
        lv_style_set_height(&style_route, 300);

        lv_style_init(&cont);
        lv_style_set_width(&cont, lv_pct(100));
        lv_style_set_height(&cont, lv_pct(100));
        lv_style_set_bg_opa(&cont, 0);
        lv_style_set_border_width(&cont, 0);
        lv_style_set_pad_all(&cont, 10);
        lv_style_set_layout(&cont, LV_LAYOUT_FLEX);
        lv_style_set_flex_flow(&cont, LV_FLEX_FLOW_COLUMN);
        lv_style_set_flex_main_place(&cont, LV_FLEX_ALIGN_SPACE_BETWEEN);
        lv_style_set_pad_row(&cont, 0);

        lv_style_init(&stop);
        lv_style_set_width(&stop, 30);
        lv_style_set_height(&stop, 30);
        lv_style_set_radius(&stop, 15);

        lv_style_init(&style_slider);
        lv_style_set_bg_color(&style_slider, lv_color_hex(0x4b4b4b));
        lv_style_set_bg_opa(&style_slider, 255);

        lv_style_init(&style_indicator);
        lv_style_set_bg_color(&style_indicator, lv_color_hex(0x286af9));

        lv_style_init(&clear);
        lv_style_set_bg_opa(&clear, 0);

        style_inited = true;
    }
    lv_obj_add_style(obj, &style_route, 0);

    lv_obj_t * lv_obj_0 = lv_obj_create(obj);
    lv_obj_set_width(lv_obj_0, LV_SIZE_CONTENT);
    lv_obj_set_height(lv_obj_0, lv_pct(100));
    lv_obj_set_style_bg_opa(lv_obj_0, 0, 0);
    lv_obj_set_style_radius(lv_obj_0, 0, 0);
    lv_obj_set_style_border_width(lv_obj_0, 0, 0);
    lv_obj_set_style_pad_all(lv_obj_0, 20, 0);
    lv_obj_set_style_pad_bottom(lv_obj_0, 35, 0);
    lv_obj_set_style_pad_top(lv_obj_0, 35, 0);
    widget->lv_obj_0 = lv_obj_0;

    lv_obj_t * lv_slider_0 = lv_slider_create(lv_obj_0);
    lv_slider_set_min_value(lv_slider_0, 100);
    lv_slider_set_max_value(lv_slider_0, 0);
    lv_slider_set_value(lv_slider_0, 0, false);lv_obj_set_width(lv_slider_0, 10);
    lv_obj_set_height(lv_slider_0, lv_pct(100));
    widget->lv_slider_0 = lv_slider_0;
    lv_obj_add_style(lv_slider_0, &style_slider, 0);
    lv_obj_add_style(lv_slider_0, &style_indicator, LV_PART_INDICATOR);
    lv_obj_add_style(lv_slider_0, &clear, LV_PART_KNOB);



    lv_obj_t * stop_cont = lv_obj_create(obj);
    lv_obj_set_flag(stop_cont, LV_OBJ_FLAG_CLICKABLE, false);
    lv_obj_set_name(stop_cont, "stop_cont");
    widget->stop_cont = stop_cont;
    lv_obj_add_style(stop_cont, &cont, 0);



    wd_route_constructor_hook(obj);

    LV_TRACE_OBJ_CREATE("finished");
}

static void wd_route_destructor(const lv_obj_class_t * class_p, lv_obj_t * obj)
{
    LV_UNUSED(class_p);

    wd_route_destructor_hook(obj);
}

static void wd_route_event(const lv_obj_class_t * class_p, lv_event_t * e)
{
    LV_UNUSED(class_p);

    lv_result_t res;

    /* Call the ancestor's event handler */
    res = lv_obj_event_base(&wd_route_class, e);
    if(res != LV_RESULT_OK) return;

    wd_route_event_hook(e);
}

