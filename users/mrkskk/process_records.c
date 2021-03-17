#include "mrkskk.h"

// call this function for plain tapping a keycode which differs on on the OS'es
void tap_os_key(uint16_t win_keycode, uint16_t mac_keycode, bool pressed) {
    if (pressed) {
        tap_code16(is_windows() ? win_keycode : mac_keycode);
    }
}
/* This particular implementation is by @dnaq at splitkb.com discord. Idea
 * originally from @iaap, also at splitkb.com discord. */

static bool caps_word_enabled = false;
void caps_word_enable(void) {
  caps_word_enabled = true;
  if (!host_keyboard_led_state().caps_lock) {
    tap_code(KC_CAPS);
  }
}

void caps_word_disable(void) {
  caps_word_enabled = false;
  if (host_keyboard_led_state().caps_lock) {
    tap_code(KC_CAPS);
  }
}

void caps_word_toggle(void) {
  if (caps_word_enabled) {
    caps_word_disable();
  } else {
    caps_word_enable();
  }
}

static void process_caps_word(uint16_t keycode, keyrecord_t *record) {
  if (caps_word_enabled) {
    // first strip of the mod taps and layer taps if needed
    switch (keycode) {
    case QK_MOD_TAP ... QK_MOD_TAP_MAX:
    case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
      if (record->tap.count == 0)
        return;
      keycode = keycode & 0xFF;
    }
    // we end caps word on one of the following keypresses
    switch (keycode & 0xFF) {
    case KC_ESC:
    case KC_SPC:
    case KC_ENT:
    case KC_TAB:
    case KC_DOT:
    case KC_COMM:
      if (record->event.pressed) {
        caps_word_disable();
      }
    }
  }
}

uint16_t key_timer;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  process_caps_word(keycode, record);
  const bool pressed = record->event.pressed;
  switch (keycode) {
  case CAPSWRD:
    if (pressed){
      caps_word_enable();
    }
    return false;
    break;
  case TG_OS: // toggle os (win or mac)
     if (pressed){
    keymap_config.swap_lctl_lgui = !keymap_config.swap_lctl_lgui; // mimics CG_TOGG. If I need other Magic functions from process_magic.c I should Instead enable MAGIC in rules.mk
    keymap_config.swap_rctl_rgui = keymap_config.swap_lctl_lgui;  //
    }
    return false;
    break;
  /*case LSFT_T(KC_F22): // defined as OSM_T_SFT in mrkskk.h
    if (record->tap.count > 0) {
      if (pressed){
        set_oneshot_mods(MOD_LSFT);
      }
      return false;
    }
    break;*/
  /*case LT(NUMPAD, KC_F23):
            if (record->tap.count > 0) {
                if (pressed){
                    set_oneshot_mods(MOD_LSFT);
                }
                return false;
            }
            break;*/
  /*case LT(SYMBOLS, KC_F24):
            if (record->tap.count > 0) {
                if (pressed){
                    set_oneshot_mods(MOD_LSFT);
                }
                return false;
            }
            break;*/
   case SCR_SHOT: /*Screenshots*/
    tap_os_key(S_S_WIN, S_S_MAC, pressed);
    break;
  case FIND: /*alfred or gui*/
    tap_os_key(KC_LGUI, LGUI(KC_SPC), pressed);
    break;
  case C_END: // @ universal WIN and MAC
    tap_os_key(KC_END, LGUI(KC_RGHT), pressed);
    break;
case C_HOME: // @ universal WIN and MAC
    tap_os_key(KC_HOME, LGUI(KC_LEFT), pressed);
    break;
  case AT: // @ universal WIN and MAC
    tap_os_key(AT_WIN, AT_MAC, pressed);
    break;
  case LCB: // { universal WIN and MAC
    tap_os_key(LCBR_WIN, LCBR_MAC, pressed);
    break;
  case RCB: // } universal WIN and MAC
    tap_os_key(RCBR_WIN, RCBR_MAC, pressed);
    break;
  case PIPE: // | universal MAC and WIN
    tap_os_key(PIPE_WIN, PIPE_MAC, pressed);
    break;
  case EUR: // € universal MAC and WIN
    tap_os_key(EUR_WIN, EUR_MAC, pressed);
    break;
  case GBP: // £ universal MAC and WIN
    tap_os_key(GBP_WIN, GBP_MAC, pressed);
    break;
  case USD: // usd universal MAC and WIN
    tap_os_key(USD_WIN, USD_MAC, pressed);
    break;
  case BSLH: // \ universal MAC and WIN
    tap_os_key(BLSH_WIN, BSLH_MAC, pressed);
    break;
  case NXTW: // \ universal MAC and WIN
    tap_os_key(WIN_NEXT_WRD, MAC_NEXT_WORD, pressed);
    break;
  case PRVW: // \ universal MAC and WIN
    tap_os_key(WIN_PREV_WRD, MAC_PREV_WORD, pressed);
    break;
  case S_NXTW: // \ universal MAC and WIN
    tap_os_key(WIN_S_NEXT_WRD, MAC_S_NEXT_WORD, pressed);
    break;
  case S_PRVW: // \ universal MAC and WIN
    tap_os_key(WIN_S_PREV_WRD, MAC_S_PREV_WORD, pressed);
    break;
  case S_UP_W: // \ universal MAC and WIN
    tap_os_key(WIN_S_UP_WRD, MAC_S_UP_WRD, pressed);
    break;
  case S_DN_W: // \ universal MAC and WIN
    tap_os_key(WIN_S_DN_WRD, MAC_S_DN_WRD, pressed);
    break;
  case COPY: // \ universal MAC and WIN
    tap_os_key(WIN_COPY, MAC_COPY, pressed);
    break;
  case PASTE: // \ universal MAC and WIN
    tap_os_key(WIN_PASTE, MAC_PASTE, pressed);
    break;
  case CUT: // \ universal MAC and WIN
    tap_os_key(WIN_CUT, MAC_CUT, pressed);
    break;
  case UNDO: // \ universal MAC and WIN
    tap_os_key(WIN_UNDO, MAC_UNDO, pressed);
    break;
  case REDO: // \ universal MAC and WIN
    tap_os_key(WIN_REDO, MAC_REDO, pressed);
    break;
  case ALL: // \ universal MAC and WIN
    tap_os_key(WIN_ALL, MAC_ALL, pressed);
    break;
  case REFSH: // \ universal MAC and WIN
    tap_os_key(WIN_REFRESH, MAC_REFRESH, pressed);
    break;
    // TO DO: Re-code NXTW and PRVW into encoder.c
#if defined(LEADER_ENABLE)
  case LCAG_T(LEAD):
    if (record->tap.count > 0) {
      if (pressed){
        qk_leader_start();
        return false;
      }
      return true;
    }
    break;
#endif
  /*
  case Cedilla:
    if (pressed){
      tap_code16(LALT(KC_C));
    }
    break;*/
  case ACUT_E:
    if (pressed){
      tap_code16(ACUT);
      tap_code(KC_E);
    }
    break;/*
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
  case SP_AS:
    if (pressed){
      tap_code16(SIGN);
      tap_code16(ACPT);
    }
  break;
  case COLEM:
    if (pressed){
      set_single_persistent_default_layer(COLEMAK_DH);
    }
    break;
  case QWERT:
    if (pressed){
      set_single_persistent_default_layer(QWERTY);
    }
    break;
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
  }
  return true;
}
