#pragma once
#include <stdbool.h>

/******************************************************************************
 * INCLUDES
 ******************************************************************************/
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

#if defined(UNIVERSAL_OS_KEYS_ENABLE) || defined(OS_DETECTION_ENABLE)
#    include "features/os_keys.h"
#    undef OSKEY
#    define OSKEY(name, windows, mac) name,
#endif

#ifdef LAYER_MODES_ENABLE
#    include "features/layermodes.h"
#endif

#ifdef SENTENCE_CASE_ENABLE
#    include "features/sentence_case.h"
#endif

/******************************************************************************
 * LAYER DEFINITIONS
 ******************************************************************************/
// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _MOUSE,
    _NAV_MAC,
    _NUM,
    _NUMROW,
    _FNKEYS,
    // 8 is set to max layers in config currently
};

/******************************************************************************
 * CUSTOM KEYCODE DEFINITIONS
 ******************************************************************************/
enum custom_keycodes {
    TG_OS = QK_USER,
#ifdef CUSTOM_ONESHOT_ENABLE
    OS_LSFT,
    OS_LCTL,
    OS_LALT,
    OS_RALT,
    OS_LGUI,
    OS_HYPR,
    OS_MEH,
    OS_CAG,
    CLEAR,
    OSS_NAV, // One-shot navigation layer key
#endif
#ifdef SELECT_WORD_ENABLE
    S_R_WRD,
    S_L_WRD,
#endif
#ifdef LAYER_LOCK_ENABLE
    LLOCK,
#endif
    BASE_ENT, // This keycode sends ent and then clears layer
    KC_SECRET_1,
    KC_SECRET_2,
    KC_SECRET_3,
    LOGIN,
    WORK_MAIL,
    PERS_MAIL,
    TO_BASE,
    TILDE_ND, // Tilde not-dead key
#ifdef REPEAT_ENABLE
    REPEAT,
#endif
#ifdef SENTENCE_CASE_ENABLE
    TG_SENT,
#endif
#ifdef SWAPPER_ENABLE
    SW_REV, // Dead key, reverse direction
    SW_MAC,
    SW_WIN, // Alt+Tab time!
    SW_TAB, // Ctl+Tab time!
#endif
#if defined(UNIVERSAL_OS_KEYS_ENABLE) || defined(OS_DETECTION_ENABLE)
    OS_RESET, // Reset OS detection system to default state
    OS_DEBUG, // Print OS detection debug info
#    include "features/os_keys.def"
#endif
};

/******************************************************************************
 * HELPER DEFINITIONS
 ******************************************************************************/

#define XXXXXXX KC_NO

/******************************************************************************
 * LAYER ACCESS KEYS
 ******************************************************************************/
#define NUM MO(_NUM)                // Number layer
#define NUMROW MO(_NUMROW)          // Number row layer
#define MOUSE MO(_MOUSE)            // Mouse layer
#define MOUSE_N LT(_MOUSE, KC_N)    // Mouse layer on hold, N on tap
#define TG_MS TG(_MOUSE)            // Toggle mouse layer
#define NAV_MAC MO(_NAV_MAC)        // Navigation layer for Mac
#define FN_V LT(_FNKEYS, KC_V)      // Function keys layer on hold, V on tap
#define FN_AE LT(_FNKEYS, DK_AE)    // Function keys layer on hold, Æ on tap
#define SCROLL MO(_AUTO_DRAGSCLL)   // Auto drag-scroll layer
#define NUM_SPC LT(_NUMROW, KC_SPC) // Number row layer on hold, NUM_SPC on tap
#define NUM_N LT(_NUMROW, KC_N)     // Number row layer on hold, N on tap
#define FN_BSPC LT(_FNKEYS, KC_BSPC)
#define NUMPAD MO(_NUM) // Function keys layer on hold, BSPC on tap
/******************************************************************************
 * DANISH KEYCODES
 ******************************************************************************/
#define EXLM S(KC_1)       // !
#define DQUO S(KC_2)       // "
#define HASH S(KC_3)       // #
#define PERC S(KC_5)       // %
#define QUOT KC_NUHS       // '
#define LPRN S(KC_8)       // (
#define RPRN S(KC_9)       // )
#define ACUTE KC_EQL       // ´ (dead)
#define GRAVE S(ACUTE)     // ` (dead)
#define LBRC ALGR(KC_8)    // [
#define RBRC ALGR(KC_9)    // ]
#define AMPR S(KC_6)       // &
#define SLSH S(KC_7)       // /
#define PARA S(KC_GRAVE)   // § (on mac)
#define ASTR S(KC_NUHS)    // *
#define EQL S(KC_0)        // =
#define QUES S(KC_MINS)    // ?
#define PLUS KC_MINS       // +
#define HAT S(KC_RBRC)     // ^ (dead)
#define DIAE KC_RBRC       // ¨ (dead)
#define TILDE ALGR(DIAE)   // ~ (dead)
#define LABK KC_NUBS       // >
#define RABK S(LABK)       // <
#define DK_AE KC_SCLN      // Æ
#define DK_OE KC_QUOT      // Ø
#define DK_AA KC_LBRC      // Å
#define MINUS KC_SLSH      // -
#define UNDSC S(MINUS)     // _
#define COLON S(MEH_DOT)   // :
#define SEMICOL S(HYP_COM) // ;

// OS-specific Danish keys
#define LCB_WIN ALGR(KC_7)    // {
#define LCB_MAC LSA(KC_8)     // {
#define RCB_WIN ALGR(KC_0)    // }
#define RCB_MAC LSA(KC_9)     // }
#define PIPE_WIN ALGR(KC_EQL) // |
#define PIPE_MAC LALT(KC_I)   // |
#define HALF_WIN KC_GRAVE     // ½
// HALF_MAC is ONLY AVAILABLE THROUGH UNICODE

/******************************************************************************
 * HOME ROW MODIFIERS
 ******************************************************************************/
// Base layer
#define HM_LSFT LSFT_T(KC_R)
#define HM_LALT LALT_T(KC_S)
#define HM_LCTL LCTL_T(KC_T)
#define HM_LGUI LGUI_T(KC_H)
#define HM_RGUI RGUI_T(KC_I)
#define HM_RCTL RCTL_T(KC_E)
#define HM_RALT RALT_T(KC_O)
#define HM_RSFT RSFT_T(KC_A)

// Number row home row mods
#define HOME_7 LSFT_T(KC_7)
#define HOME_5 LALT_T(KC_5)
#define HOME_1 LCTL_T(KC_1)
#define HOME_3 LGUI_T(KC_3)
#define HOME_4 RGUI_T(KC_4)
#define HOME_2 RCTL_T(KC_2)
#define HOME_6 RALT_T(KC_6)
#define HOME_8 RSFT_T(KC_8)

// Number layer home row mods
#define MEH_1 MEH_T(KC_1)
#define HYPR_2 HYPR_T(KC_2)
#define CAG_3 LCAG_T(KC_3)
#define CAG_1 LCAG_T(KC_1)
#define MEH_3 MEH_T(KC_3)
#define ALT_4 LALT_T(KC_4)
#define GUI_6 LGUI_T(KC_6)
#define GUI_4 LGUI_T(KC_4)
#define CTL_5 LCTL_T(KC_5)
#define ALT_6 LALT_T(KC_6)
#define SFT_0 LSFT_T(KC_0)
#define SFT_N LSFT_T(KC_N)

// Special modifier keys
#define MEH_B MEH_T(KC_B)
#define HYP_L HYPR_T(KC_L)
#define CAG_D LCAG_T(KC_D)
#define CAG_9 LCAG_T(KC_9)
#define CAG_0 LCAG_T(KC_0)
#define CAG_P LCAG_T(KC_P)
#define HYP_COM HYPR_T(KC_COMM)
#define MEH_DOT MEH_T(KC_DOT)

#define MEH_CARET MT(MOD_MEH, KC_F18) // Use unused F-key as dummy
#define HYPR_USD MT(MOD_HYPR, KC_F19) // Use another unused F-key as dummy
/******************************************************************************
 * SHORTCUT KEYS
 ******************************************************************************/
// Common shortcuts
#define UNDO LGUI(KC_Z)
#define COPY LGUI(KC_C)
#define PASTE LGUI(KC_V)
#define CLIPB_M G(A(KC_C))    // Clipboard manager
#define REPLACE LGUI(S(KC_H)) // Find and replace
// #define RAYCST G(KC_SPC)      // Raycast app launcher

/******************************************************************************
 * MOUSE KEYS AND BUTTONS
 ******************************************************************************/
#define S_BTN1 S(MS_BTN1)     // Shift+Click
#define A_BTN1 A(MS_BTN1)     // Alt+Click
#define C_BTN1 C(MS_BTN1)     // Ctrl+Click
#define G_BTN1 G(MS_BTN1)     // GUI+Click
#ifdef POINTING_DEVICE_MODES_ENABLE
#    define PRE_MO PM_MO(PM_PRE) // Precision mode (sniping)
#else
#    define PRE_MO KC_NO
#endif

/******************************************************************************
 * SYSTEM AND UTILITY KEYS
 ******************************************************************************/
#define EMOJI LGUI(LCTL(KC_SPC)) // Emoji keyboard shortcut
#define SLEEP KC_SLEP            // Sleep computer
#define CA_DEL C(A(KC_DEL))      // Ctrl+Alt+Del
#define BITWRDN G(S(KC_Y))       // Bitwarden shortcut

/******************************************************************************
 * FEATURE-SPECIFIC KEYS
 ******************************************************************************/

#define TG_FN TG(_FNKEYS) // Toggle function keys layer
#define KC_CAG LCAG(KC_NO)
