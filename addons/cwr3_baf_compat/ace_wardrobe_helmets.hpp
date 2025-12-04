#define HELMET_SCRIM(HelmetBase,HelmetScrim)\
class HelmetBase: ace_wardrobe_base {\
    class modifiableTo {\
        class HelmetScrim {};\
    };\
    alternativeActionName = "Add Scrim/Foliage";\
};\
class HelmetScrim: ace_wardrobe_base {\
    class modifiableTo {\
        class HelmetBase {};\
    };\
    alternativeActionName = "Remove Scrim/Foliage";\
}

HELMET_SCRIM(cwr3_b_uk_headgear_m76_dpm_net,cwr3_b_uk_headgear_m76_dpm_camo);
HELMET_SCRIM(cwr3_b_uk_headgear_m76_olive_net,cwr3_b_uk_headgear_m76_camo);
HELMET_SCRIM(cwr3_b_uk_headgear_parahelmet_olive_net,cwr3_b_uk_headgear_parahelmet_camo);
HELMET_SCRIM(cwr3_b_uk_headgear_mk5_helmet_dpm_net,cwr3_b_uk_headgear_mk5_helmet_scrim_dpm);
HELMET_SCRIM(cwr3_b_uk_headgear_mk5_helmet_net,cwr3_b_uk_headgear_mk5_helmet_scrim_camo);

class cwr3_b_uk_headgear_mk5_helmet_scrim_burlap: ace_wardrobe_base {
    class modifiableTo {
        class cwr3_b_uk_headgear_mk5_helmet_scrim_burlap_camo {};
    };
    alternativeActionName = "Add Foliage to Helmet";
};
class cwr3_b_uk_headgear_mk5_helmet_scrim_burlap_camo: ace_wardrobe_base {
    class modifiableTo {
        class cwr3_b_uk_headgear_mk5_helmet_scrim_burlap {};
    };
    alternativeActionName = "Remove Foliage from Helmet";
};
