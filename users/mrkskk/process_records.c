#include "mrkskk.h"

#if (__has_include("secrets.h") && !defined(NO_SECRETS))
#include "secrets.h"
#else
// If the secret.h file is ever lost, simply create it again with this array
// being the only content
static const char *const secrets[] = {
    "no secrets to be found", "no secrets to be found",
    "no secrets to be found", "no secrets to be found",
    "no secrets to be found", "no secrets to be found",
    "no secrets to be found", "no secrets to be found",
    "no secrets to be found", "no secrets to be found",
    "no secrets to be found",
};
#endif

//For tap_os_key def
#undef OSKEY
#define OSKEY(name, windows, mac)           \
    case name:                            \
        tap_os_key(windows, mac, pressed);  \
        break;

// call this function for plain tapping a keycode which differs on on the OS'es
void tap_os_key(uint16_t win_keycode, uint16_t mac_keycode, bool pressed) {
    if (pressed) {
        tap_code16(is_windows() ? win_keycode : mac_keycode);
    }
}

layer_state_t layer_state_set_user(layer_state_t state) {
    if (is_alt_tab_active) {
        unregister_code((is_mac()) ? KC_LALT : KC_LGUI);
        is_alt_tab_active = false;
    }
    return state;
}


uint16_t key_timer;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Process case modes
    if (!process_case_modes(keycode, record)) {
        return false;
    }
  const bool pressed = record->event.pressed;
  switch (keycode) {
  case CAPSWRD:
    if (pressed){
     toggle_caps_word();
    }
    return false;
  case SNAKECSE:
    if (pressed){
        if (xcase_enabled()) {
        disable_xcase();
        }
        else {
        enable_xcase_with(UNDSC);
        }
        }
    return false;
  case TG_OS: // toggle os (win or mac)
     if (pressed){
    keymap_config.swap_lctl_lgui = !keymap_config.swap_lctl_lgui; // mimics CG_TOGG. If I need other Magic functions from process_magic.c I should Instead enable MAGIC in rules.mk
    keymap_config.swap_rctl_rgui = keymap_config.swap_lctl_lgui;  //
    eeconfig_update_keymap(keymap_config.raw);
     clear_keyboard();  // clear to prevent stuck keys
    }
    return false;
    break;
    // TO DO: Re-code NXT_WRD and PRV_WRD into encoder.
  case KC_CL:
    if (pressed){
      tap_code(KC_C);
      tap_code(KC_L);
    }
    break;
 case TO_BASE:
    if (pressed){
      layer_clear();
      }
    break;
case SCROLL_UP:
if (pressed){
      tap_code(KC_UP);
      tap_code(KC_UP);
      tap_code(KC_UP);
      tap_code(KC_UP);
      tap_code(KC_UP);
      tap_code(KC_UP);
      tap_code(KC_UP);
      tap_code(KC_UP);
      tap_code(KC_UP);
      tap_code(KC_UP);
      }
    break;
case SCROLL_DN:
if (pressed){
      tap_code(KC_DOWN);
      tap_code(KC_DOWN);
      tap_code(KC_DOWN);
      tap_code(KC_DOWN);
      tap_code(KC_DOWN);
      tap_code(KC_DOWN);
      tap_code(KC_DOWN);
      tap_code(KC_DOWN);
      tap_code(KC_DOWN);
      tap_code(KC_DOWN);
      }
    break;
case KC_HV:
    if (pressed){
      tap_code(KC_H);
      tap_code(KC_V);
    }
    break;
case KC_PAA:
    if (pressed){
      tap_code(KC_P);
      tap_code(DK_AA);
    }
    break;
case KC_FL:
    if (pressed){
        tap_code(KC_F);
        tap_code(KC_L);
    }
    break;
case KC_JE:
    if (pressed){
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
    if (pressed){
      tap_code16(SIGN);
      tap_code16(ACPT);
    }
  break;
  case L_HANDSDOWN:
    if (pressed){
      set_single_persistent_default_layer(HANDSDOWN_ALT_NX_DK_MOD);
    }
    break;
  case L_QWERTY:
    if (pressed){
      set_single_persistent_default_layer(QWERTY);
    }
    break;
    // include all keys that change between OS'es
  #include "oskeys.def"
   break;
 case PW:
if (pressed){
      send_string(secrets[0]);
      tap_code(KC_TAB);
      send_string(secrets[8]);
      tap_code(KC_ENT);
    }
    break;
case PM:
if (pressed){
      send_string(secrets[2]);
      tap_code16(AT);
      send_string(secrets[3]);
      tap_code(KC_TAB);
      send_string(secrets[8]);
      tap_code(KC_ENT);
    }
    break;
case PK:
if (pressed){
      send_string(secrets[8]);
      tap_code(KC_ENT);
    }
    break;
case LH:
if (pressed){
    send_string(secrets[7]);
    tap_code(KC_ENT);
    }
    break;
case MW:
if (pressed){
    send_string(secrets[2]);
    tap_code16(AT);
    send_string(secrets[3]);
    }
break;

case MP:
if (pressed){
    send_string(secrets[4]);
    tap_code16(AT);
    send_string(secrets[5]);
}
break;
case BSPC_WRD_SENT:
    if (pressed) {
      if (get_mods() & MOD_MASK_SHIFT) {
          //bspc entire sentence
          register_code16((S(KC_HOME)));
          register_code(KC_BSPC);
        } else {
          //bspc one word
          register_code16((is_mac()) ? LALT(KC_BSPC) : LCTL(KC_BSPC ));
        }
      } else { //release key
          unregister_code16((S(KC_HOME)));
          unregister_code(KC_BSPC);
          unregister_code16((is_mac()) ? LALT(KC_BSPC) : LCTL(KC_BSPC ));
      }
break;
case DEL_WRD_SENT:
    if (pressed) {
      if (get_mods() & MOD_MASK_SHIFT) {
          //bspc entire sentence
          register_code16((S(KC_END)));
          register_code(KC_DEL);
        } else {
          //bspc one word
          register_code16((is_mac()) ? LALT(KC_DEL) : LCTL(KC_DEL ));
        }
      } else { //release key
          unregister_code16((S(KC_END)));
          unregister_code(KC_DEL);
          unregister_code16((is_mac()) ? LALT(KC_DEL) : LCTL(KC_DEL ));
      }
break;
// all mod_tab cases
case ALT_TAB: // super alt tab macro
            if (record->event.pressed) {
                if (!is_alt_tab_active) {
                    is_alt_tab_active = true;
                    register_code((is_mac()) ? KC_LALT : KC_LGUI);
                }
                register_code(KC_TAB);
            } else {
                unregister_code(KC_TAB);
            }
break;
}
  return true;
}
