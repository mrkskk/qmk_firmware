// clang-format on
// including files
#include QMK_KEYBOARD_H
#include "quantum.h"
// Include features
#include "pointing_device_modes.h"

#include "defines.h"
#include "sendstring_danish.h" // Has too be here and not in defines.h

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
            case NAV:
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
        /*case BV:
            if (record->event.pressed) {
                send_string("BV ");
            } else {
                caps_word_toggle();
            }
            break;*/
        case ACUTE_E:
            if (record->event.pressed) {
                tap_code16(ACUTE);
                register_code(KC_E);
            } else {
                unregister_code(KC_E);
            }
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
            /*
        case C_BLCK:
            if (record->event.pressed) {
                SEND_STRING("```c" SS_LSFT("\n\n") "``` " SS_TAP(X_UP));
            }
            break;
            */
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
        case DRAG_TAB:                   // DRAG_TAB:
            if (record->tap.count > 0) { // Key is being tapped.
                if (record->event.pressed) {
                    tap_code(KC_TAB);
                }
            } else { // Key is being held.
                charybdis_set_pointer_dragscroll_enabled(record->event.pressed);
            }
            return false; // Skip default handling.
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

#ifdef POINTING_DEVICE_ENABLE

#    ifndef POINTING_DEVICE_MODES_ENABLE
layer_state_t layer_state_set_user(layer_state_t state) {
    // state = update_tri_layer_state(state, _NAV_MAC, _NUM, _FNKEYS2);
    // state = update_tri_layer_state(state, _NAV_WIN, _NUM, _FNKEYS2);
    charybdis_set_pointer_dragscroll_enabled(layer_state_cmp(state, _AUTO_DRAGSCLL));
    return state;
}
#    endif

#    ifdef POINTING_DEVICE_MODES_ENABLE
layer_state_t layer_state_set_keymap(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case _AUTO_CARET:
            set_pointing_mode_id(PM_CARET);
        case _AUTO_DRAGSCLL:
            set_pointing_mode_id(PM_DRAG);
        default:
            if (get_toggled_pointing_mode_id() != get_pointing_mode_id()) {
                set_pointing_mode_id(get_toggled_pointing_mode_id());
            }
            break;
    }
    return state;
}
#    endif
#endif // POINTING_DEVICE_ENABLE

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

#ifdef POINTING_DEVICE_AUTO_MOUSE_ENABLE
void pointing_device_init_user(void) {
    set_auto_mouse_layer(_AUTO_MOUSE); // only required if AUTO_MOUSE_DEFAULT_LAYER is not set to index of <mouse_layer>
    set_auto_mouse_enable(true);       // always required before the auto mouse feature will work
}

// Treat these keys as if they are mouse keys (resets the timer)
bool is_mouse_record_kb(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SNIPING:
            return true;
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
       KC_W,    KC_C,    KC_G,    KC_M,    KC_J,      QUOT,    KC_U,   KC_K,     DK_OE,   DK_AA,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       KC_R,    KC_S,    KC_T,    KC_H,    KC_F,      KC_Y,    KC_I,   KC_E,     KC_O,    KC_A,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       KC_V,    KC_B,    DRAG_L,  KC_D,    KC_X,      KC_Z,    KC_P,   KC_COMM,  KC_DOT,  DK_AE,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         NUM,     SFT_SPC, NAV,       KC_BSPC, FN_N 
  //                   ╰───────────────────────────╯ ╰──────────────────╯
  ), 

[_NAV_MAC] = LAYOUT(
//  FOR MODS AND NAVIGATION. ALSO FOR WINDOW MANAGEMENT WITH HYPER KEY
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
       UNDO,    COPY,    CBOARD,   PASTE,   REDO,     CLOSE,   KC_HOME, KC_UP,   KC_END,   KC_ESC,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       OS_LSFT, OS_LCTL, OS_LALT,  OS_LGUI, KC_HYPR,  QUIT,     KC_LEFT, KC_DOWN, KC_RGHT,  KC_ENT,
  // ├─────────────────────────────────────────────┤ ├-────────────────────────────────────────────┤
       ALFRED,  SW_REV,  SW_TAB,   SW_MAC,  FIND,     REPLACE,  KC_BTN1, REPEAT,  KC_BTN2,  KC_TAB,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         _______,  _______, _______,  KC_BSPC,  KC_DEL  
  //                   ╰───────────────────────────╯ ╰──────────────────╯ 
  ),

[_NAV_WIN] = LAYOUT(
// FOR MODS AND NAVIGATION. ALSO FOR WINDOW MANAGEMENT WITH HYPER KEY
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
       UNDO,    COPY,    CBOARD,  PASTE,   REDO,      CLOSE,   KC_HOME, KC_UP,   KC_END,  KC_ESC,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       OS_LSFT, OS_LGUI, OS_LALT, OS_LCTL, KC_HYPR,   QUIT,    KC_LEFT, KC_DOWN, KC_RGHT, KC_ENT,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       SEARCH,  SW_REV,  SW_TAB,  SW_WIN,  FIND,      REPLACE, KC_BTN1, REPEAT,  KC_BTN2, KC_TAB,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         _______,  _______, _______,  KC_BSPC, KC_DEL
  //                   ╰───────────────────────────╯ ╰──────────────────╯ 
  ),

[_NUM] = LAYOUT(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
       HAT,     DIAE,   GRAVE,   ACUTE,    TILDE,     ASTR,    KC_7,   KC_8,    KC_9,  PLUS,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       KC_LSFT, KC_LCTL, KC_LALT, KC_LGUI, LABK,      SLSH,    KC_4,   KC_5,    KC_6,  EQL,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       USD,     PIPE,   KC_COMM,  KC_DOT,    RABK,      PERC,    KC_1,   KC_2,    KC_3,  MINUS,  
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                        _______,   _______, _______,  KC_BSPC, KC_0
  //                   ╰───────────────────────────╯ ╰──────────────────╯ 
  ), 

[_FNKEYS] = LAYOUT(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
       CA_DEL,   KC_F7,   KC_F8,   KC_F9,  KC_F12,     SW_LANG,  WORK_MAIL, PERS_MAIL, _______, KC_ESC,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       SCRSHOT,  KC_F4,   KC_F5,   KC_F6,  KC_F11,     DPI_MOD,  KC_LGUI,   KC_LALT,   KC_LCTL, KC_LSFT,  
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       _______,  KC_F1,   KC_F2,   KC_F3,  KC_F10,     TG_OS,    SECRET_1,  LOGIN,     SECRET_2, _______,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         _______, _______, _______,   _______,  _______  
  //                   ╰───────────────────────────╯ ╰──────────────────╯
  ),

[_AUTO_DRAGSCLL] = LAYOUT(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
       _______, _______, _______, _______, _______,    KC_PGUP, KC_HOME, KC_WH_U, KC_END, _______,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       _______, _______, _______, _______, _______,    KC_PGDN, KC_WH_L, KC_WH_D, KC_WH_R, _______,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         _______, _______, _______,    _______, _______
  //                   ╰───────────────────────────╯ ╰──────────────────╯ 
  ),
/*
[_AUTO_CARET] = LAYOUT(
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
  [_AUTO_MOUSE] = LAYOUT(
  // ╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
       _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______,
  // ├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
       SNIPING, KC_BTN2, _______, KC_BTN1, _______,    _______, _______, _______, _______, _______,
  // ╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                         _______, _______, _______,    _______, _______
  //                   ╰───────────────────────────╯ ╰──────────────────╯ 
  ),

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
};
// clang-format on

// reset CPI after wake
/*void suspend_wakeup_init_user(void) {
    keyboard_post_init_kb();
}*/