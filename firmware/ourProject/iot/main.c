/*
 * Copyright (C) 2015 Ludwig Knüpfer, Christian Mehlis
 *               2016-2017 Freie Universität Berlin
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

/**
 * @ingroup tests
 * @{
 *
 * @file
 * @brief       Test application for the dht humidity and temperature sensor driver
 *
 * @author      Ludwig Knüpfer <ludwig.knuepfer@fu-berlin.de>
 * @author      Christian Mehlis <mehlis@inf.fu-berlin.de>
 * @author      Hauke Petersen <hauke.petersen@fu-berlin.de>
 *
 * @}
 */

#include <stdio.h>
#include <math.h>

#include "xtimer.h"
#include "timex.h"
#include "fmt.h"
#include "dht.h"
#define DHT_PARAM_PIN               (GPIO_PIN(PORT_B, 3))
#include "dht_params.h"
// #include "gds.h"
// #define GDS_PARAM_PIN               (GPIO_PIN(PORT_A, 0))
// #include "gds_params.h"

#define DELAY           (2 * US_PER_SEC)

int main(void)
{
    dht_t dev;
    int16_t temp, hum;

    // test grove dust sensor
    // gds_t dev_2;
    // unsigned long duration = 0;
    // unsigned long sampletime_ms = 30000;//sampe 30s ;
    // unsigned long lowpulseoccupancy = 0;
    // float ratio = 0;
    // float concentration = 0;

    puts("DHT temperature and humidity sensor test application\n");

    /* initialize first configured sensor */
    printf("Initializing DHT sensor...\t");
    if (dht_init(&dev, &dht_params[0]) == DHT_OK) {
        puts("[OK]\n");
    }
    else {
        puts("[Failed]");
        return 1;
    }

    // test grove dust sensor
    // printf("Initializing GDS sensor...\t");
    // if (gds_init(&dev_2, &gds_params[0]) == GDS_OK) {
    //     puts("[OK]\n");
    // }
    // else {
    //     puts("[Failed]");
    //     return 1;
    // }
    // duration = gds_read(&dev_2, &duration);
    // lowpulseoccupancy = lowpulseoccupancy + duration;

    /* periodically read temp and humidity values */
    while (1) {
        if (dht_read(&dev, &temp, &hum) != DHT_OK) {
            // puts("Error reading values");
            continue;
        }

        printf("DHT values - temp: %d.%d°C - relative humidity: %d.%d%%\n",
               temp/10, temp%10, hum/10, hum%10);

        xtimer_usleep(DELAY);

        // test grove dust sensor
        // ratio = lowpulseoccupancy/(sampletime_ms*10.0);  // Integer percentage 0=>100
        // concentration = 1.1*pow(ratio,3)-3.8*pow(ratio,2)+520*ratio+0.62; // using spec sheet curve
        // printf("LPO : %lu %%, Ratio : %f, Concentration : %f\n", lowpulseoccupancy, ratio, concentration);
        // lowpulseoccupancy = 0;
    }

    return 0;
}
