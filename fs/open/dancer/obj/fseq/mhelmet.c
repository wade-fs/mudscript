// 網聚獎品by cgy(22/10/00)
#include <armor.h>
#include <ansi.h>
inherit HEAD;
object me=this_player();
void create()
{
        set_name(HIG"咕哩咕哩貓防雷盔"NOR, ({"Konn_helmet", "helmet"}));
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("unit", "頂");
        set("value", 0);
        set("material", "steel");
        set("long","這是一件咕哩咕哩貓賜與的頭盔，擁有防雷的功\能。\n");
        set("armor_prop/armor", 14);
        set("no_auc",1);
        set("no_sell",1);
        set("no_give",1);
        set("no_put",1);
        set("no_drop",1);
        set("no_get",1);
        set("thunder",100);
        set("wear_msg", "$N將$n往頭上一戴，瞬時$n接受咕哩咕哩貓的保護，使雷擊不敢靠近。\n");
		set("remove_msg", "$N將$n脫掉，天上召來一道閃電, 把$N化為灰燼.。\n");
        }
        setup();
if(me->query("class")=="blademan")  this_object()->set("armor_prop/blade", 5);
if(me->query("class")=="fighter")   this_object()->set("armor_prop/unarmed",5);
if(me->query("class")=="swordsman") this_object()->set("armor_prop/sword",5);
if(me->query("class")=="scholar")   this_object()->set("armor_prop/stabber",5);
if(me->query("class")=="bandit")    this_object()->set("armor_prop/unarmed",5);
        this_object()->set("armor_prop/dodge", 5);
        this_object()->set("armor_prop/parry", 5);
        this_object()->set("armor_prop/move", 5);
        this_object()->set("armor_prop/force",3);
}
