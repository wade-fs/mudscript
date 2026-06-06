#include <ansi.h>
#include <armor.h>
inherit LEGGINGS;
void create()
{
        set_name(HIR"鴻都脛甲"NOR,({"large legging","legging"}));
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("unit","件");
        set("value",3000);
        set("material","steel");
        set("long","雷骨所作成的護腿甲。\n");
        set("armor_prop/armor", 8);
        set("armor_prop/parry",6);
        set("armor_prop/staff", 2);
        }
        setup();
}

