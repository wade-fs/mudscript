inherit ITEM;
#include <ansi.h>

void create()
{
        set_name(HIM "無雙拳理" NOR, ({ "Fist_Book","book" }) );

        set("unit", "本");
        set("long", "無雙寺的鎮寺之學，但你天賦不夠聰穎，認定它不是什麼武學秘笈\n");
        set_weight(100);
        set("value",0);
        set("no_put",1);
        set("no_drop",1);
        set("no_get",1);
        set("no_sell",1);
        set("no_auc",1);
        set("no_give",1);
        set("no_steal",1);
}

