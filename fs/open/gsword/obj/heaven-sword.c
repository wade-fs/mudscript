// sword.c : an example weapon
#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
	seteuid(getuid());
  set_name(HIB + "玄鐵劍" + NOR,({"heaven sword","sword"}));
	set_weight(13000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
set("long","一把黑黝黝的寶劍 ,似乎頗為沉重 .\n");
		set("value",10000);
		set("material", "steel");
	set("wield_msg", "$N從背後抽出$n,頓時全身充滿力量。\n");
	set("unwield_msg", "$N將手中$n收回。\n");
	}
    init_sword(60);
	setup();
}
