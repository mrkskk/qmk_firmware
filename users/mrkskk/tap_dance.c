// clang-format on
#include "mrkskk.h"
#include "mymod.h"
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
                tap_code(KC_DEL);
            } else {
                tap_code(KC_BSPC);
            }
            break;
        case SINGLE_HOLD:
            layer_on(MOUSE_LAYER);
        case DOUBLE_SINGLE_TAP:
            break;
    }
}

void td_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case SINGLE_TAP:
        case SINGLE_HOLD:
            layer_off(MOUSE_LAYER);
        case DOUBLE_SINGLE_TAP:
            break;
    }
}

// Handle the possible states for each tapdance keycode you define:

void lt_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case SINGLE_TAP:
            if (my_mod_enabled()) {  // paste
                tap_code16((is_mac()) ? LGUI(KC_V) : LCTL(KC_V));
            } else {  // copy
                tap_code16((is_mac()) ? LGUI(KC_C) : LCTL(KC_C));
            }
            break;
        case SINGLE_HOLD:
            layer_on(LEFTNAVCLUSTER_LAYER);
            break;
        case DOUBLE_SINGLE_TAP:
            break;
    }
}

void lt_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case SINGLE_TAP:
            // unregister_code(KC_E);
            break;
        case SINGLE_HOLD:
            layer_off(LEFTNAVCLUSTER_LAYER);
            break;
        case DOUBLE_SINGLE_TAP:
            break;
    }
}

// Define `ACTION_TAP_DANCE_FN_ADVANCED()` for each tapdance keycode, passing in `finished` and `reset` functions
qk_tap_dance_action_t tap_dance_actions[] = {
    [MOUSE_D_B]          = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_finished, td_reset),
    [LEFTNAV_COPY_PASTE] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, lt_finished, lt_reset),

};
