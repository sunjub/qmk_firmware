#include QMK_KEYBOARD_H

#include "sunjub_split_test.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        KC_1,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F11,    KC_F12,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_0,
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_GRV,    KC_DEL,  KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_LBRC,   KC_RBRC, KC_Y,    KC_U,    OSL(2),  OSL(3),  OSL(1),  KC_BSLS,
        KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_LPRN,   KC_RPRN, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_EQL,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
        KC_LGUI, KC_F22,  KC_LCTL, KC_LALT, KC_F14,  KC_SPC,  MO(1),     MO(2),   KC_ENT,  KC_F13,  KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT 
    ),
    [_FN1] = LAYOUT(
        KC_1,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F11,    KC_F12,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_0,
        KC_TRNS, KC_F1,   KC_F2,   KC_6,    KC_7,    KC_8,    KC_F11,    KC_F12,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_TRNS,
        KC_TRNS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_TRNS,   KC_TRNS, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_TRNS, 
        KC_CAPS, KC_EXLM, KC_QUES, KC_SCLN, KC_QUOT, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_MINS, KC_PLUS, KC_EQL,  KC_BSLS, KC_TRNS, 
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_ASTR, KC_SLSH, KC_TRNS, KC_TRNS, KC_TRNS, 
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(1),   MO(3),     MO(4),   MO(2),   KC_TRNS, KC_HOME, KC_PGDN, KC_PGUP, KC_END
    ),
    [_FN2] = LAYOUT(
        KC_1,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F11,    KC_F12,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_0,
        KC_TRNS, KC_F1,   KC_F2,   KC_Q,    KC_W,    KC_E,    KC_F11,    KC_F12,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_TRNS,
        KC_TRNS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_TRNS,   KC_TRNS, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_TRNS, 
        KC_CAPS, KC_EXLM, KC_QUES, KC_SCLN, KC_QUOT, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_MINS, KC_PLUS, KC_EQL,  KC_BSLS, KC_TRNS, 
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_ASTR, KC_SLSH, KC_TRNS, KC_TRNS, KC_TRNS, 
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(1),   MO(3),     MO(4),   MO(2),   KC_TRNS, KC_HOME, KC_PGDN, KC_PGUP, KC_END
    ),
    [_FN3] = LAYOUT(
        KC_1,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F11,    KC_F12,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_0,
        KC_TRNS, KC_F1,   KC_F2,   KC_CAPS, KC_SCRL, KC_NUM,  KC_F11,    KC_F12,  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_TRNS,
        KC_TRNS, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_TRNS,   KC_TRNS, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_TRNS, 
        KC_CAPS, KC_EXLM, KC_QUES, KC_SCLN, KC_QUOT, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_MINS, KC_PLUS, KC_EQL,  KC_BSLS, KC_TRNS, 
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS, KC_TRNS, KC_ASTR, KC_SLSH, KC_TRNS, KC_TRNS, KC_TRNS, 
        KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, MO(1),   MO(3),     MO(4),   MO(2),   KC_TRNS, KC_HOME, KC_PGDN, KC_PGUP, KC_END
    )
};

#ifdef RGBLIGHT_LAYERS
# define LOCK_COLOR_1 HSV_TEAL

const rgblight_segment_t PROGMEM navpad_capslock[] = RGBLIGHT_LAYER_SEGMENTS(
  {4,  1, LOCK_COLOR_1},
  {15, 1, LOCK_COLOR_1}
);

const rgblight_segment_t PROGMEM navpad_numlock[] = RGBLIGHT_LAYER_SEGMENTS(
  {0,  1, LOCK_COLOR_1},
  {5,  1, LOCK_COLOR_1},
  {14, 1, LOCK_COLOR_1}
);

const rgblight_segment_t PROGMEM navpad_scrolllock[] = RGBLIGHT_LAYER_SEGMENTS(
  {2,  1, LOCK_COLOR_1},
  {6,  1, LOCK_COLOR_1},
  {26, 1, LOCK_COLOR_1}
);

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, host_keyboard_led_state().caps_lock);
    rgblight_set_layer_state(1, (host_keyboard_led_state().num_lock && IS_LAYER_ON(_BASE)));
    rgblight_set_layer_state(2, host_keyboard_led_state().scroll_lock);
    return true;
}

const rgblight_segment_t* const PROGMEM navpad_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
  navpad_capslock,
  navpad_numlock,
  navpad_scrolllock
);

void keyboard_post_init_user(void) {
    rgblight_sethsv_noeeprom(HSV_WHITE);
    // Enable the LED layers
    rgblight_layers = navpad_rgb_layers;
}
#endif

#ifdef OLED_ENABLE
bool oled_task_user(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case _BASE:
            oled_write_P(PSTR("Default\n"), false);
            break;
        case _FN1:
            oled_write_P(PSTR("FN1\n"), false);
            break;
        case _FN2:
            oled_write_P(PSTR("FN2\n"), false);
            break;
        case _FN3:
            oled_write_P(PSTR("FN3\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }

    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
    
    return false;
}
#endif