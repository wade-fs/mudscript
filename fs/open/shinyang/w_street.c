// Room: /open/shinyang/w_street.c
#include <room.h>

inherit ROOM;

void create ()
{
  set ("short", "西出口城門");
  set ("long", @LONG
由這裡進入襄陽城，前面站著數位衛兵，正在作嚴密的檢查，防止蒙古
大軍的入侵。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"1-5.c",
]));
  set("outdoors", "/open/shinyang");

  setup();

  create_door("east","西門大門","west",DOOR_OPENED);
}
