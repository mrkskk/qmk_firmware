// clang-format on
#pragma once

// including files
#include QMK_KEYBOARD_H
#include "which_os.h"
#include "process_records.h"
#include "oneshot.h"
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

// defining layers used in keymap.c
enum layers {
    BASE_LAYER = 0,
    NUM_LAYER,
    SYM_LAYER,
    NAV_LAYER,
    NAV2_LAYER,
    MOD_LAYER,
    HAMMERSPOON_LAYER,
    MOUSE_LAYER,
    MEDIA_LAYER,
    ADJUST_LAYER,
    FN_LAYER,

};

// defining keycodes used in keymap.c
// LEFT-hand home row mods

// Other definitions

#define ZOOMIN LGUI(PLUS)
#define ZOOMOUT LGUI(MINUS)

#define SLEEP KC_SLEP
#define DEL KC_DEL
#define CAD C(A(KC_DEL))

// changing tabs
#define PRV_TAB S(C(KC_TAB))
#define NXT_TAB C(KC_TAB)

// HAMMERSPOON_LAYER
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

// changing the focused app with hammerspoon
#define FOCUS_L G(A(C(S(KC_A))))
#define FOCUS_U G(A(C(S(KC_O))))
#define FOCUS_D G(A(C(S(KC_E))))
#define FOCUS_R G(A(C(S(KC_I))))

// LAYERS
#if defined(LEADER_ENABLE)
#    define SYM_LEAD LT(SYM_LAYER, LEAD)
#endif

// For 34 keys
//#define N_NAV LT(SYM_LAYER, KC_N)
//#define N_NAV LT(NAV_LAYER, KC_N)
#define N_NAV TD(NAVTEST)
#define FN_ENT LT(FN_LAYER, KC_ENTER)
#define MS_BSPC TD(MOUSE_D_B)
//#define SPC_NUM TD(DT_SPC_DOT)

#define SYM_N LT(SYM_LAYER, KC_N)
//#define HMR_I TD(HMRWINSNAP)
#define NAV2_I LT(NAV2_LAYER, KC_I)
#define HMR_O LT(HAMMERSPOON_LAYER, KC_O)
#define NAV_T LT(NAV_LAYER, KC_T)
#define NAV2_H LT(NAV2_LAYER, KC_H)
#define MODS MO(MOD_LAYER)
#define NAV_E LT(NAV_LAYER, KC_E)

#define SYM MO(SYM_LAYER)
#define NUM MO(NUM_LAYER)
#define SPC_NUM LT(NUM_LAYER, KC_SPC)
#define SFT_R LSFT_T(KC_R)
#define SFT_A RSFT_T(KC_A)
//#define HMR_O LT(HAMMERSPOON_LAYER, KC_O)

//#define SPC_DOT TD(SPACE_DOT)
