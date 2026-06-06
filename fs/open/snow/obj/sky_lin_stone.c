// Room: /open/snow/obj/sky_lin_stone
// 天靈石
#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIM + "天靈石" + NOR, ({ "sky_lin_stone"}) );
        set_weight(5000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("unit", "顆");
                set("long","這是傳說中有許\多的特異功\能的石頭.\n");
                set("value", 10000);
             }
      setup();
}

