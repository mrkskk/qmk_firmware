#pragma once
#include QMK_KEYBOARD_H

//#include  "OS_Toggle.h"
#include  "which_os.h"
#include  "process_records.h"
// #include  "combos.h"

#if defined(LEADER_ENABLE)
#include  "leader.h"
#endif

#if defined(ENCODER_ENABLE)
#include  "encoders.h"
#endif

#if defined(TAP_DANCE_ENABLE)
#include  "tap_dance.h"
#endif

#if defined(RGBLIGHT_ENABLE)
#include  "rgblight_list.h"
#endif

#if defined(UNICODEMAP_ENABLE)
#include  "mrks_unicode_map.h"
#endif

#include <stdio.h>
#include "keymap.h"
#include "quantum.h"

enum layers
{
    QWERTY = 0,
    HANDSDOWN_ALT_NX_DK_MOD,
    NUMPAD,
    L_SYMBOLS,
    R_SYMBOLS,
    ADJUST,
    NAV,
    NAV2,
    HAMMERSPOON,

};

#include "defines_danish.h"

//QWERTY
//QWERTY MOD-TAPS// Left-hand home row mods
// Left-hand home row mods
// Left-hand home row mods
#define HOME_A LCTL_T(KC_A)
#define HOME_S LALT_T(KC_S)
#define HOME_D LGUI_T(KC_D)
#define HOME_F LSFT_T(KC_F)

// Right-hand home row mods
#define HOME_J RSFT_T(KC_J)
#define HOME_K RGUI_T(KC_K)
#define HOME_L LALT_T(KC_L)
#define HOME_QT RCTL_T(KC_QUOT)
//HANDSDOWN
// Left-hand home row mods
#define CTL_R LCTL_T(KC_R)
#define ALT_S LALT_T(KC_S)
#define COMD_T LGUI_T(KC_T)
#define SFT_H LSFT_T(KC_H)

// Right-hand home row mods
#define SFT_I RSFT_T(KC_I)
#define COMD_E RGUI_T(KC_E)
#define ALT_O LALT_T(KC_O)
#define CTL_A RCTL_T(KC_A)
/*
//COLEMAK DH
//COLEMAK DH Mod taps
    #define RSFT_O RSFT_T(KC_O)
//COLEMAK DH HOME row layer toggles
	#define ADJ_R LT(ADJUST, KC_R)
	#define NUM_S LT(NUMPAD, KC_S)
	#define SYM_T LT(R_SYMBOLS, KC_T) //COLEMAK_DH
	#define SYM_N LT(L_SYMBOLS, KC_N) //COLEMAK_DH
 //RSTD
 //RSTD Mod taps
    #define LSFT_R LSFT_T(KC_R) //Pinky shift
	#define LCTL_V LCTL_T(KC_V)
	#define LALT_G LALT_T(KC_G)
    #define RSFT_O RSFT_T(KC_O) //Pinky shift
 //RSTD Layer toggles
    #define NAV_E LT(NAV, KC_E) //for RSTD
    #define SYM_ENT LT(L_SYMBOLS, KC_ENT) //for RSTD
    #define NUM_T LT(NUMPAD, KC_T)
    #define SYM_H LT(R_SYMBOLS, KC_H)
    #define SYM_N LT(L_SYMBOLS, KC_N) //QWERTY
*/
// Other definitions
#define SC_F2 LT(NAV2, KC_F2)
#define OSM_S OSM(MOD_LSFT)
#define ZOOMIN LGUI(PLUS)
#define ZOOMOUT LGUI(MINUS)
#define TRNS KC_TRNS
#define CAPS KC_CAPS
#define SLEEP KC_SLEP
#define DEL KC_DEL
#define CAD C(A(KC_DEL))

#define SIGN LALT(KC_S)
#define ACPT LALT(KC_A)


#define PRV_TAB S(C(KC_TAB))
#define NXT_TAB (C(KC_TAB))


// HAMMERSPOON
#define one_6 G(A(C(KC_Q)))
#define two_6 G(A(C(KC_W)))
#define three_6 G(A(C(KC_E)))

#define four_6 G(A(C(KC_I)))
#define five_6 G(A(C(KC_O)))
#define sixth_6 G(A(C(KC_P)))


#define one_3 G(A(C(KC_A)))
#define two_3 G(A(C(KC_S)))
#define three_3 G(A(C(KC_D)))

#define one_4 G(A(C(KC_R)))
#define two_4 G(A(C(KC_T)))
#define three_4 G(A(C(KC_Y)))
#define four_4 G(A(C(KC_U)))

#define Left_half G(A(C(KC_G)))
#define right_half G(A(C(KC_H)))
#define fullscr G(A(C(KC_F)))
#define midt G(A(C(KC_M)))
#define vlayout G(A(C(KC_V)))


#define TG_NUM TG(NUMPAD)
#define NUM_LEAD  LT(NUMPAD, LEAD)
#define NAV_SPC LT(NAV, KC_SPC)
#define FN_ENT LT(ADJUST, KC_ENT)
#define HMR_BSPC LT(HAMMERSPOON, KC_BSPC)
#define NAV_N LT(NAV, KC_N)// Togges NAV layer on hold and enter on tap
#define SYM_LEAD LT(L_SYMBOLS, LEAD)
#define NUMBER TT(NUMPAD)
