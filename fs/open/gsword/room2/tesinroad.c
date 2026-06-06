//tesinroad
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIW"竹林小道"NOR);
        set("long", @LONG
通過天地破魔迷陣之後..你不經意的走到了一個佈滿竹林的鄉間小徑...
小徑似乎只能往前方前進...不過.在你後方..竟出現了一個神奇的傳送區
傳送區內閃耀著奇異的光芒...。
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
 "north":"/open/gsword/room2/tesinroad1.c",
 "back":"/open/gsword/room/g5-1.c",

]));
        set("light_up",1);
        set("no_transmit", 1);
        setup();
}
