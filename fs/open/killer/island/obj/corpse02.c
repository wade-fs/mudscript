#include <ansi.h>
inherit ITEM;
void create()
{
    set_name("骸骨", ({ "corpse"}) );
    set_weight(1000000);
 if( clonep() )
    set_default_object(__FILE__);
 else {
       set("long", "屍骨殘缺不全，看來生前受到極大的傷害。\n");
       set("unit", "具");
       set("value", 0);
       set("no_sell",1);
       set("no_auc",1);
       set("no_give",1);
       set("no_get",1);
      }
    setup();
}
