#include <armor.h>
#include <ansi.h>
inherit HEAD;
object me=this_player();
void create()
{
        set_name(HIY"聖者頭巾"NOR, ({"kensai scarf", "scarf"}));
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("unit", "條");
        set("value", 0);
        set("material", "linen");
        set("long","劍聖專用之頭巾.能使劍聖視野遼闊。\n");
        set("armor_prop/armor", 5);
        set("no_auc",1);
        set("no_sell",1);
        set("no_give",1);
        set("no_put",1);
        set("no_drop",1);
        set("no_get",1);
        set("thunder",100);
        set("wear_msg", "$N戴上$n，渾身上下散發出傲人氣息。\n");
        }
        setup();
if(me->query("class")=="swordsman") this_object()->set("armor_prop/sword",6);
        this_object()->set("armor_prop/dodge", 6);
        this_object()->set("armor_prop/parry", 4);
        this_object()->set("armor_prop/move", 4);
}

