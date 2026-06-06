// made by onion
#include <weapon.h>
inherit STABBER;
void create()
{
        set_name("靈動扇",({"aura fan","fan"}) );
        set_weight(8000);
        if( clonep() )
		set_default_object(__FILE__);
	else {
        set("long","古時萬物皆有靈氣, 靈動之扇便是附著大地精靈之氣, 若有靈氣乍現。\n");
        set("unit","把");
        set("value", 9000);
        set("material","blacksteel");
	}
        init_stabber(70);
        setup();
}
