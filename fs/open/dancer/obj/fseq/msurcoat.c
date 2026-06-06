// 網聚獎品by cgy(22/10/00)
#include <ansi.h>
#include <armor.h>
inherit CAPE;
object me=this_player();
void create()
{
        set_name(HIW + "菠蘿麵包隱身披風" + NOR,({"Wade_cloak","cloak"}));
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
        set("value",0);
        set("material","steel");
        set("long","這是一件菠蘿麵包賜與的披風，擁有不可思議的功\能。\n");
set("wear_msg","只見$N伸手凌空一指，變出了$n，$N的身影變的模糊不清。\n");
set("remove_msg","一陣煙霧，$n失去了蹤影，$N的身影變的清晰可見。\n");
        set("no_auc",1);
        set("no_give",1);
        set("no_sell",1);
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
        this_object()->set("armor_prop/armor",10);
        this_object()->set("armor_prop/parry",5);
        this_object()->set("armor_prop/force",2);
        this_object()->set("armor_prop/dodge",5);
}
