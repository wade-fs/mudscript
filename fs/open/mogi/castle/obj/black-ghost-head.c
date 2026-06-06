#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIW+BLK"黑羅剎的人頭"NOR, ({ "black-ghost-head","head" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "個");
                set("long","魔界二大護法之黑羅剎的人頭.\n");
                set("value", 0);
                set("no_sell",1);
                set("no_put",1);
                set("no_auc",1);
                set("no_sac",1);
      set("no_drop",1);
        }
}

