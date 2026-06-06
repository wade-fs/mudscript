#include <ansi.h>
#include <armor.h>
inherit EQUIP;
void create()
{
set_name("狂風戰鍊",({"wind neck","neck"}));
   set_weight(5000);
   if ( clonep() )
       set_default_object(__FILE__);
   else {
   set("long","這是一件由天上諸神使用風岩石所打造的項鍊。\n");
   set("wear_msg", "$N將$n載上，" + HIW + "狂風戰鍊" + NOR + "的發出的光芒注入$N身中。\n");
   set("unequip_msg", "$N將$n脫掉，" + HIW + "狂風戰鍊" + NOR + "的光芒力量隨之逝去。\n");
   set("armor_prop/armor",7);
   set("armor_prop/stabber",3);
   set("unit", "條");
   set("armor_type", "neck");
   set("value", 30000);
   set("no_sell",1);
   set("no_auc",1);
   set("no_drop",1);
     }
   setup();
}
int query_autoload()
{
 return 1;
}
