#pragma once
#include <stdbool.h>
void tap_os_key(uint16_t win_keycode, uint16_t mac_keycode, bool pressed);
void caps_word_enable(void);
void caps_word_disable(void);
void caps_word_toggle(void);




#undef OSKEY
#define OSKEY(name, windows, mac) name,




//Custom keycode definitions
enum custom_keycodes
{
    CAPSWRD = SAFE_RANGE, // Holds capslock until end of a word - then release capslock
    SNAKECSE,
    TG_OS,                // Toggles WinOS and MacOS layouts (Swap1 and 2 and unicode mode
    LEAD,                 // Ctrl Alt GUI on hold, Leader on press (Used in tapdance too)
    ACUT_E,               // É
    //ACUT_A,               // Á
    //ACUT_I,               // Í
    //ACUT_O,               // Ó
    GRV_E,                // É
    //GRV_A,                // À
    //GRV_I,                // Ì
    //GRV_O,                // Ò
    //TILD_N,               // Ñ
    //DIAE_U,               // Ü
    //DIAE_A,               // Ä
    //DIAE_O,               // Ö
    //DIAE_I,               // Ï
    SP_AS,
    COLEM,                //  Change to persistent COLEMAK DH base layer
    QWERT,                // Change to persistent QWERTY base layer
    EN_EM_DSH,            // EN dash on press EM dash on shifted press (on both mac and windows)
    #include "oskeys.def"
};
