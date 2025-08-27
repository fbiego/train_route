/**
 * @file train_route_gen.h
 */

#ifndef TRAIN_ROUTE_GEN_H
#define TRAIN_ROUTE_GEN_H

#ifndef UI_SUBJECT_STRING_LENGTH
#define UI_SUBJECT_STRING_LENGTH 256
#endif

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

/*********************
 *      DEFINES
 *********************/



/**********************
 *      TYPEDEFS
 **********************/



/**********************
 * GLOBAL VARIABLES
 **********************/

/*-------------------
 * Permanent screens
 *------------------*/

/*----------------
 * Global styles
 *----------------*/


/*----------------
 * Fonts
 *----------------*/
extern lv_font_t * nn_regular_30;
extern lv_font_t * nn_regular_50;
extern lv_font_t * nn_bold_30;

/*----------------
 * Images
 *----------------*/

/*----------------
 * Subjects
 *----------------*/
extern lv_subject_t progress;

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/*----------------
 * Event Callbacks
 *----------------*/

/**
 * Initialize the component library
 */

void train_route_init_gen(const char * asset_path);

/**********************
 *      MACROS
 **********************/

/**********************
 *   POST INCLUDES
 **********************/

/*Include all the widget and components of this library*/
#include "widgets/wd_route/wd_route_gen.h"
#include "components/stop_gen.h"
#include "screens/main_gen.h"

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*TRAIN_ROUTE_GEN_H*/