

#ifdef UNICODEMAP_ENABLE
#include "mrkskk.h"
const uint32_t PROGMEM unicode_map[] = {
    FOREACH_UNICODE(UCM_ENTRY)
};
#endif