//clang-format on
#include "mymod.h"

// my mod function. Used to make my own combination of shortcuts, without interfering with existing ones.
// For example my mod held + backspace = delete.
// used to do this with shift but in some apps like vs code shift+backspace will then have to be set as a shortcut for delete.

static bool my_mod_on = false;

bool my_mod_enabled(void) { return my_mod_on; }
void enable_my_mod(void) { my_mod_on = true; }
void disable_my_mod(void) { my_mod_on = false; }
/*
void toggle_my_mod(void) {
    if (my_mod_on) {
        disable_my_mod();
    } else {
        enable_my_mod();
    }
}
*/
