HELMET_GOGGLES_COMPONENT(H_Simc_M1_erdl_ns,H_Simc_M1_erdl_swdg,G_SWDG);
HELMET_GOGGLES_COMPONENT(H_Simc_M1_bitch_flip_ns,H_Simc_M1_bitch_flip_swdg,G_SWDG);
HELMET_GOGGLES_COMPONENT(H_Simc_M1_bitch_ns,H_Simc_M1_bitch_swdg,G_SWDG);

class H_Simc_Hat_Patrol_od7: ace_wardrobe_base {
    class modifiableTo {
        class H_Simc_Hat_Patrol_od7_swdg {};
    };
};
class H_Simc_Hat_Patrol_od7_swdg: ace_wardrobe_base_H_goggles_off {
    class modifiableTo {
        class H_Simc_Hat_Patrol_od7 {};
        class H_Simc_Hat_Patrol_od7_swdg_rear {};
    };
    components[] = {"G_SWDG"};
};
class H_Simc_Hat_Patrol_od7_swdg_rear: ace_wardrobe_base_H_goggles_off {
    class modifiableTo {
        class H_Simc_Hat_Patrol_od7_swdg {};
    };
    components[] = {"G_SWDG"};
};

HELMET_GOGGLES_COMPONENT(H_Simc_M1C_bitch_ns,H_Simc_M1C_bitch_swdg,G_SWDG);

class H_Simc_MC_hat_1:ace_wardrobe_base {
    class modifiableTo {
        class H_Simc_MC_hat_2 {};
        class H_Simc_MC_hat_3 {};
    };
};
class H_Simc_MC_hat_2:ace_wardrobe_base {
    class modifiableTo {
        class H_Simc_MC_hat_1 {};
        class H_Simc_MC_hat_3 {};
    };
};
class H_Simc_MC_hat_3:ace_wardrobe_base {
    class modifiableTo {
        class H_Simc_MC_hat_1 {};
        class H_Simc_MC_hat_2 {};
    };
};

class H_Simc_MC_hat_erdl_1:ace_wardrobe_base {
    class modifiableTo {
        class H_Simc_MC_hat_erdl_2 {};
        class H_Simc_MC_hat_erdl_3 {};
    };
};
class H_Simc_MC_hat_erdl_2:ace_wardrobe_base {
    class modifiableTo {
        class H_Simc_MC_hat_erdl_1 {};
        class H_Simc_MC_hat_erdl_3 {};
    };
};
class H_Simc_MC_hat_erdl_3:ace_wardrobe_base {
    class modifiableTo {
        class H_Simc_MC_hat_erdl_1 {};
        class H_Simc_MC_hat_erdl_2 {};
    };
};
