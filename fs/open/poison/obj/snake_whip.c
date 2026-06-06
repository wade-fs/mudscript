// green_whip.c
#include <weapon.h>

inherit WHIP;

void create()
{
	set_name("水蛇長鞭",({"snake whip","whip"}));
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit","條");
		set("value",1000);
		set("rigidity",30);
                set("material","ironsteel");
                set("long",
	"這是一條形如水蛇的長鞭。\n");
        }
	init_whip(25);
        setup();
}
