/*
 * $ Copyright Cypress Semiconductor $
 */

/** @file
 *
 */

#include <string.h>
#include <stdlib.h>

#include "wwd_wifi.h"
#include "wwd_debug.h"
#include "wwd_constants.h"
#include "internal/wwd_bcmendian.h"
#include "internal/bus_protocols/wwd_bus_protocol_interface.h"

#include "platform_map.h"
#include "platform_mcu_peripheral.h"
#include "wiced_low_power.h"
#include "internal/wwd_internal.h"

/******************************************************
 *                      Macros
 ******************************************************/

/******************************************************
 *                    Constants
 ******************************************************/

#define WLAN_SHARED_ADDR (PLATFORM_ATCM_RAM_BASE(0) + PLATFORM_WLAN_RAM_SIZE - 4)

/******************************************************
 *                   Enumerations
 ******************************************************/

/******************************************************
 *                 Type Definitions
 ******************************************************/

/******************************************************
 *                    Structures
 ******************************************************/

/******************************************************
 *               Function Declarations
 ******************************************************/

/******************************************************
 *               Variables Definitions
 ******************************************************/

/******************************************************
 *               Function Definitions
 ******************************************************/

wwd_result_t wwd_wifi_read_wlan_log( char* buffer, uint32_t buffer_size )
{
    wwd_result_t result;

    wwd_ensure_wlan_bus_is_up();

    result = wwd_wifi_read_wlan_log_unsafe( WLAN_SHARED_ADDR, buffer, buffer_size );

    wwd_thread_notify();

    return result;
}

wwd_result_t wwd_wifi_set_custom_country_code( const wiced_country_info_t* country_code )
{
    UNUSED_PARAMETER(country_code);
    return WWD_UNSUPPORTED;
}
