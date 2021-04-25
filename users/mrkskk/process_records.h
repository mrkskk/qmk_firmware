#pragma once
#include <stdbool.h>
void tap_os_key(uint16_t win_keycode, uint16_t mac_keycode, bool pressed);
//void caps_word_enable(void);
//void caps_word_disable(void);
//void caps_word_toggle(void);

#include "casemodes.h"


#undef OSKEY
#define OSKEY(name, windows, mac) name,

//Custom keycode definitions
enum custom_keycodes
{
    CAPSWRD = SAFE_RANGE, // Holds capslock until end of a word - then release capslock
    SNAKECSE,
    TG_OS,                // Toggles WinOS and MacOS layouts (Swap1 and 2 and unicode mode
    LEAD,                 // Ctrl Alt GUI on hold, Leader on press (Used in tapdance too)
    KC_CL,
    KC_GL,
    KC_HV,
    KC_PAA,
    KC_JE,
    KC_FL,
    TO_BASE,
    SP_AS,
    BASE_TRNS,
    L_HANDSDOWN,
    L_QWERTY,                // Change to persistent QWERTY base layer
    #include "oskeys.def"
};
