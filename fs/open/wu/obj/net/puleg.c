#include <ansi.h>
#include <armor.h>
inherit EQUIP;
void create()
{
set_name("紫芸仙巾",({"purple legging","legging"}));
   set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
   set("long","這是一件由天上諸神採集先天靈氣所煉造而成的仙巾。\n");
   set("unequip_msg", "$N將$n脫掉,$N身上的$n所散發的靈氣隨之逝去。\n");
   set("wear_msg", "$N將$n穿上，$N身上的$n散發的靈氣將$N包圍。\n");
        set("unit","件");
        set("value",70000);
        set("material","cloth");
        set("armor_type","leggings");
        set("armor_prop/armor",6);
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
