#include <room.h>

inherit ROOM;

void create()
{
           set("short","洞穴");
         set("long","一個普通的洞穴,錯蹤複雜的地形,是匪徒藏匿的好地點。\n");

        set("exits", ([
          "west":__DIR__"hole1",
        ]) );
        set("objects", ([ /* sizeof() == 3 */
        "/open/snow/npc/bandit" :3,
        ]));
        setup();
}
