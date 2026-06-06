//  made bye adam..
#include <weapon.h>
inherit STABBER;
void create()
{
        object me=this_player();
        set_name("鬼影針", ({"ghost needle", "needle"}) );
        set_weight(5000);
        if( clonep() )
         set_default_object(__FILE__);
        else
         {
          set("unit", "柄");
          set("long","相傳有一個名醫以此針自殺，魂魄附於針上。\n");
          set("value", 10000);
          set("material", "crimsonsteel");
         }
        init_stabber(40);
        setup();
}


