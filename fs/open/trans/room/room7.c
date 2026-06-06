#include <ansi.h>
inherit TRANS_ROOM;
void create()
{
    set("short","長沙城驛站");
    set("long",@LONG
這裡是長沙城的驛站, 這裡四處的可以看到, 家家門口都掛著一副弓
箭, 原來這裡就是射手派的所在地。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : "/open/marksman/room/room1-13",
]));

    setup();
}

