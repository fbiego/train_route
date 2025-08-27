/**
 * @file wd_route.c
 *
 */

/*********************
 *      INCLUDES
 *********************/
#include "wd_route_private_gen.h"
#include "ui.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
static void route_highlight(wd_route_t * widget);
static void slider_event_cb(lv_event_t * e);
static void route_added_cb(lv_event_t *e);
static void value_observer_cb(lv_observer_t * observer, lv_subject_t * subject);

/**********************
 *  STATIC VARIABLES
 **********************/

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void wd_route_constructor_hook(lv_obj_t * obj)
{

    wd_route_t * widget = (wd_route_t *)obj;

    lv_obj_add_event_cb(widget->lv_slider_0, slider_event_cb, LV_EVENT_VALUE_CHANGED, widget);

    lv_obj_add_event_cb(widget->stop_cont, route_added_cb, LV_EVENT_CHILD_CREATED, widget);


}

void wd_route_destructor_hook(lv_obj_t * obj)
{
    wd_route_t * widget = (wd_route_t *)obj;
    
    if (widget->observer)
    {
        lv_observer_remove(widget->observer);
        widget->observer = NULL;
    }

}

void wd_route_event_hook(lv_event_t * e)
{

}


void wd_route_bind_subject(lv_obj_t * wd_route, lv_subject_t * bind_subject)
{
    wd_route_t * widget = (wd_route_t *)wd_route;
    widget->bind_subject = bind_subject;
    lv_slider_bind_value(widget->lv_slider_0, widget->bind_subject);
    widget->observer = lv_subject_add_observer(widget->bind_subject, value_observer_cb, widget);

}

lv_obj_t * wd_route_get_stops(lv_obj_t * wd_route, int32_t index)
{
    wd_route_t * widget = (wd_route_t *)wd_route;
    return widget->stop_cont;
}

void wd_route_set_value(lv_obj_t * wd_route, int32_t value)
{
    // wd_route_t * widget = (wd_route_t *)wd_route;
    // widget->value = value;
    // lv_slider_set_value(widget->lv_slider_0, widget->value, false);
    // route_highlight(widget);

}

/**********************
 *   STATIC FUNCTIONS
 **********************/

static void route_highlight(wd_route_t * widget)
{

    int32_t progress = widget->value;
    int32_t stops = lv_obj_get_child_count(widget->stop_cont);

    if (stops > 1) {

        int32_t steps = 100 / (stops - 1);

        for (int32_t i = 0; i < stops; i++)
        {
            lv_obj_t *child = lv_obj_get_child(widget->stop_cont, i);
            lv_obj_set_state(child, LV_STATE_CHECKED, (progress + 2 > i * steps));
        }
    } 
    
    // if (stops == 1) {
    //     lv_obj_t *ch = lv_obj_get_child(widget->stop_cont, 0);
    //     lv_obj_add_state(ch, LV_STATE_CHECKED);
    // }
    // LV_LOG_WARN("Stops count %d", stops);

}

static void slider_event_cb(lv_event_t * e)
{
    // handled using subject
    // wd_route_t * widget = (wd_route_t *)lv_event_get_user_data(e);
    // lv_obj_t * slider = lv_event_get_target_obj(e);
    // int32_t progress = (int32_t)lv_slider_get_value(slider);
    // widget->value = progress;
    // route_highlight(widget);

}

static void route_added_cb(lv_event_t *e)
{
    wd_route_t * widget = (wd_route_t *)lv_event_get_user_data(e);
    route_highlight(widget);
}

static void value_observer_cb(lv_observer_t * observer, lv_subject_t * subject)
{
    wd_route_t * widget = (wd_route_t *)lv_observer_get_user_data(observer);
    widget->value = lv_subject_get_int(subject);
    route_highlight(widget);

}