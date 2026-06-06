#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIY"黃金甲龍的龍頭"NOR, ({ "dragon-head","head" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "個");
                set("long","黃金甲龍的龍頭.\n");
                set("value", 0);
        set("feed", 1);           //可以餵馬
                set("no_sell",1);
                set("no_put",1);
                set("no_auc",1);
                set("no_sac",1);
  set("no_drop",1);
        }
}

