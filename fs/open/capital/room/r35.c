// Room: /open/capital/room/r35.c
#include "/open/capital/capital.h"

inherit ROOM;

void create ()
{
  set ("short", "南城門下");
  set ("long", @LONG
往北就進入了城內，由於這裡是進出城的必經之路，常有馬匹的經
過，所以你還是不要在此逗留，以免招受無妄之災。
    這裡有禁衛軍四處的巡邏著，所以你還是不要在城內惹事的好。

LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/capital/npc/soldier" : 1,
]));

  set("outdoors", "/open/capital");

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"r34",
  "south" : __DIR__"D03",
]));

  set("gopath", "north");

  setup();
}
