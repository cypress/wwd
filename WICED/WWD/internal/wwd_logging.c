/*
 * Copyright (c) 2018 Cypress Semiconductor
 * SPDX-License-Identifier: Apache-2.0
 */
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include "wwd_logging.h"

#ifdef WWD_LOGGING_STDOUT_ENABLE
int                  wwd_logging_enabled = 0;

#elif defined WWD_LOGGING_BUFFER_ENABLE

#ifndef LOGGING_BUFFER_SIZE
#error LOGGING_BUFFER_SIZE is not defined
#endif /* LOGGING_BUFFER_SIZE */

static unsigned long logging_buffer_position = 0;
static char          logging_buffer[LOGGING_BUFFER_SIZE];
int                  wwd_logging_enabled = 0;

int wwd_logging_printf(const char *format, ...)
{
    int potential_num_written = 0;
    va_list args;
    va_start (args, format);
    potential_num_written = vsnprintf (&logging_buffer[logging_buffer_position], (size_t)(LOGGING_BUFFER_SIZE - logging_buffer_position), format, args);
    if ( potential_num_written > (int)(LOGGING_BUFFER_SIZE - logging_buffer_position) )
    {
        /* full print did not fit in buffer - wipe what was just written and reprint at start of buffer */
        memset( &logging_buffer[logging_buffer_position], (int)'\n', (size_t)(LOGGING_BUFFER_SIZE - logging_buffer_position ) );
        logging_buffer_position = 0;
        potential_num_written = vsnprintf (&logging_buffer[logging_buffer_position], (size_t)(LOGGING_BUFFER_SIZE - logging_buffer_position), format, args);
    }
    logging_buffer_position += (unsigned)potential_num_written;
    if ( logging_buffer_position >= LOGGING_BUFFER_SIZE )
    {
        logging_buffer_position = 0;
    }

    va_end (args);
    return potential_num_written;
}

#endif /* ifdef WWD_LOGGING_BUFFER_ENABLE */

