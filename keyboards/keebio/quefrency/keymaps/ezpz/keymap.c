#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BASE 0
#define _FN1 1

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_65_with_macro(
    KC_MEDIA_PLAY_PAUSE,   KC_GESC, KC_GRAVE, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_DEL,  KC_BSPC, KC_WWW_BACK, \
    KC_MEDIA_PREV_TRACK,   KC_MEDIA_NEXT_TRACK,   KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_PGUP, \
    KC_MEDIA_PLAY_PAUSE,   KC_MUTE,   KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,  KC_PGDN, \
    KC_BRIGHTNESS_DOWN,   KC_BRIGHTNESS_UP,   KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,   KC_PRINT_SCREEN, \
    KC_NO,   KC_NO,  KC_LCTL, KC_LGUI, KC_LALT, MO(_FN1),KC_SPC,           MO(_FN1),KC_SPC,  MO(_FN1), KC_RCTL, KC_RGUI, KC_LEFT, KC_DOWN, KC_RGHT
  ),

  [_FN1] = LAYOUT_65_with_macro(
    KC_KB_MUTE, _______, KC_GESC, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  KC_DEL, KC_WWW_FORWARD, \
    KC_P7, KC_P8, RGB_TOG, RGB_MOD, _______, KC_UP,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_P9, \
    KC_P4, KC_P5, _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, _______, _______, _______, _______, KC_P6, \
    KC_P1, KC_P2, _______, RGB_HUI, RGB_SAI, RGB_VAI, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_P3, \
    _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______, _______
  )
};

/*

if(IS_LAYER_ON(0)) {
  configure function for each layer
}
 */

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    else if (index == 1) {
      if (IS_LAYER_ON(0)) {
        if (clockwise) {
            tap_code16(KC_MS_WH_DOWN);
        } else {
            tap_code16(KC_MS_WH_UP);
        }
      } else if (IS_LAYER_ON(1)) {
        if (clockwise) {
            tap_code16(KC_MS_LEFT);
        } else {
            tap_code16(KC_MS_RIGHT);
        }
      }
        
    }
    return true;
}
