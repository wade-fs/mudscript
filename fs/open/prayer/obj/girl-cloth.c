#include <ansi.h>

inherit EQUIP;

void create()
{
        set_name("聖女玉衣",({"girl-cloth","cloth"}) );
        set_weight(15000);
        if( clonep() )
                set_default_object(__FILE__);
else    {
        set("meterial","silk");
        set("unit","件");
        set("value", 20000);
        set("armor_type","cloth");
        set("wear_msg","$N穿上了$n之後,，全身覺得輕飄飄的，非常舒服。\n");
        set("armor_prop/armor", 18);
        set("armor_prop/dodge", 1);
        set("armor_prop/force", 1);
        set("long","
西域特殊的織料再用西域翠玉混合製成,在身上主要的經脈均做了防護。
可以有效防止經脈方式的攻擊。後面則繡有女媧娘娘的圖象。\n");
        }
         setup();
}





