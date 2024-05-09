#ifdef TAP_DANCE_ENABLE
#    include QMK_KEYBOARD_H
#    include "features/tap_dance.h"

#    ifdef CUSTOM_ONESHOT_ENABLE
#        include "features/nshot.h"
#    endif
#    ifdef UNIVERSAL_OS_KEYS_ENABLE
#        include "features/os_keys.h"
#    endif

int cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        // key has not been interrupted, but they key is still held. Means you want to send a 'HOLD'.
        else
            return SINGLE_HOLD;
    } else if (state->count == 2) {
        /*
         * DOUBLE_SINGLE_TAP is to distinguish between typing "pepper", and actually wanting a double tap
         * action when hitting 'pp'. Suggested use case for this return value is when you want to send two
         * keystrokes of the key, and not the 'double tap' action/macro.
         */
        if (state->interrupted)
            return DOUBLE_SINGLE_TAP;
        else if (state->pressed)
            return DOUBLE_HOLD;
        else
            return DOUBLE_TAP;
    }
    // Assumes no one is trying to type the same letter three times (at least not quickly).
    // If your tap dance key is 'KC_W', and you want to type "www." quickly - then you will need to add
    // an exception here to return a 'TRIPLE_SINGLE_TAP', and define that enum just like 'DOUBLE_SINGLE_TAP'
    if (state->count == 3) {
        if (state->interrupted || !state->pressed)
            return TRIPLE_TAP;
        else
            return TRIPLE_HOLD;
    } else
        return 8; // magic number. At some point this method will expand to work for more presses
}

// instanalize an instance of 'tap' for the 'x' tap dance.
static tap xtap_state = {.is_press_action = true, .state = 0};

void nav_finished(qk_tap_dance_state_t *state, void *user_data) {
    xtap_state.state = cur_dance(state);
    switch (xtap_state.state) {
        case SINGLE_TAP:
            register_code(KC_SPC);
            break;
        case SINGLE_HOLD:
            if (is_mac()) {
                // del entire sentence
                layer_on(_NAV_MAC);
            } else {
                // del one word
                layer_on(_NAV_WIN);
            }
            break;
        case DOUBLE_TAP:
        case DOUBLE_SINGLE_TAP:
            tap_code(KC_SPC);
            register_code(KC_SPC);
        case TRIPLE_TAP:
            tap_code(KC_SPC);
            tap_code(KC_SPC);
            register_code(KC_SPC);
        default:
            register_code(KC_SPC);
    }
}

void nav_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (xtap_state.state) {
        case SINGLE_TAP:
            unregister_code(KC_SPC);
            break;
        case SINGLE_HOLD:
            if (is_mac()) {
                // del entire sentence
                layer_off(_NAV_MAC);
            } else {
                // del one word
                layer_off(_NAV_WIN);
            }
            break;
        case DOUBLE_TAP:
        case DOUBLE_SINGLE_TAP:
        case TRIPLE_TAP:
            unregister_code(KC_SPC);
        default:
            unregister_code(KC_SPC);
    }
    xtap_state.state = 0;
}

// clang-format off
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_SPC_NAV] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, nav_finished, nav_reset),

};
// clang-format on
#endif