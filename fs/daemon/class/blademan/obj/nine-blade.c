//nine-blade.c
#include <weapon.h>
#include <ansi.h>


   inherit BLADE;
void create()
{
	seteuid(getuid());
set_name(HIB "九環寶刀" NOR,({"nine blade","blade"}));
	set_weight(13000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
   set("long","一把沉重的巨刀 ,刀背有九個刀環 .\n");
		set("value",10000);
		set("material", "steel");
	set("wield_msg", "$N從背後抽出$n,頓時全身充滿力量。\n");
	set("unwield_msg", "$N將手中$n收回。\n");
	}
    init_blade(60);

/*
	set("ski_type1", "blade");
	set("ski_level1", 75);
*/

	setup();
}
