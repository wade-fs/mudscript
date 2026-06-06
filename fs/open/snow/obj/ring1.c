// fusword.c
#include <weapon.h>
#include <ansi.h>

inherit UNARMED;

void create()
{
        seteuid(getuid());
set_name(HIR"雪熔爪"NOR,({"snowfire ring","ring"}));
set_weight(4000);

        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
set("long","這像武器是在雪蒼後山洞所發掘的，爪如其名..一半是千年不溶之雪作的,一半是用百年不凍之熔漿所特製的。\n");

                set("value",10000);
                set("material", "gem");
set("wield_msg","$N拿起$n慢慢的感覺到一陣寒意和酷熱,$N覺的全身力氣一湧而上。");
set("armor_prop/unarmed",3);
        }
        init_unarmed(35);
        setup();
}
