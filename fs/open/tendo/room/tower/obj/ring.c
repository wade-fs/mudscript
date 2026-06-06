
#include <weapon.h>
#include <ansi.h>

inherit UNARMED;

void create()
{
        seteuid(getuid());
        set_name(HIB "修羅戰鬥指環" NOR,({"fiend ring","ring"}));
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
	set("unit", "把");
	set("value",10000);
	set("material", "steel");
	set("sharp",8);
	set("material","gem");
        }
        init_unarmed(40);
        setup();
}


