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
    NAV2_LAYER,
    SYM_LAYER,
    EXTRA_NAV_LAYER,
    EDIT_LAYER,
    WINDOW_MANAGE_LAYER,
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

#define NXT_TAB C(KC_TAB)

// WINDOW_MANAGE_LAYER
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
#define LEFT_MAC G(A(C(KC_G)))
#define RIGHT_MAC G(A(C(KC_H)))
#define FULLSCR G(A(C(KC_F)))
#define MIDDLE G(A(C(KC_M)))
#define wLAYOUT G(A(C(KC_V)))

// changing the focused app with hammerspoon
#define FOCUS_L G(A(C(S(KC_A))))
#define FOCUS_U G(A(C(S(KC_O))))
#define FOCUS_D G(A(C(S(KC_E))))
#define FOCUS_R G(A(C(S(KC_I))))

#define LEFT_WIN G(KC_LEFT)
#define RIGHT_WIN G(KC_RIGHT)

#define S_HOME S(KC_HOME)
#define S_END S(KC_END)
// LAYERS
#if defined(LEADER_ENABLE)
#    define SYM_LEAD LT(SYM_LAYER, LEAD)
#endif

// For 34 keys
//#define N_NAV LT(SYM_LAYER, KC_N)
//#define N_NAV LT(NAV_LAYER, KC_N)

#define SYM_N LT(SYM_LAYER, KC_N)

#define FN MO(FN_LAYER)
#define SYM MO(SYM_LAYER)
#define NUM MO(NUM_LAYER)
#define SPC_NUM LT(NUM_LAYER, KC_SPC)
#define HMR_ENT LT(WINDOW_MANAGE_LAYER, KC_ENTER)
#define MS_BSPC TD(MOUSE_D_B)

#define HOME_R LSFT_T(KC_R)
#define HOME_B LALT_T(KC_B)
#define NAV2_T LT(NAV2_LAYER, KC_T)
#define HOME_H LGUI_T(KC_H)
#define HOME_L LCTL_T(KC_L)

#define HOME_I RGUI_T(KC_I)
#define NAV2_E LT(EDIT_LAYER, KC_E)
#define HOME_DOT LALT_T(KC_DOT)
#define HOME_A RSFT_T(KC_A)
#define HOME_CO RCTL_T(KC_COMM)

#define HOME_P0 LSFT_T(KC_P0)
#define HOME_P1 LALT_T(KC_P1)
#define HOME_P6 LGUI_T(KC_P6)
#define HOME_P2 LCTL_T(KC_P2)
#define HOME_PCO RCTL_T(KC_PDOT)

#define HM_EXLM LSFT_T(KC_F21)
#define HM_ACUT LALT_T(KC_F22)
#define HM_QUES LGUI_T(KC_F23)
#define HM_PIPE LCTL_T(KC_F20)
#define HM_SEMC RCTL_T(KC_F19)

#define HM_LPRN LGUI_T(KC_F20)
#define HM_RBRC LALT_T(KC_F19)

//#define SPC_DOT TD(SPACE_DOT)

// epic emr
#define L_TAB C(S(KC_TAB))
#define R_TAB C(KC_TAB)
#define U_TAB C(KC_UP)
#define D_TAB C(KC_DOWN)

// for left handed navigation
#define CV TD(LEFTNAV_COPY_PASTE)

#define ALFRED LGUI(KC_SPC)

#define EXTRA_SYM MO(EXTRA_NAV_LAYER)

void keyboard_post_init_user(void);
void rgb_matrix_indicators_user(void);
