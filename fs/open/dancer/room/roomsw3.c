// Room: /open/dancer/room/roomsw3.c :cgy
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short", HIG"夢月閣"NOR);
  set ("long", @LONG
這裡是夢月閣，也算是夜夢小築的重心之一，走到這裡你聞到了
陣陣香味，原來南邊是廚房傳來了陣陣的飯菜香，而北方則是藥房也
傳來草藥香味，奇怪的是這兩種味道混在一起不但不會排斥，反而溶
合成一股令人舒暢的芬芳。

LONG);

  set("exits", ([ /* sizeof() == 3 */
  "east" : "/open/dancer/room/roomsw2.c",
  "north" : "/open/dancer/room/roomsw3n.c",
  "south" : "/open/dancer/room/roomsw3s.c",

]));

  set("light_up", 1);

  setup();
}
