inherit EQUIP;
#include <ansi.h>

void create()
{
        set_name(HIW + "冰蠶寒絲袍" + NOR,({"cold cloth","cloth"}) );
        set_weight(3000);
        set("gender_only", "女性");
                if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long","一件雪白的袍服 ,被一股奇特的寒氣所籠罩 ,
據說是以萬年冰蠶絲縫製而成。\n");
        set("unit", "套");
        set("value",10000);
        set("material","cloth");
        set("armor_type", "cloth");
        set("armor_prop/armor",50 );
        set("armor_prop/poison",5 );
        set("wear_msg","$N穿上$n ,一股寒氣迅速的爬滿$N全身 ,看起來神秘而美麗 .\n");
        set("remove_msg","$N脫下了$n ,寒氣慢慢的消退 ,露出本來的面目 .\n");
        }
        setup();
}
