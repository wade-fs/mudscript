// fusword.c
#include <weapon.h>
#include <ansi.h>

inherit UNARMED;

void create()
{
        seteuid(getuid());
set_name(HIB"狂風戰爪"NOR,({"wind claws","claws"}));
set_weight(6000);

        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
set("long","這是一只由傳說中的『風岩石』所打造而成的武器。\n");

set("value",15000);
                set("material", "steel");
set("wield_msg","$N戴上$n後身體湧出了風的力量\n");
set("unwield_msg","$N將$n取下，風的力量隨之消逝。\n");
        }
init_unarmed(40);
        setup();
}
