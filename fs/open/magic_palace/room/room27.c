inherit ROOM;
#include <ansi.h>
void create ()
{
set ("short","魔宮-七重冰獄");
set("long",@LONG
周圍依舊持續著駭人的低溫，像是連火焰也將被凍結般，然而前方
隱隱泛著一片紫紅，甚至夾雜幾許青光，不過即使如此，亦無法令週遭
的寒氣有所減少。

LONG);
        set("no_auc", 1);
        set("no_transmit", 1);
        set("light_up",-1);
        set("exits", ([ /* sizeof() == 2 */
        "north"   : __DIR__"room28",
        "south"   : __DIR__"room26",
      ]));
        setup();
}
