// goldwhisk.c by Airke
// QC by Anmy (98/2/25)

#include <weapon.h>
inherit WHIP;

void create()
{
	set_name("黃金拂塵",({"Goldwhisk","goldwhisk","whisk"}) );
        set_weight(1500);
        set("value",5000);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "把");
	set("long","只有最高階段的道士才配擁有這把黃金拂塵。\n");	
		set("material","gold");
	set("wield_msg","$N從背後拔出$n握在手中。\n");
		set("unwield_msg","$N將手中的$n掛回背後。\n");
	}
	init_whip(70);
	setup();
}
