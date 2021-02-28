# Mrkskk's Layout

## Introduction

I'm using the the [Kyria Keyboard](https://splitkb.com). 

### OS Toggle
This enables me to toggle between Mac and Windows with a keypress that changes a boolean value. Simultaneously this changes the Unicode mode. 

Files:

* [`OS_Toggle.c`](OS_Toggle.c)
* [`OS_Toggle.h`](OS_Toggle.h)

### Process_records
Creating custom keycodes.
Most of my custom keycodes are for making custom codes that trigger the same key on Windows and MacOS. For example "@" on MacOS is Alt+' while on Windows its altgr+2. My kecodes combines these to one key.

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
The OLEDs show the toggled OS as well as layer and Encoder functions. 

Files:

* [`OLED_static.c`](OLED_static.c)
* [`OLED.h`](OLED.h)

### Unicode Map
I don't currently use this

### Combos
 By using this branch (PR 8591) of QMK I'm able to put combos on LT() keys.
 On the Kyria this is especially useful when having 1u thumb clusters. The upper thumb keys are hard to reach.
 
File:
* [`combos.def`](combos.def)

### Special thanks
to the QMK discord community and especially to [metheon](https://github.com/metheon/qmk_firmware/tree/metheon/users/metheon) for helping a brother out. This layout is based heavily on his.

