// fusword.c
#include <weapon.h>
#include <ansi.h>

inherit UNARMED;

void create()
{
        seteuid(getuid());
set_name(HIW"白金指環"NOR,({"platinum ring","ring"}));
set_weight(4000);

        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
set("long","這是從雪泉洞裡的岩壁所挖出來一個純白金礦質所提練出來的指環。\n");

                set("value",10000);
            set("material","gold");
set("wield_msg","$N戴起$n突然霎那間力量提升了不少!!");
set("armor_prop/unarmed",5);
        }
        init_unarmed(40);
        setup();
}
