BASE_PAIR(TFC_CH_BCAP_BW_AR,TFC_CH_BCAP_AR);
BASE_PAIR(TFC_CH_BCAP_BW_BLUE,TFC_CH_BCAP_BLUE);
BASE_PAIR(TFC_CH_BCAP_BW_MCAM,TFC_CH_BCAP_MCAM);
BASE_PAIR(TFC_CH_BCAP_BW_TW,TFC_CH_BCAP_TW);

HELMET_VISOR(TFC_CH_Helo_Pilot_up,TFC_AH64_Helmet);

//Scrim Helmets
#define SCRIM_HELMET(HelmetBase,HelmetScrim11,HelmetScrim12,HelmetScrim21,HelmetScrim22,HelmetScrim31,HelmetScrim32)\
class HelmetBase: ace_wardrobe_base {\
    class modifiableTo {\
        class HelmetScrim11 {\
            directionalName = "Add light Scrim";\
        };\
        class HelmetScrim21 {\
            directionalName = "Add light Scrim";\
        };\
        class HelmetScrim31 {\
            directionalName = "Add light Scrim";\
        };\
    };\
};\
class HelmetScrim11: ace_wardrobe_base {\
    class modifiableTo {\
        class HelmetBase {\
            directionalName = "Remove light Scrim";\
        };\
        class HelmetScrim12 {\
            directionalName = "Add full Scrim";\
        };\
    };\
};\
class HelmetScrim12: ace_wardrobe_base {\
    class modifiableTo {\
        class HelmetScrim11 {\
            directionalName = "Remove full Scrim";\
        };\
    };\
};\
class HelmetScrim21: ace_wardrobe_base {\
    class modifiableTo {\
        class HelmetBase {\
            directionalName = "Remove light Scrim";\
        };\
        class HelmetScrim22 {\
            directionalName = "Add full Scrim";\
        };\
    };\
};\
class HelmetScrim22: ace_wardrobe_base {\
    class modifiableTo {\
        class HelmetScrim21 {\
            directionalName = "Remove full Scrim";\
        };\
    };\
};\
class HelmetScrim31: ace_wardrobe_base {\
    class modifiableTo {\
        class HelmetBase {\
            directionalName = "Remove light Scrim";\
        };\
        class HelmetScrim32 {\
            directionalName = "Add full Scrim";\
        };\
    };\
};\
class HelmetScrim32: ace_wardrobe_base {\
    class modifiableTo {\
        class HelmetScrim31 {\
            directionalName = "Remove full Scrim";\
        };\
    };\
}

SCRIM_HELMET(TFC_CH_CG634_CADPAT_MT,TFC_CH_CG634_CADPAT_SCRIM_L_01_MT,TFC_CH_CG634_CADPAT_SCRIM_01_MT,TFC_CH_CG634_CADPAT_SCRIM_L_02_MT,TFC_CH_CG634_CADPAT_SCRIM_02_MT,TFC_CH_CG634_CADPAT_SCRIM_L_03_MT,TFC_CH_CG634_CADPAT_SCRIM_03_MT);
SCRIM_HELMET(TFC_CH_CG634_CADPAT_TW,TFC_CH_CG634_CADPAT_SCRIM_L_01_TW,TFC_CH_CG634_CADPAT_SCRIM_01_TW,TFC_CH_CG634_CADPAT_SCRIM_L_02_TW,TFC_CH_CG634_CADPAT_SCRIM_02_TW,TFC_CH_CG634_CADPAT_SCRIM_L_03_TW,TFC_CH_CG634_CADPAT_SCRIM_03_TW);

class TFC_CH_Caiman_CADPAT_MT: ace_wardrobe_base {
    class modifiableTo {
        class TFC_CH_Caiman_CADPAT_MT_Scrim {
            directionalName = "Add Scrim";
        };
    };
};
class TFC_CH_Caiman_CADPAT_MT_Scrim: ace_wardrobe_base {
    class modifiableTo {
        class TFC_CH_Caiman_CADPAT_MT {
            directionalName = "Remove Scrim";
        };
    };
};
class TFC_CH_Caiman_pel_CADPAT_MT: ace_wardrobe_base {
    class modifiableTo {
        class TFC_CH_Caiman_pel_CADPAT_MT_Scrim {
            directionalName = "Add Scrim";
        };
    };
};
class TFC_CH_Caiman_pel_CADPAT_MT_Scrim: ace_wardrobe_base {
    class modifiableTo {
        class TFC_CH_Caiman_pel_CADPAT_MT {
            directionalName = "Remove Scrim";
        };
    };
};
