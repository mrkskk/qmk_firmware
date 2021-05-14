#include "mrkskk.h"
#include "sendstring_danish.h"
#if defined(COMBO_ENABLE)
#include "g/keymap_combo.h" // to make combo def dictionary work
#endif

void matrix_scan_user(void)
{
    /*
#if defined(ENCODER_ENABLE)
    matrix_scan_encoders();
#endifY
*/
#if defined(LEADER_ENABLE)
    matrix_scan_leader();
#endif
}

//With TAPPING_FORCE_HOLD, the second press will be interpreted as a modifier, allowing to use it as a modifier shortly after having used it as a tap.
bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        default:
            return true;
    }
}

//Setting per key tapping term. registers as TAP when time < TAPPING_TERM and registers as HOLD when time > TAPPING_TERM.
 uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HOME_A:
        case HOME_S:
        case HOME_D:
        case HOME_F:
        // Right-hand home row mods
        case HOME_J:
        case HOME_K:
        case HOME_L:
        case HOME_QT:
        //HANDSDOWN
        // Left-hand home row mods
        case CTL_R:
        case NAV_T:
        case COMD_H:
        // Right-hand home row mods
        case COMD_I:
        case NAV_E:
        case ALT_O:
        case CTL_A:
            return 200;
        default:
            return TAPPING_TERM;       //
    }
}

#ifdef COMBO_ENABLE
bool get_combo_must_tap(uint16_t index, combo_t *combo) {
    // If you want all combos to be tap-only, just uncomment the next line
    // return true

    // If you want *all* combos, that have Mod-Tap/Layer-Tap/Momentary keys in its chord, to be tap-only, this is for you:
    uint16_t key;
    uint8_t idx = 0;
    while ((key = pgm_read_word(&combo->keys[idx])) != COMBO_END) {
        switch (key) {
            case QK_MOD_TAP...QK_MOD_TAP_MAX:
            //case QK_LAYER_TAP...QK_LAYER_TAP_MAX: // If this is enabled the LT(SHORCUTS,KC_F2) key does not work.
            case QK_MOMENTARY...QK_MOMENTARY_MAX:
                return true;
        }
        idx += 1;
    }
    return false;

}

uint16_t get_combo_term(uint16_t index, combo_t *combo) {
    switch (index) {

        //thumbs
        case HMR_N:
        case FN_BSPC_TRNS_HMR:
        case COMBO_NAV2_F2:
             return 400;
        //danish  combos
        case AE_AE:
        case OE_OE:
        case AO_AA:
            return 60;
        case AAE_OE:
        case RV_V:
        case COPY:
        case PASTE:
        case UNDO:
        case REDO:
            return 90;
        case SPC_N_CAPSWRD:
            return 60;
        default:
            return COMBO_TERM; //
    }
    }
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] =
{
    [QWERTY] = LAYOUT_Kyria3x5(
 //.--------+--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------+--------.
            KC_Q,     KC_W,    KC_E,   KC_R,    KC_T,                                            KC_Y,    KC_U,    KC_I,      KC_O,    KC_P,
// |--------+--------+--------+--------+--------+--------|                                      |--------+--------+--------+--------+--------+--------|
            HOME_A,   HOME_S,  HOME_D, HOME_F,  KC_G,                                            KC_H,    HOME_J,  HOME_K,    HOME_L,  HOME_QT,
// |--------+--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+-------esc-------+--------+--------+--------|
            KC_Z,     BOT_X,   NAV2_C,   KC_V,  KC_B,      TRNS,     TRNS,     TRNS,      TRNS,  KC_N,    KC_M,    NAV2_COMM, BOT_DOT, MINUS,
// |--------+--------+--------+--------+--------+--------+-SC-F2--+--------|  |--------+--------+--------+--------+--------+--------+--------+--------|
                               LOCK,  TRNS,   SYM_TAB,  SFT_SPC,  NUM_ENT,  NUM_BSPC,  SFT_N, SYM_DEL,   TRNS, TRNS
 //                           '--------+--------+--------+--------+--------'  '--------+--------+--------+--------+--------'
    ),


    [HANDSDOWN_ALT_NX_DK_MOD] = LAYOUT_Kyria3x5(
                                                                /*N is moved to right hand*/

 //.--------+--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------+--------.
            KC_W,   KC_C,    KC_G,    KC_M,     KC_Q,                                            QUOT,    KC_U,    KC_K,     KC_J,    DK_AA,
// |--------+--------+--------+--------+--------+--------|                                  |--------+--------+--------+--------+--------+--------|
            CTL_R,  HOME_S,  NAV_T,  COMD_H,    KC_F,                                            KC_Y,    COMD_I,  NAV_E,    ALT_O,   CTL_A,
// |--------+--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+-------esc-------+--------+--------+--------|
            KC_V,   BOT_B,   NAV2_L,  KC_D,     KC_X,     TRNS,      TRNS,     SCR_SHOT,  TRNS,  KC_Z,    KC_P,    NAV2_COMM, BOT_DOT, DK_AE,
// |--------+--------+--------+--------+--------+--------+-SC-F2--+--------|  |--------+--------+--------+--------+--------+--------+--------+--------|
                               LOCK,  TRNS,   SYM_TAB,  SFT_SPC,  NUM_ENT,     NUM_BSPC,  SFT_N, SYM_DEL, HMR_ESC, TRNS
 //                           '--------+--------+--------+--------+--------'  '--------+--------+--------+--------+--------'
    ),

    [NUMPAD_FN] = LAYOUT_Kyria3x5(
 //.--------+--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------+--------.
            KC_F12,    KC_F7,  KC_F8,   KC_F9,   MINUS,                                          SLSH,    KC_7,     KC_8,    KC_9,     KC_0,
// |--------+--------+--------+--------+--------+--------|                                      |--------+--------+--------+--------+--------+--------|
            KC_F11,    KC_F4,   KC_F5,  KC_F6,    PLUS,                                           ASTR,    KC_4,     KC_5,    KC_6,     KC_DOT,
// |--------+--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------+--------|
            KC_F10,    KC_F1,   KC_F2,  KC_F3,    EQL,    TRNS,   TRNS,          TRNS,   TRNS,    EQL,     KC_1,     KC_2,    KC_3,     KC_COMM,
// |--------+--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------+--------|
                                 CAD,    TO_BASE ,   TRNS,    TRNS,   TRNS,        TRNS,   TRNS,    TRNS,   TRNS,     TRNS
 //                           '--------+--------+--------+--------+--------'  '--------+--------+--------+--------+--------'
    ),

    [SYMBOLS] = LAYOUT_Kyria3x5(
 //.--------+--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------+--------.
             DIAE,      DQUO,   LCB,     RCB,     BSLH,                                          SLSH,   PERC,    ACUT,     GRV,     EUR,
// |--------+--------+--------+--------+--------+--------|           i                          |--------+--------+--------+--------+--------+--------|
             HAT,       AT,     LPRN,    RPRN,    HASH,                                          ASTR,   QUES,    MINUS,    UNDSC,   USD,
// |--------+--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------+--------|
             TILD,      EXLM,   LBRC,    RBRC,    PIPE,    TRNS,     TRNS,      TRNS,    TRNS,   EQL,    AMPR,    LABK ,    RABK,    GBP,
// |--------+--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------+--------|
                                 CAD,    TO_BASE,    TRNS,   TRNS,     TRNS,     TRNS,     QUOT,     TRNS,  KC_NO,     KC_NO
 //                           '--------+--------+--------+--------+--------'  '--------+--------+--------+--------+--------'
    ),

    [NAV] = LAYOUT_Kyria3x5(
 //.--------+--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------+--------.
             KC_ESC,  TRNS,    PRV_TAB, NXT_TAB,  TRNS,                                           TRNS,  PRV_WRD, SCROLL_DN, SCROLL_UP, NXT_WRD,
// |--------+--------+--------+--------+--------+--------|                                      |--------+--------+--------+--------+--------+--------|
             TRNS,    KC_LALT,  ALFRED,  ALT_TAB,  TRNS,                                           TRNS,  KC_LEFT, KC_DOWN,   KC_UP,     KC_RGHT,
// |--------+--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------+--------|
             TRNS,     TRNS,   TRNS, TRNS, TRNS,     TRNS,    TRNS,      TRNS,   TRNS,     TRNS,  KC_HOME, KC_PGDN,   KC_PGUP,   KC_END,
// |--------+--------+--------+--------+--------+--------+--------+--------|  |--------+------+--------+--------+--------+--------+--------+--------|
                                CAD,   TO_BASE,   TRNS,  KC_LSFT, SP_AS,     BSPC_WRD_SENT,    TRNS,    DEL_WRD_SENT,    TRNS,    TRNS
 //                           '--------+--------+--------+--------+--------'  '--------+--------+--------+--------+--------'
    ),

    [NAV2] = LAYOUT_Kyria3x5(
 //.--------+--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------+--------.
             TRNS,     TRNS,     TRNS,    TRNS,    TRNS,                                         TRNS,     TRNS,     TRNS, TRNS,     TRNS,
// |--------+--------+--------+--------+--------+--------|                                      |--------+--------+--------+--------+--------+--------|
             TRNS,     TRNS,     TRNS,    TRNS,   TRNS,                                          UNDO,    CUT,      COPY,  PASTE,    REDO,
// |--------+--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------+--------|
             TRNS,     TRNS,     TRNS,    TRNS,    TRNS,  TRNS,    TRNS,        TRNS,      TRNS, TRNS,    TRNS,     UNDO,    REDO,   TRNS,
// |--------+--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------+--------|
                                 SLEEP,   TO_BASE,    TRNS,  TRNS,    SP_AS,      TRNS,  TRNS, TRNS, TRNS,    TRNS
 //                           '--------+--------+--------+--------+--------'  '--------+--------+--------+--------+--------'
    ),

    [HAMMERSPOON] = LAYOUT_Kyria3x5(
 //.--------+--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------+--------.
            one_6,   two_6,   three_6, one_4,    two_4,                                          three_4, four_4, four_6, five_6, sixth_6,
// |--------+--------+--------+--------+--------+--------|                                      |--------+--------+--------+--------+--------+--------|
            one_3,   two_3,  three_3,  fullscr,  Left_half,                                     right_half, FOCUS_L, FOCUS_D,  FOCUS_U, FOCUS_R,
// |--------+--------+--------+-------tab-------+--------+--------+--------|  |--------+--------+--------+-------esc-------+--------+--------+--------|
            KC_NO,     KC_NO,  KC_NO, vlayout,   midt,     KC_NO,  KC_NO,    KC_NO,  KC_NO,    midt,    KC_NO,    KC_NO, KC_NO, KC_NO,
// |--------+--------+--------+--------+--------+-------+-SC-F2--+--------|  |--------+--------+--------+--------+--------+--------+--------+--------|
                               TRNS,  TO_BASE,     KC_NO,     KC_NO,  KC_NO,     KC_NO,  KC_NO, KC_NO,   KC_NO, TRNS
 //                           '--------+--------+--------+--------+--------'  '--------+--------+--------+--------+--------'
    ),

    [MEDIA_LAYER] = LAYOUT_Kyria3x5(
 //.--------+--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------+--------.
            KC_NO ,   KC_NO, KC_NO,  KC_NO,  KC_NO,                                              KC_NO,   KC_NO,   KC_BRID,   KC_BRIU,   KC_NO,
// |--------+--------+--------+--------+--------+--------|                                      |--------+--------+--------+--------+--------+--------|
            KC_NO,    KC_NO, KC_NO,  KC_NO,  KC_NO,                                              KC_NO,   KC_MPRV, KC_VOLD,   KC_VOLU,   KC_MNXT,
// |--------+--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------+--------|
            KC_NO,    KC_NO, KC_NO,  KC_NO,  KC_NO,    KC_NO,   KC_NO,      KC_NO,   KC_NO,      KC_NO,   KC_NO,  KC_NO,   KC_NO,   KC_NO,
// |--------+--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------+--------|
                                  CAD,   TO_BASE, TO_BASE, TO_BASE, TO_BASE,    KC_MSTP, KC_MPLY, KC_MUTE,    TRNS,   KC_NO
 //                           '--------+--------+--------+--------+--------'  '--------+--------+--------+--------+--------'
    ),

    [MOUSE_LAYER] = LAYOUT_Kyria3x5(
 //.--------+--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------+--------.
            KC_NO ,   KC_NO,   KC_NO,  KC_NO,  KC_NO,                                              KC_NO,   KC_ACL0,   KC_ACL1,  KC_ACL2,   KC_NO,
// |--------+--------+--------+--------+--------+--------|                                      |--------+--------+--------+--------+--------+--------|
            KC_NO,    KC_NO,   KC_NO,  KC_NO,  KC_NO,                                              KC_NO,   KC_MS_L, KC_MS_D,   KC_MS_U,   KC_MS_R,
// |--------+--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------+--------|
            KC_NO,    KC_NO,   KC_NO,  KC_NO,  KC_NO,    KC_NO,   KC_NO,      KC_NO,   KC_NO,      KC_NO,   KC_WH_L,  KC_WH_D,  KC_WH_U,  KC_WH_R,
// |--------+--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------+--------|
                               CAD,    TO_BASE,   TO_BASE, TO_BASE, TO_BASE,  KC_BTN2, KC_BTN1, KC_BTN3,    TRNS,   KC_NO
 //                           '--------+--------+--------+--------+--------'  '--------+--------+--------+--------+--------'
    ),

    [ADJUST] = LAYOUT_Kyria3x5(
//.--------+--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------+--------.
            L_QWERTY,    KC_NO,  KC_NO,  KC_NO,   KC_NO,                                        KC_NO,     PM,      LH,      MP,    KC_NO,
// |--------+--------+--------+--------+--------+--------|                                      |--------+--------+--------+--------+--------+--------|
            L_HANDSDOWN, KC_NO,  KC_NO,  TG_OS,   KC_NO,                                        KC_NO,     PW,      PK,      MW,    KC_NO,
// |--------+--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------+--------|
            KC_NO,       KC_NO,  KC_NO,  KC_NO,   KC_NO,   KC_NO,  KC_NO,    KC_NO,    KC_NO,   KC_NO,     KC_NO,   KC_NO,   KC_NO, KC_NO,
// |--------+--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------+--------|
                                 KC_NO,  TO_BASE,   KC_NO,   KC_NO,  KC_NO,    KC_NO,    KC_NO,   KC_NO,    KC_NO,    KC_NO
 //                           '--------+--------+--------+--------+--------'  '--------+--------+--------+--------+--------'
    ),

/*
    [TEMPLATE] = LAYOUT_Kyria3x5(
//.--------+--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------+--------.
            TRNS,     TRNS,    TRNS,    TRNS,    TRNS,                                           TRNS,     TRNS,    TRNS,   TRNS,    TRNS,
// |--------+--------+--------+--------+--------+--------|                                      |--------+--------+--------+--------+--------+--------|
            TRNS,     TRNS,    TRNS,    TRNS,    TRNS,                                           TRNS,     TRNS,    TRNS,   TRNS,    TRNS,
// |--------+--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------+--------|
            TRNS,     TRNS,    TRNS,    TRNS,    TRNS,    TRNS,    TRNS,        TRNS,   TRNS,    TRNS,    TRNS,    TRNS,    TRNS,     TRNS,
// |--------+--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------+--------|
                                TRNS,    TRNS,    TRNS,   TRNS,      TRNS,      TRNS,   TRNS,     TRNS,     TRNS,   TRNS
 //                           '--------+--------+--------+--------+--------'  '--------+--------+--------+--------+--------'
    ),
*/

};
