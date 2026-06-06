//虹晶神行靴---2000.4.3 by dhk
#include <ansi.h>
inherit EQUIP;


void create()
{
        set_name(WHT + "虹晶神行靴" + NOR,({"diamond boots","boots"}) );
            set_weight(1000);
        set("no_sell",1);
        set("no_auc",1);
        set("no_drop",1); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long","
一件由北勝天使用〝虹晶〞特異礦石鑄成，表面散發著特異的白光，是萬年的寶物。
\n");
        set("unit", "雙");
        set("value",910000);
        set("armor_type","boots");
        set("material","lether");
        set("armor_prop/armor",10);
        set("armor_prop/stabber",10);
        set("armor_prop/move",7);
        set("armor_prop/dodge",7);
set("wear_msg", HIC + "$N穿上$n" + HIC + "，周圍的白光漸漸起了一層雲霧，慢慢的把$N托了起來。\n" + NOR);
set("unequip_msg", HIC + "$N將$n" + HIC + "脫了下來，雲霧又化成白光$N緩緩的回到地面上。\n");
        }
        setup();
}

