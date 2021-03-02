#include "mrkskk.h"

bool is_windows(void) {
    return keymap_config.swap_lctl_lgui;
}

bool is_mac(void) {
    return !is_windows();
}

/*
#if defined(UNICODEMAP_ENABLE)
static void toggle_unicode_mode(void) {
  if (is_mac()) {
    set_unicode_input_mode(UC_MAC);
  } else {
    set_unicode_input_mode(UC_WIN);
  }
}
#endif
*/