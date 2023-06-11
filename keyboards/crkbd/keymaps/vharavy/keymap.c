/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#define MIRYOKU_LAYER_LIST \
MIRYOKU_X(ENGLISH,"Engish") \
MIRYOKU_X(SHIFT,  "Shift") \
MIRYOKU_X(BUTTON, "Button") \
MIRYOKU_X(NAV,    "Nav") \
MIRYOKU_X(NUM,    "Num") \
MIRYOKU_X(SYM,    "Sym") \
MIRYOKU_X(FUN,    "Fun")

enum miryoku_layers {
#define MIRYOKU_X(LAYER, STRING) U_##LAYER,
MIRYOKU_LAYER_LIST
#undef MIRYOKU_X
};

// Keymap

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // English
    [0] = LAYOUT_split_3x6_3(
        U_NU,             KC_Q,              KC_W,              KC_F,              KC_P,              KC_B,                                                                 KC_J,              KC_L,              KC_U,              KC_Y,              KC_SCLN,              U_NU,
        KC_ESC,           KC_A,              KC_R,              KC_S,              KC_T,              KC_G,                                                                 KC_M,              KC_N,              KC_E,              KC_I,              KC_O,                 KC_QUOTE,
        U_NU,             KC_Z,              KC_X,              KC_C,              KC_D,              KC_V,                                                                 KC_K,              KC_H,              KC_COMM,           KC_DOT,            KC_SLSH,              U_NU,
                                                                                   LT(U_SYM,KC_ESC),  LT(U_NAV,KC_BSPC), LT(U_FUN,KC_TAB),              LT(U_BUTTON,KC_ENT),LT(U_NUM,KC_SPC),  OSL(U_SHIFT)
    ),

    // Shift
    [1] = LAYOUT_split_3x6_3(
        U_NU,             S(KC_Q),           S(KC_W),           S(KC_F),           S(KC_P),           S(KC_B),                                                              S(KC_J),           S(KC_L),           S(KC_U),           S(KC_Y),           S(KC_SCLN),           U_NU,
        S(KC_ESC),        S(KC_A),           S(KC_R),           S(KC_S),           S(KC_T),           S(KC_G),                                                              S(KC_M),           S(KC_N),           S(KC_E),           S(KC_I),           S(KC_O),              S(KC_QUOTE),
        U_NU,             S(KC_Z),           S(KC_X),           S(KC_C),           S(KC_D),           S(KC_V),                                                              S(KC_K),           S(KC_H),           S(KC_COMM),        S(KC_DOT),         S(KC_SLSH),           U_NU,
                                                                                   LT(U_SYM,KC_ESC),  S(KC_BSPC),        S(KC_TAB),                     S(KC_ENT),          S(KC_SPC),         U_NA
    ),

    // Button
    [2] = LAYOUT_split_3x6_3(
        U_NU,             U_UND,             U_CUT,             U_CPY,             U_PST,             U_RDO,                                                                U_RDO,             U_PST,             U_CPY,             U_CUT,             U_UND,             U_NU,
        KC_ESC,           KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,           U_NU,                                                                 U_NU,              KC_LSFT,           KC_LCTL,           KC_LALT,           KC_LGUI,           KC_QUOTE,
        U_NU,             U_UND,             U_CUT,             U_CPY,             U_PST,             U_RDO,                                                                U_RDO,             U_PST,             U_CPY,             U_CUT,             U_UND,             U_NU,
                                                                                   U_NU,              U_NU,              U_NU,                           U_NU,              U_NU,              U_NU
    ),

    //
    // Activated by Left Hand Thumb
    //

    // Nav
    [3] = LAYOUT_split_3x6_3(
        U_NA,             U_NA,              U_NA,              U_NA,              U_NA,              U_NA,                                                                 U_RDO,             U_PST,             U_CPY,             U_CUT,             U_UND,             U_NU,
        KC_ESC,           KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,           U_NA,                                                                 U_NU,              KC_LEFT,           KC_DOWN,           KC_UP,             KC_RGHT,           KC_QUOTE,
        U_NA,             U_NA,              KC_ALGR,           U_NA,              U_NA,              U_NA,                                                                 KC_INS,            KC_HOME,           KC_PGDN,           KC_PGUP,           KC_END,            U_NU,
                                                                                   U_NA,              U_NA,              U_NA,                           KC_ENT,            KC_BSPC,           KC_DEL
    ),

    //
    // Activated by Left Hand Thumb
    //

    // Num
    [4] = LAYOUT_split_3x6_3(
        U_NU,             KC_LBRC,           KC_7,              KC_8,              KC_9,              KC_RBRC,                                                              U_NA,              U_NA,              U_NA,              U_NA,              U_NA,              U_NU,
        KC_ESC,           KC_SCLN,           KC_4,              KC_5,              KC_6,              KC_EQL,                                                               U_NA,              KC_LSFT,           KC_LCTL,           KC_LALT,           KC_LGUI,           KC_QUOTE,
        U_NU,             KC_GRV,            KC_1,              KC_2,              KC_3,              KC_BSLS,                                                              U_NA,              U_NA,              U_NA,              KC_ALGR,           U_NA,              U_NU,
                                                                                   KC_DOT,            KC_0,              KC_MINS,                        U_NA,              U_NA,              U_NA
    ),
    // Sym
    [5] = LAYOUT_split_3x6_3(
        U_NU,             KC_LCBR,           KC_AMPR,           KC_ASTR,           KC_LPRN,           KC_RCBR,                                                              U_NA,              U_NU,              U_NU,              U_NU,              U_NU,              U_NU,
        KC_ESC,           KC_COLN,           KC_DLR,            KC_PERC,           KC_CIRC,           KC_PLUS,                                                              U_NA,              KC_LSFT,           KC_LCTL,           KC_LALT,           KC_LGUI,           KC_QUOTE,
        U_NU,             KC_TILD,           KC_EXLM,           KC_AT,             KC_HASH,           KC_PIPE,                                                              U_NA,              U_NU,              U_NU,              KC_ALGR,           U_NA,              U_NU,
                                                                                   KC_LPRN,           KC_RPRN,           KC_UNDS,                        U_NA,              U_NA,              U_NA
    ),
    // Fun
    [6] = LAYOUT_split_3x6_3(
        U_NU,             KC_F12,            KC_F7,             KC_F8,             KC_F9,             KC_PSCR,                                                              U_NA,              U_NU,              U_NU,              U_NU,              U_NU,              U_NU,
        KC_ESC,           KC_F11,            KC_F4,             KC_F5,             KC_F6,             KC_SCRL,                                                              U_NA,              KC_LSFT,           KC_LCTL,           KC_LALT,           KC_LGUI,           KC_QUOTE,
        U_NU,             KC_F10,            KC_F1,             KC_F2,             KC_F3,             KC_PAUS,                                                              U_NA,              U_NU,              U_NU,              KC_ALGR,           U_NA,              U_NU,
                                                                                   KC_APP,            KC_SPC,            KC_TAB,                         U_NA,              U_NA,              U_NA
    )
};

// Thumb Combos

#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;
  }
  return OLED_ROTATION_0;
}

#define MIRYOKU_X(LAYER, STRING)            \
case U_##LAYER:                             \
    oled_write_ln_P(PSTR(STRING), false);  \
    break;

bool oled_render_layer_state(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        MIRYOKU_LAYER_LIST
        default:
            oled_write_ln_P(PSTR("Undefined"), false);
    }

    return false;
}
#undef MIRYOKU_X

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master( )) {
        oled_render_layer_state();
    } else {
        oled_render_logo();
     }
    return false;
}

#endif
