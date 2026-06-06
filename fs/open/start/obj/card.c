
#include <ansi.h>
#include <room.h>

inherit ITEM;

void create()
{
	set_name("聖誕卡",({"card"}));
	set_weight(100);
	if( clonep() )
		set_default_object(__FILE__);
	else {
	set("long","這是一張精美的聖誕卡。\n");
	set("unit","封");
        set("value",100);
	}
	setup();
}
