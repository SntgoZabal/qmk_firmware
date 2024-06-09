/*
Copyright 2023 Spencer Deven <splitlogicdesign@gmail.com>
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

enum custom_keycodes {
    KB_MODE0 = SAFE_RANGE,
    KB_MODE1,
    KB_MODE2,
    KB_MODE3
};

#ifdef RGB_MATRIX_ENABLE

#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KB_MODE0:
            if (record->event.pressed) {
                // Switch to layer 0
                layer_move(0);
                // Switch to custom effect 0
                rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_SZV_EFFECT_0);
            }
            return false;

        case KB_MODE1:
            if (record->event.pressed) {
                // Switch to layer 1
                layer_move(1);
                // Switch to custom effect 1
                rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_SZV_EFFECT_1);
            }
            return false;
    }
    return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT(
      KC_ESC,    KC_1,        KC_2,         KC_3,      KC_4,       KC_5,                                                             KC_6,       KC_7,        KC_8,        KC_9,       KC_0,       KC_BSPC,
      KC_MPLY,   KC_Q,        KC_W,         KC_E,      KC_R,       KC_T,                                                             KC_Y,       KC_U,        KC_I,        KC_O,       KC_P,       KC_LBRC,
      KC_PSCR,   KC_A,        KC_S,         KC_D,      KC_F,       KC_G,     KC_RSFT,    KC_MUTE,          RGB_TOG,     KC_ENT,      KC_H,       KC_J,        KC_K,        KC_L,       KC_SCLN,    KC_RBRC,
      KC_LSFT,   KC_Z,        KC_X,         KC_C,      KC_V,       KC_B,     KC_LCTL,    KC_LALT,          KC_EQL,      KC_MINS,     KC_N,       KC_M,        KC_COMM,     KC_DOT,     KC_SLSH,    KC_QUOT,
      KB_MODE0,     KB_MODE1,       TO(2),        TO(3),     KC_GRV,          KC_TAB,          KC_SLEP,          KC_ENT,            KC_SPC,            KC_LEFT,     KC_UP,       KC_DOWN,    KC_RGHT,    KC_BSLS
    ),

	[1] = LAYOUT(
      KC_ESC,    KC_F1,       KC_F2,        KC_F3,     KC_F4,      KC_F5,                                                            KC_F6,      KC_F7,       KC_F8,       KC_F9,      KC_F10,     KC_BSPC,
      _______,   _______,     _______,      _______,   _______,    _______,                                                          KC_NUM,     KC_P7,       KC_P8,       KC_P9,      _______,    KC_F11,   
      KC_CAPS,   _______,     _______,      _______,   _______,    _______,  _______,    _______,          _______,     _______,     KC_PSLS,    KC_P4,       KC_P5,       KC_P6,      _______,    KC_F12,
      _______,   _______,     _______,      _______,   _______,    _______,  _______,    _______,          _______,     _______,     _______,    KC_P1,       KC_P2,       KC_P3,      _______,    _______,
      KB_MODE0,     KB_MODE1,       TO(2),        TO(3),     _______,         _______,         _______,          _______,           _______,           KC_P0,       KC_PDOT,     KC_PENT,    _______,    _______
      ),

	[2] = LAYOUT(
      KC_ESC,    KC_F1,       KC_F2,        KC_F3,     KC_F4,      KC_F5,                                                            KC_F6,      KC_F7,       KC_F8,       KC_F9,      KC_F10,     KC_BSPC,
      _______,   _______,     _______,      _______,   _______,    _______,                                                          KC_NUM,     KC_P7,       KC_P8,       KC_P9,      _______,    KC_F11,   
      KC_CAPS,   _______,     _______,      _______,   _______,    _______,  _______,    _______,          _______,     _______,     KC_PSLS,    KC_P4,       KC_P5,       KC_P6,      _______,    KC_F12,
      _______,   _______,     _______,      _______,   _______,    _______,  _______,    _______,          _______,     _______,     _______,    KC_P1,       KC_P2,       KC_P3,      _______,    _______,
      KB_MODE0,     KB_MODE1,       TO(2),        TO(3),     _______,         _______,         _______,          _______,           _______,           KC_P0,       KC_PDOT,     KC_PENT,    _______,    _______
      ),

	[3] = LAYOUT(
      QK_BOOT,   KC_F1,       KC_F2,        KC_F3,     KC_F4,      KC_F5,                                                            KC_F6,      KC_F7,       KC_F8,       KC_F9,      KC_F10,     KC_F11,
      _______,   _______,     _______,      _______,   _______,    _______,                                                          _______,    _______,     _______,     _______,    _______,    KC_F12,
      _______,   KB_MODE0,    _______,      _______,   _______,    _______,  _______,    _______,          _______,     _______,     _______,    RGB_TOG,     _______,     _______,    _______,    _______,
      _______,   KB_MODE1,    _______,      _______,   _______,    _______,  _______,    _______,          _______,     _______,     _______,    RGB_MOD,     RGB_SPI,     RGB_HUI,    RGB_SAI,    RGB_VAI,
      KB_MODE0,     KB_MODE1,       TO(2),        TO(3),     _______,         _______,         _______,          _______,           _______,           RGB_RMOD,    RGB_SPD,     RGB_HUD,    RGB_SAD,    RGB_VAD
      )

};
