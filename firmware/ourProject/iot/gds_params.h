/*
 * Copyright (C) 2016 Freie Universität Berlin
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @ingroup     drivers_gds
 *
 * @{
 * @file
 * @brief       Default configuration for GDS devices
 *
 * @author      Melina Debono & Ugo Cipriani
 */

#ifndef GDS_PARAMS_H
#define GDS_PARAMS_H

#include "board.h"
#include "gds.h"
#include "saul_reg.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * @name    Set default configuration parameters for the GDS devices
 * @{
 */
#ifndef GDS_PARAM_PIN
#define GDS_PARAM_PIN               (GPIO_PIN(0, 0))
#endif
#ifndef GDS_PARAM_PULL
#define GDS_PARAM_PULL              (GPIO_IN_PU)
#endif
#ifndef GDS_PARAMS
#define GDS_PARAMS                  { .pin     = GDS_PARAM_PIN,  \
                                      .in_mode = GDS_PARAM_PULL }
#endif
#ifndef GDS_SAULINFO
#define GDS_SAULINFO                { .name = "gds" }
#endif
/**@}*/

/**
 * @brief   Configure GDS devices
 */
static const gds_params_t gds_params[] =
{
    GDS_PARAMS
};

/**
 * @brief   Allocate and configure entries to the SAUL registry
 */
static const saul_reg_info_t gds_saul_info[] =
{
    GDS_SAULINFO
};

#ifdef __cplusplus
}
#endif

#endif /* GDS_PARAMS_H */
/** @} */
