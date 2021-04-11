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
    /*COLEMAK_DH,
    RSTHD,*/
    NUMPAD,
    L_SYMBOLS,
    R_SYMBOLS,
    ADJUST,
    NAV,
    NAV2,

};

#include "defines_danish.h"

//QWERTY
//QWERTY MOD-TAPS
	#define LSFT_A LSFT_T(KC_A) //Pinky shift
	#define LCTL_X LCTL_T(KC_X)
	#define LALT_C LALT_T(KC_C)
    #define G_F LGUI_T(KC_F)
    #define G_J LGUI_T(KC_J)
	#define LALT_COM LALT_T(KC_COMM)
	#define RCTL_DOT RCTL_T(KC_DOT)
    #define RSFT_QT RSFT_T(QUOT) // Pinky shift
// QWERTY HOME row layer toggles
	#define ADJ_S LT(ADJUST, KC_S)
 	#define NUM_D LT(NUMPAD, KC_D)
	#define SYM_D LT(R_SYMBOLS, KC_D) //QWERTY
	#define SYM_K LT(L_SYMBOLS, KC_K) //QWERTY
//HANDSDOWN
    #define LSFT_R LSFT_T(KC_R) //Pinky shift
    #define LCTL_B LCTL_T(KC_B)
    #define LALT_L LALT_T(KC_L)
    #define G_H LGUI_T(KC_H)
    #define G_A LGUI_T(KC_A)

    #define SYM_T LT(R_SYMBOLS, KC_T)
    #define SYM_E  LT(L_SYMBOLS, KC_E)
    #define RSFT_I RSFT_T(KC_I) // Pinky shift
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

#define NAV_SPC LT(NAV, KC_SPC)
#define TILE_LEAD LCAG_T(LEAD) // Toggles Hammerspoon on hold and leader on tap
#define NAV_ENT LT(NAV, KC_ENT)//
#define NAV_N LT(NAV, KC_N)// Togges NAV layer on hold and enter on tap

#define NUM_ENT LT(NUMPAD, KC_ENT)
#define SYM_BSPC LT(L_SYMBOLS, KC_BSPC)
#define NUMBER TT(NUMPAD)
#define TG_NUM TG(NUMPAD)

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
