#include <ansi.h>

inherit EQUIP;

void create()
{
        set_name("金剛拳法衣",({"emery-robe","robe"}) );
        set_weight(11000);
        if( clonep() )
                set_default_object(__FILE__);
else    {
        set("meterial","silk");
        set("unit","件");
        set("value", 10000);
        set("armor_type","cloth");
        set("wear_msg","$N穿上了$n之後,整個人就像是被獸魂附身一樣,肌肉暴漲,與怪獸無異....\n");
        set("remove_msg","$N除下了$n之後,全身經脈萎靡不振,面色蒼白......\n");
        set("armor_prop/armor", 17);
        set("armor_prop/dodge", 1);
        set("armor_prop/force", 1);
        set("long","
西域特殊的織料加上金剛砂所製成.衣服的前面繡有聖火教的聖火圖樣,
後面則是藍線所繡出來的金剛圖樣,平常都是穿在聖火教各支門的門主
級人物身上。\n");
        }
         setup();
}





