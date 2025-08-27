/**
 * @file wd_route_gen.h
 *
 */

#ifndef WD_ROUTE_GEN_H
#define WD_ROUTE_GEN_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/
#ifdef LV_LVGL_H_INCLUDE_SIMPLE
    #include "lvgl.h"
#else
    #include "lvgl/lvgl.h"
#endif

#include "train_route_gen.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/




/**********************
 * GLOBAL PROTOTYPES
 **********************/

/**
 * Create a wd_route object
 * @param parent pointer to an object, it will be the parent of the new wd_route
 * @return pointer to the created wd_route
 */
lv_obj_t * wd_route_create(lv_obj_t * parent);


/**
 * wd_route value
 * @param obj   pointer to a wd_route
 * @param value  value
 */
void wd_route_set_value(lv_obj_t * wd_route, int32_t value);

/**
 * wd_route bind_subject
 * @param obj   pointer to a wd_route
 * @param bind_subject  bind_subject
 */
void wd_route_bind_subject(lv_obj_t * wd_route, lv_subject_t * bind_subject);

/**
 * wd_route observer
 * @param obj   pointer to a wd_route
 * @param observer  observer
 */
void wd_route_set_observer(lv_obj_t * wd_route, void * observer);

/**
 * wd_route stops
 * @param obj   pointer to a wd_route
 * @param index  index
 */
lv_obj_t * wd_route_get_stops(lv_obj_t * wd_route, int32_t index);

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*WD_ROUTE_GEN_H*/