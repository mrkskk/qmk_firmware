#include "mrkskk.h"


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



uint16_t key_timer;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Process case modes
    if (!process_case_modes(keycode, record)) {
        return false;
    }
    if (!process_case_modes2(keycode, record)) {
        return false;
    }
  const bool pressed = record->event.pressed;
  switch (keycode) {
  case CAPSWRD:
            if (record->event.pressed) {
                enable_caps_word();
            }
            return false;
  case CAPSSENT:
            if (record->event.pressed) {
                enable_caps_sentence();
            }
            return false;
  case SNAKECSE:
            if (record->event.pressed) {
                enable_xcase_with(UNDSC);
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
    // TO DO: Re-code NXTW and PRVW into encoder.
  case KC_CL:
    if (pressed){
      tap_code(KC_C);
      tap_code(KC_L);
    }
    break;
case KC_GL:
    if (pressed){
      tap_code(KC_G);
      tap_code(KC_L);
    }
    break;
#if defined(LEADER_ENABLE)
  case LEAD:
    if (record->tap.count > 0) {
      if (pressed){
        qk_leader_start();
      }
      return false;
    }
    break;
#endif/*
  case ACUT_E:
    if (pressed){
      tap_code16(ACUT);
      tap_code(KC_E);
    }
    break;
  case ACUT_A:
    if (pressed){
      tap_code16(ACUT);
      tap_code(KC_A);
    }
    break;
  case ACUT_I:
    if (pressed){
      tap_code16(ACUT);
      tap_code(KC_I);
    }
    break;
  case ACUT_O:
    if (pressed){
      tap_code16(ACUT);
      tap_code(KC_O);
    }
    break;*/
  case GRV_E:
    if (pressed){
      tap_code16(GRV);
      tap_code(KC_E);
    }
    break;/*
  case GRV_A:
    if (pressed){
      tap_code16(GRV);
      tap_code(KC_A);
    }
    break;
  case GRV_I:
    if (pressed){
      tap_code16(GRV);
      tap_code(KC_I);
    }
    break;
  case GRV_O:
    if (pressed){
      tap_code16(GRV);
      tap_code(KC_O);
    }
    break;
  case TILD_N:
    if (pressed){
      tap_code16(TILD);
      tap_code(KC_N);
    }
    break;
  case DIAE_U:
    if (pressed){
      tap_code16(DIAE);
      tap_code(KC_U);
    }
    break;
  case DIAE_A:
    if (pressed){
      tap_code16(DIAE);
      tap_code(KC_A);
    }
    break;
  case DIAE_O:
    if (pressed){
      tap_code16(DIAE);
      tap_code(KC_O);
    }
    break;
  case DIAE_I:
    if (pressed){
      tap_code16(DIAE);
      tap_code(KC_I);
    }
    break;*/
  case TO_BASE:
    if (pressed){
      layer_clear();
     //s tap_code16(KC_V);
    }
  break;
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
    break;/*
  case L_COLEMAK:
    if (pressed){
      set_single_persistent_default_layer(COLEMAK_DH);
    }
    break;*/
  case L_QWERTY:
    if (pressed){
      set_single_persistent_default_layer(QWERTY);
    }
    break;/*
   case L_RSTHD:
    if (pressed){
      set_single_persistent_default_layer(RSTHD);
    }
    break;*/
#if defined(UNICODEMAP_ENABLE)
  case EN_EM_DSH:
    if (pressed){
      if (is_mac()) { // macOS
        if (get_mods() & MOD_MASK_SHIFT) {
          tap_code16(LALT(KC_SLSH));
        } else {
          tap_code16(S(LALT(KC_SLSH)));
        }
      } else { // Windows
        if (get_mods() & MOD_MASK_SHIFT) {
          send_unicode_string("–");
        } else {
          send_unicode_string("—");
        }
      }
    }
    break;
#endif
    break;
    // include all keys that change between OS'es
  #include "oskeys.def"
  }
  return true;
}
