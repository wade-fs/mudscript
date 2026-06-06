#include <weapon.h>
#include <ansi.h>

inherit BLADE;

void create()
{
        set_name(HIC"百戰寶刀"NOR,({"hundred-fight blade","blade"}) );
        set_weight(10000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
                set("long","一把特製的刀子 ,刀身發著奇異的藍芒 ,為項少龍的愛刀 .\n");
                set("value", 10000);
                set("material","steel");
                set("weapon_prop/blade", 6);
        }
        init_blade(80);

        set("wield_msg","$N將百戰寶刀由刀鞘抽出 ,頓時藍芒大盛 ,炫麗奪目 .\n");
        set("unwield_msg","$N將百戰寶刀收回刀鞘裡 ,奇異的藍芒慢慢的暗了下來 .\n");

        setup();
}
