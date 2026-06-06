#include <armor.h>
#include <ansi.h>
inherit ARMBANDS;
void create()
{
        set_name(HIC"雪翎護臂"NOR,({"snow_armband","snow","armband"}));
        set_weight(4000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("unit","個");
        set("value",12000);
        set("long","太白山上雲石所製, 聽說戴上能讓人身體舒朗。\n");
        set("armor_prop/armor",8);
        set("armor_prop/parry",5);
                set("armor_prop/staff",4);
        }
        setup();
}
