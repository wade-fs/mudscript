// 網聚獎品by cgy(22/10/00)
#include <armor.h>
#include <ansi.h>
inherit WAIST;
object me=this_player();
void create()
{
    set_name(HIM + "小笨笨的蛋蛋腰帶" + NOR, ({"Acelan_belt","belt"}) );
    set_weight(1000);
     if ( clonep() )
              set_default_object(__FILE__);
     else {
            set("unit", "付");
            set("material", "steel");
            set("value", 0);
            set("long","繡工精細的腰帶，上面泛著蛋形狀的螢光圖案。\n");
        set("no_auc",1);
        set("no_sell",1);
        set("no_give",1);
        set("no_put",1);
        set("no_drop",1);
        set("no_get",1);
            set("wear_msg", "$N將$n往腰一綁，靈性好像增加不少。\n");
			set("wear_msg", "$N脫下了$n，彷彿張大了嘴巴, 僵立在一旁。\n");
     }
            setup();
if(me->query("class")=="blademan")  this_object()->set("armor_prop/blade", 5);
if(me->query("class")=="fighter")   this_object()->set("armor_prop/unarmed",5);
if(me->query("class")=="swordsman") this_object()->set("armor_prop/sword",5);
if(me->query("class")=="scholar")   this_object()->set("armor_prop/stabber",5);
if(me->query("class")=="bandit")    this_object()->set("armor_prop/unarmed",5);
            this_object()->set("armor_prop/dodge",5);
            this_object()->set("armor_prop/attack",5);
            this_object()->set("armor_prop/armor",9);
            this_object()->set("armor_prop/force",2);
}
