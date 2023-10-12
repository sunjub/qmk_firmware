// Copyright 2022 Y.Sakamoto (@FREEWING-JP)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _FN
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT(
        KC_A, KC_B, KC_C, KC_D, KC_E,
        KC_C, KC_D, KC_E, KC_F, KC_G,
        KC_E, KC_F, KC_G, KC_H, KC_I,
        KC_G, KC_H, KC_I, KC_J, KC_K,
        KC_I, KC_J, KC_K, KC_L, KC_M,
        KC_A, KC_B, KC_C, KC_D, KC_E,
        KC_C, KC_D, KC_E, KC_F, KC_G,
        KC_E, KC_F, KC_G, KC_H, KC_I,
        KC_G, KC_H, KC_I, KC_J, KC_K,
        KC_A, KC_B, KC_C, KC_D, KC_E,
        KC_C, KC_D, KC_E, KC_F, KC_G,
        KC_E, KC_F, KC_G, KC_H, KC_I,
        KC_G, KC_H, KC_I, KC_J, KC_K,
        KC_C, KC_D, KC_E, KC_F, KC_G,
        KC_E, KC_F, KC_G, KC_H, KC_I,
        KC_G, KC_H, KC_I, KC_J, KC_K
    ),
    [_FN] = LAYOUT(
        KC_A, KC_B, KC_C, KC_D, KC_E,
        KC_C, KC_D, KC_E, KC_F, KC_G,
        KC_E, KC_F, KC_G, KC_H, KC_I,
        KC_G, KC_H, KC_I, KC_J, KC_K,
        KC_I, KC_J, KC_K, KC_L, KC_M,
        KC_A, KC_B, KC_C, KC_D, KC_E,
        KC_C, KC_D, KC_E, KC_F, KC_G,
        KC_E, KC_F, KC_G, KC_H, KC_I,
        KC_G, KC_H, KC_I, KC_J, KC_K,
        KC_A, KC_B, KC_C, KC_D, KC_E,
        KC_C, KC_D, KC_E, KC_F, KC_G,
        KC_E, KC_F, KC_G, KC_H, KC_I,
        KC_G, KC_H, KC_I, KC_J, KC_K,
        KC_C, KC_D, KC_E, KC_F, KC_G,
        KC_E, KC_F, KC_G, KC_H, KC_I,
        KC_G, KC_H, KC_I, KC_J, KC_K
    )
};

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  debug_enable=true;
  debug_matrix=true;
  debug_keyboard=true;
  //debug_mouse=true;
}
