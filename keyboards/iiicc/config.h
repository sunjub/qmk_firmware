/*
Copyright 2020 kbjunky

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

//#include "config_common.h"

/* Macropad */
//#define MACROPAD_ENABLE //uncomment to enable macropad

/* OLED settings */
//#define OLED_DISPLAY_ADDRESS 0x78 //128x64 sometimes run on 0x3C just like 128x32, that was the case for me
#define OLED_DISPLAY_128X64
#define OLED_FONT_H "keyboards/iiicc/glcdfont.c"
#define OLED_TIMEOUT 0
//full matrix, we skip macropad scanning in matrix.c if not defined here
#define MATRIX_ROWS 5
#define MATRIX_COLS 20

/* COL2ROW, ROW2COL*/
#define DIODE_DIRECTION COL2ROW