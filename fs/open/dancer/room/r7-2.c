// Room: /open/dancer/room/r7-2.c :cgy
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short","村莊");
  set ("long", @LONG
這裡是鏡月島上唯一的村莊，西邊則是鏡月港，是你進出鏡月島
唯一的通道，你的東邊是村莊內的鬧區，在這裡你看到魚民們正辛苦
的修補著魚網，往北是這個村莊的魚池。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : "/open/dancer/room/port.c",
  "east" : "/open/dancer/room/r7-3.c",
]));

  set("light_up", 1);

  setup();
}
