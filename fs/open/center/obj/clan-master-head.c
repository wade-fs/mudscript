#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(YEL + "長樂幫總舵主人頭" + NOR, ({ "clan-master-head" }) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "個");
                set("long","江湖第一幫幫主的人頭.\n");
                set("value", 0);
                set("no_sell",1);
                set("no_put",1);
                set("no_auc",1);
                set("no_sac",1);
  set("no_drop",1);
        }
}

