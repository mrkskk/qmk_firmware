// clang format on
#include "mrkskk.h"
#include "window_tab.h"

#if (__has_include("secrets.h") && !defined(NO_SECRETS))
#    include "secrets.h"
#else
// If the secret.h file is ever lost, simply create it again with this array
// being the only content
static const char *const secrets[] = {
    "no secrets to be found", "no secrets to be found", "no secrets to be found", "no secrets to be found", "no secrets to be found", "no secrets to be found", "no secrets to be found", "no secrets to be found", "no secrets to be found", "no secrets to be found", "no secrets to be found",
};
#endif

// Custom oneshot mod implementation with no timers.
bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
        // cancel key can't be a layer toggle key if I need to carry over the one shot mod to that layer.
        // theres no existing shortcuts on the Æ key to my knowledge so its a 'safe' cancel keys
        case MS_BSPC:
            return true;
        default:
            return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
        // must ignore the layers toggle keys to layers that contain the osm mods
        case SYM_N:
        case MODS:
        // must ignore the osm mods themselves
        case OS_SHFT:
        case OS_CTRL:
        case OS_ALT:
        case OS_CMD:
            return true;
        default:
            return false;
    }
}

oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state  = os_up_unqueued;
oneshot_state os_cmd_state  = os_up_unqueued;

// For tap_os_key def
#undef OSKEY
#define OSKEY(name, windows, mac)          \
    case name:                             \
        tap_os_key(windows, mac, pressed); \
        break;
// call this function for tapping a keycode which differs on on the OS'es
void tap_os_key(uint16_t win_keycode, uint16_t mac_keycode, bool pressed) {
    if (pressed) {
        tap_code16(is_windows() ? win_keycode : mac_keycode);
    }
}

// For shifted tap_os_key defs
#undef SFT_OSKEY
#define SFT_OSKEY(name, shiftedmac, shiftedwin, unshiftedmac, unshiftedwin)          \
    case name:                                                                       \
        shifted_os_key(shiftedmac, shiftedwin, unshiftedmac, unshiftedwin, pressed); \
        break;
// call this function for shifted os key which differs on on the OS'es
void shifted_os_key(uint16_t shifted_mac_keycode, uint16_t shifted_win_keycode, uint16_t unshifted_mac_keycode, uint16_t unshifted_win_keycode, bool pressed) {
    if (pressed) {
        if (get_mods() & MOD_MASK_SHIFT) {
            register_code16((is_mac()) ? shifted_mac_keycode : shifted_win_keycode);
        } else {
            register_code16((is_mac()) ? unshifted_mac_keycode : unshifted_win_keycode);
        }
    } else {  // release key
        unregister_code16((is_mac()) ? shifted_mac_keycode : shifted_win_keycode);
        unregister_code16((is_mac()) ? unshifted_mac_keycode : unshifted_win_keycode);
    }
}

// Custom keycodes
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Process case modes
    if (!process_case_modes(keycode, record)) {
        return false;
    }

    update_oneshot(&os_shft_state, KC_LSFT, OS_SHFT, keycode, record);
    update_oneshot(&os_ctrl_state, KC_LCTL, OS_CTRL, keycode, record);
    update_oneshot(&os_alt_state, KC_LALT, OS_ALT, keycode, record);
    update_oneshot(&os_cmd_state, KC_LGUI, OS_CMD, keycode, record);

    const bool pressed = record->event.pressed;
    switch (keycode) {
        case CAPSWRD:
            if (pressed) {
                toggle_caps_word();
            }
            return false;
        case SNAKECSE:
            if (pressed) {
                if (xcase_enabled()) {
                    disable_xcase();
                } else {
                    enable_xcase_with(UNDSC);
                }
            }
            return false;
        case TG_OS:  // toggle os (win or mac)
            if (pressed) {
                // keymap_config.swap_lctl_lgui = !keymap_config.swap_lctl_lgui;  // mimics CG_TOGG. If I need other Magic functions from process_magic.c I should Instead enable MAGIC in rules.mk
                // keymap_config.swap_rctl_rgui = keymap_config.swap_lctl_lgui;   //
                eeconfig_update_keymap(keymap_config.raw);
                clear_keyboard();  // clear to prevent stuck keys
            }
            return false;
            break;
        case KC_CL:
            if (pressed) {
                tap_code(KC_C);
                tap_code(KC_L);
            }
            break;
        case TO_BASE:
            if (pressed) {
                layer_clear();
            }
            break;
        case KC_HV:
            if (pressed) {
                tap_code(KC_H);
                tap_code(KC_V);
            }
            break;
        case KC_PAA:
            if (pressed) {
                tap_code(KC_P);
                tap_code(DK_AA);
            }
            break;
        case KC_FL:
            if (pressed) {
                tap_code(KC_F);
                tap_code(KC_L);
            }
            break;
        case KC_JE:
            if (pressed) {
                tap_code(KC_J);
                tap_code(KC_E);
            }
            break;

#if defined(LEADER_ENABLE)
            /*
             case SYM_TAB:
                 if (record->tap.count > 0) {
                     if (record->event.pressed) {
                         qk_leader_start();
                     }
                     return false;
                 }
                 break;
    */
#endif

        case SP_AS:
            if (pressed) {
                tap_code16(SIGN);
                tap_code16(ACPT);
            }
            break; /*
        case L_HANDS:
            if (pressed) {
                set_single_persistent_default_layer(BASE_LAYER);
            }
            break;
        case L_QWERTY:
            if (pressed) {
                set_single_persistent_default_layer(QWERTY);
            }
            break; */
                   // include all keys that change between OS'es
#include "oskeys.def"
            break;
        case PW:
            if (pressed) {
                send_string(secrets[0]);
                tap_code(KC_TAB);
                send_string(secrets[8]);
                tap_code(KC_ENT);
            }
            break;
        case PM:
            if (pressed) {
                send_string(secrets[2]);
                tap_code16((is_mac()) ? LALT(QUOT) : ALGR(KC_2));
                send_string(secrets[3]);
                tap_code(KC_TAB);
                send_string(secrets[8]);
                tap_code(KC_ENT);
            }
            break;
        case PK:
            if (pressed) {
                send_string(secrets[8]);
                tap_code(KC_ENT);
            }
            break;
        case LH:
            if (pressed) {
                send_string(secrets[7]);
                tap_code(KC_ENT);
            }
            break;
        case MW:
            if (pressed) {
                send_string(secrets[2]);
                tap_code16((is_mac()) ? LALT(QUOT) : ALGR(KC_2));
                send_string(secrets[3]);
            }
            break;

        case MP:
            if (pressed) {
                send_string(secrets[4]);
                tap_code16((is_mac()) ? LALT(QUOT) : ALGR(KC_2));
                send_string(secrets[5]);
            }
            break;
        case BSPC_W_S:
            if (pressed) {
                if (get_mods() & MOD_MASK_SHIFT) {
                    // bspc entire sentence
                    register_code16((S(KC_HOME)));
                    register_code(KC_BSPC);
                } else {
                    // bspc one word
                    register_code16((is_mac()) ? LALT(KC_BSPC) : LCTL(KC_BSPC));
                }
            } else {  // release key
                unregister_code16((S(KC_HOME)));
                unregister_code(KC_BSPC);
                unregister_code16((is_mac()) ? LALT(KC_BSPC) : LCTL(KC_BSPC));
            }
            break;
        case DEL_W_S:
            if (pressed) {
                if (get_mods() & MOD_MASK_SHIFT) {
                    // del entire sentence
                    register_code16((S(KC_END)));
                    register_code(KC_DEL);
                } else {
                    // del one word
                    register_code16((is_mac()) ? LALT(KC_DEL) : LCTL(KC_DEL));
                }
            } else {  // release key
                unregister_code16((S(KC_END)));
                unregister_code(KC_DEL);
                unregister_code16((is_mac()) ? LALT(KC_DEL) : LCTL(KC_DEL));
            }
            break;

        case DEL_BSPC_W:
            if (pressed) {
                if (get_mods() & MOD_MASK_SHIFT) {
                    // del one word
                    register_code16((is_mac()) ? LALT(KC_DEL) : LCTL(KC_DEL));
                } else {
                    // bspc one word
                    register_code16((is_mac()) ? LALT(KC_BSPC) : LCTL(KC_BSPC));
                }
            } else {  // release key
                unregister_code16((is_mac()) ? LALT(KC_BSPC) : LCTL(KC_BSPC));
                unregister_code16((is_mac()) ? LALT(KC_DEL) : LCTL(KC_DEL));
            }
            break;
        case MSWHEEL:
            if (pressed) {
                if (get_mods() & MOD_MASK_CTRL) {
                    // del one word
                    register_code16(KC_WH_U);
                } else {
                    // bspc one word
                    register_code16(KC_WH_D);
                }
            } else {  // release key
                unregister_code16(KC_WH_U);
                unregister_code16(KC_WH_D);
            }
            break;
        // all mod_tab cases
        case ALT_TAB:
            mod_tab(record, false);
            break;
        case RP:
            if (pressed) {
                tap_code(KC_TAB);
                SEND_STRING("Rp. ***");
                tap_code(KC_HOME);
                tap_code(KC_F2);
            }
            break;

// Shifted symbols
#include "shiftedoskeys.def"
    }
    return true;
}
