## Introduction
This is my QMK keyboard layout that is primarly used on the [Kyria Keyboard](https://splitkb.com). 
the keymap is found in the [keymap.c](https://github.com/mrkskk/qmk_firmware/tree/review/8591/keyboards/kyria/keymaps/mrkskk/keymap.c) file in the kyria keymap folder

### Process_records
Most of my custom keycodes are for making custom codes that trigger the same key on Windows and MacOS. For example "@" on MacOS is Alt+' while on my Windows it's altgr+2. My keycodes combines these to one key, so I avoid having two "@" keys on my symbol layer.

Files:

* [`process_records.c`](process_records.c)
* [`process_records.h`](process_records.h)

### which_os
This is used when changing between  MacOS  and windows. TG_OS keycode in process records toggles between these (Same function as CG_TOGG). This code is created by [metheon](hhttps://github.com/metheon/qmk_firmware/blob/metheon_early_combos/users/metheon/)

Files:

* [`which_os.c`](which_os.c)
* [`which_os.h`](which_os.h)
* [`process_records.c`](process_records.c)

### Leader
The leader is mostly used as a text expansion tool. 

Files:

* [`leader.c`](leader.c)
* [`leader.h`](leader.h)

### Encoders
My keyboards features two rotary encoders. They do stuff like scroll text, scroll up/down, Undo-Redo, Control volume ect. ect.

Files:

* [`encoders.c`](encoders.c)
* [`encoders.h`](encoders.h)

### OLEDs
The OLED on the Master side (Side thats plugged in with usb-c cable) shows the toggled OS as well as layer and Encoder functions. 
The Slave OLED shows the kyria logo.

Files:

* [`OLED.c`](OLED.c)
* [`OLED.h`](OLED.h)

### Combos
 By using this branch (PR 8591) of QMK I'm able to put combos on LT() keys.
 On the Kyria this is especially useful two chord with the upper 1u thumb keys that are otherwise in a hard to reach position.

File:
* [`combos.def`](combos.def)


### Case Modes
this is @andrewjrae's caps word implementation. 

Files:
[`casemodes.c`](casemodes.c)
[`casemodes.h`](casemodes.h)
### Unicode keymap
 The Unicode map is currently disabled. 

### Tap dance keys
 The Tap dance keys are currently disabled. 


