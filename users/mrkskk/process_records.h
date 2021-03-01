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

#define MAC_NTAB LGUI(KC_T)
#define WIN_NTAB C(KC_T)

#define ENDASH_MAC LALT(KC_SLSH)
#define EMDASH_MAC S(LALT(KC_SLSH)) 


//For home row mods GUI and Ctrl swap
#define A_WIN LGUI_T(KC_A)
#define A_MAC LCTL_T(KC_A)

#define D_WIN LCTL_T(KC_D)
#define D_MAC LGUI_T(KC_D)

#define K_WIN RCTL_T(KC_K)
#define K_MAC RGUI_T(KC_K)

#define AE_WIN RGUI_T(DK_AE)
#define AE_MAC RCTL_T(DK_AE)



/*Custom keycode definitions
*******************
*******************/
enum custom_keycodes
{
    KC_MAKE = SAFE_RANGE,
    S_S,
    pil,
    TG_OS,
    AT,
    LCB,
    RCB,
    FIND,
    PRN,
    SWAP1,
    SWAP2,
    PIPE,
    EUR,
    GBP,
    USD,
    BSLH,
    LEAD,
    NXTW,
    PRVW,
    S_UP_W,
    S_DN_W,
    COPY,
    PASTE,
    CUT,
    UNDO,
    REDO,
    ALL,
    REFSH,
    NTAB,
    EN_EM_DSH,
    EM_DASH,
    EN_DASH,
    S_NXTW,
    S_PRVW,
    L_ARW,
    R_ARW,
    U_ARW,
    D_ARW,
    E_ARW,
    UD_ARW,
    ALPHA,
    BETA,
    GAMMA,
    KAPPA,
    LAMBD,
    FUNNY,
    YAY,
    NAY,
    Cedilla,
    ACUT_E,
    ACUT_A,
    ACUT_I,
    ACUT_O,
    GRV_E,
    GRV_A,
    GRV_I,
    GRV_O,
    TILD_N,
    DIAE_U,
    DIAE_A,
    DIAE_O,
    DIAE_I,
    MOD_A,
    MOD_D,
    MOD_K,
    MOD_AE,
    QWERT, //QWERTY layer
    COLEM, //COLEMAK DH layer
    CAPSWRD, //Caps lock one sentence

};