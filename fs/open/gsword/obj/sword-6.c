// sword.c : an example weapon
#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
	seteuid(getuid());
            set_name("紫薇軟劍",({"purple sword","sword"}));
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
                set("long","仙劍七子中何雙雙的配劍，此軟劍頗適合何雙雙劍法的靈動\n");
		set("value",10000);
		set("material", "steel");
     set("wield_msg", "$N手中一抖，閃出了一把$n\n");
        set("unwield_msg", "$N將$n纏回腰間\n");
	}
	init_sword(60);
	setup();
}
