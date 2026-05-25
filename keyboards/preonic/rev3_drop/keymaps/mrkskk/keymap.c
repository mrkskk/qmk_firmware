// Copyright 2026
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "mrkskk.h"

#ifdef KEY_OVERRIDE_ENABLE
#    include "features/key_overrides.c"
#endif

#ifdef COMBO_ENABLE
#    include "g/keymap_combo.h"
#endif

/* tzarc/globe_key module */
bool process_record_globe_key(uint16_t keycode, keyrecord_t *record);

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_record_globe_key(keycode, record)) {
        return false;
    }
    return true;
}

/*
 * Adapted from users/mrkskk key layout for Preonic 5x12.
 * Edit these two rows directly for your board-specific tweaks.
 */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_preonic_grid(
        KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
        KC_TAB,  KC_W,    KC_C,    KC_G,    KC_M,    KC_J,    QUOT,    KC_U,    KC_K,    DK_OE,   DK_AA,   KC_BSLS,
        KC_ESC,  HM_LSFT, HM_LALT, HM_LCTL, HM_LGUI, KC_F,    KC_Y,    HM_RGUI, HM_RCTL, HM_RALT, HM_RSFT, KC_ENT,
        KC_LSFT, KC_V,    MEH_B,   HYP_L,   CAG_D,   KC_X,    KC_Z,    CAG_P,   HYP_COM, MEH_DOT, DK_AE,   KC_RSFT,
        TG_MS,   KC_LCTL, KC_LALT, KC_LGUI, NUM_SPC, MO(_NAV_MAC), FN_BSPC, NUM_N, KC_RGUI, KC_RALT, KC_RCTL, TO_BASE

    ),

    [_NAV_MAC] = LAYOUT_preonic_grid(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        KC_TAB,  UNDO,    COPY,    CBOARD,  PASTE,   REDO,    KC_PGUP, _______, KC_UP,   _______, KC_END,  _______,
        KC_ESC,  KC_LSFT, KC_LALT, KC_LCTL, KC_LGUI, KC_RALT, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_HOME, KC_ENT,
        KC_LSFT, TG_MS,   KC_MEH,  KC_HYPR, KC_CAG,  CW_TOGG, QUIT,    KC_TAB,  KC_ENT,  KC_ESC,  _______, KC_RSFT,
        KC_GLOBE, TO_BASE, TO_BASE, TO_BASE, TO_BASE, FN_BSPC, KC_DEL,  TO_BASE, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
    ),

    [_MOUSE] = LAYOUT_preonic_grid(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
        TO_BASE, TO_BASE, TO_BASE, MS_WHLU, TO_BASE, TO_BASE, TO_BASE, TO_BASE, MS_UP,   TO_BASE, TO_BASE, TO_BASE,
        TO_BASE, TO_BASE, MS_WHLL, MS_WHLD, MS_WHLL, TO_BASE, TO_BASE, MS_LEFT, MS_DOWN, MS_RGHT, TO_BASE, TO_BASE,
        TO_BASE, TO_BASE, MS_BTN2, PRE_MO,  MS_BTN1, TO_BASE, TO_BASE, TO_BASE, TO_BASE, TO_BASE, TO_BASE, TO_BASE,
        TO_BASE, TO_BASE, TO_BASE, TO_BASE, TO_BASE, TO_BASE, TO_BASE, TO_BASE, TO_BASE, TO_BASE, TO_BASE, TO_BASE
    ),

    [_NUMROW] = LAYOUT_preonic_grid(
        KC_GRV,  HAT_ND,  DIAE,    GRAVE_ND, ACUTE_ND, TILDE_ND, DQUO,    LABK,    MINUS,   PLUS,    RABK,    KC_BSPC,
        _______, HAT_ND,  DIAE,    GRAVE_ND, ACUTE_ND, TILDE_ND, DQUO,    LABK,    MINUS,   PLUS,    RABK,    _______,
        _______, HOME_7,  HOME_5,  HOME_1,  HOME_3,  KC_9,    KC_0,    HOME_4,  HOME_2,  HOME_6,  HOME_8,  _______,
        _______, TG(_NUM), MEH_CARET, HYPR_USD, CAG_9, PIPE, PARA, CAG_0, HYP_COM, MEH_DOT, KC_PDOT, _______,
        TO_BASE, TO_BASE, TO_BASE, TO_BASE, TO_BASE, KC_BSPC, KC_0,    TO_BASE, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
    ),

    [_NUM] = LAYOUT_preonic_grid(
        _______, KC_7,    KC_8,    KC_9,    _______, _______, KC_7,    KC_8,    KC_9,    _______, _______, _______,
        _______, TO_BASE, KC_7,    KC_8,    KC_9,    TO_BASE, TO_BASE, KC_7,    KC_8,    KC_9,    TO_BASE, _______,
        _______, SFT_0,   ALT_4,   CTL_5,   GUI_6,   TO_BASE, TO_BASE, GUI_4,   CTL_5,   ALT_6,   KC_LSFT, _______,
        _______, TO_BASE, MEH_1,   HYPR_2,  CAG_3,   TO_BASE, TO_BASE, CAG_1,   HYPR_2,  MEH_3,   KC_RALT, _______,
        TO_BASE, KC_0,    TO_BASE, TO_BASE, TO_BASE, KC_BSPC, KC_0,    TO_BASE, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
    ),

    [_FNKEYS] = LAYOUT_preonic_grid(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
        _______, CA_DEL,  KC_F7,   KC_F8,   KC_F9,   KC_F12,  TG_SENT, KC_MPRV, KC_MPLY, KC_MNXT, KC_INS,  _______,
        _______, SCRSHOT, KC_F4,   KC_F5,   KC_F6,   KC_F11,  TG_OS,   KC_LGUI, KC_LCTL, KC_LALT, KC_LSFT, _______,
        _______, _______, KC_F1,   KC_F2,   KC_F3,   KC_F10,  OS_RESET, KC_BRID, KC_BRIU, KC_ASST, _______, _______,
        KC_MUTE, KC_VOLD, KC_VOLU, TO_BASE, TO_BASE, KC_VOLU, KC_VOLD, TO_BASE, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
    ),
};
