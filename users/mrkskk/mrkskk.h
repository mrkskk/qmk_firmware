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
    SYMBOLS,
    ADJUST, 
    NAV, 
    SHORTCUTS,
 // GREEK,
 // EMOTICONS,
 // EPIC,

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

#define RALT_E ALGR(KC_E) // é
#define RALT_N ALGR(KC_E) // ñ

//The Danish keymap keys that differ between MAC and WIN OS is defined, and combined to a cross-OS key in process_records.c

/*
 *´
 *
 *  Home row mods
 *
 *
 *
*/
//QWERTY home row mods
//CASG (MacOS) GASC (Windows)

// Left-hand home row mods
	#define LCTL_A LCTL_T(KC_A)
	#define LALT_S LALT_T(KC_S)
	#define LSFT_D LSFT_T(KC_D)
	#define LGUI_F LGUI_T(KC_F)

	// Right-hand home row mods
	#define RGUI_J RGUI_T(KC_J)
	#define RSFT_K RSFT_T(KC_K)
	#define LALT_L LALT_T(KC_L)
	#define RCTL_AE RCTL_T(KC_SCLN)


//COLEMAK DH home row mods
	// Left-hand home row mods
	//#define CTL_A LCTL_T(KC_A)
	#define LALT_R LALT_T(KC_R)
	#define LSFT_S LSFT_T(KC_S)
	#define HOME_T LGUI_T(KC_T)

	// Right-hand home row mods
	#define RGUI_N RGUI_T(KC_N)
	#define RSFT_E RSFT_T(KC_E)
	#define LALT_I LALT_T(KC_I)
	#define RCTL_O RCTL_T(KC_O)

/*
 *´
 *
 *  Other definitions
 *
 *
 *
*/
#define ___ KC_TRNS
#define _____ KC_TRNS
#define ____ KC_TRNS
#define MPRV KC_MPRV
#define MPLY KC_MPLY
#define MNXT KC_MNXT
#define MUTE KC_MUTE
#define VOLU KC_VOLU
#define VOLD KC_VOLD


#define ESC KC_ESC
#define HOME KC_HOME

#define END KC_END
#define PGUP KC_PGUP
#define PGDN KC_PGDN
#define OP KC_UP
#define LEFT KC_LEFT
#define NED KC_DOWN
#define RGHT KC_RGHT
#define CAPS KC_CAPS
#define SLEP KC_SLEP
#define DEL KC_DEL
#define CAD C(A(KC_DEL))
#define ESC KC_ESC

#define RESET EEP_RST

#define SC_F2 LT(SHORTCUTS, KC_F2)
#define SIGN LALT(KC_S)
#define ACPT LALT(KC_A)


#define BSPC_W  LALT(KC_BSPC) // backspace one word at a time
#define BSPC_S LGUI(KC_BSPC) // backspace whole sentence
#define DEL_W LALT(KC_DEL) // Delete one word at a time
#define DEL_S LGUI(KC_DEL) // Delete whole sentence

#define UNTAB LSFT(KC_TAB)
#define TT_NR TT(NUMPAD) 
#define NVSPC LT(NAV, KC_SPC) // Togges NAV layer on hold and space on tap
#define HLEAD LCAG_T(LEAD) // Toggles Hammerspoon on hold and leader on tap

// #define ABSPC LALT_T(KC_BSPC) // Toggles LALT on hold and backspace on tap
#define CBSPC LCTL_T(KC_BSPC) // Toggles ctrl on hold and backspace on tap
#define NVENT LT(NAV, KC_ENT)// Togges NAV layer on hold and enter on tap
#define SP_LEAD TD(SPLEAD)
#define OSM_T_SFT  LSFT_T(KC_F22)

#define SYESC  LT(SYMBOLS, KC_ESC)
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