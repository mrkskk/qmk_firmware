# ⌨️ mrkskk Keymap

Highly customized QMK keymap with advanced features, combos, and macros.
Designed for split ergonomic keyboards using a layout-agnostic approach.

## Supported Keyboards

- **Hazel Bad Wings v2** - Split keyboard with integrated pointing device
- **BastardKB Charybdis 3x5** - Split keyboard with trackball

## Table of Contents

- [Layer Overview](#layer-overview)
- [Keymap Layers](#keymap-layers)
- [Combo System](#combo-system)
- [Features & Add-ons](#features--add-ons)
- [Keyboard-Specific Settings](#keyboard-specific-settings)

## Layer Overview

| Layer | Access | Purpose |
|-------|--------|---------|
| **BASE** | Default | Main DVORAK-like layout with home-row mods |
| **NAV_MAC** | Hold NAV key | Navigation, clipboard, and text editing (macOS-optimized) |
| **MOUSE** | Toggle/N key | Mouse movement and clicking |
| **NUMROW** | Space hold | Quick access to numbers and symbols in top row |
| **NUM** | FN/Bsp hold | Full number pad + symbols |
| **FNKEYS** | V/Æ key hold | Function keys, media controls, OS detection |

## Keymap Layers

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

**Layout Style**: DVORAK-inspired with optimized consonant placement

**Home-Row Mods**:
- Left: Shift, Alt, Ctrl, Gui on R, S, T, H
- Right: Gui, Ctrl, Alt, Shift on I, E, O, A
- Hyper (Shift+Ctrl+Alt) on B and comma
- Meh (Ctrl+Alt) on B and period
- CAG (Ctrl+Alt+Gui) on D and P

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

**Features**:
- Arrow keys in inverted-T formation
- Word selection (left/right)
- Clipboard operations (undo, copy, paste)
- Page navigation
- Tab and Escape access
- CapsWord toggle for quick capitalization

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

**Features**:
- Trackball/mouse movement
- Precision mode toggle
- Click buttons (left, right)
- Scroll wheel (up, down, left, right)
- Kinetic mouse acceleration enabled

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

**Features**:
- Numbers distributed in pairs with shifted symbols
- Diacritical marks (^, ¨, `, ´, ~)
- Math and comparison operators
- Home-row mods on numbers
- Paragraph symbol (§)

### Number Pad Layer

```
╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
  ToBase      7        8        9     ToBase    ToBase      7        8        9     ToBase
├─────────────────────────────────────┤───────┤ ├─────────────────────────────────────────────┤
  ⇧ Sft 0  ⌥ Alt 4  ⌃ Ctl 5  ⌘ Gui 6  ToBase    ToBase  ⌘ Gui 4  ⌃ Ctl 5  ⌥ Alt 6   Shift
├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
  ToBase   Meh 1    Hyp 2    Cag 3    ToBase    ToBase   Cag 1    Hyp 2    Meh 3     RAlt
╰─────────────────────────────────────────────┤ ├─────────────────────────────────────────────╯
                  ToBase      0      ToBase       Bspc      0
                 ╰───────────────────────────╯ ╰──────────────────╯
```

**Features**:
- Traditional numpad layout on right side
- Number input on left side
- Modifiers on numbers for quick access

### Function Keys Layer

```
╭─────────────────────────────────────────────╮ ╭─────────────────────────────────────────────╮
  C-A-Del     F7       F8       F9      F12     TgSent    Prev     Play     Next      Ins
├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
  ScrShot     F4       F5       F6      F11      TgOS      Gui      Ctrl     Alt     Shift
├─────────────────────────────────────────────┤ ├─────────────────────────────────────────────┤
     __       F1       F2       F3      F10     OSReset   BriDn    BriUp    Assist     __
```

**Features**:
- Function keys F1-F12
- Media controls (play, pause, next, previous)
- System controls (screenshot, brightness, eject)
- macOS-specific (Assist = Siri)
- OS detection toggle
- Sentence case toggle

## Combo System

Combos provide quick single-keystroke access to frequently-used symbols, commands, and macros.

### Symbol Combos

**Brackets & Braces** (press simultaneously):
- `[` and `]` - Standard bracket pair
- `{` and `}` - Brace pair via modifier combinations
- Parentheses available via home-row mod combos

**Math & Comparison** (press 2-3 keys):
- `+` - Multiple chord options
- `*` (asterisk) - Hyper+Ctrl combo
- `/` (slash) - Ctrl+M combo
- `\` (backslash) - G+Gui combo
- `-` (minus) - Ctrl+Gui combo
- `_` (underscore) - Gui+Ctrl combo

**Special Characters**:
- `@` - Alt+Gui combo
- `$` - Ctrl+Shift combo
- `%` - Shift+Alt combo
- `?` - Cag+Hyp combo
- `!` - Hyp+Cag combo
- `"` (quote) - Space + N combo
- `` ` `` (backtick) - Diacritical marks
- `^`, `¨`, `´`, `~` - Diacritical options

### Quick Action Combos

- **Enter** - C+G+M chord (left hand, no pinky)
- **Backspace** - B+L+D chord (left hand, no pinky)
- **Caps Word** - Ctrl+Alt+Gui triple-tap
- **Toggle Mouse** - NAV+Ctrl combo

### Number Combos

Quick number access from spacebar layer (NUM_SPC):
- **0-9** - Space + corresponding key
- Example: Space + KC_U = 7, Space + KC_N = 0

### String/Macro Combos

- **LOGIN** - Login credentials macro (Gui+Alt+Ctrl+Shift)
- **WORK_MAIL** - Work email address (Gui+Alt+Ctrl+Shift)
- **PERS_MAIL** - Personal email address (V+B+L+D)
- **SECRET_1/2/3** - Custom stored strings (multi-key chords)
  - Requires `features/secrets.h` for sensitive data

### Combo Timer Settings
- **Combo Term**: 20ms (very tight - fingertaps must be nearly simultaneous)
- **Active on BASE layer only** - Prevents accidental triggers on other layers

## Features & Add-ons

### Core QMK Features

**Caps Word** - Toggle with Combo
- Auto-capitalizes words without caps lock
- Smart: only capitalizes letters, allows common symbols (backspace, delete, underscore)
- Useful for variable names or capitalized words

**Combo System** - Rapid multi-key sequences
- ~50 combos for symbols, numbers, actions, and macros
- 20ms detection window for simultaneous keypresses
- Base layer only to prevent accidental triggers

**Auto Shift** - Hold duration detection
- 190ms threshold
- Useful for symbols bound to letter keys
- No repeat on auto-shift

**Mouse Keys** - Keyboard-controlled cursor
- Kinetic acceleration mode
- Tuned for trackball use
- Precision mode available

### Advanced Custom Features

**OS Detection** - Auto-adapt to macOS or Windows
- Detects OS on connection
- Adapts key mappings automatically
- Cmd (macOS) vs Ctrl (Windows) handling
- Toggle or manual override available

**Select Word Features**
- **Select Word Right** - Extend selection to next word end
- **Select Word Left** - Extend selection to previous word start
- Useful with Shift for selection, Alt for specific behaviors

**Swapper** - Quick app/window switching
- **Cmd-Tab** (macOS) / **Alt-Tab** (Windows) - SW_MAC/SW_WIN
- **Ctrl-Tab** - Tab switching
- Reverse direction support (Shift variant)
- Configurable timeout

**Layer Lock** - Lock active layer
- Press dedicated key to lock a layer
- Press again to toggle back to base
- Useful for temporary mode activation without holding

**Sentence Case** - Auto-capitalize sentence starts
- Intelligently capitalizes first letter after sentences
- Recognizes sentence endings (`.`, `!`, `?`)
- Improves writing without caps lock

**Repeat Key** - Duplicate last keystroke
- Remembers last pressed key (including modifiers)
- Useful for rapid repeated actions
- Stores keystroke with all active mods

**One-Shot Mods** (Custom nshot)
- Tap once, press another key = mod applied to that key
- Useful for quick Shift-a without holding
- Options:
  - `OS_LSFT` / `OS_RSFT` - One-shot shift
  - `OS_LCTL` / `OS_RCTL` - One-shot control
  - `OS_LALT` / `OS_RALT` - One-shot alt/option
  - `OS_LGUI` / `OS_RGUI` - One-shot command/windows
  - `OS_HYPR` - One-shot Hyper (Shift+Ctrl+Alt)
  - `OS_MEH` - One-shot Meh (Ctrl+Alt)
  - `OS_CAG` - One-shot Cag (Ctrl+Alt+Gui)
  - `OSS_NAV` - One-shot shift + NAV layer on hold

**Key Overrides** - Conditional key substitution
- Remap keys based on active modifiers
- Example: Shift+number = symbol
- Reduces need for dedicated symbol layer

**Adapt Shift** - Context-aware shift
- Shift behavior adapts based on what key is pressed
- Prevents accidental capitalization in specific contexts
- Improves typing feel

**Custom Layer Modes**
- **Num Word** - Spacebar layer auto-disables after key release
- Numbers without layer toggle
- Auto-return to base

### Home-Row Mods

Essential feature for reducing pinky load and enabling one-handed typing.

**Left Hand** (on R, S, T, H):
- **R** = Shift
- **S** = Alt / Option
- **T** = Ctrl / Control
- **H** = Cmd / Windows

**Right Hand** (on I, E, O, A):
- **I** = Cmd / Windows
- **E** = Ctrl / Control
- **O** = Alt / Option
- **A** = Shift

**Mod Row** (on B, L, comma, period):
- **B** = Hyper (Shift+Ctrl+Alt) - left
- **L** = Hyper (custom right variant)
- **Comma** = Hyper - right
- **Period** = Meh (Ctrl+Alt)

**Activation Settings**:
- **Permissive Hold** - Mod activates if another key pressed while holding
- **Tapping Term**: 230ms - careful balance for reliability
- Ensures mods activate without interfering with fast typing

### Danish/Nordic Key Support

Full support for Danish characters with custom keycodes:
- **Æ** (DK_AE)
- **Ø** (DK_OE)
- **Å** (DK_AA)
- Diacritical marks: `^`, `¨`, `` ` ``, `´`, `~`
- Alt codes for special symbols

## Configuration Details

**Timing**:
- Tapping Term: 230ms
- Combo Term: 20ms
- Auto Shift Timeout: 190ms

**Build Options**:
- Max 8 layers (LAYER_STATE_8BIT)
- Saved 1KB+ by disabling animations
- Permissive Hold enabled for faster mod responsiveness

**Disabled Features**:
- RGB animations (for size optimization)
- Music mode
- Macro/Function action handlers
- Locking shift/caps (using one-shot instead)

**Mouse Configuration**:
- Kinetic speed enabled
- Initial speed: 700 px/s
- Base speed: 1500 px/s (acceleration max)
- Wheel movements: 4 initial, 8 base, 12 accelerated

## Keyboard-Specific Settings

### Charybdis 3x5 (BastardKB)

**Location**: `keyboards/bastardkb/charybdis/3x5/keymaps/mrkskk/config.h`

**Settings**:
- `MASTER_RIGHT` - Right half is master (wiring configuration)
- Pointing device enabled (trackball support)
- `POINTING_DEVICE_AUTO_MOUSE_ENABLE` - Auto-activate mouse on pointing input
- `CARET_DIVISOR_V = 150` - Vertical scroll sensitivity (lower = faster)
- `POINTING_DRAG_DIVISOR = 80` - Drag sensitivity
- `AUTO_MOUSE_TIME = 500` - Timeout before mouse disables
- `CHARYBDIS_AUTO_SNIPING_ON_LAYER` - Precision mode on specific layers

### Bad Wings v2 (Hazel)

**No keymap-level config** - Uses default settings for this keyboard

**Integrated pointing device** available but uses default QMK settings

---

## Notes for Future Development

- `archive.c` - Repository of old code snippets and experimental features
- Combos set to very fast (20ms) - adjust if false-triggers occur
- Secrets system requires `features/secrets.h` for credentials
- OS detection auto-triggers on connection; can be toggled manually
