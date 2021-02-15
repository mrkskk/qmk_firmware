#include "mrkskk.h"

// Required for eeprom config  function
// eeprom config

// called when EEPROM is getting reset!

user_config_t user_config;

void eeconfig_init_user(void) {
  user_config.raw = 0;
  // default to mac
  user_config.os_win_mac = true;
  user_config.rgb_layer_change = true;
  // Write default value to EEPROM now
  eeconfig_update_user(user_config.raw);
}
#if defined(UNICODEMAP_ENABLE)
void toggle_unicode_mode(void) {
  if (user_config.os_win_mac) {
    set_unicode_input_mode(UC_MAC);
  } else {
    set_unicode_input_mode(UC_WIN);
  }
}
#endif

void toggle_os(keyrecord_t *record) {
  // Toggle within event.pressed to ensure this is called only once
  if (record->event.pressed) {
    user_config.os_win_mac = !user_config.os_win_mac;
    eeconfig_update_user(user_config.raw);
#if defined(UNICODEMAP_ENABLE)
    toggle_unicode_mode();
#endif
  }
}

void keyboard_post_init_user(void) {

  user_config.raw = eeconfig_read_user();
#if defined(UNICODEMAP_ENABLE)
  toggle_unicode_mode();
#endif
}
