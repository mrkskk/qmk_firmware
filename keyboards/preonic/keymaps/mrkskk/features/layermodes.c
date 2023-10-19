#include "features/layermodes.h"
#include "features/os_keys.h"
#include "defines.h"

static uint16_t num_word_timer;
static bool     _num_word_enabled = false;
bool            num_word_enabled(void) {
    return _num_word_enabled;
}
void enable_num_word(void) {
    _num_word_enabled = true;
    if (is_mac()) {
        layer_on(_NUM);
    } else {
        layer_on(_NUM_WIN);
    }
}

void disable_num_word(void) {
    _num_word_enabled = false;

    if (is_mac()) {
        layer_on(_NUM);
    } else {
        layer_on(_NUM_WIN);
    }
}

void process_num_word_activation(const keyrecord_t *record) {
    if (record->event.pressed) {
        if (is_mac()) {
            layer_on(_NUM);
        } else {
            layer_on(_NUM_WIN);
        }
        num_word_timer = timer_read();
    } else {
        if (timer_elapsed(num_word_timer) < TAPPING_TERM + 50) {
            // Tapping enables NUMWORD
            _num_word_enabled = true;
        } else {
            // Holding turns off NUM when released
            if (is_mac()) {
                layer_off(_NUM);
            } else {
                layer_off(_NUM_WIN);
            }
        }
    }
}
bool process_num_word(uint16_t keycode, const keyrecord_t *record) {
    if (!_num_word_enabled) return true;
    if (((QK_MOD_TAP <= keycode && keycode <= QK_MOD_TAP_MAX) || (QK_LAYER_TAP <= keycode && keycode <= QK_LAYER_TAP_MAX) || (QK_TAP_DANCE <= keycode && keycode <= QK_TAP_DANCE_MAX)) && (record->tap.count)) {
        keycode = keycode & 0xFF;
    };
    switch (keycode) {
        case KC_1 ... KC_0:
        case KC_COMM:
        case KC_DOT:
        case KC_BSPC:
        case KC_DEL:
        case MINUS:
        case PLUS:
        case SLSH:
        case ASTR:
        case BASE_ENT: // This keycode sends ent and then clears layer. Using this to avoid sending the alpha key from base on keypress
            // Don't disable for above keycodes
            break;
        default:
            if (record->event.pressed) {
                disable_num_word();
            }
    }
    return true;
}
