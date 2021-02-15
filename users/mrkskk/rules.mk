LINK_TIME_OPTIMIZATION_ENABLE = yes
RGBLIGHT_ENABLE = no      # Enable keyboard RGB underglow	
TAP_DANCE_ENABLE = yes
EXTRAKEY_ENABLE = yes # enables system keys (wake sleep)
COMBO_ENABLE	= yes
WPM_ENABLE = no
LEADER_ENABLE = yes       # Enable the Leader Key feature


SRC += leader.c
SRC += OS_Toggle.c
SRC += process_records.c

ifeq ($(strip $(COMBO_ENABLE)), yes)
SRC += combos.c
endif

ifeq ($(strip $(TAP_DANCE_ENABLE)), yes)
SRC += tap_dance.c
endif

ifeq ($(strip $(ENCODER_ENABLE)), yes)
SRC += encoders.c
endif

ifeq ($(strip $(OLED_DRIVER_ENABLE)), yes)
SRC += OLED_static.c
endif

ifeq ($(strip $(UNICODEMAP_ENABLE)), yes)
SRC += mrks_unicode_map.c
endif

ifeq ($(strip $(FLASH_BOOTLOADER)), yes)
    OPT_DEFS += -DFLASH_BOOTLOADER
endif

# Disable as many features as possible

UNICODEMAP_ENABLE = noø
MOUSEKEY_ENABLE = no
STENO_ENABLE = no
BOOTMAGIC_ENABLE =no 
TERMINAL_ENABLE = no
GRAVE_ESC_ENABLE = no
MAGIC_ENABLE = no
SPACE_CADET_ENABLE = no
KEY_LOCK_ENABLE = no
AUDIO_ENABLE = no
CONSOLE_ENABLE = no
VELOCIKEY_ENABLE = no


