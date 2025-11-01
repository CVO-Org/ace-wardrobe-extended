class Flex_CUP_POL_BDU_Pads: ace_wardrobe_base {
    class modifiableTo {
        class Flex_CUP_POL_BDU_Rolled_Pads {};
        class Flex_CUP_POL_BDU_Gloves_Pads {};
    };
};

class Flex_CUP_POL_BDU_Rolled_Pads: ace_wardrobe_base_U_sleeves_up {
    class modifiableTo {
        class Flex_CUP_POL_BDU_Gloves_Pads_Rolled {};
        class Flex_CUP_POL_BDU_Pads {};
    };
};

class Flex_CUP_POL_BDU_Gloves_Pads: ace_wardrobe_base_U_gloves_on {
    class modifiableTo {
        class Flex_CUP_POL_BDU_Gloves_Pads_Rolled {};
        class Flex_CUP_POL_BDU_Pads {};
    };
};

class Flex_CUP_POL_BDU_Gloves_Pads_Rolled: ace_wardrobe_base {
    class modifiableTo {
        class Flex_CUP_POL_BDU_Rolled_Pads {};
        class Flex_CUP_POL_BDU_Gloves_Pads {};
    };
};

class Flex_CUP_POL_BDU: ace_wardrobe_base {
    class modifiableTo {
        class Flex_CUP_POL_BDU_Rolled {};
        class Flex_CUP_POL_BDU_Gloves {};
    };
};

class Flex_CUP_POL_BDU_Rolled: ace_wardrobe_base_U_sleeves_up {
    class modifiableTo {
        class Flex_CUP_POL_BDU_Gloves_Rolled {};
        class Flex_CUP_POL_BDU {};
    };
};

class Flex_CUP_POL_BDU_Gloves: ace_wardrobe_base_U_gloves_on {
    class modifiableTo {
        class Flex_CUP_POL_BDU_Gloves_Rolled {};
        class Flex_CUP_POL_BDU {};
    };
};

class Flex_CUP_POL_BDU_Gloves_Rolled: ace_wardrobe_base {
    class modifiableTo {
        class Flex_CUP_POL_BDU_Rolled {};
        class Flex_CUP_POL_BDU_Gloves {};
    };
};
