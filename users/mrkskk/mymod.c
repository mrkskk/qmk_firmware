//clang-format on
#include "mymod.h"
static bool my_mod_on = false;

bool my_mod_enabled(void) { return my_mod_on; }
void enable_my_mod(void) { my_mod_on = true; }
void disable_my_mod(void) { my_mod_on = false; }

void toggle_my_mod(void) {
    if (my_mod_on) {
        disable_my_mod();
    } else {
        enable_my_mod();
    }
}
