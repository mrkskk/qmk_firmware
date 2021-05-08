LTO_ENABLE = yes
EXTRAKEY_ENABLE = yes  # enables system keys (wake sleep vol)
COMBO_ENABLE	= yes
LEADER_ENABLE = yes       # Enable the Leader Key feature

SRC += mrkskk.c
SRC += which_os.c
SRC += casemodes.c
SRC += process_records.c


ifeq ($(strip $(LEADER_ENABLE)), yes)
SRC += leader.c
endif

ifeq ($(strip $(COMBO_ENABLE)), yes)
VPATH += keyboards/gboards # to make combo dictionary work
endif

ifeq ($(strip $(TAP_DANCE_ENABLE)), yes)
SRC += tap_dance.c
endif

ifeq ($(strip $(ENCODER_ENABLE)), yes)
SRC += encoders.c
endif

ifeq ($(strip $(OLED_DRIVER_ENABLE)), yes)
SRC += OLED.c
endif

ifeq ($(strip $(UNICODEMAP_ENABLE)), yes)
SRC += mrks_unicode_map.c
endif

ifeq ($(strip $(FLASH_BOOTLOADER)), yes)
    OPT_DEFS += -DFLASH_BOOTLOADER
endif



# Disable as many features as possible
TAP_DANCE_ENABLE = no
RGBLIGHT_ENABLE = no      # Enable keyboard RGB underglow
RGB_MATRIX_ENABLE = no
WPM_ENABLE = no
UNICODEMAP_ENABLE = no
MOUSEKEY_ENABLE = no
STENO_ENABLE = no
TERMINAL_ENABLE = no
GRAVE_ESC_ENABLE = no
BOOTMAGIC_ENABLE = no
MAGIC_ENABLE = no #Disables magic functions ie the bootmagic keycodes
SPACE_CADET_ENABLE = no
KEY_LOCK_ENABLE = no
AUDIO_ENABLE = no
CONSOLE_ENABLE = no
VELOCIKEY_ENABLE = no


