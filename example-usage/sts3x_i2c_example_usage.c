/*
 * THIS FILE IS AUTOMATICALLY GENERATED
 *
 * Generator:     sensirion-driver-generator 0.33.0
 * Product:       sts3x
 * Model-Version: 2.0.0
 */
/*
 * Copyright (c) 2023, Sensirion AG
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * * Redistributions of source code must retain the above copyright notice, this
 *   list of conditions and the following disclaimer.
 *
 * * Redistributions in binary form must reproduce the above copyright notice,
 *   this list of conditions and the following disclaimer in the documentation
 *   and/or other materials provided with the distribution.
 *
 * * Neither the name of Sensirion AG nor the names of its
 *   contributors may be used to endorse or promote products derived from
 *   this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */
#include "sensirion_common.h"
#include "sensirion_i2c_hal.h"
#include "sts3x_i2c.h"
#include <stdio.h>  // printf

#define sensirion_hal_sleep_us sensirion_i2c_hal_sleep_usec

int main(void) {
    int16_t error = NO_ERROR;
    sensirion_i2c_hal_init();
    sts3x_init(STS30_I2C_ADDR_4A);

    sts3x_stop_measurement();
    sensirion_hal_sleep_us(1000);
    sts3x_soft_reset();
    sensirion_hal_sleep_us(100000);
    uint16_t a_status_register = 0u;
    error = sts3x_read_status_register(&a_status_register);
    if (error != NO_ERROR) {
        printf("error executing read_status_register(): %i\n", error);
        return error;
    }
    printf("a_status_register: %02x\n", a_status_register);
    error = sts3x_start_periodic_measurement(REPEATABILITY_MEDIUM,
                                             MPS_ONE_PER_SECOND);
    if (error != NO_ERROR) {
        printf("error executing start_periodic_measurement(): %i\n", error);
        return error;
    }
    return NO_ERROR;
}
