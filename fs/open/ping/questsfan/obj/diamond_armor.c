//虹晶雙翼鎧---2000.4.3 by dhk
#include <armor.h>
#include <ansi.h>
inherit EQUIP;


void create()
{
        set_name(HIC"虹晶雙翼鎧"NOR,({"diamond armor","armor"}) );
            set_weight(10000);
        set("no_sell",1);
        set("no_auc",1);
        set("no_drop",1); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long","
一件由北勝天使用〝虹晶〞特異礦石鑄成，表面散發著特異的紅光，是萬年的寶物。
\n");
        set("unit", "套");
        set("value",2000000);
        set("armor_type","cloth");
        set("material","crimsonsteel");
        set("armor_prop/armor",40);
        set("armor_prop/stabber",7);
        set("armor_prop/parry",10);
        set("armor_prop/attack",5);
set("wear_msg", HIY"$N穿上$n"HIY"，光芒一閃火紅色的異光已將$N的四周護住\n"NOR);
set("unequip_msg", HIY"$N將$n"HIY"卸了下來，四周的火光也慢慢離散開來了。\n"NOR);
        }
        setup();
}

