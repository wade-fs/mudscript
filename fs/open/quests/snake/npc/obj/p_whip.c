#include <weapon.h>
#include <ansi.h>
inherit WHIP;

void create()
{
        set_name(HIC + "毒蛇鞭" + NOR,({"poison whip","whip"}));
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit","條");
          	set("value",5000);
                set("material","iron");
                set("rigidity",70);
                set("long",
        "鞭子以長期浸泡於毒蛇液中的蛇皮編織而成，蛇鞭上還鑲上一些毒蛇牙
，毒蛇牙之劇毒以無毒性，不過卻會增加鞭子的傷害力。\n");
        }
        init_whip(80);
        setup();
}
