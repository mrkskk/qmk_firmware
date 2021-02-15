#pragma once


#include QMK_KEYBOARD_H
#include  "OS_Toggle.h"

#include  "process_records.h"
// #include  "combos.h"
#include  "leader.h"
#include  "encoders.h"
#include  "tap_dance.h"
#include  "rgblight_list.h"
#include  "mrks_unicode_map.h"
#include <stdio.h>
#include "keymap.h"
#include "quantum.h"

enum layers
{
    QWERTY = 0,
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
#define HALF_MAC 
#define PARA S(KC_GRV) // §


#define DK_AE   KC_SCLN // Æ
#define DK_OE   KC_QUOT // Ø
#define DK_AA   KC_LBRC // Å

#define MINUS  KC_SLSH // -



//The Danish keymap keys that differ between MAC and WIN OS is defined, and combined to a cross-OS key in process_records.c

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
#define CAPS KC_CAPS

#define TOGG RGB_TOG
#define MOD RGB_MOD
#define RMOD RGB_RMOD
#define SAI RGB_SAI
#define HUI RGB_HUI
#define VAI RGB_VAI
#define SPI RGB_SPI
#define SAD RGB_SAD
#define HUD RGB_HUD

#define VAD RGB_VAD
#define SPD RGB_SPD
#define HUD RGB_HUD
#define RESET EEP_RST

#define SC_F2 LT(SHORTCUTS, KC_F2)
#define SIGN LALT(KC_S)
#define ADJ_S LT(ADJUST, SP_SIGN)
#define ACPT LALT(KC_A)
#define GRE_A LT(GREEK, SP_ACPT)


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
#define SYESC  LT(SYMBOLS, KC_ESC)
#define OSL_EMO  OSL(EMOTICONS)
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