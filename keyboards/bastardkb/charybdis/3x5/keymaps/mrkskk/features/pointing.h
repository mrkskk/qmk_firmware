// Copyright 2021 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// Copyright 2022 Freznel B. Sta. Ana  (@freznel10) <freznel@gmail.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#include "defines.h"

void           pointing_device_init_keymap(void);
report_mouse_t pointing_device_task_keymap(report_mouse_t mouse_report);
void           matrix_scan_pointing(void);
bool           process_record_pointing(uint16_t keycode, keyrecord_t* record);
layer_state_t  layer_state_set_pointing(layer_state_t state);
extern bool    enable_acceleration;