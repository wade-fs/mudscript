//stone.c 紅寶石 解 quests/stone 所需的item  97/11/17 by anmy

#include <weapon.h>
#include <ansi.h>
inherit STABBER;

void create()
{
        set_name(HIR + "紅寶石" + NOR,({"stone"}));
        set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("unit", "顆");
                set("long","此寶石據說為洋人所愛用。\n");
                set("value",0);
		set("material", "steel");
        set("no_sell",1);
                set("wield_msg", "$N從胸前口袋裡拿出一顆$n。\n");
                set("unwield_msg", "$N將$n收進胸前口袋中。\n");
	}
        init_stabber(50);
	setup();
}
int wield()
{
        if((string)this_player()->query("family/family_name") != "儒門")
           return notify_fail("紅寶石只有儒家的人能用\n");
        else{
              ::wield();
            }
        return 1;
}
