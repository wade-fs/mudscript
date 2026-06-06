//虹晶疾風護膝---2000.4.6 by dhk
inherit EQUIP;
#include <ansi.h>
void create()
{
        set_name(HIB + "虹晶疾風護膝" + NOR,({"diamond legging","legging"}));
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long","一件由北勝天使用〝虹晶〞特異礦石鑄成，表面散發著特異的藍光，是萬年的寶物。\n");
        set("unit","雙");
        set("value",20000);
        set("no_sell",1);
        set("no_auc",1);
        set("no_drop",1);
        set("material","diamond");
        set("armor_type","leggings");
        set("armor_prop/armor",10);
        set("armor_prop/attack",10);
        set("armor_prop/dodge",8);
        set("armor_prop/move",8);
set("wear_msg", HIR + "$N穿上$n" + HIR + "，周圍的藍光漸漸漩起了一陣強風，慢慢的把$N的雙腿包了起來。\n" + NOR);
set("unequip_msg", HIR + "$N將$n" + HIR + "脫了下來，強風又化成藍光緩緩的消逝在四周。\n");
        }
        setup();
}

