// This code unifies keycodes that differ between ISO-DK MacOS and ISO-DK Windows OS (Or two layouts of your choosing)

// It uses the boolean value is_windows that is set to true/false manually with the keycode TG_OS
// The keycodes themselves are found in "oskeys.def", To make reading and modyfying easier

#include "features/os_keys.h"
#include "os_detection.h"
#include "eeconfig.h"

#ifdef UNIVERSAL_OS_KEYS_ENABLE
// Manual OS switching logic (existing code)
bool is_windows(void) {
    // Both swaps should be in sync, so just check one
    return keymap_config.swap_lctl_lgui;
}

bool is_mac(void) {
    return !is_windows();
}
#endif

#ifdef OS_DETECTION_ENABLE
// Variables for auto-detection with manual override
static bool manual_override          = false;
static bool manual_os_is_windows     = false;
static bool last_detected_os_windows = false;
static bool initialized              = false;

void initialize_os_detection(void) {
    if (initialized) return;

    // Wait a bit for OS detection to complete
    if (detected_host_os() == OS_UNSURE) {
        return; // Not ready yet, will try again next time
    }

    initialized              = true;
    bool os_is_windows       = (detected_host_os() == OS_WINDOWS);
    last_detected_os_windows = os_is_windows;

    // Only update keymap config if not manually overridden
    if (!manual_override) {
        keymap_config.swap_lctl_lgui = os_is_windows;
        keymap_config.swap_rctl_rgui = os_is_windows;
        eeconfig_update_keymap(&keymap_config);
    }
}

void toggle_os_manually(void) {
    manual_override      = true;
    manual_os_is_windows = !manual_os_is_windows;

    // Set keymap config based on manually toggled setting
    keymap_config.swap_lctl_lgui = manual_os_is_windows;
    keymap_config.swap_rctl_rgui = manual_os_is_windows;
    eeconfig_update_keymap(&keymap_config);
}

void reset_to_auto_detection(void) {
    manual_override = false;

    // Reset to auto-detected state
    bool os_is_windows           = (detected_host_os() == OS_WINDOWS);
    keymap_config.swap_lctl_lgui = os_is_windows;
    keymap_config.swap_rctl_rgui = os_is_windows;
    eeconfig_update_keymap(&keymap_config);
}

bool is_windows(void) {
    // Initialize OS detection if not done yet
    if (!initialized) {
        initialize_os_detection();
    }

    if (manual_override) {
        return manual_os_is_windows;
    } else {
        // Check if detected OS changed
        bool current_os_is_windows = (detected_host_os() == OS_WINDOWS);
        if (initialized && current_os_is_windows != last_detected_os_windows) {
            last_detected_os_windows     = current_os_is_windows;
            keymap_config.swap_lctl_lgui = current_os_is_windows;
            keymap_config.swap_rctl_rgui = current_os_is_windows;
            eeconfig_update_keymap(&keymap_config);
        }
        return current_os_is_windows;
    }
}

bool is_mac(void) {
    return !is_windows();
}

bool get_manual_override_status(void) {
    return manual_override;
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
