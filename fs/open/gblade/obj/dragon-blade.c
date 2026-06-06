//blade.c : 大刀
#include <ansi.h>
#include <weapon.h>

inherit BLADE;

void create()
{
	set_name(HIW + "龍虎刀" + NOR,({"dragon-tiger blade","blade"}));
    set_weight(1000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long","金刀門開山祖師 -- 王蹇的佩刀 , 為金刀門至寶 \n");
		set("value",0);
		set("material", "steel");
		set("wield_msg", "$N從腰間抽出一把$n握在手中。\n");
		set("unwield_msg", "$N將手中的$n插入腰間的刀鞘。\n");
	}
	init_blade(100);
	setup();
}
int wield()
{
	return notify_fail("如此神器 , 你不配使用 , 物歸原主吧 !\n");
	return 1;
}
int query_autoload()
{
	return 1;
}
