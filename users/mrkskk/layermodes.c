#include "layermodes.h"
#include "mrkskk.h"

static uint16_t num_word_timer;
static bool _num_word_enabled = false;
bool num_word_enabled(void) {
    return _num_word_enabled;
}
void enable_num_word(void) {
    _num_word_enabled = true;
    layer_on(NUM_LAYER );
}
void disable_num_word(void) {
    _num_word_enabled = false;
    layer_off(NUM_LAYER );
}
void process_num_word_activation(const keyrecord_t *record) {
    if (record->event.pressed) {
        layer_on(NUM_LAYER);
        num_word_timer = timer_read();
    } else {
        if (timer_elapsed(num_word_timer) < TAPPING_TERM) {
            // Tapping enables NUMWORD
            _num_word_enabled = true;
        } else {
            // Holding turns off NUM when released
            layer_off(NUM_LAYER );
        }
    }
}
bool process_num_word(uint16_t keycode, const keyrecord_t *record) {
    if (!_num_word_enabled) return true;

    switch (keycode) {
        case QK_MOD_TAP ... QK_MOD_TAP_MAX:
        case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
        case QK_TAP_DANCE ... QK_TAP_DANCE_MAX:
            if (record->tap.count == 0)
                return true;
            keycode = keycode & 0xFF;
    }
    switch (keycode) {
        case KC_P1 ... KC_P0:
        case LABK:
        case LCB: 
        case PLUS:
        case RCB: 
        case RABK:
        case ASTR:
        case LPRN:
        case MINUS: 
        case RPRN: 
        case S_SLSH:
        case LBRC:
        case KC_PDOT:
        case RBRC:
        case KC_BSPC:
            // Don't disable for above keycodes
            break;
        case TO_BASE:
            if (record->event.pressed) {
                disable_num_word();
            }
            return false;
        default:
            if (record->event.pressed) {
                disable_num_word();
            }
    }
    return true;
}
