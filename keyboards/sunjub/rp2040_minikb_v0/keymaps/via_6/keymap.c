#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_BTN1, KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_BTN3, KC_LEFT, KC_NO,   KC_NO,   KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_BTN2, KC_DOWN, KC_UP,   TG(4),   TG(5),     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_RGHT, TG(1),   TG(2),   TG(3),     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO
    ),
    [1] = LAYOUT(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   TG(4),   TG(5),     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   TG(1),   TG(2),   TG(3),     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO
    ),
    [2] = LAYOUT(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   TG(4),   TG(5),     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   TG(1),   TG(2),   TG(3),     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO
    ),
    [3] = LAYOUT(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   TG(4),   TG(5),     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   TG(1),   TG(2),   TG(3),     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO
    ),
    [4] = LAYOUT(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_4,    KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   TG(4),   TG(5),     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   TG(1),   TG(2),   TG(3),     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO
    ),
    [5] = LAYOUT(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_5,    KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,   TG(4),   TG(5),     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   TG(1),   TG(2),   TG(3),     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO
    )
};

#ifdef RGBLIGHT_LAYERS
# define LOCK_COLOR_1 HSV_TEAL

const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {1, 1, HSV_RED},
  {3, 1, HSV_GREEN}
);

const rgblight_segment_t PROGMEM my_numlock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
//   {1, 1, HSV_GREEN},
  {3, 1, HSV_GREEN}
);

const rgblight_segment_t PROGMEM my_scrolllock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {1, 1, HSV_BLUE},
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

const rgblight_segment_t PROGMEM my_layer4_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {0, 1, LOCK_COLOR_1},
  {2, 1, HSV_BLUE}
);

const rgblight_segment_t PROGMEM my_layer5_layer[] = RGBLIGHT_LAYER_SEGMENTS(
  {0, 1, LOCK_COLOR_1},
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
    rgblight_set_layer_state(3, layer_state_cmp(state, 1));
    rgblight_set_layer_state(4, layer_state_cmp(state, 2));
    rgblight_set_layer_state(5, layer_state_cmp(state, 3));
    rgblight_set_layer_state(6, layer_state_cmp(state, 4));
    rgblight_set_layer_state(7, layer_state_cmp(state, 5));
    return state;
}

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
  my_capslock_layer,
  my_numlock_layer,
  my_scrolllock_layer,
  my_layer1_layer,    // Overrides caps lock layer
  my_layer2_layer,    // Overrides other layers
  my_layer3_layer,    // Overrides other layers
  my_layer4_layer,    // Overrides other layers
  my_layer5_layer
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
        case 0:
            oled_write_P(PSTR("Default\n"), false);
            break;
        case 1:
            oled_write_P(PSTR("FN1\n"), false);
            break;
        case 2:
            oled_write_P(PSTR("FN2\n"), false);
            break;
        case 3:
            oled_write_P(PSTR("FN3\n"), false);
            break;
        case 4:
            oled_write_P(PSTR("FN4\n"), false);
            break;
        case 5:
            oled_write_P(PSTR("FN5\n"), false);
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

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [0] =   { ENCODER_CCW_CW(KC_WH_U, KC_WH_D), ENCODER_CCW_CW(KC_WH_U, KC_WH_D)  },
    [1] =   { ENCODER_CCW_CW(RGB_VAI, RGB_VAD), ENCODER_CCW_CW(KC_WH_U, KC_WH_D)  },
    [2] =   { ENCODER_CCW_CW(KC_WH_U, KC_WH_D), ENCODER_CCW_CW(KC_WH_U, KC_WH_D)  },
    [3] =   { ENCODER_CCW_CW(KC_WH_U, KC_WH_D), ENCODER_CCW_CW(KC_WH_U, KC_WH_D)  },
    [4] =   { ENCODER_CCW_CW(KC_WH_U, KC_WH_D), ENCODER_CCW_CW(KC_WH_U, KC_WH_D)  },
    [5] =   { ENCODER_CCW_CW(KC_WH_U, KC_WH_D), ENCODER_CCW_CW(KC_WH_U, KC_WH_D)  }
    //                  Encoder 1                                     Encoder 2
};
#endif