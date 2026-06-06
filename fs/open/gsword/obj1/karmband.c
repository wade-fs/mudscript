#include <armor.h>
#include <ansi.h>
inherit ARMBANDS;
object me=this_player();
void create()
{
        set_name("劍聖手甲",({"kensai armband","armband"}) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("unit","件");
        set("value",0);
        set("long","不知名的材質製成..似乎專為劍客所做。\n");
set("wear_msg","$N穿上$n後，$n散發出淡但藍光。\n");
        set("material","steel");
        set("no_auc",1);
        set("no_sell",1);
        set("no_give",1);

        set("no_put",1);
        set("no_drop",1);
        set("no_get",1);
        }
        setup();
this_object()->set("armor_prop/sword",5);
this_object()->set("armor_prop/armor", 10);
this_object()->set("armor_prop/parry", 5);
this_object()->set("armor_prop/dodge", 5);
}
