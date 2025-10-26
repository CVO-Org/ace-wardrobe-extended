#define HELMET_MK6_ESS(HelmetBase,HelmetGoggles,Goggles)\
class HelmetBase: ace_wardrobe_base {\
    class modifiableTo {\
        class HelmetGoggles {};\
    };\
    components[] = {QUOTE(HelmetGoggles)};\
}\

HELMET_MK6_ESS(UK3CB_BAF_H_Mk6_DDPM_C,UK3CB_BAF_H_Mk6_DDPM_F,G_Combat);
HELMET_MK6_ESS(UK3CB_BAF_H_Mk6_DPMT_C,UK3CB_BAF_H_Mk6_DPMT_F,G_Combat);
HELMET_MK6_ESS(UK3CB_BAF_H_Mk6_DPMW_C,UK3CB_BAF_H_Mk6_DPMW_F,G_Combat);

#define HELMET_MK7_ESS(HelmetBase,HelmetGoggles1,HelmetGoggles2,Goggles)\
class HelmetBase: ace_wardrobe_base {\
    class modifiableTo {\
        class HelmetGoggles {};\
    };\
    components[] = {QUOTE(HelmetGoggles)};\
};\
class HelmetGoggles1: ace_wardrobe_base {\
    class modifiableTo {\
        class HelmetGoggles2 {};\
        class HelmetBase {};\
    };\
};\
class HelmetGoggles2: ace_wardrobe_base {\
    class modifiableTo {\
        class HelmetGoggles1 {};\
    };\
}\

HELMET_MK7_ESS(UK3CB_BAF_H_Mk7_Camo_A,UK3CB_BAF_H_Mk7_Camo_ESS_A,UK3CB_BAF_H_Mk7_Camo_CESS_A,G_Combat);
HELMET_MK7_ESS(UK3CB_BAF_H_Mk7_Camo_B,UK3CB_BAF_H_Mk7_Camo_ESS_B,UK3CB_BAF_H_Mk7_Camo_CESS_B,G_Combat);
HELMET_MK7_ESS(UK3CB_BAF_H_Mk7_Camo_C,UK3CB_BAF_H_Mk7_Camo_ESS_C,UK3CB_BAF_H_Mk7_Camo_CESS_C,G_Combat);
HELMET_MK7_ESS(UK3CB_BAF_H_Mk7_Camo_D,UK3CB_BAF_H_Mk7_Camo_ESS_D,UK3CB_BAF_H_Mk7_Camo_CESS_D,G_Combat);

HELMET_MK7_ESS(UK3CB_BAF_H_Mk7_Net_A,UK3CB_BAF_H_Mk7_Net_ESS_A,UK3CB_BAF_H_Mk7_Net_CESS_A,G_Combat);
HELMET_MK7_ESS(UK3CB_BAF_H_Mk7_Net_B,UK3CB_BAF_H_Mk7_Net_ESS_B,UK3CB_BAF_H_Mk7_Net_CESS_B,G_Combat);
HELMET_MK7_ESS(UK3CB_BAF_H_Mk7_Net_C,UK3CB_BAF_H_Mk7_Net_ESS_C,UK3CB_BAF_H_Mk7_Net_CESS_C,G_Combat);
HELMET_MK7_ESS(UK3CB_BAF_H_Mk7_Net_D,UK3CB_BAF_H_Mk7_Net_ESS_D,UK3CB_BAF_H_Mk7_Net_CESS_D,G_Combat);
