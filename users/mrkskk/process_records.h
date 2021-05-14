#pragma once
#include <stdbool.h>
void tap_os_key(uint16_t win_keycode, uint16_t mac_keycode, bool pressed);
//void caps_word_enable(void);
//void caps_word_disable(void);
//void caps_word_toggle(void);

#include "casemodes.h"


#undef OSKEY
#define OSKEY(name, windows, mac) name,

#define TAP_HOLD(_tap_, _hold_) \
    if (record->tap.count) record->event.pressed ? register_code16(_tap_) : unregister_code16(_tap_); \
    else if (record->event.pressed) _hold_; \
    return false

//Custom keycode definitions
enum custom_keycodes
{
    CAPSWRD = SAFE_RANGE, // Holds capslock until end of a word - then release capslock
    SNAKECSE,
    TG_OS,                // Toggles WinOS and MacOS layouts (Swap1 and 2 and unicode mode
   #if defined(LEADER_ENABLE)
    LEAD,
   #endif           // Ctrl Alt GUI on hold, Leader on press (Used in tapdance too)
    KC_CL,
    TO_BASE,
    SCROLL_UP,
    SCROLL_DN,
    KC_HV,
    KC_PAA,
    KC_JE,
    KC_FL,
    SP_AS,
    BASE_TRNS,
    L_HANDSDOWN,
    L_QWERTY,
    PW,
    PM,
    PK,
    MW,
    MP,
    LH,
    BSPC_WRD_SENT,
    DEL_WRD_SENT,
    ALT_TAB,    // Change to persistent QWERTY base layer
    #include "oskeys.def"
};
