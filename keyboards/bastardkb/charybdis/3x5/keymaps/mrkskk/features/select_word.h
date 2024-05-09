// For full documentation, see
// https://getreuer.info/posts/keyboards/select-word

#pragma once
#include "quantum.h"

bool process_select_word_right(uint16_t keycode, keyrecord_t* record, uint16_t sel_keycode);
bool process_select_word_left(uint16_t keycode, keyrecord_t* record, uint16_t sel_keycode);
