// clang-format on
#pragma once

// Tap Dance keycodes
enum td_keycodes {
    SYM_D_B,
};

// Define a type containing as many tapdance states as you need
typedef enum {
    SINGLE_TAP,
    SINGLE_HOLD,
    // DOUBLE_SINGLE_TAP,
} td_state_t;

void td_finished(qk_tap_dance_state_t *state, void *user_data);
void td_reset(qk_tap_dance_state_t *state, void *user_data);
