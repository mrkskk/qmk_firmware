#pragma once
#include <stdbool.h>

#ifdef SELECT_WORD_ENABLE
#    include "features/select_word.h"
#endif

#ifdef SWAPPER_ENABLE
#    include "features/swapper.h"
#endif

#ifdef CUSTOM_ONESHOT_ENABLE
#    include "features/nshot.h"
#endif

#ifdef LAYER_LOCK_ENABLE
#    include "features/layer_lock.h"
#endif

#ifdef CUSTOM_MOD_ENABLE
#    include "features/custom_mod.h"
#endif

#ifdef TAP_DANCE_ENABLE
#    include "features/tap_dance.h"
#endif

#ifdef UNIVERSAL_OS_KEYS_ENABLE
#    include "features/os_keys.h"
#    undef OSKEY
#    define OSKEY(name, windows, mac) name,

#endif

#include "features/layermodes.h"

#define XXXXXXX KC_NO
#define KC_SECRET_1 SECRET_1
#define KC_SECRET_2 SECRET_2
#define KC_SECRET_3 SECRET_3

// DEFINES
// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _MOUSE,
    _NAV_MAC,
    _NAV_WIN,
    _NUM_WIN,
    _NUM_MAC,
    _FNKEYS,
    _AUTO_DRAGSCLL,
    // 16 is set to max layers in config currently
};

// Custom keycode definitions
enum custom_keycodes {
    TG_OS = QK_USER,
#ifdef CUSTOM_ONESHOT_ENABLE
    OS_LSFT,
    OS_LCTL,
    OS_LALT,
    OS_LGUI,
#endif
#ifdef SELECT_WORD_ENABLE
    S_R_WRD,
    S_L_WRD,
#endif
#ifdef LAYER_LOCK_ENABLE
    LLOCK,
#endif

    /*R_PIPE,
    R_DEF,
    */
    BASE_ENT,
    TG_EDIT,

    BV,

    KC_QU,
    KC_SECRET_1,
    KC_SECRET_2,
    LOGIN,
    // C_BLCK,
    FLASH,
    ACUTE_E,
#ifdef REPEAT_ENABLE
    REPEAT,
#endif
    NUM,
    NAV,
// TO_BASE,
#ifdef SWAPPER_ENABLE
    SW_REV, // Dead key, reverse direction
    SW_MAC,
    SW_WIN, // Alt+Tab time!
    SW_TAB, // Ctl+Tab time!
#endif
#ifdef UNIVERSAL_OS_KEYS_ENABLE
#    include "features/os_keys.def"
#endif

};

#define SLEEP KC_SLEP
#define CA_DEL C(A(KC_DEL))

// Layers
// #define TAB_HYPR HYPR_T(KC_TAB)

#ifdef SELECT_WORD_ENABLE
#    define SELECT MO(_SELECT)
#    define SLCT_U S(KC_UP)
#    define SLCT_D S(KC_DOWN)
#endif

// TILING WINDOW MANAGE LAYER
// #define frst3rd G(A(C(KC_5)))
// #define centr3rd G(A(C(KC_6)))
// #define last3rd G(A(C(KC_7)))
// #define UPPER G(A(C(KC_COMM)))
// #define LOWER G(A(C(KC_DOT)))

// OS dependent shortcuts - unified in in process_records (with oskeys.def)
// #define LEFT_HALF_MAC G(A(C(KC_8)))
// #define RIGHT_HALF_MAC G(A(C(KC_9)))
// #define LEFT_HALF_WIN G(KC_LEFT)
// #define RIGHT_HALF_WIN G(KC_RIGHT)
// #define FULLSCR_MAC G(A(C(KC_0)))
// #define FULLSCR_WIN A(KC_ENTER)
// #define ALLHALF G(A(C(KC_H)))

#define HALF KC_GRAVE   // ½
#define EXLM S(KC_1)    // !
#define DQUO S(KC_2)    // "
#define HASH S(KC_3)    // #
#define PERC S(KC_5)    // %
#define QUOT KC_NUHS    // '
#define LPRN S(KC_8)    // (
#define RPRN S(KC_9)    // )
#define ACUTE KC_EQL    // ´ (dead)
#define GRAVE S(ACUTE)  // ` (dead)
#define LBRC ALGR(KC_8) // [
#define RBRC ALGR(KC_9) //  ]
#define AMPR S(KC_6)    //
#define SLSH S(KC_7)    //  /
// #define USD  KC_NUBS      //<
#define PARAG S(KC_NUBS) //>
#define ASTR S(KC_NUHS)  //*
#define EQL S(KC_0)      // =
#define QUES S(KC_MINS)  // ?
#define PLUS KC_MINS     // +
#define PLUS2 KC_PPLS    // +
#define HAT S(KC_RBRC)   // ^ (dead)
#define DIAE KC_RBRC     // ¨ (dead)
#define TILDE ALGR(DIAE) // ~ (dead)

#define LABK KC_NUBS   // >
#define RABK S(LABK)   // <
#define DK_AE KC_SCLN  // Æ
#define DK_OE KC_QUOT  // Ø
#define DK_AA KC_LBRC  // Å
#define MINUS KC_SLSH  // -
#define UNDSC S(MINUS) // _
#define COLON S(KC_DOT)
#define SEMICOL S(KC_COMM)
// The Danish keymap keys that differ between MAC and WIN OS is defined, and combined to a cross-OS key in oskeys.def
#define LCB_WIN ALGR(KC_7)
#define LCB_MAC LSA(KC_8)
#define RCB_WIN ALGR(KC_0)
#define RCB_MAC LSA(KC_9)
#define PIPE_WIN ALGR(KC_EQL)
#define PIPE_MAC LALT(KC_I)
#define HALF_WIN KC_GRAVE // ½

#define EMOJI LGUI(LCTL(KC_SPC)) // Emoji keyboard shortcut

#define DRAG_TAB LT(0, KC_1)
#define KC_QU LT(0, KC_2)
#define DRAG_COMM LT(_AUTO_DRAGSCLL, KC_COMM)

#define DRAG_L LT(_AUTO_DRAGSCLL, KC_L)
#define FN_DOT LT(_FNKEYS, KC_DOT)

#define SPTLGHT A(KC_SPC)

#define UNDO_W LCTL(KC_Z)
#define UNDO_M LGUI(KC_Z)

#define COPY_W LCTL(KC_C)
#define COPY_M LGUI(KC_C)

#define CLIPB_W C(KC_E)
#define CLIPB_M G(A(KC_C))

#define PASTE_W LCTL(KC_V)
#define PASTE_M LGUI(KC_V)

#define REDO_W LCTL(KC_Y)
#define REDO_M S(G(KC_Z))
// #define QUIT_W A(KC_F4)
// #define QUIT_M G(KC_Q)

#define FIND_W LCTL(KC_F)
#define FIND_M LGUI(KC_F)

#define REPLACE_W LCTL(KC_H)
#define REPLACE_M LGUI(S(KC_H))

#define PRV_W_W LCTL(KC_LEFT)
#define NXT_W_W LCTL(KC_RIGHT)
#define SPRV_W_W LCTL(S(KC_LEFT))
#define SNXT_W_W LCTL(S(KC_RIGHT))

#define PRV_W_M LALT(KC_LEFT)
#define NXT_W_M LALT(KC_RIGHT)
#define SPRV_W_M LALT(S(KC_LEFT))
#define SNXT_W_M LALT(S(KC_RIGHT))

#define SEARCH_W KC_LGUI
#define SEARCH_M G(KC_SPC)

#define SFT_SPC LSFT_T(KC_SPC)
