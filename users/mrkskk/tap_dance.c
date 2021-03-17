#include  "mrkskk.h"

static td_state_t td_state;


// Function to determine the current tapdance state
uint8_t cur_dance(qk_tap_dance_state_t *state);


// Determine the tapdance state to return
uint8_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    }

    //if (state->count == 2) return DOUBLE_SINGLE_TAP;
    else return 3; // Any number higher than the maximum state value you return above
}

// Handle the possible states for each tapdance keycode you define:


    //LEADER and layer key
    void splead_finished(qk_tap_dance_state_t *state, void *user_data) {
        td_state = cur_dance(state);
        switch (td_state) {
            case SINGLE_TAP:
            #if defined(LEADER_ENABLE)
                qk_leader_start();
            #endif
                break;
            case SINGLE_HOLD:
            if (is_mac()){
                register_mods(MOD_BIT(KC_LCTRL) | MOD_BIT(KC_LALT) | MOD_BIT(KC_LGUI));
                }else{
                  layer_on(SHORTCUTS);
                } //Hold Ctrl lAlt and gui (to activate hammerspoon keybinds) 
                break;
            /*case DOUBLE_SINGLE_TAP: // Allow nesting of 2 parens `((` within tapping term
                tap_code16(KC_LPRN);
                register_code16(KC_LPRN);*/
        }
    }

    void splead_reset(qk_tap_dance_state_t *state, void *user_data) {
        switch (td_state) {
            case SINGLE_TAP:
            #if defined(LEADER_ENABLE)
                leader_end();
            #endif
                break;
            case SINGLE_HOLD:
                if (is_mac()){
                unregister_mods(MOD_BIT(KC_LCTRL) | MOD_BIT(KC_LALT) | MOD_BIT(KC_LGUI));
                }else{
                  layer_off(SHORTCUTS);
                } // For a layer-tap key, use `layer_off(_MY_LAYER)` here
                break;
          /*  case DOUBLE_SINGLE_TAP:
                unregister_code16(KC_LPRN);*/
        }
    }

    

// Define `ACTION_TAP_DANCE_FN_ADVANCED()` for each tapdance keycode, passing in `finished` and `reset` functions
qk_tap_dance_action_t tap_dance_actions[] = {
    [SPLEAD] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, splead_finished, splead_reset),
};


