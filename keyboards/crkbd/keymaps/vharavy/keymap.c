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
MIRYOKU_X(ENG,    "ENG") \
MIRYOKU_X(RUS,    "RUS") \
MIRYOKU_X(BUTTON, "Button") \
MIRYOKU_X(NAV,    "Nav") \
MIRYOKU_X(MOUSE,  "Mouse") \
MIRYOKU_X(MEDIA,  "Media") \
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
        U_NU,             KC_Q,              KC_W,              KC_F,              KC_P,              KC_B,                                                                 KC_J,              KC_L,              KC_U,              KC_Y,              KC_QUOT,              U_NU, 
        U_NU,             LGUI_T(KC_A),      LALT_T(KC_R),      LCTL_T(KC_S),      LSFT_T(KC_T),      KC_G,                                                                 KC_M,              LSFT_T(KC_N),      LCTL_T(KC_E),      LALT_T(KC_I),      LGUI_T(KC_O),         U_NU,
        U_NU,             LT(U_BUTTON,KC_Z), ALGR_T(KC_X),      KC_C,              KC_D,              KC_V,                                                                 KC_K,              KC_H,              KC_COMM,           ALGR_T(KC_DOT),    LT(U_BUTTON,KC_SLSH), U_NU,
                                                                                   LT(U_MEDIA,KC_ESC),LT(U_NAV,KC_BSPC), LT(U_MOUSE,KC_TAB),             LT(U_SYM,KC_ENT),  LT(U_NUM,KC_SPC), OSM(MOD_LSFT)
    ),
    // TODO: Russian
    [1] = LAYOUT_split_3x6_3(
        U_NU,             KC_Q,              KC_W,              KC_F,              KC_P,              KC_B,                                                                 KC_J,              KC_L,              KC_U,              KC_Y,              KC_QUOT,              U_NU,
        U_NU,             LGUI_T(KC_A),      LALT_T(KC_R),      LCTL_T(KC_S),      LSFT_T(KC_T),      KC_G,                                                                 KC_M,              LSFT_T(KC_N),      LCTL_T(KC_E),      LALT_T(KC_I),      LGUI_T(KC_O),         U_NU,
        U_NU,             LT(U_BUTTON,KC_Z), ALGR_T(KC_X),      KC_C,              KC_D,              KC_V,                                                                 KC_K,              KC_H,              KC_COMM,           ALGR_T(KC_DOT),    LT(U_BUTTON,KC_SLSH), U_NU,
                                                                                   LT(U_MEDIA,KC_ESC),LT(U_NAV,KC_SPC),  LT(U_MOUSE,KC_TAB),             LT(U_SYM,KC_ENT),  LT(U_NUM,KC_BSPC), OSM(MOD_LSFT)
    ),
    
    // Button
    [2] = LAYOUT_split_3x6_3(
        U_NU,             U_UND,             U_CUT,             U_CPY,             U_PST,             U_RDO,                                                                U_RDO,             U_PST,             U_CPY,             U_CUT,             U_UND,             U_NU,
        U_NU,             KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,           U_NU,                                                                 U_NU,              KC_LSFT,           KC_LCTL,           KC_LALT,           KC_LGUI,           U_NU,
        U_NU,             U_UND,             U_CUT,             U_CPY,             U_PST,             U_RDO,                                                                U_RDO,             U_PST,             U_CPY,             U_CUT,             U_UND,             U_NU,
                                                                                   KC_BTN3,           KC_BTN1,           KC_BTN2,                        KC_BTN2,           KC_BTN1,           KC_BTN3
    ),

    //
    // Activated by Left Hand Thumb
    //

    // Nav
    [3] = LAYOUT_split_3x6_3(
        U_NA,             U_NA,              U_NA,              U_NA,              U_NA,              U_NA,                                                                 U_RDO,             U_PST,             U_CPY,             U_CUT,             U_UND,             U_NU,
        U_NA,             KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,           U_NA,                                                                 U_NU,              KC_LEFT,           KC_DOWN,           KC_UP,             KC_RGHT,           U_NU,
        U_NA,             U_NA,              KC_ALGR,           U_NA,              U_NA,              U_NA,                                                                 KC_INS,            KC_HOME,           KC_PGDN,           KC_PGUP,           KC_END,            U_NU,
                                                                                   U_NA,              U_NA,              U_NA,                           KC_ENT,            KC_BSPC,           KC_DEL
    ),
    // Mouse
    [4] = LAYOUT_split_3x6_3(
        U_NA,             U_NA,              U_NA,              U_NA,              U_NA,              U_NA,                                                                 U_RDO,             U_PST,             U_CPY,             U_CUT,             U_UND,             U_NU,
        U_NA,             KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,           U_NA,                                                                 U_NU,              KC_MS_L,           KC_MS_D,           KC_MS_U,           KC_MS_R,           U_NU,
        U_NA,             U_NA,              KC_ALGR,           U_NA,              U_NA,              U_NA,                                                                 U_NU,              KC_WH_L,           KC_WH_D,           KC_WH_U,           KC_WH_R,           U_NU,
                                                                                   U_NA,              U_NA,              U_NA,                           KC_BTN2,           KC_BTN1,           KC_BTN3
    ),
    // Media
    [5] = LAYOUT_split_3x6_3(
        U_NA,             U_NA,              U_NA,              U_NA,              U_NA,              U_NA,                                                                 RGB_TOG,           RGB_MOD,           RGB_HUI,           RGB_SAI,           RGB_VAI,           U_NU,
        U_NA,             KC_LGUI,           KC_LALT,           KC_LCTL,           KC_LSFT,           U_NA,                                                                 U_NU,              KC_MPRV,           KC_VOLD,           KC_VOLU,           KC_MNXT,           U_NU,
        U_NA,             U_NA,              KC_ALGR,           U_NA,              U_NA,              U_NA,                                                                 OU_AUTO,           U_NU,              U_NU,              U_NU,              U_NU,              U_NU,
                                                                                   U_NA,              U_NA,              U_NA,                           KC_MSTP,           KC_MPLY,           KC_MUTE
    ),

    //
    // Activated by Left Hand Thumb
    //

    // Num
    [6] = LAYOUT_split_3x6_3(
        U_NU,             KC_LBRC,           KC_7,              KC_8,              KC_9,              KC_RBRC,                                                              U_NA,              U_NA,              U_NA,              U_NA,              U_NA,              U_NU,
        U_NU,             KC_SCLN,           KC_4,              KC_5,              KC_6,              KC_EQL,                                                               U_NA,              KC_LSFT,           KC_LCTL,           KC_LALT,           KC_LGUI,           U_NU,
        U_NU,             KC_GRV,            KC_1,              KC_2,              KC_3,              KC_BSLS,                                                              U_NA,              U_NA,              U_NA,              KC_ALGR,           U_NA,              U_NU,
                                                                                   KC_DOT,            KC_0,              KC_MINS,                        U_NA,              U_NA,              U_NA
    ),
    // Sym
    [7] = LAYOUT_split_3x6_3(
        U_NU,             KC_LCBR,           KC_AMPR,           KC_ASTR,           KC_LPRN,           KC_RCBR,                                                              U_NA,              U_NU,              U_NU,              U_NU,              U_NU,              U_NU,
        U_NU,             KC_COLN,           KC_DLR,            KC_PERC,           KC_CIRC,           KC_PLUS,                                                              U_NA,              KC_LSFT,           KC_LCTL,           KC_LALT,           KC_LGUI,           U_NU,
        U_NU,             KC_TILD,           KC_EXLM,           KC_AT,             KC_HASH,           KC_PIPE,                                                              U_NA,              U_NU,              U_NU,              KC_ALGR,           U_NA,              U_NU,
                                                                                   KC_LPRN,           KC_RPRN,           KC_UNDS,                        U_NA,              U_NA,              U_NA
    ),
    // Fun
    [8] = LAYOUT_split_3x6_3(
        U_NU,             KC_F12,            KC_F7,             KC_F8,             KC_F9,             KC_PSCR,                                                              U_NA,              U_NU,              U_NU,              U_NU,              U_NU,              U_NU,
        U_NU,             KC_F11,            KC_F4,             KC_F5,             KC_F6,             KC_SCRL,                                                              U_NA,              KC_LSFT,           KC_LCTL,           KC_LALT,           KC_LGUI,           U_NU,
        U_NU,             KC_F10,            KC_F1,             KC_F2,             KC_F3,             KC_PAUS,                                                              U_NA,              U_NU,              U_NU,              KC_ALGR,           U_NA,              U_NU,
                                                                                   KC_APP,            KC_SPC,            KC_TAB,                         U_NA,              U_NA,              U_NA
    )    
};

// Thumb Combos

#if defined (MIRYOKU_KLUDGE_THUMBCOMBOS)
const uint16_t PROGMEM thumbcombos_base_right[] = {LT(U_SYM, KC_ENT), LT(U_NUM, KC_BSPC), COMBO_END};
const uint16_t PROGMEM thumbcombos_base_left[] = {LT(U_NAV, KC_SPC), LT(U_MOUSE, KC_TAB), COMBO_END};
const uint16_t PROGMEM thumbcombos_nav[] = {KC_ENT, KC_BSPC, COMBO_END};
const uint16_t PROGMEM thumbcombos_mouse[] = {KC_BTN2, KC_BTN1, COMBO_END};
const uint16_t PROGMEM thumbcombos_media[] = {KC_MSTP, KC_MPLY, COMBO_END};
const uint16_t PROGMEM thumbcombos_num[] = {KC_0, KC_MINS, COMBO_END};
const uint16_t PROGMEM thumbcombos_sym[] = {KC_RPRN, KC_UNDS, COMBO_END};
const uint16_t PROGMEM thumbcombos_fun[] = {KC_SPC, KC_TAB, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
  COMBO(thumbcombos_base_right, LT(U_FUN, KC_DEL)),
  COMBO(thumbcombos_base_left, LT(U_MEDIA, KC_ESC)),
  COMBO(thumbcombos_nav, KC_DEL),
  COMBO(thumbcombos_mouse, KC_BTN3),
  COMBO(thumbcombos_media, KC_MUTE),
  COMBO(thumbcombos_num, KC_DOT),
  COMBO(thumbcombos_sym, KC_LPRN),
  COMBO(thumbcombos_fun, KC_APP)
};
#endif

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