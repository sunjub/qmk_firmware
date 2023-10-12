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


//#define PCF8575_I2C_ADDR 0x20  // PCF8575のI2Cアドレス
#define OLED_DISPLAY_128X64
#define OLED_FONT_H "keyboards/sunjub2/glcdfont.c"
#define OLED_TIMEOUT 0