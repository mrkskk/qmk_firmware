// clang-format on
#ifdef TAP_DANCE_ENABLE
#    pragma once
#    include "defines.h"

typedef struct {
    bool is_press_action;
    int  state;
} tap;

enum {
    SINGLE_TAP        = 1,
    SINGLE_HOLD       = 2,
    DOUBLE_TAP        = 3,
    DOUBLE_HOLD       = 4,
    DOUBLE_SINGLE_TAP = 5, // send two single taps
    TRIPLE_TAP        = 6,
    TRIPLE_HOLD       = 7
};

// Tap dance enums
enum {
    TD_SPC_NAV = 0,
    // TD_CURLYBRACKET = 0,
    // TD_SQUAREBRACKET,
    // TD_LTGT,
    // TD_DQUO,
    // TD_PRN,
};

int cur_dance(qk_tap_dance_state_t *state);

void nav_finished(qk_tap_dance_state_t *state, void *user_data);
void nav_reset(qk_tap_dance_state_t *state, void *user_data);

#    define NAV_SPC TD(TD_SPC_NAV)

#endif