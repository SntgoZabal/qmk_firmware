// !!! DO NOT ADD #pragma once !!! //

// Step 1.
// Declare custom effects using the RGB_MATRIX_EFFECT macro
// (note the lack of semicolon after the macro!)
RGB_MATRIX_EFFECT(SZV_EFFECT_0)

// Step 2.
// Define effects inside the `RGB_MATRIX_CUSTOM_EFFECT_IMPLS` ifdef block
#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

typedef struct {
    uint8_t index;
    HSV color;
} led_override_t;

// Define the list of LEDs to override and their static colors
static const led_override_t led_overrides[] = {
    {0, {HSV_RED, 199, 199}},    // LED 0 with red color
    {5, {HSV_BLUE, 199, 199}},   // LED 5 with blue color
    // Add more LEDs and colors as needed
};
static const size_t num_led_overrides = sizeof(led_overrides) / sizeof(led_overrides[0]);

// Function to check if an LED is in the override list
static bool is_led_overridden(uint8_t i, HSV* color) {
    for (size_t j = 0; j < num_led_overrides; j++) {
        if (led_overrides[j].index == i) {
            *color = led_overrides[j].color;
            return true;
        }
    }
    return false;
}

static HSV SZV_EFFECT_0_math(HSV hsv, uint8_t i, uint8_t time) {
// Check if the current LED should be overridden
    HSV override_color;
    if (is_led_overridden(i, &override_color)) {
        return override_color;  // Return the static color for the overridden LED
    }
    
    // Original effect logic for non-overridden LEDs
    int16_t s = hsv.s - abs(scale8(g_led_config.point[i].x, 228) + 28 - time) * 8;
    hsv.s     = scale8(s < 0 ? 0 : s, hsv.s);
    return hsv;
}

bool SZV_EFFECT_0(effect_params_t* params) {
    return effect_runner_i(params, &SZV_EFFECT_0_math);
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
