// clang-format on
#include "mrkskk.h"
#include "sendstring_danish.h"
#if defined(COMBO_ENABLE)
#    include "g/keymap_combo.h"  // to make combo def dictionary work
#endif

void matrix_scan_user(void) {
    matrix_scan_window_tab();
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
        case CV:
            return 100;  // do not change
        default:
            return TAPPING_TERM;
    }
}

bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HMR_ENT:
        case MS_BSPC:
        case SPC_NUM:
            return false;
        default:
            return true;
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
        // Vertical combos for Alphas
        case VERTICALX:
        case VERTICALZ:
        case AAE_OE:
        case RV_V:
            return 90;
        case OSLADJUST:
        case TG_MEDIA:
        case TG_MOUSE:
        case SNAKE:
        case CAPS:
            return 35;
        default:
            return COMBO_TERM;  //
    }
}
#endif

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [BASE_LAYER] = LAYOUT_Kyria3x5(

        //.--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------.
            KC_W,    KC_C,    KC_G,   KC_M,     KC_Q,                                          S_QUOT, KC_U,    KC_K,     KC_J,   DK_AA,
        //|--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------|
            HOME_R,  HOME_S,  NAV2_T, HOME_H,   KC_F,                                          KC_Y,   HOME_I,  NAV2_E,   HOME_O,  HOME_A,
        //.--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
            KC_V,    KC_B,    HOME_L, KC_D,     KC_X,   XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, KC_Z,   KC_P,    HOME_CO,  KC_DOT,  DK_AE,
        //.--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                LOCK, XXXXXXX, HMR_ENT, SPC_NUM, XXXXXXX,    XXXXXXX, SYM_N,  MS_BSPC, XXXXXXX, XXXXXXX
        //                  '--------+--------+--------+--------+--------'  '--------+--------+--------+--------+--------'
        ),

    [NUM_LAYER] = LAYOUT_Kyria3x5(
        //.--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------.
            _______, KC_P7,   KC_P8,   KC_P9,   _______,                                       _______, LCB,     PLUS,     RCB, _______,
        //.--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------.
            HOME_P0, HOME_P4, KC_P5,   HOME_P6, EQL,                                           ASTR,    HM_LPRN, MINUS,    HM_RPRN, SLSH,
        //.--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
            _______, KC_P1,   HOME_P2, KC_P3,   _______, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, _______, LBRC,    HOME_PCO, RBRC, _______,
        //.--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                             CAD,     XXXXXXX,  XXXXXXX, _______, XXXXXXX,   XXXXXXX, SYM,     DEL_WRD, XXXXXXX, XXXXXXX
        //                  '--------+--------+--------+--------+--------'  '--------+--------+--------+--------+--------'
        ),

     [SYM_AND_NAV_LAYER] = LAYOUT_Kyria3x5(
        //.--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------.
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
            _______, _______, TILD,    DIAE,    _______,                                       DQUO,    ACUT,    PLUS,    GRV,     _______,
        //.--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------.
<<<<<<< HEAD
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
=======
            AT,      HASH,   UNDSC,   OSS_QUES, S_PIPE,                                         LCB,    LBRC,    ASTR,    RBRC,     RCB,
>>>>>>> added alt tab shifted function (copied from metheon)
=======
            _______, _______, TILD,    DIAE,   _______,                                         _______, _______, PLUS,   _______, _______,
        //.--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------.
            AT,      HASH,    UNDSC,   QUES,   S_PIPE,                                          S_LBRC,   LCB,    ASTR,   RCB,    S_RBRC,
>>>>>>> mod layer, home row shift. and other stuff
=======
            _______, _______, TILD,    DIAE,   _______,                                         HAT,    _______, PLUS,   _______, _______,
        //.--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------.
            AT,      HASH,    UNDSC,   QUES,   _______,                                          LCB,   _______, ASTR,   _______,    RCB,
>>>>>>> move symbols so they match num layer shifted symbols
=======
            _______, _______, TILD,    DIAE,   _______,                                         DQUO,    LBRC,   PLUS,     RBRC,    _______,
        //.--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------.
            AT,      HASH,    UNDSC,   QUES,   BSLH,                                            HAT,     LCB,    ASTR,     RCB,     AMPR,
>>>>>>> osm shift after alpha and enter.
        //.--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
            _______, _______, ACUT,    GRV,    _______, XXXXXXX, XXXXXXX,    XXXXXXX,  XXXXXXX, _______, EXLM,   SEMCOL,   COL,     _______,
=======
            TILD,    LABK,    MINUS,    RABK,   PLUS,                                            ASTR,  LBRC,    HASH,  RBRC,    BSLH,
        //.--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------.
            AT,      LPRN,    UNDSC,    RPRN,   MINUS,                                           SLSH,  LCB,     QUES,   RCB,     AMPR,
>>>>>>> went back to home row mods
=======
            TILD,    LABK,    HAT,     RABK,     _______,                                      KC_HOME, KC_PGUP, KC_UP,   KC_PGDN,  KC_END,
        //.--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------.
            HM_EXLM, HM_HASH, QUES,    HM_UNDSC, BSLH,                                         _______, KC_LEFT, KC_DOWN, KC_RGHT,  AT,
>>>>>>> new changes to sym and num layer
=======
            TILD,    LABK,    HAT,     RABK,    _______,                                      KC_HOME,  KC_PGUP, KC_UP,   KC_PGDN,  KC_END,
        //.--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------.
<<<<<<< HEAD
            HM_EXLM, HM_HASH, UNDSC,   HM_QUES, BSLH,                                         PAIR_QUO, KC_LEFT, KC_DOWN, KC_RGHT,  AT,
>>>>>>> minor changes to keymap
=======
            HM_EXLM, HM_HASH, UNDSC,   HM_QUES, PERC,                                         DQUO,     KC_LEFT, KC_DOWN, KC_RGHT,  AT,
>>>>>>> extra nav layer and changes to num-sym layers.
        //.--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
            DIAE,    ACUT,    HM_PIPE, GRV,     _______, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,  BSLH,    HM_SEMC,  COL, _______,
        //.--------+--------+--------+--------+--------+--------+--------|  |--------+--------+---------+--------+--------+--------+--------|
                             CAD,     XXXXXXX, _______, EXTRA_SYM, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX
        //                  '--------+--------+--------+--------+--------'  '--------+--------+--------+--------+--------'
        ),

    [EXTRA_NAV_LAYER] = LAYOUT_Kyria3x5(
        //.--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------.
            KC_END, KC_PGDN, KC_UP,   KC_PGUP, KC_HOME,                                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        //.--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------.
            XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX,                                        XXXXXXX, KC_LGUI, XXXXXXX, KC_LALT, KC_RSFT,
        //.--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
            XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_RCTL, XXXXXXX, XXXXXXX,
        //.--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                              CAD,     XXXXXXX, _______,  _______, XXXXXXX,   XXXXXXX, _______,  _______, XXXXXXX, _______
        //                  '--------+--------+--------+--------+--------'  '--------+--------+--------+--------+--------'
        ),

     [NAV2_LAYER] = LAYOUT_Kyria3x5(
        //.--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------.
           _______, _______, XXXXXXX, KC_ESC,  _______,                                        S_HOME,  S_PRV_W,  KC_UP,   S_NXT_W, S_END,
        //.--------+--------+--------+--------+--------.                                      .--------+--------+--------+-------+--------.
           KC_LSFT, KC_LALT, XXXXXXX, KC_LGUI, NXT_TAB,                                        ALT_TAB, PRV_WRD,  KC_DOWN, NXT_WRD, KC_RSFT,
        //.--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
           _______, _______, XXXXXXX, KC_TAB,  _______,  XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, _______, _______, KC_RCTL, _______, _______,
        //.--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                             XXXXXXX, XXXXXXX, UNDOREDO, CPYPASTE, XXXXXXX,  XXXXXXX, _______, DEL_WRD, XXXXXXX, XXXXXXX
        //                  '--------+--------+--------+--------+--------'  '--------+--------+--------+--------+--------'
        ),

     [EDIT_LAYER] = LAYOUT_Kyria3x5(
        //.--------+--------+--------+--------+--------.                                       .--------+--------+--------+--------+--------.
            _______, _______, _______, KC_ESC, _______,                                         _______, REPLACE, _______, _______, _______,
        //.--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------.
            KC_LSFT, KC_LALT, KC_F2,   KC_LGUI, NXT_TAB,                                        ALT_TAB, FIND,    XXXXXXX, _______, _______,
        //.--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
           _______, _______,  KC_LCTL, KC_TAB, _______,  XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______,
        //.--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                              CAD,     XXXXXXX, SP_AS,  ALFRED, XXXXXXX,      XXXXXXX, _______, _______, XXXXXXX, _______
        //                  '--------+--------+--------+--------+--------'  '--------+--------+--------+--------+--------'
        ),

     [WINDOW_MANAGE_LAYER] = LAYOUT_Kyria3x5(
        //.--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------.
            one_6,  two_6,   three_6, one_4,  two_4,                                           three_4, four_4, XXXXXXX, XXXXXXX,  XXXXXXX,
        //.--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------.
            four_6, five_6,  sixth_6, three_4, four_4,                                         MIDDLE,  FULLSCR, ALFRED, _______, _______,
        //.--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
            one_3,  two_3,   three_3, wLAYOUT,  LEFT,    XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, RIGHT,   XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,
        //.--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                              _______, XXXXXXX, _______, _______, XXXXXXX,  XXXXXXX, _______, _______, XXXXXXX, _______
        //                  '--------+--------+--------+--------+--------'  '--------+--------+--------+--------+--------'

        ),

    [MOUSE_LAYER] = LAYOUT_Kyria3x5(
        //.--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------.
           ZOOMIN,  PRV_PGE, NXT_PGE, KC_ESC,  XXXXXXX,                                       FOCUS_D, FOCUS_L, KC_MS_U, FOCUS_R, FOCUS_U,
        //.--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------.
           KC_LCTL, KC_ACL0, KC_ACL1, KC_ACL2, NXT_TAB,                                        ALT_TAB, KC_MS_L, KC_MS_D, KC_MS_R, KC_RSFT,
        //.--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
           ZOOMOUT, ALL,     XXXXXXX, KC_TAB, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, KC_BTN2, KC_WH_L, XXXXXXX, KC_WH_R, XXXXXXX,
        //.--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                             CAD, XXXXXXX,     KC_BTN1,  MSWHEEL, _______,   XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX
        //                  '--------+--------+--------+--------+--------'  '--------+--------+--------+--------+--------'
        ),

    [MEDIA_LAYER] = LAYOUT_Kyria3x5(
        //.--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------.
             TO_BASE, TO_BASE, TO_BASE, TO_BASE, TO_BASE,                                      TO_BASE, TO_BASE, KC_VOLU, TO_BASE, TO_BASE,
        //.--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------.
             TO_BASE, TO_BASE, TO_BASE, TO_BASE, TO_BASE,                                       TO_BASE, KC_MPRV, KC_VOLD, KC_MNXT, TO_BASE,
        //.--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
             TO_BASE, TO_BASE, TO_BASE, TO_BASE, TO_BASE,  XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, TO_BASE, TO_BASE, TO_BASE, TO_BASE, TO_BASE,
        //.--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                              CAD,      XXXXXXX, KC_MUTE, KC_MPLY, _______,     _______, KC_MPLY, KC_MUTE, XXXXXXX, XXXXXXX
        //                  '--------+--------+--------+--------+--------'  '--------+--------+--------+--------+--------'
        ),

    [ADJUST_LAYER] = LAYOUT_Kyria3x5(
        //.--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------.
           XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,                                       XXXXXXX,  PM,        LH,     MP,     XXXXXXX,
        //.--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------.
           XXXXXXX, SCR_SHOT, CAD,    TG_OS,    XXXXXXX,                                       XXXXXXX,  PW,        PK,     MW,     XXXXXXX,
        //.--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        //.--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                              XXXXXXX, XXXXXXX, _______, _______, XXXXXXX,    XXXXXXX, _______, _______, XXXXXXX, XXXXXXX
        //                  '--------+--------+--------+--------+--------'  '--------+--------+--------+--------+--------'
        ),

    [FN_LAYER] = LAYOUT_Kyria3x5(
        //.--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------.
           KC_F11,   KC_F7,  KC_F8,   KC_F9,   TO_BASE,                                         TO_BASE, TO_BASE, TO_BASE, TO_BASE, TO_BASE,
        //.--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------.
           KC_F10,   KC_F4,  KC_F5,   KC_F6,   TO_BASE,                                         TO_BASE, KC_LGUI, KC_LALT, KC_LCTL, KC_RSFT,
        //.--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
           KC_F12,   KC_F1,  KC_F2,   KC_F3,   TO_BASE, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX,  TO_BASE, TO_BASE, TO_BASE, TO_BASE, TO_BASE,
        //.--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                             CAD,     XXXXXXX, _______, XXXXXXX, _______,    XXXXXXX, _______, _______, XXXXXXX, XXXXXXX
        //                  '--------+--------+--------+--------+--------'  '--------+--------+--------+--------+--------'
        ),



};
// clang format on
