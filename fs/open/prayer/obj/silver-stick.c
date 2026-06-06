#include <weapon.h>

inherit STICK;

void create()
{
        set_name( "銀雙節棍" , ({ "silver club","club"}) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "根");
                set("long", "一根銀製的雙節棍。\n");
                set("value", 4000);
                set("material", "silver");
        }
        init_stick(10);

        set("wield_msg", "只見到$N緩緩地將$n從布包中拿出，威風凜凜。\n");
        set("unwield_msg", "$N帥氣地將$n放回布包內。\n");

        setup();
}                   
