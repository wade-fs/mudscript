//虹晶識皇披風---2000.4.6 by dhk
#include <armor.h>
#include <ansi.h>
inherit EQUIP;

void create()
{
        set_name(""HIG"虹晶識皇披風"NOR"",({"diamond cloak","cloak"}) );
        set_weight(600);
        set("no_sell",1);
        set("no_auc",1);
        set("no_drop",1); 
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long","一件由北勝天使用〝虹晶〞特異礦石鑄成，表面散發著特異的綠光，是萬年的寶物。\n");
        set("unit", "件");
        set("value",50000);
        set("armor_type","cape");
        set("material","diamond");
        set("armor_prop/armor",7);
        set("armor_prop/stabber",7);
        set("armor_prop/parry",7);
set("wear_msg", HIR"$N穿上$n"HIR"，周圍的綠光忽明忽暗的，漸漸的將$N的氣質改變成皇者般的風範來。\n"NOR);
set("unequip_msg", HIR"$N將$n"HIR"脫了下來，瞬間四周發出一聲強烈的音爆。\n");
         }
        setup();
}

