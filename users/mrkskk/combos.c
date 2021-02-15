#include "mrkskk.h"


enum combo_events {
  COMBO_NR_1,
  COMBO_NR_2,
  COMBO_NR_3,

};

const uint16_t PROGMEM OUTER_RIGHT_THUMB_COMBO[] = { ____, CBSPC, COMBO_END};
const uint16_t PROGMEM INNER_RIGHT_THUMB_COMBO[] = { NVENT, S_S, COMBO_END};
const uint16_t PROGMEM INNER_LEFT_THUMB_COMBO[] = { FIND, NVSPC, COMBO_END};




combo_t key_combos[COMBO_COUNT] = {
  [COMBO_NR_1] = COMBO_ACTION(OUTER_RIGHT_THUMB_COMBO),
  [COMBO_NR_2] = COMBO_ACTION(INNER_RIGHT_THUMB_COMBO),
  [COMBO_NR_3] = COMBO_ACTION(INNER_LEFT_THUMB_COMBO),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case COMBO_NR_1:
      if (pressed) {
        tap_code16(BSPC_W);
      }
      break;
      case COMBO_NR_2:
      if (pressed) {
        tap_code16(DEL_W);
      }
      break;
      case COMBO_NR_3:
      if (pressed) {
        tap_code16(S(MINUS));
      }
      break;
 }
}

