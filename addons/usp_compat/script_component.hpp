#define COMPONENT usp_compat
#define COMPONENT_BEAUTIFIED Mod Compat - USP

#include "\x\awx\addons\main\script_mod.hpp"
#include "\x\awx\addons\main\script_macros.hpp"

// Auto-generated relationship matrix for the USP G3C uniform family.
// Identifier grammar (order is fixed): [SLEEVE]_[CU]_[KP]_[GLOVE]_[VQ]_<CAMO>
//   SLEEVE: (none, long sleeves) | CS (cut sleeves) | RS (rolled) | RS2 (rolled twice)
//   CU:     (none) | CU (collar up)
//   KP:     (none) | KP (kneepads on)
//   GLOVE:  (none) | MX | OR
//   VQ:     (none, standard boots) | VQ (VQ-style boots)
//
// Rules encoded below:
//   - Sleeves form a chain: (none) <-> RS <-> RS2. Cutting the sleeves (CS) is reachable
//     from any of (none)/RS/RS2, but CS itself is a dead end (no way back).
//   - Collar (CU) and kneepads (KP) are simple independent toggles.
//   - Gloves (MX/OR, plus bare hands) form their own fully-connected set.
//   - Boots (VQ) form a wholly separate set: swapping VQ <-> non-VQ is NOT offered as a
//     wardrobe transition (boots cant be easily changed), so no edges cross that boundary.
//
// Not every combination is modelled by the base mod (mostly among the VQ variants) -
// this macro only links a transition when BOTH sides actually exist for that base uniform.
// Assumes every camo pattern shares the exact same set of modelled combinations as AOR1 (see data.md).
//
// Each modifiableTo entry carries a displayName describing that specific action (per the ACE
// Wardrobe Framework docs, displayName is directional and read from the ORIGIN class's entry;
// if omitted ACE falls back to the target item's own displayName). Generic actions (sleeves,
// collar, kneepads, taking gloves off) use shared stringtable keys in addons/main; the MX/OR
// glove-brand labels are USP-specific so they're left as literal text.
#define USP_G3C_UNIFORMS(CAMO) \
class USP_G3C_##CAMO: ACEWARDROBE(base_U_sleeves_down) { \
    class modifiableTo { \
        class USP_G3C_RS_##CAMO { \
            displayName = ECSTRING(main,roll_sleeves_up); \
        }; \
        class USP_G3C_CS_##CAMO { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_CU_##CAMO { \
            displayName = ECSTRING(main,collar_up); \
        }; \
        class USP_G3C_KP_##CAMO { \
            displayName = ECSTRING(main,kneepads_on); \
        }; \
        class USP_G3C_MX_##CAMO { \
            displayName = "Put On MX Gloves"; \
        }; \
        class USP_G3C_OR_##CAMO { \
            displayName = "Put On OR Gloves"; \
        }; \
    }; \
}; \
class USP_G3C_CS_##CAMO: ACEWARDROBE(base) { \
    class modifiableTo { \
        class USP_G3C_CS_CU_##CAMO { \
            displayName = ECSTRING(main,collar_up); \
        }; \
        class USP_G3C_CS_KP_##CAMO { \
            displayName = ECSTRING(main,kneepads_on); \
        }; \
        class USP_G3C_CS_MX_##CAMO { \
            displayName = "Put On MX Gloves"; \
        }; \
        class USP_G3C_CS_OR_##CAMO { \
            displayName = "Put On OR Gloves"; \
        }; \
    }; \
}; \
class USP_G3C_CS_CU_##CAMO: ACEWARDROBE(base) { \
    class modifiableTo { \
        class USP_G3C_CS_##CAMO { \
            displayName = ECSTRING(main,collar_down); \
        }; \
        class USP_G3C_CS_CU_KP_##CAMO { \
            displayName = ECSTRING(main,kneepads_on); \
        }; \
        class USP_G3C_CS_CU_MX_##CAMO { \
            displayName = "Put On MX Gloves"; \
        }; \
        class USP_G3C_CS_CU_OR_##CAMO { \
            displayName = "Put On OR Gloves"; \
        }; \
    }; \
}; \
class USP_G3C_CS_CU_KP_##CAMO: ACEWARDROBE(base) { \
    class modifiableTo { \
        class USP_G3C_CS_CU_##CAMO { \
            displayName = ECSTRING(main,kneepads_off); \
        }; \
        class USP_G3C_CS_CU_KP_MX_##CAMO { \
            displayName = "Put On MX Gloves"; \
        }; \
        class USP_G3C_CS_CU_KP_OR_##CAMO { \
            displayName = "Put On OR Gloves"; \
        }; \
        class USP_G3C_CS_KP_##CAMO { \
            displayName = ECSTRING(main,collar_down); \
        }; \
    }; \
}; \
class USP_G3C_CS_CU_KP_MX_##CAMO: ACEWARDROBE(base) { \
    class modifiableTo { \
        class USP_G3C_CS_CU_KP_##CAMO { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_G3C_CS_CU_KP_OR_##CAMO { \
            displayName = "Switch to OR Gloves"; \
        }; \
        class USP_G3C_CS_CU_MX_##CAMO { \
            displayName = ECSTRING(main,kneepads_off); \
        }; \
        class USP_G3C_CS_KP_MX_##CAMO { \
            displayName = ECSTRING(main,collar_down); \
        }; \
    }; \
}; \
class USP_G3C_CS_CU_KP_MX_VQ_##CAMO: ACEWARDROBE(base) { \
    class modifiableTo { \
        class USP_G3C_CS_CU_KP_OR_VQ_##CAMO { \
            displayName = "Switch to OR Gloves"; \
        }; \
        class USP_G3C_CS_CU_KP_VQ_##CAMO { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_G3C_CS_CU_MX_VQ_##CAMO { \
            displayName = ECSTRING(main,kneepads_off); \
        }; \
    }; \
}; \
class USP_G3C_CS_CU_KP_OR_##CAMO: ACEWARDROBE(base) { \
    class modifiableTo { \
        class USP_G3C_CS_CU_KP_##CAMO { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_G3C_CS_CU_KP_MX_##CAMO { \
            displayName = "Switch to MX Gloves"; \
        }; \
        class USP_G3C_CS_CU_OR_##CAMO { \
            displayName = ECSTRING(main,kneepads_off); \
        }; \
        class USP_G3C_CS_KP_OR_##CAMO { \
            displayName = ECSTRING(main,collar_down); \
        }; \
    }; \
}; \
class USP_G3C_CS_CU_KP_OR_VQ_##CAMO: ACEWARDROBE(base) { \
    class modifiableTo { \
        class USP_G3C_CS_CU_KP_MX_VQ_##CAMO { \
            displayName = "Switch to MX Gloves"; \
        }; \
        class USP_G3C_CS_CU_KP_VQ_##CAMO { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_G3C_CS_CU_OR_VQ_##CAMO { \
            displayName = ECSTRING(main,kneepads_off); \
        }; \
        class USP_G3C_CS_KP_OR_VQ_##CAMO { \
            displayName = ECSTRING(main,collar_down); \
        }; \
    }; \
}; \
class USP_G3C_CS_CU_KP_VQ_##CAMO: ACEWARDROBE(base) { \
    class modifiableTo { \
        class USP_G3C_CS_CU_KP_MX_VQ_##CAMO { \
            displayName = "Put On MX Gloves"; \
        }; \
        class USP_G3C_CS_CU_KP_OR_VQ_##CAMO { \
            displayName = "Put On OR Gloves"; \
        }; \
        class USP_G3C_CS_CU_VQ_##CAMO { \
            displayName = ECSTRING(main,kneepads_off); \
        }; \
        class USP_G3C_CS_KP_VQ_##CAMO { \
            displayName = ECSTRING(main,collar_down); \
        }; \
    }; \
}; \
class USP_G3C_CS_CU_MX_##CAMO: ACEWARDROBE(base) { \
    class modifiableTo { \
        class USP_G3C_CS_CU_##CAMO { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_G3C_CS_CU_KP_MX_##CAMO { \
            displayName = ECSTRING(main,kneepads_on); \
        }; \
        class USP_G3C_CS_CU_OR_##CAMO { \
            displayName = "Switch to OR Gloves"; \
        }; \
        class USP_G3C_CS_MX_##CAMO { \
            displayName = ECSTRING(main,collar_down); \
        }; \
    }; \
}; \
class USP_G3C_CS_CU_MX_VQ_##CAMO: ACEWARDROBE(base) { \
    class modifiableTo { \
        class USP_G3C_CS_CU_KP_MX_VQ_##CAMO { \
            displayName = ECSTRING(main,kneepads_on); \
        }; \
        class USP_G3C_CS_CU_OR_VQ_##CAMO { \
            displayName = "Switch to OR Gloves"; \
        }; \
        class USP_G3C_CS_CU_VQ_##CAMO { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_G3C_CS_MX_VQ_##CAMO { \
            displayName = ECSTRING(main,collar_down); \
        }; \
    }; \
}; \
class USP_G3C_CS_CU_OR_##CAMO: ACEWARDROBE(base) { \
    class modifiableTo { \
        class USP_G3C_CS_CU_##CAMO { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_G3C_CS_CU_MX_##CAMO { \
            displayName = "Switch to MX Gloves"; \
        }; \
        class USP_G3C_CS_CU_KP_OR_##CAMO { \
            displayName = ECSTRING(main,kneepads_on); \
        }; \
        class USP_G3C_CS_OR_##CAMO { \
            displayName = ECSTRING(main,collar_down); \
        }; \
    }; \
}; \
class USP_G3C_CS_CU_OR_VQ_##CAMO: ACEWARDROBE(base) { \
    class modifiableTo { \
        class USP_G3C_CS_CU_MX_VQ_##CAMO { \
            displayName = "Switch to MX Gloves"; \
        }; \
        class USP_G3C_CS_CU_KP_OR_VQ_##CAMO { \
            displayName = ECSTRING(main,kneepads_on); \
        }; \
        class USP_G3C_CS_CU_VQ_##CAMO { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_G3C_CS_OR_VQ_##CAMO { \
            displayName = ECSTRING(main,collar_down); \
        }; \
    }; \
}; \
class USP_G3C_CS_CU_VQ_##CAMO: ACEWARDROBE(base) { \
    class modifiableTo { \
        class USP_G3C_CS_CU_KP_VQ_##CAMO { \
            displayName = ECSTRING(main,kneepads_on); \
        }; \
        class USP_G3C_CS_CU_MX_VQ_##CAMO { \
            displayName = "Put On MX Gloves"; \
        }; \
        class USP_G3C_CS_CU_OR_VQ_##CAMO { \
            displayName = "Put On OR Gloves"; \
        }; \
        class USP_G3C_CS_VQ_##CAMO { \
            displayName = ECSTRING(main,collar_down); \
        }; \
    }; \
}; \
class USP_G3C_CS_KP_##CAMO: ACEWARDROBE(base) { \
    class modifiableTo { \
        class USP_G3C_CS_##CAMO { \
            displayName = ECSTRING(main,kneepads_off); \
        }; \
        class USP_G3C_CS_CU_KP_##CAMO { \
            displayName = ECSTRING(main,collar_up); \
        }; \
        class USP_G3C_CS_KP_MX_##CAMO { \
            displayName = "Put On MX Gloves"; \
        }; \
        class USP_G3C_CS_KP_OR_##CAMO { \
            displayName = "Put On OR Gloves"; \
        }; \
    }; \
}; \
class USP_G3C_CS_KP_MX_##CAMO: ACEWARDROBE(base) { \
    class modifiableTo { \
        class USP_G3C_CS_KP_##CAMO { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_G3C_CS_CU_KP_MX_##CAMO { \
            displayName = ECSTRING(main,collar_up); \
        }; \
        class USP_G3C_CS_KP_OR_##CAMO { \
            displayName = "Switch to OR Gloves"; \
        }; \
        class USP_G3C_CS_MX_##CAMO { \
            displayName = ECSTRING(main,kneepads_off); \
        }; \
    }; \
}; \
class USP_G3C_CS_KP_OR_##CAMO: ACEWARDROBE(base) { \
    class modifiableTo { \
        class USP_G3C_CS_KP_##CAMO { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_G3C_CS_KP_MX_##CAMO { \
            displayName = "Switch to MX Gloves"; \
        }; \
        class USP_G3C_CS_CU_KP_OR_##CAMO { \
            displayName = ECSTRING(main,collar_up); \
        }; \
        class USP_G3C_CS_OR_##CAMO { \
            displayName = ECSTRING(main,kneepads_off); \
        }; \
    }; \
}; \
class USP_G3C_CS_KP_OR_VQ_##CAMO: ACEWARDROBE(base) { \
    class modifiableTo { \
        class USP_G3C_CS_CU_KP_OR_VQ_##CAMO { \
            displayName = ECSTRING(main,collar_up); \
        }; \
        class USP_G3C_CS_KP_VQ_##CAMO { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_G3C_CS_OR_VQ_##CAMO { \
            displayName = ECSTRING(main,kneepads_off); \
        }; \
    }; \
}; \
class USP_G3C_CS_KP_VQ_##CAMO: ACEWARDROBE(base) { \
    class modifiableTo { \
        class USP_G3C_CS_CU_KP_VQ_##CAMO { \
            displayName = ECSTRING(main,collar_up); \
        }; \
        class USP_G3C_CS_KP_OR_VQ_##CAMO { \
            displayName = "Put On OR Gloves"; \
        }; \
        class USP_G3C_CS_VQ_##CAMO { \
            displayName = ECSTRING(main,kneepads_off); \
        }; \
    }; \
}; \
class USP_G3C_CS_MX_##CAMO: ACEWARDROBE(base) { \
    class modifiableTo { \
        class USP_G3C_CS_##CAMO { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_G3C_CS_CU_MX_##CAMO { \
            displayName = ECSTRING(main,collar_up); \
        }; \
        class USP_G3C_CS_KP_MX_##CAMO { \
            displayName = ECSTRING(main,kneepads_on); \
        }; \
        class USP_G3C_CS_OR_##CAMO { \
            displayName = "Switch to OR Gloves"; \
        }; \
    }; \
}; \
class USP_G3C_CS_MX_VQ_##CAMO: ACEWARDROBE(base) { \
    class modifiableTo { \
        class USP_G3C_CS_CU_MX_VQ_##CAMO { \
            displayName = ECSTRING(main,collar_up); \
        }; \
        class USP_G3C_CS_OR_VQ_##CAMO { \
            displayName = "Switch to OR Gloves"; \
        }; \
        class USP_G3C_CS_VQ_##CAMO { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
    }; \
}; \
class USP_G3C_CS_OR_##CAMO: ACEWARDROBE(base) { \
    class modifiableTo { \
        class USP_G3C_CS_##CAMO { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_G3C_CS_MX_##CAMO { \
            displayName = "Switch to MX Gloves"; \
        }; \
        class USP_G3C_CS_CU_OR_##CAMO { \
            displayName = ECSTRING(main,collar_up); \
        }; \
        class USP_G3C_CS_KP_OR_##CAMO { \
            displayName = ECSTRING(main,kneepads_on); \
        }; \
    }; \
}; \
class USP_G3C_CS_OR_VQ_##CAMO: ACEWARDROBE(base) { \
    class modifiableTo { \
        class USP_G3C_CS_MX_VQ_##CAMO { \
            displayName = "Switch to MX Gloves"; \
        }; \
        class USP_G3C_CS_CU_OR_VQ_##CAMO { \
            displayName = ECSTRING(main,collar_up); \
        }; \
        class USP_G3C_CS_KP_OR_VQ_##CAMO { \
            displayName = ECSTRING(main,kneepads_on); \
        }; \
        class USP_G3C_CS_VQ_##CAMO { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
    }; \
}; \
class USP_G3C_CS_VQ_##CAMO: ACEWARDROBE(base) { \
    class modifiableTo { \
        class USP_G3C_CS_CU_VQ_##CAMO { \
            displayName = ECSTRING(main,collar_up); \
        }; \
        class USP_G3C_CS_KP_VQ_##CAMO { \
            displayName = ECSTRING(main,kneepads_on); \
        }; \
        class USP_G3C_CS_MX_VQ_##CAMO { \
            displayName = "Put On MX Gloves"; \
        }; \
        class USP_G3C_CS_OR_VQ_##CAMO { \
            displayName = "Put On OR Gloves"; \
        }; \
    }; \
}; \
class USP_G3C_CU_##CAMO: ACEWARDROBE(base_U_sleeves_down) { \
    class modifiableTo { \
        class USP_G3C_##CAMO { \
            displayName = ECSTRING(main,collar_down); \
        }; \
        class USP_G3C_RS_CU_##CAMO { \
            displayName = ECSTRING(main,roll_sleeves_up); \
        }; \
        class USP_G3C_CS_CU_##CAMO { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_CU_KP_##CAMO { \
            displayName = ECSTRING(main,kneepads_on); \
        }; \
        class USP_G3C_CU_MX_##CAMO { \
            displayName = "Put On MX Gloves"; \
        }; \
        class USP_G3C_CU_OR_##CAMO { \
            displayName = "Put On OR Gloves"; \
        }; \
    }; \
}; \
class USP_G3C_CU_KP_##CAMO: ACEWARDROBE(base_U_sleeves_down) { \
    class modifiableTo { \
        class USP_G3C_CU_##CAMO { \
            displayName = ECSTRING(main,kneepads_off); \
        }; \
        class USP_G3C_RS_CU_KP_##CAMO { \
            displayName = ECSTRING(main,roll_sleeves_up); \
        }; \
        class USP_G3C_CS_CU_KP_##CAMO { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_CU_KP_MX_##CAMO { \
            displayName = "Put On MX Gloves"; \
        }; \
        class USP_G3C_CU_KP_OR_##CAMO { \
            displayName = "Put On OR Gloves"; \
        }; \
        class USP_G3C_KP_##CAMO { \
            displayName = ECSTRING(main,collar_down); \
        }; \
    }; \
}; \
class USP_G3C_CU_KP_MX_##CAMO: ACEWARDROBE(base_U_sleeves_down) { \
    class modifiableTo { \
        class USP_G3C_CU_KP_##CAMO { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_G3C_RS_CU_KP_MX_##CAMO { \
            displayName = ECSTRING(main,roll_sleeves_up); \
        }; \
        class USP_G3C_CS_CU_KP_MX_##CAMO { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_CU_KP_OR_##CAMO { \
            displayName = "Switch to OR Gloves"; \
        }; \
        class USP_G3C_CU_MX_##CAMO { \
            displayName = ECSTRING(main,kneepads_off); \
        }; \
        class USP_G3C_KP_MX_##CAMO { \
            displayName = ECSTRING(main,collar_down); \
        }; \
    }; \
}; \
class USP_G3C_CU_KP_OR_##CAMO: ACEWARDROBE(base_U_sleeves_down) { \
    class modifiableTo { \
        class USP_G3C_CU_KP_##CAMO { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_G3C_CU_KP_MX_##CAMO { \
            displayName = "Switch to MX Gloves"; \
        }; \
        class USP_G3C_RS_CU_KP_OR_##CAMO { \
            displayName = ECSTRING(main,roll_sleeves_up); \
        }; \
        class USP_G3C_CS_CU_KP_OR_##CAMO { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_CU_OR_##CAMO { \
            displayName = ECSTRING(main,kneepads_off); \
        }; \
        class USP_G3C_KP_OR_##CAMO { \
            displayName = ECSTRING(main,collar_down); \
        }; \
    }; \
}; \
class USP_G3C_CU_MX_##CAMO: ACEWARDROBE(base_U_sleeves_down) { \
    class modifiableTo { \
        class USP_G3C_CU_##CAMO { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_G3C_RS_CU_MX_##CAMO { \
            displayName = ECSTRING(main,roll_sleeves_up); \
        }; \
        class USP_G3C_CS_CU_MX_##CAMO { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_CU_KP_MX_##CAMO { \
            displayName = ECSTRING(main,kneepads_on); \
        }; \
        class USP_G3C_CU_OR_##CAMO { \
            displayName = "Switch to OR Gloves"; \
        }; \
        class USP_G3C_MX_##CAMO { \
            displayName = ECSTRING(main,collar_down); \
        }; \
    }; \
}; \
class USP_G3C_CU_OR_##CAMO: ACEWARDROBE(base_U_sleeves_down) { \
    class modifiableTo { \
        class USP_G3C_CU_##CAMO { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_G3C_CU_MX_##CAMO { \
            displayName = "Switch to MX Gloves"; \
        }; \
        class USP_G3C_RS_CU_OR_##CAMO { \
            displayName = ECSTRING(main,roll_sleeves_up); \
        }; \
        class USP_G3C_CS_CU_OR_##CAMO { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_CU_KP_OR_##CAMO { \
            displayName = ECSTRING(main,kneepads_on); \
        }; \
        class USP_G3C_OR_##CAMO { \
            displayName = ECSTRING(main,collar_down); \
        }; \
    }; \
}; \
class USP_G3C_KP_##CAMO: ACEWARDROBE(base_U_sleeves_down) { \
    class modifiableTo { \
        class USP_G3C_##CAMO { \
            displayName = ECSTRING(main,kneepads_off); \
        }; \
        class USP_G3C_RS_KP_##CAMO { \
            displayName = ECSTRING(main,roll_sleeves_up); \
        }; \
        class USP_G3C_CS_KP_##CAMO { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_CU_KP_##CAMO { \
            displayName = ECSTRING(main,collar_up); \
        }; \
        class USP_G3C_KP_MX_##CAMO { \
            displayName = "Put On MX Gloves"; \
        }; \
        class USP_G3C_KP_OR_##CAMO { \
            displayName = "Put On OR Gloves"; \
        }; \
    }; \
}; \
class USP_G3C_KP_MX_##CAMO: ACEWARDROBE(base_U_sleeves_down) { \
    class modifiableTo { \
        class USP_G3C_KP_##CAMO { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_G3C_RS_KP_MX_##CAMO { \
            displayName = ECSTRING(main,roll_sleeves_up); \
        }; \
        class USP_G3C_CS_KP_MX_##CAMO { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_CU_KP_MX_##CAMO { \
            displayName = ECSTRING(main,collar_up); \
        }; \
        class USP_G3C_KP_OR_##CAMO { \
            displayName = "Switch to OR Gloves"; \
        }; \
        class USP_G3C_MX_##CAMO { \
            displayName = ECSTRING(main,kneepads_off); \
        }; \
    }; \
}; \
class USP_G3C_KP_OR_##CAMO: ACEWARDROBE(base_U_sleeves_down) { \
    class modifiableTo { \
        class USP_G3C_KP_##CAMO { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_G3C_KP_MX_##CAMO { \
            displayName = "Switch to MX Gloves"; \
        }; \
        class USP_G3C_RS_KP_OR_##CAMO { \
            displayName = ECSTRING(main,roll_sleeves_up); \
        }; \
        class USP_G3C_CS_KP_OR_##CAMO { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_CU_KP_OR_##CAMO { \
            displayName = ECSTRING(main,collar_up); \
        }; \
        class USP_G3C_OR_##CAMO { \
            displayName = ECSTRING(main,kneepads_off); \
        }; \
    }; \
}; \
class USP_G3C_MX_##CAMO: ACEWARDROBE(base_U_sleeves_down) { \
    class modifiableTo { \
        class USP_G3C_##CAMO { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_G3C_RS_MX_##CAMO { \
            displayName = ECSTRING(main,roll_sleeves_up); \
        }; \
        class USP_G3C_CS_MX_##CAMO { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_CU_MX_##CAMO { \
            displayName = ECSTRING(main,collar_up); \
        }; \
        class USP_G3C_KP_MX_##CAMO { \
            displayName = ECSTRING(main,kneepads_on); \
        }; \
        class USP_G3C_OR_##CAMO { \
            displayName = "Switch to OR Gloves"; \
        }; \
    }; \
}; \
class USP_G3C_MX_VQ_##CAMO: ACEWARDROBE(base_U_sleeves_down) { \
    class modifiableTo { \
        class USP_G3C_RS_MX_VQ_##CAMO { \
            displayName = ECSTRING(main,roll_sleeves_up); \
        }; \
        class USP_G3C_CS_MX_VQ_##CAMO { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_OR_VQ_##CAMO { \
            displayName = "Switch to OR Gloves"; \
        }; \
        class USP_G3C_VQ_##CAMO { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
    }; \
}; \
class USP_G3C_OR_##CAMO: ACEWARDROBE(base_U_sleeves_down) { \
    class modifiableTo { \
        class USP_G3C_##CAMO { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_G3C_MX_##CAMO { \
            displayName = "Switch to MX Gloves"; \
        }; \
        class USP_G3C_RS_OR_##CAMO { \
            displayName = ECSTRING(main,roll_sleeves_up); \
        }; \
        class USP_G3C_CS_OR_##CAMO { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_CU_OR_##CAMO { \
            displayName = ECSTRING(main,collar_up); \
        }; \
        class USP_G3C_KP_OR_##CAMO { \
            displayName = ECSTRING(main,kneepads_on); \
        }; \
    }; \
}; \
class USP_G3C_OR_VQ_##CAMO: ACEWARDROBE(base_U_sleeves_down) { \
    class modifiableTo { \
        class USP_G3C_MX_VQ_##CAMO { \
            displayName = "Switch to MX Gloves"; \
        }; \
        class USP_G3C_RS_OR_VQ_##CAMO { \
            displayName = ECSTRING(main,roll_sleeves_up); \
        }; \
        class USP_G3C_CS_OR_VQ_##CAMO { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_VQ_##CAMO { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
    }; \
}; \
class USP_G3C_RS_##CAMO: ACEWARDROBE(base_U_sleeves_up) { \
    class modifiableTo { \
        class USP_G3C_##CAMO { \
            displayName = ECSTRING(main,roll_sleeves_down); \
        }; \
        class USP_G3C_RS2_##CAMO { \
            displayName = ECSTRING(main,roll_sleeves_up_further); \
        }; \
        class USP_G3C_CS_##CAMO { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_RS_CU_##CAMO { \
            displayName = ECSTRING(main,collar_up); \
        }; \
        class USP_G3C_RS_KP_##CAMO { \
            displayName = ECSTRING(main,kneepads_on); \
        }; \
        class USP_G3C_RS_MX_##CAMO { \
            displayName = "Put On MX Gloves"; \
        }; \
        class USP_G3C_RS_OR_##CAMO { \
            displayName = "Put On OR Gloves"; \
        }; \
    }; \
}; \
class USP_G3C_RS_CU_##CAMO: ACEWARDROBE(base_U_sleeves_up) { \
    class modifiableTo { \
        class USP_G3C_CU_##CAMO { \
            displayName = ECSTRING(main,roll_sleeves_down); \
        }; \
        class USP_G3C_RS_##CAMO { \
            displayName = ECSTRING(main,collar_down); \
        }; \
        class USP_G3C_RS2_CU_##CAMO { \
            displayName = ECSTRING(main,roll_sleeves_up_further); \
        }; \
        class USP_G3C_CS_CU_##CAMO { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_RS_CU_KP_##CAMO { \
            displayName = ECSTRING(main,kneepads_on); \
        }; \
        class USP_G3C_RS_CU_MX_##CAMO { \
            displayName = "Put On MX Gloves"; \
        }; \
        class USP_G3C_RS_CU_OR_##CAMO { \
            displayName = "Put On OR Gloves"; \
        }; \
    }; \
}; \
class USP_G3C_RS_CU_KP_##CAMO: ACEWARDROBE(base_U_sleeves_up) { \
    class modifiableTo { \
        class USP_G3C_CU_KP_##CAMO { \
            displayName = ECSTRING(main,roll_sleeves_down); \
        }; \
        class USP_G3C_RS_CU_##CAMO { \
            displayName = ECSTRING(main,kneepads_off); \
        }; \
        class USP_G3C_RS2_CU_KP_##CAMO { \
            displayName = ECSTRING(main,roll_sleeves_up_further); \
        }; \
        class USP_G3C_CS_CU_KP_##CAMO { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_RS_CU_KP_MX_##CAMO { \
            displayName = "Put On MX Gloves"; \
        }; \
        class USP_G3C_RS_CU_KP_OR_##CAMO { \
            displayName = "Put On OR Gloves"; \
        }; \
        class USP_G3C_RS_KP_##CAMO { \
            displayName = ECSTRING(main,collar_down); \
        }; \
    }; \
}; \
class USP_G3C_RS_CU_KP_MX_##CAMO: ACEWARDROBE(base_U_sleeves_up) { \
    class modifiableTo { \
        class USP_G3C_CU_KP_MX_##CAMO { \
            displayName = ECSTRING(main,roll_sleeves_down); \
        }; \
        class USP_G3C_RS_CU_KP_##CAMO { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_G3C_RS2_CU_KP_MX_##CAMO { \
            displayName = ECSTRING(main,roll_sleeves_up_further); \
        }; \
        class USP_G3C_CS_CU_KP_MX_##CAMO { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_RS_CU_KP_OR_##CAMO { \
            displayName = "Switch to OR Gloves"; \
        }; \
        class USP_G3C_RS_CU_MX_##CAMO { \
            displayName = ECSTRING(main,kneepads_off); \
        }; \
        class USP_G3C_RS_KP_MX_##CAMO { \
            displayName = ECSTRING(main,collar_down); \
        }; \
    }; \
}; \
class USP_G3C_RS_CU_KP_MX_VQ_##CAMO: ACEWARDROBE(base_U_sleeves_up) { \
    class modifiableTo { \
        class USP_G3C_RS2_CU_KP_MX_VQ_##CAMO { \
            displayName = ECSTRING(main,roll_sleeves_up_further); \
        }; \
        class USP_G3C_CS_CU_KP_MX_VQ_##CAMO { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_RS_CU_KP_OR_VQ_##CAMO { \
            displayName = "Switch to OR Gloves"; \
        }; \
        class USP_G3C_RS_CU_KP_VQ_##CAMO { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_G3C_RS_CU_MX_VQ_##CAMO { \
            displayName = ECSTRING(main,kneepads_off); \
        }; \
    }; \
}; \
class USP_G3C_RS_CU_KP_OR_##CAMO: ACEWARDROBE(base_U_sleeves_up) { \
    class modifiableTo { \
        class USP_G3C_CU_KP_OR_##CAMO { \
            displayName = ECSTRING(main,roll_sleeves_down); \
        }; \
        class USP_G3C_RS_CU_KP_##CAMO { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_G3C_RS_CU_KP_MX_##CAMO { \
            displayName = "Switch to MX Gloves"; \
        }; \
        class USP_G3C_RS2_CU_KP_OR_##CAMO { \
            displayName = ECSTRING(main,roll_sleeves_up_further); \
        }; \
        class USP_G3C_CS_CU_KP_OR_##CAMO { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_RS_CU_OR_##CAMO { \
            displayName = ECSTRING(main,kneepads_off); \
        }; \
        class USP_G3C_RS_KP_OR_##CAMO { \
            displayName = ECSTRING(main,collar_down); \
        }; \
    }; \
}; \
class USP_G3C_RS_CU_KP_OR_VQ_##CAMO: ACEWARDROBE(base_U_sleeves_up) { \
    class modifiableTo { \
        class USP_G3C_RS_CU_KP_MX_VQ_##CAMO { \
            displayName = "Switch to MX Gloves"; \
        }; \
        class USP_G3C_RS2_CU_KP_OR_VQ_##CAMO { \
            displayName = ECSTRING(main,roll_sleeves_up_further); \
        }; \
        class USP_G3C_CS_CU_KP_OR_VQ_##CAMO { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_RS_CU_KP_VQ_##CAMO { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_G3C_RS_CU_OR_VQ_##CAMO { \
            displayName = ECSTRING(main,kneepads_off); \
        }; \
        class USP_G3C_RS_KP_OR_VQ_##CAMO { \
            displayName = ECSTRING(main,collar_down); \
        }; \
    }; \
}; \
class USP_G3C_RS_CU_KP_VQ_##CAMO: ACEWARDROBE(base_U_sleeves_up) { \
    class modifiableTo { \
        class USP_G3C_RS2_CU_KP_VQ_##CAMO { \
            displayName = ECSTRING(main,roll_sleeves_up_further); \
        }; \
        class USP_G3C_CS_CU_KP_VQ_##CAMO { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_RS_CU_KP_MX_VQ_##CAMO { \
            displayName = "Put On MX Gloves"; \
        }; \
        class USP_G3C_RS_CU_KP_OR_VQ_##CAMO { \
            displayName = "Put On OR Gloves"; \
        }; \
        class USP_G3C_RS_CU_VQ_##CAMO { \
            displayName = ECSTRING(main,kneepads_off); \
        }; \
        class USP_G3C_RS_KP_VQ_##CAMO { \
            displayName = ECSTRING(main,collar_down); \
        }; \
    }; \
}; \
class USP_G3C_RS_CU_MX_##CAMO: ACEWARDROBE(base_U_sleeves_up) { \
    class modifiableTo { \
        class USP_G3C_CU_MX_##CAMO { \
            displayName = ECSTRING(main,roll_sleeves_down); \
        }; \
        class USP_G3C_RS_CU_##CAMO { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_G3C_RS2_CU_MX_##CAMO { \
            displayName = ECSTRING(main,roll_sleeves_up_further); \
        }; \
        class USP_G3C_CS_CU_MX_##CAMO { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_RS_CU_KP_MX_##CAMO { \
            displayName = ECSTRING(main,kneepads_on); \
        }; \
        class USP_G3C_RS_CU_OR_##CAMO { \
            displayName = "Switch to OR Gloves"; \
        }; \
        class USP_G3C_RS_MX_##CAMO { \
            displayName = ECSTRING(main,collar_down); \
        }; \
    }; \
}; \
class USP_G3C_RS_CU_MX_VQ_##CAMO: ACEWARDROBE(base_U_sleeves_up) { \
    class modifiableTo { \
        class USP_G3C_RS2_CU_MX_VQ_##CAMO { \
            displayName = ECSTRING(main,roll_sleeves_up_further); \
        }; \
        class USP_G3C_CS_CU_MX_VQ_##CAMO { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_RS_CU_KP_MX_VQ_##CAMO { \
            displayName = ECSTRING(main,kneepads_on); \
        }; \
        class USP_G3C_RS_CU_OR_VQ_##CAMO { \
            displayName = "Switch to OR Gloves"; \
        }; \
        class USP_G3C_RS_CU_VQ_##CAMO { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_G3C_RS_MX_VQ_##CAMO { \
            displayName = ECSTRING(main,collar_down); \
        }; \
    }; \
}; \
class USP_G3C_RS_CU_OR_##CAMO: ACEWARDROBE(base_U_sleeves_up) { \
    class modifiableTo { \
        class USP_G3C_CU_OR_##CAMO { \
            displayName = ECSTRING(main,roll_sleeves_down); \
        }; \
        class USP_G3C_RS_CU_##CAMO { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_G3C_RS_CU_MX_##CAMO { \
            displayName = "Switch to MX Gloves"; \
        }; \
        class USP_G3C_RS2_CU_OR_##CAMO { \
            displayName = ECSTRING(main,roll_sleeves_up_further); \
        }; \
        class USP_G3C_CS_CU_OR_##CAMO { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_RS_CU_KP_OR_##CAMO { \
            displayName = ECSTRING(main,kneepads_on); \
        }; \
        class USP_G3C_RS_OR_##CAMO { \
            displayName = ECSTRING(main,collar_down); \
        }; \
    }; \
}; \
class USP_G3C_RS_CU_OR_VQ_##CAMO: ACEWARDROBE(base_U_sleeves_up) { \
    class modifiableTo { \
        class USP_G3C_RS_CU_MX_VQ_##CAMO { \
            displayName = "Switch to MX Gloves"; \
        }; \
        class USP_G3C_RS2_CU_OR_VQ_##CAMO { \
            displayName = ECSTRING(main,roll_sleeves_up_further); \
        }; \
        class USP_G3C_CS_CU_OR_VQ_##CAMO { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_RS_CU_KP_OR_VQ_##CAMO { \
            displayName = ECSTRING(main,kneepads_on); \
        }; \
        class USP_G3C_RS_CU_VQ_##CAMO { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_G3C_RS_OR_VQ_##CAMO { \
            displayName = ECSTRING(main,collar_down); \
        }; \
    }; \
}; \
class USP_G3C_RS_CU_VQ_##CAMO: ACEWARDROBE(base_U_sleeves_up) { \
    class modifiableTo { \
        class USP_G3C_RS2_CU_VQ_##CAMO { \
            displayName = ECSTRING(main,roll_sleeves_up_further); \
        }; \
        class USP_G3C_CS_CU_VQ_##CAMO { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_RS_CU_KP_VQ_##CAMO { \
            displayName = ECSTRING(main,kneepads_on); \
        }; \
        class USP_G3C_RS_CU_MX_VQ_##CAMO { \
            displayName = "Put On MX Gloves"; \
        }; \
        class USP_G3C_RS_CU_OR_VQ_##CAMO { \
            displayName = "Put On OR Gloves"; \
        }; \
        class USP_G3C_RS_VQ_##CAMO { \
            displayName = ECSTRING(main,collar_down); \
        }; \
    }; \
}; \
class USP_G3C_RS_KP_##CAMO: ACEWARDROBE(base_U_sleeves_up) { \
    class modifiableTo { \
        class USP_G3C_KP_##CAMO { \
            displayName = ECSTRING(main,roll_sleeves_down); \
        }; \
        class USP_G3C_RS_##CAMO { \
            displayName = ECSTRING(main,kneepads_off); \
        }; \
        class USP_G3C_RS2_KP_##CAMO { \
            displayName = ECSTRING(main,roll_sleeves_up_further); \
        }; \
        class USP_G3C_CS_KP_##CAMO { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_RS_CU_KP_##CAMO { \
            displayName = ECSTRING(main,collar_up); \
        }; \
        class USP_G3C_RS_KP_MX_##CAMO { \
            displayName = "Put On MX Gloves"; \
        }; \
        class USP_G3C_RS_KP_OR_##CAMO { \
            displayName = "Put On OR Gloves"; \
        }; \
    }; \
}; \
class USP_G3C_RS_KP_MX_##CAMO: ACEWARDROBE(base_U_sleeves_up) { \
    class modifiableTo { \
        class USP_G3C_KP_MX_##CAMO { \
            displayName = ECSTRING(main,roll_sleeves_down); \
        }; \
        class USP_G3C_RS_KP_##CAMO { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_G3C_RS2_KP_MX_##CAMO { \
            displayName = ECSTRING(main,roll_sleeves_up_further); \
        }; \
        class USP_G3C_CS_KP_MX_##CAMO { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_RS_CU_KP_MX_##CAMO { \
            displayName = ECSTRING(main,collar_up); \
        }; \
        class USP_G3C_RS_KP_OR_##CAMO { \
            displayName = "Switch to OR Gloves"; \
        }; \
        class USP_G3C_RS_MX_##CAMO { \
            displayName = ECSTRING(main,kneepads_off); \
        }; \
    }; \
}; \
class USP_G3C_RS_KP_OR_##CAMO: ACEWARDROBE(base_U_sleeves_up) { \
    class modifiableTo { \
        class USP_G3C_KP_OR_##CAMO { \
            displayName = ECSTRING(main,roll_sleeves_down); \
        }; \
        class USP_G3C_RS_KP_##CAMO { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_G3C_RS_KP_MX_##CAMO { \
            displayName = "Switch to MX Gloves"; \
        }; \
        class USP_G3C_RS2_KP_OR_##CAMO { \
            displayName = ECSTRING(main,roll_sleeves_up_further); \
        }; \
        class USP_G3C_CS_KP_OR_##CAMO { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_RS_CU_KP_OR_##CAMO { \
            displayName = ECSTRING(main,collar_up); \
        }; \
        class USP_G3C_RS_OR_##CAMO { \
            displayName = ECSTRING(main,kneepads_off); \
        }; \
    }; \
}; \
class USP_G3C_RS_KP_OR_VQ_##CAMO: ACEWARDROBE(base_U_sleeves_up) { \
    class modifiableTo { \
        class USP_G3C_RS2_KP_OR_VQ_##CAMO { \
            displayName = ECSTRING(main,roll_sleeves_up_further); \
        }; \
        class USP_G3C_CS_KP_OR_VQ_##CAMO { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_RS_CU_KP_OR_VQ_##CAMO { \
            displayName = ECSTRING(main,collar_up); \
        }; \
        class USP_G3C_RS_KP_VQ_##CAMO { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_G3C_RS_OR_VQ_##CAMO { \
            displayName = ECSTRING(main,kneepads_off); \
        }; \
    }; \
}; \
class USP_G3C_RS_KP_VQ_##CAMO: ACEWARDROBE(base_U_sleeves_up) { \
    class modifiableTo { \
        class USP_G3C_RS2_KP_VQ_##CAMO { \
            displayName = ECSTRING(main,roll_sleeves_up_further); \
        }; \
        class USP_G3C_CS_KP_VQ_##CAMO { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_RS_CU_KP_VQ_##CAMO { \
            displayName = ECSTRING(main,collar_up); \
        }; \
        class USP_G3C_RS_KP_OR_VQ_##CAMO { \
            displayName = "Put On OR Gloves"; \
        }; \
        class USP_G3C_RS_VQ_##CAMO { \
            displayName = ECSTRING(main,kneepads_off); \
        }; \
    }; \
}; \
class USP_G3C_RS_MX_##CAMO: ACEWARDROBE(base_U_sleeves_up) { \
    class modifiableTo { \
        class USP_G3C_MX_##CAMO { \
            displayName = ECSTRING(main,roll_sleeves_down); \
        }; \
        class USP_G3C_RS_##CAMO { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_G3C_RS2_MX_##CAMO { \
            displayName = ECSTRING(main,roll_sleeves_up_further); \
        }; \
        class USP_G3C_CS_MX_##CAMO { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_RS_CU_MX_##CAMO { \
            displayName = ECSTRING(main,collar_up); \
        }; \
        class USP_G3C_RS_KP_MX_##CAMO { \
            displayName = ECSTRING(main,kneepads_on); \
        }; \
        class USP_G3C_RS_OR_##CAMO { \
            displayName = "Switch to OR Gloves"; \
        }; \
    }; \
}; \
class USP_G3C_RS_MX_VQ_##CAMO: ACEWARDROBE(base_U_sleeves_up) { \
    class modifiableTo { \
        class USP_G3C_MX_VQ_##CAMO { \
            displayName = ECSTRING(main,roll_sleeves_down); \
        }; \
        class USP_G3C_RS2_MX_VQ_##CAMO { \
            displayName = ECSTRING(main,roll_sleeves_up_further); \
        }; \
        class USP_G3C_CS_MX_VQ_##CAMO { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_RS_CU_MX_VQ_##CAMO { \
            displayName = ECSTRING(main,collar_up); \
        }; \
        class USP_G3C_RS_OR_VQ_##CAMO { \
            displayName = "Switch to OR Gloves"; \
        }; \
        class USP_G3C_RS_VQ_##CAMO { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
    }; \
}; \
class USP_G3C_RS_OR_##CAMO: ACEWARDROBE(base_U_sleeves_up) { \
    class modifiableTo { \
        class USP_G3C_OR_##CAMO { \
            displayName = ECSTRING(main,roll_sleeves_down); \
        }; \
        class USP_G3C_RS_##CAMO { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_G3C_RS_MX_##CAMO { \
            displayName = "Switch to MX Gloves"; \
        }; \
        class USP_G3C_RS2_OR_##CAMO { \
            displayName = ECSTRING(main,roll_sleeves_up_further); \
        }; \
        class USP_G3C_CS_OR_##CAMO { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_RS_CU_OR_##CAMO { \
            displayName = ECSTRING(main,collar_up); \
        }; \
        class USP_G3C_RS_KP_OR_##CAMO { \
            displayName = ECSTRING(main,kneepads_on); \
        }; \
    }; \
}; \
class USP_G3C_RS_OR_VQ_##CAMO: ACEWARDROBE(base_U_sleeves_up) { \
    class modifiableTo { \
        class USP_G3C_OR_VQ_##CAMO { \
            displayName = ECSTRING(main,roll_sleeves_down); \
        }; \
        class USP_G3C_RS_MX_VQ_##CAMO { \
            displayName = "Switch to MX Gloves"; \
        }; \
        class USP_G3C_RS2_OR_VQ_##CAMO { \
            displayName = ECSTRING(main,roll_sleeves_up_further); \
        }; \
        class USP_G3C_CS_OR_VQ_##CAMO { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_RS_CU_OR_VQ_##CAMO { \
            displayName = ECSTRING(main,collar_up); \
        }; \
        class USP_G3C_RS_KP_OR_VQ_##CAMO { \
            displayName = ECSTRING(main,kneepads_on); \
        }; \
        class USP_G3C_RS_VQ_##CAMO { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
    }; \
}; \
class USP_G3C_RS_VQ_##CAMO: ACEWARDROBE(base_U_sleeves_up) { \
    class modifiableTo { \
        class USP_G3C_CS_VQ_##CAMO { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_RS_CU_VQ_##CAMO { \
            displayName = ECSTRING(main,collar_up); \
        }; \
        class USP_G3C_RS_KP_VQ_##CAMO { \
            displayName = ECSTRING(main,kneepads_on); \
        }; \
        class USP_G3C_RS_MX_VQ_##CAMO { \
            displayName = "Put On MX Gloves"; \
        }; \
        class USP_G3C_RS_OR_VQ_##CAMO { \
            displayName = "Put On OR Gloves"; \
        }; \
        class USP_G3C_VQ_##CAMO { \
            displayName = ECSTRING(main,roll_sleeves_down); \
        }; \
    }; \
}; \
class USP_G3C_RS2_##CAMO: ACEWARDROBE(base_U_sleeves_up) { \
    class modifiableTo { \
        class USP_G3C_RS_##CAMO { \
            displayName = ECSTRING(main,roll_sleeves_down_partial); \
        }; \
        class USP_G3C_CS_##CAMO { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_RS2_CU_##CAMO { \
            displayName = ECSTRING(main,collar_up); \
        }; \
        class USP_G3C_RS2_KP_##CAMO { \
            displayName = ECSTRING(main,kneepads_on); \
        }; \
        class USP_G3C_RS2_MX_##CAMO { \
            displayName = "Put On MX Gloves"; \
        }; \
        class USP_G3C_RS2_OR_##CAMO { \
            displayName = "Put On OR Gloves"; \
        }; \
    }; \
}; \
class USP_G3C_RS2_CU_##CAMO: ACEWARDROBE(base_U_sleeves_up) { \
    class modifiableTo { \
        class USP_G3C_RS_CU_##CAMO { \
            displayName = ECSTRING(main,roll_sleeves_down_partial); \
        }; \
        class USP_G3C_RS2_##CAMO { \
            displayName = ECSTRING(main,collar_down); \
        }; \
        class USP_G3C_CS_CU_##CAMO { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_RS2_CU_KP_##CAMO { \
            displayName = ECSTRING(main,kneepads_on); \
        }; \
        class USP_G3C_RS2_CU_MX_##CAMO { \
            displayName = "Put On MX Gloves"; \
        }; \
        class USP_G3C_RS2_CU_OR_##CAMO { \
            displayName = "Put On OR Gloves"; \
        }; \
    }; \
}; \
class USP_G3C_RS2_CU_KP_##CAMO: ACEWARDROBE(base_U_sleeves_up) { \
    class modifiableTo { \
        class USP_G3C_RS_CU_KP_##CAMO { \
            displayName = ECSTRING(main,roll_sleeves_down_partial); \
        }; \
        class USP_G3C_RS2_CU_##CAMO { \
            displayName = ECSTRING(main,kneepads_off); \
        }; \
        class USP_G3C_CS_CU_KP_##CAMO { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_RS2_CU_KP_MX_##CAMO { \
            displayName = "Put On MX Gloves"; \
        }; \
        class USP_G3C_RS2_CU_KP_OR_##CAMO { \
            displayName = "Put On OR Gloves"; \
        }; \
        class USP_G3C_RS2_KP_##CAMO { \
            displayName = ECSTRING(main,collar_down); \
        }; \
    }; \
}; \
class USP_G3C_RS2_CU_KP_MX_##CAMO: ACEWARDROBE(base_U_sleeves_up) { \
    class modifiableTo { \
        class USP_G3C_RS_CU_KP_MX_##CAMO { \
            displayName = ECSTRING(main,roll_sleeves_down_partial); \
        }; \
        class USP_G3C_RS2_CU_KP_##CAMO { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_G3C_CS_CU_KP_MX_##CAMO { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_RS2_CU_KP_OR_##CAMO { \
            displayName = "Switch to OR Gloves"; \
        }; \
        class USP_G3C_RS2_CU_MX_##CAMO { \
            displayName = ECSTRING(main,kneepads_off); \
        }; \
        class USP_G3C_RS2_KP_MX_##CAMO { \
            displayName = ECSTRING(main,collar_down); \
        }; \
    }; \
}; \
class USP_G3C_RS2_CU_KP_MX_VQ_##CAMO: ACEWARDROBE(base_U_sleeves_up) { \
    class modifiableTo { \
        class USP_G3C_RS_CU_KP_MX_VQ_##CAMO { \
            displayName = ECSTRING(main,roll_sleeves_down_partial); \
        }; \
        class USP_G3C_CS_CU_KP_MX_VQ_##CAMO { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_RS2_CU_KP_OR_VQ_##CAMO { \
            displayName = "Switch to OR Gloves"; \
        }; \
        class USP_G3C_RS2_CU_KP_VQ_##CAMO { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_G3C_RS2_CU_MX_VQ_##CAMO { \
            displayName = ECSTRING(main,kneepads_off); \
        }; \
    }; \
}; \
class USP_G3C_RS2_CU_KP_OR_##CAMO: ACEWARDROBE(base_U_sleeves_up) { \
    class modifiableTo { \
        class USP_G3C_RS_CU_KP_OR_##CAMO { \
            displayName = ECSTRING(main,roll_sleeves_down_partial); \
        }; \
        class USP_G3C_RS2_CU_KP_##CAMO { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_G3C_RS2_CU_KP_MX_##CAMO { \
            displayName = "Switch to MX Gloves"; \
        }; \
        class USP_G3C_CS_CU_KP_OR_##CAMO { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_RS2_CU_OR_##CAMO { \
            displayName = ECSTRING(main,kneepads_off); \
        }; \
        class USP_G3C_RS2_KP_OR_##CAMO { \
            displayName = ECSTRING(main,collar_down); \
        }; \
    }; \
}; \
class USP_G3C_RS2_CU_KP_OR_VQ_##CAMO: ACEWARDROBE(base_U_sleeves_up) { \
    class modifiableTo { \
        class USP_G3C_RS_CU_KP_OR_VQ_##CAMO { \
            displayName = ECSTRING(main,roll_sleeves_down_partial); \
        }; \
        class USP_G3C_RS2_CU_KP_MX_VQ_##CAMO { \
            displayName = "Switch to MX Gloves"; \
        }; \
        class USP_G3C_CS_CU_KP_OR_VQ_##CAMO { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_RS2_CU_KP_VQ_##CAMO { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_G3C_RS2_CU_OR_VQ_##CAMO { \
            displayName = ECSTRING(main,kneepads_off); \
        }; \
        class USP_G3C_RS2_KP_OR_VQ_##CAMO { \
            displayName = ECSTRING(main,collar_down); \
        }; \
    }; \
}; \
class USP_G3C_RS2_CU_KP_VQ_##CAMO: ACEWARDROBE(base_U_sleeves_up) { \
    class modifiableTo { \
        class USP_G3C_RS_CU_KP_VQ_##CAMO { \
            displayName = ECSTRING(main,roll_sleeves_down_partial); \
        }; \
        class USP_G3C_CS_CU_KP_VQ_##CAMO { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_RS2_CU_KP_MX_VQ_##CAMO { \
            displayName = "Put On MX Gloves"; \
        }; \
        class USP_G3C_RS2_CU_KP_OR_VQ_##CAMO { \
            displayName = "Put On OR Gloves"; \
        }; \
        class USP_G3C_RS2_CU_VQ_##CAMO { \
            displayName = ECSTRING(main,kneepads_off); \
        }; \
        class USP_G3C_RS2_KP_VQ_##CAMO { \
            displayName = ECSTRING(main,collar_down); \
        }; \
    }; \
}; \
class USP_G3C_RS2_CU_MX_##CAMO: ACEWARDROBE(base_U_sleeves_up) { \
    class modifiableTo { \
        class USP_G3C_RS_CU_MX_##CAMO { \
            displayName = ECSTRING(main,roll_sleeves_down_partial); \
        }; \
        class USP_G3C_RS2_CU_##CAMO { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_G3C_CS_CU_MX_##CAMO { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_RS2_CU_KP_MX_##CAMO { \
            displayName = ECSTRING(main,kneepads_on); \
        }; \
        class USP_G3C_RS2_CU_OR_##CAMO { \
            displayName = "Switch to OR Gloves"; \
        }; \
        class USP_G3C_RS2_MX_##CAMO { \
            displayName = ECSTRING(main,collar_down); \
        }; \
    }; \
}; \
class USP_G3C_RS2_CU_MX_VQ_##CAMO: ACEWARDROBE(base_U_sleeves_up) { \
    class modifiableTo { \
        class USP_G3C_RS_CU_MX_VQ_##CAMO { \
            displayName = ECSTRING(main,roll_sleeves_down_partial); \
        }; \
        class USP_G3C_CS_CU_MX_VQ_##CAMO { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_RS2_CU_KP_MX_VQ_##CAMO { \
            displayName = ECSTRING(main,kneepads_on); \
        }; \
        class USP_G3C_RS2_CU_OR_VQ_##CAMO { \
            displayName = "Switch to OR Gloves"; \
        }; \
        class USP_G3C_RS2_CU_VQ_##CAMO { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_G3C_RS2_MX_VQ_##CAMO { \
            displayName = ECSTRING(main,collar_down); \
        }; \
    }; \
}; \
class USP_G3C_RS2_CU_OR_##CAMO: ACEWARDROBE(base_U_sleeves_up) { \
    class modifiableTo { \
        class USP_G3C_RS_CU_OR_##CAMO { \
            displayName = ECSTRING(main,roll_sleeves_down_partial); \
        }; \
        class USP_G3C_RS2_CU_##CAMO { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_G3C_RS2_CU_MX_##CAMO { \
            displayName = "Switch to MX Gloves"; \
        }; \
        class USP_G3C_CS_CU_OR_##CAMO { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_RS2_CU_KP_OR_##CAMO { \
            displayName = ECSTRING(main,kneepads_on); \
        }; \
        class USP_G3C_RS2_OR_##CAMO { \
            displayName = ECSTRING(main,collar_down); \
        }; \
    }; \
}; \
class USP_G3C_RS2_CU_OR_VQ_##CAMO: ACEWARDROBE(base_U_sleeves_up) { \
    class modifiableTo { \
        class USP_G3C_RS_CU_OR_VQ_##CAMO { \
            displayName = ECSTRING(main,roll_sleeves_down_partial); \
        }; \
        class USP_G3C_RS2_CU_MX_VQ_##CAMO { \
            displayName = "Switch to MX Gloves"; \
        }; \
        class USP_G3C_CS_CU_OR_VQ_##CAMO { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_RS2_CU_KP_OR_VQ_##CAMO { \
            displayName = ECSTRING(main,kneepads_on); \
        }; \
        class USP_G3C_RS2_CU_VQ_##CAMO { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_G3C_RS2_OR_VQ_##CAMO { \
            displayName = ECSTRING(main,collar_down); \
        }; \
    }; \
}; \
class USP_G3C_RS2_CU_VQ_##CAMO: ACEWARDROBE(base_U_sleeves_up) { \
    class modifiableTo { \
        class USP_G3C_RS_CU_VQ_##CAMO { \
            displayName = ECSTRING(main,roll_sleeves_down_partial); \
        }; \
        class USP_G3C_CS_CU_VQ_##CAMO { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_RS2_CU_KP_VQ_##CAMO { \
            displayName = ECSTRING(main,kneepads_on); \
        }; \
        class USP_G3C_RS2_CU_MX_VQ_##CAMO { \
            displayName = "Put On MX Gloves"; \
        }; \
        class USP_G3C_RS2_CU_OR_VQ_##CAMO { \
            displayName = "Put On OR Gloves"; \
        }; \
    }; \
}; \
class USP_G3C_RS2_KP_##CAMO: ACEWARDROBE(base_U_sleeves_up) { \
    class modifiableTo { \
        class USP_G3C_RS_KP_##CAMO { \
            displayName = ECSTRING(main,roll_sleeves_down_partial); \
        }; \
        class USP_G3C_RS2_##CAMO { \
            displayName = ECSTRING(main,kneepads_off); \
        }; \
        class USP_G3C_CS_KP_##CAMO { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_RS2_CU_KP_##CAMO { \
            displayName = ECSTRING(main,collar_up); \
        }; \
        class USP_G3C_RS2_KP_MX_##CAMO { \
            displayName = "Put On MX Gloves"; \
        }; \
        class USP_G3C_RS2_KP_OR_##CAMO { \
            displayName = "Put On OR Gloves"; \
        }; \
    }; \
}; \
class USP_G3C_RS2_KP_MX_##CAMO: ACEWARDROBE(base_U_sleeves_up) { \
    class modifiableTo { \
        class USP_G3C_RS_KP_MX_##CAMO { \
            displayName = ECSTRING(main,roll_sleeves_down_partial); \
        }; \
        class USP_G3C_RS2_KP_##CAMO { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_G3C_CS_KP_MX_##CAMO { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_RS2_CU_KP_MX_##CAMO { \
            displayName = ECSTRING(main,collar_up); \
        }; \
        class USP_G3C_RS2_KP_OR_##CAMO { \
            displayName = "Switch to OR Gloves"; \
        }; \
        class USP_G3C_RS2_MX_##CAMO { \
            displayName = ECSTRING(main,kneepads_off); \
        }; \
    }; \
}; \
class USP_G3C_RS2_KP_OR_##CAMO: ACEWARDROBE(base_U_sleeves_up) { \
    class modifiableTo { \
        class USP_G3C_RS_KP_OR_##CAMO { \
            displayName = ECSTRING(main,roll_sleeves_down_partial); \
        }; \
        class USP_G3C_RS2_KP_##CAMO { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_G3C_RS2_KP_MX_##CAMO { \
            displayName = "Switch to MX Gloves"; \
        }; \
        class USP_G3C_CS_KP_OR_##CAMO { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_RS2_CU_KP_OR_##CAMO { \
            displayName = ECSTRING(main,collar_up); \
        }; \
        class USP_G3C_RS2_OR_##CAMO { \
            displayName = ECSTRING(main,kneepads_off); \
        }; \
    }; \
}; \
class USP_G3C_RS2_KP_OR_VQ_##CAMO: ACEWARDROBE(base_U_sleeves_up) { \
    class modifiableTo { \
        class USP_G3C_RS_KP_OR_VQ_##CAMO { \
            displayName = ECSTRING(main,roll_sleeves_down_partial); \
        }; \
        class USP_G3C_CS_KP_OR_VQ_##CAMO { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_RS2_CU_KP_OR_VQ_##CAMO { \
            displayName = ECSTRING(main,collar_up); \
        }; \
        class USP_G3C_RS2_KP_VQ_##CAMO { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_G3C_RS2_OR_VQ_##CAMO { \
            displayName = ECSTRING(main,kneepads_off); \
        }; \
    }; \
}; \
class USP_G3C_RS2_KP_VQ_##CAMO: ACEWARDROBE(base_U_sleeves_up) { \
    class modifiableTo { \
        class USP_G3C_RS_KP_VQ_##CAMO { \
            displayName = ECSTRING(main,roll_sleeves_down_partial); \
        }; \
        class USP_G3C_CS_KP_VQ_##CAMO { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_RS2_CU_KP_VQ_##CAMO { \
            displayName = ECSTRING(main,collar_up); \
        }; \
        class USP_G3C_RS2_KP_OR_VQ_##CAMO { \
            displayName = "Put On OR Gloves"; \
        }; \
    }; \
}; \
class USP_G3C_RS2_MX_##CAMO: ACEWARDROBE(base_U_sleeves_up) { \
    class modifiableTo { \
        class USP_G3C_RS_MX_##CAMO { \
            displayName = ECSTRING(main,roll_sleeves_down_partial); \
        }; \
        class USP_G3C_RS2_##CAMO { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_G3C_CS_MX_##CAMO { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_RS2_CU_MX_##CAMO { \
            displayName = ECSTRING(main,collar_up); \
        }; \
        class USP_G3C_RS2_KP_MX_##CAMO { \
            displayName = ECSTRING(main,kneepads_on); \
        }; \
        class USP_G3C_RS2_OR_##CAMO { \
            displayName = "Switch to OR Gloves"; \
        }; \
    }; \
}; \
class USP_G3C_RS2_MX_VQ_##CAMO: ACEWARDROBE(base_U_sleeves_up) { \
    class modifiableTo { \
        class USP_G3C_RS_MX_VQ_##CAMO { \
            displayName = ECSTRING(main,roll_sleeves_down_partial); \
        }; \
        class USP_G3C_CS_MX_VQ_##CAMO { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_RS2_CU_MX_VQ_##CAMO { \
            displayName = ECSTRING(main,collar_up); \
        }; \
        class USP_G3C_RS2_OR_VQ_##CAMO { \
            displayName = "Switch to OR Gloves"; \
        }; \
    }; \
}; \
class USP_G3C_RS2_OR_##CAMO: ACEWARDROBE(base_U_sleeves_up) { \
    class modifiableTo { \
        class USP_G3C_RS_OR_##CAMO { \
            displayName = ECSTRING(main,roll_sleeves_down_partial); \
        }; \
        class USP_G3C_RS2_##CAMO { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_G3C_RS2_MX_##CAMO { \
            displayName = "Switch to MX Gloves"; \
        }; \
        class USP_G3C_CS_OR_##CAMO { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_RS2_CU_OR_##CAMO { \
            displayName = ECSTRING(main,collar_up); \
        }; \
        class USP_G3C_RS2_KP_OR_##CAMO { \
            displayName = ECSTRING(main,kneepads_on); \
        }; \
    }; \
}; \
class USP_G3C_RS2_OR_VQ_##CAMO: ACEWARDROBE(base_U_sleeves_up) { \
    class modifiableTo { \
        class USP_G3C_RS_OR_VQ_##CAMO { \
            displayName = ECSTRING(main,roll_sleeves_down_partial); \
        }; \
        class USP_G3C_RS2_MX_VQ_##CAMO { \
            displayName = "Switch to MX Gloves"; \
        }; \
        class USP_G3C_CS_OR_VQ_##CAMO { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_RS2_CU_OR_VQ_##CAMO { \
            displayName = ECSTRING(main,collar_up); \
        }; \
        class USP_G3C_RS2_KP_OR_VQ_##CAMO { \
            displayName = ECSTRING(main,kneepads_on); \
        }; \
    }; \
}; \
class USP_G3C_VQ_##CAMO: ACEWARDROBE(base_U_sleeves_down) { \
    class modifiableTo { \
        class USP_G3C_RS_VQ_##CAMO { \
            displayName = ECSTRING(main,roll_sleeves_up); \
        }; \
        class USP_G3C_CS_VQ_##CAMO { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_MX_VQ_##CAMO { \
            displayName = "Put On MX Gloves"; \
        }; \
        class USP_G3C_OR_VQ_##CAMO { \
            displayName = "Put On OR Gloves"; \
        }; \
    }; \
}

// BLK has no camo suffix at all in USP's own naming (it's the undyed/base finish), so it
// gets its own non-parametrised macro instead of USP_G3C_UNIFORMS(BLK).
#define USP_G3C_UNIFORMS_BLK \
class USP_G3C: ACEWARDROBE(base_U_sleeves_down) { \
    class modifiableTo { \
        class USP_G3C_RS { \
            displayName = ECSTRING(main,roll_sleeves_up); \
        }; \
        class USP_G3C_CS { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_CU { \
            displayName = ECSTRING(main,collar_up); \
        }; \
        class USP_G3C_KP { \
            displayName = ECSTRING(main,kneepads_on); \
        }; \
        class USP_G3C_MX { \
            displayName = "Put On MX Gloves"; \
        }; \
        class USP_G3C_OR { \
            displayName = "Put On OR Gloves"; \
        }; \
    }; \
}; \
class USP_G3C_CS: ACEWARDROBE(base) { \
    class modifiableTo { \
        class USP_G3C_CS_CU { \
            displayName = ECSTRING(main,collar_up); \
        }; \
        class USP_G3C_CS_KP { \
            displayName = ECSTRING(main,kneepads_on); \
        }; \
        class USP_G3C_CS_MX { \
            displayName = "Put On MX Gloves"; \
        }; \
        class USP_G3C_CS_OR { \
            displayName = "Put On OR Gloves"; \
        }; \
    }; \
}; \
class USP_G3C_CS_CU: ACEWARDROBE(base) { \
    class modifiableTo { \
        class USP_G3C_CS { \
            displayName = ECSTRING(main,collar_down); \
        }; \
        class USP_G3C_CS_CU_KP { \
            displayName = ECSTRING(main,kneepads_on); \
        }; \
        class USP_G3C_CS_CU_MX { \
            displayName = "Put On MX Gloves"; \
        }; \
        class USP_G3C_CS_CU_OR { \
            displayName = "Put On OR Gloves"; \
        }; \
    }; \
}; \
class USP_G3C_CS_CU_KP: ACEWARDROBE(base) { \
    class modifiableTo { \
        class USP_G3C_CS_CU { \
            displayName = ECSTRING(main,kneepads_off); \
        }; \
        class USP_G3C_CS_CU_KP_MX { \
            displayName = "Put On MX Gloves"; \
        }; \
        class USP_G3C_CS_CU_KP_OR { \
            displayName = "Put On OR Gloves"; \
        }; \
        class USP_G3C_CS_KP { \
            displayName = ECSTRING(main,collar_down); \
        }; \
    }; \
}; \
class USP_G3C_CS_CU_KP_MX: ACEWARDROBE(base) { \
    class modifiableTo { \
        class USP_G3C_CS_CU_KP { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_G3C_CS_CU_KP_OR { \
            displayName = "Switch to OR Gloves"; \
        }; \
        class USP_G3C_CS_CU_MX { \
            displayName = ECSTRING(main,kneepads_off); \
        }; \
        class USP_G3C_CS_KP_MX { \
            displayName = ECSTRING(main,collar_down); \
        }; \
    }; \
}; \
class USP_G3C_CS_CU_KP_MX_VQ: ACEWARDROBE(base) { \
    class modifiableTo { \
        class USP_G3C_CS_CU_KP_OR_VQ { \
            displayName = "Switch to OR Gloves"; \
        }; \
        class USP_G3C_CS_CU_KP_VQ { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_G3C_CS_CU_MX_VQ { \
            displayName = ECSTRING(main,kneepads_off); \
        }; \
    }; \
}; \
class USP_G3C_CS_CU_KP_OR: ACEWARDROBE(base) { \
    class modifiableTo { \
        class USP_G3C_CS_CU_KP { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_G3C_CS_CU_KP_MX { \
            displayName = "Switch to MX Gloves"; \
        }; \
        class USP_G3C_CS_CU_OR { \
            displayName = ECSTRING(main,kneepads_off); \
        }; \
        class USP_G3C_CS_KP_OR { \
            displayName = ECSTRING(main,collar_down); \
        }; \
    }; \
}; \
class USP_G3C_CS_CU_KP_OR_VQ: ACEWARDROBE(base) { \
    class modifiableTo { \
        class USP_G3C_CS_CU_KP_MX_VQ { \
            displayName = "Switch to MX Gloves"; \
        }; \
        class USP_G3C_CS_CU_KP_VQ { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_G3C_CS_CU_OR_VQ { \
            displayName = ECSTRING(main,kneepads_off); \
        }; \
        class USP_G3C_CS_KP_OR_VQ { \
            displayName = ECSTRING(main,collar_down); \
        }; \
    }; \
}; \
class USP_G3C_CS_CU_KP_VQ: ACEWARDROBE(base) { \
    class modifiableTo { \
        class USP_G3C_CS_CU_KP_MX_VQ { \
            displayName = "Put On MX Gloves"; \
        }; \
        class USP_G3C_CS_CU_KP_OR_VQ { \
            displayName = "Put On OR Gloves"; \
        }; \
        class USP_G3C_CS_CU_VQ { \
            displayName = ECSTRING(main,kneepads_off); \
        }; \
        class USP_G3C_CS_KP_VQ { \
            displayName = ECSTRING(main,collar_down); \
        }; \
    }; \
}; \
class USP_G3C_CS_CU_MX: ACEWARDROBE(base) { \
    class modifiableTo { \
        class USP_G3C_CS_CU { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_G3C_CS_CU_KP_MX { \
            displayName = ECSTRING(main,kneepads_on); \
        }; \
        class USP_G3C_CS_CU_OR { \
            displayName = "Switch to OR Gloves"; \
        }; \
        class USP_G3C_CS_MX { \
            displayName = ECSTRING(main,collar_down); \
        }; \
    }; \
}; \
class USP_G3C_CS_CU_MX_VQ: ACEWARDROBE(base) { \
    class modifiableTo { \
        class USP_G3C_CS_CU_KP_MX_VQ { \
            displayName = ECSTRING(main,kneepads_on); \
        }; \
        class USP_G3C_CS_CU_OR_VQ { \
            displayName = "Switch to OR Gloves"; \
        }; \
        class USP_G3C_CS_CU_VQ { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_G3C_CS_MX_VQ { \
            displayName = ECSTRING(main,collar_down); \
        }; \
    }; \
}; \
class USP_G3C_CS_CU_OR: ACEWARDROBE(base) { \
    class modifiableTo { \
        class USP_G3C_CS_CU { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_G3C_CS_CU_MX { \
            displayName = "Switch to MX Gloves"; \
        }; \
        class USP_G3C_CS_CU_KP_OR { \
            displayName = ECSTRING(main,kneepads_on); \
        }; \
        class USP_G3C_CS_OR { \
            displayName = ECSTRING(main,collar_down); \
        }; \
    }; \
}; \
class USP_G3C_CS_CU_OR_VQ: ACEWARDROBE(base) { \
    class modifiableTo { \
        class USP_G3C_CS_CU_MX_VQ { \
            displayName = "Switch to MX Gloves"; \
        }; \
        class USP_G3C_CS_CU_KP_OR_VQ { \
            displayName = ECSTRING(main,kneepads_on); \
        }; \
        class USP_G3C_CS_CU_VQ { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_G3C_CS_OR_VQ { \
            displayName = ECSTRING(main,collar_down); \
        }; \
    }; \
}; \
class USP_G3C_CS_CU_VQ: ACEWARDROBE(base) { \
    class modifiableTo { \
        class USP_G3C_CS_CU_KP_VQ { \
            displayName = ECSTRING(main,kneepads_on); \
        }; \
        class USP_G3C_CS_CU_MX_VQ { \
            displayName = "Put On MX Gloves"; \
        }; \
        class USP_G3C_CS_CU_OR_VQ { \
            displayName = "Put On OR Gloves"; \
        }; \
        class USP_G3C_CS_VQ { \
            displayName = ECSTRING(main,collar_down); \
        }; \
    }; \
}; \
class USP_G3C_CS_KP: ACEWARDROBE(base) { \
    class modifiableTo { \
        class USP_G3C_CS { \
            displayName = ECSTRING(main,kneepads_off); \
        }; \
        class USP_G3C_CS_CU_KP { \
            displayName = ECSTRING(main,collar_up); \
        }; \
        class USP_G3C_CS_KP_MX { \
            displayName = "Put On MX Gloves"; \
        }; \
        class USP_G3C_CS_KP_OR { \
            displayName = "Put On OR Gloves"; \
        }; \
    }; \
}; \
class USP_G3C_CS_KP_MX: ACEWARDROBE(base) { \
    class modifiableTo { \
        class USP_G3C_CS_KP { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_G3C_CS_CU_KP_MX { \
            displayName = ECSTRING(main,collar_up); \
        }; \
        class USP_G3C_CS_KP_OR { \
            displayName = "Switch to OR Gloves"; \
        }; \
        class USP_G3C_CS_MX { \
            displayName = ECSTRING(main,kneepads_off); \
        }; \
    }; \
}; \
class USP_G3C_CS_KP_OR: ACEWARDROBE(base) { \
    class modifiableTo { \
        class USP_G3C_CS_KP { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_G3C_CS_KP_MX { \
            displayName = "Switch to MX Gloves"; \
        }; \
        class USP_G3C_CS_CU_KP_OR { \
            displayName = ECSTRING(main,collar_up); \
        }; \
        class USP_G3C_CS_OR { \
            displayName = ECSTRING(main,kneepads_off); \
        }; \
    }; \
}; \
class USP_G3C_CS_KP_OR_VQ: ACEWARDROBE(base) { \
    class modifiableTo { \
        class USP_G3C_CS_CU_KP_OR_VQ { \
            displayName = ECSTRING(main,collar_up); \
        }; \
        class USP_G3C_CS_KP_VQ { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_G3C_CS_OR_VQ { \
            displayName = ECSTRING(main,kneepads_off); \
        }; \
    }; \
}; \
class USP_G3C_CS_KP_VQ: ACEWARDROBE(base) { \
    class modifiableTo { \
        class USP_G3C_CS_CU_KP_VQ { \
            displayName = ECSTRING(main,collar_up); \
        }; \
        class USP_G3C_CS_KP_OR_VQ { \
            displayName = "Put On OR Gloves"; \
        }; \
        class USP_G3C_CS_VQ { \
            displayName = ECSTRING(main,kneepads_off); \
        }; \
    }; \
}; \
class USP_G3C_CS_MX: ACEWARDROBE(base) { \
    class modifiableTo { \
        class USP_G3C_CS { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_G3C_CS_CU_MX { \
            displayName = ECSTRING(main,collar_up); \
        }; \
        class USP_G3C_CS_KP_MX { \
            displayName = ECSTRING(main,kneepads_on); \
        }; \
        class USP_G3C_CS_OR { \
            displayName = "Switch to OR Gloves"; \
        }; \
    }; \
}; \
class USP_G3C_CS_MX_VQ: ACEWARDROBE(base) { \
    class modifiableTo { \
        class USP_G3C_CS_CU_MX_VQ { \
            displayName = ECSTRING(main,collar_up); \
        }; \
        class USP_G3C_CS_OR_VQ { \
            displayName = "Switch to OR Gloves"; \
        }; \
        class USP_G3C_CS_VQ { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
    }; \
}; \
class USP_G3C_CS_OR: ACEWARDROBE(base) { \
    class modifiableTo { \
        class USP_G3C_CS { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_G3C_CS_MX { \
            displayName = "Switch to MX Gloves"; \
        }; \
        class USP_G3C_CS_CU_OR { \
            displayName = ECSTRING(main,collar_up); \
        }; \
        class USP_G3C_CS_KP_OR { \
            displayName = ECSTRING(main,kneepads_on); \
        }; \
    }; \
}; \
class USP_G3C_CS_OR_VQ: ACEWARDROBE(base) { \
    class modifiableTo { \
        class USP_G3C_CS_MX_VQ { \
            displayName = "Switch to MX Gloves"; \
        }; \
        class USP_G3C_CS_CU_OR_VQ { \
            displayName = ECSTRING(main,collar_up); \
        }; \
        class USP_G3C_CS_KP_OR_VQ { \
            displayName = ECSTRING(main,kneepads_on); \
        }; \
        class USP_G3C_CS_VQ { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
    }; \
}; \
class USP_G3C_CS_VQ: ACEWARDROBE(base) { \
    class modifiableTo { \
        class USP_G3C_CS_CU_VQ { \
            displayName = ECSTRING(main,collar_up); \
        }; \
        class USP_G3C_CS_KP_VQ { \
            displayName = ECSTRING(main,kneepads_on); \
        }; \
        class USP_G3C_CS_MX_VQ { \
            displayName = "Put On MX Gloves"; \
        }; \
        class USP_G3C_CS_OR_VQ { \
            displayName = "Put On OR Gloves"; \
        }; \
    }; \
}; \
class USP_G3C_CU: ACEWARDROBE(base_U_sleeves_down) { \
    class modifiableTo { \
        class USP_G3C { \
            displayName = ECSTRING(main,collar_down); \
        }; \
        class USP_G3C_RS_CU { \
            displayName = ECSTRING(main,roll_sleeves_up); \
        }; \
        class USP_G3C_CS_CU { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_CU_KP { \
            displayName = ECSTRING(main,kneepads_on); \
        }; \
        class USP_G3C_CU_MX { \
            displayName = "Put On MX Gloves"; \
        }; \
        class USP_G3C_CU_OR { \
            displayName = "Put On OR Gloves"; \
        }; \
    }; \
}; \
class USP_G3C_CU_KP: ACEWARDROBE(base_U_sleeves_down) { \
    class modifiableTo { \
        class USP_G3C_CU { \
            displayName = ECSTRING(main,kneepads_off); \
        }; \
        class USP_G3C_RS_CU_KP { \
            displayName = ECSTRING(main,roll_sleeves_up); \
        }; \
        class USP_G3C_CS_CU_KP { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_CU_KP_MX { \
            displayName = "Put On MX Gloves"; \
        }; \
        class USP_G3C_CU_KP_OR { \
            displayName = "Put On OR Gloves"; \
        }; \
        class USP_G3C_KP { \
            displayName = ECSTRING(main,collar_down); \
        }; \
    }; \
}; \
class USP_G3C_CU_KP_MX: ACEWARDROBE(base_U_sleeves_down) { \
    class modifiableTo { \
        class USP_G3C_CU_KP { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_G3C_RS_CU_KP_MX { \
            displayName = ECSTRING(main,roll_sleeves_up); \
        }; \
        class USP_G3C_CS_CU_KP_MX { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_CU_KP_OR { \
            displayName = "Switch to OR Gloves"; \
        }; \
        class USP_G3C_CU_MX { \
            displayName = ECSTRING(main,kneepads_off); \
        }; \
        class USP_G3C_KP_MX { \
            displayName = ECSTRING(main,collar_down); \
        }; \
    }; \
}; \
class USP_G3C_CU_KP_OR: ACEWARDROBE(base_U_sleeves_down) { \
    class modifiableTo { \
        class USP_G3C_CU_KP { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_G3C_CU_KP_MX { \
            displayName = "Switch to MX Gloves"; \
        }; \
        class USP_G3C_RS_CU_KP_OR { \
            displayName = ECSTRING(main,roll_sleeves_up); \
        }; \
        class USP_G3C_CS_CU_KP_OR { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_CU_OR { \
            displayName = ECSTRING(main,kneepads_off); \
        }; \
        class USP_G3C_KP_OR { \
            displayName = ECSTRING(main,collar_down); \
        }; \
    }; \
}; \
class USP_G3C_CU_MX: ACEWARDROBE(base_U_sleeves_down) { \
    class modifiableTo { \
        class USP_G3C_CU { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_G3C_RS_CU_MX { \
            displayName = ECSTRING(main,roll_sleeves_up); \
        }; \
        class USP_G3C_CS_CU_MX { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_CU_KP_MX { \
            displayName = ECSTRING(main,kneepads_on); \
        }; \
        class USP_G3C_CU_OR { \
            displayName = "Switch to OR Gloves"; \
        }; \
        class USP_G3C_MX { \
            displayName = ECSTRING(main,collar_down); \
        }; \
    }; \
}; \
class USP_G3C_CU_OR: ACEWARDROBE(base_U_sleeves_down) { \
    class modifiableTo { \
        class USP_G3C_CU { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_G3C_CU_MX { \
            displayName = "Switch to MX Gloves"; \
        }; \
        class USP_G3C_RS_CU_OR { \
            displayName = ECSTRING(main,roll_sleeves_up); \
        }; \
        class USP_G3C_CS_CU_OR { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_CU_KP_OR { \
            displayName = ECSTRING(main,kneepads_on); \
        }; \
        class USP_G3C_OR { \
            displayName = ECSTRING(main,collar_down); \
        }; \
    }; \
}; \
class USP_G3C_KP: ACEWARDROBE(base_U_sleeves_down) { \
    class modifiableTo { \
        class USP_G3C { \
            displayName = ECSTRING(main,kneepads_off); \
        }; \
        class USP_G3C_RS_KP { \
            displayName = ECSTRING(main,roll_sleeves_up); \
        }; \
        class USP_G3C_CS_KP { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_CU_KP { \
            displayName = ECSTRING(main,collar_up); \
        }; \
        class USP_G3C_KP_MX { \
            displayName = "Put On MX Gloves"; \
        }; \
        class USP_G3C_KP_OR { \
            displayName = "Put On OR Gloves"; \
        }; \
    }; \
}; \
class USP_G3C_KP_MX: ACEWARDROBE(base_U_sleeves_down) { \
    class modifiableTo { \
        class USP_G3C_KP { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_G3C_RS_KP_MX { \
            displayName = ECSTRING(main,roll_sleeves_up); \
        }; \
        class USP_G3C_CS_KP_MX { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_CU_KP_MX { \
            displayName = ECSTRING(main,collar_up); \
        }; \
        class USP_G3C_KP_OR { \
            displayName = "Switch to OR Gloves"; \
        }; \
        class USP_G3C_MX { \
            displayName = ECSTRING(main,kneepads_off); \
        }; \
    }; \
}; \
class USP_G3C_KP_OR: ACEWARDROBE(base_U_sleeves_down) { \
    class modifiableTo { \
        class USP_G3C_KP { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_G3C_KP_MX { \
            displayName = "Switch to MX Gloves"; \
        }; \
        class USP_G3C_RS_KP_OR { \
            displayName = ECSTRING(main,roll_sleeves_up); \
        }; \
        class USP_G3C_CS_KP_OR { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_CU_KP_OR { \
            displayName = ECSTRING(main,collar_up); \
        }; \
        class USP_G3C_OR { \
            displayName = ECSTRING(main,kneepads_off); \
        }; \
    }; \
}; \
class USP_G3C_MX: ACEWARDROBE(base_U_sleeves_down) { \
    class modifiableTo { \
        class USP_G3C { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_G3C_RS_MX { \
            displayName = ECSTRING(main,roll_sleeves_up); \
        }; \
        class USP_G3C_CS_MX { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_CU_MX { \
            displayName = ECSTRING(main,collar_up); \
        }; \
        class USP_G3C_KP_MX { \
            displayName = ECSTRING(main,kneepads_on); \
        }; \
        class USP_G3C_OR { \
            displayName = "Switch to OR Gloves"; \
        }; \
    }; \
}; \
class USP_G3C_MX_VQ: ACEWARDROBE(base_U_sleeves_down) { \
    class modifiableTo { \
        class USP_G3C_RS_MX_VQ { \
            displayName = ECSTRING(main,roll_sleeves_up); \
        }; \
        class USP_G3C_CS_MX_VQ { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_OR_VQ { \
            displayName = "Switch to OR Gloves"; \
        }; \
        class USP_G3C_VQ { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
    }; \
}; \
class USP_G3C_OR: ACEWARDROBE(base_U_sleeves_down) { \
    class modifiableTo { \
        class USP_G3C { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_G3C_MX { \
            displayName = "Switch to MX Gloves"; \
        }; \
        class USP_G3C_RS_OR { \
            displayName = ECSTRING(main,roll_sleeves_up); \
        }; \
        class USP_G3C_CS_OR { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_CU_OR { \
            displayName = ECSTRING(main,collar_up); \
        }; \
        class USP_G3C_KP_OR { \
            displayName = ECSTRING(main,kneepads_on); \
        }; \
    }; \
}; \
class USP_G3C_OR_VQ: ACEWARDROBE(base_U_sleeves_down) { \
    class modifiableTo { \
        class USP_G3C_MX_VQ { \
            displayName = "Switch to MX Gloves"; \
        }; \
        class USP_G3C_RS_OR_VQ { \
            displayName = ECSTRING(main,roll_sleeves_up); \
        }; \
        class USP_G3C_CS_OR_VQ { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_VQ { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
    }; \
}; \
class USP_G3C_RS: ACEWARDROBE(base_U_sleeves_up) { \
    class modifiableTo { \
        class USP_G3C { \
            displayName = ECSTRING(main,roll_sleeves_down); \
        }; \
        class USP_G3C_RS2 { \
            displayName = ECSTRING(main,roll_sleeves_up_further); \
        }; \
        class USP_G3C_CS { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_RS_CU { \
            displayName = ECSTRING(main,collar_up); \
        }; \
        class USP_G3C_RS_KP { \
            displayName = ECSTRING(main,kneepads_on); \
        }; \
        class USP_G3C_RS_MX { \
            displayName = "Put On MX Gloves"; \
        }; \
        class USP_G3C_RS_OR { \
            displayName = "Put On OR Gloves"; \
        }; \
    }; \
}; \
class USP_G3C_RS_CU: ACEWARDROBE(base_U_sleeves_up) { \
    class modifiableTo { \
        class USP_G3C_CU { \
            displayName = ECSTRING(main,roll_sleeves_down); \
        }; \
        class USP_G3C_RS { \
            displayName = ECSTRING(main,collar_down); \
        }; \
        class USP_G3C_RS2_CU { \
            displayName = ECSTRING(main,roll_sleeves_up_further); \
        }; \
        class USP_G3C_CS_CU { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_RS_CU_KP { \
            displayName = ECSTRING(main,kneepads_on); \
        }; \
        class USP_G3C_RS_CU_MX { \
            displayName = "Put On MX Gloves"; \
        }; \
        class USP_G3C_RS_CU_OR { \
            displayName = "Put On OR Gloves"; \
        }; \
    }; \
}; \
class USP_G3C_RS_CU_KP: ACEWARDROBE(base_U_sleeves_up) { \
    class modifiableTo { \
        class USP_G3C_CU_KP { \
            displayName = ECSTRING(main,roll_sleeves_down); \
        }; \
        class USP_G3C_RS_CU { \
            displayName = ECSTRING(main,kneepads_off); \
        }; \
        class USP_G3C_RS2_CU_KP { \
            displayName = ECSTRING(main,roll_sleeves_up_further); \
        }; \
        class USP_G3C_CS_CU_KP { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_RS_CU_KP_MX { \
            displayName = "Put On MX Gloves"; \
        }; \
        class USP_G3C_RS_CU_KP_OR { \
            displayName = "Put On OR Gloves"; \
        }; \
        class USP_G3C_RS_KP { \
            displayName = ECSTRING(main,collar_down); \
        }; \
    }; \
}; \
class USP_G3C_RS_CU_KP_MX: ACEWARDROBE(base_U_sleeves_up) { \
    class modifiableTo { \
        class USP_G3C_CU_KP_MX { \
            displayName = ECSTRING(main,roll_sleeves_down); \
        }; \
        class USP_G3C_RS_CU_KP { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_G3C_RS2_CU_KP_MX { \
            displayName = ECSTRING(main,roll_sleeves_up_further); \
        }; \
        class USP_G3C_CS_CU_KP_MX { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_RS_CU_KP_OR { \
            displayName = "Switch to OR Gloves"; \
        }; \
        class USP_G3C_RS_CU_MX { \
            displayName = ECSTRING(main,kneepads_off); \
        }; \
        class USP_G3C_RS_KP_MX { \
            displayName = ECSTRING(main,collar_down); \
        }; \
    }; \
}; \
class USP_G3C_RS_CU_KP_MX_VQ: ACEWARDROBE(base_U_sleeves_up) { \
    class modifiableTo { \
        class USP_G3C_RS2_CU_KP_MX_VQ { \
            displayName = ECSTRING(main,roll_sleeves_up_further); \
        }; \
        class USP_G3C_CS_CU_KP_MX_VQ { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_RS_CU_KP_OR_VQ { \
            displayName = "Switch to OR Gloves"; \
        }; \
        class USP_G3C_RS_CU_KP_VQ { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_G3C_RS_CU_MX_VQ { \
            displayName = ECSTRING(main,kneepads_off); \
        }; \
    }; \
}; \
class USP_G3C_RS_CU_KP_OR: ACEWARDROBE(base_U_sleeves_up) { \
    class modifiableTo { \
        class USP_G3C_CU_KP_OR { \
            displayName = ECSTRING(main,roll_sleeves_down); \
        }; \
        class USP_G3C_RS_CU_KP { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_G3C_RS_CU_KP_MX { \
            displayName = "Switch to MX Gloves"; \
        }; \
        class USP_G3C_RS2_CU_KP_OR { \
            displayName = ECSTRING(main,roll_sleeves_up_further); \
        }; \
        class USP_G3C_CS_CU_KP_OR { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_RS_CU_OR { \
            displayName = ECSTRING(main,kneepads_off); \
        }; \
        class USP_G3C_RS_KP_OR { \
            displayName = ECSTRING(main,collar_down); \
        }; \
    }; \
}; \
class USP_G3C_RS_CU_KP_OR_VQ: ACEWARDROBE(base_U_sleeves_up) { \
    class modifiableTo { \
        class USP_G3C_RS_CU_KP_MX_VQ { \
            displayName = "Switch to MX Gloves"; \
        }; \
        class USP_G3C_RS2_CU_KP_OR_VQ { \
            displayName = ECSTRING(main,roll_sleeves_up_further); \
        }; \
        class USP_G3C_CS_CU_KP_OR_VQ { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_RS_CU_KP_VQ { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_G3C_RS_CU_OR_VQ { \
            displayName = ECSTRING(main,kneepads_off); \
        }; \
        class USP_G3C_RS_KP_OR_VQ { \
            displayName = ECSTRING(main,collar_down); \
        }; \
    }; \
}; \
class USP_G3C_RS_CU_KP_VQ: ACEWARDROBE(base_U_sleeves_up) { \
    class modifiableTo { \
        class USP_G3C_RS2_CU_KP_VQ { \
            displayName = ECSTRING(main,roll_sleeves_up_further); \
        }; \
        class USP_G3C_CS_CU_KP_VQ { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_RS_CU_KP_MX_VQ { \
            displayName = "Put On MX Gloves"; \
        }; \
        class USP_G3C_RS_CU_KP_OR_VQ { \
            displayName = "Put On OR Gloves"; \
        }; \
        class USP_G3C_RS_CU_VQ { \
            displayName = ECSTRING(main,kneepads_off); \
        }; \
        class USP_G3C_RS_KP_VQ { \
            displayName = ECSTRING(main,collar_down); \
        }; \
    }; \
}; \
class USP_G3C_RS_CU_MX: ACEWARDROBE(base_U_sleeves_up) { \
    class modifiableTo { \
        class USP_G3C_CU_MX { \
            displayName = ECSTRING(main,roll_sleeves_down); \
        }; \
        class USP_G3C_RS_CU { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_G3C_RS2_CU_MX { \
            displayName = ECSTRING(main,roll_sleeves_up_further); \
        }; \
        class USP_G3C_CS_CU_MX { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_RS_CU_KP_MX { \
            displayName = ECSTRING(main,kneepads_on); \
        }; \
        class USP_G3C_RS_CU_OR { \
            displayName = "Switch to OR Gloves"; \
        }; \
        class USP_G3C_RS_MX { \
            displayName = ECSTRING(main,collar_down); \
        }; \
    }; \
}; \
class USP_G3C_RS_CU_MX_VQ: ACEWARDROBE(base_U_sleeves_up) { \
    class modifiableTo { \
        class USP_G3C_RS2_CU_MX_VQ { \
            displayName = ECSTRING(main,roll_sleeves_up_further); \
        }; \
        class USP_G3C_CS_CU_MX_VQ { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_RS_CU_KP_MX_VQ { \
            displayName = ECSTRING(main,kneepads_on); \
        }; \
        class USP_G3C_RS_CU_OR_VQ { \
            displayName = "Switch to OR Gloves"; \
        }; \
        class USP_G3C_RS_CU_VQ { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_G3C_RS_MX_VQ { \
            displayName = ECSTRING(main,collar_down); \
        }; \
    }; \
}; \
class USP_G3C_RS_CU_OR: ACEWARDROBE(base_U_sleeves_up) { \
    class modifiableTo { \
        class USP_G3C_CU_OR { \
            displayName = ECSTRING(main,roll_sleeves_down); \
        }; \
        class USP_G3C_RS_CU { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_G3C_RS_CU_MX { \
            displayName = "Switch to MX Gloves"; \
        }; \
        class USP_G3C_RS2_CU_OR { \
            displayName = ECSTRING(main,roll_sleeves_up_further); \
        }; \
        class USP_G3C_CS_CU_OR { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_RS_CU_KP_OR { \
            displayName = ECSTRING(main,kneepads_on); \
        }; \
        class USP_G3C_RS_OR { \
            displayName = ECSTRING(main,collar_down); \
        }; \
    }; \
}; \
class USP_G3C_RS_CU_OR_VQ: ACEWARDROBE(base_U_sleeves_up) { \
    class modifiableTo { \
        class USP_G3C_RS_CU_MX_VQ { \
            displayName = "Switch to MX Gloves"; \
        }; \
        class USP_G3C_RS2_CU_OR_VQ { \
            displayName = ECSTRING(main,roll_sleeves_up_further); \
        }; \
        class USP_G3C_CS_CU_OR_VQ { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_RS_CU_KP_OR_VQ { \
            displayName = ECSTRING(main,kneepads_on); \
        }; \
        class USP_G3C_RS_CU_VQ { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_G3C_RS_OR_VQ { \
            displayName = ECSTRING(main,collar_down); \
        }; \
    }; \
}; \
class USP_G3C_RS_CU_VQ: ACEWARDROBE(base_U_sleeves_up) { \
    class modifiableTo { \
        class USP_G3C_RS2_CU_VQ { \
            displayName = ECSTRING(main,roll_sleeves_up_further); \
        }; \
        class USP_G3C_CS_CU_VQ { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_RS_CU_KP_VQ { \
            displayName = ECSTRING(main,kneepads_on); \
        }; \
        class USP_G3C_RS_CU_MX_VQ { \
            displayName = "Put On MX Gloves"; \
        }; \
        class USP_G3C_RS_CU_OR_VQ { \
            displayName = "Put On OR Gloves"; \
        }; \
        class USP_G3C_RS_VQ { \
            displayName = ECSTRING(main,collar_down); \
        }; \
    }; \
}; \
class USP_G3C_RS_KP: ACEWARDROBE(base_U_sleeves_up) { \
    class modifiableTo { \
        class USP_G3C_KP { \
            displayName = ECSTRING(main,roll_sleeves_down); \
        }; \
        class USP_G3C_RS { \
            displayName = ECSTRING(main,kneepads_off); \
        }; \
        class USP_G3C_RS2_KP { \
            displayName = ECSTRING(main,roll_sleeves_up_further); \
        }; \
        class USP_G3C_CS_KP { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_RS_CU_KP { \
            displayName = ECSTRING(main,collar_up); \
        }; \
        class USP_G3C_RS_KP_MX { \
            displayName = "Put On MX Gloves"; \
        }; \
        class USP_G3C_RS_KP_OR { \
            displayName = "Put On OR Gloves"; \
        }; \
    }; \
}; \
class USP_G3C_RS_KP_MX: ACEWARDROBE(base_U_sleeves_up) { \
    class modifiableTo { \
        class USP_G3C_KP_MX { \
            displayName = ECSTRING(main,roll_sleeves_down); \
        }; \
        class USP_G3C_RS_KP { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_G3C_RS2_KP_MX { \
            displayName = ECSTRING(main,roll_sleeves_up_further); \
        }; \
        class USP_G3C_CS_KP_MX { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_RS_CU_KP_MX { \
            displayName = ECSTRING(main,collar_up); \
        }; \
        class USP_G3C_RS_KP_OR { \
            displayName = "Switch to OR Gloves"; \
        }; \
        class USP_G3C_RS_MX { \
            displayName = ECSTRING(main,kneepads_off); \
        }; \
    }; \
}; \
class USP_G3C_RS_KP_OR: ACEWARDROBE(base_U_sleeves_up) { \
    class modifiableTo { \
        class USP_G3C_KP_OR { \
            displayName = ECSTRING(main,roll_sleeves_down); \
        }; \
        class USP_G3C_RS_KP { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_G3C_RS_KP_MX { \
            displayName = "Switch to MX Gloves"; \
        }; \
        class USP_G3C_RS2_KP_OR { \
            displayName = ECSTRING(main,roll_sleeves_up_further); \
        }; \
        class USP_G3C_CS_KP_OR { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_RS_CU_KP_OR { \
            displayName = ECSTRING(main,collar_up); \
        }; \
        class USP_G3C_RS_OR { \
            displayName = ECSTRING(main,kneepads_off); \
        }; \
    }; \
}; \
class USP_G3C_RS_KP_OR_VQ: ACEWARDROBE(base_U_sleeves_up) { \
    class modifiableTo { \
        class USP_G3C_RS2_KP_OR_VQ { \
            displayName = ECSTRING(main,roll_sleeves_up_further); \
        }; \
        class USP_G3C_CS_KP_OR_VQ { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_RS_CU_KP_OR_VQ { \
            displayName = ECSTRING(main,collar_up); \
        }; \
        class USP_G3C_RS_KP_VQ { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_G3C_RS_OR_VQ { \
            displayName = ECSTRING(main,kneepads_off); \
        }; \
    }; \
}; \
class USP_G3C_RS_KP_VQ: ACEWARDROBE(base_U_sleeves_up) { \
    class modifiableTo { \
        class USP_G3C_RS2_KP_VQ { \
            displayName = ECSTRING(main,roll_sleeves_up_further); \
        }; \
        class USP_G3C_CS_KP_VQ { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_RS_CU_KP_VQ { \
            displayName = ECSTRING(main,collar_up); \
        }; \
        class USP_G3C_RS_KP_OR_VQ { \
            displayName = "Put On OR Gloves"; \
        }; \
        class USP_G3C_RS_VQ { \
            displayName = ECSTRING(main,kneepads_off); \
        }; \
    }; \
}; \
class USP_G3C_RS_MX: ACEWARDROBE(base_U_sleeves_up) { \
    class modifiableTo { \
        class USP_G3C_MX { \
            displayName = ECSTRING(main,roll_sleeves_down); \
        }; \
        class USP_G3C_RS { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_G3C_RS2_MX { \
            displayName = ECSTRING(main,roll_sleeves_up_further); \
        }; \
        class USP_G3C_CS_MX { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_RS_CU_MX { \
            displayName = ECSTRING(main,collar_up); \
        }; \
        class USP_G3C_RS_KP_MX { \
            displayName = ECSTRING(main,kneepads_on); \
        }; \
        class USP_G3C_RS_OR { \
            displayName = "Switch to OR Gloves"; \
        }; \
    }; \
}; \
class USP_G3C_RS_MX_VQ: ACEWARDROBE(base_U_sleeves_up) { \
    class modifiableTo { \
        class USP_G3C_MX_VQ { \
            displayName = ECSTRING(main,roll_sleeves_down); \
        }; \
        class USP_G3C_RS2_MX_VQ { \
            displayName = ECSTRING(main,roll_sleeves_up_further); \
        }; \
        class USP_G3C_CS_MX_VQ { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_RS_CU_MX_VQ { \
            displayName = ECSTRING(main,collar_up); \
        }; \
        class USP_G3C_RS_OR_VQ { \
            displayName = "Switch to OR Gloves"; \
        }; \
        class USP_G3C_RS_VQ { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
    }; \
}; \
class USP_G3C_RS_OR: ACEWARDROBE(base_U_sleeves_up) { \
    class modifiableTo { \
        class USP_G3C_OR { \
            displayName = ECSTRING(main,roll_sleeves_down); \
        }; \
        class USP_G3C_RS { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_G3C_RS_MX { \
            displayName = "Switch to MX Gloves"; \
        }; \
        class USP_G3C_RS2_OR { \
            displayName = ECSTRING(main,roll_sleeves_up_further); \
        }; \
        class USP_G3C_CS_OR { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_RS_CU_OR { \
            displayName = ECSTRING(main,collar_up); \
        }; \
        class USP_G3C_RS_KP_OR { \
            displayName = ECSTRING(main,kneepads_on); \
        }; \
    }; \
}; \
class USP_G3C_RS_OR_VQ: ACEWARDROBE(base_U_sleeves_up) { \
    class modifiableTo { \
        class USP_G3C_OR_VQ { \
            displayName = ECSTRING(main,roll_sleeves_down); \
        }; \
        class USP_G3C_RS_MX_VQ { \
            displayName = "Switch to MX Gloves"; \
        }; \
        class USP_G3C_RS2_OR_VQ { \
            displayName = ECSTRING(main,roll_sleeves_up_further); \
        }; \
        class USP_G3C_CS_OR_VQ { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_RS_CU_OR_VQ { \
            displayName = ECSTRING(main,collar_up); \
        }; \
        class USP_G3C_RS_KP_OR_VQ { \
            displayName = ECSTRING(main,kneepads_on); \
        }; \
        class USP_G3C_RS_VQ { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
    }; \
}; \
class USP_G3C_RS_VQ: ACEWARDROBE(base_U_sleeves_up) { \
    class modifiableTo { \
        class USP_G3C_CS_VQ { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_RS_CU_VQ { \
            displayName = ECSTRING(main,collar_up); \
        }; \
        class USP_G3C_RS_KP_VQ { \
            displayName = ECSTRING(main,kneepads_on); \
        }; \
        class USP_G3C_RS_MX_VQ { \
            displayName = "Put On MX Gloves"; \
        }; \
        class USP_G3C_RS_OR_VQ { \
            displayName = "Put On OR Gloves"; \
        }; \
        class USP_G3C_VQ { \
            displayName = ECSTRING(main,roll_sleeves_down); \
        }; \
    }; \
}; \
class USP_G3C_RS2: ACEWARDROBE(base_U_sleeves_up) { \
    class modifiableTo { \
        class USP_G3C_RS { \
            displayName = ECSTRING(main,roll_sleeves_down_partial); \
        }; \
        class USP_G3C_CS { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_RS2_CU { \
            displayName = ECSTRING(main,collar_up); \
        }; \
        class USP_G3C_RS2_KP { \
            displayName = ECSTRING(main,kneepads_on); \
        }; \
        class USP_G3C_RS2_MX { \
            displayName = "Put On MX Gloves"; \
        }; \
        class USP_G3C_RS2_OR { \
            displayName = "Put On OR Gloves"; \
        }; \
    }; \
}; \
class USP_G3C_RS2_CU: ACEWARDROBE(base_U_sleeves_up) { \
    class modifiableTo { \
        class USP_G3C_RS_CU { \
            displayName = ECSTRING(main,roll_sleeves_down_partial); \
        }; \
        class USP_G3C_RS2 { \
            displayName = ECSTRING(main,collar_down); \
        }; \
        class USP_G3C_CS_CU { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_RS2_CU_KP { \
            displayName = ECSTRING(main,kneepads_on); \
        }; \
        class USP_G3C_RS2_CU_MX { \
            displayName = "Put On MX Gloves"; \
        }; \
        class USP_G3C_RS2_CU_OR { \
            displayName = "Put On OR Gloves"; \
        }; \
    }; \
}; \
class USP_G3C_RS2_CU_KP: ACEWARDROBE(base_U_sleeves_up) { \
    class modifiableTo { \
        class USP_G3C_RS_CU_KP { \
            displayName = ECSTRING(main,roll_sleeves_down_partial); \
        }; \
        class USP_G3C_RS2_CU { \
            displayName = ECSTRING(main,kneepads_off); \
        }; \
        class USP_G3C_CS_CU_KP { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_RS2_CU_KP_MX { \
            displayName = "Put On MX Gloves"; \
        }; \
        class USP_G3C_RS2_CU_KP_OR { \
            displayName = "Put On OR Gloves"; \
        }; \
        class USP_G3C_RS2_KP { \
            displayName = ECSTRING(main,collar_down); \
        }; \
    }; \
}; \
class USP_G3C_RS2_CU_KP_MX: ACEWARDROBE(base_U_sleeves_up) { \
    class modifiableTo { \
        class USP_G3C_RS_CU_KP_MX { \
            displayName = ECSTRING(main,roll_sleeves_down_partial); \
        }; \
        class USP_G3C_RS2_CU_KP { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_G3C_CS_CU_KP_MX { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_RS2_CU_KP_OR { \
            displayName = "Switch to OR Gloves"; \
        }; \
        class USP_G3C_RS2_CU_MX { \
            displayName = ECSTRING(main,kneepads_off); \
        }; \
        class USP_G3C_RS2_KP_MX { \
            displayName = ECSTRING(main,collar_down); \
        }; \
    }; \
}; \
class USP_G3C_RS2_CU_KP_MX_VQ: ACEWARDROBE(base_U_sleeves_up) { \
    class modifiableTo { \
        class USP_G3C_RS_CU_KP_MX_VQ { \
            displayName = ECSTRING(main,roll_sleeves_down_partial); \
        }; \
        class USP_G3C_CS_CU_KP_MX_VQ { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_RS2_CU_KP_OR_VQ { \
            displayName = "Switch to OR Gloves"; \
        }; \
        class USP_G3C_RS2_CU_KP_VQ { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_G3C_RS2_CU_MX_VQ { \
            displayName = ECSTRING(main,kneepads_off); \
        }; \
    }; \
}; \
class USP_G3C_RS2_CU_KP_OR: ACEWARDROBE(base_U_sleeves_up) { \
    class modifiableTo { \
        class USP_G3C_RS_CU_KP_OR { \
            displayName = ECSTRING(main,roll_sleeves_down_partial); \
        }; \
        class USP_G3C_RS2_CU_KP { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_G3C_RS2_CU_KP_MX { \
            displayName = "Switch to MX Gloves"; \
        }; \
        class USP_G3C_CS_CU_KP_OR { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_RS2_CU_OR { \
            displayName = ECSTRING(main,kneepads_off); \
        }; \
        class USP_G3C_RS2_KP_OR { \
            displayName = ECSTRING(main,collar_down); \
        }; \
    }; \
}; \
class USP_G3C_RS2_CU_KP_OR_VQ: ACEWARDROBE(base_U_sleeves_up) { \
    class modifiableTo { \
        class USP_G3C_RS_CU_KP_OR_VQ { \
            displayName = ECSTRING(main,roll_sleeves_down_partial); \
        }; \
        class USP_G3C_RS2_CU_KP_MX_VQ { \
            displayName = "Switch to MX Gloves"; \
        }; \
        class USP_G3C_CS_CU_KP_OR_VQ { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_RS2_CU_KP_VQ { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_G3C_RS2_CU_OR_VQ { \
            displayName = ECSTRING(main,kneepads_off); \
        }; \
        class USP_G3C_RS2_KP_OR_VQ { \
            displayName = ECSTRING(main,collar_down); \
        }; \
    }; \
}; \
class USP_G3C_RS2_CU_KP_VQ: ACEWARDROBE(base_U_sleeves_up) { \
    class modifiableTo { \
        class USP_G3C_RS_CU_KP_VQ { \
            displayName = ECSTRING(main,roll_sleeves_down_partial); \
        }; \
        class USP_G3C_CS_CU_KP_VQ { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_RS2_CU_KP_MX_VQ { \
            displayName = "Put On MX Gloves"; \
        }; \
        class USP_G3C_RS2_CU_KP_OR_VQ { \
            displayName = "Put On OR Gloves"; \
        }; \
        class USP_G3C_RS2_CU_VQ { \
            displayName = ECSTRING(main,kneepads_off); \
        }; \
        class USP_G3C_RS2_KP_VQ { \
            displayName = ECSTRING(main,collar_down); \
        }; \
    }; \
}; \
class USP_G3C_RS2_CU_MX: ACEWARDROBE(base_U_sleeves_up) { \
    class modifiableTo { \
        class USP_G3C_RS_CU_MX { \
            displayName = ECSTRING(main,roll_sleeves_down_partial); \
        }; \
        class USP_G3C_RS2_CU { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_G3C_CS_CU_MX { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_RS2_CU_KP_MX { \
            displayName = ECSTRING(main,kneepads_on); \
        }; \
        class USP_G3C_RS2_CU_OR { \
            displayName = "Switch to OR Gloves"; \
        }; \
        class USP_G3C_RS2_MX { \
            displayName = ECSTRING(main,collar_down); \
        }; \
    }; \
}; \
class USP_G3C_RS2_CU_MX_VQ: ACEWARDROBE(base_U_sleeves_up) { \
    class modifiableTo { \
        class USP_G3C_RS_CU_MX_VQ { \
            displayName = ECSTRING(main,roll_sleeves_down_partial); \
        }; \
        class USP_G3C_CS_CU_MX_VQ { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_RS2_CU_KP_MX_VQ { \
            displayName = ECSTRING(main,kneepads_on); \
        }; \
        class USP_G3C_RS2_CU_OR_VQ { \
            displayName = "Switch to OR Gloves"; \
        }; \
        class USP_G3C_RS2_CU_VQ { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_G3C_RS2_MX_VQ { \
            displayName = ECSTRING(main,collar_down); \
        }; \
    }; \
}; \
class USP_G3C_RS2_CU_OR: ACEWARDROBE(base_U_sleeves_up) { \
    class modifiableTo { \
        class USP_G3C_RS_CU_OR { \
            displayName = ECSTRING(main,roll_sleeves_down_partial); \
        }; \
        class USP_G3C_RS2_CU { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_G3C_RS2_CU_MX { \
            displayName = "Switch to MX Gloves"; \
        }; \
        class USP_G3C_CS_CU_OR { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_RS2_CU_KP_OR { \
            displayName = ECSTRING(main,kneepads_on); \
        }; \
        class USP_G3C_RS2_OR { \
            displayName = ECSTRING(main,collar_down); \
        }; \
    }; \
}; \
class USP_G3C_RS2_CU_OR_VQ: ACEWARDROBE(base_U_sleeves_up) { \
    class modifiableTo { \
        class USP_G3C_RS_CU_OR_VQ { \
            displayName = ECSTRING(main,roll_sleeves_down_partial); \
        }; \
        class USP_G3C_RS2_CU_MX_VQ { \
            displayName = "Switch to MX Gloves"; \
        }; \
        class USP_G3C_CS_CU_OR_VQ { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_RS2_CU_KP_OR_VQ { \
            displayName = ECSTRING(main,kneepads_on); \
        }; \
        class USP_G3C_RS2_CU_VQ { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_G3C_RS2_OR_VQ { \
            displayName = ECSTRING(main,collar_down); \
        }; \
    }; \
}; \
class USP_G3C_RS2_CU_VQ: ACEWARDROBE(base_U_sleeves_up) { \
    class modifiableTo { \
        class USP_G3C_RS_CU_VQ { \
            displayName = ECSTRING(main,roll_sleeves_down_partial); \
        }; \
        class USP_G3C_CS_CU_VQ { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_RS2_CU_KP_VQ { \
            displayName = ECSTRING(main,kneepads_on); \
        }; \
        class USP_G3C_RS2_CU_MX_VQ { \
            displayName = "Put On MX Gloves"; \
        }; \
        class USP_G3C_RS2_CU_OR_VQ { \
            displayName = "Put On OR Gloves"; \
        }; \
    }; \
}; \
class USP_G3C_RS2_KP: ACEWARDROBE(base_U_sleeves_up) { \
    class modifiableTo { \
        class USP_G3C_RS_KP { \
            displayName = ECSTRING(main,roll_sleeves_down_partial); \
        }; \
        class USP_G3C_RS2 { \
            displayName = ECSTRING(main,kneepads_off); \
        }; \
        class USP_G3C_CS_KP { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_RS2_CU_KP { \
            displayName = ECSTRING(main,collar_up); \
        }; \
        class USP_G3C_RS2_KP_MX { \
            displayName = "Put On MX Gloves"; \
        }; \
        class USP_G3C_RS2_KP_OR { \
            displayName = "Put On OR Gloves"; \
        }; \
    }; \
}; \
class USP_G3C_RS2_KP_MX: ACEWARDROBE(base_U_sleeves_up) { \
    class modifiableTo { \
        class USP_G3C_RS_KP_MX { \
            displayName = ECSTRING(main,roll_sleeves_down_partial); \
        }; \
        class USP_G3C_RS2_KP { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_G3C_CS_KP_MX { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_RS2_CU_KP_MX { \
            displayName = ECSTRING(main,collar_up); \
        }; \
        class USP_G3C_RS2_KP_OR { \
            displayName = "Switch to OR Gloves"; \
        }; \
        class USP_G3C_RS2_MX { \
            displayName = ECSTRING(main,kneepads_off); \
        }; \
    }; \
}; \
class USP_G3C_RS2_KP_OR: ACEWARDROBE(base_U_sleeves_up) { \
    class modifiableTo { \
        class USP_G3C_RS_KP_OR { \
            displayName = ECSTRING(main,roll_sleeves_down_partial); \
        }; \
        class USP_G3C_RS2_KP { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_G3C_RS2_KP_MX { \
            displayName = "Switch to MX Gloves"; \
        }; \
        class USP_G3C_CS_KP_OR { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_RS2_CU_KP_OR { \
            displayName = ECSTRING(main,collar_up); \
        }; \
        class USP_G3C_RS2_OR { \
            displayName = ECSTRING(main,kneepads_off); \
        }; \
    }; \
}; \
class USP_G3C_RS2_KP_OR_VQ: ACEWARDROBE(base_U_sleeves_up) { \
    class modifiableTo { \
        class USP_G3C_RS_KP_OR_VQ { \
            displayName = ECSTRING(main,roll_sleeves_down_partial); \
        }; \
        class USP_G3C_CS_KP_OR_VQ { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_RS2_CU_KP_OR_VQ { \
            displayName = ECSTRING(main,collar_up); \
        }; \
        class USP_G3C_RS2_KP_VQ { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_G3C_RS2_OR_VQ { \
            displayName = ECSTRING(main,kneepads_off); \
        }; \
    }; \
}; \
class USP_G3C_RS2_KP_VQ: ACEWARDROBE(base_U_sleeves_up) { \
    class modifiableTo { \
        class USP_G3C_RS_KP_VQ { \
            displayName = ECSTRING(main,roll_sleeves_down_partial); \
        }; \
        class USP_G3C_CS_KP_VQ { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_RS2_CU_KP_VQ { \
            displayName = ECSTRING(main,collar_up); \
        }; \
        class USP_G3C_RS2_KP_OR_VQ { \
            displayName = "Put On OR Gloves"; \
        }; \
    }; \
}; \
class USP_G3C_RS2_MX: ACEWARDROBE(base_U_sleeves_up) { \
    class modifiableTo { \
        class USP_G3C_RS_MX { \
            displayName = ECSTRING(main,roll_sleeves_down_partial); \
        }; \
        class USP_G3C_RS2 { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_G3C_CS_MX { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_RS2_CU_MX { \
            displayName = ECSTRING(main,collar_up); \
        }; \
        class USP_G3C_RS2_KP_MX { \
            displayName = ECSTRING(main,kneepads_on); \
        }; \
        class USP_G3C_RS2_OR { \
            displayName = "Switch to OR Gloves"; \
        }; \
    }; \
}; \
class USP_G3C_RS2_MX_VQ: ACEWARDROBE(base_U_sleeves_up) { \
    class modifiableTo { \
        class USP_G3C_RS_MX_VQ { \
            displayName = ECSTRING(main,roll_sleeves_down_partial); \
        }; \
        class USP_G3C_CS_MX_VQ { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_RS2_CU_MX_VQ { \
            displayName = ECSTRING(main,collar_up); \
        }; \
        class USP_G3C_RS2_OR_VQ { \
            displayName = "Switch to OR Gloves"; \
        }; \
    }; \
}; \
class USP_G3C_RS2_OR: ACEWARDROBE(base_U_sleeves_up) { \
    class modifiableTo { \
        class USP_G3C_RS_OR { \
            displayName = ECSTRING(main,roll_sleeves_down_partial); \
        }; \
        class USP_G3C_RS2 { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_G3C_RS2_MX { \
            displayName = "Switch to MX Gloves"; \
        }; \
        class USP_G3C_CS_OR { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_RS2_CU_OR { \
            displayName = ECSTRING(main,collar_up); \
        }; \
        class USP_G3C_RS2_KP_OR { \
            displayName = ECSTRING(main,kneepads_on); \
        }; \
    }; \
}; \
class USP_G3C_RS2_OR_VQ: ACEWARDROBE(base_U_sleeves_up) { \
    class modifiableTo { \
        class USP_G3C_RS_OR_VQ { \
            displayName = ECSTRING(main,roll_sleeves_down_partial); \
        }; \
        class USP_G3C_RS2_MX_VQ { \
            displayName = "Switch to MX Gloves"; \
        }; \
        class USP_G3C_CS_OR_VQ { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_RS2_CU_OR_VQ { \
            displayName = ECSTRING(main,collar_up); \
        }; \
        class USP_G3C_RS2_KP_OR_VQ { \
            displayName = ECSTRING(main,kneepads_on); \
        }; \
    }; \
}; \
class USP_G3C_VQ: ACEWARDROBE(base_U_sleeves_down) { \
    class modifiableTo { \
        class USP_G3C_RS_VQ { \
            displayName = ECSTRING(main,roll_sleeves_up); \
        }; \
        class USP_G3C_CS_VQ { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
        class USP_G3C_MX_VQ { \
            displayName = "Put On MX Gloves"; \
        }; \
        class USP_G3C_OR_VQ { \
            displayName = "Put On OR Gloves"; \
        }; \
    }; \
}

// Some camo patterns only have the bare sleeve-state variants modelled (no collar/
// kneepad/glove/boot variants exist for them), so they use this smaller macro instead
// of USP_G3C_UNIFORMS(CAMO).
#define USP_G3C_UNIFORMS_SLEEVES_ONLY(CAMO) \
class USP_G3C_##CAMO: ACEWARDROBE(base_U_sleeves_down) { \
    class modifiableTo { \
        class USP_G3C_RS_##CAMO { \
            displayName = ECSTRING(main,roll_sleeves_up); \
        }; \
        class USP_G3C_CS_##CAMO { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
    }; \
}; \
class USP_G3C_CS_##CAMO: ACEWARDROBE(base) { \
}; \
class USP_G3C_RS_##CAMO: ACEWARDROBE(base_U_sleeves_up) { \
    class modifiableTo { \
        class USP_G3C_##CAMO { \
            displayName = ECSTRING(main,roll_sleeves_down); \
        }; \
        class USP_G3C_RS2_##CAMO { \
            displayName = ECSTRING(main,roll_sleeves_up_further); \
        }; \
        class USP_G3C_CS_##CAMO { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
    }; \
}; \
class USP_G3C_RS2_##CAMO: ACEWARDROBE(base_U_sleeves_up) { \
    class modifiableTo { \
        class USP_G3C_RS_##CAMO { \
            displayName = ECSTRING(main,roll_sleeves_down_partial); \
        }; \
        class USP_G3C_CS_##CAMO { \
            displayName = ECSTRING(main,cut_sleeves); \
        }; \
    }; \
}

// USP outer-layer jackets (PCU, Softshell, ...) that only vary by kneepads and gloves -
// no sleeve states or collar. TOP/BOTTOM are the two halves of the camo/colour code (e.g.
// GRY top over MCB bottom); TYPE picks the garment (PCU, SOFTSHELL, ...) sharing this layout.
#define USP_G3C_LAYER_UNIFORMS(TYPE,TOP,BOTTOM) \
class USP_##TYPE##_G3C_##TOP##_##BOTTOM: ACEWARDROBE(base) { \
    class modifiableTo { \
        class USP_##TYPE##_G3C_KP_##TOP##_##BOTTOM { \
            displayName = ECSTRING(main,kneepads_on); \
        }; \
        class USP_##TYPE##_G3C_MX_##TOP##_##BOTTOM { \
            displayName = "Put On MX Gloves"; \
        }; \
        class USP_##TYPE##_G3C_OR_##TOP##_##BOTTOM { \
            displayName = "Put On OR Gloves"; \
        }; \
    }; \
}; \
class USP_##TYPE##_G3C_KP_##TOP##_##BOTTOM: ACEWARDROBE(base) { \
    class modifiableTo { \
        class USP_##TYPE##_G3C_##TOP##_##BOTTOM { \
            displayName = ECSTRING(main,kneepads_off); \
        }; \
        class USP_##TYPE##_G3C_KP_MX_##TOP##_##BOTTOM { \
            displayName = "Put On MX Gloves"; \
        }; \
        class USP_##TYPE##_G3C_KP_OR_##TOP##_##BOTTOM { \
            displayName = "Put On OR Gloves"; \
        }; \
    }; \
}; \
class USP_##TYPE##_G3C_MX_##TOP##_##BOTTOM: ACEWARDROBE(base) { \
    class modifiableTo { \
        class USP_##TYPE##_G3C_##TOP##_##BOTTOM { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_##TYPE##_G3C_KP_MX_##TOP##_##BOTTOM { \
            displayName = ECSTRING(main,kneepads_on); \
        }; \
        class USP_##TYPE##_G3C_OR_##TOP##_##BOTTOM { \
            displayName = "Switch to OR Gloves"; \
        }; \
    }; \
}; \
class USP_##TYPE##_G3C_OR_##TOP##_##BOTTOM: ACEWARDROBE(base) { \
    class modifiableTo { \
        class USP_##TYPE##_G3C_##TOP##_##BOTTOM { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_##TYPE##_G3C_MX_##TOP##_##BOTTOM { \
            displayName = "Switch to MX Gloves"; \
        }; \
        class USP_##TYPE##_G3C_KP_OR_##TOP##_##BOTTOM { \
            displayName = ECSTRING(main,kneepads_on); \
        }; \
    }; \
}; \
class USP_##TYPE##_G3C_KP_MX_##TOP##_##BOTTOM: ACEWARDROBE(base) { \
    class modifiableTo { \
        class USP_##TYPE##_G3C_KP_##TOP##_##BOTTOM { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_##TYPE##_G3C_MX_##TOP##_##BOTTOM { \
            displayName = ECSTRING(main,kneepads_off); \
        }; \
        class USP_##TYPE##_G3C_KP_OR_##TOP##_##BOTTOM { \
            displayName = "Switch to OR Gloves"; \
        }; \
    }; \
}; \
class USP_##TYPE##_G3C_KP_OR_##TOP##_##BOTTOM: ACEWARDROBE(base) { \
    class modifiableTo { \
        class USP_##TYPE##_G3C_KP_##TOP##_##BOTTOM { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_##TYPE##_G3C_OR_##TOP##_##BOTTOM { \
            displayName = ECSTRING(main,kneepads_off); \
        }; \
        class USP_##TYPE##_G3C_KP_MX_##TOP##_##BOTTOM { \
            displayName = "Switch to MX Gloves"; \
        }; \
    }; \
}

// USP outer-layer jackets that only come in a single solid colour (no top/bottom pairing).
#define USP_G3C_LAYER_UNIFORMS_SOLID(TYPE,COLOR) \
class USP_##TYPE##_G3C_##COLOR: ACEWARDROBE(base) { \
    class modifiableTo { \
        class USP_##TYPE##_G3C_KP_##COLOR { \
            displayName = ECSTRING(main,kneepads_on); \
        }; \
        class USP_##TYPE##_G3C_MX_##COLOR { \
            displayName = "Put On MX Gloves"; \
        }; \
        class USP_##TYPE##_G3C_OR_##COLOR { \
            displayName = "Put On OR Gloves"; \
        }; \
    }; \
}; \
class USP_##TYPE##_G3C_KP_##COLOR: ACEWARDROBE(base) { \
    class modifiableTo { \
        class USP_##TYPE##_G3C_##COLOR { \
            displayName = ECSTRING(main,kneepads_off); \
        }; \
        class USP_##TYPE##_G3C_KP_MX_##COLOR { \
            displayName = "Put On MX Gloves"; \
        }; \
        class USP_##TYPE##_G3C_KP_OR_##COLOR { \
            displayName = "Put On OR Gloves"; \
        }; \
    }; \
}; \
class USP_##TYPE##_G3C_MX_##COLOR: ACEWARDROBE(base) { \
    class modifiableTo { \
        class USP_##TYPE##_G3C_##COLOR { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_##TYPE##_G3C_KP_MX_##COLOR { \
            displayName = ECSTRING(main,kneepads_on); \
        }; \
        class USP_##TYPE##_G3C_OR_##COLOR { \
            displayName = "Switch to OR Gloves"; \
        }; \
    }; \
}; \
class USP_##TYPE##_G3C_OR_##COLOR: ACEWARDROBE(base) { \
    class modifiableTo { \
        class USP_##TYPE##_G3C_##COLOR { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_##TYPE##_G3C_MX_##COLOR { \
            displayName = "Switch to MX Gloves"; \
        }; \
        class USP_##TYPE##_G3C_KP_OR_##COLOR { \
            displayName = ECSTRING(main,kneepads_on); \
        }; \
    }; \
}; \
class USP_##TYPE##_G3C_KP_MX_##COLOR: ACEWARDROBE(base) { \
    class modifiableTo { \
        class USP_##TYPE##_G3C_KP_##COLOR { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_##TYPE##_G3C_MX_##COLOR { \
            displayName = ECSTRING(main,kneepads_off); \
        }; \
        class USP_##TYPE##_G3C_KP_OR_##COLOR { \
            displayName = "Switch to OR Gloves"; \
        }; \
    }; \
}; \
class USP_##TYPE##_G3C_KP_OR_##COLOR: ACEWARDROBE(base) { \
    class modifiableTo { \
        class USP_##TYPE##_G3C_KP_##COLOR { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_##TYPE##_G3C_OR_##COLOR { \
            displayName = ECSTRING(main,kneepads_off); \
        }; \
        class USP_##TYPE##_G3C_KP_MX_##COLOR { \
            displayName = "Switch to MX Gloves"; \
        }; \
    }; \
}

// The solid-colour BLK variant has no colour suffix at all, same as the main uniform's BLK.
#define USP_G3C_LAYER_UNIFORMS_SOLID_BLK(TYPE) \
class USP_##TYPE##_G3C: ACEWARDROBE(base) { \
    class modifiableTo { \
        class USP_##TYPE##_G3C_KP { \
            displayName = ECSTRING(main,kneepads_on); \
        }; \
        class USP_##TYPE##_G3C_MX { \
            displayName = "Put On MX Gloves"; \
        }; \
        class USP_##TYPE##_G3C_OR { \
            displayName = "Put On OR Gloves"; \
        }; \
    }; \
}; \
class USP_##TYPE##_G3C_KP: ACEWARDROBE(base) { \
    class modifiableTo { \
        class USP_##TYPE##_G3C { \
            displayName = ECSTRING(main,kneepads_off); \
        }; \
        class USP_##TYPE##_G3C_KP_MX { \
            displayName = "Put On MX Gloves"; \
        }; \
        class USP_##TYPE##_G3C_KP_OR { \
            displayName = "Put On OR Gloves"; \
        }; \
    }; \
}; \
class USP_##TYPE##_G3C_MX: ACEWARDROBE(base) { \
    class modifiableTo { \
        class USP_##TYPE##_G3C { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_##TYPE##_G3C_KP_MX { \
            displayName = ECSTRING(main,kneepads_on); \
        }; \
        class USP_##TYPE##_G3C_OR { \
            displayName = "Switch to OR Gloves"; \
        }; \
    }; \
}; \
class USP_##TYPE##_G3C_OR: ACEWARDROBE(base) { \
    class modifiableTo { \
        class USP_##TYPE##_G3C { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_##TYPE##_G3C_MX { \
            displayName = "Switch to MX Gloves"; \
        }; \
        class USP_##TYPE##_G3C_KP_OR { \
            displayName = ECSTRING(main,kneepads_on); \
        }; \
    }; \
}; \
class USP_##TYPE##_G3C_KP_MX: ACEWARDROBE(base) { \
    class modifiableTo { \
        class USP_##TYPE##_G3C_KP { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_##TYPE##_G3C_MX { \
            displayName = ECSTRING(main,kneepads_off); \
        }; \
        class USP_##TYPE##_G3C_KP_OR { \
            displayName = "Switch to OR Gloves"; \
        }; \
    }; \
}; \
class USP_##TYPE##_G3C_KP_OR: ACEWARDROBE(base) { \
    class modifiableTo { \
        class USP_##TYPE##_G3C_KP { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_##TYPE##_G3C_OR { \
            displayName = ECSTRING(main,kneepads_off); \
        }; \
        class USP_##TYPE##_G3C_KP_MX { \
            displayName = "Switch to MX Gloves"; \
        }; \
    }; \
}

// USP Rugby shirt: kneepads come in two mutually-exclusive styles (KP / KP2) that only
// connect back to the bare state, never to each other directly - to switch styles you have
// to take the first pair off before putting the second on. Gloves (MX/OR, plus bare hands)
// still form their own fully-connected set, independent of which kneepad style is worn.
// COLOR/CAMO are the two halves of the colour code (e.g. CBR over AOR1).
#define USP_G3C_RUGBY_UNIFORMS(COLOR,CAMO) \
class USP_RUGBY_G3C_##COLOR##_##CAMO: ACEWARDROBE(base) { \
    class modifiableTo { \
        class USP_RUGBY_G3C_KP_##COLOR##_##CAMO { \
            displayName = ECSTRING(main,kneepads_on); \
        }; \
        class USP_RUGBY_G3C_KP2_##COLOR##_##CAMO { \
            displayName = "Put On Kneepads (Type 2)"; \
        }; \
        class USP_RUGBY_G3C_MX_##COLOR##_##CAMO { \
            displayName = "Put On MX Gloves"; \
        }; \
        class USP_RUGBY_G3C_OR_##COLOR##_##CAMO { \
            displayName = "Put On OR Gloves"; \
        }; \
    }; \
}; \
class USP_RUGBY_G3C_KP_##COLOR##_##CAMO: ACEWARDROBE(base) { \
    class modifiableTo { \
        class USP_RUGBY_G3C_##COLOR##_##CAMO { \
            displayName = ECSTRING(main,kneepads_off); \
        }; \
        class USP_RUGBY_G3C_KP_MX_##COLOR##_##CAMO { \
            displayName = "Put On MX Gloves"; \
        }; \
        class USP_RUGBY_G3C_KP_OR_##COLOR##_##CAMO { \
            displayName = "Put On OR Gloves"; \
        }; \
    }; \
}; \
class USP_RUGBY_G3C_KP2_##COLOR##_##CAMO: ACEWARDROBE(base) { \
    class modifiableTo { \
        class USP_RUGBY_G3C_##COLOR##_##CAMO { \
            displayName = "Take Off Kneepads (Type 2)"; \
        }; \
        class USP_RUGBY_G3C_KP2_MX_##COLOR##_##CAMO { \
            displayName = "Put On MX Gloves"; \
        }; \
        class USP_RUGBY_G3C_KP2_OR_##COLOR##_##CAMO { \
            displayName = "Put On OR Gloves"; \
        }; \
    }; \
}; \
class USP_RUGBY_G3C_MX_##COLOR##_##CAMO: ACEWARDROBE(base) { \
    class modifiableTo { \
        class USP_RUGBY_G3C_KP_MX_##COLOR##_##CAMO { \
            displayName = ECSTRING(main,kneepads_on); \
        }; \
        class USP_RUGBY_G3C_KP2_MX_##COLOR##_##CAMO { \
            displayName = "Put On Kneepads (Type 2)"; \
        }; \
        class USP_RUGBY_G3C_##COLOR##_##CAMO { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_RUGBY_G3C_OR_##COLOR##_##CAMO { \
            displayName = "Switch to OR Gloves"; \
        }; \
    }; \
}; \
class USP_RUGBY_G3C_OR_##COLOR##_##CAMO: ACEWARDROBE(base) { \
    class modifiableTo { \
        class USP_RUGBY_G3C_KP_OR_##COLOR##_##CAMO { \
            displayName = ECSTRING(main,kneepads_on); \
        }; \
        class USP_RUGBY_G3C_KP2_OR_##COLOR##_##CAMO { \
            displayName = "Put On Kneepads (Type 2)"; \
        }; \
        class USP_RUGBY_G3C_##COLOR##_##CAMO { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_RUGBY_G3C_MX_##COLOR##_##CAMO { \
            displayName = "Switch to MX Gloves"; \
        }; \
    }; \
}; \
class USP_RUGBY_G3C_KP_MX_##COLOR##_##CAMO: ACEWARDROBE(base) { \
    class modifiableTo { \
        class USP_RUGBY_G3C_MX_##COLOR##_##CAMO { \
            displayName = ECSTRING(main,kneepads_off); \
        }; \
        class USP_RUGBY_G3C_KP_##COLOR##_##CAMO { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_RUGBY_G3C_KP_OR_##COLOR##_##CAMO { \
            displayName = "Switch to OR Gloves"; \
        }; \
    }; \
}; \
class USP_RUGBY_G3C_KP_OR_##COLOR##_##CAMO: ACEWARDROBE(base) { \
    class modifiableTo { \
        class USP_RUGBY_G3C_OR_##COLOR##_##CAMO { \
            displayName = ECSTRING(main,kneepads_off); \
        }; \
        class USP_RUGBY_G3C_KP_##COLOR##_##CAMO { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_RUGBY_G3C_KP_MX_##COLOR##_##CAMO { \
            displayName = "Switch to MX Gloves"; \
        }; \
    }; \
}; \
class USP_RUGBY_G3C_KP2_MX_##COLOR##_##CAMO: ACEWARDROBE(base) { \
    class modifiableTo { \
        class USP_RUGBY_G3C_MX_##COLOR##_##CAMO { \
            displayName = "Take Off Kneepads (Type 2)"; \
        }; \
        class USP_RUGBY_G3C_KP2_##COLOR##_##CAMO { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_RUGBY_G3C_KP2_OR_##COLOR##_##CAMO { \
            displayName = "Switch to OR Gloves"; \
        }; \
    }; \
}; \
class USP_RUGBY_G3C_KP2_OR_##COLOR##_##CAMO: ACEWARDROBE(base) { \
    class modifiableTo { \
        class USP_RUGBY_G3C_OR_##COLOR##_##CAMO { \
            displayName = "Take Off Kneepads (Type 2)"; \
        }; \
        class USP_RUGBY_G3C_KP2_##COLOR##_##CAMO { \
            displayName = ECSTRING(main,gloves_off); \
        }; \
        class USP_RUGBY_G3C_KP2_MX_##COLOR##_##CAMO { \
            displayName = "Switch to MX Gloves"; \
        }; \
    }; \
}
