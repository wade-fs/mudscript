// made by onion
#include <weapon.h>
inherit STABBER;
void create()
{
        set_name("精鋼筆",({"steel pen","pen"}) );
        set_weight(15000);
        if( clonep() )
		set_default_object(__FILE__);
	else {
        set("long","生鐵經歷鍛煉數天打造而成, 外表黝黑。\n");
        set("unit","支");
        set("value", 200);
        set("material","steel");
	}
        init_stabber(30);
        setup();
}
