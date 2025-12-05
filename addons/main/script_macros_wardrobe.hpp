// Base
#define BASIC3(variant1,variant2,variant3,base1,base2,base3)\
class variant1: base1 {\
    class modifiableTo {\
        class variant2 {};\
        class variant3 {};\
    };\
};\
class variant2: base2 {\
    class modifiableTo {\
        class variant1 {};\
        class variant3 {};\
    };\
};\
class variant3: base3 {\
    class modifiableTo {\
        class variant1 {};\
        class variant2 {};\
    };\
}

#define BASE_TRIPLET(variant1,variant2,variant3)\
BASIC3(variant1,variant2,variant3,ACEWARDROBE(base),ACEWARDROBE(base),ACEWARDROBE(base))


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

//Boonie Hat with a Variant with Rolled Up Sides
#define BOONIE_ROLLED(Boonie,BoonieRolled)\
class Boonie: ace_wardrobe_base {\
    class modifiableTo {\
        class BoonieRolled {};\
    };\
};\
class BoonieRolled: ace_wardrobe_base {\
    class modifiableTo {\
        class Boonie {};\
    };\
}

//Helmet with Goggles Up/Down but no Component
#define HELMET_GOGGLES2(HelmetGogglesUp,HelmetGogglesDown)\
class HelmetGogglesUp: ace_wardrobe_base_H_goggles_off {\
    class modifiableTo {\
        class HelmetGogglesDown {};\
    };\
};\
class HelmetGogglesDown: ace_wardrobe_base_H_goggles_on {\
    class modifiableTo {\
        class HelmetGogglesUp {};\
    };\
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


//Helmet with 2 Variants and Goggles
#define HELMET_2VARIANTS_GOGGLES(HelmetV1,HelmetV2,HelmetV1Goggles,HelmetV2Goggles,Component)\
class HelmetV1: ace_wardrobe_base {\
    class modifiableTo {\
        class HelmetV2 {};\
        class HelmetV1Goggles {};\
    };\
};\
class HelmetV2: ace_wardrobe_base {\
    class modifiableTo {\
        class HelmetV1 {};\
        class HelmetV2Goggles {};\
    };\
};\
class HelmetV1Goggles: ace_wardrobe_base {\
    class modifiableTo {\
        class HelmetV2Goggles {};\
        class HelmetV1 {};\
    };\
    components[] = { QUOTE(Component) };\
};\
class HelmetV2Goggles: ace_wardrobe_base {\
    class modifiableTo {\
        class HelmetV1Goggles {};\
        class HelmetV2 {};\
    };\
    components[] = { QUOTE(Component) };\
}



//Facemask with Goggles
#define FACEMASK_GOGGLES(FaceMaskBase,FaceMaskGoggles,Goggles)\
class FaceMaskBase: ace_wardrobe_base {\
    class modifiableTo {\
        class FaceMaskGoggles {};\
    };\
    components[] = {QUOTE(FaceMaskBase)};\
};\
class FaceMaskGoggles: ace_wardrobe_base {\
    class modifiableTo {\
        class FaceMaskBase {};\
    };\
    components[] = {QUOTE(FaceMaskBase),QUOTE(Goggles)};\
}

//Facemask with 2 Variants of Goggles
#define FACEMASK_GOGGLES2(FaceMaskBase,FaceMaskGoggles1,FaceMaskGoggles2,Goggles1,Goggles2)\
class FaceMaskBase: ace_wardrobe_base {\
    class modifiableTo {\
        class FaceMaskGoggles1 {};\
        class FaceMaskGoggles2 {};\
    };\
    components[] = {QUOTE(FaceMaskBase)};\
};\
class FaceMaskGoggles1: ace_wardrobe_base {\
    class modifiableTo {\
        class FaceMaskBase {};\
    };\
    components[] = {QUOTE(FaceMaskBase),QUOTE(Goggles1)};\
};\
class FaceMaskGoggles2: ace_wardrobe_base {\
    class modifiableTo {\
        class FaceMaskBase {};\
    };\
    components[] = {QUOTE(FaceMaskBase),QUOTE(Goggles2)};\
}

//Uniform with 2 types of rolled up
#define UNIFORM_SLEEVES2(UniformBase,UniformRolled1,UniformRolled2)\
class UniformBase: ace_wardrobe_base_U_sleeves_down {\
    class modifiableTo {\
        class UniformRolled1 {};\
    };\
};\
class UniformRolled1: ace_wardrobe_base {\
    class modifiableTo {\
        class UniformBase {};\
        class UniformRolled2 {};\
    };\
};\
class UniformRolled2: ace_wardrobe_base_U_sleeves_up {\
    class modifiableTo {\
        class UniformRolled1 {};\
    };\
}

//Helmets with a Scrim and No Scrim Version
#define HELMET_SCRIM(HelmetBase,HelmetScrim)\
class HelmetBase: ace_wardrobe_base {\
    class modifiableTo {\
        class HelmetScrim {\
            directionalActionName = "Add Scrim/Foliage to Helmet";\
        };\
    };\
};\
class HelmetScrim: ace_wardrobe_base {\
    class modifiableTo {\
        class HelmetBase {\
            directionalActionName = "Remove Scrim/Foliage from Helmet";\
        };\
    };\
}
