// features/adapt_shift.h
// Adaptive Shift: Press comma then a letter to capitalize without holding shift
#pragma once

#include "quantum.h"

// Configuration
#ifndef ADAPTIVE_TERM
#    define ADAPTIVE_TERM 200 // Base timing window in milliseconds
#endif

// The keycode that acts as the shift leader
// Comma will trigger adaptive shift behavior
#define ADAPT_SHIFT_KEY KC_COMM

// Function declaration
bool process_adapt_shift(uint16_t keycode, keyrecord_t *record);
