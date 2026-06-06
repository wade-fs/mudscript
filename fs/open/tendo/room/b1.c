#include <ansi.h>
#include <room.h>

inherit ROOM;
void create()
{
set("short","崑崙仙境");
set("long", @LONG
這裡是傳說中的崑崙仙境，只見四周雲煙裊裊，桃枝紅花，其景
有如人間仙境一般，抬頭仰望天際日月同昇，群星爭豔，隱約還可聽
到幾聲高昂驚人的啼叫聲，前方有條通道，應該是通往靈池的。

LONG);

        set("light", 1);
        set("light_up", 1);
        set("no_fanset", 1);
        set("no_chome", 1);
        set("exits", ([ /* sizeof() == 2 */
        "north" : "/open/tendo/room/b2",
        "back" : "/open/tendo/room/start",
        ]));

        set("objects",([
        "/daemon/class/taoist/necromancy/npc/hawk1" : 1,
        ]));
        setup();

}
