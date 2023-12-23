#include QMK_KEYBOARD_H

#include "rp2040_split.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        KC_NUM,  MO(1),     KC_NUM,  MO(1),
        KC_CAPS, MO(2),     KC_CAPS, MO(2),
        KC_SCRL, MO(3),     KC_SCRL, MO(3)
    ),
    [_FN1] = LAYOUT(
        KC_1,    RGB_TOG,   RGB_HUD, RGB_HUI,
        KC_NO,   RGB_MOD,   RGB_SAD, RGB_SAI,
        KC_NO,   RGB_RMOD,  RGB_VAD, RGB_VAI
    ),
    [_FN2] = LAYOUT(
        KC_2,    KC_NO,     KC_6,    KC_NO,
        KC_NO,   KC_NO,     KC_NO,   KC_NO,
        KC_NO,   KC_NO,     KC_NO,   KC_NO
    ),
    [_FN3] = LAYOUT(
        KC_3,    KC_NO,     KC_7,    KC_NO,
        KC_NO,   KC_NO,     KC_NO,   KC_NO,
        KC_NO,   KC_NO,     KC_NO,   KC_NO
    )
};

#ifdef RGBLIGHT_LAYERS
# define LOCK_COLOR_1 HSV_TEAL

const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {1,  1, LOCK_COLOR_1}
);

const rgblight_segment_t PROGMEM my_numlock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {0,  1, LOCK_COLOR_1}
);

const rgblight_segment_t PROGMEM my_scrolllock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {2,  1, LOCK_COLOR_1}
);

const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {3, 1, HSV_YELLOW},
  {10, 2, HSV_GREEN}
);

const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {4, 1, HSV_CYAN},
  {8,  2, HSV_RED}
);

const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {5, 1, HSV_MAGENTA},
  {12, 3, HSV_BLUE}
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