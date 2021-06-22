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
/*
// Custom oneshot mod implementation with no timers.
bool is_oneshot_cancel_key(uint16_t keycode) {
    switch (keycode) {
        // cancel key can't be a layer toggle key if I need to carry over the one shot mod to that layer.d
        case CLEAR:
            return true;
        default:
            return false;
    }
}

bool is_oneshot_ignored_key(uint16_t keycode) {
    switch (keycode) {
        // must ignore the layers toggle keys to layers that contain the osm mods,
        case MODS:
        case HMR_ENT:
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
*/
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

// For autoshift
uint16_t last_keycode = SAFE_RANGE;

// Custom keycodes
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Process case modes
    if (!process_case_modes(keycode, record)) {
        return false;
    }

    /*
    // update callum oneshots.
    update_oneshot(&os_shft_state, KC_LSFT, OS_SHFT, keycode, record);
    update_oneshot(&os_ctrl_state, KC_LCTL, OS_CTRL, keycode, record);
    update_oneshot(&os_alt_state, KC_LALT, OS_ALT, keycode, record);
    update_oneshot(&os_cmd_state, KC_LGUI, OS_CMD, keycode, record);
    */
    // for readability
    const bool pressed = record->event.pressed;

    // other custom keys
    switch (keycode) {
        case MYMOD:
            if (pressed) {
                enable_my_mod();

            } else {
                disable_my_mod();
            }
            return false;
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
                keymap_config.swap_lctl_lgui = !keymap_config.swap_lctl_lgui;  // mimics CG_TOGG. If I need other Magic functions from process_magic.c I should Instead enable MAGIC in rules.mk
                keymap_config.swap_rctl_rgui = keymap_config.swap_lctl_lgui;   //
                eeconfig_update_keymap(keymap_config.raw);
                clear_keyboard();  // clear to prevent stuck keys
            }
            return false;
        case KC_CL:
            if (pressed) {
                tap_code(KC_C);
                tap_code(KC_L);
            }
            return false;
        case TO_BASE:
            if (pressed) {
                layer_clear();
            }
            return false;
        case KC_JE:
            if (pressed) {
                tap_code(KC_J);
                tap_code(KC_E);
            }
            return false;

#if defined(LEADER_ENABLE)
            /*
             case SYM_TAB:
                 if (record->tap.count > 0) {
                     if (pressed) {
                         qk_leader_start();
                     }
                     return false;
                 }
                 return false;
    */
#endif

        case SP_AS:
            if (pressed) {
                tap_code16(SIGN);
                tap_code16(ACPT);
            }
            return false;
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
            return false;
        case PM:
            if (pressed) {
                send_string(secrets[2]);
                tap_code16((is_mac()) ? LALT(QUOT) : ALGR(KC_2));
                send_string(secrets[3]);
                tap_code(KC_TAB);
                send_string(secrets[8]);
                tap_code(KC_ENT);
            }
            return false;
        case PK:
            if (pressed) {
                send_string(secrets[8]);
                tap_code(KC_ENT);
            }
            return false;
        case LH:
            if (pressed) {
                send_string(secrets[7]);
                tap_code(KC_ENT);
            }
            return false;
        case MW:
            if (pressed) {
                send_string(secrets[2]);
                tap_code16((is_mac()) ? LALT(QUOT) : ALGR(KC_2));
                send_string(secrets[3]);
            }
            return false;

        case MP:
            if (pressed) {
                send_string(secrets[4]);
                tap_code16((is_mac()) ? LALT(QUOT) : ALGR(KC_2));
                send_string(secrets[5]);
            }
            return false;
        case BSPC_W_S:
            if (pressed) {
           if (my_mod_enabled()) {
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
            return false;
        case DEL_W_S:
            if (pressed) {
                 if (my_mod_enabled()) {
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
            return false;

        case DEL_BS_W:
            if (pressed) {
                if (my_mod_enabled()) {
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
            return false;
        case MSWHEEL:
            if (pressed) {
                 if (my_mod_enabled()) {
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
            return false;
        // all mod_tab cases
        case ALT_TAB:
            mod_tab(record, false);
            return false;
        case RP:
            if (pressed) {
                tap_code(KC_TAB);
                SEND_STRING("Rp. ***");
                tap_code(KC_HOME);
                tap_code(KC_F2);
            }
            return false;
        case CLEAR:
            if (pressed) {
                clear_oneshot_mods();
                if (get_oneshot_layer() != 0) {
                    clear_oneshot_layer_state(ONESHOT_OTHER_KEY_PRESSED);
                }
            }
            return false;
        case UNDOREDO:  // One key copy/paste
            if (pressed) {
                if (my_mod_enabled()) {  // redo
                    register_code16((is_mac()) ? LGUI(S(KC_Z)) : LCTL(KC_Y));
                } else {  // undo
                    register_code16((is_mac()) ? LGUI(KC_Z) : LCTL(KC_Z));
                }
            } else {
                unregister_code16((is_mac()) ? LGUI(S(KC_Z)) : LCTL(KC_Y));
                unregister_code16((is_mac()) ? LGUI(KC_Z) : LCTL(KC_Z));
            }
            break;
        case COPYPASTE:  // One key copy/paste
            if (pressed) {
                if (my_mod_enabled()) {  // redo
                    register_code16((is_mac()) ? LGUI(S(KC_V)) : LCTL(KC_V));
                } else {  // undo
                    register_code16((is_mac()) ? LGUI(KC_C) : LCTL(KC_C));
                }
            } else {
                unregister_code16((is_mac()) ? LGUI(S(KC_V)) : LCTL(KC_V));
                unregister_code16((is_mac()) ? LGUI(KC_C) : LCTL(KC_C));
            }
            break;
        case PAIR_PN:
        if (pressed) {
            tap_code16(LPRN);
            
            tap_code16(RPRN);
            tap_code(KC_LEFT);
        }
        break;
        case PAIR_CPN:
        if (pressed) {
            tap_code16(LCB);
       
            tap_code16(RCB);     
            tap_code(KC_LEFT);
        }
        case PAIR_BPN: 
        if (pressed) {
            tap_code16(LBRC);
      
            tap_code16(RBRC);      
            tap_code(KC_LEFT);
        }
        break;
            // adaptive keys. Inspiration from the nari layout.
            /*
            case KC_DOE:
                if (record->event.pressed) {
                    if (last_keycode == KC_W || last_keycode == KC_C || last_keycode == KC_G || last_keycode == KC_M || last_keycode == KC_Q || last_keycode == HOME_R || last_keycode == HOME_S || last_keycode == NAV2_T || last_keycode == HOME_H || last_keycode == KC_F || last_keycode == KC_V || last_keycode == KC_B || last_keycode == KC_L || last_keycode == KC_DOE || last_keycode == KC_X || last_keycode == KC_K || last_keycode == KC_J || last_keycode == KC_PAA) {
                        tap_code(DK_OE);
                    } else {
                        tap_code(HOME_D);
                    }
                    last_keycode = keycode;  // Update last keycode with current
                    return false;
                }*/
        case HOME_R:
        case HOME_A:
        case HOME_P0:
            if (pressed) {
                enable_my_mod();
            } else {
                disable_my_mod();
            }
       /* case LT(NUM_LAYER, KC_SPC):
            if (last_keycode == KC_DOT) {
                if (pressed) {
                    // Do something when pressed
                    tap_code(KC_SPC);
                    set_oneshot_mods(MOD_BIT(KC_LSFT));
                    // Do something when sequence is KC_A,KC_B
                }

                last_keycode = keycode;  // Update last keycode with current
                return false;
            }*/
        default:

            last_keycode = keycode;  // Update last keycode with current
            return true;
            break;
            // Shifted symbols
            //#include "shiftedoskeys.def"
    }
    return true;
}
