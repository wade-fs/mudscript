// made by onion
#include <weapon.h>
inherit STABBER;
void create()
{
        set_name("鋼鑄鐵筆",({"steel pen","pen"}));
        set_weight(20000);
        if( clonep() )
		set_default_object(__FILE__);
	else {
        set("long",".\n");
        set("unit","支");
        set("value", 1000);
        set("material","blacksteel");
	}
        init_stabber(40);
        set("wield_msg", "$N從腰間抽出流銀筆握住。\n");
        setup();
}
