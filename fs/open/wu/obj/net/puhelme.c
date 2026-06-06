#include <armor.h>
#include <ansi.h>
inherit HEAD;
void create()
{
set_name("紫芸仙冠" , ({"purple helme","helme"}));
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
   set("long","這是一件由天上諸神採集先天靈氣所煉造而成的仙冠。\n");
   set("unequip_msg", "$N將$n脫掉,$N身上的$n所散發的靈氣隨之逝去。\n");
   set("wear_msg", "$N將$n穿上，$N身上的$n散發的靈氣將$N包圍。\n");
   set("armor_prop/dodge",3);
        set("no_sell",1);
        set("no_auc",1);
        set("no_drop",1);
      set("armor_prop/armor",7);
        set("unit", "頂");
        set("value", 30000);
        set("material", "steel");
        }
        setup();
}
int query_autoload()
{
 return 1;
}
