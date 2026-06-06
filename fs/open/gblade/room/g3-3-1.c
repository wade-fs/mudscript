#include <room.h>
inherit ROOM;

void create()
{
  set ("short", "臥房");
  set ("long", @LONG

這裡是王元霸的獨子王人傑的臥房，房中的陳設相當的簡單，角落一個石
頭盆景，另一邊擺著一架紗照屏，案上有個墨凍石鼎。榻上掛著水墨字帳
子，看起來又大方又素淨。


LONG);


  set("light_up", 1 );
  set("exits", ([ /* sizeof() == 1 */
  "south": __DIR__"g3-3",
]));
create_door("south", "雕花紫檀木門", "north", DOOR_CLOSED);

  setup();
}
