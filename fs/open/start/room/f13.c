// Room: /open/start/room/f13.c

#include "../start.h"

inherit ROOM;

void create ()
{
  set ("short", "草棚");
  set ("long", @LONG
這是農夫們搭建專門用來休息的草棚，棚內只有
一些簡陋的器具，幾張破舊的椅子，有個大水缸放在
旁邊。

LONG);

  set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"f8",
  "west" : __DIR__"f12",
  "south" : __DIR__"f18",
  "east" : __DIR__"f14",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/start/obj/beck" : 1,
]));
  set("light_up", 1);

  set ("資源/液體", ([
       "種類" : "水",
       "名稱" : "清水",
       "止渴" : 30
  ]) );

  setup();
}
