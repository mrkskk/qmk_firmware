// clang-format on
// including files
#include QMK_KEYBOARD_H
#include "quantum.h"
// Include features
#ifdef POINTING_DEVICE_ENABLE
#    include "pointing_device_modes.h"
#endif

#include "defines.h"
#include "sendstring_danish.h" // Has to be here and not in defines.h

#ifdef KEY_OVERRIDE_ENABLE
#    include "features/key_overrides.c"
#endif

#if (__has_include("features/secrets.h"))
#    include "features/secrets.h"
#else
const char secrets[][64] = {"test1", "test2", "test3", "test4", "test5"};
#endif

#if defined CAPS_WORD_ENABLE
// For Caps_word_lock
bool caps_word_lock_on;
bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
            // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
            add_weak_mods(MOD_BIT(KC_LSFT)); // Apply shift to next key.
            return true;
        // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:

        case NUM:

        case UNDSC:
        case MINUS:
            return true;
        default:
            return false; // Deactivate Caps Word.
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

#ifdef UNIVERSAL_OS_KEYS_ENABLE

// For tap_os_key def
#    undef OSKEY
#    define OSKEY(name, windows, mac)          \
        case name:                             \
            tap_os_key(windows, mac, pressed); \
            break;
// call this function for tapping a keycode which differs on on the OS'es
void tap_os_key(uint16_t win_keycode, uint16_t mac_keycode, bool pressed) {
    if (pressed) {
        tap_code16(is_windows() ? win_keycode : mac_keycode);
    }
}
#endif

// used to hold last modifier in repeat key code and for shifted KC_BSPC = KC_DEL
uint8_t last_modifier = 0;
uint8_t mod_state     = 0;
#ifdef REPEAT_ENABLE
// Used to extract the basic tapping keycode from a dual-role key.
// Example: GET_TAP_KC(MT(MOD_RSFT, KC_E)) == KC_E
#    define GET_TAP_KC(dual_role_key) dual_role_key & 0xFF

// used to hold last keycode  in repeat key code
uint16_t last_keycode    = KC_NO;
uint16_t pressed_keycode = KC_NO;

void process_repeat_key(uint16_t keycode, const keyrecord_t *record) {
    if (keycode != REPEAT) {
        // Early return when holding down a pure layer key
        // to retain modifiers
        switch (keycode) {
            case QK_DEF_LAYER ... QK_DEF_LAYER_MAX:
            case QK_MOMENTARY ... QK_MOMENTARY_MAX:
            case QK_LAYER_MOD ... QK_LAYER_MOD_MAX:
            case QK_ONE_SHOT_LAYER ... QK_ONE_SHOT_LAYER_MAX:
            case QK_TOGGLE_LAYER ... QK_TOGGLE_LAYER_MAX:
            case QK_TO ... QK_TO_MAX:
            case QK_LAYER_TAP_TOGGLE ... QK_LAYER_TAP_TOGGLE_MAX:
            case QK_MODS ... QK_MODS_MAX:

                return;
        }
        if (record->event.pressed) {
            last_modifier = get_mods();
            switch (keycode) {
                case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
                case QK_MOD_TAP ... QK_MOD_TAP_MAX:
                    last_keycode = GET_TAP_KC(keycode);
                    break;
                default:
                    last_keycode = keycode;
                    break;
            }
        }
    } else { // keycode == REPEAT
        if (record->event.pressed) {
            pressed_keycode = last_keycode;
            register_mods(last_modifier);
            register_code16(pressed_keycode);
            unregister_mods(last_modifier);
        } else {
            unregister_code16(pressed_keycode);
        }
    }
}
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef REPEAT_ENABLE
    process_repeat_key(keycode, record);
#endif
#ifdef SELECT_WORD_ENABLE
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
    process_nshot_state(keycode, record);
#endif

#ifdef SWAPPER_ENABLE
    process_swappers(keycode, record);
#endif

#ifdef LAYER_MODES_ENABLE
    if (!process_num_word(keycode, record)) {
        return false;
    }
#endif

#ifdef SENTENCE_CASE_ENABLE
    if (!process_sentence_case(keycode, record)) {
        return false;
    }
#endif

    const bool pressed = record->event.pressed;
    switch (keycode) {
// include all keys that change between OS'es
#ifdef UNIVERSAL_OS_KEYS_ENABLE
#    include "features/os_keys.def"
#endif
        break;
        case KC_BSPC: {
            // Initialize a boolean variable that keeps track
            // of the delete key status: registered or not?
            static bool delkey_registered;
            if (record->event.pressed) {
                // Detect the activation of either shift keys
                if (last_modifier & MOD_MASK_SHIFT) {
                    // First temporarily canceling both shifts so that
                    // shift isn't applied to the KC_DEL keycode
                    unregister_code(KC_LSFT);
                    unregister_code(KC_RSFT);
                    register_code(KC_DEL);
                    // Update the boolean variable to reflect the status of KC_DEL
                    delkey_registered = true;
                    // Reapplying modifier state so that the held shift key(s)
                    // still work even after having tapped the Backspace/Delete key.
                    set_mods(last_modifier);
                    return false;
                }
            } else { // on release of KC_BSPC
                // In case KC_DEL is still being sent even after the release of KC_BSPC
                if (delkey_registered) {
                    unregister_code(KC_DEL);
                    delkey_registered = false;
                    return false;
                }
            }
            // Let QMK process the KC_BSPC keycode as usual outside of shift
            return true;
        } break;
        case QUOT: {
            static bool dquot_registered;
            if (record->event.pressed) {
                if (last_modifier & MOD_MASK_SHIFT) {
                    unregister_code(KC_LSFT);
                    unregister_code(KC_RSFT);
                    register_code16(DQUO);
                    dquot_registered = true;
                    set_mods(last_modifier);
                    return false;
                }
            } else { // on release
                if (dquot_registered) {
                    unregister_code16(DQUO);
                    dquot_registered = false;
                    return false;
                }
            }
            // Let QMK process the QUOT keycode as usual outside of shift
            return true;
        } break;
        case TG_OS: // toggle os (win or mac)
            if (record->event.pressed) {
                keymap_config.swap_lctl_lgui = !keymap_config.swap_lctl_lgui;
                eeconfig_update_keymap(keymap_config.raw);
                clear_keyboard(); // clear to prevent stuck keys
                send_string((is_mac()) ? "Mac" : "Win");
                send_string(SS_DELAY(300));
                tap_code(KC_BSPC);
                tap_code(KC_BSPC);
                tap_code(KC_BSPC);
                // return true;
            }
            break;
            /*
        case SIGN:
            if (record->event.pressed) {
            tap_code16(A(KC_A));
            tap_code16(A(KC_S));
            tap_code16(A(KC_O));
            }
            */
            break;
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
        case KC_SECRET_1 ... KC_SECRET_3:
            if (!record->event.pressed) {
                send_string(secrets[keycode - KC_SECRET_1]);
                tap_code(KC_ENT);
            }
            break;
        case LOGIN:
            if (record->event.pressed) {
                send_string(secrets[0]);
                send_string(SS_DELAY(30));
                tap_code(KC_TAB);
                send_string(SS_DELAY(30));
                send_string(secrets[1]);
                send_string(SS_DELAY(30));
                tap_code(KC_ENT);
            }
            break;
        case PERS_MAIL:
            if (record->event.pressed) {
                send_string(secrets[4]);
                send_string(SS_DELAY(5));
                if (is_mac()) {
                    tap_code16(A(QUOT));
                } else {
                    tap_code16(ALGR(KC_2));
                }
                send_string(secrets[5]);
            }
            break;
        case WORK_MAIL:
            if (record->event.pressed) {
                send_string(secrets[2]);
                send_string(SS_DELAY(5));
                if (is_mac()) {
                    tap_code16(A(QUOT));
                } else {
                    tap_code16(ALGR(KC_2));
                }
                send_string(secrets[3]);
            }
            break;

        case C_BLCK:
            if (record->event.pressed) {
                SEND_STRING("```c" SS_LSFT("\n\n") "``` " SS_TAP(X_UP));
            }
            break;
            /*case FLASH:
                if (record->event.pressed) {
                    SEND_STRING_DELAY("qmk flash -kb " QMK_KEYBOARD " -km " QMK_KEYMAP SS_TAP(X_ENTER), TAP_CODE_DELAY);
                    reset_keyboard();
                  }
            */
            break;
#ifdef LAYER_MODES_ENABLE
        case NUM:
            process_num_word_activation(record);
            return false;
#endif
#ifndef LAYER_MODES_ENABLE

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
#endif
#ifdef SENTENCE_CASE_ENABLE
        case TG_SENT:
            if (pressed) {
                sentence_case_toggle();
            }
            break;
#endif
        case MAC_MENU:
            if (pressed) {
                tap_code16(MENU);
                tap_code(KC_DOWN);
            }
            break;
        case YT_SEARCH:
            if (pressed) {
                tap_code16(C(KC_SPC)); // SWAP LANGUAGE TO ANSI U.S.
                send_string(SS_DELAY(10));
                tap_code16(MINUS); // TAB SLSH ON ANSI. Thats on the '-' key
                send_string(SS_DELAY(10));
                tap_code16(C(KC_SPC)); // SWAP BACK TO ISO Language settings
            }
            break;
        case DBLE_BTN1:
            if (pressed) {
                tap_code(KC_BTN1);
                tap_code(KC_BTN1);
            }
            break;
        case TO_BASE:
            if (pressed) {
                layer_clear();
            }
            break;
        case PASTE2:
            if (record->tap.count && record->event.pressed) { // tap action
                tap_code16(PASTE);
            } else if (record->event.pressed) { // hold action
                tap_code16(PASTE_UNFORMAT);
            }
            return false;
            break;
            /*
           break;

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
        /*case DRAG_TAB:                   // :
            if (record->tap.count > 0) { // Key is being tapped.
                if (record->event.pressed) {
                    tap_code16(G(DIAE));
                }
            } else { // Key is being held.
                charybdis_set_pointer_dragscroll_enabled(record->event.pressed);
            }
            return false; // Skip default handling.
    */
        case KC_QU:
            if (record->tap.count && record->event.pressed) { // tap action
                send_string("qu");
            } else if (record->event.pressed) { // hold action
                send_string("Qu");
            }
            return false;
    }
    return true;
}

// clang-format off

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_ALTN] = LAYOUT_ortho_5x12(
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  PLUS,
  KC_Q,    KC_W,    KC_C,    KC_G,    KC_M,    KC_J,    QUOT,    KC_U,    KC_K,    DK_OE,   DK_AA, SLSH,
  KC_LSFT, KC_R,    KC_S,    KC_T,    KC_H,    KC_F,    KC_Y,    KC_I,    KC_E,    KC_O,    KC_A,  ASTR,
  FNLAYER, KC_V,    KC_B,    KC_L,    KC_D,    KC_X,    KC_Z,    KC_P,    KC_COMM, KC_DOT,  DK_AE, MINUS,
  _______, _______, FNLAYER, NAV,     KC_SPC,  KC_SPC,  KC_BSPC, KC_N,     KC_RSFT, _______, _______, _______
),

[_NAV_MAC] = LAYOUT_ortho_5x12(
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, UNDO,    COPY,    CBOARD,  PASTE,   REDO,    KC_PGUP,  KC_HOME, KC_UP,   KC_END,  CANCEL, _______,
  _______, OS_LSFT, OS_LCTL, OS_LALT, OS_LGUI, FIND,    KC_PGDN,  KC_LEFT, KC_DOWN, KC_RGHT, KC_ENT,  _______,
  _______, ALFRED,  OF_KEY,  OS_HYPR, HMR_KEY, REPLACE, QUIT,     KC_TAB,  HR_APP,  KC_ESC,  REPEAT, _______,
  _______, _______, _______, _______, _______, _______, KC_BSPC,  KC_DEL, _______, _______, _______, _______
),

[_FNKEYS] = LAYOUT_ortho_5x12(
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
  CA_DEL, _______, _______, _______, _______, _______, _______, WORK_MAIL, PERS_MAIL, _______, _______, TG_OS,
  SCRSHOT, KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, _______, _______, _______, _______, _______, _______, _______,
  KC_ESC, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______, _______, SECRET_1, LOGIN,     SECRET_2, _______, _______
)

};