// Copyright 2022 sunjub (@sunjub)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

// #include "config_common.h"

/* Use I2C or Serial, not both */
// #define USE_SERIAL
#define USE_I2C

/* Select hand configuration */
/* Decide which hand you want to plug in the USB */ 
// #define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS
#define SPLIT_HAND_PIN D5
//#define SPLIT_HAND_PIN_LOW_IS_LEFT
#define SPLIT_USB_DETECT
#define SPLIT_USB_TIMEOUT 2500

/* key matrix size */
// Rows are doubled-up
#define MATRIX_ROWS 10
#define MATRIX_COLS 7

// wiring of each half
#define MATRIX_ROW_PINS { F6, F5, F4, D6, D7 }
#define MATRIX_COL_PINS { F7, C7, C6, B6, B5, B4, D4 } 
#define MATRIX_ROW_PINS_RIGHT { B5, B6, C6, F6, D6 }
#define MATRIX_COL_PINS_RIGHT { B4, F5, F4, F1, F0, D4, D7 }

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

/* serial.c configuration for split keyboard */
// #define SOFT_SERIAL_PIN D0
// #define SPLIT_HAND_PIN B6

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE