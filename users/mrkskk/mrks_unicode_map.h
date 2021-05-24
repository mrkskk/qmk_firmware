
#ifdef UNICODEMAP_ENABLE
#pragma once
#include "quantum.h"



// clang-format off
#define FOREACH_UNICODE(M) \
    M(LARR,  0x2190) /* ← */ \
    M(RARR,  0x2192) /* → */ \
    M(UARR,  0x2191) /* ↑ */ \
    M(DARR,  0x2193) /* ↓ */ \
    M(HARR,  0x2194) /* ↔ */ \
    M(VARR,  0x2195) /* ↕ */ \
    M(ENDH,  0x2013) /* – */ \
    M(EMDH,  0x2014) /* — */ \
    M(ACUTESIGN, 0x00B4) /* ´ */ \
    M(GRAVESIGN, 0x0060) /* ´ */ \


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

#define l_arrow X(LARR)
#define r_arrow X(RARR)
#define u_arrow X(UARR)
#define d_arrow X(DARR)
#define lr_arrow X(HARR)
#define ud_arrow X(VARR)
#define en_em_dash XP(ENDH, EMDH)
#define ACUTE X(ACUTESIGN)
#define GRAVE X(GRAVESIGN)

#endif
*/
