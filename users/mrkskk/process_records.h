// clang-format on
#pragma once
#include <stdbool.h>
void tap_os_key(uint16_t win_keycode, uint16_t mac_keycode, bool pressed);

#include "window_tab.h"

#include "casemodes.h"
#include "layermodes.h"
#include "mymod.h"

#undef OSKEY
#define OSKEY(name, windows, mac) name,

#undef SFT_OSKEY
#define SFT_OSKEY(name, shiftedmac, shiftedwin, unshiftedmac, unshiftedwin) name,

#define TAP_HOLD(_tap_, _hold_)                                                    \
    if (record->tap.count)                                                         \
        record->event.pressed ? register_code16(_tap_) : unregister_code16(_tap_); \
    else if (record->event.pressed)                                                \
        _hold_;                                                                    \
    return false

// keycode names used in process bool
#define SIGN LALT(KC_S)
#define ACPT LALT(KC_A)

// Custom keycode definitions
enum custom_keycodes {
    CAPSWRD = SAFE_RANGE,  // Holds capslock until end of a word - then release capslock
    NUMWRD,
    SNAKECSE,
    TG_OS,
#if defined(LEADER_ENABLE)
    LEAD,
#endif  // Ctrl Alt GUI on hold, Leader on press (Used in tapdance too)
    KC_CL,
    TO_BASE,
    KC_JE,
    SP_AS,
    BASE_TRNS,
    L_HANDS,
    L_QWERTY,
    BSPC_W_S,
    DEL_W_S,
    DEL_WRD,
    MSWHEEL,
    ALT_TAB,
    PW,
    PM,
    PK,
    MW,
    MP,
    LH,
    RP,
    CLEAR,

    // Instant oneshot mods
    OS_SHFT,
    OS_CTRL,
    OS_ALT,
    OS_CMD,
    UNDOREDO,
    CPYPASTE,
#include "oskeys.def"
#include "shiftedoskeys.def"
    S_SLSH,
    MYMOD,
    MYMOD2,
    ARR_L,
    ARR_R, 
    MOD_R,
WRITE_OS,ts
};
