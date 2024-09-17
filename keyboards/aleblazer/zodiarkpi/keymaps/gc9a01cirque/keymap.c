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
#include "unicode.h"
#include "zodiarkpi.h"

void pointing_device_init_user(void) {
    //set_auto_mouse_layer(<mouse_layer>); // only required if AUTO_MOUSE_DEFAULT_LAYER is not set to index of <mouse_layer>
    set_auto_mouse_enable(true);         // always required before the auto mouse feature will work
}

enum custom_keycodes {
    KB_MODE0 = SAFE_RANGE,
    KB_MODE1,
    KB_MODE2,
    KB_MODE3,
    KB_ACCENT_MAC,
    KB_SPACELEFT,
    KB_SPACERGHT,
    RGB_ANIM_SPEED_UP,
    RGB_ANIM_SPEED_DOWN,
    RGB_SPEEDI,
    RGB_SPEEDD,
    RGB_HUEI,
    RGB_HUED,
    RGB_VALUEI,
    RGB_VALUED,
    RGB_SATURATIONI,
    RGB_SATURATIOND
};

/*
void keyboard_post_init_user(void) {
    // Set the default RGB effect
    rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_SZV_EFFECT_0);
}
*/

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    //static bool accent_tilde_mode = false;
    //static uint16_t vowel_timer;

    switch (keycode) {
        case KB_MODE0:
            if (record->event.pressed) {
                // Switch to layer 0
                layer_move(0);
                // Switch to custom effect 0
                //rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_SZV_EFFECT_0);
                // Change image
                set_layout_mode(KB_MODE_0);
            }
            return false;

        case KB_MODE1:
            if (record->event.pressed) {
                // Switch to layer 1
                layer_move(1);
                // Switch to custom effect 1
                //rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_SZV_EFFECT_1);
                // Change image
                set_layout_mode(KB_MODE_1);
            }
            return false;
        
        case KB_MODE2:
            if (record->event.pressed) {
                // Switch to layer 2
                layer_move(2);
                // Switch to custom effect 2
                //rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_SZV_EFFECT_2);
                // Change image
                set_layout_mode(KB_MODE_2);
            }
            return false;
        
        case KB_MODE3:
            if (record->event.pressed) {
                // Switch to layer 3
                layer_move(3);
                // Switch to custom effect 3
                //rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_SZV_EFFECT_3);
                // Change image
                set_layout_mode(KB_MODE_3);
            }
            return false;

        /*
        case KB_ACCENT:
            if (record->event.pressed) {
                if (get_mods() & MOD_BIT(KC_LSFT) || get_mods() & MOD_BIT(KC_RSFT)) {
                    // Shift key is held, set accent_tilde_mode to true for tilde
                    accent_tilde_mode = true;
                } else {
                    // Shift key is not held, set accent_tilde_mode to false for accent
                    accent_tilde_mode = false;
                }
                vowel_timer = timer_read();
            }
            return false;
        */
        case KB_ACCENT_MAC:
            if (record->event.pressed) {
                uint8_t mods = get_mods();  // Store the current modifier state
                // Check if the Shift key is held
                if (mods & MOD_MASK_SHIFT) {
                    // Temporarily unregister Shift for the tilde (~)
                    del_mods(MOD_MASK_SHIFT);
                    register_code(KC_RALT);  // Hold down Right Alt
                    tap_code(KC_N);          // Tap the N key (Option + N for tilde)
                    unregister_code(KC_RALT);  // Release Right Alt
                    set_mods(mods);  // Restore the original modifier state, including Shift
                } else {
                    // Send acute accent (´) if Shift is not held
                    register_code(KC_RALT);  // Hold down Right Alt
                    tap_code(KC_E);          // Tap the E key (Option + E for accent)
                    unregister_code(KC_RALT);  // Release Right Alt
                }
            }
            return false; // Skip further processing

        case KB_SPACELEFT
            if (record->event.pressed) {
                uint8_t mods = get_mods();  // Store the current modifier state
                register_code(KC_RCTL);  // Hold down Right Ctl
                tap_code(KC_LEFT);          // Tap the left arrow key (Control + Left for tilde)
                unregister_code(KC_RCTL);  // Release Right Ctl
                set_mods(mods);  // Restore the original modifier state, including Shift
            }
            return false; // Skip further processing

        case KB_SPACERGHT
            if (record->event.pressed) {
                uint8_t mods = get_mods();  // Store the current modifier state
                register_code(KC_RCTL);  // Hold down Right Ctl
                tap_code(KC_RGHT);          // Tap the right arrow key (Control + Right for tilde)
                unregister_code(KC_RCTL);  // Release Right Ctl
                set_mods(mods);  // Restore the original modifier state, including Shift
            }
            return false; // Skip further processing
        
        case RGB_ANIM_SPEED_UP:
            if (record->event.pressed) {
                if (rgb_matrix_config.animation_speed < 255) {
                    rgb_matrix_config.animation_speed += 2;
                }
                eeconfig_update_rgb_matrix();  // Save the new speed to EEPROM
                rgb_matrix_enable_noeeprom();  // Apply changes without saving to EEPROM again
            }
            return false;
        case RGB_ANIM_SPEED_DOWN:
            if (record->event.pressed) {
                if (rgb_matrix_config.animation_speed > 0) {
                    rgb_matrix_config.animation_speed -= 2;
                }
                eeconfig_update_rgb_matrix();  // Save the new speed to EEPROM
                rgb_matrix_enable_noeeprom();  // Apply changes without saving to EEPROM again
            }
            return false;
        
        case RGB_SPEEDI:
            if (record->event.pressed) {
                if (rgb_matrix_config.speed < 255) {
                    rgb_matrix_config.speed += 2;
                }
                eeconfig_update_rgb_matrix();  // Save the new speed to EEPROM
                rgb_matrix_enable_noeeprom();  // Apply changes without saving to EEPROM again
            }
            return false;
        case RGB_SPEEDD:
            if (record->event.pressed) {
                if (rgb_matrix_config.speed > 0) {
                    rgb_matrix_config.speed -= 2;
                }
                eeconfig_update_rgb_matrix();  // Save the new speed to EEPROM
                rgb_matrix_enable_noeeprom();  // Apply changes without saving to EEPROM again
            }
            return false;
        
        case RGB_HUEI:
            if (record->event.pressed) {
                if (rgb_matrix_config.hsv.h < 255) {
                    rgb_matrix_config.hsv.h += 2;
                }
                eeconfig_update_rgb_matrix();  // Save the new speed to EEPROM
                rgb_matrix_enable_noeeprom();  // Apply changes without saving to EEPROM again
            }
            return false;
        case RGB_HUED:
            if (record->event.pressed) {
                if (rgb_matrix_config.hsv.h > 0) {
                    rgb_matrix_config.hsv.h -= 2;
                }
                eeconfig_update_rgb_matrix();  // Save the new speed to EEPROM
                rgb_matrix_enable_noeeprom();  // Apply changes without saving to EEPROM again
            }
            return false;

        case RGB_VALUEI:
            if (record->event.pressed) {
                if (rgb_matrix_config.hsv.v < 255) {
                    rgb_matrix_config.hsv.v += 2;
                }
                eeconfig_update_rgb_matrix();  // Save the new speed to EEPROM
                rgb_matrix_enable_noeeprom();  // Apply changes without saving to EEPROM again
            }
            return false;
        case RGB_VALUED:
            if (record->event.pressed) {
                if (rgb_matrix_config.hsv.v > 0) {
                    rgb_matrix_config.hsv.v -= 2;
                }
                eeconfig_update_rgb_matrix();  // Save the new speed to EEPROM
                rgb_matrix_enable_noeeprom();  // Apply changes without saving to EEPROM again
            }
            return false;

        case RGB_SATURATIONI:
            if (record->event.pressed) {
                if (rgb_matrix_config.hsv.s < 255) {
                    rgb_matrix_config.hsv.s += 2;
                }
                eeconfig_update_rgb_matrix();  // Save the new speed to EEPROM
                rgb_matrix_enable_noeeprom();  // Apply changes without saving to EEPROM again
            }
            return false;
        case RGB_SATURATIOND:
            if (record->event.pressed) {
                if (rgb_matrix_config.hsv.s > 0) {
                    rgb_matrix_config.hsv.s -= 2;
                }
                eeconfig_update_rgb_matrix();  // Save the new speed to EEPROM
                rgb_matrix_enable_noeeprom();  // Apply changes without saving to EEPROM again
            }
            return false;
        
        //default:
            /*
            if (!record->event.pressed) {
                if (timer_elapsed(vowel_timer) < TAPPING_TERM) {
                    // Check if the key is a vowel and apply the accent/tilde
                    if (accent_tilde_mode) {
                        
                        register_unicode(0x0303);
                        
                    } else {
                        
                        register_unicode(0x0301);
                        
                    }
                }
            }
            */
            
        break;
        
    }
    return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    //Windows Keyboard
    [0] = LAYOUT(
      KC_ESC,    KC_1,        KC_2,         KC_3,      KC_4,           KC_5,                                                             KC_6,       KC_7,        KC_8,        KC_9,       KC_0,                  KC_BSPC,
      KC_TAB,    KC_Q,        KC_W,         KC_E,      KC_R,           KC_T,                                                             KC_Y,       KC_U,        KC_I,        KC_O,       KC_P,                  KC_LBRC,
      KC_CAPS,   KC_A,        KC_S,         KC_D,      KC_F,           KC_G,     KC_ENT,     KC_MUTE,          RGB_TOG,     KC_ENT,      KC_H,       KC_J,        KC_K,        KC_L,       KC_SCLN,               KC_RBRC,
      KC_LSFT,   KC_Z,        KC_X,         KC_C,      KC_V,           KC_B,     KC_LCTL,    KC_LALT,          KC_EQL,      KC_MINS,     KC_N,       KC_M,        KC_COMM,     KC_DOT,     KC_SLSH,               KC_GRAVE,
      KB_MODE0,  KB_MODE1,    KB_MODE2,     KB_MODE3,  KC_QUOTE,            KC_SPC,          KC_LGUI,          KC_RGUI,           KC_SPC,            KC_LEFT,     KC_UP,       KC_DOWN,    KC_RGHT,               KC_BSLS
    ),

    //Apple Keyboard
	[1] = LAYOUT(
      _______,   _______,     _______,      _______,   _______,        _______,                                                             _______,    _______,     _______,     _______,    _______,               _______,
      _______,   _______,     _______,      _______,   _______,        _______,                                                             _______,    _______,     _______,     _______,    _______,               _______,   
      _______,   _______,     _______,      _______,   _______,        _______,  _______,    _______,          _______,        _______,     _______,    _______,     _______,     _______,    _______,               _______,
      _______,   _______,     _______,      _______,   _______,        _______,  KC_LGUI,    _______,          _______,        _______,     _______,    _______,     _______,     _______,    _______,               KC_QUOTE,
      KB_MODE0,  KB_MODE1,    KB_MODE2,     KB_MODE3,  KB_ACCENT_MAC,       _______,         KC_LCTL,          _______,              _______,           _______,     _______,     _______,    _______,               _______
      ),

    //Mouse & NumPad
	[2] = LAYOUT(
      KC_ESC,    KC_F1,       KC_F2,        KC_F3,     KC_F4,          KC_F5,                                                               KC_F6,      KC_F7,       KC_F8,       KC_F9,      KC_F10,                KC_BSPC,
      KC_PSCR,   _______,     _______,      _______,   _______,        _______,                                                             KC_NUM,     KC_P7,       KC_P8,       KC_P9,      KC_KP_ASTERISK,        KC_F11,   
      KC_MPLY,   _______,     _______,      _______,   _______,        _______,  _______,    _______,          _______,        _______,     KC_PSLS,    KC_P4,       KC_P5,       KC_P6,      KC_KP_MINUS,           KC_F12,
      _______,   _______,     _______,      _______,   _______,        _______,  _______,    _______,          _______,        _______,     _______,    KC_P1,       KC_P2,       KC_P3,      KC_KP_PLUS,            _______,
      KB_MODE0,  KB_MODE1,    KB_MODE2,     KB_MODE3,  _______,             _______,         KC_SLEP,          _______,              _______,           KC_P0,       KC_PDOT,     KC_PENT,    _______,               _______
      ),

    //RGB Settings
	[3] = LAYOUT(
      QK_BOOT,   KC_F1,       KC_F2,        KC_F3,     KC_F4,          KC_F5,                                                               KC_F6,      KC_F7,       KC_F8,       KC_F9,      KC_F10,                KC_BSPC,
      _______,   _______,     _______,      _______,   _______,        _______,                                                             _______,    _______,     _______,     _______,    RGB_ANIM_SPEED_UP,     KC_F11,
      _______,   _______,     _______,      _______,   _______,        _______,  _______,    _______,          _______,        _______,     _______,    RGB_TOG,     _______,     _______,    RGB_ANIM_SPEED_DOWN,   KC_F12,
      _______,   _______,     _______,      _______,   _______,        _______,  _______,    _______,          _______,        _______,     _______,    RGB_MOD,     RGB_SPEEDI,  RGB_HUEI,   RGB_SATURATIONI,       RGB_VALUEI,
      KB_MODE0,  KB_MODE1,    KB_MODE2,     KB_MODE3,  _______,             _______,         _______,          _______,              _______,           RGB_RMOD,    RGB_SPEEDD,  RGB_HUED,   RGB_SATURATIOND,       RGB_VALUED
      ),

    //Mouse Layer
    [4] = LAYOUT(
      _______,   _______,     _______,      _______,   _______,        _______,                                                             _______,    _______,     _______,     _______,    _______,               _______,
      _______,   _______,     _______,      _______,   _______,        _______,                                                             _______,    _______,     _______,     _______,    _______,               _______,   
      _______,   _______,     _______,      _______,   _______,        _______,  _______,    _______,          _______,        _______,     _______,    _______,     _______,     _______,    _______,               _______,
      _______,   _______,     _______,      _______,   _______,        _______,  _______,    _______,          KC_MS_BTN1,     KC_MS_BTN2,  _______,    _______,     _______,     _______,    _______,               _______,
      KB_MODE0,  KB_MODE1,    KB_MODE2,     KB_MODE3,  _______,             _______,         _______,          KB_SPACELEFT,         KB_SPACERGHT,      _______,     _______,     _______,    _______,               _______
      )

};
