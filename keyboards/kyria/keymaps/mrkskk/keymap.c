// clang format on
#include "mrkskk.h"
#include "sendstring_danish.h"
#if defined(COMBO_ENABLE)
#    include "g/keymap_combo.h"  // to make combo def dictionary work
#endif

void matrix_scan_user(void) {
    matrix_scan_alttab();
    /*
#if defined(ENCODER_ENABLE)
    matrix_scan_encoders();
#endif
*/
#if defined(LEADER_ENABLE)
    matrix_scan_leader();
#endif
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
        case SYM_DEL:
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
            // case :
            return 200;
        default:
            return TAPPING_TERM;
    }
}
/*
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
#endif
*/
#ifdef COMBO_ENABLE
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
        case NAV_MINUS:
        case NAV_UNDCS:
            return 90;
        case SPC_N_CAPSWRD:
            return 60;
            // case SPC_DOT_SHIFT:
            // case SPC_COL_SHIFT:
            // case SPC_SEMC_SHIFT:
            // case SPC_QUES_SHIFT:
            // case SPC_EXLM_SHIFT:
            // return 5000;
        default:
            return COMBO_TERM;  //
    }
}
#endif

// clang-format off

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [HANDSDOWN_ALT_NX_DK_MOD] = LAYOUT_Kyria3x5(

        //.--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------.
            KC_W,   KC_C,    KC_G,   KC_M,     KC_Q,                                            S_QUOT,   KC_U,    KC_K,     KC_J,   DK_AA,
        //|--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------|
            CONT_R,  ALT_S,  NAV_T,  COMD_H,   KC_F,                                            KC_Y,   COMD_I,  HMR_E,    ALT_O,    CONT_A,
        //.--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
            KC_V,    ALT_B,  KC_L,   KC_D,     KC_X,    _______, _______,    SCR_SHOT, _______,   KC_Z,   KC_P,    KC_COMM, KC_DOT, DK_AE,
        //.--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                LOCK, XXXXXXX, NUM_ENT, SPC_DOT, NUM_ENT,    SYM_DEL, SFT_N,  SYM_DEL, XXXXXXX, XXXXXXX
        //                  '--------+--------+--------+--------+--------'  '--------+--------+--------+--------+--------'
        ),

    [NUMPAD] = LAYOUT_Kyria3x5(
        //.--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------.
            XXXXXXX, S_LBRC, S_EQL,  S_RBRC,  XXXXXXX,                                          EUR,    KC_7,    KC_8,    KC_9,    KC_0,
        //.--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------.
            S_SLSH,  LPRN,  UNDSC,   RPRN,    S_PERC,                                           USD,    KC_4,    KC_5,    KC_6,    KC_DOT,
        //.--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
            S_PIPE,  LABK,  S_MINUS, RABK,    XXXXXXX, XXXXXXX, _______,      _______, _______, GBP,    KC_1,    KC_2,    KC_3,    KC_COMM,
        //.--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                             CAD,     XXXXXXX, _______, OS_SHFT, _______,     _______, OS_SHFT, TO_BASE, XXXXXXX, XXXXXXX
        //                  '--------+--------+--------+--------+--------'  '--------+--------+--------+--------+--------'
        ),

    [SYMBOLS] = LAYOUT_Kyria3x5(
        //.--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------.
           XXXXXXX, S_LBRC, S_EQL,  S_RBRC,   XXXXXXX,                                         XXXXXXX,  TILD,   ACUT,   GRV, XXXXXXX,
        //.--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------.
            S_SLSH,  LPRN,  UNDSC,   RPRN,    S_PERC,                                          _______,  S_QUOT, QUES,    AT,      HASH,
        //.--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
            S_PIPE,  LABK,  S_MINUS, RABK,    XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,    DIAE,   SEMCOL,  COL, _______,
        //.--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                              CAD,      XXXXXXX, _______, OS_SHFT, _______, _______, OS_SHFT, TO_BASE, XXXXXXX, XXXXXXX
        //                  '--------+--------+--------+--------+--------'  '--------+--------+--------+--------+--------'
        ),

    [NAV] = LAYOUT_Kyria3x5(
        //.--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------.
            CLOSE,  _______,  XXXXXXX, KC_ESC, XXXXXXX,                                         UNDO,   CUT,     COPY,    PASTE,  REDO,
        //.--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------.
            OS_CTRL, OS_ALT, XXXXXXX, OS_CMD, SP_AS,                                        ALT_TAB, KC_LEFT, KC_DOWN, KC_UP,  KC_RGHT,
        //.--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
            _______, _______, XXXXXXX, KC_F2, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,
        //.--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                             CAD,     XXXXXXX, KC_TAB, OS_SHFT, _______,    DEL_BSPC_W, KC_ENT, DEL_BSPC_W, XXXXXXX, _______
        //                  '--------+--------+--------+--------+--------'  '--------+--------+--------+--------+--------'
        ),

    [HAMMERSPOON] = LAYOUT_Kyria3x5(
        //.--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------.
            one_6,  two_6,   three_6, one_4,  two_4,                                           three_4, four_4, XXXXXXX, XXXXXXX,  XXXXXXX,
        //.--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------.
            four_6, five_6,  sixth_6, FULLSCR, LEFT,                                           RIGHT,   MIDDLE, XXXXXXX, XXXXXXX, XXXXXXX,
        //.--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
            one_3,  two_3,   three_3, wLAYOUT, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        //.--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                              _______, XXXXXXX, _______, ALFRED, _______,   _______,  ALFRED, TO_BASE, XXXXXXX, _______
        //                  '--------+--------+--------+--------+--------'  '--------+--------+--------+--------+--------'
        ),

    [MOUSE_LAYER] = LAYOUT_Kyria3x5(
        //.--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------.
           CLOSE, XXXXXXX,   PRV_TAB, NXT_TAB,  XXXXXXX,                                       XXXXXXX, FOCUS_L, FOCUS_D, FOCUS_U, FOCUS_R,
        //.--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------.
           XXXXXXX, KC_ACL0, KC_ACL1, KC_ACL2, XXXXXXX,                                        ALT_TAB, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R,
        //.--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
           XXXXXXX, XXXXXXX, PRV_PGE, NXT_PGE, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R,
        //.--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                             CAD, XXXXXXX,     KC_ENT,   KC_BTN2, _______,    _______, KC_BTN1, TO_BASE, XXXXXXX, XXXXXXX
        //                  '--------+--------+--------+--------+--------'  '--------+--------+--------+--------+--------'
        ),

        [MEDIA_LAYER] = LAYOUT_Kyria3x5(
        //.--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------.
             XXXXXXX, XXXXXXX, _______, _______, XXXXXXX,                                       XXXXXXX, XXXXXXX, KC_BRID, KC_BRIU, XXXXXXX,
        //.--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------.
             XXXXXXX, KC_MSTP, KC_MPLY, KC_MUTE, XXXXXXX,                                       XXXXXXX, KC_MPRV, KC_VOLD, KC_VOLU, KC_MNXT,
        //.--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        //.--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                              CAD,      XXXXXXX, _______, _______, _______, _______, _______, TO_BASE, XXXXXXX, XXXXXXX
        //                  '--------+--------+--------+--------+--------'  '--------+--------+--------+--------+--------'
        ),

    [ADJUST] = LAYOUT_Kyria3x5(
        //.--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------.
           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                        XXXXXXX, PM,        LH,     MP,     XXXXXXX,
        //.--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------.
           XXXXXXX,  XXXXXXX, XXXXXXX, TG_OS, XXXXXXX,                                          XXXXXXX, PW,        PK,     MW,     XXXXXXX,
        //.--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
           XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, RP, XXXXXXX, XXXXXXX, XXXXXXX,
        //.--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                              XXXXXXX, XXXXXXX, _______, _______, XXXXXXX,    XXXXXXX, _______, TO_BASE, XXXXXXX, XXXXXXX
        //                  '--------+--------+--------+--------+--------'  '--------+--------+--------+--------+--------'
        ),

    [FN_LAYER] = LAYOUT_Kyria3x5(
        //.--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------.
           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                         XXXXXXX, KC_F7,  KC_F8,   KC_F9,  KC_F12,
        //.--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------.
           KC_LCTL, KC_LALT, XXXXXXX, KC_LGUI, XXXXXXX,                                         XXXXXXX, KC_F4,  KC_F5,   KC_F6,  KC_F11,
        //.--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX,  XXXXXXX, KC_F1,  KC_F2,   KC_F3,  KC_F10,
        //.--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                             CAD,     XXXXXXX, _______, KC_LSFT, _______,    XXXXXXX, _______, TO_BASE, XXXXXXX, XXXXXXX
        //                  '--------+--------+--------+--------+--------'  '--------+--------+--------+--------+--------'
        ),

    /*
        [TEMPLATE] = LAYOUT_Kyria3x5(
    //.--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------.
                _______,     _______,    _______,    _______,    _______,                                           _______,     _______,    _______,   _______,    _______,
    //.--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------.
                _______,     _______,    _______,    _______,    _______,                                           _______,     _______,    _______,   _______,    _______,
    //.--------+--------+--------+--------+--------.  |--------+--------+--------+--------+--------+--------+--------+--------|
                _______,     _______,    _______,    _______,    _______,    _______,    _______,        _______,   _______,    _______,    _______,    _______,    _______,     _______,
    //.--------+--------+--------+--------+--------.  |--------+--------+--------+--------+--------+--------+--------+--------|
                                    _______,    _______,    _______,   _______,      _______,      _______,   _______,     _______,     _______,   _______
     //                  '--------+--------+--------+--------+--------'  '--------+--------+--------+--------+--------'
        ),
    */

};
// clang format on
