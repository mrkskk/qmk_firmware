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
        case MS_BSPC:
            return 100;
            // HANDSDOWN
            // LEFT-hand home row mods
            // case CONT_R:
            // case ALT_S:
        case NAV_T:
        case NAV2_H:
        // case COMD_H:
        // case ALT_B:
        // Right-hand home row mods
        // case COMD_I:
        case HMR_O:
            // case ALT_O:
            // case CONT_A:
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
            KC_W,   KC_C,    KC_G,   KC_M,     KC_Q,                                            S_QUOT, KC_U,    KC_K,     KC_J,   DK_AA,
        //|--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------|
            KC_R,   KC_S,    NAV_T,  NAV2_H,   KC_F,                                            KC_Y,   KC_I,    HMR_E,    KC_O,  KC_A,
        //.--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
            KC_V,   KC_B,   KC_L,   KC_D,     KC_X,    XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, KC_Z,   KC_P,    KC_COMM, DOTSFT,  DK_AE,
        //.--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                LOCK, XXXXXXX, FN_ENT, SPC_NUM, XXXXXXX,    XXXXXXX, N_SYM,  MS_BSPC, XXXXXXX, XXXXXXX
        //                  '--------+--------+--------+--------+--------'  '--------+--------+--------+--------+--------'
        ),
        [NUMPAD] = LAYOUT_Kyria3x5(
        //.--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------.
            _______, KC_7,    KC_8,    KC_9,    EUR,                                           _______,  LABK,  S_MINUS,  RABK,  XXXXXXX,
        //.--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------.
            KC_0,    KC_4,    KC_5,    KC_6,    USD,                                            _______, LPRN,  S_SLSH,   RPRN,    S_PERC,
        //.--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
            _______, KC_1,    KC_2,    KC_3,    GBP,    XXXXXXX, _______,     _______, _______,  XXXXXXX, S_EQL, KC_COMM, KC_DOT,   _______,
        //.--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                             CAD,     XXXXXXX, KC_ENT,  XXXXXXX, _______,     _______, OS_SHFT, _______, XXXXXXX, XXXXXXX
        //                  '--------+--------+--------+--------+--------'  '--------+--------+--------+--------+--------'
        ),

        [SYMBOLS] = LAYOUT_Kyria3x5(
        //.--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------.
<<<<<<< HEAD
            _______, _______, TILD,    DIAE,    _______,                                       DQUO,    ACUT,    PLUS,    GRV,     _______,
        //.--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------.
<<<<<<< HEAD
            AT,      HASH,   UNDSC,   QUESSFT, S_PIPE,                                         LCB,     LBRC,    ASTR,    RBRC,     RCB,
=======
            _______, _______, TILD,    DIAE,    _______,                                       _______, ACUT,    PLUS,    GRV,     _______,
        //.--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------.
            AT,      HASH,   UNDSC,   QUESSFT, S_PIPE,                                          LCB,    LBRC,   ASTR,    RBRC,     RCB,
>>>>>>> MAJER LAYOUT CHANGES
=======
            AT,      HASH,   UNDSC,   QUESSFT, S_PIPE,                                         LCB,     LBRC,   ASTR,    RBRC,     RCB,
>>>>>>> removing unused keys
        //.--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
            _______, _______, _______, _______, _______, _______, XXXXXXX,   _______, _______, _______, EXLMSFT, SEMCOLSFT, COLSFT, _______,
        //.--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                             CAD,     XXXXXXX, _______, _______, _______,    _______, XXXXXXX, _______, XXXXXXX, XXXXXXX
        //                  '--------+--------+--------+--------+--------'  '--------+--------+--------+--------+--------'
        ),

    [NAV] = LAYOUT_Kyria3x5(
        //.--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------.
            CLOSE,  _______,  XXXXXXX, KC_ESC,  XXXXXXX,                                         UNDO,  COPY,    KC_UP,   PASTE,    REDO,
        //.--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------.
            OS_CTRL, OS_ALT,  XXXXXXX, OS_CMD,  ALT_TAB,                                         SP_AS, KC_LEFT, KC_DOWN, KC_RGHT,  _______,
        //.--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
            _______, _______, XXXXXXX, KC_F2,   XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX,  _______, _______, _______, _______, _______,
        //.--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                              CAD,     XXXXXXX, KC_TAB,  OS_SHFT, XXXXXXX,    XXXXXXX, _______,  MS_BSPC, XXXXXXX, _______
        //                  '--------+--------+--------+--------+--------'  '--------+--------+--------+--------+--------'
        ),

    [NAV2] = LAYOUT_Kyria3x5(
        //.--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------.
           _______, _______, _______,  XXXXXXX, XXXXXXX,                                       UNDO,    COPY,     KC_UP,   PASTE,   REDO,
        //.--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------.
           _______,  _______, _______, XXXXXXX, XXXXXXX,                                       _______, PRV_WRD,  KC_DOWN, NXT_WRD, _______,
        //.--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
           _______,  _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, _______, KC_HOME, _______, KC_END, _______,
        //.--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                              XXXXXXX, XXXXXXX, _______, KC_LSFT, XXXXXXX,    XXXXXXX, _______, DEL_BSPC_W, XXXXXXX, XXXXXXX
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
                              _______, XXXXXXX, _______, ALFRED, _______,    _______,  ALFRED, _______, XXXXXXX, _______
        //                  '--------+--------+--------+--------+--------'  '--------+--------+--------+--------+--------'
        ),

    [WINDOWSWINSNAP] = LAYOUT_Kyria3x5(
        //.--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------.
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, G(KC_DOWN),                                   G(KC_UP), XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX,
        //.--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------.
            XXXXXXX, XXXXXXX, XXXXXXX, FULLSCR, G(KC_LEFT),                                  G(KC_RGHT), XXXXXXX , XXXXXXX, XXXXXXX, XXXXXXX,
        //.--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        //.--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                              _______, XXXXXXX, _______, ALFRED, _______,    _______,  ALFRED, _______, XXXXXXX, _______
        //                  '--------+--------+--------+--------+--------'  '--------+--------+--------+--------+--------'
        ),

    [MOUSE_LAYER] = LAYOUT_Kyria3x5(
        //.--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------.
           CLOSE, XXXXXXX,   PRV_TAB, NXT_TAB,  XXXXXXX,                                       FOCUS_D, FOCUS_L, KC_MS_U, FOCUS_R, FOCUS_U,
        //.--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------.
           KC_LCTRL, KC_ACL0, KC_ACL1, KC_ACL2, ALT_TAB,                                        KC_BTN2, KC_MS_L, KC_MS_D, KC_MS_R, _______,
        //.--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
           XXXXXXX, XXXXXXX, PRV_PGE, NXT_PGE, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, _______, KC_WH_L, _______, KC_WH_R, _______,
        //.--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                             CAD, XXXXXXX,     KC_BTN1,  MSWHEEL, _______,   _______, _______, _______, XXXXXXX, XXXXXXX
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
                              CAD,      XXXXXXX, _______, _______, _______, _______, _______, _______, XXXXXXX, XXXXXXX
        //                  '--------+--------+--------+--------+--------'  '--------+--------+--------+--------+--------'
        ),

    [ADJUST] = LAYOUT_Kyria3x5(
        //.--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------.
           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                        XXXXXXX, PM,        LH,     MP,     XXXXXXX,
        //.--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------.
           XXXXXXX,  SCR_SHOT, XXXXXXX, TG_OS, XXXXXXX,                                          XXXXXXX, PW,        PK,     MW,     XXXXXXX,
        //.--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
           XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, RP, XXXXXXX, XXXXXXX, XXXXXXX,
        //.--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                              XXXXXXX, XXXXXXX, _______, _______, XXXXXXX,    XXXXXXX, _______, _______, XXXXXXX, XXXXXXX
        //                  '--------+--------+--------+--------+--------'  '--------+--------+--------+--------+--------'
        ),

    [FN_LAYER] = LAYOUT_Kyria3x5(
        //.--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------.
           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                        XXXXXXX, KC_F9,   KC_F10,  KC_F11, KC_F12,
        //.--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------.
           OS_CTRL, OS_ALT,  XXXXXXX, OS_CMD, XXXXXXX,                                         XXXXXXX, KC_F1,  KC_F2,   KC_F3,  KC_F4,
        //.--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX,  XXXXXXX, KC_F5,   KC_F6,  KC_F7, KC_F8,
        //.--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                             CAD,     XXXXXXX, _______, XXXXXXX, _______,    XXXXXXX, OS_SHFT, _______, XXXXXXX, XXXXXXX
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
