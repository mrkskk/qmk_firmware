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
    COLEMAK_DH,
    NUMPAD,
    L_SYMBOLS,
    R_SYMBOLS,
    ADJUST,
    NAV,
    NAV2,
};

#include "defines_danish.h"
#include  "sendstring_danish.h"
//MOD-TAPS
//QWERTY
	#define LSFT_A LSFT_T(KC_A) //Pinky shift
	#define LCTL_X LCTL_T(KC_X)
	#define LALT_C LALT_T(KC_C)
	#define LALT_COM LALT_T(KC_COMM)
	#define RCTL_DOT RCTL_T(KC_DOT)
	#define RSFT_AE RSFT_T(DK_AE) // Pinky shift
    #define RSFT_QT RSFT_T(QUOT) // Pinky shift
    #define LSFT_MIN LSFT_T(MINUS) //Pinky shift
    #define LSFT_Z LSFT_T(KC_Z) //Pinky shift
//COLEMAK DH Mod taps
    #define RSFT_O RSFT_T(KC_O)

// HOME row layer toggels
	#define ADJ_S LT(ADJUST, KC_S)
 	#define NUM_D LT(NUMPAD, KC_D)
	#define SYM_F LT(R_SYMBOLS, KC_F) //QWERTY
	#define SYM_J LT(L_SYMBOLS, KC_J) //QWERTY

	#define ADJ_R LT(ADJUST, KC_R)
	#define NUM_S LT(NUMPAD, KC_S)
	#define SYM_T LT(R_SYMBOLS, KC_T) //COLEMAK_DH
	#define SYM_N LT(L_SYMBOLS, KC_N) //COLEMAK_DH

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

#define NAV_SPC LT(NAV, KC_SPC) // Togges NAV layer on hold and space on tap
#define HLEAD LCAG_T(LEAD) // Toggles Hammerspoon on hold and leader on tap
#define NAV_ENT LT(NAV, KC_ENT)// Togges NAV layer on hold and enter on tap

//#define SYMBOL MO(R_SYMBOLS)
#define NUMBER TT(NUMPAD)
#define NUM_TAB LT(NUMPAD, KC_TAB)
#define SYM_ESC LT(L_SYMBOLS, KC_ESC)

//#define SP_LEAD TD(SPLEAD)

#define PRV_TAB S(C(KC_TAB))
#define NXT_TAB (C(KC_TAB))
/*
// #define SYESC  LT(SYMBOLS, KC_ESC)
#define A_ESC MT(MOD_LALT, KC_ESC)
#define OSL_SC  OSL(NAV2)
//Unused definitions
#define Nav_PRV KC_F7
#define Nav_NXT KC_F8
#define Nav_O_C KC_F9
#define Bestord LCTL(KC_O)
#define SB_Orders LALT(KC_M)
#define Smartsets LALT(KC_D)
#define NyBestOrd LALT(KC_W)
#define Move_Field LALT(KC_D)
#define AMBULANT LCA(KC_2)
#define INDLAGT LCA(KC_3)
#define INBASKET LCA(KC_4)
#define PT1 LCA(KC_5)
#define PT2 LCA(KC_6)
#define NXT LCA(KC_6)
#define AFTALER LCTL(KC_5)
#define REMINDER LCTL(KC_4)
#define TLF_K LCTL(KC_3)
#define PTOPSLAG LCTL(KC_2)
#define AFSNIT LCTL(KC_9)

#define C_MOVE_U LCTL(KC_UP)
#define C_MOVE_D LCTL(KC_DOWN)
#define ALTMOVE_U LALT(KC_UP)
#define ALTMOVE_D LALT(KC_DOWN)


#define SPCTD TD(SPCTAPD)
*/
