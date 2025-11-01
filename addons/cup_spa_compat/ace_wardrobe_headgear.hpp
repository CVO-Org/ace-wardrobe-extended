#define SPA_HELMET_GOGGLES(HelmetBase,HelmetGoggles,HelmetCoverFront,HelmetCoverBack,Goggles)\
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
    component[] = {QUOTE(Goggles)};\
};\
class HelmetCoverFront: ace_wardrobe_base_H_goggles_on {\
    class modifiableTo {\
        class HelmetGoggles {};\
        class HelmetCoverBack {};\
    };\
    component[] = {QUOTE(Goggles)};\
};\
class HelmetCoverBack: ace_wardrobe_base_H_goggles_on {\
    class modifiableTo {\
        class HelmetCoverFront {};\
        class HelmetGoggles {};\
    };\
    component[] = {QUOTE(Goggles)};\
}

SPA_HELMET_GOGGLES(Flex_CUP_SPA_H_M92_Cover,Flex_CUP_SPA_H_M92_Cover_GG,Flex_CUP_SPA_H_M92_Cover_GG_CF,Flex_CUP_SPA_H_M92_Cover_GG_CB,CUP_G_ESS_BLK);
SPA_HELMET_GOGGLES(Flex_CUP_SPA_H_M92_Cover_Arid,Flex_CUP_SPA_H_M92_Cover_GG_Arid,Flex_CUP_SPA_H_M92_Cover_GG_CF_Arid,FlexFlex_CUP_SPA_H_M92_Cover_GG_CB_Arid_CUP_SPA_H_M92_Cover_GG_CB,CUP_G_ESS_BLK);
