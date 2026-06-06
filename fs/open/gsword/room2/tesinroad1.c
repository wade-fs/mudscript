//tesinroad
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIW + "竹林小道" + NOR);
        set("long", @LONG
通過天地破魔迷陣之後..你不經意的走到了一個佈滿竹林的鄉間小徑...
小徑似乎只能往前方前進...。
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
 "north":"/open/gsword/room2/tesinroad2.c",
 "south":"/open/gsword/room2/tesinroad.c",

]));
        set("light_up",1);
        set("no_transmit", 1);
        setup();
}
