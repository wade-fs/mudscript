inherit ROOM;
#include <ansi.h>

void create ()
{
        set ("short", "登山小道");
        set ("long", @LONG
小道上滿是黃土雜草，通往長白山上的路途仍舊崎嶇不平，愈往
上走愈覺得荒涼，愈往前走前途愈覺得茫茫然。
LONG);
        set("outdoors", "");
        set("exits", ([ /* sizeof() == 4 */
        "east"  : __DIR__"mon10",
        "west"  : __DIR__"mon07",
]));
        setup();
}

