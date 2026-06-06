//總鏢頭的信------by dhk 2000.4.22
#include <ansi.h>
inherit ITEM;

void create()
{
    set_name("總鏢頭的信", ({ "leader_letter","letter" }) );
    set_weight(10);
 if( clonep() )
    set_default_object(__FILE__);
 else {
       set("long", "這是一封給副鏢頭的信。\n");
       set("unit", "封");
       set("value", 150);
       set("no_sell",1);
       set("no_auc",1);
       set("no_get",1);      
      }
    setup();
}

