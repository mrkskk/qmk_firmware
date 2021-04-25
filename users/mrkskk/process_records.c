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
  const bool pressed = record->event.pressed;
  switch (keycode) {
  case CAPSWRD:
    if (pressed){
    enable_caps_word();
    }
    return false;
  case SNAKECSE:
    if (pressed){
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
    // TO DO: Re-code NXT_WRD and PRV_WRD into encoder.
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
  case SYM_LEAD:
    if (record->tap.count > 0) {
      if (record->event.pressed) {
        qk_leader_start();
      }
      return false;
    }
    break;
#endif
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
    break;
  case L_QWERTY:
    if (pressed){
      set_single_persistent_default_layer(QWERTY);
    }
    break;
    // include all keys that change between OS'es
  #include "oskeys.def"
  }
  return true;
}
