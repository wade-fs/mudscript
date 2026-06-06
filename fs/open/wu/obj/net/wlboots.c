inherit EQUIP;
#include <ansi.h>
#include <armor.h>
void create()
{
set_name("狂風戰靴" , ({"wind boots","boots"}));
         set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("unit", "雙");
        set("value",110000);
        set("material","cloth");
        set("armor_type", "boots");
          set("armor_prop/armor",6);
   set("long","這是一件由天上諸神使用風岩石所打造的戰靴。\n");
   set("wear_msg", "$N將$n穿上，" + HIW + "狂風戰靴" + NOR + "的發出的光芒注入$N身中。\n");
   set("unequip_msg", "$N將$n脫掉，" + HIW + "狂風戰靴" + NOR + "的光芒力量隨之逝去。\n");
   set("armor_prop/stabber",2);
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
