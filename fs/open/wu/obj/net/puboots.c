inherit EQUIP;
#include <ansi.h>
#include <armor.h>
void create()
{
set_name("紫芸舞鞋" , ({"purple boots","boots"}));
         set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("unit", "雙");
        set("value",110000);
        set("material","cloth");
        set("armor_type", "boots");
          set("armor_prop/armor",6);
   set("long","這是一件由天上諸神採集先天靈氣所煉造而成的舞靴。\n");
   set("unequip_msg", "$N將$n脫掉,$N身上的$n所散發的靈氣隨之逝去。\n");
   set("wear_msg", "$N將$n穿上，$N身上的$n散發的靈氣將$N包圍。\n");
   set("armor_prop/dodge",2);
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
