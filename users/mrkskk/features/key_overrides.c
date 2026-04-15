#ifdef KEY_OVERRIDE_ENABLE

#    undef KO
#    define KO(name, mod, modded_key, new_key) const key_override_t name = ko_make_basic(mod, modded_key, new_key);
#    undef KO_NEG
#    define KO_NEG(name, mod, neg_mod, modded_key, new_key) const key_override_t name = ko_make_with_layers_and_negmods(mod, modded_key, new_key, ~0, neg_mod);

#    include "features/key_overrides.def"

#    undef KO
#    define KO(name, mod, modded_key, new_key) &name,
#    undef KO_NEG
#    define KO_NEG(name, mod, neg_mod, modded_key, new_key) &name,

// This globally defines all key overrides to be used
const key_override_t *key_overrides[] = {
#    include "features/key_overrides.def"
    NULL // Null terminate the array of overrides!
};
#endif