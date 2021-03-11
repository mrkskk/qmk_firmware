/* Copyright 2015-2017 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include  "sendstring_danish_fixed.h" 
#include "mrkskk.h"

#if defined(COMBO_ENABLE)
#include "g/keymap_combo.h" // to make combo def dictionary work
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, NUMPAD, SYMBOLS, ADJUST);
    return state;
};


bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;



void dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0:
            if (active) {
                layer_on(ADJUST);
            } else {
                layer_off(ADJUST);
            }
            break;
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
}


bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case NUMPAD:
    case SYMBOLS:
      return false;
    default:
      return true;
  }
}

void matrix_scan_user(void)
{
#if defined(ENCODER_ENABLE)
    matrix_scan_encoders();
#endif
#if defined(LEADER_ENABLE)
    matrix_scan_leader();
#endif
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif    
}



bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
         case LCTL_A:
         case LALT_S:
         case LSFT_D:
         case LGUI_F:
         case RGUI_J:
         case RSFT_K:
         case LALT_L:
         case RCTL_AE: 
         case LALT_R:
         case HOME_T:   
         case RGUI_N:
         case RSFT_E:
         case LALT_I:
         case RCTL_O: 
            return true;
        default:
            return false;
    }
}

//Setting per key tapping term. 
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LCTL_A:
        case LALT_S:
        case LSFT_D:
        case LGUI_F:
        case RGUI_J:
        case RSFT_K:
        case LALT_L:
        case RCTL_AE: 
        case LALT_R:
        case HOME_T:   
        case RGUI_N:
        case RSFT_E:
        case LALT_I:
        case RCTL_O: 
            return TAPPING_TERM + 125; // 175+125=300
        case TT_NR:
        case NVSPC:
        case CBSPC:
        case NVENT:
        case OSM_T_SFT:
            return TAPPING_TERM;
        case SPLEAD:
            return TAPPING_TERM;
        default:
            return TAPPING_TERM;       // 400
    }
}


#ifdef COMBO_ENABLE
bool get_combo_must_tap(uint16_t index, combo_t *combo) {
    // If you want all combos to be tap-only, just uncomment the next line
    // return true

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

uint16_t get_combo_term(uint16_t index, combo_t *combo) {
    switch (index) {
        case COMBO_BSPC_W:
            return 300;
        case COMBO_DEL_W:
            return 300;
        case FIND_NVSPC_SC_F2:
            return 300;
        case SPLEAD_CAPSWRD_QUOT:
            return 300;
        default:
            return COMBO_TERM;
    }
    }
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[QWERTY] = LAYOUT_preonic_1x2uL(

// ,---------------------------------------------------------------------------------------------------------------.
    KC_GRV,     KC_1,    KC_2,     KC_3,    KC_4,    KC_5,   KC_6,       KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
// ,---------------------------------------------------------------------------------------------------------------|
    KC_TAB,     KC_Q,    KC_W,     KC_E,    KC_R,    KC_T,   KC_Y,       KC_U,    KC_I,    KC_O,    KC_P,    DK_AA,    
// |---------------------------------------------------------------------------------------------------------------|
    KC_LGUI,    LCTL_A,  LALT_S,   LSFT_D,  LGUI_F,  KC_G,   KC_H,       RGUI_J,  RSFT_K,  LALT_L,  RCTL_AE, DK_OE,       
// |,--------------------------------------------------------------------------------------------------------------|
    OSM_T_SFT,  KC_Z,    KC_X,     KC_C,    KC_V,    KC_B,   KC_N,       KC_M,    KC_COMM, KC_DOT,  OP,      MINUS,    
// `---------------------------------------------------------------------------------------------------------------|
    KC_LGUI,    KC_LCTL, KC_LALT,  TT_NR,      NVSPC,        TD(SPLEAD),      NVENT,   OS_SYM,  LEFT,    NED,     RGHT    
// `-----------------------------------------------------------------------------------.---------------------------'
    ),

[NUMPAD] = LAYOUT_preonic_1x2uL(

// ,---------------------------------------------------------------------------------------------------------------.
    CAD,       ____,    ____,     ____,    ____,    ____,   ____,       ____,    ____,    ____,    ____,    ____,
// ,---------------------------------------------------------------------------------------------------------------|
    ____,      ____,    ____,     ____,    ____,    ____,   ____,       KC_7,    KC_8,    KC_9,    KC_0,    DK_AA,    
// |---------------------------------------------------------------------------------------------------------------|
    ____,      ____,    ____,     ____,    ____,    ____,   ____,       KC_4,    KC_5,    KC_6,    PLUS,    MINUS,       
// |,--------------------------------------------------------------------------------------------------------------|
    ____,      ____,    ____,     ____,    ____,    ____,   ____,       KC_1,    KC_2,    KC_3,    KC_DOT,  KC_COMM,    
// `---------------------------------------------------------------------------------------------------------------|
    ____,      ____,    ____,     ____,          ____,      ____,       ____,    ____,    ____,    ____,    ____    
// `-----------------------------------------------------------------------------------.---------------------------'
    ),
[SYMBOLS] = LAYOUT_preonic_1x2uL(

// ,---------------------------------------------------------------------------------------------------------------.
    CAD,       ____,    ____,    ____,     ____,    ____,   ____,       ____,    ____,    ____,    ____,    ____,
// ,---------------------------------------------------------------------------------------------------------------|
    ____,      EXLM,    DQUO,    LCB,      RCB,    PERC,    SLSH,       BSLH,    HAT,    DIAE,    EQL,      ____,    
// |---------------------------------------------------------------------------------------------------------------|
    ____,      AT,      TILD,    LPRN,     RPRN,    HASH,   ASTR,       QUOT,    ACUT,    GRV,    PIPE,    MINUS,       
// |,--------------------------------------------------------------------------------------------------------------|
    ____,      LABK,    RABK,    LBRC,     RBRC,    QUES,   ____,       AMPR,    LABK,    RABK,   EN_EM_DSH,  KC_COMM,    
// `---------------------------------------------------------------------------------------------------------------|
    ____,      ____,    ____,     ____,          ____,      ____,       ____,   ____,     LEFT,    NED,      RGHT    
// `-----------------------------------------------------------------------------------.---------------------------'
    ),

[NAV] = LAYOUT_preonic_1x2uL(

// ,---------------------------------------------------------------------------------------------------------------.
    NXT_TAB,       ____,    ____,    ____,     ____,    ____,   ____,       ____,    ____,  ____,     ____,   ____,
// ,---------------------------------------------------------------------------------------------------------------|
    PRV_TAB,   NXT_TAB,     ____,    UNDO,     REDO,    PGUP,   C_HOME,     PRVW,    OP,    NXTW,      ____,  ____,   
// |---------------------------------------------------------------------------------------------------------------|
    CAPSWRD,   ACPT,       SIGN,     ____,     ____,    PGDN,   C_END,      KC_LEFT, NED,   KC_RGHT,   ____,  ____,       
// |,--------------------------------------------------------------------------------------------------------------|
    ____,      ____,       ____,     ____,     ____,    ____,   ____,       ____,    ____,    ____,     OP,    ____,    
// `---------------------------------------------------------------------------------------------------------------|
    ____,      ____,       ____,     ____,          ____,       ____,       ____,    ____,     LEFT,    NED,  RGHT   
// `-----------------------------------------------------------------------------------.---------------------------'
    ),

[ADJUST] = LAYOUT_preonic_1x2uL(

// ,---------------------------------------------------------------------------------------------------------------.
    TG_OS,     KC_F1,       KC_F2,   KC_F3,   KC_F4,   KC_F5,  KC_F6, KC_F7,   KC_F8,    KC_F9,    KC_F10,    KC_F11,
// ,---------------------------------------------------------------------------------------------------------------|
    PRV_TAB,   NXT_TAB,    ____,    ____,     ____,    ____,   ____, KC_F7,    KC_F8,    KC_F9,   KC_F12,     ____,   
// |---------------------------------------------------------------------------------------------------------------|
    CAPSWRD,   ACPT,       SIGN,     ____,     ____,   ____,   ____, KC_F4,    KC_F5,    KC_F6,    KC_F11,    ____,       
// |,--------------------------------------------------------------------------------------------------------------|
    ____,      ____,       ____,     ____,     ____,   ____,   ____, KC_F1,    KC_F2,    KC_F3,    KC_F10,    ____,    
// `---------------------------------------------------------------------------------------------------------------|
    ____,      ____,       ____,     ____,         ____,       ____,  ____,    ____,     ____,     ____,      ____    
// `-----------------------------------------------------------------------------------.---------------------------'
    ),
[SHORTCUTS] = LAYOUT_preonic_1x2uL(

// ,---------------------------------------------------------------------------------------------------------------.
    ____,     ____,       ____,     ____,    ____,    ____,  ____,    ____,   ____,    ____,    ____,    ____,
// ,---------------------------------------------------------------------------------------------------------------|
    ____,     ____,        ____,    ____,    ____,    KC_HOME,   PRVW,   S_UP_W,    NXTW,    ____,   ____,    ____,   
// |---------------------------------------------------------------------------------------------------------------|
    ____,      ____,       ____,     ____,   Bestord, KC_END,   S_PRVW,  S_DN_W,    S_NXTW,    ____,    ____,    ____,       
// |,--------------------------------------------------------------------------------------------------------------|
    ____,      ____,       ____,     ____,   ____,    ____,   ____,   ____,    ____,    ____,    ____,    ____,    
// `---------------------------------------------------------------------------------------------------------------|
    ____,      ____,       ____,     ____,        ____,       ____,   ____,    ____,   ____,     ____,    ____   
// `-----------------------------------------------------------------------------------.---------------------------'
    ),

};

