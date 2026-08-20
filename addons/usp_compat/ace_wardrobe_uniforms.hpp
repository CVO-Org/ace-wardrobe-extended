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

// One invocation per camo pattern, alphabetically sorted within each macro type. BLK has no
// camo suffix at all; AMCU/DCU/MM14/MPD/MPW/MTN/MTP/RBS only have the sleeve-state variants
// modelled; the rest use the full uniform matrix.
USP_G3C_UNIFORMS_BLK;
USP_G3C_UNIFORMS_SLEEVES_ONLY(AMCU);
USP_G3C_UNIFORMS_SLEEVES_ONLY(DCU);
USP_G3C_UNIFORMS_SLEEVES_ONLY(MM14);
USP_G3C_UNIFORMS_SLEEVES_ONLY(MPD);
USP_G3C_UNIFORMS_SLEEVES_ONLY(MPW);
USP_G3C_UNIFORMS_SLEEVES_ONLY(MTN);
USP_G3C_UNIFORMS_SLEEVES_ONLY(MTP);
USP_G3C_UNIFORMS_SLEEVES_ONLY(RBS);
USP_G3C_UNIFORMS(AOR1);
USP_G3C_UNIFORMS(AOR2);
USP_G3C_UNIFORMS(GRY);
USP_G3C_UNIFORMS(KHK);
USP_G3C_UNIFORMS(M81);
USP_G3C_UNIFORMS(MC);
USP_G3C_UNIFORMS(MCB);
USP_G3C_UNIFORMS(MCD);
USP_G3C_UNIFORMS(MCT);
USP_G3C_UNIFORMS(MCW);
USP_G3C_UNIFORMS(NAV);
USP_G3C_UNIFORMS(RGR);
USP_G3C_UNIFORMS(TSD);
USP_G3C_UNIFORMS(TSW);

// Known TOP_BOTTOM combinations, alphabetically sorted within each garment type. TOP and
// BOTTOM both draw from the same camo palette - a colour isn't fixed to one slot - so this
// is every ordered pairing between the colours confirmed to appear in this layer at all.
USP_G3C_LAYER_UNIFORMS(PCU,AOR1,AOR2);
USP_G3C_LAYER_UNIFORMS(PCU,AOR1,BLK);
USP_G3C_LAYER_UNIFORMS(PCU,AOR1,GRY);
USP_G3C_LAYER_UNIFORMS(PCU,AOR1,KHK);
USP_G3C_LAYER_UNIFORMS(PCU,AOR1,M81);
USP_G3C_LAYER_UNIFORMS(PCU,AOR1,MC);
USP_G3C_LAYER_UNIFORMS(PCU,AOR1,MCB);
USP_G3C_LAYER_UNIFORMS(PCU,AOR1,MCD);
USP_G3C_LAYER_UNIFORMS(PCU,AOR1,MCT);
USP_G3C_LAYER_UNIFORMS(PCU,AOR1,MCW);
USP_G3C_LAYER_UNIFORMS(PCU,AOR1,NAV);
USP_G3C_LAYER_UNIFORMS(PCU,AOR1,RGR);
USP_G3C_LAYER_UNIFORMS(PCU,AOR1,TSD);
USP_G3C_LAYER_UNIFORMS(PCU,AOR1,TSW);
USP_G3C_LAYER_UNIFORMS(PCU,AOR2,AOR1);
USP_G3C_LAYER_UNIFORMS(PCU,AOR2,BLK);
USP_G3C_LAYER_UNIFORMS(PCU,AOR2,GRY);
USP_G3C_LAYER_UNIFORMS(PCU,AOR2,KHK);
USP_G3C_LAYER_UNIFORMS(PCU,AOR2,M81);
USP_G3C_LAYER_UNIFORMS(PCU,AOR2,MC);
USP_G3C_LAYER_UNIFORMS(PCU,AOR2,MCB);
USP_G3C_LAYER_UNIFORMS(PCU,AOR2,MCD);
USP_G3C_LAYER_UNIFORMS(PCU,AOR2,MCT);
USP_G3C_LAYER_UNIFORMS(PCU,AOR2,MCW);
USP_G3C_LAYER_UNIFORMS(PCU,AOR2,NAV);
USP_G3C_LAYER_UNIFORMS(PCU,AOR2,RGR);
USP_G3C_LAYER_UNIFORMS(PCU,AOR2,TSD);
USP_G3C_LAYER_UNIFORMS(PCU,AOR2,TSW);
USP_G3C_LAYER_UNIFORMS(PCU,BLK,AOR1);
USP_G3C_LAYER_UNIFORMS(PCU,BLK,AOR2);
USP_G3C_LAYER_UNIFORMS(PCU,BLK,GRY);
USP_G3C_LAYER_UNIFORMS(PCU,BLK,KHK);
USP_G3C_LAYER_UNIFORMS(PCU,BLK,M81);
USP_G3C_LAYER_UNIFORMS(PCU,BLK,MC);
USP_G3C_LAYER_UNIFORMS(PCU,BLK,MCB);
USP_G3C_LAYER_UNIFORMS(PCU,BLK,MCD);
USP_G3C_LAYER_UNIFORMS(PCU,BLK,MCT);
USP_G3C_LAYER_UNIFORMS(PCU,BLK,MCW);
USP_G3C_LAYER_UNIFORMS(PCU,BLK,NAV);
USP_G3C_LAYER_UNIFORMS(PCU,BLK,RGR);
USP_G3C_LAYER_UNIFORMS(PCU,BLK,TSD);
USP_G3C_LAYER_UNIFORMS(PCU,BLK,TSW);
USP_G3C_LAYER_UNIFORMS(PCU,GRY,AOR1);
USP_G3C_LAYER_UNIFORMS(PCU,GRY,AOR2);
USP_G3C_LAYER_UNIFORMS(PCU,GRY,BLK);
USP_G3C_LAYER_UNIFORMS(PCU,GRY,KHK);
USP_G3C_LAYER_UNIFORMS(PCU,GRY,M81);
USP_G3C_LAYER_UNIFORMS(PCU,GRY,MC);
USP_G3C_LAYER_UNIFORMS(PCU,GRY,MCB);
USP_G3C_LAYER_UNIFORMS(PCU,GRY,MCD);
USP_G3C_LAYER_UNIFORMS(PCU,GRY,MCT);
USP_G3C_LAYER_UNIFORMS(PCU,GRY,MCW);
USP_G3C_LAYER_UNIFORMS(PCU,GRY,NAV);
USP_G3C_LAYER_UNIFORMS(PCU,GRY,RGR);
USP_G3C_LAYER_UNIFORMS(PCU,GRY,TSD);
USP_G3C_LAYER_UNIFORMS(PCU,GRY,TSW);
USP_G3C_LAYER_UNIFORMS(PCU,KHK,AOR1);
USP_G3C_LAYER_UNIFORMS(PCU,KHK,AOR2);
USP_G3C_LAYER_UNIFORMS(PCU,KHK,BLK);
USP_G3C_LAYER_UNIFORMS(PCU,KHK,GRY);
USP_G3C_LAYER_UNIFORMS(PCU,KHK,M81);
USP_G3C_LAYER_UNIFORMS(PCU,KHK,MC);
USP_G3C_LAYER_UNIFORMS(PCU,KHK,MCB);
USP_G3C_LAYER_UNIFORMS(PCU,KHK,MCD);
USP_G3C_LAYER_UNIFORMS(PCU,KHK,MCT);
USP_G3C_LAYER_UNIFORMS(PCU,KHK,MCW);
USP_G3C_LAYER_UNIFORMS(PCU,KHK,NAV);
USP_G3C_LAYER_UNIFORMS(PCU,KHK,RGR);
USP_G3C_LAYER_UNIFORMS(PCU,KHK,TSD);
USP_G3C_LAYER_UNIFORMS(PCU,KHK,TSW);
USP_G3C_LAYER_UNIFORMS(PCU,M81,AOR1);
USP_G3C_LAYER_UNIFORMS(PCU,M81,AOR2);
USP_G3C_LAYER_UNIFORMS(PCU,M81,BLK);
USP_G3C_LAYER_UNIFORMS(PCU,M81,GRY);
USP_G3C_LAYER_UNIFORMS(PCU,M81,KHK);
USP_G3C_LAYER_UNIFORMS(PCU,M81,MC);
USP_G3C_LAYER_UNIFORMS(PCU,M81,MCB);
USP_G3C_LAYER_UNIFORMS(PCU,M81,MCD);
USP_G3C_LAYER_UNIFORMS(PCU,M81,MCT);
USP_G3C_LAYER_UNIFORMS(PCU,M81,MCW);
USP_G3C_LAYER_UNIFORMS(PCU,M81,NAV);
USP_G3C_LAYER_UNIFORMS(PCU,M81,RGR);
USP_G3C_LAYER_UNIFORMS(PCU,M81,TSD);
USP_G3C_LAYER_UNIFORMS(PCU,M81,TSW);
USP_G3C_LAYER_UNIFORMS(PCU,MC,AOR1);
USP_G3C_LAYER_UNIFORMS(PCU,MC,AOR2);
USP_G3C_LAYER_UNIFORMS(PCU,MC,BLK);
USP_G3C_LAYER_UNIFORMS(PCU,MC,GRY);
USP_G3C_LAYER_UNIFORMS(PCU,MC,KHK);
USP_G3C_LAYER_UNIFORMS(PCU,MC,M81);
USP_G3C_LAYER_UNIFORMS(PCU,MC,MCB);
USP_G3C_LAYER_UNIFORMS(PCU,MC,MCD);
USP_G3C_LAYER_UNIFORMS(PCU,MC,MCT);
USP_G3C_LAYER_UNIFORMS(PCU,MC,MCW);
USP_G3C_LAYER_UNIFORMS(PCU,MC,NAV);
USP_G3C_LAYER_UNIFORMS(PCU,MC,RGR);
USP_G3C_LAYER_UNIFORMS(PCU,MC,TSD);
USP_G3C_LAYER_UNIFORMS(PCU,MC,TSW);
USP_G3C_LAYER_UNIFORMS(PCU,MCB,AOR1);
USP_G3C_LAYER_UNIFORMS(PCU,MCB,AOR2);
USP_G3C_LAYER_UNIFORMS(PCU,MCB,BLK);
USP_G3C_LAYER_UNIFORMS(PCU,MCB,GRY);
USP_G3C_LAYER_UNIFORMS(PCU,MCB,KHK);
USP_G3C_LAYER_UNIFORMS(PCU,MCB,M81);
USP_G3C_LAYER_UNIFORMS(PCU,MCB,MC);
USP_G3C_LAYER_UNIFORMS(PCU,MCB,MCD);
USP_G3C_LAYER_UNIFORMS(PCU,MCB,MCT);
USP_G3C_LAYER_UNIFORMS(PCU,MCB,MCW);
USP_G3C_LAYER_UNIFORMS(PCU,MCB,NAV);
USP_G3C_LAYER_UNIFORMS(PCU,MCB,RGR);
USP_G3C_LAYER_UNIFORMS(PCU,MCB,TSD);
USP_G3C_LAYER_UNIFORMS(PCU,MCB,TSW);
USP_G3C_LAYER_UNIFORMS(PCU,MCD,AOR1);
USP_G3C_LAYER_UNIFORMS(PCU,MCD,AOR2);
USP_G3C_LAYER_UNIFORMS(PCU,MCD,BLK);
USP_G3C_LAYER_UNIFORMS(PCU,MCD,GRY);
USP_G3C_LAYER_UNIFORMS(PCU,MCD,KHK);
USP_G3C_LAYER_UNIFORMS(PCU,MCD,M81);
USP_G3C_LAYER_UNIFORMS(PCU,MCD,MC);
USP_G3C_LAYER_UNIFORMS(PCU,MCD,MCB);
USP_G3C_LAYER_UNIFORMS(PCU,MCD,MCT);
USP_G3C_LAYER_UNIFORMS(PCU,MCD,MCW);
USP_G3C_LAYER_UNIFORMS(PCU,MCD,NAV);
USP_G3C_LAYER_UNIFORMS(PCU,MCD,RGR);
USP_G3C_LAYER_UNIFORMS(PCU,MCD,TSD);
USP_G3C_LAYER_UNIFORMS(PCU,MCD,TSW);
USP_G3C_LAYER_UNIFORMS(PCU,MCT,AOR1);
USP_G3C_LAYER_UNIFORMS(PCU,MCT,AOR2);
USP_G3C_LAYER_UNIFORMS(PCU,MCT,BLK);
USP_G3C_LAYER_UNIFORMS(PCU,MCT,GRY);
USP_G3C_LAYER_UNIFORMS(PCU,MCT,KHK);
USP_G3C_LAYER_UNIFORMS(PCU,MCT,M81);
USP_G3C_LAYER_UNIFORMS(PCU,MCT,MC);
USP_G3C_LAYER_UNIFORMS(PCU,MCT,MCB);
USP_G3C_LAYER_UNIFORMS(PCU,MCT,MCD);
USP_G3C_LAYER_UNIFORMS(PCU,MCT,MCW);
USP_G3C_LAYER_UNIFORMS(PCU,MCT,NAV);
USP_G3C_LAYER_UNIFORMS(PCU,MCT,RGR);
USP_G3C_LAYER_UNIFORMS(PCU,MCT,TSD);
USP_G3C_LAYER_UNIFORMS(PCU,MCT,TSW);
USP_G3C_LAYER_UNIFORMS(PCU,MCW,AOR1);
USP_G3C_LAYER_UNIFORMS(PCU,MCW,AOR2);
USP_G3C_LAYER_UNIFORMS(PCU,MCW,BLK);
USP_G3C_LAYER_UNIFORMS(PCU,MCW,GRY);
USP_G3C_LAYER_UNIFORMS(PCU,MCW,KHK);
USP_G3C_LAYER_UNIFORMS(PCU,MCW,M81);
USP_G3C_LAYER_UNIFORMS(PCU,MCW,MC);
USP_G3C_LAYER_UNIFORMS(PCU,MCW,MCB);
USP_G3C_LAYER_UNIFORMS(PCU,MCW,MCD);
USP_G3C_LAYER_UNIFORMS(PCU,MCW,MCT);
USP_G3C_LAYER_UNIFORMS(PCU,MCW,NAV);
USP_G3C_LAYER_UNIFORMS(PCU,MCW,RGR);
USP_G3C_LAYER_UNIFORMS(PCU,MCW,TSD);
USP_G3C_LAYER_UNIFORMS(PCU,MCW,TSW);
USP_G3C_LAYER_UNIFORMS(PCU,NAV,AOR1);
USP_G3C_LAYER_UNIFORMS(PCU,NAV,AOR2);
USP_G3C_LAYER_UNIFORMS(PCU,NAV,BLK);
USP_G3C_LAYER_UNIFORMS(PCU,NAV,GRY);
USP_G3C_LAYER_UNIFORMS(PCU,NAV,KHK);
USP_G3C_LAYER_UNIFORMS(PCU,NAV,M81);
USP_G3C_LAYER_UNIFORMS(PCU,NAV,MC);
USP_G3C_LAYER_UNIFORMS(PCU,NAV,MCB);
USP_G3C_LAYER_UNIFORMS(PCU,NAV,MCD);
USP_G3C_LAYER_UNIFORMS(PCU,NAV,MCT);
USP_G3C_LAYER_UNIFORMS(PCU,NAV,MCW);
USP_G3C_LAYER_UNIFORMS(PCU,NAV,RGR);
USP_G3C_LAYER_UNIFORMS(PCU,NAV,TSD);
USP_G3C_LAYER_UNIFORMS(PCU,NAV,TSW);
USP_G3C_LAYER_UNIFORMS(PCU,RGR,AOR1);
USP_G3C_LAYER_UNIFORMS(PCU,RGR,AOR2);
USP_G3C_LAYER_UNIFORMS(PCU,RGR,BLK);
USP_G3C_LAYER_UNIFORMS(PCU,RGR,GRY);
USP_G3C_LAYER_UNIFORMS(PCU,RGR,KHK);
USP_G3C_LAYER_UNIFORMS(PCU,RGR,M81);
USP_G3C_LAYER_UNIFORMS(PCU,RGR,MC);
USP_G3C_LAYER_UNIFORMS(PCU,RGR,MCB);
USP_G3C_LAYER_UNIFORMS(PCU,RGR,MCD);
USP_G3C_LAYER_UNIFORMS(PCU,RGR,MCT);
USP_G3C_LAYER_UNIFORMS(PCU,RGR,MCW);
USP_G3C_LAYER_UNIFORMS(PCU,RGR,NAV);
USP_G3C_LAYER_UNIFORMS(PCU,RGR,TSD);
USP_G3C_LAYER_UNIFORMS(PCU,RGR,TSW);
USP_G3C_LAYER_UNIFORMS(PCU,TSD,AOR1);
USP_G3C_LAYER_UNIFORMS(PCU,TSD,AOR2);
USP_G3C_LAYER_UNIFORMS(PCU,TSD,BLK);
USP_G3C_LAYER_UNIFORMS(PCU,TSD,GRY);
USP_G3C_LAYER_UNIFORMS(PCU,TSD,KHK);
USP_G3C_LAYER_UNIFORMS(PCU,TSD,M81);
USP_G3C_LAYER_UNIFORMS(PCU,TSD,MC);
USP_G3C_LAYER_UNIFORMS(PCU,TSD,MCB);
USP_G3C_LAYER_UNIFORMS(PCU,TSD,MCD);
USP_G3C_LAYER_UNIFORMS(PCU,TSD,MCT);
USP_G3C_LAYER_UNIFORMS(PCU,TSD,MCW);
USP_G3C_LAYER_UNIFORMS(PCU,TSD,NAV);
USP_G3C_LAYER_UNIFORMS(PCU,TSD,RGR);
USP_G3C_LAYER_UNIFORMS(PCU,TSD,TSW);
USP_G3C_LAYER_UNIFORMS(PCU,TSW,AOR1);
USP_G3C_LAYER_UNIFORMS(PCU,TSW,AOR2);
USP_G3C_LAYER_UNIFORMS(PCU,TSW,BLK);
USP_G3C_LAYER_UNIFORMS(PCU,TSW,GRY);
USP_G3C_LAYER_UNIFORMS(PCU,TSW,KHK);
USP_G3C_LAYER_UNIFORMS(PCU,TSW,M81);
USP_G3C_LAYER_UNIFORMS(PCU,TSW,MC);
USP_G3C_LAYER_UNIFORMS(PCU,TSW,MCB);
USP_G3C_LAYER_UNIFORMS(PCU,TSW,MCD);
USP_G3C_LAYER_UNIFORMS(PCU,TSW,MCT);
USP_G3C_LAYER_UNIFORMS(PCU,TSW,MCW);
USP_G3C_LAYER_UNIFORMS(PCU,TSW,NAV);
USP_G3C_LAYER_UNIFORMS(PCU,TSW,RGR);
USP_G3C_LAYER_UNIFORMS(PCU,TSW,TSD);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,AOR1,AOR2);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,AOR1,BLK);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,AOR1,GRY);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,AOR1,KHK);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,AOR1,M81);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,AOR1,MC);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,AOR1,MCB);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,AOR1,MCD);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,AOR1,MCT);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,AOR1,MCW);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,AOR1,NAV);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,AOR1,RGR);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,AOR1,TSD);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,AOR1,TSW);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,AOR2,AOR1);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,AOR2,BLK);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,AOR2,GRY);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,AOR2,KHK);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,AOR2,M81);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,AOR2,MC);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,AOR2,MCB);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,AOR2,MCD);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,AOR2,MCT);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,AOR2,MCW);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,AOR2,NAV);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,AOR2,RGR);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,AOR2,TSD);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,AOR2,TSW);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,BLK,AOR1);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,BLK,AOR2);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,BLK,GRY);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,BLK,KHK);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,BLK,M81);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,BLK,MC);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,BLK,MCB);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,BLK,MCD);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,BLK,MCT);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,BLK,MCW);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,BLK,NAV);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,BLK,RGR);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,BLK,TSD);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,BLK,TSW);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,GRY,AOR1);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,GRY,AOR2);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,GRY,BLK);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,GRY,KHK);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,GRY,M81);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,GRY,MC);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,GRY,MCB);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,GRY,MCD);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,GRY,MCT);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,GRY,MCW);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,GRY,NAV);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,GRY,RGR);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,GRY,TSD);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,GRY,TSW);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,KHK,AOR1);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,KHK,AOR2);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,KHK,BLK);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,KHK,GRY);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,KHK,M81);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,KHK,MC);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,KHK,MCB);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,KHK,MCD);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,KHK,MCT);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,KHK,MCW);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,KHK,NAV);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,KHK,RGR);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,KHK,TSD);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,KHK,TSW);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,M81,AOR1);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,M81,AOR2);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,M81,BLK);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,M81,GRY);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,M81,KHK);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,M81,MC);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,M81,MCB);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,M81,MCD);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,M81,MCT);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,M81,MCW);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,M81,NAV);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,M81,RGR);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,M81,TSD);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,M81,TSW);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,MC,AOR1);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,MC,AOR2);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,MC,BLK);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,MC,GRY);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,MC,KHK);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,MC,M81);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,MC,MCB);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,MC,MCD);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,MC,MCT);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,MC,MCW);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,MC,NAV);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,MC,RGR);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,MC,TSD);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,MC,TSW);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,MCB,AOR1);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,MCB,AOR2);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,MCB,BLK);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,MCB,GRY);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,MCB,KHK);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,MCB,M81);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,MCB,MC);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,MCB,MCD);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,MCB,MCT);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,MCB,MCW);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,MCB,NAV);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,MCB,RGR);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,MCB,TSD);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,MCB,TSW);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,MCD,AOR1);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,MCD,AOR2);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,MCD,BLK);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,MCD,GRY);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,MCD,KHK);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,MCD,M81);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,MCD,MC);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,MCD,MCB);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,MCD,MCT);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,MCD,MCW);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,MCD,NAV);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,MCD,RGR);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,MCD,TSD);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,MCD,TSW);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,MCT,AOR1);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,MCT,AOR2);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,MCT,BLK);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,MCT,GRY);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,MCT,KHK);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,MCT,M81);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,MCT,MC);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,MCT,MCB);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,MCT,MCD);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,MCT,MCW);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,MCT,NAV);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,MCT,RGR);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,MCT,TSD);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,MCT,TSW);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,MCW,AOR1);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,MCW,AOR2);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,MCW,BLK);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,MCW,GRY);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,MCW,KHK);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,MCW,M81);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,MCW,MC);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,MCW,MCB);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,MCW,MCD);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,MCW,MCT);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,MCW,NAV);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,MCW,RGR);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,MCW,TSD);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,MCW,TSW);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,NAV,AOR1);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,NAV,AOR2);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,NAV,BLK);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,NAV,GRY);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,NAV,KHK);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,NAV,M81);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,NAV,MC);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,NAV,MCB);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,NAV,MCD);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,NAV,MCT);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,NAV,MCW);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,NAV,RGR);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,NAV,TSD);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,NAV,TSW);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,RGR,AOR1);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,RGR,AOR2);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,RGR,BLK);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,RGR,GRY);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,RGR,KHK);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,RGR,M81);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,RGR,MC);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,RGR,MCB);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,RGR,MCD);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,RGR,MCT);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,RGR,MCW);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,RGR,NAV);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,RGR,TSD);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,RGR,TSW);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,TSD,AOR1);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,TSD,AOR2);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,TSD,BLK);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,TSD,GRY);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,TSD,KHK);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,TSD,M81);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,TSD,MC);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,TSD,MCB);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,TSD,MCD);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,TSD,MCT);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,TSD,MCW);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,TSD,NAV);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,TSD,RGR);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,TSD,TSW);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,TSW,AOR1);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,TSW,AOR2);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,TSW,BLK);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,TSW,GRY);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,TSW,KHK);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,TSW,M81);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,TSW,MC);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,TSW,MCB);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,TSW,MCD);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,TSW,MCT);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,TSW,MCW);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,TSW,NAV);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,TSW,RGR);
USP_G3C_LAYER_UNIFORMS(SOFTSHELL,TSW,TSD);

// Known single-colour PCU variants (BLK has no suffix at all).
USP_G3C_LAYER_UNIFORMS_SOLID_BLK(PCU);
USP_G3C_LAYER_UNIFORMS_SOLID(PCU,GRY);
USP_G3C_LAYER_UNIFORMS_SOLID(PCU,MC);
USP_G3C_LAYER_UNIFORMS_SOLID(PCU,MCB);
USP_G3C_LAYER_UNIFORMS_SOLID(PCU,MCD);
USP_G3C_LAYER_UNIFORMS_SOLID(PCU,MCT);
