#include QMK_KEYBOARD_H

enum keyboard_layers {
  _BASE = 0,
  _F1
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        KC_1,    KC_2,    KC_3,    KC_4,    KC_5,      KC_6,    KC_7,    KC_8,    KC_9,    KC_0, 
        KC_Q,    KC_D,    KC_R,    KC_W,    KC_B,      KC_J,    KC_F,    KC_U,    KC_P,    KC_SCLN, 
        KC_A,    KC_S,    KC_H,    KC_T,    KC_G,      KC_Y,    KC_N,    KC_E,    KC_O,    KC_I,  
        KC_Z,    KC_X,    KC_M,    KC_C,    KC_V,      KC_K,    KC_L,    KC_COMM, KC_DOT,  MO(1)
    ),
    [_F1] = LAYOUT(
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   QK_BOOT, KC_TRNS, KC_TRNS, KC_TRNS, KC_Q,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   QK_BOOT, DB_TOGG, KC_TRNS, KC_TRNS, KC_TRNS
    )
};