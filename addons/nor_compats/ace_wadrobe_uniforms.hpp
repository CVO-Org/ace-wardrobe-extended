class NOR_Combat_Uniform: ace_wardrobe_base {
    class modifiableTo {
        class NOR_Combat_Uniform_Gloves {};
        class NOR_Combat_Uniform_Rolled {};
    };
};
class NOR_Combat_Uniform_Gloves: ace_wardrobe_base {
    class modifiableTo {
        class NOR_Combat_Uniform {};
        class NOR_Combat_Uniform_Gloves_Rolled {};
    };
};
class NOR_Combat_Uniform_Rolled: ace_wardrobe_base {
    class modifiableTo {
        class NOR_Combat_Uniform {};
        class NOR_Combat_Uniform_Gloves_Rolled {};
    };
};
class NOR_Combat_Uniform_Gloves_Rolled: ace_wardrobe_base {
    class modifiableTo {
        class NOR_Combat_Uniform_Rolled {};
        class NOR_Combat_Uniform_Gloves {};
    };
};