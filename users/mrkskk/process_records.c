// clang format on
#include "mrkskk.h"

#if (__has_include("secrets.h") && !defined(NO_SECRETS))
#    include "secrets.h"
#else
// If the secret.h file is ever lost, simply create it again with this array
// being the only content
static const char *const secrets[] = {
    "no secrets to be found", "no secrets to be found", "no secrets to be found", "no secrets to be found", "no secrets to be found", "no secrets to be found", "no secrets to be found", "no secrets to be found", "no secrets to be found", "no secrets to be found", "no secrets to be found",
};
#endif

// For tap_os_key def
#undef OSKEY
#define OSKEY(name, windows, mac)          \
    case name:                             \
        tap_os_key(windows, mac, pressed); \
        break;

// call this function for plain tapping a keycode which differs on on the OS'es
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

bool     is_alt_tab_active = false;  // ADD this near the begining of keymap.c
uint16_t alt_tab_timer     = 0;

uint16_t key_timer;
bool     process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Process case modes
    if (!process_case_modes(keycode, record)) {
        return false;
    }
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
                keymap_config.swap_lctl_lgui = !keymap_config.swap_lctl_lgui;  // mimics CG_TOGG. If I need other Magic functions from process_magic.c I should Instead enable MAGIC in rules.mk
                keymap_config.swap_rctl_rgui = keymap_config.swap_lctl_lgui;   //
                eeconfig_update_keymap(keymap_config.raw);
                clear_keyboard();  // clear to prevent stuck keys
            }
            return false;
            break;
            // TO DO: Re-code NXT_WRD and PRV_WRD into encoder.
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
        case SYM_TAB:
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    qk_leader_start();
                }
                return false;
            }
            break;
#endif
        case SP_AS:
            if (pressed) {
                tap_code16(SIGN);
                tap_code16(ACPT);
            }
            break; /*
        case L_HANDS:
            if (pressed) {
                set_single_persistent_default_layer(HANDSDOWN_ALT_NX_DK_MOD);
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
                    // bspc entire sentence
                    register_code16((S(KC_END)));
                    register_code(KC_DEL);
                } else {
                    // bspc one word
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
        case ALT_TAB:
            if (pressed) {
                if (!is_alt_tab_active) {
                    is_alt_tab_active = true;
                    if (is_mac()) {
                        register_code(KC_LGUI);
                    } else if (is_windows()) {
                        register_code(KC_LALT);
                    }
                }
                alt_tab_timer = timer_read();
                register_code(KC_TAB);
            } else {
                unregister_code(KC_TAB);
            }
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
            break;
            // autoshifting combos
        case DOTSFT:
            if (pressed) {
                tap_code(KC_DOT);
                tap_code(KC_SPC);
                set_oneshot_mods(MOD_BIT(KC_LSFT));
            }
            break;
        case COLSFT:
            if (pressed) {
                tap_code16(S(KC_DOT));
                tap_code(KC_SPC);
                set_oneshot_mods(MOD_BIT(KC_LSFT));
            }
            break;
        case QUESSFT:
            if (pressed) {
                tap_code16(QUES);
                tap_code(KC_SPC);
                set_oneshot_mods(MOD_BIT(KC_LSFT));
            }
            break;
        case EXLMSFT:
            if (pressed) {
                tap_code16(EXLM);
                tap_code(KC_SPC);
                set_oneshot_mods(MOD_BIT(KC_LSFT));
            }
            break;
        case SEMCOLSFT:
            if (pressed) {
                tap_code16(S(KC_COMM));
                tap_code(KC_SPC);
                set_oneshot_mods(MOD_BIT(KC_LSFT));
            }
            break;
    }
    return true;
}

void matrix_scan_alttab(void) {  // The very important timer.
    if (is_alt_tab_active) {
        if (timer_elapsed(alt_tab_timer) > 750) {
            if (is_mac()) {
                unregister_code(KC_LGUI);
            } else if (is_windows()) {
                unregister_code(KC_LALT);
            }
            is_alt_tab_active = false;
        }
    }
}
