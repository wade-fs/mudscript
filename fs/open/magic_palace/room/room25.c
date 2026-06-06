inherit ROOM;
#include <ansi.h>
void create ()
{
set ("short","魔宮-七重冰獄");
set("long",@LONG
四周圍不復之前萬蟲鑽動的景象，因為此地散發著陣陣驚人寒氣，
連旁邊支撐宮殿的樑柱都是由結成萬年玄冰的冰柱構成，霎時一片藍色
的世界更將魔妖之氣增添了幾許死寂的氣氛。

LONG);
        set("no_auc", 1);
        set("no_transmit", 1);
        set("light_up",-1);
        set("exits", ([ /* sizeof() == 2 */
        "north"   : __DIR__"room26",
        "west"    : __DIR__"room24",
      ]));
        setup();
}
