// clang-format on
#ifdef ENCODER_ENABLE
#    include "mrkskk.h"
void encoder_update_user(uint8_t index, bool counterclockwise) {
    /**********************************************LEFT ENCODER***********************************************/
    if (index == 0) {
        switch (biton32(layer_state)) {
            case SYM_LAYER:
                // history scrubbing
                if (counterclockwise) {
                    tap_code16((is_mac()) ? G(KC_Z) : C(KC_Z));
                } else {
                    tap_code16((is_mac()) ? G(KC_Y) : C(KC_Y));
                }
                break;
            case NAV2_LAYER:
                // epic emr navigation
                if (counterclockwise) {
                    tap_code(KC_F7);
                } else {
                    tap_code(KC_F8);
                }
                break;
            default:
                // Scrolling
                if (counterclockwise) {
                    tap_code(KC_PGUP);
                } else {
                    tap_code(KC_PGDN);
                }
                break;
        }
        /**********************************************RIGHT ENCODER***********************************************/
    } else if (index == 1) {
        switch (biton32(layer_state)) {
            case NUM_LAYER:
                // Volume control.
                if (counterclockwise) {
                    tap_code(KC_VOLD);
                } else {
                    tap_code(KC_VOLU);
                }
                break;
            case NAV2_LAYER:
                // Move cursor left words. Hold shift to select while moving.
                if (counterclockwise) {
                    tap_code16((is_mac()) ? A(KC_LEFT) : C(KC_LEFT));
                } else {
                    tap_code16((is_mac()) ? A(KC_RIGHT) : C(KC_RIGHT));
                }
                break;
            default:
                // Scrolling left and right
                if (counterclockwise) {
                    tap_code(KC_LEFT);
                } else {
                    tap_code(KC_RGHT);
                }
                break;
        }
    }
}
#endif
