
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

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LSFT_A:
        case LCTL_X:
        case LALT_C:
        case RSFT_AE:
        case LSFT_MIN:
        case LSFT_Z:
        case RSFT_QT:
        case LALT_COM:
        case RCTL_DOT:
            return true;
        default:
            return false;
    }
}

//Setting per key tapping term.
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LSFT_A:
        case RSFT_QT:
        case RSFT_AE:
            return 275;
        case LCTL_X:
        case LALT_C:
        case LALT_COM:
        case RCTL_DOT:
            return 300;
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
        case JK_ESC:
        case DF_TAB:
        case EI_SP:
            return 50;
        case ROLL_AE1:
        case ROLL_OE1:
        case ROLL_AA1:
        case ROLL_AE2:
        case ROLL_OE2:
        case ROLL_AA2:
            return 5000;
        case AE_AE:
        case OE_OE:
        case AO_AA:
            return COMBO_TERM;
        case COMBO_BSPC_W:
        case COMBO_DEL_W:
        case COMBO_NAV2_F2:
        case COMBO_ENTER:
             return 150;
        default:
            return COMBO_TERM; //100
    }
    }
#endif

// For CAPSWRD and SNAKECSE.
// Returns true if the case modes should terminate, false if they continue
// Note that the keycodes given to this function will be stripped down to
// basic keycodes if they are dual function keys. Meaning a modtap on 'a'
// will pass KC_A rather than LSFT_T(KC_A).
// Case delimiters will also not be passed into this function.
bool terminate_case_modes(uint16_t keycode, const keyrecord_t *record) {
    switch (keycode) {
        // Keycodes to ignore (don't disable caps word)
        case KC_A ... KC_Z:
        case KC_1 ... KC_0:
        case KC_MINS:
        case KC_UNDS:
        case KC_BSPC:
        case CAPSWRD:
        case SNAKECSE:
            // If mod chording disable the mods
            if (record->event.pressed && (get_mods() != 0)) {
                return true;
            }
            break;
        default:
            if (record->event.pressed) {
                return true;
            }
            break;
    }
    return false;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] =
{
    [QWERTY] = LAYOUT(
 //.--------+--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------+--------.
     TRNS,    KC_Q,     KC_W,    KC_E,   KC_R,    KC_T,                                          KC_Y,     KC_U,   KC_I,     KC_O,    KC_P,     TRNS,
// |--------+--------+--------+--------+--------+--PGup--|                                      |--------+--------+--------+--------+--------+--------|
     TRNS,    LSFT_A,   ADJ_S,   NUM_D,  SYM_F,   KC_G,                                          KC_H,    SYM_J,  KC_K,     KC_L,    RSFT_QT,   TRNS,
// |--------+--------+--------+-------tab-------+--PGdn--+--------+--------|  |--------+--------+--------+-------esc-------+--------+--------+--------|
     OSM_S,   LSFT_Z,   LCTL_X,  LALT_C, KC_V,    KC_B,    FIND,    TRNS,      SCR_SHOT,  TRNS,  KC_N,    KC_M,   LALT_COM, RCTL_DOT, LSFT_MIN, TRNS,
// |--------+--------+--------+--------+--------+--------+-SC-F2--+--------|  |-BSPC_W-+--------+--------+--------+--------+--------+--------+--------|
                                  TRNS,  KC_LGUI, NUM_TAB,  NAV_SPC,  HLEAD, KC_BSPC,  NAV2_S,  SYM_ESC,  KC_LGUI,    TRNS
 //                           '--------+--------+--------+--------+--------'  '--------+--------+--------+--------+--------'
    ),

    [COLEMAK_DH] = LAYOUT(
 //.--------+--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------+--------.
    TRNS,     KC_Q,     KC_W,    KC_F,   KC_P,    KC_B,                                           KC_J,    KC_L,   KC_U,     KC_Y,     DK_AE,  TRNS,
// |--------+--------+--------+--------+--------+--------|                                      |--------+--------+--------+--------+--------+--------|
    TRNS,     LSFT_A,   ADJ_R,   NUM_S,  SYM_T,   KC_G,                                           KC_M,    SYM_N,  KC_E,     KC_I,     KC_O,   TRNS,
// |--------+--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------+--------|
    OSM_S,     KC_Z,     LCTL_X,  LALT_C, KC_D,    KC_V,    FIND,   TRNS,       SCR_SHOT,  TRNS,    KC_K,    KC_H,   LALT_COM, RCTL_DOT, MINUS,  TRNS,
// |--------+--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------+--------|
                                 TRNS,   KC_LGUI, NUM_TAB,  NAV_SPC,  HLEAD, KC_BSPC, NAV2_S, SYM_ESC, TRNS,   TRNS
 //                           '--------+--------+--------+--------+--------'  '--------+--------+--------+--------+--------'
    ),

    [NUMPAD] = LAYOUT(
 //.--------+--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------+--------.
    TRNS  ,   TRNS,     TRNS,   TRNS,    TRNS,    TRNS,                                            SLSH,  KC_7,     KC_8,    KC_9,     KC_0,  TRNS,
// |--------+--------+--------+--------+--------+--------|                                      |--------+--------+--------+--------+--------+--------|
    TRNS ,    TRNS,     TRNS,   TRNS,    TRNS,    TRNS,                                            ASTR,  KC_4,     KC_5,    KC_6,     PLUS,  TRNS,
// |--------+--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------+--------|
    TRNS ,    TRNS,     TRNS,   TRNS,    TRNS,    TRNS,     TRNS,    TRNS,       TRNS,  TRNS,     KC_DOT, KC_1,     KC_2,    KC_3,     MINUS,   TRNS,
// |--------+--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------+--------|
                                 CAD,    TRNS ,   TRNS,     TRNS,    TRNS,       TRNS,    EQL,    TRNS,   TRNS,     TRNS
 //                           '--------+--------+--------+--------+--------'  '--------+--------+--------+--------+--------'
    ),

    [L_SYMBOLS] = LAYOUT(
 //.--------+--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------+--------.
    TRNS,    EXLM,      DQUO,   LCB,     RCB,     PERC,                                              SLSH,     BSLH,   LABK,   RABK,   EQL,    TRNS,
// |--------+--------+--------+--------+--------+--------|                                      |--------+--------+--------+--------+--------+--------|
    TRNS,    AT,        TILD,   LPRN,    RPRN,    HASH,                                              ASTR,     QUOT,   ACUT,   GRV,    PIPE,   TRNS,
// |--------+--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------+--------|
    TRNS,    HAT,       DIAE,   LBRC,    RBRC,    QUES,    TRNS,     TRNS,       TRNS,    TRNS,    EN_EM_DSH, AMPR,   SEMCOL,  COL,    UNDSC,  TRNS,
// |--------+--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------+--------|
                                 CAD,    TRNS,    TRNS,   TRNS,      TRNS,       TRNS,    TRNS,     TRNS,  TRNS,     TRNS
 //                           '--------+--------+--------+--------+--------'  '--------+--------+--------+--------+--------'
    ),

    [R_SYMBOLS] = LAYOUT(
 //.--------+--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------+--------.
    TRNS,    EXLM,      DQUO,   LCB,     RCB,     PERC,                                           SLSH,     BSLH,   LABK,     RABK,    EQL,    TRNS,
// |--------+--------+--------+--------+--------+--------|                                      |--------+--------+--------+--------+--------+--------|
    TRNS,    AT,        TILD,   LPRN,    RPRN,    HASH,                                           ASTR,     QUOT,   ACUT,     GRV,     PIPE,   TRNS,
// |--------+--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------+--------|
    TRNS,    HAT,       DIAE,   LBRC,    RBRC,    QUES,    TRNS,      TRNS,       TRNS,    TRNS,  EN_EM_DSH, AMPR,   SEMCOL,  COL,     UNDSC,  TRNS,
// |--------+--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------+--------|
                                  CAD,    TRNS,    TRNS,   TRNS,      TRNS,      TRNS,    TRNS,     TRNS,  TRNS,     TRNS
 //                           '--------+--------+--------+--------+--------'  '--------+--------+--------+--------+--------'
    ),

    [NAV] = LAYOUT(
 //.--------+--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------+--------.
    TRNS,    TRNS,     TRNS,    TRNS,   PRV_TAB,  KC_PGUP,                                           TRNS,    PRVW,    KC_UP,   NXTW,    ZOOMIN,  TRNS,
// |--------+--------+--------+--------+--------+--------|                                      |--------+--------+--------+--------+--------+--------|
    TRNS,    TRNS,     SP_AS,   NUMBER,   NXT_TAB, KC_PGDN,                                           TRNS,    KC_LEFT, KC_DOWN, KC_RGHT, ZOOMOUT, TRNS,
// |--------+--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------+--------|
    CAPSWRD,    CAPSWRD,     CUT,     COPY,   PASTE,    TRNS,    TRNS,    TRNS,        TRNS,   TRNS,   TRNS,    TRNS,    TRNS,    TRNS,   SNAKECSE,   SNAKECSE,
// |--------+--------+--------+--------+--------+--------+--------+--------|  |-DEL_W--+--------+--------+--------+--------+--------+--------+--------|
                                SLEEP,   TRNS,     TRNS,    TRNS,    TRNS,        DEL,   KC_ENT,   TRNS,    TRNS,    TRNS
 //                           '--------+--------+--------+--------+--------'  '--------+--------+--------+--------+--------'
    ),
    [ADJUST] = LAYOUT(
 //.--------+--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------+--------.
    TRNS,   QWERT ,   TRNS,    TRNS,    TRNS,    TG_OS,                                           TRNS,     KC_F7,  KC_F8,   KC_F9,   KC_F12, TRNS,
// |--------+--------+--------+--------+--------+--------|                                      |--------+--------+--------+--------+--------+--------|
    TRNS,    TRNS,     TRNS,    KC_LALT, TRNS,    TRNS,                                           TRNS,     KC_F4,  KC_F5,   KC_F6,   KC_F11, TRNS,
// |--------+--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------+--------|
    TRNS,    TRNS,     TRNS,    COLEM,   TRNS,    TRNS,    TRNS,    TRNS,        TRNS,   TRNS,    TRNS,     KC_F1,  KC_F2,  KC_F3,    KC_F10, TRNS,
// |--------+--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------+--------|
                                  CAD,    TRNS,    TRNS,   CAPSWRD, SNAKECSE,   TRNS, TRNS,    TRNS,     TRNS,   TRNS
 //                           '--------+--------+--------+--------+--------'  '--------+--------+--------+--------+--------'
    ),

//
    [NAV2] = LAYOUT(
 //.--------+--------+--------+--------+--------+--------.                                      .--------+--------+--------+--------+--------+--------.
    TRNS,    TRNS,     TRNS,    TRNS,    TRNS,    TRNS,                                           KC_HOME, PRVW,    S_UP_W,  NXTW,     TRNS,  TRNS,
// |--------+--------+--------+--------+--------+--------|                                      |--------+--------+--------+--------+--------+--------|
    TRNS,    ACPT,     SIGN,    TRNS,    TRNS,    TRNS,                                           KC_END,  S_PRVW,  S_DN_W, S_NXTW,    TRNS,  TRNS,
// |--------+--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------+--------|
    TRNS,    TRNS,     TRNS,    TRNS,    TRNS,    TRNS,    TRNS,    TRNS,        TRNS,   TRNS,    TRNS,    TRNS,    TRNS,    TRNS,     TRNS,   TRNS,
// |--------+--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------+--------|
                                  CAD,    TRNS,    TRNS,   TRNS,    TRNS,      TRNS,     SP_AS,    TRNS,     TRNS,   TRNS
 //                           '--------+--------+--------+--------+--------'  '--------+--------+--------+--------+--------'
    ),
/*
//
    [TEMPLATE] = LAYOUT(
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
