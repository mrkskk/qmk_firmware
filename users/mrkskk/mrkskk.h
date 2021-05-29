// clang-format on
#pragma once
#include QMK_KEYBOARD_H

//#include  "OS_Toggle.h"
#include "which_os.h"
#include "process_records.h"
#include "oneshot.h"

// #include  "combos.h"

#if defined(LEADER_ENABLE)
#    include "leader.h"
#endif

#if defined(ENCODER_ENABLE)
#    include "encoders.h"
#endif

#if defined(TAP_DANCE_ENABLE)
#    include "tap_dance.h"
#endif

#if defined(RGBLIGHT_ENABLE)
#    include "rgblight_list.h"
#endif

#if defined(UNICODEMAP_ENABLE)
#    include "mrks_unicode_map.h"
#endif

#include <stdio.h>
#include "keymap.h"
#include "quantum.h"
#include "defines_danish.h"
enum layers {
    HANDSDOWN_ALT_NX_DK_MOD = 0,
    NUMPAD,
    SYMBOLS,
    NAV,
    NAV2,
    HAMMERSPOON,
    WINDOWSWINSNAP,
    MOUSE_LAYER,
    MEDIA_LAYER,
    ADJUST,
    FN_LAYER,

};

// LEFT-hand home row mods
//#define CONT_A LCTL_T(KC_A)

#define NAV_T LT(NAV, KC_T)
#define NAV2_H LT(NAV2, KC_H)
#define HMR_O LT(HAMMERSPOON, KC_O)
#define HMR_E TD(HMRWINSNAP)
/*
// HANDSDOWN
// LEFT-hand home row mod
#define CONT_R LCTL_T(KC_R)
#define ALT_S LALT_T(KC_S)
#define COMD_H LGUI_T(KC_H)
#define ALT_B RALT_T(KC_B)

// Right-hand home row mods
#define COMD_I RGUI_T(KC_I)
#define ALT_O LALT_T(KC_O)
#define CONT_A RCTL_T(KC_A)
*/

// Other definitions
#define SC_F2 LT(NAV, KC_F2)
#define OSM_S OSM(MOD_LSFT)
#define ZOOMIN LGUI(PLUS)
#define ZOOMOUT LGUI(MINUS)

#define SLEEP KC_SLEP
#define DEL KC_DEL
#define CAD C(A(KC_DEL))

#define SIGN LALT(KC_S)
#define ACPT LALT(KC_A)

#define PRV_TAB S(C(KC_TAB))
#define NXT_TAB C(KC_TAB)

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
#define LEFT G(A(C(KC_G)))
#define RIGHT G(A(C(KC_H)))
#define FULLSCR G(A(C(KC_F)))
#define MIDDLE G(A(C(KC_M)))
#define wLAYOUT G(A(C(KC_V)))

#define FOCUS_L G(A(C(S(KC_A))))
#define FOCUS_U G(A(C(S(KC_O))))
#define FOCUS_D G(A(C(S(KC_E))))
#define FOCUS_R G(A(C(S(KC_I))))

// LAYERS
#if defined(LEADER_ENABLE)
#    define SYM_LEAD LT(SYMBOLS, LEAD)
#endif

#define MEDIA TG(MEDIA_LAYER)
#define MOUSE TG(MOUSE_LAYER)

//#define FN_ENT LT(NUMPAD, KC_ENTER)

//#define NUM_BSPC LT(NUMPAD, KC_BSPC)

//#define HMR_ESC LT(HAMMERSPOON, KC_ESC)

// For 34 keys
#define N_SYM LT(SYMBOLS, KC_N)
#define FN_ENT LT(FN_LAYER, KC_ENTER)
#define MS_BSPC TD(SYM_D_B)
#define SPC_NUM LT(NUMPAD, KC_SPC)

//#define SPC_DOT TD(SPACE_DOT)
