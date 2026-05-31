#include <ansi.h>
inherit __DIR__"mixeq_stone.c";

void create()
{
	set_name(HIC"狂想原石"NOR, ({"original stone", "original", "stone" }));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("stone_id", "stone");
		set("long", "這是構成這世界最重要物質，具有特殊的生命氣息。\n");
		set("unit", "顆");
		set("base_value", 1);
		set("base_unit", "顆");
		set("base_weight", 1);
		set("no_sell",1);
		set("no_sac",1);
	}
	set_amount(1);
	setup();
}
int value()  { return 1; }
