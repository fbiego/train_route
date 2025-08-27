/**
 * @file wd_route_private_gen.h
 *
 */

#ifndef WD_ROUTE_PRIVATE_H
#define WD_ROUTE_PRIVATE_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/
#include "lvgl/src/core/lv_obj_private.h"
#include "wd_route.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

typedef struct {
    lv_obj_t obj;  /* Base widget to extend */
    void * stops;
    void * value;
    void * bind_subject;
    void * observer;
    lv_obj_t * style_route;
    lv_obj_t * lv_obj_1;
    lv_obj_t * lv_slider_1;
    lv_obj_t * style_slider;
    lv_obj_t * style_indicator;
    lv_obj_t * clear;
    lv_obj_t * stop_cont;
    lv_obj_t * cont;
} wd_route_t;

/**********************
 * GLOBAL PROTOTYPES
 **********************/

#if LV_USE_XML
    void wd_route_register(void);
#endif

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*WD_ROUTE_PRIVATE_H*/