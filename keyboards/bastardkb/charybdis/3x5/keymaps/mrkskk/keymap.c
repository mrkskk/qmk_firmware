// clang-format on
// including files
#include QMK_KEYBOARD_H
#include "quantum.h"
// Include features
#ifdef POINTING_DEVICE_ENABLE
#    include "pointing_device_modes.h" // Include trackball/pointer functionality when enabled
#endif

#include "defines.h"           // Custom keyboard definitions
#include "sendstring_danish.h" // Danish language support for sending strings - Has to be here and not in defines.h
#include "os_detection.h"      // Automatically detect the operating system (Windows/Mac)

#if defined(UNIVERSAL_OS_KEYS_ENABLE) || defined(OS_DETECTION_ENABLE)
#    include "features/os_keys.h" // OS-specific key functionality
#endif

#ifdef KEY_OVERRIDE_ENABLE
#    include "features/key_overrides.c" // Key override functionality for context-dependent mappings
#endif

#if (__has_include("features/secrets.h"))
#    include "features/secrets.h" // Personal secrets file (passwords, emails, etc.) if available
#else
const char secrets[][64] = {"test1", "test2", "test3", "test4", "test5"}; // Default placeholder values
#endif

#if defined CAPS_WORD_ENABLE
// For Caps_word_lock - allows typing in ALL CAPS without holding shift
bool caps_word_lock_on;
bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
            // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
            add_weak_mods(MOD_BIT(KC_LSFT)); // Apply shift to next key.
            return true;
        // Keycodes that continue Caps Word, without shifting - allows numbers and certain symbols
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case NUM:
        case UNDSC:
        case MINUS:
            return true;
        default:
            return false; // Deactivate Caps Word on any other key.
    }
}
/*
void caps_word_set_user(bool active) {
    if (active) {
        // Do something when Caps Word activates.
    } else {
        // Do something when Caps Word deactivates.
    }
}
*/
#endif

#if defined(UNIVERSAL_OS_KEYS_ENABLE) || defined(OS_DETECTION_ENABLE)
// Cross-platform keymapping functionality - allows same physical key to send different keycodes on Mac vs Windows

// For tap_os_key definition - redefine the OSKEY macro for use in switch statements
#    undef OSKEY
#    define OSKEY(name, windows, mac)          \
        case name:                             \
            tap_os_key(windows, mac, pressed); \
            break;

// Helper function that sends the appropriate keycode based on the detected operating system
void tap_os_key(uint16_t win_keycode, uint16_t mac_keycode, bool pressed) {
    if (pressed) {
        tap_code16(is_windows() ? win_keycode : mac_keycode); // Send Windows or Mac keycode based on OS
    }
}
#endif

// used to hold last modifier in repeat key code and for example for shifted KC_BSPC = KC_DEL, and other functions
uint8_t last_modifier = 0;
uint8_t mod_state     = 0;
#ifdef REPEAT_ENABLE
// Repeat key functionality - allows repeating the last keypress with a dedicated key
// Used to extract the basic tapping keycode from a dual-role key.
// Example: GET_TAP_KC(MT(MOD_RSFT, KC_E)) == KC_E
#    define GET_TAP_KC(dual_role_key) dual_role_key & 0xFF

// used to hold last keycode in repeat key code
uint16_t last_keycode    = KC_NO; // The last keycode that was pressed (for repeating)
uint16_t pressed_keycode = KC_NO; // Currently pressed keycode (for repeating)

// Process the repeat key functionality
void process_repeat_key(uint16_t keycode, const keyrecord_t *record) {
    if (keycode != REPEAT) {
        // Early return when holding down a pure layer key
        // to retain modifiers - prevents layer keys from being remembered for repeat
        switch (keycode) {
            case QK_DEF_LAYER ... QK_DEF_LAYER_MAX:
            case QK_MOMENTARY ... QK_MOMENTARY_MAX:
            case QK_LAYER_MOD ... QK_LAYER_MOD_MAX:
            case QK_ONE_SHOT_LAYER ... QK_ONE_SHOT_LAYER_MAX:
            case QK_TOGGLE_LAYER ... QK_TOGGLE_LAYER_MAX:
            case QK_TO ... QK_TO_MAX:
            case QK_LAYER_TAP_TOGGLE ... QK_LAYER_TAP_TOGGLE_MAX:
            case QK_MODS ... QK_MODS_MAX:
            case NAV:
                return;
        }
        if (record->event.pressed) {
            last_modifier = get_mods(); // Store current modifiers
            switch (keycode) {
                case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
                case QK_MOD_TAP ... QK_MOD_TAP_MAX:
                    last_keycode = GET_TAP_KC(keycode); // Store the base keycode from dual-function keys
                    break;
                default:
                    last_keycode = keycode; // Store regular keycodes directly
                    break;
            }
        }
    } else { // keycode == REPEAT
        if (record->event.pressed) {
            pressed_keycode = last_keycode;
            register_mods(last_modifier);     // Apply the same modifiers as the original keypress
            register_code16(pressed_keycode); // Send the repeated keycode
            unregister_mods(last_modifier);   // Remove the modifiers immediately to prevent them from affecting subsequent keys
        } else {
            unregister_code16(pressed_keycode); // Release the repeated keycode
        }
    }
}
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Process various feature handlers based on enabled modules
#ifdef REPEAT_ENABLE
    process_repeat_key(keycode, record); // Handle repeat key functionality
#endif
#ifdef SELECT_WORD_ENABLE
    // Custom word selection shortcuts (similar to Ctrl+Shift+Arrow keys)
    if (!process_select_word_right(keycode, record, S_R_WRD)) {
        return false;
    }
    if (!process_select_word_left(keycode, record, S_L_WRD)) {
        return false;
    }
#endif

#ifdef LAYER_LOCK_ENABLE
    if (!process_layer_lock(keycode, record, LLOCK)) {
        return false;
    }
#endif

#ifdef CUSTOM_ONESHOT_ENABLE
    process_nshot_state(keycode, record); // Custom implementation of one-shot modifiers
#endif

#ifdef SWAPPER_ENABLE
    process_swappers(keycode, record); // Custom Alt+Tab implementation
#endif

#ifdef LAYER_MODES_ENABLE
    if (!process_num_word(keycode, record)) { // Num Word mode (similar to Caps Word but for numbers)
        return false;
    }
#endif

#ifdef SENTENCE_CASE_ENABLE
    if (!process_sentence_case(keycode, record)) { // Auto-capitalize first letter of sentences
        return false;
    }
#endif

    const bool pressed = record->event.pressed;
    switch (keycode) {
        case OSS_NAV:
            if (record->tap.count > 0) {
                // Tap: trigger nshot shift
                if (pressed) {
                    register_code16(OS_LSFT);             // Register one-shot shift
                    process_nshot_state(OS_LSFT, record); // Process nshot state                }
                    return false;
                } else {
                    // Hold: activate NAV_MAC layer
                    if (pressed) {
                        layer_on(_NAV_MAC);
                    } else {
                        layer_off(_NAV_MAC);
                    }
                    return false;
                }
            }
            break;
            // Include all keys that change between OS'es - loaded from os_keys.def
#if defined(UNIVERSAL_OS_KEYS_ENABLE) || defined(OS_DETECTION_ENABLE)
#    include "features/os_keys.def" // Pull in OS-specific keycodes from definition file
#endif
            break;
        case TG_OS: // toggle os (win or mac) - manually switch between OS modes
            if (record->event.pressed) {
#ifdef OS_DETECTION_ENABLE
                // Use the toggle_os_manually function for the auto-detection system
                toggle_os_manually();
#else
                // Original manual toggle behavior - directly flip the GUI/Ctrl swap bit
                keymap_config.swap_lctl_lgui = !keymap_config.swap_lctl_lgui;
                eeconfig_update_keymap(keymap_config.raw); // Save to EEPROM
#endif

                clear_keyboard(); // clear to prevent stuck keys
                // Visual feedback of current OS
                send_string((is_mac()) ? "Mac" : "Win");
                send_string(SS_DELAY(800)); // Wait 800ms for user to see message

                // Delete the feedback text
                for (int i = 0; i < 3; i++) { // "Mac" or "Win" = 3 chars
                    tap_code(KC_BSPC);
                }
            }
            break;
        case OS_RESET:
            if (record->event.pressed) {
#ifdef OS_DETECTION_ENABLE
                // Reset the OS detection system to default state
                reset_to_auto_detection();
                clear_keyboard(); // clear to prevent stuck keys
                // Visual feedback of reset state
                send_string("OS DetectionReset");
                send_string(SS_DELAY(800)); // Wait 800ms for user to see message

                // Delete the feedback text
                for (int i = 0; i < 17; i++) { // "OS DetectionReset" = 17 chars (longest message)
                    tap_code(KC_BSPC);
                }
#endif
            }
            break;
        case OS_DEBUG:
            if (record->event.pressed) {
                // Console disabled - OS_DEBUG key has no function
                // You can still test OS detection with TG_OS and OS-specific keys
            }
            break;
        case KC_SECRET_1 ... KC_SECRET_3:
            if (!record->event.pressed) {
                send_string(secrets[keycode - KC_SECRET_1]);
            }
            break;
        case LOGIN: // Automatically enter username and password
            if (record->event.pressed) {
                send_string(secrets[0]); // Username
                send_string(SS_DELAY(30));
                tap_code(KC_TAB);
                send_string(SS_DELAY(30));
                send_string(secrets[1]); // Password
                send_string(SS_DELAY(30));
            }
            break;
        case PERS_MAIL: // Type personal email address
            if (record->event.pressed) {
                send_string(secrets[4]);
                send_string(SS_DELAY(5));
                // Type @ symbol with correct OS-specific keycode
                if (is_mac()) {
                    tap_code16(A(QUOT));
                } else {
                    tap_code16(ALGR(KC_2));
                }
                send_string(secrets[5]);
            }
            break;
        case WORK_MAIL: // Type work email address
            if (record->event.pressed) {
                send_string(secrets[2]);
                send_string(SS_DELAY(5));
                // Type @ symbol with correct OS-specific keycode
                if (is_mac()) {
                    tap_code16(A(QUOT));
                } else {
                    tap_code16(ALGR(KC_2));
                }
                send_string(secrets[3]);
            }
            break;
        case TILDE_ND:
            if (record->event.pressed) {
                send_string("~"); // Send ~ symbol with correct OS-specific keycode
            }
            break;
        case MEH_CARET: // Intercept the actual mod-tap keycode
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    SEND_STRING("^");
                }
                return false;
            }
            return true; // Let QMK handle hold behavior

        case HYPR_USD: // Intercept the actual mod-tap keycode
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    tap_os_key(ALGR(KC_4), KC_GRAVE, true); // Send $ symbol with correct OS-specific keycode
                }
                return false;
            }
            return true;
#ifdef LAYER_MODES_ENABLE
        case NUM: // Activate number layer/mode
            process_num_word_activation(record);
            return false;
#endif
#ifdef SENTENCE_CASE_ENABLE
        case TG_SENT: // Toggle sentence case mode
            if (pressed) {
                sentence_case_toggle();

                // Visual feedback showing current state
                clear_keyboard(); // Clear to prevent stuck keys
                if (is_sentence_case_on()) {
                    send_string("Sentence Case ON");
                } else {
                    send_string("Sentence Case OFF");
                }
                send_string(SS_DELAY(800)); // Wait 800ms for user to see message

                // Delete the feedback text
                for (int i = 0; i < 16; i++) { // "Sentence Case OFF" = 16 chars (longest message)
                    tap_code(KC_BSPC);
                }
            }
            break;
#endif
        case TO_BASE: // Return to base layer and clear all modifiers
            if (pressed) {
                layer_clear();
                clear_mods();
            }
            break;
    }
    return true;
}

#ifdef POINTING_DEVICE_ENABLE
#    ifndef POINTING_DEVICE_MODES_ENABLE
// Layer state management for pointing device
layer_state_t layer_state_set_user(layer_state_t state) {
    //    state = update_tri_layer_state(state, _NAV_MAC, _MOUSE, _FNKEYS);
    //   state = update_tri_layer_state(state, _NAV_WIN, _NUM, _FNKEYS2);
    charybdis_set_pointer_dragscroll_enabled(layer_state_cmp(state, _AUTO_DRAGSCLL));
    return state;
}
#    endif // POINTING_DEVICE_MODES_ENABLE

#    ifdef POINTING_DEVICE_MODES_ENABLE
// assuming enum and Layout for layers are already defined
layer_state_t layer_state_set_user(layer_state_t state) {
    // reset mode id to toggle_id
    pointing_mode_reset();
    switch (get_highest_layer(state)) {
        case _NAV_MAC: // Navigation layer - use caret pointing mode
            set_pointing_mode_id(PM_CARET);
            break;
        case _NUMROW:
        case _NUM: // Number layers - use drag pointing mode
            set_pointing_mode_id(PM_DRAG);
            break;
        case _FNKEYS: // Media control layer - use volume control mode
            set_pointing_mode_id(PM_VOL);
            break;
    }
    return state;
}
#    endif // POINTING_DEVICE_MODES_ENABLE
#endif     // POINTING_DEVICE_ENABLE

// Combo key functionality (press multiple keys simultaneously for an action)
#ifdef COMBO_ENABLE
#    include "g/keymap_combo.h"

uint16_t get_combo_term(uint16_t index, combo_t *combo) {
    // or with combo index, i.e. its name from enum.
    switch (index) {
        default:
            return COMBO_TERM;
    }
    return COMBO_TERM;
}
/*
bool get_combo_must_tap(uint16_t index, combo_t *combo) {
    // If you want all combos to be tap-only, just uncomment the next line
    return true;

    // If you want *all* combos, that have Mod-Tap/Layer-Tap/Momentary keys in its chord, to be tap-only, this is for you:
    uint16_t key;
    uint8_t idx = 0;
    while ((key = pgm_read_word(&combo->keys[idx])) != COMBO_END) {
        switch (key) {
            case QK_MOD_TAP...QK_MOD_TAP_MAX:
            case QK_LAYER_TAP...QK_LAYER_TAP_MAX:
            case QK_MOMENTARY...QK_MOMENTARY_MAX:
                return true;
        }
        idx += 1;
    }
    return false;
}


bool get_combo_must_press_in_order(uint16_t combo_index, combo_t *combo) {
    switch (combo_index) {
        default:
            return true;
    }
}
*/
#endif

// Automatic mouse layer functionality
#ifdef POINTING_DEVICE_AUTO_MOUSE_ENABLE
void pointing_device_init_user(void) {
    set_auto_mouse_layer(_MOUSE); // only required if AUTO_MOUSE_DEFAULT_LAYER is not set to index of <mouse_layer>
    set_auto_mouse_enable(true);  // always required before the auto mouse feature will work
}

// Treat these keys as if they are mouse keys (resets the timer)
bool is_mouse_record_kb(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SNIPING: // Consider precision/sniping mode as mouse activity
            return true;
        case TO_BASE:
            set_auto_mouse_enable(false); // Disable auto mouse
            layer_on(_BASE);              // Enable base layer
            layer_clear();                // Clear all layers
            clear_mods();                 // Clear all modifiers
            set_auto_mouse_enable(true);  // Re-enable auto mouse with fresh timer
            return false;                 // Don't count TO_BASE as a mouse action
        default:
            return false;
    }
    return is_mouse_record_user(keycode, record);
}

#endif // POINTING_DEVICE_AUTO_MOUSE_ENABLE
       // clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LAYOUT(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
       KC_W,    KC_C,    KC_G,    KC_M,    KC_J,      QUOT,    KC_U,    KC_K,    DK_OE,     DK_AA,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       HM_LSFT, HM_LALT, HM_LCTL, HM_LGUI, KC_F,      KC_Y,    HM_RGUI, HM_RCTL, HM_RALT,   HM_RSFT,
  // ├─────────────────────────────────────────────┤ ├────────────────────────────────────────────-┤
       KC_V,    MEH_B,   HYP_L,    CAG_D,  KC_X,      KC_Z,    CAG_P,   HYP_COM,  MEH_DOT,  DK_AE,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         CW_TOGG,  NUM_SPC, MO(_NAV_MAC), FN_BSPC,  NUM_N
  //                   ╰───────────────────────────╯ ╰-──────────────────╯
  ),

  [_NAV_MAC] = LAYOUT(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
       UNDO,    COPY,     CBOARD,   PASTE,   REDO,    KC_PGUP, S_L_WRD, KC_UP,   S_R_WRD, KC_END,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       KC_LSFT, KC_LALT,  KC_LCTL,  KC_LGUI, OS_RALT,  KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_HOME,
  // ├─────────────────────────────────────────────┤ ├-────────────────────────────────────────────┤
       TG_MS,   OS_MEH,   OS_HYPR,  OS_CAG, CW_TOGG,   QUIT,    KC_TAB,  KC_ENT,  KC_ESC,  _______,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         TO_BASE,  TO_BASE, TO_BASE,   FN_BSPC, KC_DEL
  //                   ╰───────────────────────────╯ ╰──────────────────╯
  ),

[_MOUSE] = LAYOUT(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
       TO_BASE, TO_BASE, KC_WH_U, TO_BASE, TO_BASE,  TO_BASE, TO_BASE, KC_MS_U, TO_BASE, TO_BASE,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       TO_BASE, KC_WH_L, KC_WH_D, KC_WH_L, TO_BASE,  TO_BASE, KC_MS_L, KC_MS_D, KC_MS_R, TO_BASE,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       TO_BASE, KC_BTN2, PRE_MO,  KC_BTN1, TO_BASE,  TO_BASE, TO_BASE, TO_BASE, TO_BASE, TO_BASE,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         TO_BASE, TO_BASE, TO_BASE, TO_BASE, TO_BASE
  //                   ╰───────────────────────────╯ ╰──────────────────╯
  ),

[_NUMROW] = LAYOUT(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
       HAT,     DIAE,   GRAVE,   ACUTE,    TILDE,     DQUO,   LABK,    MINUS,   PLUS,   RABK,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       HOME_7,  HOME_5, HOME_1,  HOME_3,    KC_9,     KC_0,   HOME_4,  HOME_2,  HOME_6, HOME_8,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       TG(_NUM), MEH_CARET, HYPR_USD, CAG_9,   PIPE,     PARA,    CAG_0,   HYP_COM, MEH_DOT, KC_PDOT,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         TO_BASE, TO_BASE, TO_BASE,   KC_BSPC, KC_0
  //                   ╰───────────────────────────╯ ╰──────────────────╯
  ),

[_NUM] = LAYOUT(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
       TO_BASE, KC_7,    KC_8,    KC_9,  TO_BASE,     TO_BASE, KC_7,    KC_8,     KC_9,  TO_BASE,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       SFT_0,   ALT_4,   CTL_5,  GUI_6,  TO_BASE,     TO_BASE, GUI_4,  CTL_5,   ALT_6, KC_LSFT,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       TO_BASE, MEH_1,   HYPR_2,  CAG_3, TO_BASE,     TO_BASE, CAG_1,  HYPR_2,   MEH_3,  KC_RALT,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                        TO_BASE,  KC_0,  TO_BASE,     KC_BSPC, KC_0
  //                   ╰───────────────────────────╯ ╰──────────────────╯
  ),

[_FNKEYS] = LAYOUT(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
       CA_DEL,   KC_F7,   KC_F8,   KC_F9,  KC_F12,    TG_SENT,  KC_MPRV,  KC_MPLY,  KC_MNXT, KC_INS,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       SCRSHOT,  KC_F4,   KC_F5,   KC_F6,  KC_F11,    TG_OS,  KC_LGUI,  KC_LCTL,  KC_LALT, KC_LSFT,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       _______,    KC_F1,   KC_F2,    KC_F3,  KC_F10, OS_DEBUG,  KC_BRID,  KC_BRIU,  KC_ASST, _______,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         TO_BASE, TO_BASE, TO_BASE,    KC_VOLU,  KC_VOLD
  //                   ╰───────────────────────────╯ ╰──────────────────╯
  ),
/*
  [TEMPLATE] = LAYOUT(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
       _______, _______, _______, _______, _______,    DPI_RMOD, _______, _______, _______, _______,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       _______, _______, _______, _______, _______,    DPI_MOD, _______, _______, _______, _______,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         _______, _______, _______,    _______, _______
  //                   ╰───────────────────────────╯ ╰──────────────────╯
  ),
*/
};
       // clang-format on

// reset CPI after wake
/*void suspend_wakeup_init_user(void) {
    keyboard_post_init_kb();
}*/

#ifdef SENTENCE_CASE_ENABLE
void matrix_scan_user(void) {
#    ifdef OS_DETECTION_ENABLE
    initialize_os_detection();
#    endif
    sentence_case_task();
    // Other tasks...
}
#else
void matrix_scan_user(void) {
#    ifdef OS_DETECTION_ENABLE
    initialize_os_detection();
#    endif
    // Other tasks...
}
#endif

void keyboard_post_init_user(void) {
    // Console disabled - no debug output
}
