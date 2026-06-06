// Room: /u/l/lotus/girl/tree.c
#include "/open/open.h"
inherit ROOM;

void create ()
{
  set ("short", "前院");
  set ("long", @LONG
院子四周種滿了赭色茶花, 開得相當美. 南面的院子裡停了幾頂
轎子, 人來人往的, 相當熱鬧. 你老遠就看見大廳裡有一位豔光照人
的婦人, 她是如此的吸引你的目光.
LONG);

  set("light_up", 1);
  set("outdoors", "/u/l/lotus/girl");
  set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"tree2.c",
  "west" : __DIR__"guest.c",
  "east" : __DIR__"gstore",
]));

  setup();
}
