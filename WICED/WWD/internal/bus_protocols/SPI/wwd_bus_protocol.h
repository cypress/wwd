/*
 * Copyright (c) 2018 Cypress Semiconductor
 * SPDX-License-Identifier: Apache-2.0
 */

#ifndef INCLUDED_SPI_WWD_BUS_PROTOCOL_H
#define INCLUDED_SPI_WWD_BUS_PROTOCOL_H

#include <stdint.h>
#include "internal/wwd_thread_internal.h"

#ifdef __cplusplus
extern "C" {
#endif

/******************************************************
 *             Constants
 ******************************************************/

/******************************************************
 *             Structures
 ******************************************************/

typedef uint32_t wwd_bus_gspi_header_t;


#pragma pack(1)

typedef struct
{
    wwd_bus_gspi_header_t gspi_header;
} wwd_bus_header_t;

#pragma pack()

#define WWD_BUS_HAS_HEADER

#define WWD_BUS_HEADER_SIZE                     ( sizeof(wwd_bus_header_t) )

#define WWD_BUS_USE_STATUS_REPORT_SCHEME        ( 1 == 1 )

#define WWD_BUS_MAX_BACKPLANE_TRANSFER_SIZE     ( 64 ) /* Max packet size on F1 */
#define WWD_BUS_BACKPLANE_READ_PADD_SIZE        ( 4 )

/******************************************************
 *             Function declarations
 ******************************************************/

/******************************************************
 *             Global variables
 ******************************************************/

#ifdef __cplusplus
} /*extern "C" */
#endif

#endif /* ifndef INCLUDED_SPI_WWD_BUS_PROTOCOL_H */
