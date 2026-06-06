//sky-blade.c
//攜帶mob exp:175萬
#include <weapon.h>
#include <ansi.h>

inherit BLADE;

void create()
{
	seteuid(getuid());
	set_name("天邪刀",({"sky-blade","blade"}));
	set_weight(50000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long","一把看起來頗為邪惡的刀 .\n");
		set("value",50000);
		set("material", "steel");
                set("wield_msg", "拿著$n,$N覺的只想殺！殺！殺！\n");
		set("unwield_msg", "$N放下$n,臉色緩和多了。\n");
	}
	init_blade(60);

	setup();
}
