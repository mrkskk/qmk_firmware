// This code unifies keycodes that differ between ISO-DK MacOS and ISO-DK Windows OS (Or two layouts of your choosing)

// It uses the boolean value is_windows that is set to true/false manually with the keycode TG_OS
// The keycodes themselves are found in "oskeys.def", To make reading and modyfying easier

#include "features/os_keys.h"
#include "os_detection.h"

#ifdef UNIVERSAL_OS_KEYS_ENABLE
// Manual OS switching logic (existing code)
bool is_windows(void) {
    return keymap_config.swap_lctl_lgui;
}

bool is_mac(void) {
    return !is_windows();
}
#endif

#ifdef OS_DETECTION_ENABLE
// Automatic OS detection
bool is_windows(void) {
    bool os_is_windows = (detected_host_os() == OS_WINDOWS);

    // Toggle swap_lctl_lgui based on detected OS
    if (os_is_windows) {
        keymap_config.swap_lctl_lgui = true;
    } else {
        keymap_config.swap_lctl_lgui = false;
    }

    return os_is_windows;
}

bool is_mac(void) {
    return !is_windows();
}
#endif

// Common code for both operating modes
#if defined(UNICODE_ENABLE)
static void toggle_unicode_mode(void) {
    if (is_mac()) {
        set_unicode_input_mode(UC_MAC);
    } else {
        set_unicode_input_mode(UC_WIN);
    }
}
#endif
