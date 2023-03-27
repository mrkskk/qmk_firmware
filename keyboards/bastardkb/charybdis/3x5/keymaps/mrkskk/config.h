// clang-format on
#pragma once

#define TAPPING_TERM 160

#ifdef COMBO_ENABLE
// #    define COMBO_MUST_PRESS_IN_ORDER_PER_COMBO
#    define COMBO_MUST_TAP_PER_COMBO
// #    define COMBO_TERM_PER_COMBO
#    define COMBO_TERM 20
#    define COMBO_ONLY_FROM_LAYER 0
#endif

#ifdef POINTING_DEVICE_ENABLE
#    define POINTING_DEVICE_AUTO_MOUSE_ENABLE
#    define AUTO_MOUSE_TIME 850

#    define CHARYBDIS_AUTO_SNIPING_ON_LAYER

// #    define CHARYBDIS_DRAGSCROLL_REVERSE_X
#    define CHARYBDIS_DRAGSCROLL_REVERSE_Y
#endif // POINTING_DEVICE_ENABLE

#ifdef AUTO_SHIFT_ENABLE
// #    define RETRO_SHIFT 200
#    define AUTO_SHIFT_TIMEOUT 160
#    define NO_AUTO_SHIFT_SPECIAL
#    define NO_AUTO_SHIFT_ALPHA
// #    define NO_AUTO_SHIFT_NUMERIC
#    define AUTO_SHIFT_NO_AUTO_REPEAT
#endif

// saving bytes
#define NO_MUSIC_MODE     // not using speakers
#define LAYER_STATE_16BIT // maximum of 7 layers

#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION
#define NO_ACTION_ONESHOT // disable One shot layers and mods

#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE

// #define DEBOUNCE 10 //if problems with chatter