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
        case NAV_CV:
            return 100;  // do not change
        case SPC_NUM:
        case NAV_T:
        case NAV2_H:
        case NAV2_I:
        case HMR_O:
        case MODS_ENT:
        case SYM_N:
        case NAV_E:
        case SFT_R:
        case SFT_A:

            // case :
            return 170;
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
        // Horisontal combos
        /*
        case COPY:
        case PASTE:
        case UNDO:
        case REDO:
        */
        case SPC_N_CAPSWRD:
            return 90;

        default:
            return COMBO_TERM;  //
    }
}
#endif

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [BASE_LAYER] = LAYOUT_Kyria3x5(


        //.--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------.
            KC_W,   KC_C,    KC_G,   KC_M,     KC_Q,                                           QUOT,   KC_U,    KC_K,     KC_J,   DK_AA,
        //|--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------|
            SFT_R,  KC_S,    NAV_T,  NAV2_H,   KC_F,                                           KC_Y,   NAV2_I,  NAV_E,    HMR_O,  SFT_A,
        //.--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
            KC_V,   KC_B,    KC_L,   KC_D,     KC_X,    XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, KC_Z,   KC_P,    KC_COMM, KC_DOT,  DK_AE,
        //.--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                LOCK, XXXXXXX, MODS_ENT, SPC_NUM, XXXXXXX,    XXXXXXX, SYM_N,    MS_BSPC, XXXXXXX, XXXXXXX
        //                  '--------+--------+--------+--------+--------'  '--------+--------+--------+--------+--------'
        ),
    [NUM_LAYER] = LAYOUT_Kyria3x5(
        //.--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------.
            _______, KC_P7,   KC_P8,   KC_P9,    EUR,                                          DQUO,    LABK,    MINUS,  RABK,   _______,
        //.--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------.
            KC_P0,   KC_P4,   KC_P5,   KC_P6,    USD,                                          PERC,    LPRN,    SLSH,   RPRN,   PIPE,
        //.--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
            _______, KC_P1,   KC_P2,   KC_P3,    GBP,  XXXXXXX, XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, EQL,     KC_COMM, KC_PDOT, _______,
        //.--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                             CAD,     XXXXXXX, XXXXXXX,  _______, XXXXXXX,   XXXXXXX,     SYM,  FN,     XXXXXXX, XXXXXXX
        //                  '--------+--------+--------+--------+--------'  '--------+--------+--------+--------+--------'
        ),

    [SYM_LAYER] = LAYOUT_Kyria3x5(
        //.--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------.
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
            _______, _______, ACUT,    GRV, _______, XXXXXXX, XXXXXXX,       XXXXXXX,  XXXXXXX, _______, EXLM,   SEMCOL,   COL,     _______,
        //.--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                              CAD,     XXXXXXX, _______, _______, XXXXXXX,   XXXXXXX, _______, _______, XXXXXXX, XXXXXXX
        //                  '--------+--------+--------+--------+--------'  '--------+--------+--------+--------+--------'
        ),

    [MODS_LAYER] = LAYOUT_Kyria3x5(
        //.--------+--------+--------+--------+--------.                                       .--------+--------+--------+--------+--------.
            _______, _______, _______, _______, _______,                                       _______, _______, _______, _______, _______,
        //.--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------.
            OS_SHFT, OS_CTRL, OS_ALT,  OS_CMD,  _______,                                        _______, OS_CMD,  OS_ALT,  OS_CTRL, OS_SHFT,
        //.--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
            _______, _______, _______, CLEAR,  _______, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, _______, CLEAR, _______, _______, _______,
        //.--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                              CAD,     XXXXXXX, _______,  XXXXXXX, XXXXXXX,    XXXXXXX, _______,  _______, XXXXXXX, _______
        //                  '--------+--------+--------+--------+--------'  '--------+--------+--------+--------+--------'
        ),

    [NAV_LAYER] = LAYOUT_Kyria3x5(
        //.--------+--------+--------+--------+--------.                                       .--------+--------+--------+--------+--------.
            CLOSE,   PRV_PGE, NXT_PGE,    KC_ESC,  _______,                                        REPLACE,  KC_PGUP, KC_UP,   KC_PGDN, _______,
        //.--------+--------+--------+--------+--------.                                       .--------+--------+--------+--------+--------.
            MYMOD, SAVE,    ALFRED,  NEWTAB,  NXT_TAB,                                        FIND,  KC_LEFT, KC_DOWN, KC_RGHT, OS_SHFT,
        //.--------+--------+------- -+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
            _______, ALL,     GSEARCH, KC_TAB,  _______,  XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, _______, KC_HOME, _______, KC_END, _______,
        //.--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                              CAD,     XXXXXXX, UNDOREDO, NAV_CV, XXXXXXX,  XXXXXXX, _______,  DEL_BS_W, XXXXXXX, _______
        //                  '--------+--------+--------+--------+--------'  '--------+--------+--------+--------+--------'
        ),
    [LEFTNAVCLUSTER_LAYER] = LAYOUT_Kyria3x5(
        //.--------+--------+--------+--------+--------.                                       .--------+--------+--------+--------+--------.
            _______, KC_PGUP, KC_UP,   KC_PGDN, _______,                                        _______, _______, _______, _______, _______,
        //.--------+--------+--------+--------+--------.                                       .--------+--------+--------+--------+--------.
            _______, KC_LEFT, KC_DOWN, KC_RGHT, _______,                                        _______, _______, _______, _______, _______,
        //.--------+--------+------- -+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
            _______, KC_HOME, _______, KC_END, _______, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX,   _______, _______, _______, _______, _______,
        //.--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                              CAD,     XXXXXXX, _______, _______, XXXXXXX,  XXXXXXX, _______,   _______, XXXXXXX, _______
        //                  '--------+--------+--------+--------+--------'  '--------+--------+--------+--------+--------'
        ),

    [NAV2_LAYER] = LAYOUT_Kyria3x5(
        //.--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------.
           KC_F7,   KC_F8,   _______, _______, _______,                                        UNDRLINE, S_PRV_W, KC_UP,   S_NXT_W, _______,
        //.--------+--------+--------+--------+--------.                                      .--------+--------+--------+-------+--------.
           OS_SHFT, KC_F9,   ALT_TAB, KC_F2,   _______,                                        BOLD,     PRV_WRD, KC_DOWN, NXT_WRD, OS_SHFT,
        //.--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
           U_TAB,   D_TAB,   L_TAB,   R_TAB,   _______,  XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, ITALIC,   S_HOME, _______,    S_END, _______,
        //.--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                              XXXXXXX, XXXXXXX, SP_AS,   _______, XXXXXXX,       XXXXXXX, _______,   DEL_BS_W, XXXXXXX, XXXXXXX
        //                  '--------+--------+--------+--------+--------'  '--------+--------+--------+--------+--------'
        ),

    [WINDOW_MANAGE_LAYER] = LAYOUT_Kyria3x5(
        //.--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------.
            one_6,  two_6,   three_6, one_4,  two_4,                                           three_4, four_4, XXXXXXX, XXXXXXX,  XXXXXXX,
        //.--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------.
            four_6, five_6,  sixth_6, three_4, four_4,                                         MIDDLE, _______, FULLSCR, _______, _______,
        //.--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
            one_3,  two_3,   three_3, wLAYOUT, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        //.--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                              _______, XXXXXXX, LEFT,   HIDE, XXXXXXX,     XXXXXXX,   SHOW, RIGHT, XXXXXXX, _______
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
           KC_F11, KC_F7, KC_F8, KC_F9, XXXXXXX,                                        XXXXXXX, KC_F9,   KC_F10,  KC_F11, KC_F12,
        //.--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------.
           KC_F10, KC_F4,  KC_F5, KC_F6, XXXXXXX,                                         XXXXXXX, KC_F1,  KC_F2,   KC_F3,  KC_F4,
        //.--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
           KC_F12, KC_F1, KC_F2, KC_F3, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX,  XXXXXXX, KC_F5,   KC_F6,  KC_F7, KC_F8,
        //.--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                             CAD,     XXXXXXX, _______, XXXXXXX, _______,    XXXXXXX, _______, _______, XXXXXXX, XXXXXXX
        //                  '--------+--------+--------+--------+--------'  '--------+--------+--------+--------+--------'
        ),



};
// clang format on
