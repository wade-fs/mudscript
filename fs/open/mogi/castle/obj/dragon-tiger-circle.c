// 地邪鬼weapon exp 175萬
#include <weapon.h>
#include <ansi.h>

inherit UNARMED;

void create()
{
	seteuid(getuid());
        set_name("龍虎鋼環",({"dragon tiger circle","circle"}));
        set_weight(3500);
	if( clonep() )
		set_default_object(__FILE__);
	else {
                set("unit", "對");
         set("long","傳說中一對右大左小的奇形空手武器。\n");

                set("value",70000);
		set("material", "steel");
                set("ski_level",70);
                set("ski_type","unarmed");
         set("wield_msg", "裝備上$n,$N的攻擊力大幅提昇\n");
		set("unwield_msg", "$N放下$n,臉色緩和多了。\n");
	}
          init_unarmed(75);

	setup();
}
