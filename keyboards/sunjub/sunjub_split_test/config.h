// Copyright 2022 sunjub (@sunjub)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

// #include "config_common.h"

/* Use I2C or Serial, not both */
// #define USE_SERIAL
// #define USE_I2C

/* Select hand configuration */
/* Decide which hand you want to plug in the USB */ 
// #define MASTER_LEFT
#define MASTER_RIGHT
// #define EE_HANDS
// #define SPLIT_HAND_PIN D5
// #define SPLIT_HAND_PIN_LOW_IS_LEFT
// #define SPLIT_USB_DETECT
// #define SPLIT_USB_TIMEOUT 2500

/* COL2ROW or ROW2COL */
// #define DIODE_DIRECTION COL2ROW

/* Set 0 if debouncing isn't needed */
// #define DEBOUNCE 5

/* serial.c configuration for split keyboard */
// #define SOFT_SERIAL_PIN D0
// #define SPLIT_HAND_PIN B6

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

#define RGBLIGHT_LAYERS
#define RGBLIGHT_MAX_LAYERS 6

#define QUICK_TAP_TERM 0
#define TAPPING_LAYER_TERM 90

#ifdef OLED_ENABLE
    #ifndef OLED_FONT_H
        #define OLED_FONT_H "keyboards/crkbd/lib/glcdfont.c"
    #endif
#endif


// #undef OLED_UPDATE_INTERVAL
// #ifdef DEBUG_MATRIX_SCAN_RATE
// #    define OLED_UPDATE_INTERVAL 500
// #else
// #    define OLED_UPDATE_INTERVAL 50
// #endif