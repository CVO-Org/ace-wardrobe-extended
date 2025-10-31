#define BANDANA_GOGGLES(BandanaBase,BandanaGoggles1,BandanaGoggles2,Goggles1,Goggles2)\
class BandanaBase: ace_wardrobe_base {\
    class modifiableTo {\
        class BandanaGoggles1 {};\
        class BandanaGoggles2 {};\
    };\
};\
class BandanaGoggles1: ace_wardrobe_base {\
    class modifiableTo {\
        class BandanaBase {};\
    };\
    components[] = {QUOTE(Goggles1)};\
};\
class BandanaGoggles2: ace_wardrobe_base {\
    class modifiableTo {\
        class BandanaBase {};\
    };\
    components[] = {QUOTE(Goggles2)};\
}

BANDANA_GOGGLES(UK3CB_G_Bandanna_brown_check,UK3CB_G_Bandanna_aviator_brown_check,UK3CB_G_Bandanna_shades_brown_check,G_Aviator,G_Shades_Black);
BANDANA_GOGGLES(UK3CB_G_Bandanna_flora_alt,UK3CB_G_Bandanna_aviator_flora_alt,UK3CB_G_Bandanna_shades_flora_altG_Aviator,G_Aviator,G_Shades_Black);
BANDANA_GOGGLES(UK3CB_G_Bandanna_green_check,UK3CB_G_Bandanna_aviator_green_check,UK3CB_G_Bandanna_shades_green_check,G_Aviator,G_Shades_Black);
BANDANA_GOGGLES(UK3CB_G_Bandanna_red_check,UK3CB_G_Bandanna_aviator_red_check,UK3CB_G_Bandanna_shades_red_check,G_Aviator,G_Shades_Black);
BANDANA_GOGGLES(UK3CB_G_Bandanna_winter_flora_alt,UK3CB_G_Bandanna_aviator_winter_flora_alt,UK3CB_G_Bandanna_shades_winter_flora_alt,G_Aviator,G_Shades_Black);
BANDANA_GOGGLES(UK3CB_G_Bandanna_winter,UK3CB_G_Bandanna_aviator_winter,UK3CB_G_Bandanna_shades_white_check,G_Aviator,G_Shades_Black);
