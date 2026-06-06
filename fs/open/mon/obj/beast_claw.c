#include <weapon.h>
#include <ansi.h>
inherit UNARMED;

void create()
{
 	        set_name(HIG + "靈芝仙爪" + NOR, ({ "beast claw" ,"claw" }) );
	        set_weight(1500);
       		if( clonep() )
                set_default_object(__FILE__);
        	else {
        	set("long", "靈芝仙獸幻化出的隨身武器，具有強大的殺傷力。\n");
                set("unit", "把");
                set("value", 300000);
                set("material", "steal");
		set("type", 1); 
       		}
		init_unarmed(75);
		setup();
}
