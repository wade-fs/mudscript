#include <ansi.h>
inherit __DIR__"mixeq_stone.c"
;
void create()
{
	set_name("狂想原石一角", ({"original jiao", "original", "jiao" }));
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("stone_id", "jiao");
		set("long", "這是構成這世界最重要物質，然而呈現在你眼前的卻只是原石的一角。\n");
		set("unit", "粒");
		set("base_value", 1);
		set("base_unit", "粒");
		set("base_weight", 1);
		set("no_sell",1);
		set("no_sac",1);
	}
	set_amount(1);
	setup();
}
