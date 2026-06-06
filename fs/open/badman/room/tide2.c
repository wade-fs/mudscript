#include "/open/open.h"
#include <room.h>


inherit ROOM;

void create()
{
        set("short", "小巷道");
        set("long", @LONG
小巷道到此已是死路，一堵高牆擋住了往南的出路。而此處則　　　　
是充斥著股濃烈的餿水味；大概是兩旁的住戶經由窗戶，直接將餿
水倒至此處之故吧。而昏暗中，似乎有個人橫臥在地，也不知是死
是活。

LONG
        );
        set("outdoors",1);

        set("exits", ([ /* sizeof() == 1 */
                "north" : __DIR__"tide1",
        ]) );

        set("objects",([
            BAD_NPC"drinker" : 1,
        ]));

        setup();
}
