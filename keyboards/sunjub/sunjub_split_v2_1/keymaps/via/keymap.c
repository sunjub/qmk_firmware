#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_ESC,    KC_DEL,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS,
        KC_TAB,  KC_Q,    KC_D,    KC_R,    KC_W,    KC_B,    KC_LBRC,   KC_RBRC, KC_J,    KC_F,    KC_U,    KC_P,    KC_SCLN, KC_EQL, 
        KC_LCTL, KC_A,    KC_S,    KC_H,    KC_T,    KC_G,    KC_NO,     KC_NO,   KC_Y,    KC_N,    KC_E,    KC_O,    KC_I,    KC_BSPC,
        KC_LSFT, KC_Z,    KC_X,    KC_M,    KC_C,    KC_V,    MO(2),     KC_RCTL, KC_K,    KC_L,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
        KC_LGUI, KC_F22,  KC_LCTL, KC_LALT, KC_F14,  KC_SPC,  MO(1),     KC_RSFT, KC_ENT,  KC_F13,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT 
    ),
    [1] = LAYOUT(
        KC_TRNS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F11,    KC_F12,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_TRNS,
        KC_TRNS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_TRNS,   KC_TRNS, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_TRNS, 
        KC_CAPS, KC_EXLM, KC_QUES, KC_SCLN, KC_QUOT, KC_LPRN, KC_TRNS,   KC_TRNS, KC_RPRN, KC_MINS, KC_PLUS, KC_EQL,  KC_BSLS, KC_TRNS, 
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   TG(3),   KC_TRNS, KC_ASTR, KC_SLSH, KC_TRNS, KC_TRNS, KC_TRNS, 
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_BSPC, KC_TRNS, KC_HOME, KC_PGDN, KC_PGUP, KC_END
    ),
    [2] = LAYOUT(
        QK_BOOT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_SLEP,   KC_INS,  KC_HOME, KC_PGUP, KC_PEQL, KC_PSLS, KC_PAST, KC_PMNS, 
        KC_TAB,  NK_OFF,  NK_ON,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_DEL,  KC_END,  KC_PGDN, KC_P7,   KC_P8,   KC_P9,   KC_PPLS, 
        KC_TRNS, KC_TRNS, KC_F15,  KC_F16,  KC_F17,  KC_F18,  KC_F19,   S(KC_TAB), KC_UP,  KC_TAB,  KC_P4,   KC_P5,   KC_P6,   KC_LPRN,
        KC_TRNS, KC_TRNS, KC_F20,  KC_F21,  KC_F22,  KC_F23,  KC_F24,    KC_LEFT, KC_DOWN, KC_RGHT, KC_P1,   KC_P2,   KC_P3,   KC_PENT,
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_BSPC, KC_P0,   KC_TRNS, KC_PDOT, KC_RPRN
    ),
    [3] = LAYOUT(
        KC_ESC,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_6,      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, KC_Y,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,      KC_TRNS, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_TRNS, 
        KC_TRNS, KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,      KC_TRNS, KC_H,    KC_J,    KC_K,    KC_L,    KC_TRNS, KC_TRNS, 
        KC_TRNS, KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,      KC_TRNS, KC_N,    KC_M,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 
        KC_TRNS, KC_LCTL, KC_F14,  KC_LCTL, KC_LALT, KC_TRNS, KC_V,      KC_ENT,  KC_M,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    )
};