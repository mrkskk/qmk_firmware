# ⌨️ mrkskk Charybdis 3x5 Keymap

Custom QMK keymap for the Bastard Keyboards Charybdis 3x5.

## Table of Contents <!-- omit in toc -->

- [🗺️ Keymap Layout](#️-keymap-layout)
  - [Base Layer](#base-layer)
  - [Navigation Layer](#navigation-layer)
  - [Mouse Layer](#mouse-layer)
  - [Number Row Layer](#number-row-layer)
  - [Number Pad Layer](#number-pad-layer)
  - [Function Keys Layer](#function-keys-layer)
- [⚙️ Configuration Files](#️-configuration-files)
- [✨ Features](#-features)
  - [📁 Features Currently Enabled](#-features-currently-enabled)
    - [QMK Built-in Features](#qmk-built-in-features)
    - [Custom Implementations](#custom-implementations)
- [🔐 Secrets](#-secrets)

## 🗺️ Keymap Layout

### Base Layer

```
╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
     W        C        G        M        J          '        U        K        Ø        Å
├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
  ⇧ Sft R  ⌥ Alt S  ⌃ Ctl T  ⌘ Gui H     F          Y     ⌘ Gui I  ⌃ Ctl E  ⌥ Alt O  ⇧ Sft A
├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
     V      Meh B    Hyp L    Cag D       X          Z     Cag P    Hyp ,    Meh .       Æ
╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                  NUMROW     SPC      NAV         FN/Bsp     N
                 ╰───────────────────────────╯ ╰──────────────────╯
```

### Navigation Layer

```
╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
    Undo     Copy   Clipbrd   Paste    Redo      PgUp   SelWrdL    Up    SelWrdR    End
├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
   Shift     Alt      Ctrl     Gui     RAlt      PgDn     Left     Down    Right    Home
├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
   TgMse     Meh      Hypr     Cag    CpsWrd      Quit     Tab      Ent      Esc      __
╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                  ToBase   ToBase   ToBase      FN/Bsp    Del
                 ╰───────────────────────────╯ ╰──────────────────╯
```

### Mouse Layer

```
╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
  ToBase   ToBase   WhlUp   ToBase   ToBase    ToBase   ToBase   MseUp   ToBase   ToBase
├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
  ToBase   WhlLft   WhlDn   WhlRgt   ToBase    ToBase   MseLft   MseDn   MseRgt   ToBase
├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
  ToBase   RgtClk   Precis   LftClk   ToBase    ToBase   ToBase   ToBase   ToBase   ToBase
╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                  ToBase   ToBase   ToBase     ToBase   ToBase
                 ╰───────────────────────────╯ ╰──────────────────╯
```

### Number Row Layer

```
╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
     ^        ¨        `        ´        ~          "        <        -        +        >
├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
  ⇧ Sft 7  ⌥ Alt 5  ⌃ Ctl 1  ⌘ Gui 3      9          0     ⌘ Gui 4  ⌃ Ctl 2  ⌥ Alt 6  ⇧ Sft 8
├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
  TgNum    Meh ^    Hyp $    Cag 9       |          §     Cag 0    Hyp ,    Meh .     .
╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                  ToBase   ToBase   ToBase       Bspc      0
                 ╰───────────────────────────╯ ╰──────────────────╯
```

### Number Pad Layer

```
╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
  ToBase      7        8        9     ToBase    ToBase      7        8        9     ToBase
├─────────────────────────────────┤───────────┤ ├─────────────────────────────────────────────┤
  ⇧ Sft 0  ⌥ Alt 4  ⌃ Ctl 5  ⌘ Gui 6  ToBase    ToBase  ⌘ Gui 4  ⌃ Ctl 5  ⌥ Alt 6   Shift
├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
  ToBase   Meh 1    Hyp 2    Cag 3    ToBase    ToBase   Cag 1    Hyp 2    Meh 3     RAlt
╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                  ToBase      0      ToBase       Bspc      0
                 ╰───────────────────────────╯ ╰──────────────────╯
```

### Function Keys Layer

```
╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
  C-A-Del     F7       F8       F9      F12     TgSent    Prev     Play     Next      Ins
├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
  ScrShot     F4       F5       F6      F11      TgOS      Gui      Ctrl     Alt     Shift
├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
     __       F1       F2       F3      F10     OSReset   BriDn    BriUp    Assist     __
╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                   Mute    VolDn    VolUp        VolUp    VolDn
                 ╰───────────────────────────╯ ╰──────────────────╯
```

## ⚙️ Configuration Files

- [rules.mk](rules.mk) - Feature toggles and build configuration
- [config.h](config.h) - Timing, behavior settings, and feature-specific configs
- [keymap.c](keymap.c) - Main keymap layout and custom keycodes
- [defines.h](defines.h) - Custom keyboard definitions and layer enums

## ✨ Features

### 📁 Features Currently Enabled

#### QMK Built-in Features

| Feature | Description |
|---------|-------------|
| **Caps Word** | Type in UPPERCASE when double-tapping shift |
| **Combo** | Chord key combinations - pressing multiple keys triggers actions |
| **Extrakey** | Media keys and system controls |
| **Key Override** | Simple key overrides for custom behavior |
| **LTO** | Link Time Optimization - reduces firmware size |
| **Mousekey** | Keyboard control of mouse cursor and buttons |

#### Custom Implementations

Custom feature implementations are located in the [features/](features/) directory:

| Feature | Description | Files |
|---------|-------------|-------|
| **Adaptive Shift** | Press comma then a letter to capitalize without holding shift | [adapt_shift.c](features/adapt_shift.c), [adapt_shift.h](features/adapt_shift.h) |
| **OS Detection** | Automatic OS detection for universal shortcuts (QMK Built-in + custom) | [os_keys.c](features/os_keys.c), [os_keys.h](features/os_keys.h), [os_keys.def](features/os_keys.def) |
| **Select Word** | Quickly select word under cursor with directional navigation | [select_word.c](features/select_word.c), [select_word.h](features/select_word.h) |
| **Sentence Case** | Automatically capitalize first letter of sentences, reducing need for shift | [sentence_case.c](features/sentence_case.c), [sentence_case.h](features/sentence_case.h) |

## 🔐 Secrets

The keymap supports storing sensitive strings in [features/secrets.h](features/secrets.h) for quick access via custom keycodes and combos ([keymap.c:257-297](keymap.c#L257-L297)).

**Example secrets.h format:**
```c
static const char* secrets[] = {
    "mysecretstring ",      // [0] first secret string
    "mysecretstring2",      // [1] second secret string
};
```

**Note:** Keep `secrets.h` out of version control by adding it to `.gitignore`.
