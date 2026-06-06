inherit ITEM;
#include <ansi.h>

void create()
{
        set_name(HIR + "天道魔經殘卷" + NOR, ({ "Evil Book","evil book","book" }) );

        set("unit", "本");
        set("long", "殘留殷紅血漬的魔書，依稀寫著 「魔隨...e..rt cr.zy」。\n");
        set_weight(100);
        set("value",0);
        set("no_put",1);
        set("no_drop",1);
        set("no_get",1);
        set("no_sell",1);
        set("no_auc",1);
        set("no_give",1);
        set("no_steal",1);
        set("no_save",1);
}

