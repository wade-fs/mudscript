// fusword.c
#include <weapon.h>
#include <ansi.h>

inherit UNARMED;

void create()
{
        seteuid(getuid());
set_name(HIY + "黃金手鍊" + NOR,({"gold star","star"}));
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
set("long","這是一只以黃金打造而成的手環\n");

set("value",80000);
                set("material", "steel");
set("wield_msg","$N戴上$n後，手上發出不可思議的黃金光芒\n");
set("unwield_msg","$N你將$n卸了下來，光芒隨之消去。\n");
        }
init_unarmed(20);
        setup();
}
