// Qc by anmy (98/3/3)
#include <ansi.h>
#include <armor.h>
inherit HANDS;
object me=this_player();
void create()
{
        set_name(HIB + "魔龍手甲" + NOR,({"mdragon hands","hands"}));
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("unit", "雙");
        set("value",0);
        set("long","為魔龍皮革所製。\n");
set("wear_msg","$N戴上$n，頓時力量增強數倍。\n");
        set("material","steel");
        set("armor_prop/armor", 9);
        set("no_auc",1);
        set("no_sell",1);
        set("no_give",1);
        set("no_put",1);
        set("no_drop",1);
        set("no_get",1);
        }
        setup();
if(me->query("class")=="blademan")  this_object()->set("armor_prop/blade", 5);
if(me->query("class")=="fighter")   this_object()->set("armor_prop/unarmed",5);
if(me->query("class")=="swordsman") this_object()->set("armor_prop/sword",5);
if(me->query("class")=="scholar")   this_object()->set("armor_prop/stabber",5);
if(me->query("class")=="bandit")    this_object()->set("armor_prop/unarmed",5);
        this_object()->set("armor_prop/attack", 5);
        this_object()->set("armor_prop/dodge",4);
        this_object()->set("armor_prop/parry",4);
        this_object()->set("armor_prop/move",4);
        this_object()->set("armor_prop/force",3);
}

