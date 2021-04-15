#include "mrkskk.h"

// For the alt tab macro (rotary encoder)
bool     is_alt_tab_active = false;
uint16_t alt_tab_timer     = 0;

void matrix_scan_encoders(void)
{
    if (is_alt_tab_active)
    {
        if (timer_elapsed(alt_tab_timer) > 750)
        {
            unregister_code(KC_LALT);
            unregister_code(KC_LGUI);
            is_alt_tab_active = false;
        }
    }
}

/*ROTARY ENCODER functions
*******************
*******************/

#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool counterclockwise)
{
/**********************************************LEFT ENCODER***********************************************/
if (index == 0)
    {
        switch (biton32(layer_state))
            {
            case SYMBOLS:
                // history scrubbing
                if (counterclockwise)
                {
                    tap_code16((is_mac()) ? G(KC_Z) : C(KC_Z));
                }
                else
                {
                    tap_code16((is_mac()) ? G(KC_Y) : C(KC_Y));
                }
                break;
            case NAV:
            // epic emr navigation
                if (counterclockwise)
                {
                    tap_code(KC_F7);
                }
                else
                {
                    tap_code(KC_F8);
                }
                break;
            default:
                // Scrolling
                if (counterclockwise)
                {
                    tap_code(KC_UP);
                    tap_code(KC_UP);
                    tap_code(KC_UP);
                    tap_code(KC_UP);
                    tap_code(KC_UP);
                    tap_code(KC_UP);
                    tap_code(KC_UP);
                    tap_code(KC_UP);
                    tap_code(KC_UP);
                    tap_code(KC_UP);
                    tap_code(KC_UP);
                }
                else
                {
                    tap_code(KC_DOWN);
                    tap_code(KC_DOWN);
                    tap_code(KC_DOWN);
                    tap_code(KC_DOWN);
                    tap_code(KC_DOWN);
                    tap_code(KC_DOWN);
                    tap_code(KC_DOWN);
                    tap_code(KC_DOWN);
                    tap_code(KC_DOWN);
                    tap_code(KC_DOWN);
                    tap_code(KC_DOWN);
                }
                break;
            }
/**********************************************RIGHT ENCODER***********************************************/
}
else if (index == 1)
    {
        switch (biton32(layer_state))
            {
            case NUMPAD:
                // Volume control.
                if (counterclockwise)
                {
                    tap_code(KC_VOLD);
                }
                else
                {
                    tap_code(KC_VOLU);
                }
                break;
            case NAV:
             // Move cursor left words. Hold shift to select while moving.
            if (counterclockwise)
                {
                    tap_code16((is_mac()) ? A(KC_LEFT) : C(KC_LEFT));
                }
                else
                {
                    tap_code16((is_mac()) ? A(KC_RIGHT) : C(KC_RIGHT));
                }
                break;
            case NAV2:
             // Move cursor left words. Hold shift to select while moving.
            if (counterclockwise)
                {
                    tap_code16((is_mac()) ? LALT(S(KC_LEFT)) : LCTL(S(KC_LEFT)));
                }
                else
                {
                    tap_code16((is_mac()) ? LALT(S(KC_RIGHT)) : LCTL(S(KC_RIGHT)));
                }
                break;
            default:
                // Scrolling left and right
                if (counterclockwise)
                {
                    tap_code(KC_LEFT);
                }
                else
                {
                    tap_code(KC_RGHT);
                }
                break;
            }
        }
}
#endif
