// Room: /open/shinyang/e_street.c
#include <room.h>

inherit ROOM;

void create ()
{
  set ("short", "東出口城門");
  set ("long", @LONG
由這裡進入襄陽城，前面站著數位衛兵，正在作嚴密的檢查，防止蒙古
大軍的入侵。
LONG);

  set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"9-5",
]));
  set("outdoors", "/open/shinyang");

  setup();

  create_door("west","東門大門","east",DOOR_OPENED);
}
