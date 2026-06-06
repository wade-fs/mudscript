inherit ITEM;
#include <ansi.h>

void create()
{
        set_name(HIC + "英雄真經" + NOR, ({ "Real_Hero Book","book" }) );

        set("unit", "本");
        set("long", "武林人士夢寐以求的驚世武學，但你天賦不夠聰穎，認定它不是什麼武學秘笈\n");
        set_weight(100);
        set("value",0);
        set("no_put",1);
	set("no_save",1);
        set("no_drop",1);
        set("no_get",1);
        set("no_sell",1);
        set("no_auc",1);
        set("no_give",1);
        set("no_steal",1);
}

