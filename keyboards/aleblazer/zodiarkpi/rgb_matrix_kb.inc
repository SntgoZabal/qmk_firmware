// !!! DO NOT ADD #pragma once !!! //

// Step 1.
// Declare custom effects using the RGB_MATRIX_EFFECT macro
// (note the lack of semicolon after the macro!)
RGB_MATRIX_EFFECT(SZV_EFFECT_0)
RGB_MATRIX_EFFECT(SZV_EFFECT_1)

// Step 2.
// Define effects inside the `RGB_MATRIX_CUSTOM_EFFECT_IMPLS` ifdef block
#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

typedef struct {
    uint8_t index;
    HSV color;
} led_override_t;

// Define the list of LEDs to override and their static colors for SZV_EFFECT_0
static const led_override_t led_overrides_0[] = {
    {43, {HSV_CYAN}},    // F1 LED in Cyan
    {41, {HSV_WHITE}},    // F2 LED in White
    {40, {HSV_WHITE}},    // F3 LED in White
    {38, {HSV_WHITE}},    // F4 LED in White
    // Add more LEDs and colors as needed
};
static const size_t num_led_overrides_0 = sizeof(led_overrides_0) / sizeof(led_overrides_0[0]);

// Define the list of LEDs to override and their static colors for SZV_EFFECT_1
static const led_override_t led_overrides_1[] = {
    {43, {HSV_WHITE}},    // F1 LED in White
    {41, {HSV_CYAN}},    // F2 LED in Cyan
    {40, {HSV_WHITE}},    // F3 LED in White
    {38, {HSV_WHITE}},    // F4 LED in White
    // Add more LEDs and colors as needed
};

static const size_t num_led_overrides_1 = sizeof(led_overrides_1) / sizeof(led_overrides_1[0]);

// Function to check if an LED is in the override list for SZV_EFFECT_0
static bool is_led_overridden_0(uint8_t i, HSV* color) {
    for (size_t j = 0; j < num_led_overrides_0; j++) {
        if (led_overrides_0[j].index == i) {
            *color = led_overrides_0[j].color;
            return true;
        }
    }
    return false;
}

// Function to check if an LED is in the override list for SZV_EFFECT_1
static bool is_led_overridden_1(uint8_t i, HSV* color) {
    for (size_t j = 0; j < num_led_overrides_1; j++) {
        if (led_overrides_1[j].index == i) {
            *color = led_overrides_1[j].color;
            return true;
        }
    }
    return false;
}

// Math function for SZV_EFFECT_0
static HSV SZV_EFFECT_0_math(HSV hsv, uint8_t i, uint8_t time) {
    // Check if the current LED should be overridden
    HSV override_color;
    if (is_led_overridden_0(i, &override_color)) {
        return override_color;  // Return the static color for the overridden LED
    }
    
    // Original effect logic for non-overridden LEDs
    int16_t s = hsv.s - abs(scale8(g_led_config.point[i].x, 228) + 28 - time) * 8;
    hsv.s     = scale8(s < 0 ? 0 : s, hsv.s);
    return hsv;
}

// Math function for SZV_EFFECT_1
static HSV SZV_EFFECT_1_math(HSV hsv, uint8_t i, uint8_t time) {
    // Check if the current LED should be overridden
    HSV override_color;
    if (is_led_overridden_1(i, &override_color)) {
        return override_color;  // Return the static color for the overridden LED
    }
    
    // Original effect logic for non-overridden LEDs
    int16_t s = hsv.s - abs(scale8(g_led_config.point[i].x, 228) + 28 - time) * 8;
    hsv.s     = scale8(s < 0 ? 0 : s, hsv.s);
    return hsv;
}

// Effect runner for SZV_EFFECT_0
bool SZV_EFFECT_0(effect_params_t* params) {
    return effect_runner_i(params, &SZV_EFFECT_0_math);
}

// Effect runner for SZV_EFFECT_1
bool SZV_EFFECT_1(effect_params_t* params) {
    return effect_runner_i(params, &SZV_EFFECT_1_math);
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
