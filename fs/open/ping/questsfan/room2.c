// Room: /u/d/dhk/questsfan/room2
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", "密道");
  set ("long", @LONG
四周黑不拉幾的你恍惚的走在不知有多長的通道中，
而且彌漫著一股死老鼠和蟲屍的惡臭，顯示此地已許久未
有人通行了。
LONG);

  set("no_transmit", 1);
  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"room3",
  "east" : __DIR__"room1",
]));

  setup();
}
