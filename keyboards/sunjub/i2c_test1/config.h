// Copyright 2022 sunjub (@sunjub)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/* USB Device descriptor parameter */
#define VENDOR_ID       0x3DEB
#define PRODUCT_ID      0x4D31
#define DEVICE_VER      0x0001
#define MANUFACTURER    sunjub
#define PRODUCT         macroi2c


#define ENCODERS_PAD_A { F0 }
#define ENCODERS_PAD_B { E6 }

/* Use I2C or Serial, not both */
// #define USE_SERIAL
#define USE_I2C

/* serial.c configuration for split keyboard */
// #define SOFT_SERIAL_PIN D2
// #define SELECT_SOFT_SERIAL_SPEED 2
// D0 or D1,D2,D3,E6
// #define SPLIT_HAND_PIN B6
// #define SERIAL_DEBUG

/* Select hand configuration */
/* Decide which hand you want to plug in the USB */ 
// #define MASTER_LEFT
#define MASTER_RIGHT
// #define EE_HANDS

/* key matrix size */
// Rows are doubled-up
#define MATRIX_ROWS 8
#define MATRIX_COLS 5

// wiring of each half
#define MATRIX_ROW_PINS { F1, F4, F5, F6 }
#define MATRIX_COL_PINS { B3, B2, B1, B0, F7 } 

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE