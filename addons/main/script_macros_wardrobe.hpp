//Uniform with Variants for Gloves, Rolled Up and Combined Gloves+Rolled Up
#define UNIFORM_GLOVES_ROLLED(UniformBase,UniformGloves,UniformRolled,UniformGlovesRolled)\
class UniformBase: ace_wardrobe_base {\
    class modifiableTo {\
        class UniformGloves {};\
        class UniformRolled {};\
    };\
};\
class UniformGloves: ace_wardrobe_base_U_gloves_on {\
    class modifiableTo {\
        class UniformBase {};\
        class UniformGlovesRolled {};\
    };\
};\
class UniformRolled: ace_wardrobe_base_U_sleeves_up {\
    class modifiableTo {\
        class UniformBase {};\
        class UniformGlovesRolled {};\
    };\
};\
class UniformGlovesRolled: ace_wardrobe_base {\
    class modifiableTo {\
        class UniformGloves {};\
        class UniformRolled {};\
    };\
}

//Uniform with Gloves as Component, and Sleeves Rolled up and Combined
#define UNIFORM_GLOVES_ROLLED_COMPONENT(UniformBase,UniformGloves,UniformRolled,UniformGlovesRolled,Gloves)\
class UniformBase: ace_wardrobe_base {\
    class modifiableTo {\
        class UniformGloves {};\
        class UniformRolled {};\
    };\
};\
class UniformGloves: ace_wardrobe_base_U_gloves_on {\
    class modifiableTo {\
        class UniformBase {};\
        class UniformGlovesRolled {};\
    };\
    components[] = {QUOTE(Gloves)};\
};\
class UniformRolled: ace_wardrobe_base_U_sleeves_up {\
    class modifiableTo {\
        class UniformBase {};\
        class UniformGlovesRolled {};\
    };\
};\
class UniformGlovesRolled: ace_wardrobe_base {\
    class modifiableTo {\
        class UniformGloves {};\
        class UniformRolled {};\
    };\
    components[] = {QUOTE(Gloves)};\
}

//Uniform with Gloves and Component
#define UNIFORM_GLOVES_COMPONENT(UniformBase,UniformGloves,Gloves)\
class UniformBase: ace_wardrobe_base_U_gloves_off {\
    class modifiableTo {\
        class UniformGloves {};\
    };\
};\
class UniformGloves: ace_wardrobe_base_U_gloves_on {\
    class modifiableTo {\
        class UniformBase {};\
    };\
    components[] = {QUOTE(Gloves)};\
}


//Uniform with a Variant with Gloves and a Variant with Sleeves Rolled up, BUT not combined
#define UNIFORM_GLOVES_ROLLED2(UniformBase,UniformGloves,UniformRolled)\
class UniformBase: ace_wardrobe_base {\
    class modifiableTo {\
        class UniformGloves {};\
        class UniformRolled {};\
    };\
};\
class UniformGloves: ace_wardrobe_base_U_gloves_on {\
    class modifiableTo {\
        class UniformBase {};\
    };\
};\
class UniformRolled: ace_wardrobe_base_U_sleeves_up {\
    class modifiableTo {\
        class UniformBase {};\
    };\
}

//Helmet with Goggles on, and Cover Front or Back
#define HELMET_GOGGLES_COVER(HelmetBase,HelmetGoggles,HelmetCoverFront,HelmetCoverBack,Goggles)\
class HelmetBase: ace_wardrobe_base_H_goggles_off {\
    class modifiableTo {\
        class HelmetGoggles {};\
    };\
};\
class HelmetGoggles: ace_wardrobe_base_H_goggles_on {\
    class modifiableTo {\
        class HelmetCoverFront {};\
        class HelmetCoverBack {};\
    };\
    components[] = {QUOTE(Goggles)};\
};\
class HelmetCoverFront: ace_wardrobe_base_H_goggles_on {\
    class modifiableTo {\
        class HelmetGoggles {};\
        class HelmetCoverBack {};\
    };\
    components[] = {QUOTE(Goggles)};\
};\
class HelmetCoverBack: ace_wardrobe_base_H_goggles_on {\
    class modifiableTo {\
        class HelmetCoverFront {};\
        class HelmetGoggles {};\
    };\
    components[] = {QUOTE(Goggles)};\
}

//Helmet with Goggles Component
#define HELMET_GOGGLES_COMPONENT(HelmetBase,HelmetGoggles,Goggles)\
class HelmetBase: ace_wardrobe_base_H_goggles_off {\
    class modifiableTo {\
        class HelmetGoggles {};\
    };\
};\
class HelmetGoggles: ace_wardrobe_base_H_goggles_on {\
    class modifiableTo {\
        class HelmetBase {};\
    };\
    components[] = {QUOTE(Goggles)};\
}
