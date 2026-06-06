// sword.c : an example weapon
#include <ansi.h>
#include <weapon.h>

inherit STABBER;

void create()
{
    set_name("逆麟銀筆",({"scale pen","pen"}));
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("value",30000);
		set("material", "steel");
        set("wield_msg", "$N拿起$n, 身上散發著銀光!!\n");
        set("unwield_msg", "$N將手中的$n插入腰間。\n");
	}
    init_stabber(100);
	setup();
}
