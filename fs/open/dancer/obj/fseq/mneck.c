// 網聚獎品by cgy(22/10/00)
#include <ansi.h>
#include <armor.h>
inherit NECK;
object me=this_player();
void create()
{
     set_name(HIB + "清秀小嵐美眉項鍊" + NOR , ({"Anmy_gem","gem"}) );
     set_weight(1000);
     if ( clonep() )
              set_default_object(__FILE__);
     else {
            set("unit", "條");
            set("value", 0);
            set("material","steel");
            set("long","這是一條清秀小嵐美眉賜與的項鍊，散發出陣陣的光芒。\n");
set("wear_msg","$N戴起$n，四周馬上亮起光芒，$n開始發揮效用。 \n");
set("remove_msg","$N脫下了$n,身上的光芒也隨之黯淡下來。 \n");
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
            this_object()->set("armor_prop/parry",5);
            this_object()->set("armor_prop/force",3);
            this_object()->set("armor_prop/attack",5);
            this_object()->set("armor_prop/armor",9);
}

