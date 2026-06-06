//天子 eq
inherit EQUIP;
#include <ansi.h>
void create()
{
        set_name(HIY"天帝"HIM"腰帶"NOR, ({ "king belt" ,"belt" }) );
        set_weight(300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","天帝賜給天子的腰帶。\n");
                set("unit", "件");
                set("value", 70000);
                set("material","leather");
                set("armor_type", "waist");
                set("armor_prop/armor",7);
                set("armor_prop/dodge",3);
                set("armor_prop/move",3);
                setup();

        }
}

