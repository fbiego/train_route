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
#include "lvgl/lvgl.h"

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
 * Set the stops
 * @param obj   pointer to a wd_route
 * @param stops  stops
 */
void wd_route_set_stops(lv_obj_t * obj, void * stops);

/**
 * Set the value
 * @param obj   pointer to a wd_route
 * @param value  value
 */
void wd_route_set_value(lv_obj_t * obj, int32_t value);

/**
 * Set the bind_subject
 * @param obj   pointer to a wd_route
 * @param bind_subject  bind_subject
 */
void wd_route_set_bind_subject(lv_obj_t * obj, void * bind_subject);

/**
 * Set the observer
 * @param obj   pointer to a wd_route
 * @param observer  observer
 */
void wd_route_set_observer(lv_obj_t * obj, lv_obj_t * observer);

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*WD_ROUTE_GEN_H*/