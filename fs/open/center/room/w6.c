// Room: /u/l/lotus/girl/w6.c
#include "/open/open.h"

#include <room.h>

inherit ROOM;

void create ()
{
  set ("short", "井邊");
  set ("long", @LONG
一口井, 井旁有盆子, 可能是姑娘洗完衣服後留下的. 隱隱約約
聽到女孩子的哭聲, 不知道是哪個方向傳來的 .....
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"r9.c",
  "east" : __DIR__"w5",
]));
  set("outdoors", "/u/l");
  create_door("south", "破舊的木門", "north", DOOR_CLOSED);
  setup();
}
