#include <ansi.h>

inherit EQUIP;

void create()
{
        set_name("乾坤戰鬥服",({"boris-cloth","cloth"}) );
        set_weight(15000);
        if( clonep() )
                set_default_object(__FILE__);
else    {
        set("meterial","silk");
        set("unit","件");
        set("value", 200000);
        set("armor_type","cloth");
        set("wear_msg","$N穿上了$n之後,只見卦象如虹,全身散發出雄渾的鬥氣!!\n");
        set("remove_msg","$N將$n脫下之後,雄渾的鬥氣慢慢地消散了!!\n");
        set("armor_prop/armor", 20);
        set("armor_prop/dodge", 5);
        set("armor_prop/unarmed", 15);
        set("armor_prop/stick", 15);
        set("armor_prop/force", 5);
        set("long","
西域特殊的織料再佐以血麒麟的鱗皮混合製成,前面繡有聖火教的聖火
圖樣,後面則是女媧娘娘的圖象. 刀槍不入,水火不侵.是聖火教歷代教主
的嫡傳寶衣。\n");
        }
         setup();
}





