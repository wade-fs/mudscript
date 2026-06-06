#include <ansi.h>

inherit EQUIP;

void create()
{
        set_name("聖火教便服",({"communion-cloth","cloth"}) );
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
else    {
        set("meterial","silk");
        set("unit","件");
        set("value", 100);
        set("armor_type","cloth");
        set("armor_prop/armor", 2);
        set("long","
由西域布料簡單縫製而成.衣服的前後均繡有聖火教的聖火圖樣,
聖火教教眾的基本服裝。\n");
        }
         setup();
}





