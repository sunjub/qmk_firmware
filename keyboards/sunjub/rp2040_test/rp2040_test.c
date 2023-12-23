/* Copyright 2021 yushakobo
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

#include "rp2040_test.h"

bool process_record_kb(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_user(keycode, record)) { return false; }
    switch (keycode) {
  case TAP_00:
    if (record->event.pressed){
      tap_code(KC_P0);
      tap_code(KC_P0);
      }
    break;

  default:
    break;
  }
  return true;
}

// bool led_update_kb(led_t led_state) {
//     return led_update_user(led_state);
// }

#ifdef ENCODER_ENABLE
bool encoder_update_kb(uint8_t index, bool clockwise) {
    if (!encoder_update_user(index, clockwise)) { return false; }
    if (index == 0) { /* Navpad side encoder */
      switch (get_highest_layer(layer_state|default_layer_state)) {
      case _BASE:
        if (clockwise) {
          tap_code16(KC_WH_D);
        } else {
          tap_code16(KC_WH_U);
        }
        break;
      
      case _FN1:
        if (clockwise) {
          tap_code16(KC_WH_D);
        } else {
          tap_code16(KC_WH_U);
        }
        break;
      
      case _FN2:
        if (clockwise) {
          tap_code16(KC_WH_D);
        } else {
          tap_code16(KC_WH_U);
        }
        break;
      
      case _FN3:
        if (clockwise) {
          tap_code16(KC_WH_D);
        } else {
          tap_code16(KC_WH_U);
        }
        break;

      default:
        break;
      }
    }
    return false;
  }
#endif

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) {
        return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
    }

    return rotation;
}
#endif