#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIC + "五轉" + HIW + "聚" + HIY + "靈珠" + NOR, ({ "five turn ball","ball" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
		set("unit", "顆");
		set("long","為五轉聚靈盤的核心物件，可以增強五轉聚靈盤的能力。\n");
		set("value", 0);
		set("no_sell",1);
		set("no_put",1);
		set("no_auc",1);
		set("no_sac",1);
		set("no_drop",1);
		set("no_steal",1);
		set("no_give",1);
		set("five-ball",1);

        }
}
