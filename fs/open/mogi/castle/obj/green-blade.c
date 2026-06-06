//green-blade.c
//攜帶mob exp180萬;kee 5000;dragon-blade 120;比master還強
#include <weapon.h>
#include <ansi.h>

inherit BLADE;

void create()
{
	seteuid(getuid());
	set_name(HIG + "綠波香露刀" + NOR,({"green-blade","blade"}));
	set_weight(50000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long","一把泛著淡淡綠光傳說中的寶刀。\n");
		set("value",100000);
		set("material", "steel");
                set("wield_msg", HIG + "拿著$n" + HIG + ",$N的手臂上泛起綠光\n" + NOR);
		set("unwield_msg", "$N放下$n" + HIG + ",手臂上的綠光也消失了。\n");
	}
	init_blade(65);

	setup();
}
