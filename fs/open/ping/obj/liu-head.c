#include <ansi.h>
inherit ITEM;
void create()
{
        set_name("劉信的人頭", ({ "liu-head","head" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "個");
                set("long","二頭目劉信的人頭.\n");
                set("value", 0);
                set("no_sell",1);
                set("no_put",1);
                set("no_auc",1);
//馬可以吃
set("feed",1);
                set("no_sac",1);
  set("no_drop",1);
        }
}

