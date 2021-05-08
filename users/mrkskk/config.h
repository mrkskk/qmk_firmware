

#pragma once

#ifdef UNICODEMAP_ENABLE
#define UNICODE_SELECTED_MODES UC_MAC, UC_WIN
#define UNICODE_CYCLE_PERSIST false
#endif

#ifdef OLED_DRIVER_ENABLE
 #ifdef OLED_DRIVER_ENABLE
  #define OLED_DISPLAY_128X64
  #define OLED_TIMEOUT 300000
#endif
#endif


// The Leader key allows to flexibly assign macros to key sequences.
#undef LEADER_TIMEOUT
#define LEADER_PER_KEY_TIMING
#define LEADER_TIMEOUT 1500
// #define LEADER_KEY_STRICT_KEY_PROCESSING If enabled I have to use entire mod-tap keycodes (ec. LGUI_T(KC_J) instead of KC_J )

//Home row mods
// Configure the global tapping term (default: 200ms)
#define TAPPING_TERM 150

// Prevent normal rollover on alphas from accidentally triggering mods.
#define IGNORE_MOD_TAP_INTERRUPT

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
//#define TAPPING_FORCE_HOLD
// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define TAPPING_FORCE_HOLD_PER_KEY
#define TAPPING_TERM_PER_KEY

#define PERMISSIVE_HOLD


// Apply the modifier on keys that are tapped during a short hold of a modtap
//#define PERMISSIVE_HOLD


//One shots
#define ONESHOT_TIMEOUT     2500 //Time (in ms) before the one shot key is released */
#define ONESHOT_TAP_TOGGLE  3
#define TAPPING_TOGGLE 3 // Number of taps to lock Numpad layer (TT)

#ifdef COMBO_ENABLE
#define COMBO_TERM 30
//#define COMBO_HOLD_TERM 300
#define COMBO_TERM_PER_COMBO
#define COMBO_MUST_TAP_PER_COMBO
//#define COMBO_MUST_HOLD_PER_COMBO
//#define COMBO_PERMISSIVE_HOLD
#undef COMBO_NO_TIMER

//#define COMBO_ONLY_FROM_LAYER 0 //Always use the combo positions from the QWERTY layer - also when on colemak. (to avoid remapping all combos for colemakdh)
//#define COMBO_COUNT 11 //Instead it is automatically updated by the combodef vpath
//#define EXTRA_LONG_COMBOS //Instead it is automatically updated by the combodef vpath
#endif

#define EE_HANDS

// Allows media codes to properly register in macros and rotary encoder code
#define TAP_CODE_DELAY 10


#ifdef ENCODER_ENABLE
// EC11K encoders have a different resolution than other EC11 encoders.
// When using the default resolution of 4, if you notice your encoder skipping
// every other tick, lower the resolution to 2.
#define ENCODER_RESOLUTION 2
#endif

////////////////////////////////
////// RGB LED ANIMATIONS //////
////////////////////////////////
	//#define RGBLIGHT_SLEEP
    //#define RGBLIGHT_HUE_STEP 8
    //#define RGBLIGHT_SAT_STEP 8
    //#define RGBLIGHT_VAL_STEP 8
 	//#define RGBLIGHT_LED_MAP {0,1,2,9,8,7,4,3,5,6,19,18,17,10,11,12,15,16,14,13} // Orients Kyria LEDs to a circle around both halves.
    //#define RBGLIGHT_LED_MAP {9,8,6,7,5,3,2,4,1,0,10,12,13,11,14,16,17,15,18,19} // Orients Kyria LEDs for a left half-right half columnar progression.


