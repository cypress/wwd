/*
 * Copyright (c) 2018 Cypress Semiconductor
 * SPDX-License-Identifier: Apache-2.0
 */

/** @file
 *
 */
#include "platform_toolchain.h"
#include "wwd_management.h"
#include "wwd_wifi.h"
#include "wwd_assert.h"
#include "wwd_wlioctl.h"
#include "wwd_debug.h"
#include "wwd_bus_protocol.h"
#include "wwd_wifi_chip_common.h"
#include "internal/bus_protocols/wwd_bus_protocol_interface.h"


WEAK wwd_result_t wwd_wlan_bus_complete_ds_wake( wiced_bool_t wake_from_firmware, uint32_t wake_event_indication_addr, uint32_t wake_indication_addr, uint32_t sdio_control_addr )
{
    UNUSED_PARAMETER( wake_from_firmware );

    UNUSED_PARAMETER( wake_event_indication_addr );
    UNUSED_PARAMETER( wake_indication_addr );
    UNUSED_PARAMETER( sdio_control_addr );

    return WWD_UNSUPPORTED;
}

wwd_result_t wwd_wlan_register_read( uint32_t addr, uint32_t size, uint32_t *value )
{
    wwd_result_t result;

    *value = 0;
    result = wwd_bus_read_backplane_value( addr, (uint8_t)size, (uint8_t*)value );

    if ( WWD_SUCCESS != result )
    {
        wiced_assert( "Unable to read register\n", WWD_SUCCESS == result );
        WPRINT_WWD_ERROR(("Error %d: Unable to read register\n", result));
        return WWD_TIMEOUT;
    }

    return WWD_SUCCESS;
}

wwd_result_t wwd_wlan_register_write( uint32_t addr, uint32_t size, uint32_t value )
{
    wwd_result_t result = wwd_bus_write_backplane_value( addr, (uint8_t)size, value );

    if ( WWD_SUCCESS != result )
    {
        wiced_assert( "Unable to write register\n", WWD_SUCCESS == result );
        WPRINT_WWD_ERROR(("Error %d: Unable to write register\n", result));
        return WWD_TIMEOUT;
    }

    return WWD_SUCCESS;
}

wwd_result_t wwd_wlan_shared_memory_read( uint32_t addr, uint8_t size, uint32_t *value )
{
    wwd_result_t result;

    *value = 0;
    result = wwd_bus_read_backplane_value( addr, (uint8_t)size, (uint8_t*)value );

    if ( WWD_SUCCESS != result )
    {
        wiced_assert( "Unable to read shm\n", WWD_SUCCESS == result );
        WPRINT_WWD_ERROR(("Error %d: Unable to read shm\n", result));
        return WWD_TIMEOUT;
    }

    return WWD_SUCCESS;
}

