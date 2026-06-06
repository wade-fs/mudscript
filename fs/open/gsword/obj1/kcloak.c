
#include <ansi.h>
#include <armor.h>
inherit CAPE;
object me=this_player();
void create()
{
        set_name(HIY"劍聖披肩"NOR,({"kensai cloak","cloak"}));
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "件");
        set("value",0);
        set("material","linen");
        set("long","與一般披肩不同.為使劍客擁有更強的行動力..故大龍鐵心在製做時採用輕薄設計使劍聖用起來得心順手。\n");
set("wear_msg","穿上$n，$N的行動越來越順暢。\n");
        set("no_auc",1);
        set("no_give",1);
        set("no_sell",1);
        set("no_put",1);
        set("no_drop",1);
        set("no_get",1);
        }
        setup();
        this_object()->set("armor_prop/sword",5);
        this_object()->set("armor_prop/armor",5);
        this_object()->set("armor_prop/parry",5);
        this_object()->set("armor_prop/dodge",5);
        this_object()->set("armor_prop/move",5);

}
