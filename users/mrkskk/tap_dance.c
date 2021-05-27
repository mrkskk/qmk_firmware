// clang-format on
#include "mrkskk.h"

static td_state_t td_state;

// Function to determine the current tapdance state
uint8_t cur_dance(qk_tap_dance_state_t *state);

// Determine the tapdance state to return
uint8_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed)
            return SINGLE_TAP;
        else
            return SINGLE_HOLD;
    }
    if (state->count == 2)
        return DOUBLE_SINGLE_TAP;
    else
        return 3;  // Any number higher than the maximum state value you return above
}

// Handle the possible states for each tapdance keycode you define:

void td_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case SINGLE_TAP:
            if (get_mods() & MOD_MASK_SHIFT) {
                register_code16(KC_DEL);
            } else {
                register_code16(KC_BSPC);
            }
            break;
        case SINGLE_HOLD:
            layer_on(SYMBOLS);
        case DOUBLE_SINGLE_TAP:
            break;
    }
}

void td_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case SINGLE_TAP:
            if (get_mods() & MOD_MASK_SHIFT) {
                unregister_code16(KC_DEL);
            } else {
                unregister_code16(KC_BSPC);
            }
            break;
        case SINGLE_HOLD:
            layer_off(SYMBOLS);
        case DOUBLE_SINGLE_TAP:
            break;
    }
}

// Handle the possible states for each tapdance keycode you define:

void space_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case SINGLE_TAP:
            register_code(KC_SPC);
            break;
        case SINGLE_HOLD:
            register_code(KC_LSFT);
            break;
        case DOUBLE_SINGLE_TAP:
            register_code(KC_DOT);
            register_code(KC_SPC);
            break;
    }
}

void space_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case SINGLE_TAP:
            unregister_code(KC_SPC);
            break;
        case SINGLE_HOLD:
            unregister_code(KC_LSFT);
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code(KC_DOT);
            unregister_code(KC_SPC);
            set_oneshot_mods(MOD_BIT(KC_LSFT));
            break;
    }
}
// Define `ACTION_TAP_DANCE_FN_ADVANCED()` for each tapdance keycode, passing in `finished` and `reset` functions
qk_tap_dance_action_t tap_dance_actions[] = {
    [SYM_D_B]   = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_finished, td_reset),
    [SPACE_DOT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, space_finished, space_reset),
};
