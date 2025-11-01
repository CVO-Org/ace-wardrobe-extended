
#define LDF_GLOVES_ROLLED(UniformBase,UniformGloves,UniformRolled,UniformGlovesRolled)\
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

LDF_GLOVES_ROLLED(LDF_Combat_Uniform,LDF_Combat_Uniform_Gloves,LDF_Combat_Uniform_Rolled,LDF_Combat_Uniform_Gloves_Rolled);
LDF_GLOVES_ROLLED(LDF_Combat_Uniform_Arid,LDF_Combat_Uniform_Arid_Gloves,LDF_Combat_Uniform_Arid_Rolled,LDF_Combat_Uniform_Arid_Gloves_Rolled);
