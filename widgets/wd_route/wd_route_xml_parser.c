/**
 * @file wd_route_xml_parser.c
 *
 */

/*********************
 *      INCLUDES
 *********************/
#include "wd_route_gen.h"
#include "lvgl/src/others/xml/parsers/lv_xml_obj_parser.h"
#include "lvgl/src/others/xml/lv_xml_widget.h"
#include "lvgl/src/others/xml/lv_xml_parser.h"

#if LV_USE_XML

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void * wd_route_xml_create(lv_xml_parser_state_t * state, const char ** attrs)
{
    LV_UNUSED(attrs);
    void * item = wd_route_create(lv_xml_state_get_parent(state));

    if(item == NULL) {
        LV_LOG_ERROR("Failed to create wd_route");
        return NULL;
    }

    return item;
}

void wd_route_xml_apply(lv_xml_parser_state_t * state, const char ** attrs)
{

    void * item = lv_xml_state_get_item(state);

    lv_xml_obj_apply(state, attrs);

    for(int i = 0; attrs[i]; i += 2) {
        const char * name = attrs[i];
        const char * value = attrs[i + 1];


        if(lv_streq("value", name)) {
            wd_route_set_value(item, lv_xml_atoi(value));
        }

        if(lv_streq("bind_subject", name)) {
            lv_subject_t * subject = lv_xml_get_subject(&state->scope, value);
            if(subject) {
                wd_route_bind_subject(item, subject);
            }
            else {
                LV_LOG_WARN("Subject \"%s\" doesn't exist in wd_route bind_subject", value);
            }
        }
    }
}

void * wd_route_stops_xml_create(lv_xml_parser_state_t * state, const char ** attrs)
{
    LV_UNUSED(attrs);
    void * item = lv_xml_state_get_parent(state);

    if(item == NULL) {
        LV_LOG_ERROR("Failed to create wd_route-stops");
        return NULL;
    }

    return wd_route_get_stops(item, 0);
}

void wd_route_stops_xml_apply(lv_xml_parser_state_t * state, const char ** attrs)
{

    void * parent_item = lv_xml_state_get_parent(state);
    void * item = lv_xml_state_get_item(state);

    lv_xml_obj_apply(state, attrs);

    for(int i = 0; attrs[i]; i += 2) {
        const char * name = attrs[i];
        const char * value = attrs[i + 1];
        
    }
}

void wd_route_register(void)
{
    lv_xml_widget_register("wd_route", wd_route_xml_create, wd_route_xml_apply);
    lv_xml_widget_register("wd_route-stops", wd_route_stops_xml_create, wd_route_stops_xml_apply);
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

#endif /* LV_USE_XML */