#include <room.h>
#include "/open/open.h"
inherit ROOM;

void create()
{
set("short","試煉之間");
          set("long",@LONG
在你眼前的就是傳說中的超上級殺手--柴榮，據說他以並沒有真正脫離黑牙聯。
而是秘密的在此訓練，黑牙聯的超級殺手，據說柴榮的必殺密技----魔氣殺，
都是黑牙聯之中最上層的終極奧義，一般弟子根本不能學。
而據說閻影匕首的試煉，也是由此開始。。。。。

LONG);
        set("exits", ([
"up":__DIR__"rbd.c",
        ]) );
set("objects",([
    "/open/killer/npc/rou":1,
]));
set("light_up",1);
        setup();
}
