inherit ITEM;
#include <ansi.h>

void create()
{
        set_name(HIG "柳葉霸刀奧義" NOR, ({ "Leaf_Book","book" }) );

        set("unit", "本");
        set("long", "柳葉山莊的傳家刀法精要，但你天賦不夠聰穎，認定它不是什麼武學秘笈\n");
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

