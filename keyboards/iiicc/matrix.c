#include <stdint.h>
#include <stdbool.h>
#include "wait.h"
#include "print.h"
#include "debug.h"
#include "util.h"
#include "matrix.h"
#include "debounce.h"
#include "quantum.h"

#include QMK_KEYBOARD_H

#if (MATRIX_COLS <= 8)
#    define print_matrix_header() print("\nr/c 01234567\n")
#    define print_matrix_row(row) print_bin_reverse8(matrix_get_row(row))
#    define matrix_bitpop(i) bitpop(matrix[i])
#    define ROW_SHIFTER ((uint8_t)1)
#elif (MATRIX_COLS <= 16)
#    define print_matrix_header() print("\nr/c 0123456789ABCDEF\n")
#    define print_matrix_row(row) print_bin_reverse16(matrix_get_row(row))
#    define matrix_bitpop(i) bitpop16(matrix[i])
#    define ROW_SHIFTER ((uint16_t)1)
#elif (MATRIX_COLS <= 32)
#    define print_matrix_header() print("\nr/c 0123456789ABCDEF0123456789ABCDEF\n")
#    define print_matrix_row(row) print_bin_reverse32(matrix_get_row(row))
#    define matrix_bitpop(i) bitpop32(matrix[i])
#    define ROW_SHIFTER ((uint32_t)1)
#endif

#ifdef MATRIX_MASKED
extern const matrix_row_t matrix_mask[];
#endif

/* matrix state(1:on, 0:off) */
static matrix_row_t raw_matrix[MATRIX_ROWS];  // raw values
static matrix_row_t matrix[MATRIX_ROWS];      // debounced values

//__attribute__((weak)) void matrix_init_quantum(void) { matrix_init_kb(); }
//__attribute__((weak)) void matrix_scan_quantum(void) { matrix_scan_kb(); }
__attribute__((weak)) void matrix_init_kb(void) { matrix_init_user(); }
__attribute__((weak)) void matrix_scan_kb(void) { matrix_scan_user(); }
__attribute__((weak)) void matrix_init_user(void) {}
__attribute__((weak)) void matrix_scan_user(void) {}
//__attribute__((weak)) void matrix_init_kb(void) {}

inline uint8_t matrix_rows(void) { return MATRIX_ROWS; }
inline uint8_t matrix_cols(void) { return MATRIX_COLS; }

#define ENC_RES 4
#define ENCPAD 0x2
#define ENC_MATRIX_POS 0x20000

int8_t enc_state = 0;
int8_t enc_count = 0;
int8_t enc_states [] = {0, -1, 1, 0, 1, 0, 0, -1, -1, 0, 0, 1, 0, 1, -1, 0};

/* HERE STARTS IMPLEMENTATION OF CUSTOM MATRIX HANDLING */
matrix_row_t matrix_get_row(uint8_t row) {
    // TODO: return the requested row data
    return matrix[row];
}

void matrix_power_up() {
    print("matrix.c->matrix_power_up()");
}

void matrix_power_down() {
    print("matrix.c->matrix_power_down()");
}

void matrix_print(void) {
    print_matrix_header();

    for (uint8_t row = 0; row < MATRIX_ROWS; row++) {
        print_hex8(row);
        print(": ");
        print_matrix_row(row);
        print("\n");
    }
}

void matrix_init(void) {
    // TODO: initialize hardware and global matrix state here
    i2c_initialize();
    for(uint8_t i = 0; i < MATRIX_ROWS; i++) {
        raw_matrix[i] = 0;
        matrix[i] = 0;
    }
   
    // Unless hardware debouncing - Init the configured debounce routine
    debounce_init(MATRIX_ROWS);

    // This *must* be called for correct keyboard behavior
    matrix_init_kb();
}



uint8_t matrix_scan(void) {
    
    bool changed = false;
    uint8_t expander_data = 0;
    uint8_t enc_data = 0;
    matrix_row_t current_row = 0;

    for(uint8_t i = 0; i < MATRIX_ROWS; i++) {
#ifdef MACROPAD_ENABLE
        i2c_select_row_on(I2CM_ADDRESS, i);
        expander_data = i2c_read8(I2CM_ADDRESS, GPIOB);
        if(i2c_last_error()) {
            dprint("Macropad connection error!\n");
            i2c_initialize();
            current_row |= 0;
        }else {
            current_row |= expander_data;
        }

        if(i == 0) {
            enc_data = current_row & ENCPAD;
            enc_data <<= 1;
        }

        if(i == 1) {
            enc_data |= (current_row & ENCPAD);
            enc_data >>= 1;
        }

        current_row <<= 8;
#endif

        i2c_select_row_on(I2CB_ADDRESS, i);
        expander_data = i2c_read8(I2CB_ADDRESS, GPIOB);
        if(i2c_last_error()) {
            dprint("Right side connection error!\n");
            i2c_initialize();
            current_row |= 0;
        }else {
            current_row |= expander_data;
        }
        current_row <<= 8;

        i2c_select_row_on(I2CA_ADDRESS, i);
        expander_data = i2c_read8(I2CA_ADDRESS, GPIOB);
        if(i2c_last_error()) {
            dprint("Left side connection error!\n");
            i2c_initialize();
            current_row |= 0;
        }else {
            current_row |= expander_data;
        }

        if(current_row != raw_matrix[i]) {
            raw_matrix[i] = current_row;
            changed = true;
        } 
        current_row = 0; 
    }

    // debounce(raw_matrix, matrix, MATRIX_ROWS, changed);
    changed = debounce(raw_matrix, matrix, MATRIX_ROWS, changed);

    enc_count <<= 2;
    enc_count |= enc_data;
    enc_count &= 0xF;
    enc_state += enc_states[enc_count];

    if (enc_state <= -ENC_RES ) {
        matrix[1] |= ENC_MATRIX_POS;
        enc_state = 0;
    }else {
        matrix[1] &= ~ENC_MATRIX_POS;

    }

    if (enc_state >= ENC_RES ) {
        matrix[0] |= ENC_MATRIX_POS; 
        enc_state = 0;
    }else {
        matrix[0] &= ~ENC_MATRIX_POS;

    }

    matrix_scan_kb();

    return changed;
}