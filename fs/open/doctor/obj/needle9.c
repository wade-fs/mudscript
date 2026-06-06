//  made bye adam..
#include <weapon.h>
#include <ansi.h>
inherit STABBER;
void create()
{
        object me=this_player();
        set_name(HIW"冰雪寒絲針"NOR, ({"cold needle", "needle"}) );
        set_weight(5000);
        if( clonep() )
         set_default_object(__FILE__);
        else
         {
          set("unit", "柄");
          set("long","這是華陀為人治病所用的針,相傳為千年寒鐵鑄煉而成。\n");
          set("value", 10000);
         }
        init_stabber(85);
        setup();
}


