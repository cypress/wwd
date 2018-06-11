/*
 * Copyright (c) 2018 Cypress Semiconductor
 * SPDX-License-Identifier: Apache-2.0
 */

#include <string.h>
#include "wwd_debug.h"
#include "internal/bus_protocols/wwd_bus_protocol_interface.h"

/******************************************************
 *             Constants
 ******************************************************/

/******************************************************
 *             Structures
 ******************************************************/

/******************************************************
 *             Variables
 ******************************************************/
#ifdef WWD_ENABLE_STATS
wwd_stats_t wwd_stats;
#endif /* WWD_ENABLE_STATS */

/******************************************************
 *             Function definitions
 ******************************************************/
void wwd_init_stats ( void )
{
#ifdef WWD_ENABLE_STATS
    memset( &wwd_stats, 0, sizeof(wwd_stats) );
#endif /* WWD_ENABLE_STATS */
}

wwd_result_t wwd_print_stats ( wiced_bool_t reset_after_print )
{
#ifdef WWD_ENABLE_STATS
    WPRINT_MACRO(( "WWD Stats.. \n"
                   "tx_total:%ld, rx_total:%ld, tx_no_mem:%ld, rx_no_mem:%ld\n"
                   "tx_fail:%ld, no_credit:%ld, flow_control:%ld\n",
                   wwd_stats.tx_total, wwd_stats.rx_total, wwd_stats.tx_no_mem, wwd_stats.rx_no_mem,
                   wwd_stats.tx_fail, wwd_stats.no_credit, wwd_stats.flow_control ));

    if ( reset_after_print == WICED_TRUE )
    {
        memset( &wwd_stats, 0, sizeof(wwd_stats) );
    }
    return wwd_bus_print_stats( reset_after_print );
#else /* WWD_ENABLE_STATS */
    UNUSED_VARIABLE(reset_after_print);
    return WWD_DOES_NOT_EXIST;
#endif /* WWD_ENABLE_STATS */
}
