#pragma once
#include <stdbool.h>

// #include "features/pointing.h"

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

#ifdef LAYER_MODES_ENABLE
#    include "features/layermodes.h"
#endif

#ifdef SENTENCE_CASE_ENABLE
#    include "features/sentence_case.h"
#endif

/* Now in quantum folder
#ifdef POINTING_DEVICE_MODES_ENABLE
#    include "features/pointing_device_modes.h"
#endif
*/
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
    //_NAV_WIN,
    _NUM,
    _NUMROW,
    _FNKEYS,
    // 8 is set to max layers in config currently
};

// Custom keycode definitions
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
    BASE_ENT, // This keycode sends ent and then clears layer. Using this to avoid sending the alpha key from base on keypress
    //KC_QU,
    MAC_MENU,
    KC_SECRET_1,
    KC_SECRET_2,
    KC_SECRET_3,
    LOGIN,
    WORK_MAIL,
    PERS_MAIL,
    //DBLE_BTN1,
   // C_BLCK, // Used in combos
    // YT_SEARCH,
    TO_BASE,
// FLASH,
#ifdef REPEAT_ENABLE
    REPEAT,
#endif
 //iNAV,
#ifdef SENTENCE_CASE_ENABLE
    TG_SENT,
#endif
#ifdef SWAPPER_ENABLE
    SW_REV, // Dead key, reverse direction
    SW_MAC,
    SW_WIN, // Alt+Tab time!
    SW_TAB, // Ctl+Tab time!
// SW_LANG, // Language swapper
#endif
#ifdef UNIVERSAL_OS_KEYS_ENABLE
#    include "features/os_keys.def"
#endif

};

#define ____ _______
// DANISH KEYCODES
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
#define COLON S(MEH_DOT)    // :
#define SEMICOL S(HYP_COM) // ;

// The Danish keymap keys that differ between MAC and WIN OS is defined, and combined to a cross-OS key in oskeys.def
#define LCB_WIN ALGR(KC_7)    // {
#define LCB_MAC LSA(KC_8)     // {
#define RCB_WIN ALGR(KC_0)    // }
#define RCB_MAC LSA(KC_9)     // }
#define PIPE_WIN ALGR(KC_EQL) // |
#define PIPE_MAC LALT(KC_I)   // |
#define HALF_WIN KC_GRAVE     // ½
// HALF_MAC is ONLY AVAILABLE THROUGH UNICODE

// LAYERS
// #define DRAG_TAB LT(0, KC_1)

#define KC_QU LT(0, KC_2)

#define SFT_SPC LSFT_T(KC_SPC)

#define NUM MO(_NUM)
#define NUMROW MO(_NUMROW)





#define MOUSE MO(_MOUSE)
#define MOUSE_N LT(_MOUSE, KC_N)
#define SCROLL MO(_AUTO_DRAGSCLL)

#define EXTR_B LT(_EXTRAS, MEH_B)
#define NAV_MAC MO(_NAV_MAC)

#define UNDO LGUI(KC_Z)
#define COPY LGUI(KC_C)
#define CLIPB_M G(A(KC_C))
#define PASTE LGUI(KC_V)

#define REPLACE LGUI(S(KC_H))
#define RAYCST G(KC_SPC)



// HOME ROW MODS
#define HM_LSFT LSFT_T(KC_R)
#define HM_LALT LALT_T(KC_S)
#define HM_LCTL LCTL_T(KC_T)
#define HM_LGUI LGUI_T(KC_H)
#define HM_RGUI LGUI_T(KC_I)
#define HM_RCTL LCTL_T(KC_E)
#define HM_RALT LALT_T(KC_O)
#define HM_RSFT LSFT_T(KC_A)

#define MEH_B MEH_T(KC_B)
#define HYP_L HYPR_T(KC_L)
#define CAG_D LCAG_T(KC_D)
#define HYP_COM HYPR_T(KC_COMM)

#define HOME_7 LSFT_T(KC_7)
#define HOME_5 LALT_T(KC_5)
#define HOME_1 LCTL_T(KC_1)
#define HOME_3 LGUI_T(KC_3)
#define HOME_4 RGUI_T(KC_4)
#define HOME_2 LCTL_T(KC_2)
#define HOME_6 LALT_T(KC_6)
#define HOME_8 RSFT_T(KC_8)

#define CAG_9 LCAG_T(KC_9)
#define CAG_0 LCAG_T(KC_0)

#define CAG_P LCAG_T(KC_P)
#define HYPR_COM HYPR_T(KC_COM)
#define MEH_DOT MEH_T(KC_DOT)

// RANDOM SHORTCUTS
#define BITWRDN G(S(KC_Y))
#define EMOJI LGUI(LCTL(KC_SPC)) // Emoji keyboard shortcut
#define SLEEP KC_SLEP
#define CA_DEL C(A(KC_DEL))

#ifdef SELECT_WORD_ENABLE
#    define SELECT MO(_SELECT)
#    define SLCT_U S(KC_UP)
#    define SLCT_D S(KC_DOWN)
#endif

// Mac navitagion shortcuts
//#define ZOOM_I G(PLUS)
//#define ZOOM_O G(MINUS)
//#define ZOOM_R G(KC_0)
// #define ZOOM_F G(KC_9)
//#define FONT_I S(A(C(G((KC_8)))))
//#define FONT_D S(A(C(G(KC_9))))

// Using mac with keyboard
// 1.  Installed homerow.app and using it to navigate UI elements with normal mode or search mode
// Set navigation keys inside to match my nonQWERTY layout (ieko)
// For toggling homerow.app
#define HR_APP G(DIAE)
//#define HR_SCROLL S(G(DK_AA))

// Now MENU AND DOCK keys becomes obsolete
#define MENU C(KC_F2) // Focus to menubar mac
#define MENUAPPS C(KC_F8) // Focus to the mac menu bar right side app icons
// #define DOCK C(KC_F3)    // Focus to dock on mac
#define CANCEL G(KC_DOT) // when selecting menues when return will accept the change. This will cancel.
#define HELP S(G(HYP_COM)) //go to help menu


#define S_BTN1 S(KC_BTN1)
#define A_BTN1 A(KC_BTN1)
#define C_BTN1 C(KC_BTN1)
#define G_BTN1 G(KC_BTN1)

//#define GTD_ITEM C(A(KC_SPC))
//#define PASTE_UNFORMAT G(S(KC_V))

#define OF_KEY OS_MEH
#define HMR_KEY OS_CAG

#define KC_CAG LCTL(LALT(KC_LGUI))



#define FN_V LT(_FNKEYS, KC_V)
#define FN_AE LT(_FNKEYS, DK_AE)

// WARPD shortcuts
//#define MODE_GRD G(A(KC_G))
//#define MODE_HNT G(A(KC_X))
//#define MODE_NRM G(A(KC_C))
