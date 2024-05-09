#ifdef KEY_OVERRIDE_ENABLE

#    undef KO
#    define KO(name, mod, modded_key, new_key) const key_override_t name = ko_make_basic(mod, modded_key, new_key);

#    include "features/key_overrides.def"

#    undef KO
#    define KO(name, mod, modded_key, new_key) &name,

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
#    include "features/key_overrides.def"
    NULL // Null terminate the array of overrides!
};
#endif