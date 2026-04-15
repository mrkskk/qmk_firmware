// clang-format on
#pragma once

#include "users/mrkskk/config.h"

// Charybdis-specific split-half wiring.
#define MASTER_RIGHT

#ifdef POINTING_DEVICE_ENABLE
#    define POINTING_DEVICE_AUTO_MOUSE_ENABLE
#    define POINTING_CARET_DIVISOR_V 150 // Higher numbers are slower.
#    define POINTING_DRAG_DIVISOR 80

#    define AUTO_MOUSE_TIME 500
#    define CHARYBDIS_AUTO_SNIPING_ON_LAYER
#endif
