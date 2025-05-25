EXTRAFLAGS += -flto  # Link Time Optimization flag for compiler

#Current settings On
CAPS_WORD_ENABLE = yes         # Enables typing in UPPERCASE when double-tapping shift
COMBO_ENABLE = yes             # Enables chord key combinations (pressing multiple keys to trigger actions)
CUSTOM_ONESHOT_ENABLE = yes    # Custom one-shot implementation for modifier keys
EXTRAKEY_ENABLE = yes          # Enables media keys and system controls
LTO_ENABLE = yes               # Link Time Optimization - reduces firmware size
POINTING_DEVICE_ENABLE = yes   # Enables trackball/pointer functionality
REPEAT_ENABLE = no             # Custom key repeat functionality
UNIVERSAL_OS_KEYS_ENABLE = no  # Manual OS toggling for universal shortcuts (obsolete with OS_DETECTION_ENABLE)
MOUSEKEY_ENABLE = yes          # Keyboard control of mouse cursor and buttons
OS_DETECTION_ENABLE = yes      # Automatic OS detection for universal shortcuts

#Current settings Off
SENTENCE_CASE_ENABLE = no      # Custom functionality for sentence capitalization
AUDIO_ENABLE = no              # Audio output support for beeps/music
AUTO_SHIFT_ENABLE = no         # Auto-shift (long press for shift) functionality
BACKLIGHT_ENABLE = no          # LED backlight support
BLUETOOTH_ENABLE = no          # Bluetooth connectivity support
BOOTMAGIC_ENABLE = no          # Boot-time configuration without flashing
COMMAND_ENABLE = no            # Command line interface for debugging
CONSOLE_ENABLE = no            # Console for debugging
CUSTOM_MOD_ENABLE = no         # Custom modifier key behavior
FAUXCLICKY_ENABLE = no         # Simulated click sounds
GRAVE_ESC_ENABLE = no          # Esc when tapped, ~ when shifted
HAPTIC_ENABLE = no             # Haptic feedback support
HD44780_ENABLE = no            # Support for HD44780 LCD displays
JOYSTICK_ENABLE = no           # Joystick functionality
KEY_LOCK_ENABLE = no           # Key lock functionality
KEY_OVERRIDE_ENABLE = no       # Simple key overrides
LAYER_LOCK_ENABLE = no         # Custom layer lock keycode
LAYER_MODES_ENABLE = no        # Custom layer lock acting like caps word
LEADER_ENABLE = no             # Leader key sequences (like Vim)
MAGIC_ENABLE = no              # Magic commands (bootmagic without boot)
MAGIC_KEYCODE_ENABLE = no      # Magic keycodes
MIDI_ENABLE = no               # MIDI control
MUSIC_ENABLE = no              # Play simple tunes on keyboard
NKRO_ENABLE = no               # N-key rollover
RGB_MATRIX_ENABLE = no         # Per-key RGB LED matrix
RGBLIGHT_ENABLE = no           # RGB lighting support
SELECT_WORD_ENABLE = no        # Custom word selection
SLEEP_LED_ENABLE = no          # LED behavior when host is sleeping
SPACE_CADET_ENABLE = no        # Space Cadet feature (shift=parentheses)
SWAPPER_ENABLE = no            # Custom Alt+Tab implementation
TAP_DANCE_ENABLE = no          # Multiple actions on a single key
UNICODE_ENABLE = no            # Unicode character support
USBPD_ENABLE = no              # USB Power Delivery - may help with Apple Fn key
VIA_ENABLE = no                # VIA configurator support
WPM_ENABLE = no                # Words per minute calculation




#Including files
ifeq ($(strip $(CUSTOM_ONESHOT_ENABLE)), yes)
	OPT_DEFS += -DCUSTOM_ONESHOT_ENABLE
	SRC += features/nshot.c
endif
ifeq ($(strip $(UNIVERSAL_OS_KEYS_ENABLE)), yes)
	OPT_DEFS += -DUNIVERSAL_OS_KEYS_ENABLE
	SRC += features/os_keys.c
endif
ifeq ($(strip $(OS_DETECTION_ENABLE)), yes)
    OPT_DEFS += -DOS_DETECTION_ENABLE
    SRC += features/os_keys.c
endif
ifeq ($(strip $(SELECT_WORD_ENABLE)), yes)
	OPT_DEFS += -DSELECT_WORD_ENABLE
	SRC += features/select_word.c
endif
ifeq ($(strip $(COMBO_ENABLE)), yes)
	VPATH += keyboards/gboards # to make combo dictionary work
endif
ifeq ($(strip $(TAP_DANCE_ENABLE)), yes)
	SRC += features/tap_dance.c
endif
ifeq ($(strip $(LAYER_LOCK_ENABLE)), yes)
	OPT_DEFS += -DLAYER_LOCK_ENABLE
	SRC += features/layer_lock.c
endif
ifeq ($(strip $(SWAPPER_ENABLE)), yes)
	OPT_DEFS += -DSWAPPER_ENABLE
		SRC += features/swapper.c
endif
ifeq ($(strip $(LEADER_ENABLE)), yes)
	SRC += features/leader.c
endif
ifeq ($(strip $(CUSTOM_MOD_ENABLE)), yes)
	OPT_DEFS += -DCUSTOM_MOD_ENABLE
	SRC += features/custom_mod.c
endif

ifeq ($(strip $(LAYER_MODES_ENABLE)), yes)
	OPT_DEFS += -DLAYER_MODES_ENABLE
	SRC += features/layermodes.c
endif

ifeq ($(strip $(REPEAT_ENABLE)), yes)
	OPT_DEFS += -DREPEAT_ENABLE
endif

ifeq ($(strip $(SENTENCE_CASE_ENABLE)), yes)
	OPT_DEFS += -DSENTENCE_CASE_ENABLE
	SRC += features/sentence_case.c
endif

#ifeq ($(strip $(POINTING_DEVICE_MODES_ENABLE)), yes)
#	OPT_DEFS += -DPOINTING_DEVICE_MODES_ENABLE
#	SRC += features/POINTING_DEVICE_MODES_ENABLE.c
#endif
