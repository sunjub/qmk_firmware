#include QMK_KEYBOARD_H

#include "rp2040_minikb_v0.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_7,    KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_0,    KC_PSLS, KC_PAST, MO(3),   KC_F11,    KC_4,    KC_F6,   KC_F7,   KC_F8,   KC_F9,
        KC_P7,   KC_P8,   KC_P9,   MO(2),   KC_GRV,    KC_DEL,  KC_6,    KC_7,    KC_8,    KC_9,
        KC_P4,   KC_P5,   KC_P6,   MO(2),   KC_LBRC,   KC_RBRC, KC_Y,    KC_U,    KC_I,    KC_O,
        KC_P1,   KC_P2,   KC_P3,   MO(1),   KC_LPRN,   KC_RPRN, KC_H,    KC_J,    KC_K,    KC_L
    ),
    [_FN1] = LAYOUT(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_7,    KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_1,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_5,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
        KC_TRNS, RGB_TOG, RGB_MOD, RGB_RMOD,KC_8,      KC_F12,  KC_F6,   KC_F7,   KC_F8,   KC_F9,
        KC_TRNS, RGB_HUI, RGB_SAI, RGB_VAI, KC_5,      KC_TRNS, KC_6,    KC_7,    KC_8,    KC_9,
        KC_TRNS, RGB_HUD, RGB_SAD, RGB_VAD, KC_TRNS,   KC_TRNS, KC_TRNS, KC_MINS, KC_PLUS, KC_EQL
    ),
    [_FN2] = LAYOUT(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_7,    KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_2,    KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_6,    KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO
    ),
    [_FN3] = LAYOUT(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_7,    KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_3,    KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_7,    KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO
    )
};

#ifdef RGBLIGHT_LAYERS
# define LOCK_COLOR_1 HSV_TEAL

const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {1, 1, HSV_GREEN},
  {3, 1, HSV_GREEN}
);

const rgblight_segment_t PROGMEM my_numlock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {1, 1, HSV_GREEN},
  {3, 1, HSV_GREEN}
);

const rgblight_segment_t PROGMEM my_scrolllock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {1, 1, HSV_GREEN},
  {3, 1, HSV_GREEN}
);

const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {0, 1, HSV_YELLOW},
  {2, 1, HSV_GREEN}
);

const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {0, 1, HSV_CYAN},
  {2, 1, HSV_RED}
);

const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {0, 1, HSV_MAGENTA},
  {2, 1, HSV_BLUE}
);

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, host_keyboard_led_state().caps_lock);
    rgblight_set_layer_state(1, host_keyboard_led_state().num_lock);
    // rgblight_set_layer_state(1, (host_keyboard_led_state().num_lock && IS_LAYER_ON(_BASE)));
    rgblight_set_layer_state(2, host_keyboard_led_state().scroll_lock);
    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(3, layer_state_cmp(state, _FN1));
    rgblight_set_layer_state(4, layer_state_cmp(state, _FN2));
    rgblight_set_layer_state(5, layer_state_cmp(state, _FN3));
    return state;
}

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
  my_capslock_layer,
  my_numlock_layer,
  my_scrolllock_layer,
  my_layer1_layer,    // Overrides caps lock layer
  my_layer2_layer,    // Overrides other layers
  my_layer3_layer
);

void keyboard_post_init_user(void) {
    rgblight_sethsv_noeeprom(HSV_WHITE);
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
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