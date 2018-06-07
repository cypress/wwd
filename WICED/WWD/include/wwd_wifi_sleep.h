/*
 * $ Copyright Cypress Semiconductor $
 */

/** @file
 *  Prototypes of functions for controlling the Wi-Fi system sleep and wake functionality
 *
 */

#ifndef INCLUDED_WWD_WIFI_SLEEP_H
#define INCLUDED_WWD_WIFI_SLEEP_H

#ifdef __cplusplus
extern "C"
{
#endif

/**
 ******************************************************************************
* Deep Sleep 1 (DS1) types
*/
typedef enum
{
    STATE_DS_DISABLED   = 0,
    STATE_DS_ENABLING   = 1,
    STATE_DS_ENABLED    = 2,
    STATE_DS_DISABLING  = 3
} wwd_ds_state_t;

/* user_parameter is specified when registering for callback */
typedef void (*wwd_ds1_state_change_callback_t)( void* user_parameter );

/**
 ******************************************************************************
* Deep Sleep 1 (DS1) functions
*/

/* Begin process of entering deep sleep */
extern wwd_result_t wwd_wifi_enter_ds1( wwd_interface_t interface, uint32_t ulp_wait_milliseconds );

/* Determine if FW caused wake; process it if so */
extern wwd_result_t wwd_wifi_ds1_wake_handle( wiced_bool_t force );

/* Attempt to disable DS1 and clear wowl */
extern wwd_result_t wwd_wifi_ds1_disable( wwd_interface_t interface );

/* Called by Other modules in WWD to report a DS entry event */
extern void* wwd_wifi_event_ulp_handler( const wwd_event_header_t* event_header, const uint8_t* event_data, /*@returned@*/ void* handler_user_data );

/* Register a callback for deep sleep state changes; current state can then be queried */
extern wwd_result_t wwd_wifi_ds1_set_state_change_callback( wwd_ds1_state_change_callback_t callback, void *user_parameter );

/* Get current DS1 state */
extern wwd_ds_state_t wwd_wifi_ds1_get_state( void );

/* Return status as a string */
void wwd_wifi_ds1_get_status_string( uint8_t *output, uint16_t max_output_length );


/**
 ******************************************************************************
* Wake On Wireless LAN (WOWL) functions
*/

/* Enable Wake on Wireless and add 1 or more of: patterns, host_ip, or keep alive to trigger Wake */
extern wwd_result_t wwd_wifi_wowl_enable( wwd_interface_t interface, uint32_t wowl_caps, uint32_t wowl_os,
     wl_mkeep_alive_pkt_t *wowl_keepalive_data, uint8_t *pattern_data, uint32_t pattern_data_size, uint32_t *arp_host_ip_v4_address );

/* Disable WOWL and clear any settings */
extern wwd_result_t wwd_wifi_wowl_disable( wwd_interface_t interface );

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* INCLUDED_WWD_WIFI_SLEEP_H */
