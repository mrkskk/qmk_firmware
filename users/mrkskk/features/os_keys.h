// clang-format on

#pragma once
#include QMK_KEYBOARD_H

// Common functions for both operating modes
bool is_windows(void);
bool is_mac(void);

#ifdef OS_DETECTION_ENABLE
// Functions for auto-detection with manual override
void initialize_os_detection(void);
void toggle_os_manually(void);
void reset_to_auto_detection(void);
bool get_manual_override_status(void);
#endif

// Unicode mode functions
#if defined(UNICODE_ENABLE)
static void toggle_unicode_mode(void);
#endif
