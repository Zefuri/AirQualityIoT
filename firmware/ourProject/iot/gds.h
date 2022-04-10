/*
 * Copyright 2015 Ludwig Knüpfer,
 *           2015 Christian Mehlis
 *           2016-2017 Freie Universität Berlin
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @defgroup    drivers_gds GDS Family of Humidity and Temperature Sensors
 * @ingroup     drivers_sensors
 * @ingroup     drivers_saul
 * @brief       Device driver for the GDS Family of humidity
 *              and temperature sensors
 *
 * This driver provides @ref drivers_saul capabilities.
 *
 * @{
 *
 * @file
 * @brief       Device driver interface for the GDS family of humidity
 *              and temperature sensors
 *
 * @author      Melina Debono & Ugo Cipriani
 */

#ifndef GDS_H
#define GDS_H

#include <stdint.h>

#include "periph/gpio.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief   Possible return codes
 */
enum {
    GDS_OK      =  0,       /**< all good */
    GDS_NOCSUM  = -1,       /**< checksum error */
    GDS_TIMEOUT = -2,       /**< communication timed out */
};

/**
 * @brief   Data type for storing GDS sensor readings
 */
typedef struct {
    unsigned long duration;
} gds_data_t;

/**
 * @brief   Configuration parameters for GDS devices
 */
typedef struct {
    gpio_t pin;             /**< GPIO pin of the device's data pin */
    gpio_mode_t in_mode;    /**< input pin configuration, with or without pull
                             *   resistor */
} gds_params_t;

/**
 * @brief   Device descriptor for GDS sensor devices
 */
typedef struct {
    gds_params_t params;    /**< Device parameters */
    gds_data_t last_val;    /**< Values of the last measurement */
    uint32_t last_read_us;  /**< Time of the last measurement */
} gds_t;

/**
 * @brief   Initialize a new GDS device
 *
 * @param[out] dev      device descriptor of a GDS device
 * @param[in]  params   configuration parameters
 *
 * @return              0 on success
 * @return              -1 on error
 */
int gds_init(gds_t *dev, const gds_params_t *params);

/**
 * @brief   get a new temperature and humidity value from the device
 *
 * @note    if reading fails or checksum is invalid, no new values will be
 *          written into the result values
 *
 * @param[in]  dev      device descriptor of a GDS device
 * @param[out] duration
 *
 * @retval GDS_OK       Success
 * @retval GDS_NOCSUM   Checksum error
 * @retval GDS_TIMEOUT  Reading data timed out (check wires!)
 */
int gds_read(gds_t *dev, unsigned long *duration);

#ifdef __cplusplus
}
#endif

#endif /* GDS_H */
/** @} */
