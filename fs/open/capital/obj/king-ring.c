//king ring
#include <weapon.h>
#include <ansi.h>

inherit UNARMED;

void create()
{
        seteuid(getuid());
        set_name(HIM + "玉帝指環" + NOR,({"king ring","ring"}));
        set_weight(4500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "對");
         set("long","玉帝賜給天子的神奇兵器，在戰鬥中有神奇的力量。\n");

                set("value",500000);
                set("material", "crimsonsteel");
                set("ski_level",70);
                set("ski_type","unarmed");
        }
          init_unarmed(80);

        setup();
}
