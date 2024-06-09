// !!! DO NOT ADD #pragma once !!! //

// Step 1.
// Declare custom effects using the RGB_MATRIX_EFFECT macro
// (note the lack of semicolon after the macro!)
RGB_MATRIX_EFFECT(SZV_EFFECT_0)

// Step 2.
// Define effects inside the `RGB_MATRIX_CUSTOM_EFFECT_IMPLS` ifdef block
#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

static HSV SZV_EFFECT_0_math(HSV hsv, uint8_t i, uint8_t time) {
    int16_t s = hsv.s - abs(scale8(g_led_config.point[i].x, 228) + 28 - time) * 8;
    hsv.s     = scale8(s < 0 ? 0 : s, hsv.s);
    return hsv;
}

bool SZV_EFFECT_0(effect_params_t* params) {
    return effect_runner_i(params, &SZV_EFFECT_0_math);
}

#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS
