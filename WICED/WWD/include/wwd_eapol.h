/*
 * Copyright (c) 2018 Cypress Semiconductor
 * SPDX-License-Identifier: Apache-2.0
 */
#pragma once

#include "wwd_buffer.h"
#include "wwd_constants.h"

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************
 *                      Macros
 ******************************************************/

/******************************************************
 *                    Constants
 ******************************************************/

/******************************************************
 *                   Enumerations
 ******************************************************/

/******************************************************
 *                 Type Definitions
 ******************************************************/

typedef wiced_buffer_t    wwd_eapol_packet_t;

typedef void (*eapol_packet_handler_t) (wiced_buffer_t buffer, wwd_interface_t interface);

/******************************************************
 *                    Structures
 ******************************************************/

/******************************************************
 *                 Global Variables
 ******************************************************/

/******************************************************
 *               Function Declarations
 ******************************************************/

extern wwd_result_t wwd_eapol_register_receive_handler  ( eapol_packet_handler_t eapol_packet_handler );
extern void         wwd_eapol_unregister_receive_handler( void );
extern void         wwd_eapol_receive_eapol_packet( /*@only@*/ wiced_buffer_t buffer, wwd_interface_t interface );
extern uint8_t*     wwd_eapol_get_eapol_data( wwd_eapol_packet_t packet );
extern uint16_t     wwd_get_eapol_packet_size( wwd_eapol_packet_t packet );

#ifdef __cplusplus
} /*extern "C" */
#endif
