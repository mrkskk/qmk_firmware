#pragma once

// Required for leader map function
void matrix_scan_leader(void);

//Keys that differ between danish MAC keyboard and danish WIN keyboard
#define USD_WIN ALGR(KC_4)
#define USD_MAC ALGR(S(KC_3)) // 
#define EUR_WIN ALGR(KC_5)    // €
#define EUR_MAC S(KC_4) // €
#define GBP_WIN  ALGR(KC_3)    // £
#define GBP_MAC A(KC_4)
#define YEN_MAC A(KC_Y) // ¥

