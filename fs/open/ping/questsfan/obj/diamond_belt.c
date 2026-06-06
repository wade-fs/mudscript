//虹晶鈗鋮腰帶---2000.4.3 by dhk
#include <ansi.h>
inherit EQUIP;


void create()
{
        set_name(HIY"虹晶鈗鋮腰帶"NOR,({"diamond belt","belt"}) );
            set_weight(500);
        set("no_sell",1);
        set("no_auc",1);
        set("no_drop",1); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long","
一件由北勝天使用〝虹晶〞特異礦石鑄成，表面散發著特異的金光，是萬年的寶物。
\n");
        set("unit", "條");
        set("value",740000);
        set("armor_type","waist");
        set("material","lether");
        set("armor_prop/armor",10);
        set("armor_prop/dodge",9);
        set("armor_prop/move",9);
        set("armor_prop/stabber",10);
        set("wear_msg", ""HIR"$N穿上$n"HIR"，腰帶四周特有的異光瞬間消失。\n"NOR);
set("unequip_msg", ""HIR"$N將$n"HIR"解了下來，腰帶四周特有的異光再度明亮了起來。\n"NOR);
        }
        setup();
}

