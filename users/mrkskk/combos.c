#include "mrkskk.h"


enum combo_events {
  COMBO_NR_1,
  COMBO_NR_2,
};

const uint16_t PROGMEM OUTER_RIGHT_THUMB_COMBO[] = { KC_LCTRL, KC_TRNS, COMBO_END};
//const uint16_t PROGMEM INNER_RIGHT_THUMB_COMBO[] = { NVEN, S_S, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
  [COMBO_NR_1] = COMBO_ACTION(OUTER_RIGHT_THUMB_COMBO),
 // [COMBO_NR_2] = COMBO_ACTION(INNER_RIGHT_THUMB_COMBO),

};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case COMBO_NR_1:
      if (pressed) {
        layer_on(SHORTCUTS);
      } else {
        layer_off(SHORTCUTS);
      }
      break;
/*      case COMBO_NR_2:
      if (pressed) {
        SEND_STRING(SS_DELAY(100)"test\n");
      }
      break;
*/ }
}

