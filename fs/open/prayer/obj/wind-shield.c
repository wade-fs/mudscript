#include <ansi.h>

inherit EQUIP;

void create()
{
        set_name("風之盾牌",({"wind-shield","shield"}) );
        set_weight(11500);
        if( clonep() )
                set_default_object(__FILE__);
else    {
        set("meterial","iron");
        set("unit","面");
        set("value", 2000);
        set("armor_type","shield");
        set("armor_prop/armor", 1);
        set("long","
由鐵打造而成的盾牌. 牌面刻有聖火教的聖火圖樣, 聖火教教眾的防具。\n");
        }
         setup();
}





