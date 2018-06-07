/*
 * $ Copyright Cypress Semiconductor $
 */

/** @file
 *  Implementation of wwd_rtos_interface.c for all RTOS
 */
#include "wwd_constants.h"
#include "wwd_rtos_interface.h"
#include "wwd_assert.h"

/******************************************************
 *             Constants
 ******************************************************/

/******************************************************
 *             Variables
 ******************************************************/
const host_rtos_timer_ifc_t *host_rtos_timer_ifc = NULL;

/******************************************************
 *             Function definitions
 ******************************************************/

wwd_result_t host_rtos_register_timer_ifc( const host_rtos_timer_ifc_t *host_rtos_timer_ifc_new )
{
    if ( NULL != host_rtos_timer_ifc )
    {
        wiced_assert( "Function already registered\n", 0 != 0 );
        return WWD_BADARG;
    }
    host_rtos_timer_ifc = host_rtos_timer_ifc_new;
    return WWD_SUCCESS;
}

wwd_result_t host_rtos_unregister_timer_ifc( const host_rtos_timer_ifc_t *host_rtos_timer_ifc_new )
{
    if ( host_rtos_timer_ifc_new != host_rtos_timer_ifc )
    {
        wiced_assert( "Interface not registered\n", 0 != 0 );
        return WWD_BADARG;
    }
    else
    {
        host_rtos_timer_ifc = NULL;
    }
    return WWD_SUCCESS;
}
