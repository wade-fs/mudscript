#include <room.h>
#include "/open/open.h"
inherit ROOM;

void create()
{
set("short","專用兵器室");
          set("long",@LONG
這是這是葉秀殺用來存放令他傷心的武器--殺意魔戒的地方。
西方有一個的通道，那是往兵器室的出口吧。 
LONG);
        set("exits", ([
"west":__DIR__"weaponrm.c",
        ]) );
set("objects",([
    "/open/killer/obj/kbox":1,
]));
set("light_up",1);
        setup();
}
