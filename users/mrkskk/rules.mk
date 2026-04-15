# Sorted feature settings for QMK rules.mk
# Features ON ( = yes )
CAPS_WORD_ENABLE = yes         # Enables typing in UPPERCASE when double-tapping shift
COMBO_ENABLE = yes             # Enables chord key combinations (pressing multiple keys to trigger actions)
EXTRAKEY_ENABLE = yes          # Enables media keys and system controls
LTO_ENABLE = yes               # Link Time Optimization - reduces firmware size
# Board-specific: override in each keyboard keymap rules.mk.
POINTING_DEVICE_ENABLE ?= no   # Enables trackball/pointer functionality
OS_DETECTION_ENABLE = yes      # Automatic OS detection for universal shortcuts
ADAPT_SHIFT_ENABLE = yes       # Adaptive shift - comma then letter = capitalized letter
SENTENCE_CASE_ENABLE = yes     # Custom functionality for sentence capitalization
MOUSEKEY_ENABLE = yes           # Keyboard control of mouse cursor and buttons


# Features OFF ( = no )
AUDIO_ENABLE = no              # Audio output support for beeps/music
AUTO_SHIFT_ENABLE = no         # Auto-shift (long press for shift) functionality
BACKLIGHT_ENABLE = no          # LED backlight support
BLUETOOTH_ENABLE = no          # Bluetooth connectivity support
BOOTMAGIC_ENABLE = no          # Boot-time configuration without flashing
COMMAND_ENABLE = no            # Command line interface for debugging
CONSOLE_ENABLE = no            # Console for debugging
CUSTOM_MOD_ENABLE = no         # Custom modifier key behavior
CUSTOM_ONESHOT_ENABLE = no     # Custom one-shot implementation for modifier keys
FAUXCLICKY_ENABLE = no         # Simulated click sounds
GRAVE_ESC_ENABLE = no          # Esc when tapped, ~ when shifted
HAPTIC_ENABLE = no             # Haptic feedback support
HD44780_ENABLE = no            # Support for HD44780 LCD displays
JOYSTICK_ENABLE = no           # Joystick functionality
KEY_LOCK_ENABLE = no           # Key lock functionality
KEY_OVERRIDE_ENABLE = yes       # Simple key overrides
LAYER_LOCK_ENABLE = no         # Custom layer lock keycode
LAYER_MODES_ENABLE = no        # Custom layer lock acting like caps word
LEADER_ENABLE = no             # Leader key sequences (like Vim)
MAGIC_ENABLE = no              # Magic commands (bootmagic without boot)
MAGIC_KEYCODE_ENABLE = no      # Magic keycodes
MIDI_ENABLE = no               # MIDI control
NKRO_ENABLE = no               # N-key rollover
OS_DETECTION_DEBUG_ENABLE = no # Disable OS detection debugging
POINTING_DEVICE_MODES_ENABLE = no  # Custom modes for pointing devices
RAW_ENABLE = no                # Enable RAW HID support
REPEAT_ENABLE = no             # Custom key repeat functionality
RGB_MATRIX_ENABLE = no         # Per-key RGB LED matrix
RGBLIGHT_ENABLE = no           # RGB lighting support
SELECT_WORD_ENABLE = no        # Custom word selection
SLEEP_LED_ENABLE = no          # LED behavior when host is sleeping
SPACE_CADET_ENABLE = no        # Space Cadet feature (shift=parentheses)
SWAPPER_ENABLE = no            # Custom Alt+Tab implementation
TAP_DANCE_ENABLE = no          # Multiple actions on a single key
UNICODE_ENABLE = no            # Unicode character support
UNIVERSAL_OS_KEYS_ENABLE = no  # Manual OS toggling for universal shortcuts (obsolete with OS_DETECTION_ENABLE)
USBPD_ENABLE = no              # USB Power Delivery - may help with Apple Fn key
VIA_ENABLE = no                # VIA configurator support
WPM_ENABLE = no                # Words per minute calculation

ifeq ($(strip $(UNIVERSAL_OS_KEYS_ENABLE)), yes)
	OPT_DEFS += -DUNIVERSAL_OS_KEYS_ENABLE
	SRC += $(USER_PATH)/features/os_keys.c
endif
ifeq ($(strip $(OS_DETECTION_ENABLE)), yes)
    OPT_DEFS += -DOS_DETECTION_ENABLE
    SRC += $(USER_PATH)/features/os_keys.c
endif
ifeq ($(strip $(SELECT_WORD_ENABLE)), yes)
	OPT_DEFS += -DSELECT_WORD_ENABLE
	SRC += $(USER_PATH)/features/select_word.c
endif
ifeq ($(strip $(COMBO_ENABLE)), yes)
	VPATH += keyboards/gboards # to make combo dictionary work
endif
ifeq ($(strip $(TAP_DANCE_ENABLE)), yes)
	SRC += $(USER_PATH)/features/tap_dance.c
endif
ifeq ($(strip $(LAYER_LOCK_ENABLE)), yes)
	OPT_DEFS += -DLAYER_LOCK_ENABLE
	SRC += $(USER_PATH)/features/layer_lock.c
endif
ifeq ($(strip $(SWAPPER_ENABLE)), yes)
	OPT_DEFS += -DSWAPPER_ENABLE
		SRC += $(USER_PATH)/features/swapper.c
endif
ifeq ($(strip $(LEADER_ENABLE)), yes)
	SRC += $(USER_PATH)/features/leader.c
endif
ifeq ($(strip $(CUSTOM_MOD_ENABLE)), yes)
	OPT_DEFS += -DCUSTOM_MOD_ENABLE
	SRC += $(USER_PATH)/features/custom_mod.c
endif

ifeq ($(strip $(LAYER_MODES_ENABLE)), yes)
	OPT_DEFS += -DLAYER_MODES_ENABLE
	SRC += $(USER_PATH)/features/layermodes.c
endif

ifeq ($(strip $(REPEAT_ENABLE)), yes)
	OPT_DEFS += -DREPEAT_ENABLE
endif

ifeq ($(strip $(SENTENCE_CASE_ENABLE)), yes)
	OPT_DEFS += -DSENTENCE_CASE_ENABLE
	SRC += $(USER_PATH)/features/sentence_case.c
endif

ifeq ($(strip $(ADAPT_SHIFT_ENABLE)), yes)
	OPT_DEFS += -DADAPT_SHIFT_ENABLE
	SRC += $(USER_PATH)/features/adapt_shift.c
endif

#ifeq ($(strip $(POINTING_DEVICE_MODES_ENABLE)), yes)
#	OPT_DEFS += -DPOINTING_DEVICE_MODES_ENABLE
#	SRC += features/POINTING_DEVICE_MODES_ENABLE.c
#endif
