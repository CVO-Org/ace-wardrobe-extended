UNIFORM_SLEEVES(CUP_U_O_RUARMY_DesertEMR,CUP_U_O_RUARMY_DesertEMR_2);
UNIFORM_SLEEVES(CUP_U_O_RUARMY_DesertEMR_VDV,CUP_U_O_RUARMY_DesertEMR_2_VDV);
UNIFORM_SLEEVES(CFP_BDU_ANP,CFP_BDU_ANP2);
UNIFORM_SLEEVES(CFP_BDU_IA_DCU,CFP_BDU_IA_DCU2);
UNIFORM_SLEEVES(CFP_BDU_Green,CFP_BDU_Green2);
UNIFORM_SLEEVES(CFP_BDU_Tan,CFP_BDU_Tan2);
UNIFORM_SLEEVES(CFP_BDU_UPDFM81,CFP_BDU_UPDFM812);
UNIFORM_SLEEVES(CFP_BDU_UPDFM812,CFP_BDU_UPDFMarpat2);
UNIFORM_SLEEVES(CFP_BDU_DBDU,CFP_BDU_DBDU2);
UNIFORM_SLEEVES(CFP_BDU_Wdl_Mali,CFP_BDU_Wdl_Mali2);

UNIFORM_SLEEVES(CFP_75th_CRYE_V1b_Full,CFP_75th_CRYE_V1b_Sleeved);
UNIFORM_SLEEVES(CFP_75th_CRYE_V2b_Full,CFP_75th_CRYE_V2b_Sleeved);
UNIFORM_SLEEVES(CFP_75th_CRYE_V3_Full,CFP_75th_CRYE_V3_Sleeved);
UNIFORM_SLEEVES(CFP_75th_CRYE_V3b_Full,CFP_75th_CRYE_V3b_Sleeved);
UNIFORM_SLEEVES(CFP_75th_CRYE_V4_Full,CFP_75th_CRYE_V4_Sleeved);
UNIFORM_SLEEVES(CFP_75th_CRYE_V4b_Full,CFP_75th_CRYE_V4b_Sleeved);

#define UNIFORM_SLEEVES_2(UniformBase,UniformRolled1,UniformRolled2)\
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

UNIFORM_SLEEVES_2(CFP_BDU_IRAN,CFP_BDU_IRAN2,CFP_BDU_IRAN3);
UNIFORM_SLEEVES_2(CFP_BDU_RGDPM,CFP_BDU_RGDPM2,CFP_BDU_RGDPM3);
UNIFORM_SLEEVES_2(CFP_BDU_M81Iraq,CFP_BDU_M81Iraq2,CFP_BDU_M81Iraq3);
UNIFORM_SLEEVES_2(CFP_BDU_M81Mali,CFP_BDU_M81Mali2,CFP_BDU_M81Mali3);
UNIFORM_SLEEVES_2(CFP_BDU_M81Sudan,CFP_BDU_M81Sudan_2,CFP_BDU_M81Sudan_3);
UNIFORM_SLEEVES_2(CFP_BDU_M81,CFP_BDU_M812,CFP_BDU_M813);
UNIFORM_SLEEVES_2(CFP_BDU_OD_Sudan,CFP_BDU_OD_Sudan2,CFP_BDU_OD_Sudan3);

class CFP_BDU_Marpat: ace_wardrobe_base {
    class modifiableTo {
        class CFP_BDU_Marpat1 {};
        class CFP_BDU_Marpat2 {};
    };
};

class CFP_BDU_Marpat1: ace_wardrobe_base {
    class modifiableTo {
        class CFP_BDU_Marpat {};
    };
};

class CFP_BDU_Marpat2: ace_wardrobe_base {
    class modifiableTo {
        class CFP_BDU_Marpat {};
    };
};

//ToDo Gloves + Rolled
CFP_BDU_PolyDes
CFP_BDU_PolyDes2
CFP_BDU_PolyDes5
CFP_BDU_PolyDes3
CFP_BDU_PolyDes4