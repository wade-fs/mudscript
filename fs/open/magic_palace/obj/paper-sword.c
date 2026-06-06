// sword.c : an example weapon

#include <weapon.h>

inherit SWORD;

void create()
{
        set_name("紙劍", ({ "papeer sword","sword" }) );
        set_weight(5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("sharp",9);
		set("e-weapon",1);
                set("no_steal",1);
                set("no_give",1);
                set("no_get",1);
                set("no_auc",1);
		set("unit", "把");
                set("long", "這是一柄用碎紙片連結而成的劍，看樣子毫無殺傷力。\n");
                set("value", 50);
	        set("material","crimsonsteel");
	}
        init_sword(5);
	set("wield_msg", "$N撕破一張紙，手指頭在天空畫了幾下，將碎紙串成了一柄劍。\n");
        set("unwield_msg", "$N將紙劍撕碎放進上衣裡。\n");
	setup();
}
