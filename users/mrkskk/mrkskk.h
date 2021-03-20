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
    SHORTCUTS,
};

/*
 *
 *
 * Danish Keymap
 *
 *
 *
*/
#define EXLM S(KC_1)// !
#define DQUO S(KC_2)// "
#define HASH S(KC_3)// #
#define PERC S(KC_5)// %
#define QUOT KC_NUHS // '
#define LPRN S(KC_8)// (
#define RPRN S(KC_9)// )
#define ACUT KC_EQL// ´ (dead)
#define GRV  S(ACUT) // ` (dead)
#define LBRC ALGR(DK_8) // [
#define RBRC ALGR(DK_9)//  ]
#define AMPR S(KC_6) //
#define SLSH S(KC_7)//  /
#define LABK KC_NUBS//<
#define RABK S(KC_NUBS)//>
#define ASTR S(KC_NUHS)//*
#define EQL S(KC_0)// =
#define QUES S(KC_MINS) // ?
#define PLUS KC_MINS // +
#define HAT S(KC_RBRC) // ^ (dead)
#define DIAE KC_RBRC // ¨ (dead)
#define TILD ALGR(DIAE) // ~ (dead)
#define HALF_WIN KC_GRV  // ½
#define PARA S(KC_GRV) // §
#define DK_AE   KC_SCLN // Æ
#define DK_OE   KC_QUOT // Ø
#define DK_AA   KC_LBRC // Å
#define MINUS  KC_SLSH // -
#define UNDSC  S(MINUS)
#define COL  S(KC_DOT)
#define SEMCOL S(KC_COMM)
#define RALT_E ALGR(KC_E) // é
#define RALT_N ALGR(KC_E) // ñ
//The Danish keymap keys that differ between MAC and WIN OS is defined, and combined to a cross-OS key in oskeys.def

/*
 *´
 *
 *  Mod-Taps
 *
 *
 *
*/
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

/*
 *´
 *
 *  Home row layer toggles
 *
 *
 *
*/
	#define ADJ_S LT(ADJUST, KC_S)
 	#define NUM_D LT(NUMPAD, KC_D)
	#define SYM_F LT(R_SYMBOLS, KC_F) //QWERTY
	#define SYM_J LT(L_SYMBOLS, KC_J) //QWERTY

	#define ADJ_R LT(ADJUST, KC_R)
	#define NUM_S LT(NUMPAD, KC_S)
	#define SYM_T LT(R_SYMBOLS, KC_T) //COLEMAK_DH
	#define SYM_N LT(L_SYMBOLS, KC_N) //COLEMAK_DH

/*
 *´
 *
 *  Other definitions
 *
 *
 *
*/

#define SC_F2 LT(SHORTCUTS, KC_F2)
#define OSM_S OSM(MOD_LSFT)
#define ZOOMIN LGUI(PLUS)
#define ZOOMOUT LGUI(MINUS)
#define TRNS KC_TRNS

#define PGUP KC_PGUP
#define PGDN KC_PGDN
#define CAPS KC_CAPS
#define SLEEP KC_SLEP
#define DEL KC_DEL
#define CAD C(A(KC_DEL))

#define SIGN LALT(KC_S)
#define ACPT LALT(KC_A)

#define NVSPC LT(NAV, KC_SPC) // Togges NAV layer on hold and space on tap
#define HLEAD LCAG_T(LEAD) // Toggles Hammerspoon on hold and leader on tap
#define NVENT LT(NAV, KC_ENT)// Togges NAV layer on hold and enter on tap

//#define SYMBOL MO(R_SYMBOLS)
#define NUMBER TT(NUMPAD)
#define SYMB_OE LT(R_SYMBOLS, DK_OE)
#define NUMB_AA LT(NUMPAD, DK_AA)
#define OS_NUM LT(NUMPAD, KC_F23)
#define OS_SYM LT(SYMBOLS, KC_F24)
#define SP_LEAD TD(SPLEAD)

#define PRV_TAB S(C(KC_TAB))
#define NXT_TAB (C(KC_TAB))
/*
// #define SYESC  LT(SYMBOLS, KC_ESC)
#define A_ESC MT(MOD_LALT, KC_ESC)
#define OSL_SC  OSL(SHORTCUTS)
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
