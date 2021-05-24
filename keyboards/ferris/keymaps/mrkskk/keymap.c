// clang format on
#include "mrkskk.h"
#include "sendstring_danish.h"
#if defined(COMBO_ENABLE)
#    include "g/keymap_combo.h"  // to make combo def dictionary work
#endif

void matrix_scan_user(void) { matrix_scan_alttab(); }

// With TAPPING_FORCE_HOLD, the second press will be interpreted as a modifier, allowing to use it as a modifier shortly after having used it as a tap.
bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        default:
            return true;
    }
}

// Setting per key tapping term. registers as TAP when time < TAPPING_TERM and registers as HOLD when time > TAPPING_TERM.
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
            // HANDSDOWN
            // LEFT-hand home row mods

        case CONT_R:
        case ALT_S:
        case NAV_T:
        case COMD_H:
        case ALT_B:
        // Right-hand home row mods
        case COMD_I:
        case HMR_E:
        case ALT_O:
        case CONT_A:
        case RALT_DOT:
            return 200;
        default:
            return TAPPING_TERM;  //
    }
}

// With TAPPING_FORCE_HOLD, the second press will be interpreted as a modifier, allowing to use it as a modifier shortly after having used it as a tap.
bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        default:
            return true;
    }
}

// Setting per key tapping term. registers as TAP when time < TAPPING_TERM and registers as HOLD when time > TAPPING_TERM.
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case NUM_DEL:
        case DEL_W_S:
            return 100;
        // HANDSDOWN
        // LEFT-hand home row mods
        case CONT_R:
        case ALT_S:
        case NAV_T:
        case COMD_H:
        case ALT_B:
        // Right-hand home row mods
        case COMD_I:
        case HMR_E:
        case ALT_O:
        case CONT_A:
        case RALT_DOT:
            return 200;
        default:
            return TAPPING_TERM;
    }
}

#ifdef COMBO_ENABLE
bool get_combo_must_tap(uint16_t index, combo_t *combo) {
    // If you want all combos to be tap-only, just uncomment the next line
    // return true

    // If you want *all* combos, that have Mod-Tap/Layer-Tap/Momentary keys in its chord, to be tap-only, this is for you:
    uint16_t key;
    uint8_t  idx = 0;
    while ((key = pgm_read_word(&combo->keys[idx])) != COMBO_END) {
        switch (key) {
            case QK_MOD_TAP ... QK_MOD_TAP_MAX:
            // case QK_LAYER_TAP...QK_LAYER_TAP_MAX: // If this is enabled the LT(SHORCUTS,KC_F2) key does not work.
            case QK_MOMENTARY ... QK_MOMENTARY_MAX:
                return true;
        }
        idx += 1;
    }
    return false;
}

uint16_t get_combo_term(uint16_t index, combo_t *combo) {
    switch (index) {
        case AAE_OE:
        case RV_V:
        case COPY:
        case PASTE:
        case UNDO:
        case REDO:
        case NAV_1:
        case NAV_2:
        case NAV_3:
        case NAV_4:
        case NAV_5:
        case NAV_6:
        case NAV_7:
        case NAV_8:
        case NAV_9:
        case NAV_0:
            return 90;
        case SPC_N_CAPSWRD:
            return 60;
        default:
            return COMBO_TERM;  //
    }
}
#endif

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

   [HANDSDOWN_ALT_NX_DK_MOD] = LAYOUT(
//.--------+--------+--------+--------+--------.                    .--------+--------+--------+--------+--------.
    KC_W,   KC_C,    KC_G,   KC_M,     KC_Q,                         S_QUOT,   KC_U,    KC_K,     KC_J,   DK_AA,
//|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
    CONT_R, ALT_S,  NAV_T,  COMD_H,   KC_F,                          KC_Y,   COMD_I,  HMR_E,    ALT_O,    CONT_A,
//|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
    KC_V,   ALT_B,  KC_L,   KC_D,     KC_X,                          KC_Z,   KC_P,    KC_COMM,  RALT_DOT, DK_AE,
//.--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------.
                                        SYM_ENT, SFT_SPC,    SFT_N, NUM_DEL,
 //                                   '--------+--------'  '--------+--------'
    ),

    [NUMPAD] = LAYOUT(
//.--------+--------+--------+--------+--------.                    .--------+--------+--------+--------+--------.
    XXXXXXX, S_PIPE, S_LBRC,   S_RBRC,   XXXXXXX,                     EUR,  KC_7,    KC_8,   KC_9, KC_0,
//|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
    S_MINUS, S_SLSH, LPRN,    RPRN,   S_PERC,                        USD,  KC_4,  KC_5,   KC_6,   KC_DOT,
//|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
    _______, S_DIAE,  S_LBRC,  S_RBRC, XXXXXXX,                      GBP,  KC_1,    KC_2, KC_3, KC_COMM,
//.--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------.
                                        TO_BASE, KC_LSFT,  KC_RSFT,  _______,
 //                                   '--------+--------'  '--------+--------'
    ),

    [SYMBOLS] = LAYOUT(
//.--------+--------+--------+--------+--------.                    .--------+--------+--------+--------+--------.
    XXXXXXX, S_PIPE, S_LBRC,   S_RBRC,   XXXXXXX,                      XXXXXXX,  ACUT,   GRV,    _______, XXXXXXX,
//|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
    S_MINUS, S_SLSH, LPRN,    RPRN,   S_PERC,                         S_QUOT, QUES,   UNDSC,    HASH,     AT,
//|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
    _______, S_EQL, LABK,    RABK,    XXXXXXX,                      XXXXXXX,  DIAE,   TILD,     _______, _______,
//.--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------.
                                        TO_BASE, KC_LSFT,   KC_RSFT, _______,
 //                                   '--------+--------'  '--------+--------'
    ),

    [NAV] = LAYOUT(
//.--------+--------+--------+--------+--------.                    .--------+--------+--------+--------+--------.
    CLOSE,   _______, XXXXXXX, KC_ESC, XXXXXXX,                       UNDO,    CUT,     COPY,    PASTE,   REDO,
//|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
    KC_LCTL, KC_LALT, XXXXXXX,  KC_LGUI, ALT_TAB,                      KC_TAB, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,
//|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
    _______, _______, XXXXXXX, SP_AS, XXXXXXX,                      XXXXXXX, KC_HOME, KC_PGDN, KC_PGDN, KC_END,
//.--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------.
                                        TO_BASE, KC_LSFT,   KC_RSFT, DEL_BSPC_W,
 //                                   '--------+--------'  '--------+--------'
    ),

    [HAMMERSPOON] = LAYOUT(
//.--------+--------+--------+--------+--------.                    .--------+--------+--------+--------+--------.
     one_6,  two_6,   three_6, one_4,  two_4,                        three_4, four_4, XXXXXXX, XXXXXXX,  XXXXXXX,
//|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
    four_6, five_6,  sixth_6, FULLSCR, LEFT,                         RIGHT,  MIDDLE, XXXXXXX, XXXXXXX, XXXXXXX,
//|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
    one_3,   two_3,   three_3, LAYOUT, MIDDLE,                       MIDDLE, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//.--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------.
                                        TO_BASE, ALFRED,   _______,  _______,
 //                                   '--------+--------'  '--------+--------'
    ),

    [MOUSE_LAYER] = LAYOUT(
//.--------+--------+--------+--------+--------.                    .--------+--------+--------+--------+--------.
    CLOSE,   KC_ESC, PRV_TAB,  NXT_TAB, XXXXXXX,                     XXXXXXX, FOCUS_L, FOCUS_D, FOCUS_U, FOCUS_R,
//|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
    XXXXXXX, KC_ACL0, KC_ACL1, KC_ACL2  XXXXXXX                      XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R,
//|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
    XXXXXXX, XXXXXXX, PRV_PGE, NXT_PGE, XXXXXXX,                     XXXXXXX, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R,
//.--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------.
                                        TO_BASE, KC_BTN1,    KC_BTN1,  KC_BTN2,
 //                                   '--------+--------'  '--------+--------'
    ),

    [MEDIA_LAYER] = LAYOUT(
//.--------+--------+--------+--------+--------.                    .--------+--------+--------+--------+--------.
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, KC_BRID, KC_BRIU, XXXXXXX,
//|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
    XXXXXXX, KC_MSTP, KC_MPLY, KC_MUTE, XXXXXXX,                     XXXXXXX, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT,
//|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//.--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------.
                                        TO_BASE, _______,    _______,  _______,
 //                                   '--------+--------'  '--------+--------'
    ),

    [ADJUST] = LAYOUT(
//.--------+--------+--------+--------+--------.                    .--------+--------+--------+--------+--------.
    RGB_TOG, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX,  PM,        LH,     MP,     XXXXXXX,
//|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
    XXXXXXX, XXXXXXX, XXXXXXX, TG_OS,   XXXXXXX,                     XXXXXXX,  PW,        PK,     MW,     XXXXXXX,
//|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX,   RP,     XXXXXXX, XXXXXXX, XXXXXXX,
//.--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------.
                                        TO_BASE, _______,   _______,  _______,
 //                                   '--------+--------'  '--------+--------'
    ),

    [FN_LAYER] = LAYOUT(
//.--------+--------+--------+--------+--------.                    .--------+--------+--------+--------+--------.
    _______, _______, _______, _______, _______,                      _______, KC_F7,  KC_F8,   KC_F9,   KC_F12,
//|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
    KC_LCTL, KC_LALT, ALFRED,  KC_LGUI, _______,                      _______, KC_F4,  KC_F5,   KC_F6,   KC_F11,
//|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
    _______, _______, _______, _______, _______,                      _______, KC_F1,  KC_F2,   KC_F3,  KC_F10,
//.--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------.
                                        _______, KC_LSFT,   _______,  _______,
 //                                   '--------+--------'  '--------+--------'
    ),
/*
     [TEMPLATE] = LAYOUT(
//.--------+--------+--------+--------+--------.                    .--------+--------+--------+--------+--------.
    _______,   _______, _______, _______, _______,                    _______,      _______,     _______,    _______,   _______,
//|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
    _______, _______, _______,  _______, _______,                     _______,   _______, _______, _______,   _______,
//|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
    _______, _______, _______, _______, _______,                     _______,   _______, _______, _______, _______,
//.--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------.
                                        _______, _______,   _______,  _______,
 //                                   '--------+--------'  '--------+--------'
    ),
*/

};

// clang-format on
