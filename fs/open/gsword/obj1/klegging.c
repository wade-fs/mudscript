
#include <ansi.h>
#include <armor.h>
inherit LEGGINGS;
object me=this_player();
void create()
{
        set_name(HIY + "劍聖護膝" + NOR,({"kensai legging","legging"}));
        set_weight(2000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("unit","件");
        set("value",0);
        set("material","blacksteel");
        set("long","不知名的材質.加上大劍師的手藝.此防具有著不知名的神力。\n");
        set("wear_msg",WHT + "穿上$n後，頓時防護增加。\n" + NOR);
        set("no_auc",1);
        set("no_sell",1);
        set("no_give",1);
        set("no_put",1);
        set("no_drop",1);
        set("no_get",1);
        }
        setup();
      this_object()->set("armor_prop/sword",8);
        this_object()->set("armor_prop/armor", 9);
        this_object()->set("armor_prop/move",5);
        this_object()->set("armor_prop/parry",6);
}
