/* Copyright 2019 Thomas Bårt <thomas@splitkb.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

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
#define LEADER_TIMEOUT 750
#define LEADER_KEY_STRICT_KEY_PROCESSING

//Home row mods
// Configure the global tapping term (default: 200ms)
#define TAPPING_TERM 175  

// Prevent normal rollover on alphas from accidentally triggering mods.
#define IGNORE_MOD_TAP_INTERRUPT

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
//#define TAPPING_FORCE_HOLD
// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define TAPPING_FORCE_HOLD_PER_KEY
#define TAPPING_TERM_PER_KEY


// Apply the modifier on keys that are tapped during a short hold of a modtap
//#define PERMISSIVE_HOLD


//One shots 
#define ONESHOT_TIMEOUT     2500 //Time (in ms) before the one shot key is released */
#define ONESHOT_TAP_TOGGLE  3
#define TAPPING_TOGGLE 2

#ifdef COMBO_ENABLE
#define COMBO_TERM 50
#define COMBO_HOLD_TERM 300
#define COMBO_PERMISSIVE_HOLD


#define COMBO_MUST_TAP_PER_COMBO
#define COMBO_ONLY_FROM_LAYER 0 //Always use the combo positions from the QWERTY layer - also when on colemak. (to avoid remapping all combos for colemakdh)
//#define COMBO_COUNT 11 //Instead it is automatically updated by the combodef vpath
//#define COMBO_NO_TIMER //Instead it is automatically updated by the combodef vpath
//#define EXTRA_LONG_COMBOS //Instead it is automatically updated by the combodef vpath
#endif

#define EE_HANDS

// Allows media codes to properly register in macros and rotary encoder code
#define TAP_CODE_DELAY 10
// EC11K encoders have a different resolution than other EC11 encoders.
// When using the default resolution of 4, if you notice your encoder skipping
// every other tick, lower the resolution to 2.
#define ENCODER_RESOLUTION 2


////////////////////////////////
////// RGB LED ANIMATIONS //////
////////////////////////////////
	//#define RGBLIGHT_SLEEP
    //#define RGBLIGHT_HUE_STEP 8
    //#define RGBLIGHT_SAT_STEP 8
    //#define RGBLIGHT_VAL_STEP 8
 	//#define RGBLIGHT_LED_MAP {0,1,2,9,8,7,4,3,5,6,19,18,17,10,11,12,15,16,14,13} // Orients Kyria LEDs to a circle around both halves.
    //#define RBGLIGHT_LED_MAP {9,8,6,7,5,3,2,4,1,0,10,12,13,11,14,16,17,15,18,19} // Orients Kyria LEDs for a left half-right half columnar progression.

#define DISABLE_RGB_MATRIX_ALPHAS_MODS
#define DISABLE_RGB_MATRIX_GRADIENT_UP_DOWN
#define DISABLE_RGB_MATRIX_BREATHING
#define DISABLE_RGB_MATRIX_BAND_SAT
#define DISABLE_RGB_MATRIX_BAND_VAL
#define DISABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
#define DISABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
#define DISABLE_RGB_MATRIX_BAND_SPIRAL_SAT
#define DISABLE_RGB_MATRIX_BAND_SPIRAL_VAL
#define DISABLE_RGB_MATRIX_CYCLE_ALL
#define DISABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
#define DISABLE_RGB_MATRIX_CYCLE_UP_DOWN
#define DISABLE_RGB_MATRIX_CYCLE_OUT_IN
#define DISABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
#define DISABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
#define DISABLE_RGB_MATRIX_DUAL_BEACON
#define DISABLE_RGB_MATRIX_CYCLE_PINWHEEL
#define DISABLE_RGB_MATRIX_CYCLE_SPIRAL
#define DISABLE_RGB_MATRIX_RAINBOW_BEACON
#define DISABLE_RGB_MATRIX_RAINBOW_PINWHEELS
#define DISABLE_RGB_MATRIX_RAINDROPS
#define DISABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
#define DISABLE_RGB_MATRIX_TYPING_HEATMAP
#define DISABLE_RGB_MATRIX_DIGITAL_RAIN
#define DISABLE_RGB_MATRIX_SOLID_REACTIVE
#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
#define DISABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
#define DISABLE_RGB_MATRIX_SPLASH
#define DISABLE_RGB_MATRIX_MULTISPLASH
#define DISABLE_RGB_MATRIX_SOLID_SPLASH
#define DISABLE_RGB_MATRIX_SOLID_MULTISPLASH
