#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(YEL"蛇郎君人頭"NOR, ({ "master-snake-head","head" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("unit", "個");
		set("long","蛇寨寨主「蛇郎君」的人頭。\n");
		set("value", 0);
		set("no_sell",1);
		set("no_put",1);
		set("no_auc",1);
		set("no_sac",1);
        set("feed",1); //可餵馬
		set("magic-manor",4);
        }
}
