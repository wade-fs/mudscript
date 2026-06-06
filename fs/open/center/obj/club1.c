#include <weapon.h>

inherit BLADE;

void create()
{
        set_name("木棍",({"club","club"}) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long","這是一根木製的棍子，平常可以用來打人，\n"
                           "緊急狀況下還可以拿來當火把。\n");
                set("light_up", 15);
                set("value",60);
                set("material", "wood");
                set("wield_msg", "$N「唰」地一聲抽出一把$n握在手中。\n");
                set("unwield_msg", "$N將手中的$n插入腰間的腰帶。\n");
        }
        init_blade(10);
        setup();
}

