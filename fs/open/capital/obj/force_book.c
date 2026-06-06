inherit ITEM;
#include <ansi.h>

void create()
{
        set_name(HIY "本來無一物神功\心法" NOR, ({ "Force_Book","book" }) );

        set("unit", "本");
        set("long", "少林寺的精深內功\心法，但你天賦不夠聰穎，認定它不是什麼武學秘笈\n");
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

