// Copyright 2021 Y.Sakamoto (@FREEWING-JP)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "matrix.h"
#include "gpio.h"
#include "i2c_master.h"

#if (MATRIX_ROWS <= 8)
#    define ROW_TYPE uint8_t
#elif (MATRIX_ROWS <= 16)
#    define ROW_TYPE uint16_t
#elif (MATRIX_ROWS <= 32)
#    define ROW_TYPE uint32_t
#endif

#define ROW_SHIFTER ((ROW_TYPE)1)

#define I2C_TIMEOUT 1000

#define I2C_WRITE 0x00
#define I2C_READ 0x01

// Col Output PCF8574 (A2=L, A1=L, A0=L)
#define I2C_ADDR_COL 0x20
#define I2C_ADDR_COL_WRITE ((I2C_ADDR_COL << 1) | I2C_WRITE)
#define I2C_ADDR_COL_READ ((I2C_ADDR_COL << 1) | I2C_READ)

// Row Input PCF857x (A2=H, A1=L, A0=L)
#define I2C_ADDR_ROW 0x24
#define I2C_ADDR_ROW_WRITE ((I2C_ADDR_ROW << 1) | I2C_WRITE)
#define I2C_ADDR_ROW_READ ((I2C_ADDR_ROW << 1) | I2C_READ)

// Col Output PCF8574 8bit
static void col_init(void) {
    // All Output 'H'
    uint8_t buf[] = { 0b11111111 };
    i2c_transmit(I2C_ADDR_COL_WRITE, buf, sizeof(buf), I2C_TIMEOUT);
}

// Row Input PCF8574 8bit / PCF8575 16bit
static void row_init(void) {
#if (MATRIX_ROWS <= 8)
    // Row Input PCF8574 8bit
    // All Input Pull Up
    uint8_t buf[] = { 0b11111111 };
    i2c_transmit(I2C_ADDR_ROW_WRITE, buf, sizeof(buf), I2C_TIMEOUT);
#elif (MATRIX_ROWS <= 16)
    // Row Input PCF8575 16bit
    // All Input Pull Up
    uint8_t buf[] = { 0b11111111, 0b11111111 };
    i2c_transmit(I2C_ADDR_ROW_WRITE, buf, sizeof(buf), I2C_TIMEOUT);
#elif (MATRIX_ROWS <= 32)
    TODO()
#endif
}

// Col Output PCF8574 8bit
static void select_col(uint8_t col) {
    // Col Output 'L'
    uint8_t colByte = ~(1 << col);
    uint8_t buf[] = { colByte };
    i2c_transmit(I2C_ADDR_COL_WRITE, buf, sizeof(buf), I2C_TIMEOUT);
}

// Row Input PCF8574 8bit / PCF8575 16bit
static ROW_TYPE read_rows(void) {
#if (MATRIX_ROWS <= 8)
    // Row Input PCF8574 8bit
    uint8_t buf[1];
    i2c_receive(I2C_ADDR_ROW_READ, buf, sizeof(buf), I2C_TIMEOUT);
    return ~buf[0];
#elif (MATRIX_ROWS <= 16)
    // Row Input PCF8575 16bit
    uint8_t buf[2];
    i2c_receive(I2C_ADDR_ROW_READ, buf, sizeof(buf), I2C_TIMEOUT);
    return ~((buf[1] << 8) | buf[0]);
#elif (MATRIX_ROWS <= 32)
    TODO()
#endif
}

void matrix_init_custom(void) {
    i2c_init();
    col_init();
    row_init();
}

// MATRIX_ROWS = 4
// MATRIX_COLS = 4
// matrix_row_t = uint8_t
bool matrix_scan_custom(matrix_row_t current_matrix[]) {
    // Scan Keyboard Matrix
    ROW_TYPE tmp[MATRIX_COLS];
    ROW_TYPE* pt = tmp;
    for (uint8_t col = 0; col < MATRIX_COLS; ++col) {
        // MSB = col 7, LSB = col 0
        select_col(col);
        matrix_io_delay();

        *pt++ = read_rows();
    }
    col_init();

    // Check Keyboard Matrix has Changed
    bool matrix_has_changed = false;
    matrix_row_t* p = current_matrix;
    for (uint8_t row = 0; row < MATRIX_ROWS; ++row) {

        ROW_TYPE and_row = (ROW_SHIFTER << row);
        matrix_row_t now_rows = 0;
        int8_t col = MATRIX_COLS;
        while (--col >= 0) {
            now_rows <<= 1;
            now_rows |= ((tmp[col] & and_row) ? 1 : 0);
        }

        if (*p != now_rows) {
            *p = now_rows;
            matrix_has_changed = true;
        }
        ++p;
    }

    return matrix_has_changed;
}