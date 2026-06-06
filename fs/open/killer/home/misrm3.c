#include <room.h>
#include "/open/open.h"
inherit ROOM;

void create ()
{
  set("short","裝備室");
  set ("long", @LONG
這裡是黑牙聯出任務領取兵器的地方﹐在這裡可以看到不少的兵器
你可以看到一個裝備箱，只有葉秀殺同意才可以拿取。
 
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "west":__DIR__"masterm.c",
]));

  set("objects",([
/*        "/open/killer/npc/spy1": 1, */
        "/open/killer/obj/misbox2.c": 1,
]));
  setup();
}
