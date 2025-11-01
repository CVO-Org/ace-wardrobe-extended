#include "script_component.hpp"

class CfgPatches {
    class ADDON {

        // Meta information for editor
        name = ADDON_NAME;
        author = "$STR_mod_author";
        authors[] = {"OverlordZorn [CVO]", "Andx [TTT]"};

        url = "$STR_mod_URL";

        VERSION_CONFIG;

        // Addon Specific Information
        // Minimum compatible version. When the game's version is lower, pop-up warning will appear when launching the game.
        requiredVersion = 2.02;

        // Required addons, used for setting load order.
        // When any of the addons is missing, pop-up warning will appear when launching the game.
        requiredAddons[] = {
            QPVAR(main),
            "UK3CB_Factions_AAF_B", //Cant be bothered figuring out each item I touched for this, so we just require all Addons that have Uniforms/Vests/Goggles
            "UK3CB_Factions_AAF_I",
            "UK3CB_Factions_AAF_O",
            "UK3CB_Factions_ANP_B",
            "UK3CB_Factions_ADA_B",
            "UK3CB_Factions_ADA_I",
            "UK3CB_Factions_ADA_O",
            "UK3CB_Factions_ADC_B",
            "UK3CB_Factions_ADC_C",
            "UK3CB_Factions_ADC_I",
            "UK3CB_Factions_ADC_O",
            "UK3CB_Factions_FIA_B",
            "UK3CB_Factions_FIA_I",
            "UK3CB_Factions_FIA_O",
            "UK3CB_Factions_GAF_B",
            "UK3CB_Factions_GAF_I",
            "UK3CB_Factions_GAF_O",
            "UK3CB_Factions_Headgear",
            "UK3CB_Factions_Headgear2",
            "UK3CB_Factions_Equipment_CW_Headgear_US",
            "UK3CB_Factions_Equipment_CW_Headgear_Soviet",
            "UK3CB_Factions_ION_B_Desert",
            "UK3CB_Factions_ION_B_Urban",
            "UK3CB_Factions_ION_B_Winter",
            "UK3CB_Factions_ION_B_Woodland",
            "UK3CB_Factions_ION_I_Desert",
            "UK3CB_Factions_ION_I_Urban",
            "UK3CB_Factions_ION_I_Winter",
            "UK3CB_Factions_ION_I_Woodland",
            "UK3CB_Factions_ION_O_Desert",
            "UK3CB_Factions_ION_O_Urban",
            "UK3CB_Factions_ION_O_Winter",
            "UK3CB_Factions_ION_O_Woodland",
            "UK3CB_Factions_KDF_I",
            "UK3CB_Factions_KDF_O",
            "UK3CB_Factions_KRG_B",
            "UK3CB_Factions_KRG_O",
            "UK3CB_Factions_KRG_I",
            "UK3CB_Factions_LDF_B",
            "UK3CB_Factions_LDF_O",
            "UK3CB_Factions_LDF_I",
            "UK3CB_Factions_LFR_B",
            "UK3CB_Factions_LFR_O",
            "UK3CB_Factions_LFR_I",
            "UK3CB_Factions_LNM_B",
            "UK3CB_Factions_LNM_I",
            "UK3CB_Factions_LNM_O",
            "UK3CB_Factions_LSM_B",
            "UK3CB_Factions_LSM_O",
            "UK3CB_Factions_LSM_I",
            "UK3CB_Factions_MDF_B",
            "UK3CB_Factions_MDF_O",
            "UK3CB_Factions_MDF_I",
            "UK3CB_Factions_MEC_B",
            "UK3CB_Factions_MEC_O",
            "UK3CB_Factions_MEC_I",
            "UK3CB_Factions_MEE_O",
            "UK3CB_Factions_MEE_I",
            "UK3CB_Factions_MEI_B",
            "UK3CB_Factions_MEI_O",
            "UK3CB_Factions_MEI_I",
            "UK3CB_Factions_NAP_B",
            "UK3CB_Factions_NAP_O",
            "UK3CB_Factions_NAP_I",
            "UK3CB_Factions_NFA_B",
            "UK3CB_Factions_NFA_O",
            "UK3CB_Factions_NFA_I",
            "UK3CB_Factions_NPD_B",
            "UK3CB_Factions_NPD_O",
            "UK3CB_Factions_NPD_I",
            "UK3CB_Factions_TKA_B",
            "UK3CB_Factions_TKA_O",
            "UK3CB_Factions_TKA_I",
            "UK3CB_Factions_TKC_B",
            "UK3CB_Factions_TKC_O",
            "UK3CB_Factions_TKC_I",
            "UK3CB_Factions_TKM_B",
            "UK3CB_Factions_TKM_O",
            "UK3CB_Factions_TKM_I",
            "UK3CB_Factions_TKP_B",
            "UK3CB_Factions_TKP_O",
            "UK3CB_Factions_TKP_I",
            "UK3CB_Factions_Equipment_CW_Soviet_Uniforms",
            "UK3CB_Factions_UN_B",
            "UK3CB_Factions_UN_I",
            "UK3CB_Factions_CW_US_B_LATE",
            "UK3CB_Factions_CW_US_B_EARLY",
            "UK3CB_Factions_CW_SOV_O_LATE",
            "UK3CB_Factions_CW_SOV_O_EARLY",
            "UK3CB_Factions_CSAT_A_O",
            "UK3CB_Factions_CSAT_B_O",
            "UK3CB_Factions_CSAT_G_O",
            "UK3CB_Factions_CSAT_F_O",
            "UK3CB_Factions_CSAT_N_O",
            "UK3CB_Factions_CSAT_M_O",
            "UK3CB_Factions_CSAT_U_O",
            "UK3CB_Factions_CSAT_S_O",
            "UK3CB_Factions_CSAT_W_O",
            "UK3CB_Factions_Facegear"
        };

        // Optional. If this is 1, if any of requiredAddons[] entry is missing in your game the entire config will be ignored and return no error (but in rpt) so useful to make a compat Mod (Since Arma 3 2.14)
        skipWhenMissingDependencies = 1;

        // List of objects (CfgVehicles classes) contained in the addon. Important also for Zeus content (units and groups)
        units[] = {};

        // List of weapons (CfgWeapons classes) contained in the addon.
        weapons[] = {};

    };
};

#include "ace_wardrobe.hpp"
