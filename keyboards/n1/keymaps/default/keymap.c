/* Copyright 2021 Nick Bowkett
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

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _CAPS_A,
    _MOV,
    _NUM,
    _LOWER,
    _RAISE,
    _GAME,
    _CAPS_B,
    _ADJUST
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    ENT_CAPS = SAFE_RANGE,
    EXT_CAPS,
    RAISE,
    LOWER
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* Adjust */
    [_ADJUST] = LAYOUT(
        DEBUG,   _______, _______, _______, _______, _______, _______, TERM_ON,   TERM_OFF, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, TG(_GAME), _______,  _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______,   _______,  _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______,   _______,  _______, _______, _______
    ),

    /* Caps B */
    [_CAPS_B] = LAYOUT(
        EXT_CAPS, _______,  _______,  _______,  _______, _______,  _______,  _______, _______, _______, _______,  _______,
        EXT_CAPS, _______,  _______,  _______,  _______, _______,  _______,  _______, _______, _______, EXT_CAPS, EXT_CAPS,
        _______,  _______,  _______,  _______,  _______, _______,  _______,  _______, _______, _______, EXT_CAPS, EXT_CAPS,
        _______,  EXT_CAPS, EXT_CAPS, EXT_CAPS, _______, EXT_CAPS, EXT_CAPS, _______, _______, _______, _______,  _______
    ),

    /* Game */
    [_GAME] = LAYOUT(
        _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        MOD_LSFT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        _______,  _______, _______, XXXXXXX, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    /* Raise */
    [_RAISE] = LAYOUT(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
        KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
        _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, KC_MPLY, KC_VOLD, KC_VOLU, KC_MNXT
    ),

    /* Lower */
    [_LOWER] = LAYOUT(
        KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_DEL,
        KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS,    KC_PLUS,    KC_LCBR, KC_RCBR, KC_PIPE,
        _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  S(KC_NUHS), S(KC_NUBS), KC_HOME, KC_END,  KC_INS,
        _______, _______, _______, _______, _______, _______, _______, _______,    KC_MPLY,    KC_VOLD, KC_VOLU, KC_MNXT
    ),

    [_NUM] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, KC_7,    KC_8,    KC_9,   _______, _______,
        _______, _______, _______, _______, _______, _______, _______, KC_4,    KC_5,    KC_6,   _______, _______,
        _______, _______, _______, _______, _______, _______, _______, KC_1,    KC_2,    KC_3,   _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, KC_0,    KC_DOT, _______, _______
    ),

    [_MOV] = LAYOUT(
        _______,  _______, _______, _______, _______, _______, _______, _______, KC_UP,   _______,  KC_PGUP, _______,
        ENT_CAPS, _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN, KC_RIGHT, KC_PGDN, _______,
        _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______,
        _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______
    ),

    /* Caps A */
    [_CAPS_A] = LAYOUT(
        _______,  S(KC_Q), S(KC_W), S(KC_E), S(KC_R), S(KC_T), S(KC_Y), S(KC_U), S(KC_I), S(KC_O), S(KC_P), _______,
        _______,  S(KC_A), S(KC_S), S(KC_D), S(KC_F), S(KC_G), S(KC_H), S(KC_J), S(KC_K), S(KC_L), _______, _______,
        _______,  S(KC_Z), S(KC_X), S(KC_C), S(KC_V), S(KC_B), S(KC_N), S(KC_M), _______, _______, _______, _______,
        _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),

    /* Base */
    [_BASE] = LAYOUT(
        KC_TAB,        KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,              KC_O,    KC_P,    KC_BSPC,
        KC_ESC,        KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,              KC_L,    KC_SCLN, KC_QUOT,
        OSM(MOD_LSFT), KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM,           KC_DOT,  KC_SLSH, MT(MOD_RSFT, KC_ENT),
        MO(_NUM),      KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   LT(_MOV, KC_LEFT), KC_DOWN, KC_UP,   KC_RGHT
    )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case ENT_CAPS:
            if (record->event.pressed) {
                layer_on(_CAPS_A);
                layer_on(_CAPS_B);
                return false;
            }
        case EXT_CAPS:
            if (record->event.pressed) {
                layer_off(_CAPS_A);
                layer_off(_CAPS_B);
                return true;
            }
        case LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
        return false;
    }
    return true;
}
