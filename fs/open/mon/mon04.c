inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short", "長白山下");
  set ("long", @LONG
經過一番長途拔涉，你終於走到這極具盛名的「長白山」了，抬
頭望望間前的長白山，山頂上白靄靄的一片，景色之壯觀，令你囋嘆
不已。環繞在長白山四邊的輕煙，更為雪白的山頭更添一股美感。
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"obj/bembembem.c" : 1,
]));
  set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"mon03",
//  "westdown" : "/open/snow/room/room3.c",
  "north" : __DIR__"mon05",
]));

  setup();
}

