// !!! DO NOT ADD #pragma once !!! //

// Step 1.
// Declare custom effects using the RGB_MATRIX_EFFECT macro
// (note the lack of semicolon after the macro!)
RGB_MATRIX_EFFECT(SZV_EFFECT_0)
RGB_MATRIX_EFFECT(SZV_EFFECT_1)
RGB_MATRIX_EFFECT(SZV_EFFECT_2)
RGB_MATRIX_EFFECT(SZV_EFFECT_3)
RGB_MATRIX_EFFECT(SZV_EFFECT_4)

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
    {57, {HSV_CYAN}},    // U LED in Cyan
    {56, {HSV_CYAN}},    // I LED in Cyan
    {55, {HSV_CYAN}},    // O LED in Cyan
    {62, {HSV_CYAN}},    // J LED in Cyan
    {63, {HSV_CYAN}},    // K LED in Cyan
    {65, {HSV_CYAN}},    // L LED in Cyan
    {73, {HSV_CYAN}},    // M LED in Cyan
    {72, {HSV_CYAN}},    // , LED in Cyan
    {71, {HSV_CYAN}},    // . LED in Cyan
    {81, {HSV_CYAN}},    // LEFT LED in Cyan
    {82, {25,210,255}},    // UP LED in Yellow
    {84, {25,210,255}},    // DOWN LED in Yellow
    {58, {25,210,255}},    // Y LED in Yellow
    {61, {25,210,255}},    // H LED in Yellow
    {24, {25,210,255}},    // CAPS LED in Yellow
    // Add more LEDs and colors as needed
};

static const size_t num_led_overrides_1 = sizeof(led_overrides_1) / sizeof(led_overrides_1[0]);

// Define the list of LEDs to override and their static colors for SZV_EFFECT_2
static const led_override_t led_overrides_2[] = {
    {43, {HSV_WHITE}},    // F1 LED in White
    {41, {HSV_WHITE}},    // F2 LED in White
    {40, {HSV_CYAN}},    // F3 LED in Cyan
    {38, {HSV_WHITE}},    // F4 LED in White
    {57, {HSV_CYAN}},    // U LED in Cyan
    {56, {HSV_CYAN}},    // I LED in Cyan
    {55, {HSV_CYAN}},    // O LED in Cyan
    {62, {HSV_CYAN}},    // J LED in Cyan
    {63, {HSV_CYAN}},    // K LED in Cyan
    {65, {HSV_CYAN}},    // L LED in Cyan
    {73, {HSV_CYAN}},    // M LED in Cyan
    {72, {HSV_CYAN}},    // , LED in Cyan
    {71, {HSV_CYAN}},    // . LED in Cyan
    {81, {HSV_CYAN}},    // LEFT LED in Cyan
    {82, {25,210,255}},    // UP LED in Yellow
    {84, {25,210,255}},    // DOWN LED in Yellow
    {58, {25,210,255}},    // Y LED in Yellow
    {61, {25,210,255}},    // H LED in Yellow
    {24, {25,210,255}},    // CAPS LED in Yellow
    // Add more LEDs and colors as needed
};
static const size_t num_led_overrides_2 = sizeof(led_overrides_2) / sizeof(led_overrides_2[0]);

// Define the list of LEDs to override and their static colors for SZV_EFFECT_3
static const led_override_t led_overrides_3[] = {
    {43, {HSV_WHITE}},    // F1 LED in White
    {41, {HSV_WHITE}},    // F2 LED in White
    {40, {HSV_WHITE}},    // F3 LED in White
    {38, {HSV_CYAN}},    // F4 LED in Cyan
    {62, {25,210,255}},    // J LED in Yellow
    {73, {25,210,255}},    // M LED in Yellow
    {72, {25,210,255}},    // , LED in Yellow
    {71, {25,210,255}},    // . LED in Yellow
    {70, {25,210,255}},    // / LED in Yellow
    {69, {25,210,255}},    // ' LED in Yellow
    {81, {25,210,255}},    // LEFT LED in Yellow
    {82, {25,210,255}},    // UP LED in Yellow
    {84, {25,210,255}},    // DOWN LED in Yellow
    {85, {25,210,255}},    // RIGHT LED in Yellow
    {87, {25,210,255}},    // \ LED in Yellow
    {8, {HSV_RED}},    // ESC LED in Red
    {58, {HSV_RED}},    // Y LED in Red
    // Add more LEDs and colors as needed
};
static const size_t num_led_overrides_3 = sizeof(led_overrides_3) / sizeof(led_overrides_3[0]);

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

// Function to check if an LED is in the override list for SZV_EFFECT_2
static bool is_led_overridden_2(uint8_t i, HSV* color) {
    for (size_t j = 0; j < num_led_overrides_2; j++) {
        if (led_overrides_2[j].index == i) {
            *color = led_overrides_2[j].color;
            return true;
        }
    }
    return false;
}

// Function to check if an LED is in the override list for SZV_EFFECT_3
static bool is_led_overridden_3(uint8_t i, HSV* color) {
    for (size_t j = 0; j < num_led_overrides_3; j++) {
        if (led_overrides_3[j].index == i) {
            *color = led_overrides_3[j].color;
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

// Math function for SZV_EFFECT_2
static HSV SZV_EFFECT_2_math(HSV hsv, uint8_t i, uint8_t time) {
    // Check if the current LED should be overridden
    HSV override_color;
    if (is_led_overridden_2(i, &override_color)) {
        return override_color;  // Return the static color for the overridden LED
    }
    
    // Original effect logic for non-overridden LEDs
    int16_t s = hsv.s - abs(scale8(g_led_config.point[i].x, 228) + 28 - time) * 8;
    hsv.s     = scale8(s < 0 ? 0 : s, hsv.s);
    return hsv;
}

// Math function for SZV_EFFECT_3
static HSV SZV_EFFECT_3_math(HSV hsv, uint8_t i, uint8_t time) {
    // Check if the current LED should be overridden
    HSV override_color;
    if (is_led_overridden_3(i, &override_color)) {
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

// Effect runner for SZV_EFFECT_2
bool SZV_EFFECT_2(effect_params_t* params) {
    return effect_runner_i(params, &SZV_EFFECT_2_math);
}

// Effect runner for SZV_EFFECT_3
bool SZV_EFFECT_3(effect_params_t* params) {
    return effect_runner_i(params, &SZV_EFFECT_3_math);
}

static HSV SZV_EFFECT_4_math(HSV hsv, uint8_t i, uint8_t time) {
    // Use animation_speed to control the time offset
    time = scale8(g_rgb_timer, rgb_matrix_config.animation_speed);

    // Calculate the range of hues to cycle through
    uint8_t hue_start = hsv.h;  // Initial hue value
    uint8_t hue_end = hue_start + rgb_matrix_config.speed;  // Final hue value based on speed

    // Calculate the current hue based on position and time
    uint8_t hue_range = hue_end - hue_start;
    uint8_t y_position = g_led_config.point[i].y;
    uint8_t hue_offset = scale8(y_position, hue_range);  // Scale y-position to the hue range

    // Cycle the hue through the defined range
    hsv.h = hue_start + ((hue_offset + time) % hue_range);

    return hsv;
}

bool SZV_EFFECT_4(effect_params_t* params) {
    return effect_runner_i(params, &SZV_EFFECT_4_math);
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
