/**
 * @file main_gen.c
 * @description Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/
#include "main_gen.h"
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

lv_obj_t * main_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");


    static bool style_inited = false;

    if (!style_inited) {

        style_inited = true;
    }

    lv_obj_t * lv_obj_0 = lv_obj_create(NULL);

    lv_obj_t * wd_route_0 = wd_route_create(lv_obj_0);
    wd_route_bind_subject(wd_route_0, &progress);
    lv_obj_t * wd_route_stops_0 = wd_route_get_stops(wd_route_0, 0);

        lv_obj_t * stop_0 = stop_create(wd_route_stops_0, "A");


        lv_obj_t * stop_1 = stop_create(wd_route_stops_0, "A");


        lv_obj_t * stop_2 = stop_create(wd_route_stops_0, "A");


        lv_obj_t * stop_3 = stop_create(wd_route_stops_0, "A");


        lv_obj_t * stop_4 = stop_create(wd_route_stops_0, "A");




    LV_TRACE_OBJ_CREATE("finished");

    lv_obj_set_name(lv_obj_0, "main");

    return lv_obj_0;
}



/**********************
 *   STATIC FUNCTIONS
 **********************/

