// 鑽石 by ACKY

#include <ansi.h>
inherit MONEY;

void create()
{
	set_name(HIW + "鑽石" + NOR, ({"diamond","diamond_money"}));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("money_id", "diamond");
		set("long", "商人遠從亞立安帝國帶來的耀眼鋼鑽，據說一粒價值一萬兩黃金哩。\n");
		set("unit", "袋");
		set("base_value", 100000000); //價值一萬兩黃金
		set("base_unit", "粒");
		set("base_weight", 10);
	}
	set_amount(1);
	setup();
}
