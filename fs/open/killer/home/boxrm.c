#include <room.h>
#include "../../open.h"
inherit ROOM;

void create()
{
set("short","裝備存放處");
          set("long",@LONG
這裡是當年那位醫生犯過錯後，被監禁後存放裝備的地方。
那裡就放著一口平常的箱子。或許你可以去看看有什麼東西吧。
南方有一個小小的通道，或許那是唯一的出口吧。 
LONG);
        set("exits", ([
"south":__DIR__"outr4.c",
        ]) );
set("objects",([
    "/open/killer/obj/mbox":1,
]));
set("light_up",1);
        setup();
}
