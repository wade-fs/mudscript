#include <ansi.h>

inherit EQUIP;

void create()
{
        set_name("龍之拳法衣",({"dragon-robe","robe"}) );
        set_weight(13000);
        if( clonep() )
                set_default_object(__FILE__);
else    {
        set("meterial","silk");
        set("unit","件");
        set("value", 60000);
        set("wear_msg","$N穿上了$n之後,呼的一聲,整個人如同是黃甲金龍般,睦地暴出金光!!
            只覺得似乎承繼了金龍兇猛的力量!!\n");
        set("remove_msg","$N除下了$n之後,那金光便逐漸地消失在拳法衣的四周......\n");
        set("armor_type","cloth");
        set("armor_prop/armor", 18);
        set("armor_prop/dodge", -3);
        set("armor_prop/unarmed", 10);
        set("armor_prop/stick", 10);
        set("armor_prop/force", 3);
        set("long","
西域特殊的織料與黃甲金龍的龍皮混織而成,衣服的前面繡有聖火教的
聖火圖樣,後面則是紅線所繡出來的龍騰,是象徵聖火教長老們高高在上
的權勢。\n");
        }
         setup();
}





