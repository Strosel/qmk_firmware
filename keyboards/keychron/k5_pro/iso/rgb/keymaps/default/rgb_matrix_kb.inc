RGB_MATRIX_EFFECT(my_cool_effect)

#ifdef RGB_MATRIX_CUSTOM_EFFECT_IMPLS

#define CALC_LEDS 21

const uint8_t calc_leds[CALC_LEDS] = {
    17, 18,         //Macro keys (not X)
    33, 34,         //Backspace & Insert
    37, 38, 39, 40, //Numpad
    57, 58, 59, 60,
    75, 76, 77,
    92, 93, 94, 95,
    107, 108
};

//NOTE for k5 pro only, safe to assume led_min == 0
static bool my_cool_effect(effect_params_t *params) {
    RGB_MATRIX_USE_LIMITS(led_min, led_max);
    for (uint8_t i = led_min; i < led_max; i++) {
      rgb_matrix_set_color(i, 0x00, 0x00, 0x00);
    }
    for (uint8_t i = 0; i < CALC_LEDS; i++) {
        uint8_t k = calc_leds[i];
        rgb_matrix_set_color(k, 0x00, 0x00, 0xff);
    }
    // Red X macro key
    rgb_matrix_set_color(19, 0xff, 0x00, 0x00);
    return rgb_matrix_check_finished_leds(led_max);
}
#endif // RGB_MATRIX_CUSTOM_EFFECT_IMPLS

