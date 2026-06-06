//焚天魔王 eq
inherit EQUIP;
#include <ansi.h>
void create()
{
set_name("紫芸仙帶" , ({"purpl belt","belt"}));
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
                set("armor_prop/dodge",3);
   set("long","這是一件由天上諸神採集先天靈氣所煉造而成的仙帶。\n");
   set("unequip_msg", "$N將$n脫掉,$N身上的$n所散發的靈氣隨之逝去。\n");
   set("wear_msg", "$N將$n穿上，$N身上的$n散發的靈氣將$N包圍。\n");
                setup();
        }
}

int query_autoload()
{
 return 1;
}
