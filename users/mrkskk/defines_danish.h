// clang-format on
#pragma once

#define EXLM S(KC_1)  // !
#define DQUO S(KC_2)  // "
#define HASH S(KC_3)  // #
#define PERC S(KC_5)  // %
#define QUOT KC_NUHS  // '
#define LPRN S(KC_8)  // (
#define RPRN S(KC_9)  // )

#define ACUT KC_EQL  // ´ (dead)
#define GRV S(ACUT)  // ` (dead)

#define LBRC ALGR(KC_8)  // [
#define RBRC ALGR(KC_9)  //  ]
#define AMPR S(KC_6)     //
#define SLSH S(KC_7)     //  /

#define LABK KC_NUBS     //<
#define RABK S(KC_NUBS)  //>

#define ASTR S(KC_NUHS)  //*
#define EQL S(KC_0)      // =
#define QUES S(KC_MINS)  // ?

#define PLUS KC_PPLS     // +
#define PLUS2 KC_PPLS    // +
#define HAT S(KC_RBRC)   // ^ (dead)
#define DIAE KC_RBRC     // ¨ (dead)
#define TILD ALGR(DIAE)  // ~ (dead)
#define HALF_WIN KC_GRV  // ½
#define PARAG S(KC_GRV)  // §
#define DK_AE KC_SCLN    // Æ
#define DK_OE KC_QUOT    // Ø
#define DK_AA KC_LBRC    // Å
#define MINUS KC_SLSH    // -
#define UNDSC S(MINUS)   // _
#define COL S(KC_DOT)
#define SEMCOL S(KC_COMM)
#define RALT_E ALGR(HMR_O)  // é
#define RALT_N ALGR(HMR_O)  // ñ

// The Danish keymap keys that differ between MAC and WIN OS is defined, and combined to a cross-OS key in oskeys.def
#define LCB_WIN ALGR(KC_7)
#define LCB_MAC LSA(KC_8)
#define RCB_WIN ALGR(KC_0)
#define RCB_MAC LSA(KC_9)

#define PIPE_WIN ALGR(KC_EQL)
#define PIPE_MAC LALT(KC_I)
