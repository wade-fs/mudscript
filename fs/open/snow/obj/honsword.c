// short_sword.c

#include <weapon.h>

inherit SWORD;

void create()
{
           set_name("青虹劍",({"hon sword","sword"}));
	set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
          set("value",30000);
		set("material", "iron");
		set("long",
         "這是當年曹操賜給夏侯恩的一把寶劍。\n");
	}
           init_sword(75, SECONDARY);
	setup();
}
