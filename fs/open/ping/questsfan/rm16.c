// Room: /u/d/dhk/questsfan/rm15
inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", "石林");
  set ("long", @LONG
這兒是一處寸草不生，堅石林立的地方。而且這兒淨是一些奇
形怪狀的巨石四處林立。但是卻又不是人造而成的，所以此地得名
〝石林〞也。在仔細看看這些巨石，有些質地鬆散、有些質地堅硬
各式各樣的石形都有，有一點像石頭大觀園一般。

LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/woman" : 2,
]));
  set("outdoors", "/u/d");
  set("exits", ([ /* sizeof() == 4 */
  "westup" : __DIR__"rm15",
  "eastup" : __DIR__"rm17",
  "eastdown" : __DIR__"rm9",
  "northup" : __DIR__"rm20",
]));

  setup();
}
