#define FIN_GLOVES_ROLLED(UniformBase,UniformGloves,UniformRolled,UniformGlovesRolled)\
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

FIN_GLOVES_ROLLED(Flex_CUP_FIN_Combat_Uniform,Flex_CUP_FIN_Combat_Uniform_Gloves,Flex_CUP_FIN_Combat_Uniform_Rolled,Flex_CUP_FIN_Combat_Uniform_Gloves_Rolled);

class Flex_CUP_FIN_Combat_Uniform_Pads: ace_wardrobe_base {
    class modifiableTo {
        class Flex_CUP_FIN_Combat_Uniform_Pads_Gloves {};
        class Flex_CUP_FIN_Combat_Uniform_Pads_Rolled {};
    };
};
class Flex_CUP_FIN_Combat_Uniform_Pads_Gloves: ace_wardrobe_base_U_gloves_on {
    class modifiableTo {
        class Flex_CUP_FIN_Combat_Uniform_Pads {};
    };
};
class Flex_CUP_FIN_Combat_Uniform_Pads_Rolled: ace_wardrobe_base_U_sleeves_up {
    class modifiableTo {
        class Flex_CUP_FIN_Combat_Uniform_Pads {};
    };
};

class Flex_CUP_FIN_Combat_Uniform_Tshirt: ace_wardrobe_base_U_gloves_off {
    class modifiableTo {
        class Flex_CUP_FIN_Combat_Uniform_Tshirt_Gloves {};
    };
};
class Flex_CUP_FIN_Combat_Uniform_Tshirt_Gloves: ace_wardrobe_base_U_gloves_on {
    class modifiableTo {
        class Flex_CUP_FIN_Combat_Uniform_Tshirt {};
    };
};
