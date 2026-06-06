// fusword.c
#include <weapon.h>
#include <ansi.h>

inherit UNARMED;

void create()
{
        seteuid(getuid());
set_name(HIB + "七步攝魂爪" + NOR,({"seven claw","claw"}));
set_weight(5000);

        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
set("long","這把武器是心玄老師經過二十年精心製做,所含的威力只有本人能完全發揮。\n");

                set("value",10000);
            set("rigidity",100);
                set("material", "crimsonsteel");
set("wield_msg","$N裝備起$n．．突然間激起$N高昂鬥志!!");
        }
        init_unarmed(30);
        setup();
}
