BASE_PAIR(TFC_CH_BCAP_BW_AR,TFC_CH_BCAP_AR);
BASE_PAIR(TFC_CH_BCAP_BW_BLUE,TFC_CH_BCAP_BLUE);
BASE_PAIR(TFC_CH_BCAP_BW_MCAM,TFC_CH_BCAP_MCAM);
BASE_PAIR(TFC_CH_BCAP_BW_TW,TFC_CH_BCAP_TW);

HELMET_VISOR(TFC_CH_Helo_Pilot_up,TFC_AH64_Helmet);

//Scrim Helmets
// Helmet with 3 scrim pattern variants, each having light (L) and full versions.
// Parameters:
//   HelmetBase      - The base helmet class (no scrim)
//   HelmetScrim11   - Scrim pattern 1, light version
//   HelmetScrim12   - Scrim pattern 1, full version
//   HelmetScrim21   - Scrim pattern 2, light version
//   HelmetScrim22   - Scrim pattern 2, full version
//   HelmetScrim31   - Scrim pattern 3, light version
//   HelmetScrim32   - Scrim pattern 3, full version
// Usage: SCRIM_HELMET(Base, Scrim1Light, Scrim1Full, Scrim2Light, Scrim2Full, Scrim3Light, Scrim3Full)
#define SCRIM_HELMET(HelmetBase,HelmetScrim11,HelmetScrim12,HelmetScrim21,HelmetScrim22,HelmetScrim31,HelmetScrim32)\
class HelmetBase: ace_wardrobe_base {\
    class modifiableTo {\
        class HelmetScrim11 {\
            displayName = ECSTRING(main,add_scrim_light);\
        };\
        class HelmetScrim21 {\
            displayName = ECSTRING(main,add_scrim_light);\
        };\
        class HelmetScrim31 {\
            displayName = ECSTRING(main,add_scrim_light);\
        };\
    };\
};\
class HelmetScrim11: ace_wardrobe_base {\
    class modifiableTo {\
        class HelmetBase {\
            displayName = ECSTRING(main,remove_scrim_light);\
        };\
        class HelmetScrim12 {\
            displayName = ECSTRING(main,add_scrim_full);\
        };\
    };\
};\
class HelmetScrim12: ace_wardrobe_base {\
    class modifiableTo {\
        class HelmetScrim11 {\
            displayName = ECSTRING(main,remove_scrim_full);\
        };\
    };\
};\
class HelmetScrim21: ace_wardrobe_base {\
    class modifiableTo {\
        class HelmetBase {\
            displayName = ECSTRING(main,remove_scrim_light);\
        };\
        class HelmetScrim22 {\
            displayName = ECSTRING(main,add_scrim_full);\
        };\
    };\
};\
class HelmetScrim22: ace_wardrobe_base {\
    class modifiableTo {\
        class HelmetScrim21 {\
            displayName = ECSTRING(main,downgrade_scrim);\
        };\
    };\
};\
class HelmetScrim31: ace_wardrobe_base {\
    class modifiableTo {\
        class HelmetBase {\
            displayName = ECSTRING(main,remove_scrim_light);\
        };\
        class HelmetScrim32 {\
            displayName = ECSTRING(main,add_scrim_full);\
        };\
    };\
};\
class HelmetScrim32: ace_wardrobe_base {\
    class modifiableTo {\
        class HelmetScrim31 {\
            displayName = ECSTRING(main,downgrade_scrim);\
        };\
    };\
}

SCRIM_HELMET(TFC_CH_CG634_CADPAT_MT,TFC_CH_CG634_CADPAT_SCRIM_L_01_MT,TFC_CH_CG634_CADPAT_SCRIM_01_MT,TFC_CH_CG634_CADPAT_SCRIM_L_02_MT,TFC_CH_CG634_CADPAT_SCRIM_02_MT,TFC_CH_CG634_CADPAT_SCRIM_L_03_MT,TFC_CH_CG634_CADPAT_SCRIM_03_MT);
SCRIM_HELMET(TFC_CH_CG634_CADPAT_TW,TFC_CH_CG634_CADPAT_SCRIM_L_01_TW,TFC_CH_CG634_CADPAT_SCRIM_01_TW,TFC_CH_CG634_CADPAT_SCRIM_L_02_TW,TFC_CH_CG634_CADPAT_SCRIM_02_TW,TFC_CH_CG634_CADPAT_SCRIM_L_03_TW,TFC_CH_CG634_CADPAT_SCRIM_03_TW);

class TFC_CH_Caiman_CADPAT_MT: ace_wardrobe_base {
    class modifiableTo {
        class TFC_CH_Caiman_CADPAT_MT_Scrim {
            displayName = ECSTRING(main,add_scrim);
        };
    };
};
class TFC_CH_Caiman_CADPAT_MT_Scrim: ace_wardrobe_base {
    class modifiableTo {
        class TFC_CH_Caiman_CADPAT_MT {
            displayName = ECSTRING(main,remove_scrim);
        };
    };
};
class TFC_CH_Caiman_pel_CADPAT_MT: ace_wardrobe_base {
    class modifiableTo {
        class TFC_CH_Caiman_pel_CADPAT_MT_Scrim {
            displayName = ECSTRING(main,add_scrim);
        };
    };
};
class TFC_CH_Caiman_pel_CADPAT_MT_Scrim: ace_wardrobe_base {
    class modifiableTo {
        class TFC_CH_Caiman_pel_CADPAT_MT {
            displayName = ECSTRING(main,remove_scrim);
        };
    };
};
