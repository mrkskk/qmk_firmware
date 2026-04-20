#include QMK_KEYBOARD_H
#include "quantum.h"

#include "mrkskk.h"



#if defined(OS_DETECTION_ENABLE)
#    include "os_detection.h"
#endif

#if defined(UNIVERSAL_OS_KEYS_ENABLE) || defined(OS_DETECTION_ENABLE)
#    include "features/os_keys.h"
#endif

#ifdef KEY_OVERRIDE_ENABLE
#    include "features/key_overrides.c"
#endif

#ifdef ADAPT_SHIFT_ENABLE
#    include "features/adapt_shift.h"
#endif

#if (__has_include("features/secrets.h"))
#    include "features/secrets.h"
#else
const char secrets[][64] = {"test1", "test2", "test3", "test4", "test5", "test6"};
#endif

#if defined(CAPS_WORD_ENABLE)
bool caps_word_lock_on;
bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        case KC_A ... KC_Z:
            add_weak_mods(MOD_BIT(KC_LSFT));
            return true;
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case NUM:
        case UNDSC:
        case MINUS:
            return true;
        default:
            return false;
    }
}
#endif

#if defined(UNIVERSAL_OS_KEYS_ENABLE) || defined(OS_DETECTION_ENABLE)
#    undef OSKEY
#    define OSKEY(name, windows, mac) \
        case name:                    \
            tap_os_key(windows, mac, pressed); \
            break;

void tap_os_key(uint16_t win_keycode, uint16_t mac_keycode, bool pressed) {
    if (pressed) {
        tap_code16(is_windows() ? win_keycode : mac_keycode);
    }
}
#endif

uint8_t last_modifier = 0;
uint8_t mod_state     = 0;

#ifdef REPEAT_ENABLE
#    define GET_TAP_KC(dual_role_key) dual_role_key & 0xFF

uint16_t last_keycode    = KC_NO;
uint16_t pressed_keycode = KC_NO;

void process_repeat_key(uint16_t keycode, const keyrecord_t *record) {
    if (keycode != REPEAT) {
        switch (keycode) {
            case QK_DEF_LAYER ... QK_DEF_LAYER_MAX:
            case QK_MOMENTARY ... QK_MOMENTARY_MAX:
            case QK_LAYER_MOD ... QK_LAYER_MOD_MAX:
            case QK_ONE_SHOT_LAYER ... QK_ONE_SHOT_LAYER_MAX:
            case QK_TOGGLE_LAYER ... QK_TOGGLE_LAYER_MAX:
            case QK_TO ... QK_TO_MAX:
            case QK_LAYER_TAP_TOGGLE ... QK_LAYER_TAP_TOGGLE_MAX:
            case QK_MODS ... QK_MODS_MAX:
            case NAV:
                return;
        }
        if (record->event.pressed) {
            last_modifier = get_mods();
            switch (keycode) {
                case QK_LAYER_TAP ... QK_LAYER_TAP_MAX:
                case QK_MOD_TAP ... QK_MOD_TAP_MAX:
                    last_keycode = GET_TAP_KC(keycode);
                    break;
                default:
                    last_keycode = keycode;
                    break;
            }
        }
    } else {
        if (record->event.pressed) {
            pressed_keycode = last_keycode;
            register_mods(last_modifier);
            register_code16(pressed_keycode);
            unregister_mods(last_modifier);
        } else {
            unregister_code16(pressed_keycode);
        }
    }
}
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef REPEAT_ENABLE
    process_repeat_key(keycode, record);
#endif

#ifdef ADAPT_SHIFT_ENABLE
    if (!process_adapt_shift(keycode, record)) {
        return false;
    }
#endif

#ifdef SELECT_WORD_ENABLE
    if (!process_select_word_right(keycode, record, S_R_WRD)) {
        return false;
    }
    if (!process_select_word_left(keycode, record, S_L_WRD)) {
        return false;
    }
#endif

#ifdef LAYER_LOCK_ENABLE
    if (!process_layer_lock(keycode, record, LLOCK)) {
        return false;
    }
#endif

#ifdef CUSTOM_ONESHOT_ENABLE
    process_nshot_state(keycode, record);
#endif

#ifdef SWAPPER_ENABLE
    process_swappers(keycode, record);
#endif

#ifdef LAYER_MODES_ENABLE
    if (!process_num_word(keycode, record)) {
        return false;
    }
#endif

#ifdef SENTENCE_CASE_ENABLE
    if (!process_sentence_case(keycode, record)) {
        return false;
    }
#endif

    const bool pressed = record->event.pressed;
    switch (keycode) {
#if defined(UNIVERSAL_OS_KEYS_ENABLE) || defined(OS_DETECTION_ENABLE)
#    include "features/os_keys.def"
#endif
        break;
        case TG_OS:
            if (record->event.pressed) {
#ifdef OS_DETECTION_ENABLE
                toggle_os_manually();
#else
                keymap_config.swap_lctl_lgui = !keymap_config.swap_lctl_lgui;
                eeconfig_update_keymap(keymap_config.raw);
#endif

                clear_keyboard();
                send_string((is_mac()) ? "Mac" : "Win");
                send_string(SS_DELAY(800));

                for (int i = 0; i < 3; i++) {
                    tap_code(KC_BSPC);
                }
            }
            break;
        case OS_RESET:
            if (record->event.pressed) {
#ifdef OS_DETECTION_ENABLE
                reset_to_auto_detection();
                clear_keyboard();
                send_string("OS DetectionReset");
                send_string(SS_DELAY(800));

                for (int i = 0; i < 17; i++) {
                    tap_code(KC_BSPC);
                }
#endif
            }
            break;
#ifdef OS_DETECTION_DEBUG_ENABLE
        case OS_DEBUG:
            if (record->event.pressed) {
            }
            break;
#endif
        case KC_SECRET_1 ... KC_SECRET_3:
            if (!record->event.pressed) {
                send_string(secrets[keycode - KC_SECRET_1]);
            }
            break;
        case LOGIN:
            if (record->event.pressed) {
                send_string(secrets[0]);
                send_string(SS_DELAY(30));
                tap_code(KC_TAB);
                send_string(SS_DELAY(30));
                send_string(secrets[1]);
                send_string(SS_DELAY(30));
            }
            break;
        case PERS_MAIL:
            if (record->event.pressed) {
                send_string(secrets[4]);
                send_string(SS_DELAY(5));
                if (is_mac()) {
                    tap_code16(A(QUOT));
                } else {
                    tap_code16(ALGR(KC_2));
                }
                send_string(secrets[5]);
            }
            break;
        case WORK_MAIL:
            if (record->event.pressed) {
                send_string(secrets[2]);
                send_string(SS_DELAY(5));
                if (is_mac()) {
                    tap_code16(A(QUOT));
                } else {
                    tap_code16(ALGR(KC_2));
                }
                send_string(secrets[3]);
            }
            break;
        case TILDE_ND:
            if (record->event.pressed) {
                send_string("~");
            }
            break;
        case MEH_CARET:
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    SEND_STRING("^");
                }
                return false;
            }
            return true;

        case HYPR_USD:
            if (record->tap.count > 0) {
                if (record->event.pressed) {
                    tap_os_key(ALGR(KC_4), KC_GRAVE, true);
                }
                return false;
            }
            return true;
#ifdef LAYER_MODES_ENABLE
        case NUM:
            process_num_word_activation(record);
            return false;
#endif
#ifdef SENTENCE_CASE_ENABLE
        case TG_SENT:
            if (pressed) {
                sentence_case_toggle();

                clear_keyboard();
                if (is_sentence_case_on()) {
                    send_string("Sentence Case ON");
                } else {
                    send_string("Sentence Case OFF");
                }
                send_string(SS_DELAY(800));

                for (int i = 0; i < 16; i++) {
                    tap_code(KC_BSPC);
                }
            }
            break;
#endif
        case TO_BASE:
            if (pressed) {
                layer_clear();
                clear_mods();
            }
            break;
    }
    return true;
}

#ifdef COMBO_ENABLE
#    include "g/keymap_combo.h"

uint16_t get_combo_term(uint16_t index, combo_t *combo) {
    switch (index) {
        default:
            return COMBO_TERM;
    }
    return COMBO_TERM;
}
#endif

#ifdef POINTING_DEVICE_AUTO_MOUSE_ENABLE
void pointing_device_init_user(void) {
    set_auto_mouse_layer(_MOUSE);
    set_auto_mouse_enable(true);
}

bool is_mouse_record_kb(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SNIPING:
            return true;
        case TO_BASE:
            set_auto_mouse_enable(false);
            layer_on(_BASE);
            layer_clear();
            clear_mods();
            set_auto_mouse_enable(true);
            return false;
        default:
            return false;
    }
    return is_mouse_record_user(keycode, record);
}

#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = MRKSKK_LAYOUT(
        KC_W, KC_C, KC_G, KC_M, KC_J, QUOT, KC_U, KC_K, DK_OE, DK_AA,
        HM_LSFT, HM_LALT, HM_LCTL, HM_LGUI, KC_F, KC_Y, HM_RGUI, HM_RCTL, HM_RALT, HM_RSFT,
        FN_V, MEH_B, HYP_L, CAG_D, KC_X, KC_Z, CAG_P, HYP_COM, MEH_DOT, DK_AE,
        TG_MS, NUM_SPC, MO(_NAV_MAC), FN_BSPC, NUM_N, KC_NO),

    [_NAV_MAC] = MRKSKK_LAYOUT(
        UNDO, COPY, CBOARD, PASTE, REDO, KC_PGUP, _______, KC_UP, _______, KC_END,
        KC_LSFT, KC_LALT, KC_LCTL, KC_LGUI, KC_RALT, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_HOME,
        TG_MS, KC_MEH, KC_HYPR, KC_CAG, CW_TOGG, QUIT, KC_TAB, KC_ENT, KC_ESC, MAC_FN,
        TO_BASE, TO_BASE, TO_BASE, FN_BSPC, KC_DEL, KC_NO),

    [_MOUSE] = MRKSKK_LAYOUT(
        TO_BASE, TO_BASE, MS_WHLU, TO_BASE, TO_BASE, TO_BASE, TO_BASE, MS_UP, TO_BASE, TO_BASE,
        TO_BASE, MS_WHLL, MS_WHLD, MS_WHLL, TO_BASE, TO_BASE, MS_LEFT, MS_DOWN, MS_RGHT, TO_BASE,
        TO_BASE, MS_BTN2, PRE_MO, MS_BTN1, TO_BASE, TO_BASE, TO_BASE, TO_BASE, TO_BASE, TO_BASE,
        TO_BASE, TO_BASE, TO_BASE, TO_BASE, TO_BASE, KC_NO),

    [_NUMROW] = MRKSKK_LAYOUT(
        HAT, DIAE, GRAVE, ACUTE, TILDE, DQUO, LABK, MINUS, PLUS, RABK,
        HOME_7, HOME_5, HOME_1, HOME_3, KC_9, KC_0, HOME_4, HOME_2, HOME_6, HOME_8,
        TG(_NUM), MEH_CARET, HYPR_USD, CAG_9, PIPE, PARA, CAG_0, HYP_COM, MEH_DOT, KC_PDOT,
        TO_BASE, TO_BASE, TO_BASE, KC_BSPC, KC_0, KC_NO),

    [_NUM] = MRKSKK_LAYOUT(
        TO_BASE, KC_7, KC_8, KC_9, TO_BASE, TO_BASE, KC_7, KC_8, KC_9, TO_BASE,
        SFT_0, ALT_4, CTL_5, GUI_6, TO_BASE, TO_BASE, GUI_4, CTL_5, ALT_6, KC_LSFT,
        TO_BASE, MEH_1, HYPR_2, CAG_3, TO_BASE, TO_BASE, CAG_1, HYPR_2, MEH_3, KC_RALT,
        TO_BASE, KC_0, TO_BASE, KC_BSPC, KC_0, KC_NO),

    [_FNKEYS] = MRKSKK_LAYOUT(
        CA_DEL, KC_F7, KC_F8, KC_F9, KC_F12, TG_SENT, KC_MPRV, KC_MPLY, KC_MNXT, KC_INS,
        SCRSHOT, KC_F4, KC_F5, KC_F6, KC_F11, TG_OS, KC_LGUI, KC_LCTL, KC_LALT, KC_LSFT,
        _______, KC_F1, KC_F2, KC_F3, KC_F10, OS_RESET, KC_BRID, KC_BRIU, KC_ASST, _______,
        KC_MUTE, KC_VOLD, KC_VOLU, KC_VOLU, KC_VOLD, KC_NO),
};

#ifdef SENTENCE_CASE_ENABLE
void matrix_scan_user(void) {
#    ifdef OS_DETECTION_ENABLE
    initialize_os_detection();
#    endif
    sentence_case_task();
}
#else
void matrix_scan_user(void) {
#    ifdef OS_DETECTION_ENABLE
    initialize_os_detection();
#    endif
}
#endif

void keyboard_post_init_user(void) {}