#include <ansi.h>
inherit ITEM;

void create()
{
        set_name(HIG + "龍涎" + NOR, ({ "dragon-medal","medal" }) );
        set_weight(1000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long","散發陣陣靈氣的菱形紋章，從特殊的角度還可以看到龍的影像。\n");
                set("unit", "個");
                set("no_drop",1);
                set("no_sell",1);
        }
        setup();
}
