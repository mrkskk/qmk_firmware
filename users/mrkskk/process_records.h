#pragma once
#include <stdbool.h>
void caps_word_enable(void);
void caps_word_disable(void);
void caps_word_toggle(void);


#define LCBR_WIN ALGR(KC_7) // { 
#define RCBR_WIN ALGR(KC_0) // }
#define LCBR_MAC LSA(KC_8) // { 
#define RCBR_MAC LSA(KC_9) // }
#define AT_WIN ALGR(KC_2)    // @
#define AT_MAC LALT(QUOT) // @
#define BSLH_MAC LALT(SLSH)
#define BLSH_WIN ALGR(LABK)
#define PIPE_WIN ALGR(KC_EQL) // |
#define PIPE_MAC LALT(KC_I)

//Often used shortcuts that differ between danish MAC keyboard and danish WIN keyboard
//Most shortcuts are simply managed by swapping ctrl and gui (SWAP1 and SWAP2 keys)

#define MAC_NEXT_WORD         LALT(KC_RIGHT) // MAC Move words right
#define MAC_PREV_WORD         LALT(KC_LEFT)  // MAC Move words left
#define WIN_NEXT_WRD         LCTL(KC_RIGHT) // WIN Move words right
#define WIN_PREV_WRD         LCTL(KC_LEFT) // WIN Move words left

#define MAC_S_NEXT_WORD         LALT(S(KC_RIGHT)) // MAC Move words right
#define MAC_S_PREV_WORD         LALT(S(KC_LEFT))  // MAC Move words left
#define MAC_S_UP_WRD         LALT(S(KC_UP)) // WIN Move words up
#define MAC_S_DN_WRD         LALT(S(KC_DOWN)) // WIN Move words down

#define WIN_S_NEXT_WRD         LCTL(S(KC_RIGHT)) // WIN Move words right
#define WIN_S_PREV_WRD         LCTL(S(KC_LEFT)) // WIN Move words left
#define WIN_S_UP_WRD         LCTL(S(KC_UP)) // WIN Move words up
#define WIN_S_DN_WRD         LCTL(S(KC_DOWN)) // WIN Move words down

#define S_S_MAC LGUI(S(KC_4)) 
#define S_S_WIN KC_PSCREEN

#define PRV_TAB S(C(KC_TAB))
#define NXT_TAB (C(KC_TAB))

#define MAC_COPY LGUI(KC_C)
#define MAC_PASTE LGUI(KC_V)
#define MAC_CUT LGUI(KC_X)
#define MAC_UNDO LGUI(KC_Z)
#define MAC_REDO LGUI(KC_Y)


#define WIN_COPY C(KC_C)
#define WIN_PASTE C(KC_V)
#define WIN_CUT C(KC_X)            
#define WIN_UNDO C(KC_Z)
#define WIN_REDO C(KC_Y)


#define MAC_ALL LGUI(KC_A)
#define WIN_ALL C(KC_A)
#define MAC_REFRESH LGUI(KC_R)
#define WIN_REFRESH C(KC_R)

//#define MAC_NTAB LGUI(KC_T)
//#define WIN_NTAB C(KC_T)
//#define ENDASH_MAC LALT(KC_SLSH)
//#define EMDASH_MAC S(LALT(KC_SLSH)) 


//Custom keycode definitions
enum custom_keycodes
{
    CAPSWRD = SAFE_RANGE, // Holds capslock until end of a word - then release capslock
    S_S,                  // take screenshot (on both macOS and windows)
    TG_OS,                // Toggles WinOS and MacOS layouts (Swap1 and 2 and unicode mode)
    FIND,                 // Activate Alfred on MacOS and Search bar on windows
    SWAP1,                // Send GUI on macOS and CTRL on Windows
    SWAP2,                // Send CTRL on macOS and GUI on Windows
    //KC_F22              // F22is already a keycode. LSFT_T(KC_F22) sends shift on hold and OSM shift on tap
    AT,                   // send @ (on both macOS and windows)
    LCB,                  // send { (on both macOS and windows)
    RCB,                  // Send } (on both macOS and windows)
    PIPE,                 // Send | (on both macOS and windows)
    EUR,                  // Send € (on both macOS and windows) - Used in leader
    GBP,                  // Send £ (on both macOS and windows) - Used in leader
    USD,                  // Send $(on both macOS and windows) - Used in leader 
    BSLH,                 // Send backslash (on both macOS and windows)
    NXTW,                 // move cursor one word right
    PRVW,                 // move cursor one word left
    S_NXTW,               // move cursor one word right and select
    S_PRVW,               // move cursor one word left and select
    S_UP_W,               // move cursor one word up and select
    S_DN_W,               // move cursor one word down and select
    COPY,                 // copy shortcut (on both macOS and windows)
    PASTE,                // paste shortcut (on both macOS and windows)
    CUT,                  // cut shortcut (on both macOS and windows)
    UNDO,                 // undo shortcut (on both macOS and windows)
    REDO,                 // Redo shortcut (on both macOS and windows)
    ALL,                  // select all shortcut (on both macOS and windows)
    REFSH,                // Refresh shortcut (on both macOS and windows)
    LEAD,                 // Ctrl Alt GUI on hold, Leader on press (Used in tapdance too)
    Cedilla,              // Sends cedilla - Might not work on windows
    ACUT_E,               // É
    ACUT_A,               // Á
    ACUT_I,               // Í
    ACUT_O,               // Ó
    GRV_E,                // É
    GRV_A,                // À
    GRV_I,                // Ì
    GRV_O,                // Ò
    TILD_N,               // Ñ
    DIAE_U,               // Ü
    DIAE_A,               // Ä
    DIAE_O,               // Ö
    DIAE_I,               // Ï
    COLEM,                //  Change to persistent COLEMAK DH base layer
    QWERT,                // Change to persistent QWERTY base layer
    EN_EM_DSH,            // EN dash on press EM dash on shifted press (on both mac and windows)
};