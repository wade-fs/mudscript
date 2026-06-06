inherit ROOM;
#include <ansi.h>
void create ()
{
set ("short","魔宮-七重冰獄");
set("long",@LONG
漸漸地，開始感覺空氣中有些許水氣飄蕩著，這應該是玄冰開始融化
所致，週遭空氣確實溫暖了許多，冰柱不再像之前般厚實堅硬，反而有點
像是鐘乳石般垂弔於上空，前方大門進去，應該就是魔宮內部中心了吧。

LONG);
        set("no_auc", 1);
        set("no_transmit", 1);
        set("light_up",-1);
        set("exits", ([ /* sizeof() == 2 */
        "enter"   : __DIR__"room29",
        "south"   : __DIR__"room27",
      ]));
        setup();
}
