// By onion
#include <weapon.h>
inherit SWORD;

void create()
{
	set_name("黑鐵劍", ({ "black sword","sword" }) );
	set_weight(10000);
	if( clonep() )
		set_default_object(__FILE__);
	else 
	{
	  set("long", "黑黝黝的一把鐵劍, 不知道是用什麼金屬製成的。\n");
	  set("unit", "把");
	  set("value", 8000);
	  set("material", "blacksteel");
	}
	init_sword(50);
	setup();
}
