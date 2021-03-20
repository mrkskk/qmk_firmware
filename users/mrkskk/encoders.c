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
            case R_SYMBOLS:
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
            case L_SYMBOLS:
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
                // change window tabs.
                if (counterclockwise)
                {
                    if (!is_alt_tab_active)
                    {
                        is_alt_tab_active = true;
                        register_code((is_mac()) ? KC_LGUI : KC_LCTL);
                    }
                    alt_tab_timer = timer_read();
                    tap_code16(S(KC_TAB));
                }
                else
                {
                    tap_code16(KC_TAB);
                }
                break;
            default:
                // Scrolling
                if (counterclockwise)
                {
                    tap_code(KC_UP);
                    tap_code(KC_UP);
                    tap_code(KC_UP);
                }
                else
                {
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
