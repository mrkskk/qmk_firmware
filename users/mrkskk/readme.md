# Mrkskk's Layout

## Introduction

I'm using the the [Kyria Keyboard](https://splitkb.com). 

### which_os
Changing between MacOS shortcuts and windows shortcuts.
TG_OS keycode in process records toggles between these (Same function as CG_TOGG)
Files:

* [`which_os.c`](which_os.c)
* [`which_os.h`](which_os.h)

### Process_records
Creating custom keycodes.

Most of my custom keycodes are for making custom codes that trigger the same key on Windows and MacOS. For example "@" on MacOS is Alt+' while on my Windows its altgr+2. My kecodes combines these to one key.

Files:

* [`process_records.c`](process_records.c)
* [`process_records.h`](process_records.h)

### Leader
The leader is mostly used as a text expansion tool. 
I avoid pushing some of these details to GitHub through a file called ```secrets.h```. 

Files:

* [`leader.c`](leader.c)
* [`leader.h`](leader.h)

### Encoders
The Encoder code should get updated for better readability. Basicly, I compensate for the OS change so they work both Mac OS and Windows.

Files:

* [`encoders.c`](encoders.c)
* [`encoders.h`](encoders.h)

### OLEDs
The Master OLED shows the toggled OS as well as layer and Encoder functions. 
The Slave OLED shows the kyria logo

Files:

* [`OLED_static.c`](OLED_static.c)
* [`OLED.h`](OLED.h)

### Combos
 By using this branch (PR 8591) of QMK I'm able to put combos on LT() keys.
 On the Kyria this is especially useful when having 1u thumb clusters. The upper thumb keys are hard to reach.
 
File:
* [`combos.def`](combos.def)

### Special thanks
to the QMK discord community and especially to [metheon](https://github.com/metheon/qmk_firmware/tree/metheon/ users/metheon) for helping a brother out. This layout is based heavily on his.

