inherit ROOM;
#include <ansi.h>

void create ()
{
        set ("short", "破舊茅屋");
        set ("long", @LONG 
這是一間久無人住的茅屋，裏頭的擺設只剩一張殘破的桌子和幾
張小椅子。如果你走累了還可以休息一下，由窗外遠遠望去可以看到
一片雪白的長白山，也不失為一個觀賞風景的好地方。
LONG);  
        set("exits", ([ /* sizeof() == 4 */
        "out" : __DIR__"mon02",
        "east" : __DIR__"mon60",
]));
        setup();
}

