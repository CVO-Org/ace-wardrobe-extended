// BOONIE_HAT
BOONIE_HAT(H_Simc_Boon_dcu);
BOONIE_HAT(H_Simc_Boon_desu);
BOONIE_HAT(H_Simc_Boon_m81);

// HELMET_CHINSTRAP(HelmetLoose,HelmetTight);
HELMET_CHINSTRAP(H_Simc_M1_desu_ns,H_Simc_M1_desu_cl);
HELMET_CHINSTRAP(H_Simc_M1_desu_ns_B,H_Simc_M1_desu_B);
HELMET_CHINSTRAP(H_Simc_M1_erdl2_ns,H_Simc_M1_erdl2_alt);
HELMET_CHINSTRAP(H_Simc_M1_erdl2_ns_alt,H_Simc_M1_erdl2_cl);

// H_Simc_M1_erdl_B_alt has a third state (no chinstrap at all), so it can't use HELMET_CHINSTRAP.
class H_Simc_M1_erdl_B_alt: ace_wardrobe_base {
    class modifiableTo {
        class H_Simc_M1_erdl_B_cl_erla {
            displayName = ECSTRING(main,loosen_chinstrap);
        };
        class H_Simc_M1_erdl_B_ns_alt {
            displayName = ECSTRING(main,remove_chinstrap);
        };
    };
};
class H_Simc_M1_erdl_B_cl_erla: ace_wardrobe_base {
    class modifiableTo {
        class H_Simc_M1_erdl_B_alt {
            displayName = ECSTRING(main,tighten_chinstrap);
        };
        class H_Simc_M1_erdl_B_ns_alt {
            displayName = ECSTRING(main,remove_chinstrap);
        };
    };
};
class H_Simc_M1_erdl_B_ns_alt: ace_wardrobe_base {
    class modifiableTo {
        class H_Simc_M1_erdl_B_alt {
            displayName = ECSTRING(main,attach_chinstrap);
        };
        class H_Simc_M1_erdl_B_cl_erla {
            displayName = ECSTRING(main,attach_chinstrap);
        };
    };
};
