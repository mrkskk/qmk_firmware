// features/adapt_shift.c
#include "adapt_shift.h"
#include "defines.h"

// State tracking variables
static uint16_t adapt_shift_keycode = 0; // The last keycode that could trigger adapt shift
static uint16_t adapt_shift_timer   = 0; // When the shift leader was pressed

bool process_adapt_shift(uint16_t keycode, keyrecord_t *record) {
    // Only process on key press
    if (!record->event.pressed) {
        return true;
    }

    // Extract the basic keycode for comparison (handles mod-tap keys)
    uint16_t current_basic = keycode;
    if (IS_QK_MOD_TAP(keycode)) {
        current_basic = QK_MOD_TAP_GET_TAP_KEYCODE(keycode);
    }

    // Check if this is the adapt shift leader key being pressed
    if (current_basic == ADAPT_SHIFT_KEY) {
        adapt_shift_keycode = keycode;
        adapt_shift_timer   = timer_read();
        return true; // Let the key be processed normally (it will type the character)
    }

    // Extract basic keycode from the stored shift leader for comparison
    uint16_t stored_basic = adapt_shift_keycode;
    if (IS_QK_MOD_TAP(adapt_shift_keycode)) {
        stored_basic = QK_MOD_TAP_GET_TAP_KEYCODE(adapt_shift_keycode);
    }

    // Check if we should apply adaptive shift
    if (stored_basic == ADAPT_SHIFT_KEY &&                         // Was shift leader pressed?
        adapt_shift_timer &&                                       // Timer is active?
        (timer_elapsed(adapt_shift_timer) <= ADAPTIVE_TERM * 4)) { // Within time window?

        // Extract the basic keycode for checking (strip any modifiers/taps)
        uint16_t target_keycode = current_basic & QK_BASIC_MAX;

        // Handle letter keys (A-Z) and Danish characters (Æ, Ø, Å)
        if ((target_keycode >= KC_A && target_keycode <= KC_Z) ||
            target_keycode == DK_AA || target_keycode == DK_OE || target_keycode == DK_AE) {
// Additional safety: don't interfere with caps word
#ifdef CAPS_WORD_ENABLE
            if (is_caps_word_on()) {
                adapt_shift_keycode = 0; // Reset state
                adapt_shift_timer   = 0;
                return true; // Let caps word handle it
            }
#endif

            // Perform the adaptive shift magic:
            tap_code(KC_BSPC);              // Delete the shift leader character (comma)
            tap_code16(S(target_keycode));  // Type the capitalized letter/Danish character

            // Reset state
            adapt_shift_keycode = 0;
            adapt_shift_timer   = 0;

            return false; // We handled this key, don't process it further
        }

        // Handle punctuation combinations
        uint16_t shifted_keycode = KC_NO;
        
        if (target_keycode == KC_COMM) {
            // ,, = semicolon (shifted comma in Danish layout)
            shifted_keycode = S(KC_COMM);
        } else if (target_keycode == KC_DOT) {
            // ,. = colon (shifted dot in Danish layout)  
            shifted_keycode = S(KC_DOT);
        } else if (target_keycode == KC_NUHS) {
            // ,' = double quote (DQUO in Danish layout)
            shifted_keycode = S(KC_2);
        }
        
        if (shifted_keycode != KC_NO) {
            // Perform the adaptive shift for punctuation:
            tap_code(KC_BSPC);          // Delete the shift leader character (comma)
            tap_code16(shifted_keycode); // Type the shifted punctuation

            // Reset state
            adapt_shift_keycode = 0;
            adapt_shift_timer   = 0;

            return false; // We handled this key, don't process it further
        }
    }

    // If we pressed any other key (not a letter) after the shift leader,
    // reset the state so we don't accidentally trigger it later
    if (stored_basic == ADAPT_SHIFT_KEY) {
        adapt_shift_keycode = 0;
        adapt_shift_timer   = 0;
    }

    return true; // Continue normal processing
}
