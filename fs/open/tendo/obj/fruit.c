
inherit ITEM;
#include <ansi.h>

void create()
{
        set_name("玉菩提",({"fruit"}));
       
        set("long",
                "一粒奇特的果實，外面裹著一層雪白的硬殼。\n");
        set("unit", "盒");
 
        set("value", 6000);
        set("base_weight", 50);
      
        setup();     
}
