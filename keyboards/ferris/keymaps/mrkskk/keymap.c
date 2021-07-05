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
        // thumbs
        case SFT_MODS:
        case SYM_N:
        case HMR_ENT:
        case NUM_SPC:
        case NAV_T:
        case WORK_E:
            return 200;
        default:  // home row mods
            return TAPPING_TERM;
    }
}
/*
bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HMR_ENT:
        case NUM_SPC: 
            return false;
        default:
            return true;
    }
}
*/ 

// the time of the last non-combo input, used to tweak the timing of combos depending on if I'm currently
// in active typing flow (should practically remove any chance of mistriggering space-combos)
static uint16_t non_combo_input_timer = 0;


#ifdef COMBO_ENABLE // 
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
      if (index >= COMBO_LSFT && index <= COMBO_LGUI) {
        return timer_elapsed(non_combo_input_timer) > 300 ? 50 : 5;
        }
        switch (index) {
        //horisontals
        case NUMBERS:
        case OSLADJUST:
        case TG_MEDIA:
        case TG_MOUSE:
        case SNAKE:
        case CAPS:
        return timer_elapsed(non_combo_input_timer) > 300 ? 35 : 5;
        //verticals
        case VERTICALX:
        case VERTICALZ:
        case AAE_OE:
        case PI_OE: 
             return 35;
        
        }
        return COMBO_TERM;
}

bool combo_should_trigger(uint16_t combo_index, combo_t *combo) {
    return true;
}

#endif //


// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

   [BASE_LAYER] = LAYOUT(
//.--------+--------+--------+--------+--------.                    .--------+--------+--------+--------+--------.
    KC_W,   KC_C,    KC_G,    KC_M,     KC_Q,                        S_QUOT,  KC_U,   KC_K,     KC_J,    DK_AA,
//|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
    HOME_R, KC_S,    NAV_T,  KC_H,     KC_F,                         KC_Y,    KC_I,   WORK_E,   KC_O,    HOME_A,
//|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
    KC_V,   KC_B,    KC_L,    KC_D,     KC_X,                        KC_Z,    KC_P,   KC_COMM,  KC_DOT,  DK_AE,
//.--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------.
                                        SFT_MODS, NUM_SPC,    SYM_N,  KC_BSPC
 //                                   '--------+--------'  '--------+--------'
    ), 
   [NUM_LAYER] = LAYOUT(
//.--------+--------+--------+--------+--------.                    .--------+--------+--------+--------+--------.
    _______, KC_P7,   KC_P8,   KC_P9,   _______,                     LABK,    LCB,     PLUS,     RCB,    RABK,
//|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
    KC_P0,   KC_P4,   KC_P5,   KC_P6,   EQL,                         ASTR,    LPRN,    MINUS,    RPRN ,   SLSH,
//|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
    _______, KC_P1,   KC_P2,   KC_P3,   _______,                     _______, LBRC,    KC_PDOT,  RBRC,    BSLH,
//.--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------.
                                        _______, TO_BASE,   KC_ENT , KC_DEL
 //                                   '--------+--------'  '--------+--------'
    ),

    [SYM_LAYER] = LAYOUT(
//.--------+--------+--------+--------+--------.                    .--------+--------+--------+--------+--------.
   TILD,     HAT,     AMPR,    AT,      _______,                     _______, _______, _______, _______, _______,
//|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
   EXLM,     HASH,    UNDSC,   QUES,    PERC,                         _______, _______, _______, _______, _______,
//|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
   DIAE,     ACUT,    PIPE,    GRV,     _______,                     _______, _______, _______, _______, _______,
//.--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------.
                                        _______, _______,   _______, _______
 //                                   '--------+--------'  '--------+--------'
    ),

    [NAV_LAYER] = LAYOUT(
//.--------+--------+--------+--------+--------.                    .--------+--------+--------+--------+--------.
    _______, _______, XXXXXXX, KC_ESC,  _______,                     FOCUS_D,  FOCUS_L, KC_UP,   FOCUS_R, FOCUS_U,
//|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
    KC_LSFT, MYMOD2,  XXXXXXX, KC_ENT, NXT_TAB,                      CAPSWRD,  ARR_L,   KC_DOWN, ARR_R,   KC_RSFT,
//|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
    _______, _______, XXXXXXX, KC_TAB,  _______,                     KC_HOME,  KC_PGUP, _______, KC_PGDN, KC_END,
//.--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------.
                                        UNDOREDO, CPYPASTE, KC_ENT, DEL_WRD
 //                                   '--------+--------'  '--------+--------'
    ),

    [MODS_LAYER] = LAYOUT(
//.--------+--------+--------+--------+--------.                    .--------+--------+--------+--------+--------.
    _______, _______, _______, KC_ESC, _______,                      _______, _______, _______, _______, _______,
//|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
    OS_SHFT, OS_ALT, OS_CTRL, OS_CMD, NXT_TAB,                       _______, FIND,    REPLACE, SAVE,    ALL,
//|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
    _______, _______, _______, KC_TAB, _______,                      _______, _______, _______, _______, _______,
//.--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------.
                                       XXXXXXX,  ALFRED,     _______, KC_DEL
 //                                   '--------+--------'  '--------+--------'
    ),

    [WORK_LAYER] = LAYOUT(
//.--------+--------+--------+--------+--------.                    .--------+--------+--------+--------+--------.
    _______, _______, _______, KC_ESC, _______,                      _______, _______, XXXXXXX, _______, _______,
//|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
    KC_LSFT, _______,  KC_F2,  CAPSWRD, _______,                     _______, _______, XXXXXXX, _______, _______,
//|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
    _______, _______, _______, KC_TAB, _______,                      _______, _______, XXXXXXX, _______, _______,
//.--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------.
                                       ALT_TAB, ALFRED,     SP_AS, KC_DEL
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
                                       KC_BTN1,  MSWHEEL,   TO_BASE, _______
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
    RGB_TOG, SCR_SHOT, CAD,    _______,     XXXXXXX,                    XXXXXXX, PW,        PK,     MW,     XXXXXXX,
//|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
    RGB_SPD, RGB_SPI, RGB_VAI, TG_OS,     XXXXXXX,                     XXXXXXX, LOCK, XXXXXXX, XXXXXXX, XXXXXXX,
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
/*
    [TEMPLATE] = LAYOUT(
//.--------+--------+--------+--------+--------.                    .--------+--------+--------+--------+--------.
    _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______,
//|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
    _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______,
//|--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------|
    _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______,
//.--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------.
                                       _______, _______,    _______, _______
 //                                   '--------+--------'  '--------+--------'
    ),
*/
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
        case NAV_LAYER:
            rgb_matrix_set_color_all(RGB_SPRINGGREEN);
            break;
        case WORK_LAYER:
            rgb_matrix_set_color_all(RGB_SPRINGGREEN);
            break;
        case WINDOW_MANAGE_LAYER:
            rgb_matrix_set_color_all(RGB_YELLOW);
            break;
        case MOUSE_LAYER:
            rgb_matrix_set_color_all(RGB_GREEN);
            break;
        case MEDIA_LAYER:
            rgb_matrix_set_color_all(RGB_BLUE);
            break;
        case ADJUST_LAYER:
            rgb_matrix_set_color_all(RGB_PURPLE);
            break;
        case MODS_LAYER:
            rgb_matrix_set_color_all(RGB_MAGENTA);
            break;
        case FN_LAYER:
            rgb_matrix_set_color_all(RGB_GOLD);
            break;
    }
}
#endif