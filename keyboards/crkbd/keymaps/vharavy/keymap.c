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

#define MY_LAYER_LIST \
MY_X(ENGLISH,"Engish") \
MY_X(SYMBOLS,"Symbols") \
MY_X(NAV,    "Nav")

enum my_layers {
#define MY_X(LAYER, STRING) U_##LAYER,
MY_LAYER_LIST
#undef MY_X
};

// Keymap

#define OSM_SFT         OSM(MOD_LSFT)
#define OSM_GUI         OSM(MOD_LGUI)
#define NAV_BSPC        LT(U_NAV,KC_BSPC)       // Activate Nav layer when held, Backspace when tapped.
#define SYM_TAB         LT(U_SYMBOLS,KC_TAB)    // Activate Symbols & Numbers layer when held, Tab when tapped.

#define HR_A            LGUI_T(KC_A)
#define HR_R            LALT_T(KC_R)
#define HR_S            LCTL_T(KC_S)
#define HR_T            LSFT_T(KC_T)

#define HR_N            RSFT_T(KC_N)
#define HR_E            RCTL_T(KC_E)
#define HR_I            RALT_T(KC_I)
#define HR_O            RGUI_T(KC_O)

#define HR_1            LGUI_T(KC_1)
#define HR_2            LALT_T(KC_2)
#define HR_3            LCTL_T(KC_3)
#define HR_4            LSFT_T(KC_4)

#define HR_7            RSFT_T(KC_7)
#define HR_8            RCTL_T(KC_8)
#define HR_9            RALT_T(KC_9)
#define HR_0            RGUI_T(KC_0)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // English
    [0] = LAYOUT_split_3x6_3(
        U_NU,       KC_Q,       KC_W,       KC_F,       KC_P,       KC_B,                                   KC_J,       KC_L,       KC_U,       KC_Y,       KC_SCLN,    U_NU,
        KC_ESC,     HR_A,       HR_R,       HR_S,       HR_T,       KC_G,                                   KC_M,       HR_N,       HR_E,       HR_I,       HR_O,       KC_QUOTE,
        U_NU,       KC_Z,       KC_X,       KC_C,       KC_D,       KC_V,                                   KC_K,       KC_H,       KC_COMM,    KC_DOT,     KC_SLSH,    U_NU,
                                                        OSM_GUI,    NAV_BSPC,   KC_ENT,         SYM_TAB,    KC_SPC,     OSM_SFT
    ),

    // Symbols & Numbers
    [1] = LAYOUT_split_3x6_3(
        U_NA,       KC_EXLM,    KC_AT,      KC_HASH,    KC_DLR,     KC_PERC,                                KC_CIRC,    KC_AMPR,    KC_ASTR,    KC_LPRN,    KC_RPRN,    U_NU,
        KC_TILD,    HR_1,       HR_2,       HR_3,       HR_4,       KC_5,                                   KC_6,       HR_7,       HR_8,       HR_9,       HR_0,       KC_BSLS,
        U_NA,       KC_GRV,     KC_PIPE,    KC_UNDS,    KC_LCBR,    KC_LBRC,                                KC_RBRC,    KC_RCBR,    KC_COMM,    KC_DOT,     KC_SLSH,    U_NU,
                                                        KC_PLUS,    KC_BSPC,    KC_EQUAL,       U_NA,       KC_SPC,     KC_MINS
    ),

    // Nav
    [2] = LAYOUT_split_3x6_3(
        U_NA,       U_NA,       U_NA,       U_NA,       U_NA,       U_NA,                                   U_RDO,      U_PST,      U_CPY,      U_CUT,      U_UND,      U_NU,
        KC_ESC,     KC_LGUI,    KC_LALT,    KC_LCTL,    KC_LSFT,    U_NA,                                   U_NU,       KC_LEFT,    KC_DOWN,    KC_UP,      KC_RGHT,    KC_QUOTE,
        U_NA,       U_NA,       KC_ALGR,    U_NA,       U_NA,       U_NA,                                   KC_INS,     KC_HOME,    KC_PGDN,    KC_PGUP,    KC_END,     U_NU,
                                                        U_NA,       U_NA,       U_NA,           U_NA,       U_NA,       U_NA
    ),
};

// Thumb Combos

#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;
  }
  return OLED_ROTATION_0;
}

#define MY_X(LAYER, STRING)            \
case U_##LAYER:                             \
    oled_write_ln_P(PSTR(STRING), false);  \
    break;

bool oled_render_layer_state(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);
    switch (get_highest_layer(layer_state)) {
        MY_LAYER_LIST
        default:
            oled_write_ln_P(PSTR("Undefined"), false);
    }

    return false;
}
#undef MY_X

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
