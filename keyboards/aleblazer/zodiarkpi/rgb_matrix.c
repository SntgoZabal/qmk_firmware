#include QMK_KEYBOARD_H

#ifdef RGB_MATRIX_ENABLE

#include "rgb_matrix_kb.inc"

// Define custom keyboard effect
bool rgb_matrix_indicators_kb(void) {
    // Clear existing effects
    rgb_matrix_set_color_all(0, 0, 0);

    // Set color based on Caps Lock state
    if (host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK)) {
        rgb_matrix_set_color(0, 255, 0, 0);  // Set key at index 0 to red
    }
    return false;
}

bool rgb_matrix_indicators_advanced_kb(uint8_t led_min, uint8_t led_max) {
    if (rgb_matrix_indicators_kb()) {
        return true;
    }
    return false;
}

#endif
