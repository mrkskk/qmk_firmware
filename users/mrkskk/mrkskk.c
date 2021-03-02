#include  "sendstring_danish_fixed.h" 
#include "mrkskk.h"
#if defined(COMBO_ENABLE)
#include "g/keymap_combo.h" // to make combo def dictionary work
#endif


layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, NUMPAD, SYMBOLS, ADJUST);
    return state;
};

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
         case LCTL_A:
         case LALT_S:
         case LSFT_D:
         case LGUI_F:
         case RGUI_J:
         case RSFT_K:
         case LALT_L:
         case RCTL_AE: 
         case LALT_R:
         case HOME_T:   
         case RGUI_N:
         case RSFT_E:
         case LALT_I:
         case RCTL_O: 
            return true;
        default:
            return false;
    }
}

//Setting per key tapping term. the global is 400
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LCTL_A:
        case LALT_S:
        case LSFT_D:
        case LGUI_F:
        case RGUI_J:
        case RSFT_K:
        case LALT_L:
        case RCTL_AE: 
        case LALT_R:
        case HOME_T:   
        case RGUI_N:
        case RSFT_E:
        case LALT_I:
        case RCTL_O: 
            return TAPPING_TERM - 100; // 400-100=300
        case TT_NR:
        case NVSPC:
        case CBSPC:
        case NVENT:
        case SYESC:
        case OSM_T_SFT:
            return TAPPING_TERM - 225; // 400-225=175
        default:
            return TAPPING_TERM;       // 400
    }
}



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] =
{
    [QWERTY] = LAYOUT(
// ,------------------------------------------.                            ,----------------------------+------+--------.
    KC_LCTRL,  KC_Q, KC_W,  KC_E,  KC_R,  KC_T,                               KC_Y,  KC_U,  KC_I,   KC_O,   KC_P,   DK_AA,    
// |--------+-----+------+------+------+------|                            |------+------+------+-------+------+--------|
    KC_TAB, LCTL_A, LALT_S, LSFT_D, LGUI_F, KC_G,                                 KC_H,  RGUI_J, RSFT_K, LALT_L, RCTL_AE,  DK_OE,       
// |--------+-----+------+------+------+------+------+------.,------+------+------+------+------+-------+------+--------|
   OSM_T_SFT, KC_Z, KC_X,  KC_C,  KC_V,  KC_B,  FIND,  CAPSWRD,   S_S,  KC_TAB, KC_N,  KC_M,  KC_COMM, KC_DOT, MINUS,   QUOT,    
// `---------------------+------+------+------+------+------||------+------+------+------+------+-----------------------'
                         UNTAB, KC_LGUI, TT_NR, NVSPC, TD(SPLEAD),  CBSPC, NVENT, SYESC, KC_LALT, ____   
//                       `----------------------------------'`----------------------------------'
    ),

    [COLEMAK_DH] = LAYOUT(
// ,------------------------------------------.                            ,----------------------------+------+--------.
    KC_LCTRL,  KC_Q, KC_W,  KC_F,  KC_P,  KC_B,                               KC_J,  KC_L,  KC_U,   KC_Y,   DK_AE,   DK_AA,    
// |--------+-----+------+------+------+------|                            |------+------+------+-------+------+--------|
    KC_TAB, LCTL_A,  LALT_R, LSFT_S,  HOME_T,  KC_G,                          KC_M,  RGUI_N,  RSFT_E,   LALT_I,   RCTL_O,    DK_OE,       
// |--------+-----+------+------+------+------+------+------.,------+------+------+------+------+-------+------+--------|
    OSM_T_SFT, KC_Z, KC_X,  KC_C,  KC_D, KC_V,  FIND, CAPSWRD,  S_S, KC_TAB,    KC_K,  KC_H,  KC_COMM, KC_DOT, MINUS,  QUOT,    
// `---------------------+------+------+------+------+------||------+------+------+------+------+-----------------------'
                         UNTAB, KC_LGUI, TT_NR, NVSPC, TD(SPLEAD),  CBSPC, NVENT, SYESC, KC_LALT, ____   
//                       `----------------------------------'`----------------------------------'
    ),

    [NUMPAD] = LAYOUT(
// ,------------------------------------------.                            ,----------------------------+------+--------.
    ____  ,  EXLM, DQUO,  LCB,   RCB,   PERC,                               KC_7,  KC_8,  KC_9,   KC_0,    EQL,   ____,    
// |--------+-----+------+------+------+------|                            |------+------+------+-------+------+--------|
    ____ ,   AT  , QUOT,  LPRN,  RPRN,  HASH,                               KC_4,  KC_5,  KC_6,   ____,   PLUS,   ASTR,       
// |--------+-----+------+------+------+------+------+------.,------+------+------+------+------+-------+------+--------|
    ____ ,   ____, ____,  LBRC,  RBRC,  QUES,  ____,  ____,   ____,  ____,  KC_1,  KC_2,  KC_3,   KC_DOT, MINUS,  SLSH,    
// `---------------------+------+------+------+------+------||------+------+------+------+------+-----------------------'
                          CAD, _____, _____, _____, _____,  _____, _____, _____, _____, ____   
//                       `----------------------------------'`----------------------------------'  
    ),
    [SYMBOLS] = LAYOUT( 
// ,------------------------------------------.                            ,----------------------------+------+--------.
    ____,   EXLM, DQUO,  LCB,   RCB,   PERC,                                  SLSH, BSLH, HAT,   DIAE,  EQL,    ____,    
// |--------+-----+------+------+------+------|                            |------+------+------+-------+------+--------|
    ____,   AT,   QUOT,  LPRN,  RPRN,  HASH,                                  ASTR, TILD,  ACUT, GRV,   PIPE,   ____,       
// |--------+-----+------+------+------+------+------+------.,------+------+------+------+------+-------+------+--------|
    ____,   ____, ____,   LBRC,  RBRC,  QUES,   FIND,  ____,   MINUS,  PLUS,  ____, AMPR,  LABK, RABK,  EN_EM_DSH, ____,    
// `---------------------+------+------+------+------+------||------+------+------+------+------+-----------------------'
                          CAD, ____,  ____,   ____,  ____,   ____,  ____,   ____, KC_RALT, ____   
//                       `----------------------------------'`----------------------------------'  
    ),
    [NAV] = LAYOUT(
// ,------------------------------------------.                            ,----------------------------+------+--------.
    PRV_TAB, ____, ____,  UNDO,  REDO,  PGUP,                                ____,  PRVW,  OP,    NXTW,   ____, ____,    
// |--------+-----+------+------+------+------|                            |------+------+------+-------+------+--------|
    NXT_TAB, ACPT, SIGN, ____,  ____,  PGDN,                                ____,  LEFT,  NED,   RGHT,   ____, ____,       
// |--------+-----+------+------+------+------+------+------.,------+------+------+------+------+-------+------+--------|
    CAPSWRD,    ____, CUT,   COPY,  PASTE,  ____,  FIND,  ____, ____, ____,  ____,  ____, ____, ____, ____,   ____,    
// `---------------------+------ +------+------+------+------||------+------+------+------+------+-----------------------'
                          SLEP, _____, _____, ____, _____,   DEL,   _____, _____, _____,  ____   
//                       `----------------------------------'`----------------------------------'  
    ),
    [ADJUST] = LAYOUT( 
// ,------------------------------------------.                            ,----------------------------+------+--------.
    TG_OS,  QWERT , ____, ____,   ____,  ____,                               KC_F7, KC_F8, KC_F9, KC_F12, ____,   ____,    
// |--------+-----+------+------+------+------|                            |------+------+------+-------+------+--------|
    KC_MAKE, ACPT, SIGN, ____,   ____,  ____,                                KC_F4, KC_F5, KC_F6, KC_F11, ____,   ____,       
// |--------+-----+------+------+------+------+------+------.,------+------+------+------+------+-------+------+--------|
    CAPSWRD ,____, ____, COLEM, ____, ____,  ____,  CG_TOGG,   AG_TOGG,  ____, KC_F1, KC_F2, KC_F3, KC_F10, ____,   ____,    
// `---------------------+------+------+------+------+------||------+------+------+------+------+-----------------------'
                          CAD,  ____,  ____, ____,  ____,      ____,  ____, _____, _____,  _____   
//                       `----------------------------------'`----------------------------------'  
    ),

// 
    [SHORTCUTS] = LAYOUT(
// ,------------------------------------------.                            ,----------------------------+------+--------.
    ____ ,   ____, ____,  ____,  ____,  ____,                                ____,   PRVW,  S_UP_W,  NXTW,   ____,   ____,    
// |--------+-----+------+------+------+------|                            |------+------+------+-------+------+--------|
    ____ ,   ____, Smartsets,  SB_Orders,  NyBestOrd,  Bestord,              ____,  S_PRVW, S_DN_W,  S_NXTW,   ____,   ____,       
// |--------+-----+------+------+------+------+------+------.,------+------+------+------+------+-------+------+--------|
    ____ ,   ____, Nav_PRV,   Nav_O_C,  Nav_NXT,  ____,  ____,  ____,   ____,  ____,  ____,  ____,  ____,   ____,   ____,   ____,    
// `---------------------+------+------+------+------+------||------+------+------+------+------+-----------------------'
                          _____, _____, _____, _____, _____,  _____, _____, _____, _____, _____   
//                       `----------------------------------'`----------------------------------'      
    ),

//Hammerspoon window management shortcuts - coded in hammerspoon config 
// ,------------------------------------------.                            ,----------------------------+------+--------.
//   ____,   1/6 ,  2/6  , 3/6 ,  1/4,   2/4,                                3/4,   4/4,    4/6,   5/6,   6/6,   ____  ,    
// |--------+-----+------+------+------+------|                            |------+------+------+-------+------+--------|
//  ____ ,   1/3 ,  2/3  , 3/3, fullscr,Layout,                              ____, Focu_l, Focu_u, Focu_r,____ , ____     
// |--------+-----+------+------+------+------+------+------.,------+------+------+------+------+-------+------+--------|
//    ____ ,   ____, ____,  ____,  ____,  ____,  ____,  ____,   ____,  ____,LScn  ,  Rscn  Focu_d, ____,  ____,  ____,    
// `---------------------+------+------+------+------+------||------+------+------+------+------+-----------------------'
//                        _____, _____, _____, _____, _____,  _____, _____, _____, _____, ____   
//                       `----------------------------------'`----------------------------------'  

/*  
    [GREEK] = LAYOUT(
        _______, _______, _______, EPSLN,   RHO,     TAU,                                         PSI,  UPSLN,   IOTA,    OMCRN, PI,          THETA,
        _______, ALPHA,   SIGMA,   DELTA,   PHI,     GAMMA,                                       ETA,  _______, KAPPA,   LAMBD, _______,   _______,
        _______, ZETA,    XI,      CHI,     OMEGA,   BETA,    _______, _______, _______, _______, NU,   GMU,     _______, _______, _______, _______,
                                   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
    
    [EMOTICONS] = LAYOUT(
        _______, _______, _______, _______,  FUNNY, THINK,                                            _______,  _______, YAY, _______, SHIT,  _______,
        _______, _______, SMIRK,   DRINK,    PARTY, _______,                                          _______,  _______, NAY, _______, _______, _______,
        _______, _______, _______, COOL,     _______, _______, _______, _______,    _______, _______, _______,  MONEY, _______, _______, _______, _______,
                                   _______,  _______, _______, _______, _______,    _______, _______, _______, _______, _______
    ),*/
};