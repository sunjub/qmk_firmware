/* Copyright 2020 kbjunky
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
#include QMK_KEYBOARD_H

#define ICO_SPEAKER 128
#define ICO_BRIGHTNESS 131
#define ICO_HUE 134
#define ICO_SAT 137
#define ICO_CAPSL 140
#define ICO_LOGO 143
#define ICO_BLANK 157
#define ICO_LOGO_WIDTH 14
#define ICO_WIDTH 3 //3x3 characters per icon  
#define CHARS_PER_LINE 32 //in glcdfont.c
#define ICO_UP  24
#define ICO_DOWN 25
#define SCREEN_TIMEOUT 2500
#ifdef OLED_ENABLE
  static uint16_t oled_timer = 0;
#endif

//Boot up LED animation
#define BOOT_ANIM_ENABLED //enable boot animation
#define BOOT_ANIM_DELAY 125 //delay for each step

#define _DFT 0
#define _FN1 10
#define _FN2 11


#define SPCFN1 LT(_FN1, KC_SPC)
#define TABFN2 LT(_FN2, KC_TAB)
#define TABFN1 LT(_FN1, KC_TAB)

#define INSALT MT(MOD_LALT, KC_INS)
#define ENTCTL MT(MOD_LCTL, KC_ENT)
#define CTLLSH MT(MOD_LCTL, KC_SLSH)
#define CTLQOT MT(MOD_RCTL, KC_QUOT)
#define DELRALT MT(MOD_RALT, KC_DEL)

void render_icon_center(uint8_t);  //forward definition
void render_action_icon(uint8_t, uint8_t);
void render_icon(uint8_t, uint8_t, uint8_t);
void clear_icon(uint8_t, uint8_t);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {\
    /* Base */
    [_DFT] = LAYOUT(\
    KC_A, KC_B, KC_C, KC_D, KC_E, KC_F, KC_G, KC_H,\
    KC_C, KC_D, KC_E, KC_F, KC_G, KC_H, KC_I, KC_J,\
    KC_E, KC_F, KC_G, KC_H, KC_I, KC_J, KC_K, KC_L,\
    KC_G, KC_H, KC_I, KC_J, KC_K, KC_L, KC_M, KC_N,\
    KC_I, KC_J, KC_K, KC_L, KC_M, KC_N, KC_O, KC_P,\
    KC_K, KC_L, KC_M, KC_N, KC_O, KC_P, KC_Q, KC_R,\
    KC_M, KC_N, KC_O, KC_P, KC_Q, KC_R, KC_S, KC_T,\
    KC_O, KC_P, KC_Q, KC_R, KC_S, KC_T, KC_U, KC_V,\
    KC_Q, KC_R, KC_S, KC_T, KC_U, KC_V, KC_W, KC_X,\
    KC_S, KC_T, KC_U, KC_V, KC_W, KC_X, KC_Y, KC_Z,\
    KC_U, KC_V, KC_W, KC_X,\
    KC_W, KC_X, KC_Y, KC_Z,\
    KC_Y, KC_Z, KC_0, KC_1,\
    KC_0, KC_1, KC_2, KC_3,\
    KC_2, KC_3, KC_4, KC_5\
    ),
    [_FN1] = LAYOUT(\
    KC_A, KC_B, KC_C, KC_D, KC_E, KC_F, KC_G, KC_H,\
    KC_C, KC_D, KC_E, KC_F, KC_G, KC_H, KC_I, KC_J,\
    KC_E, KC_F, KC_G, KC_H, KC_I, KC_J, KC_K, KC_L,\
    KC_G, KC_H, KC_I, KC_J, KC_K, KC_L, KC_M, KC_N,\
    KC_I, KC_J, KC_K, KC_L, KC_M, KC_N, KC_O, KC_P,\
    KC_K, KC_L, KC_M, KC_N, KC_O, KC_P, KC_Q, KC_R,\
    KC_M, KC_N, KC_O, KC_P, KC_Q, KC_R, KC_S, KC_T,\
    KC_O, KC_P, KC_Q, KC_R, KC_S, KC_T, KC_U, KC_V,\
    KC_Q, KC_R, KC_S, KC_T, KC_U, KC_V, KC_W, KC_X,\
    KC_S, KC_T, KC_U, KC_V, KC_W, KC_X, KC_Y, KC_Z,\
    KC_U, KC_V, KC_W, KC_X,\
    KC_W, KC_X, KC_Y, KC_Z,\
    KC_Y, KC_Z, KC_0, KC_1,\
    KC_0, KC_1, KC_2, KC_3,\
    KC_2, KC_3, KC_4, KC_5\
    ),
    [_FN2] = LAYOUT(\
    KC_A, KC_B, KC_C, KC_D, KC_E, KC_F, KC_G, KC_H,\
    KC_C, KC_D, KC_E, KC_F, KC_G, KC_H, KC_I, KC_J,\
    KC_E, KC_F, KC_G, KC_H, KC_I, KC_J, KC_K, KC_L,\
    KC_G, KC_H, KC_I, KC_J, KC_K, KC_L, KC_M, KC_N,\
    KC_I, KC_J, KC_K, KC_L, KC_M, KC_N, KC_O, KC_P,\
    KC_K, KC_L, KC_M, KC_N, KC_O, KC_P, KC_Q, KC_R,\
    KC_M, KC_N, KC_O, KC_P, KC_Q, KC_R, KC_S, KC_T,\
    KC_O, KC_P, KC_Q, KC_R, KC_S, KC_T, KC_U, KC_V,\
    KC_Q, KC_R, KC_S, KC_T, KC_U, KC_V, KC_W, KC_X,\
    KC_S, KC_T, KC_U, KC_V, KC_W, KC_X, KC_Y, KC_Z,\
    KC_U, KC_V, KC_W, KC_X,\
    KC_W, KC_X, KC_Y, KC_Z,\
    KC_Y, KC_Z, KC_0, KC_1,\
    KC_0, KC_1, KC_2, KC_3,\
    KC_2, KC_3, KC_4, KC_5\
    )
};



bool process_record_user(uint16_t keycode, keyrecord_t *record) {

  switch(keycode) {
    case KC_VOLU:
      if(record->event.pressed) {
        render_action_icon(ICO_SPEAKER, ICO_UP);
      }      
      return true;

    case KC_VOLD:
      if(record->event.pressed) {
        render_action_icon(ICO_SPEAKER, ICO_DOWN);        
      }
      return true;

      case RGB_HUI:
        render_action_icon(ICO_HUE, ICO_UP);
        return true;
      
      case RGB_HUD:
        render_action_icon(ICO_HUE, ICO_DOWN);
        return true;

      case RGB_SAI:
        render_action_icon(ICO_SAT, ICO_UP);
        return true;
      
      case RGB_SAD:
        render_action_icon(ICO_SAT, ICO_DOWN);
        return true;

      case RGB_VAI:
        render_action_icon(ICO_BRIGHTNESS, ICO_UP);
        return true;

      case RGB_VAD:
        render_action_icon(ICO_BRIGHTNESS, ICO_DOWN);
        return true;      
    }      
  
  return true;
}

#ifdef OLED_ENABLE

void render_logo(void) {
  oled_timer = timer_read();
  for(uint8_t i = 0; i < ICO_WIDTH; i++) {  
    oled_set_cursor(((oled_max_chars() / 2) - (ICO_LOGO_WIDTH / 2) + 1), (oled_max_lines() / 2) - ICO_WIDTH + i);  
    for(uint8_t j = 0; j < ICO_LOGO_WIDTH; j++) {
      oled_write_char(ICO_LOGO + ((i * CHARS_PER_LINE) + j), false);
    }   
  }
}

void oled_erase(void) {
  for(int i = 0; i < oled_max_chars() * oled_max_lines(); i++) {
      oled_write_char(0, false);
  }
}

bool oled_task_user(void) { 
  if(!host_keyboard_led_state().caps_lock) {
      clear_icon(0, 0);  
  }
  
  if(timer_elapsed(oled_timer) > SCREEN_TIMEOUT) {
    oled_erase();  
    if(host_keyboard_led_state().caps_lock) {
      render_icon(ICO_CAPSL, 0, 0);  
    }
  }  
  return false;
}
#endif

void render_icon(uint8_t icon, uint8_t col, uint8_t row) {
#ifdef OLED_ENABLE
  oled_timer = timer_read();
  for(uint8_t i = 0; i < ICO_WIDTH; i++) {
    oled_set_cursor(col, row + i);
    for(uint8_t j = 0; j < ICO_WIDTH; j++) {
      oled_write_char(icon + ((i * CHARS_PER_LINE) + j), false);
    }   
  }
#endif
}

void render_icon_center(uint8_t icon) {
#ifdef OLED_ENABLE
    render_icon(icon, ((oled_max_chars() / 2) - (ICO_WIDTH / 2)), (oled_max_lines() / 2) - (ICO_WIDTH / 2));
#endif
}

void render_action_icon(uint8_t icon, uint8_t direction) {
#ifdef OLED_ENABLE
  render_icon_center(icon);
  oled_write_char(0, false);
  oled_write_char(direction, false);
#endif
}

void clear_icon(uint8_t col, uint8_t row) {
#ifdef OLED_ENABLE
  for(uint8_t i = 0; i < ICO_WIDTH; i++) {
      oled_set_cursor(col, row + i);
      for(uint8_t j = 0; j < ICO_WIDTH; j++) {
        oled_write_char(0, false);
      }   
    } 
#endif
}


void keyboard_post_init_user(void) {
#ifdef CONSOLE_ENABLE
  // Customise these values to desired behaviour
  debug_enable=true;
  debug_matrix=true;
  debug_keyboard=true;
#endif

#ifdef OLED_ENABLE
  oled_off();
#endif
#ifdef BOOT_ANIM_ENABLED
 #ifdef RGBLIGHT_ENABLE
  rgblight_setrgb_range(0, 0, 0, 0, RGBLED_NUM);

  for(uint8_t i = 0;i < RGBLED_NUM;i++) {
    rgblight_setrgb_range(255, 255, 255, 0, i);
    wait_ms(BOOT_ANIM_DELAY);
  }
  rgblight_reload_from_eeprom();
  #endif
#endif
#ifdef OLED_ENABLE
  render_logo();  
#endif  

}