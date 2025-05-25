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
// Variables for auto-detection with manual override
static bool manual_override = false;
static bool manual_os_is_windows = false;

void toggle_os_manually(void) {
    manual_override = true;
    manual_os_is_windows = !manual_os_is_windows;
    
    // Set keymap config based on manually toggled setting
    keymap_config.swap_lctl_lgui = manual_os_is_windows;
}

void reset_to_auto_detection(void) {
    manual_override = false;
    
    // Reset to auto-detected state
    bool os_is_windows = (detected_host_os() == OS_WINDOWS);
    keymap_config.swap_lctl_lgui = os_is_windows;
}

bool is_windows(void) {
    if (manual_override) {
        return manual_os_is_windows;
    } else {
        bool os_is_windows = (detected_host_os() == OS_WINDOWS);
        
        // Toggle swap_lctl_lgui based on detected OS
        keymap_config.swap_lctl_lgui = os_is_windows;
        
        return os_is_windows;
    }
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
