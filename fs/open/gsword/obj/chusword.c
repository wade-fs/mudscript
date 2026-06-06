// sword.c : an example weapon

#include <weapon.h>

inherit SWORD;

void create()
{
        set_name("竹劍", ({ "chu sword","sword" }) );
        set_weight(3000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
                set("long","這是一把練習用的細竹劍,它似乎沒有殺傷力.\n");
                set("value", 3);
                set("material","wood");
	}
        init_sword(1);

// These properties are optional, if you don't set them, it will use the
// default values.

	set("wield_msg", "$N「唰」地一聲抽出一把$n握在手中。\n");
        set("unwield_msg", "$N將手中的$n插入腰間的劍鞘。\n");

// The setup() is required.

	setup();
}
