// clang-format on
#pragma once

#define PERMISSIVE_HOLD
// #define BILATERAL_COMBINATIONS 600

#define TAPPING_TERM 180

#ifdef COMBO_ENABLE
// #    define COMBO_MUST_PRESS_IN_ORDER_PER_COMBO
#    define COMBO_MUST_TAP_PER_COMBO
// #    define COMBO_TERM_PER_COMBO
#    undef COMBO_TERM
#    define COMBO_TERM 20
#    define COMBO_ONLY_FROM_LAYER 0
#endif

#ifdef POINTING_DEVICE_ENABLE
#    define POINTING_DEVICE_AUTO_MOUSE_ENABLE
// #    define POINTING_DEVICE_MODES_ENABLE

#    define AUTO_MOUSE_TIME 650
#    define CHARYBDIS_AUTO_SNIPING_ON_LAYER

// #    define CHARYBDIS_DRAGSCROLL_REVERSE_X
#    define CHARYBDIS_DRAGSCROLL_REVERSE_Y
#endif // POINTING_DEVICE_ENABLE

#define MK_KINETIC_SPEED
#define MOUSEKEY_DELAY 5                        // Delay between pressing a movement key and cursor movement
#define MOUSEKEY_INTERVAL 5                     // Time between cursor movements in milliseconds
#define MOUSEKEY_MOVE_DELTA 120                 // Step size for accelerating from initial to base speed
#define MOUSEKEY_INITIAL_SPEED 700              // Initial speed of the cursor in pixel per second
#define MOUSEKEY_BASE_SPEED 1500                // Maximum cursor speed at which acceleration stops
#define MOUSEKEY_DECELERATED_SPEED 50           // Decelerated cursor speed
#define MOUSEKEY_ACCELERATED_SPEED 50           // Accelerated cursor speed
#define MOUSEKEY_WHEEL_INITIAL_MOVEMENTS 4      // Initial number of movements of the mouse wheel
#define MOUSEKEY_WHEEL_BASE_MOVEMENTS 8         // Maximum number of movements at which acceleration stops
#define MOUSEKEY_WHEEL_ACCELERATED_MOVEMENTS 12 // Accelerated wheel movements
#define MOUSEKEY_WHEEL_DECELERATED_MOVEMENTS 8  // Decelerated wheel movements

// #define MOUSEKEY_WHEEL_DELAY 100
// #define MOUSEKEY_WHEEL_INTERVAL 100
// #define MOUSEKEY_WHEEL_TIME_TO_MAX 100

#ifdef AUTO_SHIFT_ENABLE
// #    define RETRO_SHIFT 200
#    define AUTO_SHIFT_TIMEOUT 190
// #    define NO_AUTO_SHIFT_SPECIAL
#    define NO_AUTO_SHIFT_ALPHA
// #    define NO_AUTO_SHIFT_NUMERIC
#    define AUTO_SHIFT_NO_AUTO_REPEAT
#endif

// saving bytes
#define NO_MUSIC_MODE // not using speakers
// define LAYER_STATE_8BIT   // maximum of 8 layers
#define LAYER_STATE_16BIT // maximum of 16 layers

#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION
// #define NO_ACTION_ONESHOT // disable One shot layers and mods.
// Enabling oneshot is needed for using "sentence_case"

#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE

// #define DEBOUNCE 10 //if problems with chatter

#ifdef SENTENCE_CASE_ENABLE
#    define SENTENCE_CASE_BUFFER_SIZE 7
// #    define SENTENCE_CASE_TIMEOUT 3000
#endif
