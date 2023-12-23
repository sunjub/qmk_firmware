// Copyright 2023 sunjub (@sunjub)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT

#define HAL_USE_I2C TRUE
#define I2C_DRIVER I2CD1
#define I2C1_SDA_PIN GP14
#define I2C1_SCL_PIN GP15

/* OLED */
// #define HAL_USE_I2C TRUE
// #define I2C1_SCL_PIN GP7
// #define I2C1_SDA_PIN GP6

#define RGBLIGHT_LAYERS
#define RGBLIGHT_MAX_LAYERS 6

// #ifdef OLED_ENABLE
//     #ifndef OLED_FONT_H
//         #define OLED_FONT_H "keyboards/crkbd/lib/glcdfont.c"
//     #endif
// #endif