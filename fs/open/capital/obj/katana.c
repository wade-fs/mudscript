#include <weapon.h>
 inherit BLADE;
void create()
{
      set_name("武士刀",({"katana"}));
      
      set_weight(8000);
	
	if( clonep() )
		set_default_object(__FILE__);
	else {
        set("unit","把");
        set("long", "這是日本武士們慣用的武器，刀身略有弧度，刀鋒閃耀著青芒。\n") ;
	set("value", 400);
 	set("material","steel");	
        set("wield_msg","$N身形微彎，『唰』的一聲，從腰際間拔出一把武士刀。\n");
        set("unwield_msg","$N將武士刀收回刀鞘內。\n");
	}
  
   	init_blade(20);
	setup();
}
