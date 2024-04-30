
EXTRAFLAGS += -flto 

#Current settings On
AUTO_SHIFT_ENABLE = no
COMBO_ENABLE	      = yes
CUSTOM_ONESHOT_ENABLE = yes #custom one shot implementation
LTO_ENABLE = yes # Saves Space
MOUSEKEY_ENABLE	= no
REPEAT_ENABLE = yes #custom repeat key
SENTENCE_CASE_ENABLE = no #custom sentence key
UNIVERSAL_OS_KEYS_ENABLE = yes #custom OS toggling for universal shortcuts
EXTRAKEY_ENABLE = yes 
POINTING_DEVICE_ENABLE = yes #enables trackball

#Current settings Off
AUDIO_ENABLE = no
BACKLIGHT_ENABLE	= no
BLUETOOTH_ENABLE = no
BOOTMAGIC_ENABLE = no
CAPS_WORD_ENABLE = no
COMMAND_ENABLE = no
CONSOLE_ENABLE	= no
CUSTOM_MOD_ENABLE = no #custom "modifier"
EXTRAKEY_ENABLE = yes 
FAUXCLICKY_ENABLE = no
GRAVE_ESC_ENABLE = no
HAPTIC_ENABLE = no
HD44780_ENABLE = no
JOYSTICK_ENABLE = no
KEY_LOCK_ENABLE = no 
KEY_OVERRIDE_ENABLE	= no		# Enables simple key overrides. 
LAYER_LOCK_ENABLE = no #custom layer lock keycode
LAYER_MODES_ENABLE = no #custom layer lock  acting like caps word
LEADER_ENABLE = no
MAGIC_ENABLE = no
MAGIC_KEYCODE_ENABLE = no
MIDI_ENABLE	= no
MUSIC_ENABLE = no
NKRO_ENABLE	= no
RGB_MATRIX_ENABLE = no
RGBLIGHT_ENABLE	= no
SELECT_WORD_ENABLE = no #custom word selection
SLEEP_LED_ENABLE= no 
SPACE_CADET_ENABLE = no
SWAPPER_ENABLE = no #custom alt+tab
TAP_DANCE_ENABLE = no
UNICODE_ENABLE = no
USBPD_ENABLE = no #something with enabling Apple FN key?
VIA_ENABLE = no
WPM_ENABLE = no

#Including files
ifeq ($(strip $(CUSTOM_ONESHOT_ENABLE)), yes)
	OPT_DEFS += -DCUSTOM_ONESHOT_ENABLE
	SRC += features/nshot.c 
endif
ifeq ($(strip $(UNIVERSAL_OS_KEYS_ENABLE)), yes)
	OPT_DEFS += -DUNIVERSAL_OS_KEYS_ENABLE
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