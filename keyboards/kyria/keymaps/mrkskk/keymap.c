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
        case HOME_R:
        case HOME_A:
            return 140;
        case SPC_NUM:
        case HOME_S:
        case NAV2_T:
        case HOME_H:
        case HOME_I:
        case NAV2_E:
        case HOME_O:
        case HOME_P0:
        case HOME_P4:

        case HOME_P6:
        case HMR_ENT:
        case SYM_N:
            return 165;
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
        // Vertical combos for Alphas
        case VERTICALX:
        case VERTICALZ:
        case AAE_OE:
        case RV_V:
        case SPC_N_CAPSWRD:
            return 90;
        case OSLADJUST:
        case TG_MEDIA:
        case TG_MOUSE:
            return 40;
        default:
            return COMBO_TERM;  //
    }
}
#endif

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [BASE_LAYER] = LAYOUT_Kyria3x5(


        //.--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------.
            KC_W,   KC_C,    KC_G,   KC_M,     KC_Q,                                           S_QUOT,   KC_U,    KC_K,     KC_J,   DK_AA,
        //|--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------|
            HOME_R,  HOME_S,  NAV2_T,  HOME_H,   KC_F,                                           KC_Y,   HOME_I,  NAV2_E,    HOME_O,  HOME_A,
        //.--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
            KC_V,   KC_B,    KC_L,   HOME_D,     KC_X,    XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, KC_Z,   HOME_P,    KC_COMM, KC_DOT,  DK_AE,
        //.--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                LOCK, XXXXXXX, HMR_ENT, SPC_NUM, XXXXXXX,    XXXXXXX, SYM_N,  MS_BSPC, XXXXXXX, XXXXXXX
        //                  '--------+--------+--------+--------+--------'  '--------+--------+--------+--------+--------'
        ),
    [NUM_LAYER] = LAYOUT_Kyria3x5(
        //.--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------.
            GBP, KC_P7,   KC_P8,   KC_P9, PLUS,                                                ASTR , KC_PGUP,  KC_UP,   KC_PGDN,   EUR,
        //.--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------.
            HOME_P0, HOME_P4, KC_P5, HOME_P6,   MINUS,                                         SLSH,  KC_LEFT, KC_DOWN, KC_RGHT,   EQL,
        //.--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
            _______, KC_P1,   KC_P2,   KC_P3, EQL,  XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX,  XXXXXXX, KC_HOME,  KC_PDOT, KC_END,    USD,
        //.--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                             CAD,     XXXXXXX, XXXXXXX,  _______, XXXXXXX,   XXXXXXX,     SYM,  DEL_BS_W,     XXXXXXX, XXXXXXX
        //                  '--------+--------+--------+--------+--------'  '--------+--------+--------+--------+--------'
        ),

    [SYM_LAYER] = LAYOUT_Kyria3x5(
        //.--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------.
            TILD,    LABK,    MINUS,    RABK,   PLUS,                                            ASTR,  LBRC,    HASH,  RBRC,    BSLH,
        //.--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------.
            AT,      LPRN,    UNDSC,    RPRN,   MINUS,                                           SLSH,  LCB,     QUES,   RCB,     AMPR,
        //.--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
            DIAE,    ACUT,    EQL,    GRV,     EQL,   XXXXXXX, XXXXXXX,      XXXXXXX,  XXXXXXX,  XXXXXXX,    PERC,   EXLM,    HAT,   PIPE,
        //.--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--s------+--------+--------+--------+--------|
                              CAD,     XXXXXXX, _______, _______, XXXXXXX,   XXXXXXX,  _______, _______, XXXXXXX, XXXXXXX
        //                  '--------+--------+--------+--------+--------'  '--------+--------+--------+--------+--------'
        ),

    [EDIT_LAYER] = LAYOUT_Kyria3x5(
        //.--------+--------+--------+--------+--------.                                       .--------+--------+--------+--------+--------.
            _______, PRV_PGE, NXT_PGE, KC_ESC, _______,                                         REPLACE, _______, _______, _______, _______,
        //.--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------.
            UNDO,    COPY,    PASTE,   REDO,   _______,                                         FIND,   _______, _______, _______, _______,
        //.--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
           _______, _______,  NXT_TAB,  KC_TAB, _______,  XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, _______, _______, _______, _______, _______,
        //.--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                              CAD,     XXXXXXX, _______,  APP_SWI, XXXXXXX,  XXXXXXX, _______,  _______, XXXXXXX, _______
        //                  '--------+--------+--------+--------+--------'  '--------+--------+--------+--------+--------'
        ),

    [NAV2_LAYER] = LAYOUT_Kyria3x5(
        //.--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------.
           _______, _______,  _______, KC_ESC, _______,                                         UNDRLINE, S_PRV_W, KC_UP,   S_NXT_W, _______,
        //.--------+--------+--------+--------+--------.                                      .--------+--------+--------+-------+--------.
           MYMOD,   _______,  _______, KC_F2,  SP_AS,                                          BOLD,     PRV_WRD, KC_DOWN, NXT_WRD, _______,
        //.--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
           _______, _______,  _______, KC_TAB, _______,  XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, ITALIC,   S_HOME, _______,    S_END, _______,
        //.--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                              XXXXXXX, XXXXXXX, UNDOREDO, COPYPASTE, XXXXXXX,       XXXXXXX, _______,   DEL_BS_W, XXXXXXX, XXXXXXX
        //                  '--------+--------+--------+--------+--------'  '--------+--------+--------+--------+--------'
        ),

    [WINDOW_MANAGE_LAYER] = LAYOUT_Kyria3x5(
        //.--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------.
            one_6,  two_6,   three_6, one_4,  two_4,                                           three_4, four_4, XXXXXXX, XXXXXXX,  XXXXXXX,
        //.--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------.
            four_6, five_6,  sixth_6, three_4, four_4,                                         MIDDLE,  FULLSCR, ALFRED, _______, _______,
        //.--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
            one_3,  two_3,   three_3, wLAYOUT,  LEFT, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX,   RIGHT, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,
        //.--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                              _______, XXXXXXX, _______,  _______ , XXXXXXX,     XXXXXXX, _______, _______, XXXXXXX, _______
        //                  '--------+--------+--------+--------+--------'  '--------+--------+--------+--------+--------'

        ),

    [MOUSE_LAYER] = LAYOUT_Kyria3x5(
        //.--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------.
           ZOOMIN,  PRV_PGE, NXT_PGE, KC_ESC,  XXXXXXX,                                       FOCUS_D, FOCUS_L, KC_MS_U, FOCUS_R, FOCUS_U,
        //.--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------.
           OS_CTRL, KC_ACL0, KC_ACL1, KC_ACL2, NXT_TAB,                                        KC_BTN2, KC_MS_L, KC_MS_D, KC_MS_R, _______,
        //.--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
           ZOOMOUT, ALL,     _______, KC_TAB, XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, _______, KC_WH_L, _______, KC_WH_R, _______,
        //.--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                             CAD, XXXXXXX,     KC_BTN1,  MSWHEEL, _______,   XXXXXXX, XXXXXXX, _______, XXXXXXX, XXXXXXX
        //                  '--------+--------+--------+--------+--------'  '--------+--------+--------+--------+--------'
        ),

    [MEDIA_LAYER] = LAYOUT_Kyria3x5(
        //.--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------.
             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                      XXXXXXX, XXXXXXX, KC_VOLU, XXXXXXX, XXXXXXX,
        //.--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------.
             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                      XXXXXXX, KC_MPRV, KC_VOLD, KC_MNXT, XXXXXXX,
        //.--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        //.--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                              CAD,      XXXXXXX, KC_MUTE, KC_MPLY, _______,     _______, KC_MPLY, KC_MUTE, XXXXXXX, XXXXXXX
        //                  '--------+--------+--------+--------+--------'  '--------+--------+--------+--------+--------'
        ),

    [ADJUST_LAYER] = LAYOUT_Kyria3x5(
        //.--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------.
           CAD,     XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,                                       XXXXXXX,  PM,        LH,     MP,     XXXXXXX,
        //.--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------.
           XXXXXXX, SCR_SHOT, XXXXXXX, TG_OS, XXXXXXX,                                         XXXXXXX,  PW,        PK,     MW,     XXXXXXX,
        //.--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        //.--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                              XXXXXXX, XXXXXXX, _______, _______, XXXXXXX,    XXXXXXX, _______, _______, XXXXXXX, XXXXXXX
        //                  '--------+--------+--------+--------+--------'  '--------+--------+--------+--------+--------'
        ),

    [FN_LAYER] = LAYOUT_Kyria3x5(
        //.--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------.
           KC_F11,   KC_F7,  KC_F8,   KC_F9,   XXXXXXX,                                         XXXXXXX, XXXXXXX,  XXXXXXX,  XXXXXXX, XXXXXXX,
        //.--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------.
           KC_F10,   KC_F4,  KC_F5,   KC_F6,   XXXXXXX,                                         XXXXXXX, OS_CMD,  OS_ALT,  OS_CTRL, OS_SHFT,
        //.--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
           KC_F12,   KC_F1,  KC_F2,   KC_F3,   XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX,  XXXXXXX, CLEAR,   XXXXXXX,  XXXXXXX, XXXXXXX,
        //.--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                             CAD,     XXXXXXX, _______, XXXXXXX, _______,    XXXXXXX, _______, _______, XXXXXXX, XXXXXXX
        //                  '--------+--------+--------+--------+--------'  '--------+--------+--------+--------+--------'
        ),



};
// clang format on
