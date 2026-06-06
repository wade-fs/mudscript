inherit ROOM;
#include <ansi.h>

void create ()
{
        set ("short", "平原小徑");
        set ("long", @LONG
小道過後，這是一塊比較平坦的地方，為崎嶇不平的路途帶來一
絲喘息的空間，前方不遠處有一個小平台，另一個方向則是往上頂的
路，平坦的道路旁，草木長的比較興盛，青翠的氣息揮去了原先的枯
黃。
LONG);
        set("outdoors", "");
        set("exits", ([ /* sizeof() == 4 */
        "east"       : __DIR__"mon15",
        "westup"     : __DIR__"mon16",
        "eastdown"   : __DIR__"mon13",
]));
        setup();
}

