#include "mrkskk.h"
// call this function for plain tapping a keycode which differs on on the OS'es
bool Win_Mac_Keycodes(uint16_t win_keycode, uint16_t mac_keycode,
                      keyrecord_t *record) {
  if (user_config.os_win_mac) // true == mac
  {
    if (record->event.pressed) {
      register_code16(mac_keycode);
    } else {
      unregister_code16(mac_keycode);
    }
  } else // false == wins
  {
    if (record->event.pressed) {
      register_code16(win_keycode);
    } else {
      unregister_code16(win_keycode);
    }
  }
  return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {

  case KC_MAKE: // Compiles the firmware, and adds the flash command based on
                // keyboard bootloader
    if (!record->event.pressed) {
      uint8_t temp_mod = get_mods();
      uint8_t temp_osm = get_oneshot_mods();
      clear_mods();
      clear_oneshot_mods();
      SEND_STRING("make " QMK_KEYBOARD ":" QMK_KEYMAP);
#ifndef FLASH_BOOTLOADER
      if ((temp_mod | temp_osm) & MOD_MASK_SHIFT)
#endif
      {
        SEND_STRING(":flash");
      }
      if ((temp_mod | temp_osm) & MOD_MASK_GUI) {
        SEND_STRING(" -j8 --output-sync");
      }
      tap_code(KC_ENT);
      set_mods(temp_mod);
    }
    break;
  case pil: // -->
    if (record->event.pressed) {
      SEND_STRING("-->");
    }
    break;
  case TG_OS: // toggle os (win or mac)
    toggle_os(record);
    return false;
    break;
  case S_S: /*Screenshots*/
    return Win_Mac_Keycodes(S_S_WIN, S_S_MAC, record);
    break;
  case FIND: /*alfred or gui*/
    return Win_Mac_Keycodes(KC_LGUI, LGUI(KC_SPC), record);
    break;
  case SWAP1: // mirrors bootmagic. sends Ctrl on win and GUI on mac
    return Win_Mac_Keycodes(KC_LCTL, KC_LGUI, record);
    break;
  case SWAP2: //  mirrors bootmagic. sends GUI on win and Ctrl on mac
    return Win_Mac_Keycodes(KC_LGUI, KC_LCTL, record);
    break;
  case LSFT_T(KC_F22): // hijack an unused keycode to do mod- and layer-taps with cooler taps than just basic keycodes
   if (record->tap.count > 0) {
      if (record->event.pressed) {
        set_oneshot_mods(MOD_LSFT);
        }
       return false;
      }
  break;
  case PRN: // Typing  two  parenthesis at once
    if (record->event.pressed) {
      SEND_STRING("()" SS_TAP(X_LEFT));
    }
    break;
  case AT: // @ universal WIN and MAC
    return Win_Mac_Keycodes(AT_WIN, AT_MAC, record);
    break;
  case LCB: // { universal WIN and MAC
    return Win_Mac_Keycodes(LCBR_WIN, LCBR_MAC, record);
    break;
  case RCB: // } universal WIN and MAC
    return Win_Mac_Keycodes(RCBR_WIN, RCBR_MAC, record);
    break;
  case PIPE: // | universal MAC and WIN
    return Win_Mac_Keycodes(PIPE_WIN, PIPE_MAC, record);
    break;
  case EUR: // € universal MAC and WIN
    return Win_Mac_Keycodes(EUR_WIN, EUR_MAC, record);
    break;
  case GBP: // £ universal MAC and WIN
    return Win_Mac_Keycodes(GBP_WIN, GBP_MAC, record);
    break;
  case USD: // usd universal MAC and WIN
    return Win_Mac_Keycodes(USD_WIN, USD_MAC, record);
    break;
  case BSLH: // \ universal MAC and WIN
    return Win_Mac_Keycodes(BLSH_WIN, BSLH_MAC, record);
    break;
  case NXTW: // \ universal MAC and WIN
    return Win_Mac_Keycodes(WIN_NEXT_WRD, MAC_NEXT_WORD, record);
    break;
  case PRVW: // \ universal MAC and WIN
    return Win_Mac_Keycodes(WIN_PREV_WRD, MAC_PREV_WORD, record);
    break;
  case S_NXTW: // \ universal MAC and WIN
    return Win_Mac_Keycodes(WIN_S_NEXT_WRD, MAC_S_NEXT_WORD, record);
    break;
  case S_PRVW: // \ universal MAC and WIN
    return Win_Mac_Keycodes(WIN_S_PREV_WRD, MAC_S_PREV_WORD, record);
    break;
  case COPY: // \ universal MAC and WIN
    return Win_Mac_Keycodes(WIN_COPY, MAC_COPY, record);
    break;
  case PASTE: // \ universal MAC and WIN
    return Win_Mac_Keycodes(WIN_PASTE, MAC_PASTE, record);
    break;
  case CUT: // \ universal MAC and WIN
    return Win_Mac_Keycodes(WIN_CUT, MAC_CUT, record);
    break;
  case UNDO: // \ universal MAC and WIN
    return Win_Mac_Keycodes(WIN_UNDO, MAC_UNDO, record);
    break;
  case REDO: // \ universal MAC and WIN
    return Win_Mac_Keycodes(WIN_REDO, MAC_REDO, record);
    break;
  case ALL: // \ universal MAC and WIN
    return Win_Mac_Keycodes(WIN_ALL, MAC_ALL, record);
    break;
  case REFSH: // \ universal MAC and WIN
    return Win_Mac_Keycodes(WIN_REFRESH, MAC_REFRESH, record);
    break;
    // TO DO: Re-code NXTW and PRVW into encoder.c
  case LCAG_T(LEAD):
    if (record->tap.count > 0) {
      if (record->event.pressed) {
        qk_leader_start();
        return false;
      }
      return true;
    }
    break;
  case Cedilla:
    if (record->event.pressed) {
      tap_code16(LALT(KC_C));
    }
    break;
  case ACUT_E:
    if (record->event.pressed) {
      tap_code16(ACUT);
      tap_code(KC_E);
    }
    break;
  case ACUT_A:
    if (record->event.pressed) {
      tap_code16(ACUT);
      tap_code(KC_A);
    }
    break;
  case ACUT_I:
    if (record->event.pressed) {
      tap_code16(ACUT);
      tap_code(KC_I);
    }
    break;
  case ACUT_O:
    if (record->event.pressed) {
      tap_code16(ACUT);
      tap_code(KC_O);
    }
    break;
  case GRV_E:
    if (record->event.pressed) {
      tap_code16(GRV);
      tap_code(KC_E);
    }
    break;
  case GRV_A:
    if (record->event.pressed) {
      tap_code16(GRV);
      tap_code(KC_A);
    }
    break;
  case GRV_I:
    if (record->event.pressed) {
      tap_code16(GRV);
      tap_code(KC_I);
    }
    break;
  case GRV_O:
    if (record->event.pressed) {
      tap_code16(GRV);
      tap_code(KC_O);
    }
    break;
  case TILD_N:
    if (record->event.pressed) {
      tap_code16(TILD);
      tap_code(KC_N);
    }
    break;
  case DIAE_U:
    if (record->event.pressed) {
      tap_code16(DIAE);
      tap_code(KC_U);
    }
    break;
  case DIAE_A:
    if (record->event.pressed) {
      tap_code16(DIAE);
      tap_code(KC_A);
    }
    break;
  case DIAE_O:
    if (record->event.pressed) {
      tap_code16(DIAE);
      tap_code(KC_O);
    }
    break;
  case DIAE_I:
    if (record->event.pressed) {
      tap_code16(DIAE);
      tap_code(KC_I);
    }
    break;
#if defined(UNICODEMAP_ENABLE)
  case L_ARW:
    if (record->event.pressed) {
      tap_code16(LALT(KC_SPC));
      send_unicode_string("←");
      tap_code16(C(A(KC_SPC)));
    }
    break;
  case R_ARW:
    if (record->event.pressed) {
      tap_code16(LALT(KC_SPC));
      send_unicode_string("→");
      tap_code16(C(A(KC_SPC)));
    }
    break;
    break;
  case U_ARW:
    if (record->event.pressed) {
      tap_code16(LALT(KC_SPC));
      send_unicode_string("↑");
      tap_code16(C(A(KC_SPC)));
    }
    break;
    break;
  case D_ARW:
    if (record->event.pressed) {
      tap_code16(LALT(KC_SPC));
      send_unicode_string("↓");
      tap_code16(C(A(KC_SPC)));
    }
    break;
    break;
  case E_ARW:
    if (record->event.pressed) {
      tap_code16(LALT(KC_SPC));
      send_unicode_string("↔");
      tap_code16(C(A(KC_SPC)));
    }
    break;
    break;
  case UD_ARW:
    if (record->event.pressed) {
      tap_code16(LALT(KC_SPC));
      send_unicode_string("↕");
      tap_code16(C(A(KC_SPC)));
    }
    break;
  case EN_EM_DSH:
    if (record->event.pressed) {
      if (user_config.os_win_mac) { // macOS
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
  case ALPHA:
    if (record->event.pressed) {
      tap_code16(LALT(KC_SPC));
      if (get_mods() & MOD_MASK_SHIFT) {
        send_unicode_string("Α");
      } else {
        send_unicode_string("α");
      }
      tap_code16(C(A(KC_SPC)));
    }
    break;
  case BETA:
    if (record->event.pressed) {
      tap_code16(LALT(KC_SPC));
      if (get_mods() & MOD_MASK_SHIFT) {
        send_unicode_string("Β");
      } else {
        send_unicode_string("β");
      }
      tap_code16(C(A(KC_SPC)));
    }
    break;
  case GAMMA:
    if (record->event.pressed) {
      tap_code16(LALT(KC_SPC));
      if (get_mods() & MOD_MASK_SHIFT) {
        send_unicode_string("Γ");
      } else {
        send_unicode_string("γ");
      }
      tap_code16(C(A(KC_SPC)));
    }
    break;
  case KAPPA:
    if (record->event.pressed) {
      tap_code16(LALT(KC_SPC));
      if (get_mods() & MOD_MASK_SHIFT) {
        send_unicode_string("Κ");
      } else {
        send_unicode_string("κ");
      }
      tap_code16(C(A(KC_SPC)));
    }
    break;
  case LAMBD:
    if (record->event.pressed) {
      tap_code16(LALT(KC_SPC));
      if (get_mods() & MOD_MASK_SHIFT) {
        send_unicode_string("Λ");
      } else {
        send_unicode_string("λ");
      }
      tap_code16(C(A(KC_SPC)));
    }
    break;
  case FUNNY:
    if (record->event.pressed) {
      tap_code16(LALT(KC_SPC));
      send_unicode_string("🤣");
      tap_code16(C(A(KC_SPC)));
    }
    break;
  case YAY:
    if (record->event.pressed) {
      tap_code16(LALT(KC_SPC));
      send_unicode_string("👍");
      tap_code16(C(A(KC_SPC)));
    }
    break;
  case NAY:
    if (record->event.pressed) {
      tap_code16(LALT(KC_SPC));
      send_unicode_string("👎");
      tap_code16(C(A(KC_SPC)));
    }
    break;
#endif
  }
  return true;
}
