#include <ansi.h>
inherit EQUIP;

void create()
{
	set_name("大紅彩帶",({"red cape","cape"}) );
	set_weight(3000);
	if ( clonep())
		set_default_object(__FILE__);
	else {
		set("unit","條");
		set("material","silk");
		set("value", 320);
		set("armor_type", "cape");
		set("armor_prop/armor", 9);
		set("armor_prop/whip", 5);
		set("long","
以西域運來之大紅絲綢織成的彩帶，揮舞時紅光耀眼，令人眼花撩亂。\n");

	}
	setup();

}
