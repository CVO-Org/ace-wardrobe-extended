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
            displayName = ECSTRING(main,collar_down); \
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
            displayName = ECSTRING(main,gloves_off); \
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

// One invocation per camo pattern - all 15 share the AOR1 combination set above.
USP_G3C_UNIFORMS(AOR1);
USP_G3C_UNIFORMS(AOR2);
USP_G3C_UNIFORMS(BLK);
USP_G3C_UNIFORMS(GRY);
USP_G3C_UNIFORMS(KHK);
USP_G3C_UNIFORMS(M81);
USP_G3C_UNIFORMS(MC);
USP_G3C_UNIFORMS(MCB);
USP_G3C_UNIFORMS(MCW);
USP_G3C_UNIFORMS(MCT);
USP_G3C_UNIFORMS(MCD);
USP_G3C_UNIFORMS(NAV);
USP_G3C_UNIFORMS(RGR);
USP_G3C_UNIFORMS(TSD);
USP_G3C_UNIFORMS(TSW);
