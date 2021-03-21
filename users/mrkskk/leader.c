#include "mrkskk.h"

#if (__has_include("secrets.h") && !defined(NO_SECRETS))
#include "secrets.h"
#else
// If the secret.h file is ever lost, simply create it again with this array
// being the only content
static const char *const secrets[] = {
    "no secrets to be found", "no secrets to be found",
    "no secrets to be found", "no secrets to be found",
    "no secrets to be found", "no secrets to be found",
    "no secrets to be found", "no secrets to be found",
    "no secrets to be found", "no secrets to be found",
    "no secrets to be found",
};
#endif

LEADER_EXTERNS();

void matrix_scan_leader(void) {
  LEADER_DICTIONARY() {
    leading = false;
    leader_end();

    // //////// //
    // Markdown //
    // //////// //
    SEQ_THREE_KEYS(KC_M, KC_C, KC_I) // Markdown Inline Code
    {
      SEND_STRING("`` " SS_TAP(X_LEFT) SS_TAP(X_LEFT));
    }
    SEQ_THREE_KEYS(KC_M, KC_C, KC_B) // Markdown code block
    {
      SEND_STRING("```c" SS_LSFT("\n") "```" SS_TAP(X_UP));
    }
    SEQ_TWO_KEYS(KC_M, KC_U) // Markdown url
    {
      SEND_STRING("[]()" SS_TAP(X_LEFT) SS_TAP(X_LEFT) SS_TAP(X_LEFT));
    }
    SEQ_TWO_KEYS(KC_M, KC_B) // Markdown bold
    {
      SEND_STRING("**" SS_TAP(X_LEFT));
    }
    SEQ_TWO_KEYS(KC_M, KC_I) // Markdown italic
    {
      SEND_STRING("__" SS_TAP(X_LEFT));
    }
    SEQ_TWO_KEYS(KC_M, KC_S) // Markdown strikethrough
    {
      SEND_STRING("~~~~" SS_TAP(X_LEFT) SS_TAP(X_LEFT));
    }
    SEQ_TWO_KEYS(KC_M, KC_C) // Markdown Checkbox
    {
      SEND_STRING("- [ ] ");
    }
    SEQ_THREE_KEYS(KC_M, KC_C, KC_C) // Markdown Checkbox checked
    {
      SEND_STRING("- [x] ");
    }

    // /// //
    // QMK //
    // /// //
    SEQ_TWO_KEYS(KC_Q, KC_D) // QMK Docs
    {
      SEND_STRING("https://docs.qmk.fm/#/");
    }
    SEQ_TWO_KEYS(KC_G, KC_H) // QMK Userspace
    {
      SEND_STRING("https://github.com/mrkskk/qmk_firmware/tree/review/8591/"
                  "users/mrkskk");
    }
    SEQ_TWO_KEYS(KC_K, KC_M) // QMK Kyria Keymap
    {
      SEND_STRING("https://github.com/mrkskk/qmk_firmware/tree/master/"
                  "keyboards/kyria/keymaps/mrkskk");
    }
    SEQ_TWO_KEYS(KC_C, KC_D) // cd to qmk_firmware folder
    {
      SEND_STRING("cd github/mrkskk/qmk_firmware");
      tap_code(KC_ENT);
    }
    /////////////////////////
    // Currency Symbols  //
    /////////////////////////
    SEQ_THREE_KEYS(KC_U, KC_S, KC_D) // $ symbol across OS
    {
      if (is_mac()) {
        tap_code16(USD_MAC);
      } else {
        tap_code16(USD_WIN);
      }
    }
    SEQ_THREE_KEYS(KC_E, KC_U, KC_R) // € symbol across OS
    {
      if (is_mac()) {
        tap_code16(EUR_MAC);
      } else {
        tap_code16(EUR_WIN);
      }
    }
    SEQ_THREE_KEYS(KC_G, KC_B, KC_P) // £ symbol across OS
    {
      if (is_mac()) {
        tap_code16(GBP_MAC);
      } else {
        tap_code16(GBP_WIN);
      }
    }
    /////////////////////////
    // Webpages for work   //
    /////////////////////////
    SEQ_THREE_KEYS(KC_M, KC_E, KC_D) // MED - Pro.med.dk
    {
      if (is_mac()) {
        tap_code16(G(KC_SPC));
      } else {
        tap_code16(KC_LGUI);
      }
      SEND_STRING(SS_DELAY(100) "pro.medicin.dk\n");
    }
    SEQ_TWO_KEYS(KC_U, KC_P) // UP - Uptodate
    {
      if (is_mac()) {
        tap_code16(G(KC_SPC));
      } else {
        tap_code16(KC_LGUI);
      }
      SEND_STRING(SS_DELAY(100) "https://www.uptodate.com/login\n");
    }
    SEQ_THREE_KEYS(KC_H, KC_E, KC_M) // HEM - Hematology.dk
    {
      if (is_mac()) {
        tap_code16(G(KC_SPC));
      } else {
        tap_code16(KC_LGUI);
      }
      SEND_STRING(SS_DELAY(100) "https://www.hematology.dk/index.php/vejledninger/kliniske\n");
    }
    SEQ_THREE_KEYS(KC_I, KC_N, KC_F) // INF  Infektionsmed guidelines
    {
      if (is_mac()) {
        tap_code16(G(KC_SPC));
      } else {
        tap_code16(KC_LGUI);
      }
      SEND_STRING(SS_DELAY(100) "https://www.infmed.dk/guidelines\n");
    }
    // De overstående leader kombier skal evt ændres til at launche i chrome
    // fremfor standardbrowseren
    SEQ_THREE_KEYS(KC_A, KC_R, KC_B) // ARB - Arbejde Åbne  overstående i chrome
    {
      if (is_mac()) {             // MAC OS
        tap_code16(LGUI(KC_SPC)); // Alfred Launch
        SEND_STRING(SS_DELAY(100) "Chrome\n");
        tap_code16(LGUI(KC_L)); // Cursor to adress bar
        SEND_STRING(SS_DELAY(100) "infmed.dk/guidelines\n");
        tap_code16(LGUI(KC_T)); // New tab
        SEND_STRING(SS_DELAY(100) "pro.medicin.dk\n");
        tap_code16(LGUI(KC_T)); // New tab
        SEND_STRING(SS_DELAY(100) "http://www.uptodate.com/login\n");
      } else {             // WIN OS
        tap_code(KC_LGUI); // Search launch
        SEND_STRING(SS_DELAY(100) "Chrome\n");
        tap_code16(LCTL(KC_L)); // Cursor to adress bar
        SEND_STRING(SS_DELAY(100) "infmed.dk/guidelines\n");
        tap_code16(LCTL(KC_T)); // New tab
        SEND_STRING(SS_DELAY(100) "pro.medicin.dk\n");
        tap_code16(LCTL(KC_T)); // New tab
        SEND_STRING(SS_DELAY(100) "http://www.uptodate.com/login\n");
      }
    }
    SEQ_THREE_KEYS(KC_C, KC_M, KC_T) // Move tab to new window
    {
      if (is_mac()) {           // MAC OS
        tap_code16(LGUI(KC_L)); // Cursor to adress bar
        tap_code16(LGUI(KC_A)); // Mark all text
        tap_code16(LGUI(KC_C)); // Copy all text
        tap_code16(LGUI(KC_W)); // Close tab
        tap_code16(LGUI(KC_N)); // Open new window
        tap_code16(LGUI(KC_V)); // Paste text
        tap_code(KC_ENT);       // Enter
      } else {                  // WIN OS
        tap_code16(C(KC_L));    // Cursor to adress bar
        tap_code16(C(KC_A));    // Mark all text
        tap_code16(C(KC_C));    // Copy all text
        tap_code16(C(KC_W));    // Close tab
        tap_code16(C(KC_N));    // Open new window
        tap_code16(C(KC_V));    // Paste text
        tap_code(KC_ENT);       // Enter
      }
    }

    // /////// //
    // Secrets //
    // /////// //
    SEQ_TWO_KEYS(KC_P, KC_W) {
      send_string(secrets[0]);
      tap_code(KC_TAB);
      send_string(secrets[8]);
      tap_code(KC_ENT);
    }

    SEQ_TWO_KEYS(KC_P, KC_M) { //Pubmed access
      send_string(secrets[2]);
      tap_code16((is_mac()) ? AT_MAC : AT_WIN);
      send_string(secrets[3]);
      tap_code(KC_TAB);
      send_string(secrets[8]);
      tap_code(KC_ENT);
    }

    SEQ_TWO_KEYS(KC_P, KC_K) {
      send_string(secrets[8]);
      tap_code(KC_ENT);
    }
    SEQ_TWO_KEYS(KC_L, KC_H) {
      send_string(secrets[7]);
      tap_code(KC_ENT);
    }
    SEQ_TWO_KEYS(KC_M, KC_W) {
      send_string(secrets[2]);
       tap_code16((is_mac()) ? AT_MAC : AT_WIN);
      send_string(secrets[3]); }
    SEQ_TWO_KEYS(KC_M, KC_P) {
      send_string(secrets[4]);
       tap_code16((is_mac()) ? AT_MAC : AT_WIN);
      send_string(secrets[5]);
    }
    SEQ_TWO_KEYS(KC_M, KC_K) { send_string(secrets[4]); }
  }
}
