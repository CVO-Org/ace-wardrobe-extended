#define HELMET_MK6_ESS(HelmetBase,HelmetGoggles,Goggles)\
class HelmetBase: ace_wardrobe_base {\
    class modifiableTo {\
        class HelmetGoggles {};\
    };\
    components[] = {QUOTE(HelmetGoggles)};\
    fallbackComponent = QUOTE(G_Combat);\
}

HELMET_MK6_ESS(UK3CB_BAF_H_Mk6_DDPM_C,UK3CB_BAF_H_Mk6_DDPM_F,rhs_ess_black);
HELMET_MK6_ESS(UK3CB_BAF_H_Mk6_DPMT_C,UK3CB_BAF_H_Mk6_DPMT_F,rhs_ess_black);
HELMET_MK6_ESS(UK3CB_BAF_H_Mk6_DPMW_C,UK3CB_BAF_H_Mk6_DPMW_F,rhs_ess_black);

#define HELMET_MK7_ESS(HelmetBase,HelmetGoggles1,HelmetGoggles2,Goggles)\
class HelmetBase: ace_wardrobe_base {\
    class modifiableTo {\
        class HelmetGoggles1 {};\
    };\
};\
class HelmetGoggles1: ace_wardrobe_base {\
    class modifiableTo {\
        class HelmetGoggles2 {};\
        class HelmetBase {};\
    };\
    components[] = {QUOTE(Goggles)};\
    fallbackComponent = QUOTE(G_Combat);\
};\
class HelmetGoggles2: ace_wardrobe_base {\
    class modifiableTo {\
        class HelmetGoggles1 {};\
        class HelmetBase {};\
        components[] = {QUOTE(Goggles)};\
        fallbackComponent = QUOTE(G_Combat);\
    };\
}

HELMET_MK7_ESS(UK3CB_BAF_H_Mk7_Camo_A,UK3CB_BAF_H_Mk7_Camo_ESS_A,UK3CB_BAF_H_Mk7_Camo_CESS_A,rhs_ess_black);
HELMET_MK7_ESS(UK3CB_BAF_H_Mk7_Camo_B,UK3CB_BAF_H_Mk7_Camo_ESS_B,UK3CB_BAF_H_Mk7_Camo_CESS_B,rhs_ess_black);
HELMET_MK7_ESS(UK3CB_BAF_H_Mk7_Camo_C,UK3CB_BAF_H_Mk7_Camo_ESS_C,UK3CB_BAF_H_Mk7_Camo_CESS_C,rhs_ess_black);
HELMET_MK7_ESS(UK3CB_BAF_H_Mk7_Camo_D,UK3CB_BAF_H_Mk7_Camo_ESS_D,UK3CB_BAF_H_Mk7_Camo_CESS_D,rhs_ess_black);

HELMET_MK7_ESS(UK3CB_BAF_H_Mk7_Net_A,UK3CB_BAF_H_Mk7_Net_ESS_A,UK3CB_BAF_H_Mk7_Net_CESS_A,rhs_ess_black);
HELMET_MK7_ESS(UK3CB_BAF_H_Mk7_Net_B,UK3CB_BAF_H_Mk7_Net_ESS_B,UK3CB_BAF_H_Mk7_Net_CESS_B,rhs_ess_black);
HELMET_MK7_ESS(UK3CB_BAF_H_Mk7_Net_C,UK3CB_BAF_H_Mk7_Net_ESS_C,UK3CB_BAF_H_Mk7_Net_CESS_C,rhs_ess_black);
HELMET_MK7_ESS(UK3CB_BAF_H_Mk7_Net_D,UK3CB_BAF_H_Mk7_Net_ESS_D,UK3CB_BAF_H_Mk7_Net_CESS_D,rhs_ess_black);

#define HELMET_MK7_SCRIM(HelmetBase,HelmetESS,Goggles)\
class HelmetBase: ace_wardrobe_base_H_goggles_off {\
    class modifiableTo {\
        class HelmetESS {};\
    };\
};\
class HelmetESS: ace_wardrobe_base_H_goggles_on {\
    class modifiableTo {\
        class HelmetBase {};\
    };\
    components[] = {QUOTE(Goggles)};\
    fallbackComponent = QUOTE(G_Combat);\
}

HELMET_MK7_SCRIM(UK3CB_BAF_H_Mk7_Scrim_A,UK3CB_BAF_H_Mk7_Scrim_ESS_A,rhs_ess_black);
HELMET_MK7_SCRIM(UK3CB_BAF_H_Mk7_Scrim_B,UK3CB_BAF_H_Mk7_Scrim_ESS_B,rhs_ess_black);
HELMET_MK7_SCRIM(UK3CB_BAF_H_Mk7_Scrim_C,UK3CB_BAF_H_Mk7_Scrim_ESS_C,rhs_ess_black);

#define HELMET_CREW_ESS(HelmetBase,HelmetESS,Goggles)\
class HelmetBase: ace_wardrobe_base_H_goggles_off {\
    class modifiableTo {\
        class HelmetESS {};\
    };\
};\
class HelmetESS: ace_wardrobe_base_H_goggles_on {\
    class modifiableTo {\
        class HelmetBase {};\
    };\
    components[] = {QUOTE(Goggles)};\
    fallbackComponent = QUOTE(G_Combat);\
}

HELMET_CREW_ESS(UK3CB_BAF_H_CrewHelmet_DDPM_A,UK3CB_BAF_H_CrewHelmet_DDPM_ESS_A,rhs_ess_black);
HELMET_CREW_ESS(UK3CB_BAF_H_CrewHelmet_DPMT_A,UK3CB_BAF_H_CrewHelmet_DPMT_ESS_A,rhs_ess_black);
HELMET_CREW_ESS(UK3CB_BAF_H_CrewHelmet_DPMW_A,UK3CB_BAF_H_CrewHelmet_DPMW_ESS_A,rhs_ess_black);
HELMET_CREW_ESS(UK3CB_BAF_H_CrewHelmet_A,UK3CB_BAF_H_CrewHelmet_ESS_A,rhs_ess_black);