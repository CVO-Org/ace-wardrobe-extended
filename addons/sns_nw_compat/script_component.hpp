#define COMPONENT sns_nw_compat
#define COMPONENT_BEAUTIFIED Mod Compat - Service & Supply: New Wave

#include "\x\awx\addons\main\script_mod.hpp"
#include "\x\awx\addons\main\script_macros.hpp"

// Boonie hats with 8 fold-style variants (_1 to _8) per camo.
// Variants 1,2,3,5,6,7,8 are just folded differently and can be freely
// converted into one another. Variant 4 has its brim cut off, so it can be
// reached from any of the other variants but cannot be converted back.
// Usage: BOONIE_HAT(H_Simc_Boon_dcu)
#define BOONIE_HAT(Base)\
class Base##_1: ace_wardrobe_base {\
    class modifiableTo {\
        class Base##_2 {};\
        class Base##_3 {};\
        class Base##_4 {\
            displayName = ECSTRING(main,cut_off_brim);\
        };\
        class Base##_5 {};\
        class Base##_6 {};\
        class Base##_7 {};\
        class Base##_8 {};\
    };\
};\
class Base##_2: ace_wardrobe_base {\
    class modifiableTo {\
        class Base##_1 {};\
        class Base##_3 {};\
        class Base##_4 {\
            displayName = ECSTRING(main,cut_off_brim);\
        };\
        class Base##_5 {};\
        class Base##_6 {};\
        class Base##_7 {};\
        class Base##_8 {};\
    };\
};\
class Base##_3: ace_wardrobe_base {\
    class modifiableTo {\
        class Base##_1 {};\
        class Base##_2 {};\
        class Base##_4 {\
            displayName = ECSTRING(main,cut_off_brim);\
        };\
        class Base##_5 {};\
        class Base##_6 {};\
        class Base##_7 {};\
        class Base##_8 {};\
    };\
};\
class Base##_4: ace_wardrobe_base {\
};\
class Base##_5: ace_wardrobe_base {\
    class modifiableTo {\
        class Base##_1 {};\
        class Base##_2 {};\
        class Base##_3 {};\
        class Base##_4 {\
            displayName = ECSTRING(main,cut_off_brim);\
        };\
        class Base##_6 {};\
        class Base##_7 {};\
        class Base##_8 {};\
    };\
};\
class Base##_6: ace_wardrobe_base {\
    class modifiableTo {\
        class Base##_1 {};\
        class Base##_2 {};\
        class Base##_3 {};\
        class Base##_4 {\
            displayName = ECSTRING(main,cut_off_brim);\
        };\
        class Base##_5 {};\
        class Base##_7 {};\
        class Base##_8 {};\
    };\
};\
class Base##_7: ace_wardrobe_base {\
    class modifiableTo {\
        class Base##_1 {};\
        class Base##_2 {};\
        class Base##_3 {};\
        class Base##_4 {\
            displayName = ECSTRING(main,cut_off_brim);\
        };\
        class Base##_5 {};\
        class Base##_6 {};\
        class Base##_8 {};\
    };\
};\
class Base##_8: ace_wardrobe_base {\
    class modifiableTo {\
        class Base##_1 {};\
        class Base##_2 {};\
        class Base##_3 {};\
        class Base##_4 {\
            displayName = ECSTRING(main,cut_off_brim);\
        };\
        class Base##_5 {};\
        class Base##_6 {};\
        class Base##_7 {};\
    };\
}

// Helmets with a loose/tight chinstrap variant.
// Usage: HELMET_CHINSTRAP(HelmetLoose,HelmetTight)
#define HELMET_CHINSTRAP(Loose,Tight)\
class Loose: ace_wardrobe_base {\
    class modifiableTo {\
        class Tight {\
            displayName = ECSTRING(main,tighten_chinstrap);\
        };\
    };\
};\
class Tight: ace_wardrobe_base {\
    class modifiableTo {\
        class Loose {\
            displayName = ECSTRING(main,loosen_chinstrap);\
        };\
    };\
}

// Uniforms with 3 sleeve states: Low (down), Mid (rolled to the forearm) and
// High (rolled all the way up). Mid can go either up to High or down to Low;
// there's no direct Low <-> High jump. Low is the only "sleeves down" state,
// Mid and High both count as "sleeves up" (see ace_wardrobe_base_U_sleeves_*).
// Usage: UNIFORM_ROLLED3(Low,Mid,High)
#define UNIFORM_ROLLED3(Low,Mid,High)\
class Low: ace_wardrobe_base_U_sleeves_down {\
    class modifiableTo {\
        class Mid {\
            displayName = ECSTRING(main,roll_up_sleeves);\
        };\
    };\
};\
class Mid: ace_wardrobe_base_U_sleeves_up {\
    class modifiableTo {\
        class Low {\
            displayName = ECSTRING(main,roll_down_sleeves);\
        };\
        class High {\
            displayName = ECSTRING(main,roll_up_sleeves);\
        };\
    };\
};\
class High: ace_wardrobe_base_U_sleeves_up {\
    class modifiableTo {\
        class Mid {\
            displayName = ECSTRING(main,roll_down_sleeves);\
        };\
    };\
}
