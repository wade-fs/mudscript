//太皇刀─藍牙------by dhk 2000.4.22
#include <ansi.h>
inherit ITEM;

void create()
{
    set_name(""HIY"太皇刀"NOR"─"HIB"藍牙"NOR"", ({ "kingblade bluetooth","kingblade","bluetooth" }) );
    set_weight(1000);
 if( clonep() )
    set_default_object(__FILE__);
 else {
       set("long", "這是一把曾由比軒轅皇帝時代更早的太皇帝隨身兵器，相傳\n"
                  +"此兵器會令使用者發狂，而且揮舞之時會出現似殘神藍虎之\n"
                  +"利牙的光影，只要跟其他兵器相交鋒，其兵器會被藍牙粉碎\n");
       set("unit", "把");
       set("value", 150000);
       set("no_get",1);
       set("no_auc",1);
       set("no_sell",1);
       set("no_drop",1);
       
      }
    setup();
}
