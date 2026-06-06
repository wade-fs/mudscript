// yensword.c

#include <weapon.h>

inherit SWORD;

void create()
{
	set_name("穿腸劍", ({ "yen sword", "sword" }) );
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("value", 3600);
		set("material", "steel");
		set("long",
			"這就是江湖人稱「穿腸劍」司馬煙所使用的劍，死在這把劍下的人多的不計其數。\n");
	}
	init_sword(60);
	setup();
}
