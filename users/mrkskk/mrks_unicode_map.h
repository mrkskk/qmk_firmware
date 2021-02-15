

#pragma once
#include "quantum.h"

// clang-format off
#define FOREACH_UNICODE(M) \
    M(UALP,  0x0391) /* Α */ \
    M(UBET,  0x0392) /* Β */ \
    M(UGAM,  0x0393) /* Γ */ \
    M(UDEL,  0x0394) /* Δ */ \
    M(UEPS,  0x0395) /* Ε */ \
    M(UZET,  0x0396) /* Ζ */ \
    M(UETA,  0x0397) /* Η */ \
    M(UTHE,  0x0398) /* Θ */ \
    M(UIOT,  0x0399) /* Ι */ \
    M(UKAP,  0x039A) /* Κ */ \
    M(ULAM,  0x039B) /* Λ */ \
    M(UMU,   0x039C) /* M */ \
    M(UNU,   0x039D) /* Ν */ \
    M(UXI,   0x039E) /* Ξ */ \
    M(UOMI,  0x039F) /* Ο */ \
    M(UPI,   0x03A0) /* Π */ \
    M(URHO,  0x03A1) /* Ρ */ \
    M(USIG,  0x03A3) /* Σ */ \
    M(UTAU,  0x03A4) /* Τ */ \
    M(UUPS,  0x03A5) /* Υ */ \
    M(UPHI,  0x03A6) /* Φ */ \
    M(UCHI,  0x03A7) /* Χ */ \
    M(UPSI,  0x03A8) /* Ψ */ \
    M(UOME,  0x03A9) /* Ω */ \
    M(LALP,  0x03B1) /* α */ \
    M(LBET,  0x03B2) /* β */ \
    M(LGAM,  0x03B3) /* γ */ \
    M(LDEL,  0x03B4) /* δ */ \
    M(LEPS,  0x03B5) /* ε */ \
    M(LZET,  0x03B6) /* ζ */ \
    M(LETA,  0x03B7) /* η */ \
    M(LTHE,  0x03B8) /* θ */ \
    M(LIOT,  0x03B9) /* ι */ \
    M(LKAP,  0x03BA) /* κ */ \
    M(LLAM,  0x03BB) /* λ */ \
    M(LMU,   0x03BC) /* μ */ \
    M(LNU,   0x03BD) /* ν */ \
    M(LXI,   0x03BE) /* ξ */ \
    M(LOMI,  0x03BF) /* ο */ \
    M(LPI,   0x03C0) /* π */ \
    M(LRHO,  0x03C1) /* ρ */ \
    M(LSIG,  0x03C3) /* σ */ \
    M(LTAU,  0x03C4) /* τ */ \
    M(LUPS,  0x03C5) /* υ */ \
    M(LPHI,  0x03C6) /* φ */ \
    M(LCHI,  0x03C7) /* χ */ \
    M(LPSI,  0x03C8) /* ψ */ \
    M(LOME,  0x03C9) /* ω */ \
    M(THIN,  0x1F914) /* 🤔 */ \
    M(MONE,  0x1F911) /* 🤑 */ \
    M(PART,  0x1F973) /* 🥳 */ \
    M(SMRK,  0x1F60F) /* 😏 */ \
    M(TUMB,  0x1F943) /* 🥃 */ \
    M(THUP,  0x1F44D) /* 👍 */ \
    M(THDN,  0x1F44E) /* 👎 */ \
    M(SUNG,  0x1F60E) /* 😎 */ \
    M(ROFL,  0x1F923) /* 🤣 */ \
    M(POOP,  0x1F4A9) /* 💩 */ \
    M(LARR,  0x2190) /* ← */ \
    M(RARR,  0x2192) /* → */ \
    M(UARR,  0x2191) /* ↑ */ \
    M(DARR,  0x2193) /* ↓ */ \
    M(HARR,  0x2194) /* ↔ */ \
    M(VARR,  0x2195) /* ↕ */ \
    M(ENDH,  0x2013) /* – */ \
    M(EMDH,  0x2014) /* — */ \
    M(LCOE,  0x00F8) /* ø */ \
    M(UCOE,  0x00D8) /* Ø */ \
// clang-format on

#define UC_KEYCODE(name, code)  name = UC(code),        // LALP = UC(0x03B1),

#define UCM_NAME(name, code)    UCM_## name,           // UCM_LALP,
#define UCM_ENTRY(name, code)   [UCM_## name] = code,  // [UCM_LALP] = 0x03B1,
#define UCM_KEYCODE(name, code) name = X(UCM_## name), // LALP = X(UCM_LALP)

#if defined(UNICODE_ENABLE)
enum unicode_keycodes
{
    FOREACH_UNICODE(UC_KEYCODE)
};
#elif defined(UNICODEMAP_ENABLE)
enum unicode_names
{
    FOREACH_UNICODE(UCM_NAME)
};

extern const uint32_t PROGMEM unicode_map[];

enum unicode_keycodes
{
    FOREACH_UNICODE(UCM_KEYCODE)
};
#endif


#define UC_OE XP(LCOE, UCOE)

#define ALPHA XP(LALP, UALP)
#define BETA  XP(LBET, UBET)
#define GAMMA XP(LGAM, UGAM)
#define DELTA XP(LDEL, UDEL)
#define EPSLN XP(LEPS, UEPS)
#define ZETA  XP(LZET, UZET)
#define ETA   XP(LETA, UETA)
#define THETA XP(LTHE, UTHE)
#define IOTA  XP(LIOT, UIOT)
#define KAPPA XP(LKAP, UKAP)
#define LAMBD XP(LLAM, ULAM)
#define GMU   XP(LMU,  UMU)
#define NU    XP(LNU,  UNU)
#define XI    XP(LXI,  UXI)
#define OMCRN XP(LOMI, UOMI)
#define PI    XP(LPI,  UPI)
#define RHO   XP(LRHO, URHO)
#define SIGMA XP(LSIG, USIG)
#define TAU   XP(LTAU, UTAU)
#define UPSLN XP(LUPS, UUPS)
#define PHI   XP(LPHI, UPHI)
#define CHI   XP(LCHI, UCHI)
#define PSI   XP(LPSI, UPSI)
#define OMEGA XP(LOME, UOME)

#define THINK X(THIN)
#define MONEY X(MONE)
#define PARTY X(PART)
#define SMIRK X(SMRK)
#define DRINK X(TUMB)
#define YAY   X(THUP)
#define NAY   X(THDN)
#define COOL  X(SUNG)
#define FUNNY X(ROFL)
#define SHIT  X(POOP)

#define l_arrow X(LARR)
#define r_arrow X(RARR)
#define u_arrow X(UARR)
#define d_arrow X(DARR)
#define lr_arrow X(HARR)
#define ud_arrow X(VARR)
#define en_em_dash XP(ENDH, EMDH)
