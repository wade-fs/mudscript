#include <ansi.h>
#include <weapon.h>

inherit WHIP;

void create()
{
        set_name(MAG+"幻"+YEL+"。"+MAG+"鞭"+NOR,({"unreal whip","whip"}));
        set_weight(3000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit","條");
          	set("value",30000);
                set("material","iron");
                set("rigidity",50);
                set("long",
        "這條鞭子只有鞭頭有握柄處，其鞭子身長，猶如一陣霧一般，無法看清楚其鞭頭在何處。\n");
        }
        init_whip(100);
        setup();
}
