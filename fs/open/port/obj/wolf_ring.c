// ph_hat.c
#include <armor.h>

inherit EQUIP;

void create()
{
	set_name("狼眼鑽戒",({"wolf ring","ring"}));
	set("long","純金鑽戒 , 鑲著稀有的狼眼石 , 閃閃發光 .\n");
	set_weight(700);
        set("armor_type","finger");
	set("light_up",-1);  
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "個");
		set("value",2000);
		set("material","gold");
	set("armor_prop/armor",5);
	set("light",-1);
        }
        setup();
}
