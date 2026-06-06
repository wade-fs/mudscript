#include <weapon.h>
#include <ansi.h>

inherit UNARMED;

void create()
{
        seteuid(getuid());
set_name( "魔迴爪" ,({"daemon claw","claw"}));
set_weight(6000);

        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "把");
              set("wield_msg", "戴著$n,妖力充滿了$N全身.\n");
  set("unwield_msg", "$N將手中$n的血跡擦拭乾淨後 ,小心的收入護套中。\n");

set("value",10000);
                set("material", "steel");
        }
init_unarmed(40);
        setup();
}
