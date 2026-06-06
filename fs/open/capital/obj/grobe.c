// K_cloth.c
#include <ansi.h>

inherit EQUIP;

void create()
{
        set_name(HIY "龍袍" NOR,({"king cloth","cloth"}) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
        set("long","這是天子所穿著的，上面繡著精緻的九紋龍圖騰。\n");
        set("unit","件");
        set("value",25000);
        set("material","cloth");
        set("armor_type","cloth");
	set("armor_prop/armor",18);
        set("armor_prop/dodge", 10);
        set("armor_prop/force",10);
        set("armor_prop/attack",30);
        }
        setup();
}
