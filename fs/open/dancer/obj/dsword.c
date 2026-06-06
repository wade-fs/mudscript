// sword.c : an example weapon
#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
	seteuid(getuid());
        set_name(HIR + "真‧連陽劍" + NOR,({"Sad sword"}));
	set_weight(9000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
       	set("long",
"靈劍連陽, 和靈刀夜千鳥, 靈筆麗玉蝶蘭並稱「開天三靈器」.劍身通體成虹, 劍鋒
更有隱隱泛出如火紅光, 銳利無比.\n");
		set("value",10000);
		set("no_steal",1);
		set("no_get",1);
		set("no_put",1);
		set("material", "crimsonsteel");
		set("rigidity",200);
 	set("wield_msg", "$N拔出" + HIR + "連陽劍" + NOR + ", 剎那間虹光閃耀, 不可逼視。\n");
	set("unwield_msg", "$N將右手內勁收回,$n消失無形 。\n");
        set("weapon_prop/sword",10);
	}
        
	init_sword(90);
	setup();
}
