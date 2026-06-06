
#include <weapon.h>
#include <ansi.h>

inherit BLADE;

void create()
{
	seteuid(getuid());
	set_name(HIC + "夜千鳥" + NOR,({"bird-blade","blade"}));
	set_weight(8000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long","
  靈刀夜千鳥，和靈劍連陽，靈筆麗玉蝶蘭並稱「開天三靈器」
  刀身泛冷光，寒意襲人，鋒利無比。
                           ");
      set("value",100000);
		set("material", "steel");
	}
	init_blade(80);

	setup();
}
