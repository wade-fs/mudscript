#include <ansi.h>
#include <armor.h>
inherit EQUIP;
void create()
{
set_name("狂風戰披" , ({"wind cloak","cloak"}));
   set_weight(10000);
   set("armor_type","cape");
   if( clonep() )
           set_default_object(__FILE__);
   else {
   set("unit", "件");
   set("material","leather");
   set("value",100000);
   set("long","這是一件由天上諸神使用風岩石所打造的披風。\n");
   set("wear_msg", "$N將$n披上，"HIW"狂風戰披"NOR"的發出的光芒注入$N身中。\n");
   set("unequip_msg", "$N將$n脫掉，"HIW"狂風戰披"NOR"的光芒力量隨之逝去。\n");
   set("armor_prop/armor",6);
   set("armor_prop/stabber",3);
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
