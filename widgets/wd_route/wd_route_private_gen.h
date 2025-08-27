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
    int32_t value;
    lv_subject_t * bind_subject;
    void * observer;
    lv_obj_t * lv_obj_0;
    lv_obj_t * lv_slider_0;
    lv_obj_t * stop_cont;
} wd_route_t;

extern const lv_obj_class_t wd_route_class;

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