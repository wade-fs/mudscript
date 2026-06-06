// green_whip.c
#include <weapon.h>

inherit WHIP;

void create()
{
        set_name("青龍鞭",({"green whip","whip"}));
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit","條");
                set("value",3000);
                set("material","ironsteel");
		set("rigidity",40);
                set("long",
        "這條鞭子成現碧綠色﹐握柄上有一隻龍頭。\n");
        }
        init_whip(60);
        setup();
}
