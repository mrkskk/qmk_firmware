
#include "mrkskk.h"

// call this function for plain tapping a keycode which differs on on the OS'es
bool Win_Mac_Keycodes(uint16_t win_keycode, uint16_t mac_keycode,
                      keyrecord_t *record) {
  if (is_mac()) // true == mac
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
  switch (keycode) {
  case CAPSWRD:
    if (record->event.pressed) {
      caps_word_enable();
    }
    return false;
    break;
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
  case TG_OS: // toggle os (win or mac)
     if (record->event.pressed) {
    keymap_config.swap_lctl_lgui = !keymap_config.swap_lctl_lgui; // mimics CG_TOGG. If I need other Magic functions from process_magic.c I should Instead enable MAGIC in rules.mk 
    keymap_config.swap_rctl_rgui = keymap_config.swap_lctl_lgui;  // 
    }
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
  case LSFT_T(KC_F22): // defined as OSM_T_SFT in mrkskk.h
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
  case S_UP_W: // \ universal MAC and WIN
    return Win_Mac_Keycodes(WIN_S_UP_WRD, MAC_S_UP_WRD, record);
    break;
  case S_DN_W: // \ universal MAC and WIN
    return Win_Mac_Keycodes(WIN_S_DN_WRD, MAC_S_DN_WRD, record);
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
#if defined(LEADER_ENABLE)
  case LCAG_T(LEAD):
    if (record->tap.count > 0) {
      if (record->event.pressed) {
        qk_leader_start();
        return false;
      }
      return true;
    }
    break;
#endif
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
  case COLEM:
    if (record->event.pressed) {
      set_single_persistent_default_layer(COLEMAK_DH);
    }
    break;
  case QWERT:
    if (record->event.pressed) {
      set_single_persistent_default_layer(QWERTY);
    }
    break;
#if defined(UNICODEMAP_ENABLE)
  case EN_EM_DSH:
    if (record->event.pressed) {
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
  case HOME_F:
    if (record->event.pressed) {
      key_timer = timer_read();
      if (is_mac()) { // macOS
        register_code(KC_LGUI);     // hold
      } else {                      // Windows
        register_code(KC_LCTRL);
      }
    } else {                        // keyrelease
      if (is_mac()) { // macOS
        unregister_code(KC_LGUI);   // tap
      } else {                      // Windows
        unregister_code(KC_LCTRL);  // tap
      }
      if (timer_elapsed(key_timer) < TAPPING_TERM) {
        tap_code(KC_F);
      }
    }
    break;
  case HOME_A:
    if (record->event.pressed) {
      key_timer = timer_read();
      if (is_mac()) { // macOS
        register_code(KC_LCTRL);    // hold
      } else {                      // Windows
        register_code(KC_LGUI);
      }
    } else {                        // keyrelease
      if (is_mac()) { // macOS
        unregister_code(KC_LCTRL);  // tap
      } else {                      // Windows
        unregister_code(KC_LGUI);   // tap
      }
      if (timer_elapsed(key_timer) < TAPPING_TERM) {
        tap_code(KC_A);
      }
    }
    break;
  case HOME_J:
    if (record->event.pressed) {
      key_timer = timer_read();
      if (is_mac()) { // macOS
        register_code(KC_LGUI);     // hold
      } else {                      // Windows
        register_code(KC_LCTRL);
      }
    } else {                        // keyrelease
      if (is_mac()) { // macOS
        unregister_code(KC_LGUI);   // tap
      } else {                      // Windows
        unregister_code(KC_LCTRL);  // tap
      }
      if (timer_elapsed(key_timer) < TAPPING_TERM) {
        tap_code(KC_J);
      }
    }
    break;
  case HOME_AE:
    if (record->event.pressed) {
      key_timer = timer_read();
      if (is_mac()) { // macOS
        register_code(KC_LCTRL);    // hold
      } else {                      // Windows
        register_code(KC_LGUI);
      }
    } else {                        // keyrelease
      if (is_mac()) { // macOS
        unregister_code(KC_LCTRL);  // tap
      } else {                      // Windows
        unregister_code(KC_LGUI);   // tap
      }
      if (timer_elapsed(key_timer) < TAPPING_TERM) {
        tap_code(DK_AE);
      }
    }
    break;

  }
  return true;
}
