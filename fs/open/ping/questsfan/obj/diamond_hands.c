//虹晶狂牙手套---2000.4.6 by dhk
inherit EQUIP;
#include <ansi.h>
void create()
{
        set_name(YEL + "虹晶狂牙手套" + NOR,({"diamond hands","hands"}));
        set_weight(7000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long","一件由北勝天使用〝虹晶〞特異礦石鑄成，表面散發著特異的黃光，是萬年的寶物。\n");
        set("unit","雙");
        set("no_sell",1);
        set("no_auc",1);
        set("no_drop",1);
        set("value",50000);
        set("material","diamond");
        set("armor_type","hands");
        set("armor_prop/armor", 25);
        set("armor_prop/attack",15);
        set("armor_prop/parry",10);
        set("armor_prop/stabber",10);
set("wear_msg", HIR + "$N穿上$n" + HIR + "，周圍的黃光漸漸凝聚成了一股獅形利牙的氣罩，緩緩的把$N的雙手包了起來。\n" + NOR);
set("unequip_msg", HIR + "$N將$n" + HIR + "脫了下來，氣罩又化成黃光緩緩的消逝在雙手上。\n");
        }
        setup();
}

