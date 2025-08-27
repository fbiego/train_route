/**
 * @file train_route_gen.c
 */

/*********************
 *      INCLUDES
 *********************/
#include "train_route_gen.h"

#if LV_USE_XML
#include "widgets/wd_route/wd_route_private_gen.h"
#endif /* LV_USE_XML */

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

/*----------------
 * Translations
 *----------------*/

/**********************
 *  GLOBAL VARIABLES
 **********************/

/*--------------------
 *  Permanent screens
 *-------------------*/

/*----------------
 * Global styles
 *----------------*/

/*----------------
 * Fonts
 *----------------*/
lv_font_t * nn_regular_30;
extern lv_font_t nn_regular_30_data;
lv_font_t * nn_regular_50;
extern lv_font_t nn_regular_50_data;
lv_font_t * nn_bold_30;
extern lv_font_t nn_bold_30_data;

/*----------------
 * Images
 *----------------*/

/*----------------
 * Subjects
 *----------------*/
lv_subject_t progress;

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void train_route_init_gen(const char * asset_path)
{
    char buf[256];

    /*----------------
     * Global styles
     *----------------*/

    /*----------------
     * Fonts
     *----------------*/
    /* get font 'nn_regular_30' from a C array */
    nn_regular_30 = &nn_regular_30_data;
    /* get font 'nn_regular_50' from a C array */
    nn_regular_50 = &nn_regular_50_data;
    /* get font 'nn_bold_30' from a C array */
    nn_bold_30 = &nn_bold_30_data;

    /*----------------
     * Images
     *----------------*/


    /*----------------
     * Subjects
     *----------------*/
    lv_subject_init_int(&progress, 0);

    /*----------------
     * Translations
     *----------------*/


#if LV_USE_XML
    /*Register widgets*/
    wd_route_register();

    /* Register fonts */
    lv_xml_register_font(NULL, "nn_regular_30", nn_regular_30);
    lv_xml_register_font(NULL, "nn_regular_50", nn_regular_50);
    lv_xml_register_font(NULL, "nn_bold_30", nn_bold_30);

    /* Register subjects */
    lv_xml_register_subject(NULL, "progress", &progress);

    /* Register callbacks */
#endif

    /* Register all the global assets so that they won't be created again when globals.xml is parsed.
     * While running in the editor skip this step to update the preview when the XML changes */
#if LV_USE_XML && !defined(LV_EDITOR_PREVIEW)

    /* Register images */
#endif

#if LV_USE_XML == 0
    /*--------------------
     *  Permanent screens
     *-------------------*/

    /* If XML is enabled it's assumed that the permanent screens are created
     *manaully from XML using lv_xml_create() */

#endif
}

/* callbacks */

/**********************
 *   STATIC FUNCTIONS
 **********************/