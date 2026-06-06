#include <ansi.h>
inherit ROOM;
void create ()
{
  set ("short", "草原");
  set ("long", @LONG
荒蕪的草地, 彷彿被死神所詛咒一般, 完全沒有任何生命
的跡象, 在草地的中央擺著一個骷髏(skeleton), 感覺上十分
的怪異。
LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "skeleton" : "一個奇異的骷髏, 完全看不出來是那一種生物的屍骨...\n",
]));
  set("outdoors", 1);
  set("objects", ([ /* sizeof() == 1 */
  "/open/mon/npc/wolf.c" : 6,
]));
  set("exits", ([ /* sizeof() == 1 */
  "west" : "/open/mon/mon57",
]));

  setup();
}
