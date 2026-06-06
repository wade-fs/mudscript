#include <room.h>
#include "../../open.h"
inherit ROOM;

void create()
{
set("short","裝備存放處");
          set("long",@LONG
這裡就是葉秀殺所說的房間，有一個屍魂人在把守的滅神匕首
如果沒有兩把刷子，還是不要冒險的好。
LONG);
        set("exits", ([
"south":__DIR__"misrm1.c",
        ]) );
set("objects",([
    "/open/killer/npc/ghost1":1,
]));
set("light_up",1);
        setup();
}
