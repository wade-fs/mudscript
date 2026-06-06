#include <ansi.h>

inherit ITEM;

void create()
{
	set_name("油燈",({"lamp"}) );
	set_weight(500);
	if ( clonep() )
		set_default_object(__FILE__);
	else{
		set("long","
一盞油燈，可為外出的旅客在黑暗中帶來光明。\n");
		set("unit","盞");
		set("burned","一盞燈油已耗盡的");
		set("light_up", 40);
		set("value",50);
		setup();
    	}
}
