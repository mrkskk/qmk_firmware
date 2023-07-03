// clang-format on
#pragma once
#define IGNORE_MOD_TAP_INTERRUPT
// #define BILATERAL_COMBINATIONS 600

#define TAPPING_TERM 160

#ifdef COMBO_ENABLE
// #    define COMBO_MUST_PRESS_IN_ORDER_PER_COMBO
#    define COMBO_MUST_TAP_PER_COMBO
// #    define COMBO_TERM_PER_COMBO
#    undef COMBO_TERM
#    define COMBO_TERM 30
#    define COMBO_ONLY_FROM_LAYER 0
#endif

#ifdef POINTING_DEVICE_ENABLE
#    define POINTING_DEVICE_AUTO_MOUSE_ENABLE
// #    define POINTING_DEVICE_MODES_ENABLE

#    define AUTO_MOUSE_TIME 800
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
#define NO_MUSIC_MODE    // not using speakers
#define LAYER_STATE_8BIT // maximum of 8 layers
// #define LAYER_STATE_16BIT // maximum of 16 layers

#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION
// #define NO_ACTION_ONESHOT // disable One shot layers and mods.
// Enabling oneshot is needed for using "sentence_case"

#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE

// #define DEBOUNCE 10 //if problems with chatter

#ifdef SENTENCE_CASE_ENABLE
#    define SENTENCE_CASE_BUFFER_SIZE 7
#endif