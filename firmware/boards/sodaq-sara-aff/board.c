/*
 * Copyright (C) 2018 HAW Hamburg
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @ingroup     boards_sodaq-sara-aff
 * @{
 *
 * @file
 * @brief       Board common implementations for the SODAQ SARA AFF boards
 *
 * @author      Leandro Lanzieri <leandro.lanzieri@haw-hamburg.de>
 * @}
 */

#include "cpu.h"
#include "board.h"
#include "periph/gpio.h"

void board_init(void)
{
    /* set NB-IoT device off by default */
    NB_IOT_DISABLE;
    gpio_init(NB_IOT_ENABLE_PIN, GPIO_OUT);
    NB_IOT_TX_EN_OFF;
    gpio_init(NB_IOT_TX_EN_PIN, GPIO_OUT);
    NB_IOT_TOGGLE_ON;
    gpio_init(NB_IOT_TOGGLE_PIN, GPIO_OUT);

    /* set GPS off by default */
    GPS_ENABLE_OFF;
    gpio_init(GPS_ENABLE_PIN, GPIO_OUT);
}
