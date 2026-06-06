#include <ansi.h>
inherit TRANS_ROOM;
void create()
{
    set("short","京城驛站");
    set("long",@LONG
這裡是京城的驛站, 因為京城是一個國家的心臟, 所以你可以看到
有很多人正在向老闆商討前往其他驛站的事宜。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : "/open/capital/room/r69",
]));

    setup();
}
// just for test
