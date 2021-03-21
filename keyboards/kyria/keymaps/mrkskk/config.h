#define RGB_DI_PIN D3
#define RGBLED_SPLIT { 10, 10 }
#define RGBLED_NUM 20

#define LAYOUT_mrkskk( \
    L00, L01, L02, L03, L04,                     R05, R06, R07, R08, R09, \
    L10, L11, L12, L13, L14,                     R19, R20, R21, R22, R23, \
    L24, L25, L26, L27, L28, L29, L30, R31, R32, R33, R34, R35, R36, R37, \
              L37, L38, L39, L40, L41, R42, R43, R44, R45, R46  \
) \
{ \
    { KC_NO, KC_NO, L04,   L03,   L02,   L01,   L00   }, \
    { KC_NO, KC_NO, L14,   L13,   L12,   L11,   L10   }, \
    { L30,   L29,   L28,   L27,   L26,   L25,   L24   }, \
    { L41,   L40,   L39,   L38,   L37,   KC_NO, KC_NO }, \
    { KC_NO, KC_NO, R05,   R06,   R07,   R08,   R09   }, \
    { KC_NO, KC_NO, R19,   R20,   R21,   R22,   R23   }, \
    { R31,   R32,   R33,   R34,   R35,   R36,   R37  }, \
    { R42,   R43,   R44,   R45,   R46,   KC_NO, KC_NO }, \
}


// clang-format on


// EC11K encoders have a different resolution than other EC11 encoders.
// When using the default resolution of 4, if you notice your encoder skipping
// every other tick, lower the resolution to 2.
#define ENCODER_RESOLUTION 2


// Allows media codes to properly register in macros and rotary encoder code
#define TAP_CODE_DELAY 10
