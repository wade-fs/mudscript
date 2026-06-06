#include <ansi.h>

inherit EQUIP;

void create()
{
        set_name("虎之拳法衣",({"tiger-robe","robe"}) );
        set_weight(9000);
        if( clonep() )
                set_default_object(__FILE__);
else    {
        set("meterial","fur");
        set("unit","件");
        set("value", 6000);
        set("armor_type","cloth");
        set("wear_msg","$N穿上了$n之後,全身長出了如邪虎一般的毛髮,此時只見$N逐漸變成了邪惡的戰士\n");
        set("remove_msg","$N除下了$n之後,毛髮一片片地掉落下來,$N氣喘噓噓,看來極端的疲憊......\n");
        set("armor_prop/armor", 14);
        set("long","
由破邪洞窟中特有的邪虎虎皮所製成.衣服的前後均繡有聖火教的聖火圖樣,
是聖火教教中總管級以上的人物的象徵。\n");
        }
         setup();
}





