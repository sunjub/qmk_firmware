/* Copyright 2020 kbjunky
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once
#include <stdint.h>
#include <stdbool.h>
#include "quantum.h"
#include "i2c_master.h"



/* I2C expander config */
#define I2CA_ADDRESS 0x20 << 1
#define I2CB_ADDRESS 0x21 << 1
#ifdef MACROPAD_ENABLE
    #define I2CM_ADDRESS 0x25 << 1  
#endif
#define I2C_TIMEOUT 1000

/* I/O Direction registers 
 * Specs say 1111111 on boot p.18
 * so all as inputs
 */
#define IODIRA 0x00
#define IODIRB 0x01

/*
 * Pull-up configuration register 
*/
#define GPPUA 0x0C
#define GPPUB 0x0D

/* I/O state register
 * This is where we read our data
*/
#define GPIOA 0x12
#define GPIOB 0x13

void i2c_initialize(void);
bool isI2C_initialized(void);

void i2c_write8(uint8_t addr, uint8_t reg, uint8_t data);
uint8_t i2c_read8(uint8_t addr, uint8_t reg);
void i2c_select_row(uint8_t row_index);
void i2c_select_row_on(uint8_t addr, uint8_t row_index);

i2c_status_t i2c_last_error(void);

#define LAYOUT( \
    L00, L01, L02, L03, L04, L05, L06, L07, \
    L10, L11, L12, L13, L14, L15, L16, L17, \
    L20, L21, L22, L23, L24, L25, L26, L27, \
    L30, L31, L32, L33, L34, L35, L36, L37, \
    L40, L41, L42, L43, L44, L45, L46, L47, \
    R07, R06, R05, R04, R03, R02, R01, R00, \
    R17, R16, R15, R14, R13, R12, R11, R10, \
    R27, R26, R25, R24, R23, R22, R21, R20, \
    R37, R36, R35, R34, R33, R32, R31, R30, \
    R47, R46, R45, R44, R43, R42, R41, R40, \
    M00, M01, M02, M03, \
    M10, M11, M12, M13, \
    M20, M21, M22, M23, \
    M30, M31, M32, M33, \
    M40, M41, M42, M43 \
) \
{ \
    { L00, L01, L02, L03, L04, L05, L06, L07, R00, R01, R02, R03, R04, R05, R06, R07, M00, M01, M02, M03}, \
    { L10, L11, L12, L13, L14, L15, L16, L17, R10, R11, R12, R13, R14, R15, R16, R17, M10, M11, M12, M13}, \
    { L20, L21, L22, L23, L24, L25, L26, L27, R20, R21, R22, R23, R24, R25, R26, R27, M20, M21, M22, M23}, \
    { L30, L31, L32, L33, L34, L35, L36, L37, R30, R31, R32, R33, R34, R35, R36, R37, M30, M31, M32, M33}, \
    { L40, L41, L42, L43, L44, L45, L46, L47, R40, R41, R42, R43, R44, R45, R46, R47, M40, M41, M42, M43} \
}
