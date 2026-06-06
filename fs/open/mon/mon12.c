inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short", "環山小徑");
  set ("long", @LONG
一條環著長白山的小徑，往山頂的路途還遙遠，兩旁的草木愈來
愈少，青綠的顏色也慢慢轉變枯黃，愈往上走，空氣中所蘊含的氣息
愈來愈冷，而大地中似乎又隱隱透著幾許的霧氣。
LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"obj/bembem.c" : 1,
]));
  set("exits", ([ /* sizeof() == 2 */
  "northup" : __DIR__"mon13",
  "southdown" : __DIR__"mon11",
]));

  setup();
}
