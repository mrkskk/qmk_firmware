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
        case HOME_R:
        case HOME_A:
        case HOME_P0:
        case HM_EXLM:
        
            return 170;  // do not change
        // thumbs
        case SYM_N:
        case HMR_ENT:
        case SPC_NUM:
        case NAV2_T:
        case NAV2_E:
            return 200;
        default:  // home row mods
            return TAPPING_TERM;
    }
}

bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HMR_ENT:
        case SPC_NUM:
            return false;
        default:
            return true;
    }
}

#ifdef COMBO_ENABLE
bool get_combo_must_tap(uint16_t index, combo_t *combo) {
    // If you want all combos to be tap-only, just uncomment the next line
    // return true
    
        // If you want *all* combos, that have Mod-Tap/Layer-Tap/Momentary keys in its chord, to be tap-only, this is for you:
        uint16_t key;
    uint8_t      idx = 0;
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

#ifdef COMBO_ENABLE
uint16_t get_combo_term(uint16_t index, combo_t *combo) {
    switch (index) {
        // Vertical combos for Alphas
        case VERTICALX:
        case VERTICALZ:
        case AAE_OE:
        case RV_V:
            return 80;
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

   [BASE_LAYER] = LAYOUT(
//.--------+--------+--------+--------+--------.                    .--------+--------+--------+--------+--------.
    KC_W,    KC_C,    KC_G,   KC_M,     KC_Q,                        S_QUOT,  KC_U,    KC_K,     KC_J,    DK_AA,
//|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
    HOME_R,  KC_S,    NAV2_T, HOME_H,   KC_F,                        KC_Y,    HOME_I,  NAV2_E,   KC_O,  HOME_A,
//|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
     KC_V,   HOME_B,  HOME_L, KC_D,     KC_X,                        KC_Z,    KC_P,    HOME_CO,  HOME_DOT,  DK_AE,
//.--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------.
                                        HMR_ENT, SPC_NUM,    SYM_N,  KC_BSPC
 //                                   '--------+--------'  '--------+--------'
    ),

    [NUM_LAYER] = LAYOUT(
//.--------+--------+--------+--------+--------.                    .--------+--------+--------+--------+--------.
    _______, KC_P7,   KC_P8,   KC_P9,   _______,                     _______, LCB,     PLUS,     RCB, _______,
//|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
    HOME_P0, KC_P4,   KC_P5,   HOME_P6, EQL,                         ASTR,    HM_LPRN, MINUS,    RPRN,  S_SLSH,
//|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
    _______, HOME_P1, HOME_P2, KC_P3,   _______,                     _______, LBRC,    HOME_PCO, HM_RBRC, _______,
//.--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------.
                                        XXXXXXX, _______,  SYM,     DEL_WRD
 //                                   '--------+--------'  '--------+--------'
    ),

    [SYM_LAYER] = LAYOUT(
//.--------+--------+--------+--------+--------.                    .--------+--------+--------+--------+--------.
   TILD,     HAT,     AMPR,    AT,    _______,                        DQUO,   _______, _______, _______, _______,
//|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
   HM_EXLM,  HASH,    UNDSC,   HM_QUES, S_PERC,                      _______, _______, _______, _______, _______,
//|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
   DIAE,     HM_ACUT, HM_PIPE, GRV,     _______,                     XXXXXXX, _______, _______, _______, DK_OE,
//.--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------.
                                        _______, EXTRA_SYM,   _______, _______
 //                                   '--------+--------'  '--------+--------'
    ),

    [EXTRA_NAV_LAYER] = LAYOUT(
//.--------+--------+--------+--------+--------.                    .--------+--------+--------+--------+--------.
     KC_END, KC_PGDN, KC_UP,   KC_PGUP, KC_HOME,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
   XXXXXXX, KC_LEFT, KC_DOWN, KC_RGHT, XXXXXXX,                      XXXXXXX, KC_LGUI, XXXXXXX, KC_LALT, KC_RSFT,
//|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
   XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, KC_RCTL, XXXXXXX, XXXXXXX,
//.--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------.
                                        _______,  _______,   _______,  _______
 //                                   '--------+--------'  '--------+--------'
    ),

    [NAV2_LAYER] = LAYOUT(
//.--------+--------+--------+--------+--------.                    .--------+--------+--------+--------+--------.
     _______, _______, XXXXXXX, KC_ESC,  _______,                    FOCUS_D,  FOCUS_L,  KC_UP,   FOCUS_R, FOCUS_U,
//|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
     KC_LSFT, MYMOD2, XXXXXXX, KC_LGUI, NXT_TAB,                      ALT_TAB, ARR_L,  KC_DOWN,   ARR_R, KC_RSFT,
//|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
    _______, KC_LALT, XXXXXXX, KC_TAB,  _______,                     KC_HOME, KC_PGUP, KC_RCTL, KC_PGDN, KC_END,
//.--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------.
                                        UNDOREDO, CPYPASTE, _______, DEL_WRD
 //                                   '--------+--------'  '--------+--------'
    ),

    [EDIT_LAYER] = LAYOUT(
//.--------+--------+--------+--------+--------.                    .--------+--------+--------+--------+--------.
    _______, _______, _______, KC_ESC, _______,                      _______, REPLACE, _______, _______, _______,
//|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
    _______, _______, KC_F2,   KC_LGUI, NXT_TAB,                      ALT_TAB, FIND,    XXXXXXX, _______, _______,
//|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
    _______, _______, _______, KC_TAB, _______,                     _______, _______, _______, _______, _______,
//.--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------.
                                       SP_AS,  ALFRED,    _______, _______
 //                                   '--------+--------'  '--------+--------'
    ),

    [WINDOW_MANAGE_LAYER] = LAYOUT(
//.--------+--------+--------+--------+--------.                    .--------+--------+--------+--------+--------.
     one_6,  two_6,   three_6, one_4,  two_4,                        three_4, four_4, XXXXXXX, XXXXXXX,  XXXXXXX,
//|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
    four_6, five_6,  sixth_6, three_4, four_4,                       MIDDLE,  FULLSCR, ALFRED, _______, _______,
//|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
    one_3,  two_3,   three_3, wLAYOUT,  LEFT,                        RIGHT,   XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX,
//.--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------.
                                        _______, _______,    _______,  _______
 //                                   '--------+--------'  '--------+--------'
    ),

    [MOUSE_LAYER] = LAYOUT(
//.--------+--------+--------+--------+--------.                    .--------+--------+--------+--------+--------.
   ZOOMIN,  PRV_PGE, NXT_PGE, KC_ESC,  XXXXXXX,                    FOCUS_D, FOCUS_L, KC_MS_U, FOCUS_R, FOCUS_U,
//|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
    KC_LCTL, KC_ACL0, KC_ACL1, KC_ACL2, NXT_TAB,                         ALT_TAB, KC_MS_L, KC_MS_D, KC_MS_R, KC_RSFT,
//|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
    ZOOMOUT, ALL,     XXXXXXX, KC_TAB, XXXXXXX,                      KC_BTN2, KC_WH_L, XXXXXXX, KC_WH_R, XXXXXXX,
//.--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------.
                                       KC_BTN1,  MSWHEEL,   XXXXXXX, _______
 //                                   '--------+--------'  '--------+--------'
    ),

    [MEDIA_LAYER] = LAYOUT(
//.--------+--------+--------+--------+--------.                    .--------+--------+--------+--------+--------.
    TO_BASE, TO_BASE, TO_BASE, TO_BASE, TO_BASE,                     TO_BASE, TO_BASE, KC_VOLU, TO_BASE, TO_BASE,
//|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
    TO_BASE, TO_BASE, TO_BASE, TO_BASE, TO_BASE,                     TO_BASE, KC_MPRV, KC_VOLD, KC_MNXT, TO_BASE,
//|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
    TO_BASE, TO_BASE, TO_BASE, TO_BASE, TO_BASE,                     TO_BASE, TO_BASE, TO_BASE, TO_BASE, TO_BASE,
//.--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------.
                                        KC_MUTE, KC_MPLY,   KC_MPLY, KC_MUTE
 //                                   '--------+--------'  '--------+--------'
    ),

     [ADJUST_LAYER] = LAYOUT(
//.--------+--------+--------+--------+--------.                    .--------+--------+--------+--------+--------.
    RGB_HUD, RGB_HUI,  RGB_M_R, RGB_M_P, XXXXXXX,                    XXXXXXX,  PM,        LH,     MP,     XXXXXXX,
//|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
    RGB_TOG, SCR_SHOT, CAD,    TG_OS,     XXXXXXX,                    XXXXXXX,  PW,        PK,     MW,     XXXXXXX,
//|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
    RGB_SPD, RGB_SPI, RGB_VAI, LOCK,     XXXXXXX,                     XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
//.--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------.
                                        _______, _______,   _______,  _______
 //                                   '--------+--------'  '--------+--------'
    ),

    [FN_LAYER] = LAYOUT(
//.--------+--------+--------+--------+--------.                    .--------+--------+--------+--------+--------.
    KC_F11,   KC_F7,  KC_F8,   KC_F9,   TO_BASE,                      TO_BASE, TO_BASE, TO_BASE, TO_BASE, TO_BASE,
//|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
    KC_F10,   KC_F4,  KC_F5,   KC_F6,   TO_BASE,                      TO_BASE, KC_LGUI, KC_LALT, KC_LCTL, KC_RSFT,
//|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
    KC_F12,   KC_F1,  KC_F2,   KC_F3,   TO_BASE,                        TO_BASE, TO_BASE, TO_BASE, TO_BASE, TO_BASE,
//.--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------.
                                        _______, XXXXXXX,   _______,  _______
 //                                   '--------+--------'  '--------+--------'
    ),

};
#ifdef RGB_MATRIX_ENABLE
void keyboard_post_init_user(void) {
    // Set RGB to known state
    rgb_matrix_enable();
    rgb_matrix_set_color_all(RGB_GOLD);
}

void rgb_matrix_indicators_user(void) {
    if (!rgb_matrix_is_enabled()) return;
    switch (get_highest_layer(layer_state)) {
        case BASE_LAYER:
            if (get_mods()) {
                rgb_matrix_set_color_all(RGB_ORANGE);
                } else  if (xcase_enabled() && host_keyboard_led_state().caps_lock) {
                rgb_matrix_set_color_all(RGB_PURPLE);
            } else  if (xcase_enabled()) {
                rgb_matrix_set_color_all(RGB_BLUE);
            } else if (host_keyboard_led_state().caps_lock) {
                rgb_matrix_set_color_all(RGB_RED);
            }
            break;
        case NUM_LAYER:
            rgb_matrix_set_color_all(RGB_TEAL);
            break;
        case SYM_LAYER:
            rgb_matrix_set_color_all(RGB_TEAL);
            break;
        case EXTRA_NAV_LAYER:
            rgb_matrix_set_color_all(RGB_PURPLE);
            break;
        case NAV2_LAYER:
            rgb_matrix_set_color_all(RGB_SPRINGGREEN);
            break;
        case EDIT_LAYER:
            rgb_matrix_set_color_all(RGB_SPRINGGREEN);
            break;
        case WINDOW_MANAGE_LAYER:
            rgb_matrix_set_color_all(RGB_GREEN);
            break;
        case MOUSE_LAYER:
            rgb_matrix_set_color_all(RGB_GREEN);
            break;
        case MEDIA_LAYER:
            rgb_matrix_set_color_all(RGB_PURPLE);
            break;
        case ADJUST_LAYER:
            rgb_matrix_set_color_all(RGB_PURPLE);
            break;
    }
}
#endif
