// ======== ARCHIVED FROM keymap.c ========
#if defined(CUSTOM_ONESHOT_ENABLE)

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
#endif
// ======== ARCHIVED FROM defines.h ========
#define EMOJI LGUI(LCTL(KC_SPC)) // Emoji keyboard shortcut
#define BITWRDN G(S(KC_Y))       // Bitwarden shortcut
    /**
     * Archive of code snippets from mrkskk keymap
     * This file contains code that has been removed from active files but kept for future reference.
     * Last updated: May 27, 2025
     */

    // ======== ARCHIVED FROM KEYMAP.C ========

    /*
    case QUOT: {
                // Smart Quote - becomes double quote when Shift is held
                static bool dquot_registered;
                if (record->event.pressed) {
                    if (last_modifier & MOD_MASK_SHIFT) {
                        unregister_code(KC_LSFT);
                        unregister_code(KC_RSFT);
                        register_code16(KC_DQUO);
                        dquot_registered = true;
                        set_mods(last_modifier);
                        return false;
                    }
                } else { // on release
                    if (dquot_registered) {
                        unregister_code16(KC_DQUO);
                        dquot_registered = false;
                        return false;
                    }
                }
                // Let QMK process the QUOT keycode as usual outside of shift
                return true;
            } break;
    */

    // Caps word functions
    /*
    void caps_word_set_user(bool active) {
        if (active) {
            // Do something when Caps Word activates.
        } else {
            // Do something when Caps Word deactivates.
        }
    }
    */

    // Sign macro
    /*
    case SIGN:
        if (record->event.pressed) {
        tap_code16(A(KC_A));
        tap_code16(A(KC_S));
        tap_code16(A(KC_O));
        }
    */

    // R pipe and R definition macros
    /*
    case R_PIPE:
        if (record->event.pressed) {
            tap_code16(AMPR);
            tap_code(LABK);
            tap_code16(AMPR);
        }
        break;
    case R_DEF:
        if (record->event.pressed) {
            tap_code(LABK);
            tap_code(MINUS);
        }
        break;
    */

    // Code block macro
    /*
    case C_BLCK:
        if (record->event.pressed) {
            SEND_STRING("```c" SS_LSFT("\n\n") "``` " SS_TAP(X_UP));
        }
        break;
    */

    // Firmware flashing macro
    /*
    case FLASH:
        if (record->event.pressed) {
            SEND_STRING_DELAY("qmk flash -kb " QMK_KEYBOARD " -km " QMK_KEYMAP SS_TAP(X_ENTER), TAP_CODE_DELAY);
            reset_keyboard();
        }
    */

    // NUM layer handling logic
    /*
    case NUM:
        if (pressed) {
            if (is_mac()) {
                layer_on(_NUM);
            } else {
                layer_on(_NUM_WIN);
            }
        } else {
                layer_off(_NUM);
                layer_off(_NUM_WIN);
            }
        }
        break;
    */

    // Paste with formatting options
    /*
    case PASTE2:
        if (record->tap.count && record->event.pressed) { // tap action
            tap_code16(PASTE);
        } else if (record->event.pressed) { // hold action
            tap_code16(PASTE_UNFORMAT);
        }
        return false;
        break;
    */

    // Navigation layer handling
    /*
    case NAV:
        if (pressed) {
            if (is_mac()) {
                layer_on(_NAV_MAC);
            } else {
                layer_on(_NAV_WIN);
            }
        } else {
            layer_off(_NAV_MAC);
            layer_off(_NAV_WIN);
        }
        break;
    */

    // Navigation with Space key
    /*
    case NAV_SPC:
        if (record->event.pressed) {
            if (record->tap.count > 0) {
                if (record->tap.interrupted) {
                    record->tap.count = 0;
                    register_code(KC_SPC);
                }
            } else {
                if (is_mac()) {
                    layer_on(_NAV_MAC);
                } else if (is_windows()) {
                    layer_on(_NAV_WIN);
                }
            }
        } else {
            if (record->tap.count > 0) {
                unregister_code(KC_SPC);
            } else {
                if (is_mac()) {
                    layer_off(_NAV_MAC);
                } else if (is_windows()) {
                    layer_off(_NAV_WIN);
                }
            }
        }
        break;
    */

    // Drag tab functionality
    /*
    case DRAG_TAB:                   // :
        if (record->tap.count > 0) { // Key is being tapped.
            if (record->event.pressed) {
                tap_code16(G(DIAE));
            }
        } else { // Key is being held.
            charybdis_set_pointer_dragscroll_enabled(record->event.pressed);
        }
        return false; // Skip default handling.
    */

    // Quick typing "qu"/"Qu"
    /*
    case KC_QU:
        if (record->tap.count && record->event.pressed) { // tap action
            send_string("qu");
        } else if (record->event.pressed) { // hold action
            send_string("Qu");
        }
        return false;
    */

    // Layer state management functions
    /*
    void suspend_wakeup_init_user(void) {
        keyboard_post_init_kb();
    }
    */

    /*
    void matrix_scan_user(void) {
        sentence_case_task();
        // Other tasks...
    }
    */

    // ======== ARCHIVED FROM COMBO.C ========

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
    */

    // Template layer for future use
    /*
    [TEMPLATE] = LAYOUT(
    // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
       _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______,
    // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______,
    // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______,
    // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         _______, _______, _______,    _______, _______
    //                   ╰───────────────────────────╯ ╰──────────────────╯
    ),
    */
