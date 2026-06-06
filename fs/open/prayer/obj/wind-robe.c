#include <ansi.h>

inherit EQUIP;

void create()
{
        set_name("風之拳法衣",({"wind-robe","robe"}) );
        set_weight(8500);
        if( clonep() )
                set_default_object(__FILE__);
else    {
        set("meterial","silk");
        set("unit","件");
        set("value", 3000);
        set("armor_type","cloth");
        set("wear_msg","$N穿上了$n之後,風聲大作,四周的氣流漸漸聚在你的身上,形成了高壓的旋風,保護著$N!!\n");
        set("remove_msg","$N除下了$n之後,旋風逐漸地消散在空氣之中......\n");
        set("armor_prop/armor", 10);
        set("long","
由西域毛料所製成.衣服的前後均繡有聖火教的聖火圖樣,
聖火教教中習武之人均以此為裝。\n");
        }
         setup();
}





