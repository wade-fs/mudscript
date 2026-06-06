//焚天魔王 eq
inherit EQUIP;
#include <ansi.h>
void create()
{
set_name("狂風腰帶" , ({"wind belt","belt"}));
         set_weight(300);
        set("no_sell",1);
        set("no_auc",1);
        set("no_drop",1);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
                set("value", 70000);
                set("material","leather");
                set("armor_type", "waist");
                set("armor_prop/armor",7);
                set("armor_prop/stabber",3);
   set("long","這是一件由天上諸神使用風岩石所打造的腰帶。\n");
   set("wear_msg", "$N將$n束上，" + HIW + "狂風腰帶" + NOR + "的發出的光芒注入$N身中。\n");
   set("unequip_msg", "$N將$n脫掉，" + HIW + "狂風腰帶" + NOR + "的光芒力量隨之逝去。\n");
                setup();
        }
}

int query_autoload()
{
 return 1;
}
