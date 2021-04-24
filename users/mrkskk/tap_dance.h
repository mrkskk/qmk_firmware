#pragma once

// Tap Dance keycodes
enum td_keycodes {
    SPLEAD, // Our example key: `LALT` when held, `(` when tapped. Add additional keycodes for each tapdance.
};

// Define a type containing as many tapdance states as you need
typedef enum {
    SINGLE_TAP,
    SINGLE_HOLD,
    //DOUBLE_SINGLE_TAP,
} td_state_t;

void splead_finished(qk_tap_dance_state_t *state, void *user_data);
void splead_reset(qk_tap_dance_state_t *state, void *user_data);
