
// This code unifies keycodes that differ between ISO-DK MacOS and ISO-DK Windows OS (Or two layouts of your choosing)

// It uses the boolean value is_windows that is set to true/false manually with the keycode TG_OS
// The keycodes themselves are found in "oskeys.def", To make reading and modyfying easier

#ifdef UNIVERSAL_OS_KEYS_ENABLE
#    include "features/os_keys.h"

bool is_windows(void) {
    return keymap_config.swap_lctl_lgui;
}

bool is_mac(void) {
    return !is_windows();
}
// It will default to is_mac

#    if defined(UNICODE_ENABLE)
static void toggle_unicode_mode(void) {
    if (is_mac()) {
        set_unicode_input_mode(UC_MAC);
    } else {
        set_unicode_input_mode(UC_WIN);
    }
}
#    endif
#endif