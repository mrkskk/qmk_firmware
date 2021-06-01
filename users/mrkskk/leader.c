// clang-format on
/*
#include "mrkskk.h"

LEADER_EXTERNS();
bool did_leader_succeed;

void matrix_scan_leader(void) {
    LEADER_DICTIONARY() {
        did_leader_succeed = leading = false;

        SEQ_ONE_KEY(KC_SPC) {
            did_leader_succeed = true;
            tap_code(KC_DOT);
            tap_code(KC_SPC);
            set_oneshot_mods(MOD_BIT(KC_LSFT));
        }
        leader_end();
        // which os

                SEQ_TWO_KEYS(KC_O, KC_S) {
                    send_string((is_mac()) ? "MacOS" : "Windows");
                    send_string(SS_DELAY(500));
                    tap_code16((is_mac()) ? LALT(KC_BSPC) : LCTL(KC_BSPC));
                }

    }
}
void leader_end(void) {
    if (did_leader_succeed) {
        // If any sequence was matched, did_leader_succeed will have
        // been set to true up in the matrix_scan_user function.
        // Put your code for a matched leader key sequence here.
    } else {
        tap_code(KC_DOT);
        // If no sequence was matched, did_leader_succeed will not
        // have been set to true anywhere, so we'll end up here.
        // Put your code for an unmatched leader key sequence here.
    }
}
*/
