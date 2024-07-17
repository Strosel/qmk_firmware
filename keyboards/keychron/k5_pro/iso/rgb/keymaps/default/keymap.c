/* Copyright 2023 @ Keychron (https://www.keychron.com)
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
#include "keymap_swedish.h"
#include "sendstring_swedish.h"
#include "tinyexpr.h"
#include "ryu/ryu.h"

enum custom_keycodes {
    L1_L_PAR = SAFE_RANGE,
    L1_R_PAR,
    L1_EQ_REPLACE,
    L1_EQ_PRINT,
    L1_CLEAR,
};

enum layers {
    MAC_BASE,
    MAC_FN,
    WIN_BASE,
    WIN_FN,
    CALC,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [MAC_BASE] = LAYOUT_109_iso(
        KC_ESC,             KC_BRID,  KC_BRIU,  KC_MCTL,  KC_LPAD,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU, KC_SNAP,  KC_SIRI,  RGB_MOD, KC_F13,  KC_F14,  KC_F15,  KC_F16,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC, KC_INS,   KC_HOME,  KC_PGUP, KC_NUM,  KC_PSLS, KC_PAST, KC_PMNS,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,           KC_DEL,   KC_END,   KC_PGDN, KC_P7,   KC_P8,   KC_P9,   KC_PPLS,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_NUHS,  KC_ENT,                               KC_P4,   KC_P5,   KC_P6,
        KC_LSFT,  KC_NUBS,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,           KC_UP,             KC_P1,   KC_P2,   KC_P3,   KC_PENT,
        KC_LCTL,  KC_LOPTN, KC_LCMMD,                               KC_SPC,                                 KC_RCMMD, KC_ROPTN,MO(MAC_FN),KC_RCTL, KC_LEFT,  KC_DOWN,  KC_RGHT, KC_P0,            KC_PDOT        ),

    [MAC_FN] = LAYOUT_109_iso(
        _______,            KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,  _______,  _______,  RGB_TOG, _______, _______, _______, _______,
        _______,  BT_HST1,  BT_HST2,  BT_HST3,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, _______,  _______,  _______, _______, _______, _______, _______,
        RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,  _______,           _______,  _______,  _______, _______, _______, _______, _______,
        _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,                              _______, _______, _______,
        _______,  _______,  _______,  _______,  _______,  _______,  BAT_LVL,  NK_TOGG,  _______,  _______,  _______,  _______,            _______,           _______,           _______, _______, _______, _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______, _______,  _______,  _______, _______,          _______        ),

    [WIN_BASE] = LAYOUT_109_iso(
        KC_ESC,             KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,  KC_PSCR,  KC_CTANA, RGB_MOD, _______, _______, _______, TG(CALC),
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC, KC_INS,   KC_HOME,  KC_PGUP, KC_NUM,  KC_PSLS, KC_PAST, KC_PMNS,
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,           KC_DEL,   KC_END,   KC_PGDN, KC_P7,   KC_P8,   KC_P9,   KC_PPLS,
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,  KC_NUHS,  KC_ENT,                               KC_P4,   KC_P5,   KC_P6,
        KC_LSFT,  KC_NUBS,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,           KC_UP,             KC_P1,   KC_P2,   KC_P3,   KC_PENT,
        KC_LCTL,  KC_LWIN,  KC_LALT,                                KC_SPC,                                 KC_RALT,  KC_RWIN, MO(WIN_FN),KC_RCTL, KC_LEFT,  KC_DOWN,  KC_RGHT, KC_P0,            KC_PDOT        ),

    [WIN_FN] = LAYOUT_109_iso(
        _______,            KC_BRID,  KC_BRIU,  KC_TASK,  KC_FILE,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU, _______,  _______,  RGB_TOG, _______, _______, _______, _______,
        _______,  BT_HST1,  BT_HST2,  BT_HST3,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, _______,  _______,  _______, _______, _______, _______, _______,
        RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  _______,  _______,  _______,  _______,  _______,  _______,  _______,           _______,  _______,  _______, _______, _______, _______, _______,
        _______,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,                              _______, _______, _______,
        _______,  _______,  _______,  _______,  _______,  _______,  BAT_LVL,  NK_TOGG,  _______,  _______,  _______,  _______,            _______,           _______,           _______, _______, _______, _______,
        _______,  _______,  _______,                                _______,                                _______,  _______,  _______,  _______, _______,  _______,  _______, _______,          _______        ),

    [CALC] = LAYOUT_109_iso(
        XXXXXXX,            XXXXXXX, XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,        XXXXXXX,  XXXXXXX, XXXXXXX,  L1_L_PAR, L1_R_PAR,  TG(CALC),
        XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  KC_BSPC, L1_EQ_REPLACE,  XXXXXXX,  XXXXXXX, L1_CLEAR, KC_PSLS,  KC_PAST,   KC_PMNS,
        XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,           XXXXXXX,        XXXXXXX,  XXXXXXX, KC_7,     KC_8,     KC_9,      KC_PPLS,
        XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,                                    KC_4,     KC_5,     KC_6,
        XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX,   XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,            XXXXXXX,                 XXXXXXX,           KC_1,     KC_2,     KC_3,      L1_EQ_PRINT,
        XXXXXXX,  XXXXXXX,  XXXXXXX,                                XXXXXXX,                                XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,        XXXXXXX,  XXXXXXX, KC_0,               KC_DOT     ),
};

// clang-format on
// FIXME does TG(CALC) in calc go back to prev layer? Otherwise needs two calc layers

// TODO change precision via buttons & display current precision via numrow LEDs
#define PRECISION 2
bool use_float = false;
#define EXPRESSIONS_BUFF_SIZE 64
int  input_count = 0;
char expressions_buffer[EXPRESSIONS_BUFF_SIZE];

void write_char_to_buff(char c, bool send) {
    if (input_count + 1 < EXPRESSIONS_BUFF_SIZE) {
        expressions_buffer[input_count]     = c;
        expressions_buffer[input_count + 1] = '\0';
        input_count++;
        if (send) send_char(c);
    }
}

void write_str_to_buff(char *s, bool send) {
    for (int i = 0; s[i] != '\0'; i++) {
        write_char_to_buff(s[i], send);
    }
}

void clear_calc_buff(bool send) {
    use_float = false;
    for (int i = 0; i < EXPRESSIONS_BUFF_SIZE && expressions_buffer[i] != '\0'; i++) {
        expressions_buffer[i] = '\0';
        if (send) send_char('\b');
    }
    input_count = 0;
}

// TODO clear buffer on layer change
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (IS_LAYER_OFF(CALC)) return true;

    switch (keycode) {
        case KC_0:
            if (record->event.pressed) {
                write_char_to_buff('0', false);
            }
            break;
        case KC_1:
            if (record->event.pressed) {
                write_char_to_buff('1', false);
            }
            break;
        case KC_2:
            if (record->event.pressed) {
                write_char_to_buff('2', false);
            }
            break;
        case KC_3:
            if (record->event.pressed) {
                write_char_to_buff('3', false);
            }
            break;
        case KC_4:
            if (record->event.pressed) {
                write_char_to_buff('4', false);
            }
            break;
        case KC_5:
            if (record->event.pressed) {
                write_char_to_buff('5', false);
            }
            break;
        case KC_6:
            if (record->event.pressed) {
                write_char_to_buff('6', false);
            }
            break;
        case KC_7:
            if (record->event.pressed) {
                write_char_to_buff('7', false);
            }
            break;
        case KC_8:
            if (record->event.pressed) {
                write_char_to_buff('8', false);
            }
            break;
        case KC_9:
            if (record->event.pressed) {
                write_char_to_buff('9', false);
            }
            break;
        case KC_DOT:
            if (record->event.pressed) {
                write_char_to_buff('.', false);
                use_float = true;
            }
            break;
        case KC_PSLS:
            if (record->event.pressed) {
                write_char_to_buff('/', false);
                use_float = true;
            }
            break;
        case KC_PAST:
            if (record->event.pressed) {
                write_char_to_buff('*', false);
            }
            break;
        case KC_PMNS:
            if (record->event.pressed) {
                write_char_to_buff('-', false);
            }
            break;
        case KC_PPLS:
            if (record->event.pressed) {
                write_char_to_buff('+', false);
            }
            break;
        case L1_L_PAR:
            if (record->event.pressed) {
                write_char_to_buff('(', true);
            }
            return false;
        case L1_R_PAR:
            if (record->event.pressed) {
                write_char_to_buff(')', true);
            }
            return false;
        case L1_EQ_REPLACE:
            if (record->event.pressed) {
                int    error;
                double result = te_interp(expressions_buffer, &error);
                if (error != 0) {
                    write_str_to_buff("=E", true);
                    return false;
                }

                char output_string[EXPRESSIONS_BUFF_SIZE];
                d2fixed_buffered(result, use_float ? PRECISION : 0, output_string);
                clear_calc_buff(true);
                send_string(output_string);
            }
            return false;
        case L1_EQ_PRINT:
            if (record->event.pressed) {
                int    error;
                double result = te_interp(expressions_buffer, &error);
                if (error != 0) {
                    write_str_to_buff("=E", true);
                    return false;
                }

                char output_string[EXPRESSIONS_BUFF_SIZE];
                output_string[0] = '=';
                // HACK slicing
                d2fixed_buffered(result, use_float ? PRECISION : 0, &output_string[1]);
                send_string(output_string);
                clear_calc_buff(false);
            }
            return false;
        case L1_CLEAR:
            if (record->event.pressed && input_count > 0) {
                clear_calc_buff(true);
            }
            return false;
        case KC_BSPC:
            if (record->event.pressed && input_count > 0) {
                input_count--;
                expressions_buffer[input_count] = '\0';
            }
            break;
    }
    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    clear_calc_buff(false);
    if (get_highest_layer(state) == CALC) {
        rgb_matrix_mode(RGB_MATRIX_CUSTOM_my_cool_effect);
    } else {
        // TODO return to prev animation not set animation
        rgb_matrix_mode(RGB_MATRIX_BREATHING);
    }
    return state;
}
