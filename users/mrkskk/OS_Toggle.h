#pragma once

typedef union {
	    uint32_t raw;
	    struct {
	        // win is false, mac is true
	        bool os_win_mac : 1;
	        bool rgb_layer_change: 1;
	    };
	} user_config_t;

	extern user_config_t user_config;

void eeconfig_init_user(void);
void toggle_unicode_mode(void);
void toggle_os(keyrecord_t *record);
void keyboard_post_init_user(void);