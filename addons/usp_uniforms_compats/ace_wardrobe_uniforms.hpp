#define USP_UNIFORM_GLOVES(UniformBase,UniformGloves1,Gloves1,UniformGloves2,Gloves2)\
class UniformBase: ace_wardrobe_base {\
    class modifiableTo {\
        class UniformVariant1 {};\
    };\
};\
class UniformVariant1: ace_wardrobe_base {\
    class modifiableTo {\
        class UniformBase {};\
        components[] = {QUOTE(Gloves1)};\
    };\
};\
class UniformVariant2: ace_wardrobe_base {\
    class modifiableTo {\
        class UniformBase {};\
        components[] = {QUOTE(Gloves2)};\
    };\
}

USP_UNIFORM_GLOVES(USP_SOFTSHELL_G3C,USP_SOFTSHELL_G3C_MX,USP_MECHANIX,USP_SOFTSHELL_G3C_OR,USP_OVERLORD);