#include "mrkskk.h"
#include "sendstring_danish.h"
#if defined(COMBO_ENABLE)
#include "g/keymap_combo.h" // to make combo def dictionary work
#endif


// layer_state_t layer_state_set_user(layer_state_t state) {
//  state = update_tri_layer_state(state, NUMPAD, SYMBOLS, ADJUST);
//  return state;
// };

void matrix_scan_user(void)
{
#if defined(ENCODER_ENABLE)
    matrix_scan_encoders();
#endif
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
        case COMD_T:
        case SFT_H:
        // Right-hand home row mods
        case SFT_I:
        case COMD_E:
        case ALT_O:
        case CTL_A:
            return 200;
        default:
            return TAPPING_TERM;       // 175
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
        case COMBO_BSPC_W:
        case COMBO_DEL_W:
            return 400;
        case COMBO_NAV2_F2:
            return 300;
        //danish qwerty combos
        case AE_AE:
        case OE_OE:
        case AO_AA:
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
            KC_Q,     KC_W,    KC_E,   KC_R,    KC_T,                                              KC_Y,    KC_U,   KC_I,     KC_O,   KC_P,
// |--------+--------+--------+--------+--------+--------|                                      |--------+--------+--------+--------+--------+--------|
            HOME_A,   HOME_S,  HOME_D, HOME_F,  KC_G,                                              KC_H,    HOME_J, HOME_K,   HOME_L, HOME_QT,
// |--------+--------+--------+-------tab-------+--------+--------+--------|  |--------+--------+--------+-------esc-------+--------+--------+--------|
            KC_Z,     KC_X,    KC_C,   KC_V,    KC_B,       ALFRED,  TRNS,     SCR_SHOT,  TRNS,    KC_N,    KC_M,    KC_COMM, KC_DOT, MINUS,
// |--------+--------+--------+--------+--------+--------+-SC-F2--+--------|  |-BSPC_W-+-capswrd+------undsc-------+--------+--------+--------+--------|
                               TRNS,  TG_NUM,   NUM_LEAD,  NAV_SPC,  FN_ENT,  HMR_BSPC,  NAV_N, SYM_LEAD,   TRNS, TRNS
 //                           '--------+--------+--------+--------+--------'  '--------+--------+--------+--------+--------'
    ),


    [HANDSDOWN_ALT_NX_DK_MOD] = LAYOUT_Kyria3x5(                 /* A and I is swapped
                                                                    N is moved to right hand*/

 //.--------+--------+--------+--------+--------+--------.                                      .--------+------- Q ------ Z -------+--------+--------.
            KC_W,     KC_C,    KC_G,    KC_M,     MINUS,          /* U + K chord = Q */            QUOT,     KC_U,    KC_K,     KC_J,   DK_AA,
// |--------+--------+--------+--------+--------+--------|          K + J chord = Z             |--------+--------+--------+--------+--------+--------|
            CTL_R,    HOME_S,   COMD_T, SFT_H,    KC_F,                                            KC_Y,     SFT_I,   COMD_E,   ALT_O,  CTL_A,
// |--------+--------+--------+-------tab-------+--------+--------+--------|  |--------+--------+--------+-------esc-------+--------+--------+--------|
            KC_X,     KC_B,    KC_L,    KC_D,     KC_V,     ALFRED,  TRNS,      SCR_SHOT,  TRNS,   DK_AE,    KC_P,    KC_COMM, KC_DOT,  DK_OE,
// |--------+--------+--------+--------+--------+--------+-SC-F2--+--------|  |BSPCWrd-+-capswrd+--------+--------+-------+--------+--------+--------|
                               TRNS,    TG_NUM,   NUM_LEAD,  NAV_SPC, FN_ENT,   HMR_BSPC,  NAV_N,  SYM_LEAD, TRNS, TRNS
 //                           '--------+--------+--------+--------+--------'  '--------+--------+--------+--------+--------'
    ),


    [NUMPAD] = LAYOUT_Kyria3x5(
 //.--------+--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------+--------.
            TO_BASE,  TO_BASE,  TRNS,    TRNS,    MINUS,                                         SLSH,    KC_7,     KC_8,    KC_9,     KC_0,
// |--------+--------+--------+--------+--------+--------|                                      |--------+--------+--------+--------+--------+--------|
            TO_BASE,  TO_BASE,  LPRN,    RPRN,    PLUS,                                          ASTR,    KC_4,     KC_5,    KC_6,     TO_BASE,
// |--------+--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------+--------|
            TO_BASE,  TO_BASE,  TO_BASE, TO_BASE, TO_BASE, TRNS,   TO_BASE,     TRNS,   TO_BASE, TO_BASE, KC_1,     KC_2,    KC_3,     KC_DOT,
// |--------+--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------+--------|
                                 CAD,    TRNS ,   TRNS,    TRNS,   TRNS,        TRNS,   TRNS,    TRNS,   TRNS,     TRNS
 //                           '--------+--------+--------+--------+--------'  '--------+--------+--------+--------+--------'
    ),

    [L_SYMBOLS] = LAYOUT_Kyria3x5(
 //.--------+--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------+--------.
             EXLM,      DQUO,   LCB,     RCB,     EN_EM_DSH,                                      SLSH,     BSLH,   LABK,   RABK,   EQL,
// |--------+--------+--------+--------+--------+--------|                                      |--------+--------+--------+--------+--------+--------|
             AT,        TILD,   LPRN,    RPRN,    HASH,                                           ASTR,     PERC,   ACUT,   GRV,    PIPE,
// |--------+--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------+--------|
             HAT,       DIAE,   LBRC,    RBRC,    QUES,    TRNS,     TRNS,       TRNS,    TRNS,   TRNS,     AMPR,   SEMCOL,  COL,   UNDSC,
// |--------+--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------+--------|
                                 CAD,    TRNS,    TRNS,   TRNS,      TRNS,       TRNS,    TRNS,     TRNS,  TRNS,     TRNS
 //                           '--------+--------+--------+--------+--------'  '--------+--------+--------+--------+--------'
    ),

    [R_SYMBOLS] = LAYOUT_Kyria3x5(
 //.--------+--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------+--------.
             EXLM,      DQUO,   LCB,     RCB,     EN_EM_DSH,                                      SLSH,     BSLH,   LABK,   RABK,   EQL,
// |--------+--------+--------+--------+--------+--------|                                      |--------+--------+--------+--------+--------+--------|
             AT,        TILD,   LPRN,    RPRN,    HASH,                                           ASTR,     PERC,   ACUT,   GRV,    PIPE,
// |--------+--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------+--------|
             HAT,       DIAE,   LBRC,    RBRC,    QUES,    TRNS,     TRNS,       TRNS,    TRNS,   TRNS,     AMPR,   SEMCOL,  COL,   UNDSC,
// |--------+--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------+--------|
                                 CAD,    TRNS,    TRNS,   TRNS,      TRNS,       TRNS,    TRNS,     TRNS,  TRNS,     TRNS
 //                           '--------+--------+--------+--------+--------'  '--------+--------+--------+--------+--------'
    ),

    [NAV] = LAYOUT_Kyria3x5(
 //.--------+--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------+--------.
            TRNS, TRNS, TRNS, TRNS, TRNS,                                                         TRNS, PRVW,    TRNS,   TRNS,    NXTW,
// |--------+--------+--------+--------+--------+--------|                                      |--------+--------+--------+--------+--------+--------|
             TRNS,    TRNS,   TRNS,     TRNS,   TRNS,                                             TRNS,  KC_LEFT, KC_DOWN, KC_UP, KC_RGHT,
// |--------+--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------+--------|
             UNDO,     CUT,     COPY,   PASTE,  REDO,    TRNS,    TRNS,        TRNS,   TRNS,      TRNS, PRV_TAB,  KC_PGDN,    KC_PGUP,    NXT_TAB,
// |--------+--------+--------+--------+--------+--------+--------+--------|  |-DEL_W--+snakecase+--------+--------+--------+--------+--------+--------|
                                SLEEP,   TRNS,     TRNS,    TRNS,    TRNS,       DEL,   SP_AS,   TRNS,    TRNS,    TRNS
 //                           '--------+--------+--------+--------+--------'  '--------+--------+--------+--------+--------'
    ),
    [ADJUST] = LAYOUT_Kyria3x5(
 //.--------+--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------+--------.
            L_QWERTY ,   KC_NO, KC_NO,  KC_NO,  TG_OS,                                            KC_NO,  KC_F7,  KC_F8,   KC_F9,   KC_F12,
// |--------+--------+--------+--------+--------+--------|                                      |--------+--------+--------+--------+--------+--------|
            L_HANDSDOWN, TRNS,  TRNS,   TRNS,  KC_NO,                                             KC_NO,  KC_F4,  KC_F5,   KC_F6,   KC_F11,
// |--------+--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------+--------|
            KC_NO,       KC_NO, KC_LALT, KC_NO,    KC_NO, TRNS,   TRNS,        TRNS,    TRNS,     KC_NO,  KC_F1,  KC_F2,  KC_F3,    KC_F10,
// |--------+--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------+--------|
                                  CAD,    TRNS,    TRNS,   TRNS,   TRNS,        DEL_W,   TRNS,    TRNS,     TRNS,   TRNS
 //                           '--------+--------+--------+--------+--------'  '--------+--------+--------+--------+--------'
    ),

//
    [NAV2] = LAYOUT_Kyria3x5(
 //.--------+--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------+--------.
             TRNS,     TRNS,    TRNS,    TRNS,    TRNS,                                           KC_HOME, TRNS,    TRNS,  TRNS,     TRNS,
// |--------+--------+--------+--------+--------+--------|                                      |--------+--------+--------+--------+--------+--------|
             ACPT,     SIGN,    TRNS,    TRNS,    TRNS,                                           KC_END,  TRNS,  TRNS,    ~TRNS,    TRNS,
// |--------+--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------+--------|
             TRNS,     TRNS,    TRNS,    TRNS,    TRNS,    TRNS,    TRNS,        TRNS,   TRNS,    TRNS,    TRNS,    TRNS,    TRNS,     TRNS,
// |--------+--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------+--------|
                                  CAD,    TRNS,    TRNS,   TRNS,    TRNS,       DEL_W,     SP_AS, TRNS,     TRNS,   TRNS
 //                           '--------+--------+--------+--------+--------'  '--------+--------+--------+--------+--------'
    ),



    [HAMMERSPOON] = LAYOUT_Kyria3x5(
 //.--------+--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------+--------.
            one_6,   two_6,   three_6, one_4,    two_4,                                          three_4, four_4, four_6, five_6, sixth_6,
// |--------+--------+--------+--------+--------+--------|                                      |--------+--------+--------+--------+--------+--------|
            one_3,   two_3,  three_3,  fullscr,  Left_half,                                     right_half,    KC_NO,     KC_NO,      KC_NO,      KC_NO,
// |--------+--------+--------+-------tab-------+--------+--------+--------|  |--------+--------+--------+-------esc-------+--------+--------+--------|
            KC_NO,     KC_NO,  KC_NO, vlayout,   midt,       KC_NO,  KC_NO,     KC_NO,  KC_NO,    midt,    KC_NO,    KC_NO, KC_NO, KC_NO,
// |--------+--------+--------+--------+--------+--------+-SC-F2--+--------|  |-BSPC_W-+-capswrd+------undsc-------+--------+--------+--------+--------|
                               TRNS,  KC_NO,     KC_NO,     KC_NO,  KC_NO,  KC_NO,  KC_NO, KC_NO,   KC_NO, TRNS
 //                           '--------+--------+--------+--------+--------'  '--------+--------+--------+--------+--------'
    ),
/*
    [COLEMAK_DH] = LAYOUT_Kyria3x5(
 //.--------+--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------+--------.
            KC_Q,     KC_W,    KC_F,   KC_P,    KC_B,                                             KC_J,    KC_L,   KC_U,     KC_Y,     DK_AE,
// |--------+--------+--------+--------+--------+--------|                                      |--------+--------+--------+--------+--------+--------|
            LSFT_A,   ADJ_R,   NUM_S,  SYM_T,   KC_G,                                             KC_M,    SYM_N,  KC_E,     KC_I,     KC_O,
// |--------+--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------+--------|
            KC_Z,     LCTL_X,  LALT_C, KC_D,    KC_V,    ALFRED,   TRNS,       SCR_SHOT,  TRNS,     KC_K,    KC_H,   LALT_COM, RCTL_DOT, MINUS,
// |--------+--------+--------+--------+--------+--------+--------+--------|  |--------+-capswrd+-------undsc-----+--------+--------+--------+--------|
                                 TRNS,   KC_LGUI, NUM_TAB,  NAV_SPC,  TILE_LEAD, KC_BSPC,  NAV_ENT, SYM_ESC, TRNS,   TRNS
 //                           '--------+--------+--------+--------+--------'  '--------+--------+--------+--------+--------'
    ),

[RSTHD] = LAYOUT_Kyria3x5(
 //.--------+--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------+--------.
            KC_Z,     KC_C,    KC_Y,     KC_F,    KC_P,                                          KC_X,     KC_M,   QUOT,    KC_U,    KC_Q,
// |--------+--------+--------+--------+--------+--------|                                      |--------+--------+--------+--------+--------+--------|
            LSFT_R,   ADJ_S,   NUM_T,    SYM_H,    KC_D,                                         KC_L,     SYM_N,  KC_A,    KC_I,    RSFT_O,
// |--------+--------+--------+-------tab-------+--------+--------+--------|  |--------+--------+--------+-------esc-------+--------+--------+--------|
            OSM_S,    LCTL_V,  LALT_G,   KC_K,    KC_B,    ALFRED,    TRNS,      SCR_SHOT,   TRNS, KC_W,     KC_J,   LALT_COM, RCTL_DOT, OSM_S,
// |--------+--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------+--------|
                               TRNS,    KC_LGUI, NUM_TAB, NAV_SPC, TILE_LEAD,      KC_BSPC,   NAV_E, SYM_ENT,     TRNS,   TRNS
 //                           '--------+--------+--------+--------+--------'  '--------+--------+--------+--------+--------'
    ),
*/
/*
//
    [TEMPLATE] = LAYOUT_Kyria3x5(
 //.--------+--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------+--------.
    TRNS,    TRNS,     TRNS,    TRNS,    TRNS,    TRNS,                                           TRNS,     TRNS,    TRNS,   TRNS,    TRNS,  TRNS,
// |--------+--------+--------+--------+--------+--------|                                      |--------+--------+--------+--------+--------+--------|
    TRNS,    TRNS,     TRNS,    TRNS,    TRNS,    TRNS,                                           TRNS,     TRNS,    TRNS,   TRNS,    TRNS,  TRNS,
// |--------+--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------+--------|
    TRNS,    TRNS,     TRNS,    TRNS,    TRNS,    TRNS,    TRNS,    TRNS,        TRNS,   TRNS,    TRNS,    TRNS,    TRNS,    TRNS,     TRNS,   TRNS,
// |--------+--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------+--------|
                                TRNS,    TRNS,    TRNS,   TRNS,      TRNS,      TRNS,   TRNS,    TRNS,     TRNS,   TRNS
 //                           '--------+--------+--------+--------+--------'  '--------+--------+--------+--------+--------'
    ),
*/


};
