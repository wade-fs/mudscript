// sword.c : an example weapon
#include <weapon.h>
#include <ansi.h>

inherit SWORD;

void create()
{
	seteuid(getuid());
	set_name("流螢劍",({"yau sword","sword"}));
	set_weight(7000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
		set("long","仙劍派七把寶劍之一,由逍遙子分贈給七個愛徒,並將此劍
取名為逍遙寶劍,與李逍遙天性放蕩不拘,快意逍遙倒有幾
分合適.\n");
		set("value",10000);
		set("material", "steel");
                set("wield_msg", "拿著$n,$N覺的渾身充滿了力量.\n");
		set("unwield_msg", "$N將手中的$n插入腰間的劍鞘。\n");
	}
	init_sword(60);
	setup();
}
