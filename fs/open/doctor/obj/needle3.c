//  made bye adam..
#include <weapon.h>
#include <ansi.h>
inherit STABBER;
void create()
{
        object me=this_player();
        set_name("銀針", ({"silver needle", "needle"}) );
        set_weight(5000);
        if( clonep() )
         set_default_object(__FILE__);
        else
         {
          set("unit", "柄");
          set("long","相傳為千年寒鐵鑄煉而成。\n");
          set("value", 5000);
          set("material", "crimsonsteel");
         }

init_stabber(30);
        setup();
}


