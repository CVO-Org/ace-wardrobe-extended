class UAF_H_M92_Cover: ace_wardrobe_base_H_goggles_off {
    class modifiableTo {
        class UAF_H_M92_Cover_GG {};
    };
};
class UAF_H_M92_Cover_GG: ace_wardrobe_base_H_goggles_on {
    class modifiableTo {
        class UAF_H_M92_Cover_GG_CF {};
        class UAF_H_M92_Cover_GG_CB {};
    };
    component[] = {QUOTE(CUP_G_ESS_BLK)};
};
class UAF_H_M92_Cover_GG_CF: ace_wardrobe_base_H_goggles_on {
    class modifiableTo {
        class UAF_H_M92_Cover_GG {};
        class UAF_H_M92_Cover_GG_CB {};
    };
    component[] = {QUOTE(CUP_G_ESS_BLK)};
};
class UAF_H_M92_Cover_GG_CB: ace_wardrobe_base_H_goggles_on {
    class modifiableTo {
        class UAF_H_M92_Cover_GG_CF {};
        class UAF_H_M92_Cover_GG {};
    };
    component[] = {QUOTE(CUP_G_ESS_BLK)};
};
