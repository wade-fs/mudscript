
#include <ansi.h>
#include <armor.h>
inherit NECK;
object me=this_player();
void create()
{
     set_name(HIY"劍聖頸飾"NOR , ({"kensai neck","neck"}) );
     set_weight(1000);
     if ( clonep() )
              set_default_object(__FILE__);
     else {
            set("unit", "條");
            set("value", 0);
            set("material","gem");
            set("long","頸飾上附有一顆閃閃發亮的寶石..隱約透露出無比正氣。\n");
set("wear_msg",BLU"戴上$n後，$N的力量增加了些許\。\n"NOR);
        set("no_auc",1);
        set("no_sell",1);
        set("no_give",1);
        set("no_put",1);
        set("no_drop",1);
        set("no_get",1);
     }
            setup();
         this_object()->set("armor_prop/sword",5);
            this_object()->set("armor_prop/parry",4);
            this_object()->set("armor_prop/attack",5);
            this_object()->set("armor_prop/armor",9);
}
