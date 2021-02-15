# Mrkskk's Layout

## Introduction

This is my layout for the [Kyria](https://splitkb.com). 

I change between Mac and windows on a daily basis and my language settings differs between OS'es (Operative Systems).

my layout:

* Changes modifier positions when changing OS (as can also be done with [bootmagic](https://docs.qmk.fm/#/feature_bootmagic?id=bootmagic)).
* Keeps rotary encoders working, despite changing OS (swapping GUI and CTRL in encoder functions can't be done in  [bootmagic](https://docs.qmk.fm/#/feature_bootmagic?id=bootmagic)).
* Files: 

* [`keymap.c`](https://github.com/mrkskk/qmk_firmware/keyboards/kyria/keymaps/mrkskk/keymap.c)
* [`mrkskk.h`](mrkskk.h) - Contains definitions used in [`mrkskk.c`](mrkskk.c)

### OS Toggle
This enables me to toggle between Mac and Windows with a keypress that changes a boolean value. Simultaneously this changes the Unicode mode. 

Files:

* [`OS_Toggle.c`](OS_Toggle.c)
* [`OS_Toggle.h`](OS_Toggle.h)

### Process_records
This is where my custom keycodes are hiding. Alot of them compensates for the OS and language change.

Files:

* [`process_records.c`](process_records.c)
* [`process_records.h`](process_records.h)

### Leader
The leader is used as a text expansion tool. 
I avoid pushing some of these details to GitHub through a file called ```secrets.h```. 
I do this by using [metheon](https://github.com/metheon/qmk_firmware/tree/metheon/users/metheon)'s interpretation of a code originally written by [Drashna](https://github.com/qmk/qmk_firmware/tree/master/users/drashna). 
Check them out for more on this.


Files:

* [`leader.c`](leader.c)
* [`leader.h`](leader.h)


### Encoders
The Encoder code should get updated for better readability. Basicly, I compensate for the OS change so they work both Mac OS and Windows.

Files:

* [`encoders.c`](encoders.c)
* [`encoders.h`](encoders.h)

### OLEDs
The OLEDs show the toggled OS as well as layer and Encoder functions. The [`OLED_animation.c`](OLED_animation.c) file is not currently used. 

Files:

* [`OLED_static.c`](OLED_static.c)
* [`OLED.h`](OLED.h)

### Unicode Map
This is the fun stuff. Allows me to output Emoticons and the Greek alphabet.

Files:

* [`mrks_unicode_map.c`](mrks_unicode_map.c.c)
* [`mrks_unicode_map.h`](mrks_unicode_map.c.h)

### Special thanks

to the QMK discord community and especially to [metheon](https://github.com/metheon/qmk_firmware/tree/metheon/users/metheon) for helping a brother out. This layout is based heavily on his.

