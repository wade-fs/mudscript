// Room: /open/badman/room/r5

#include "/open/open.h"

inherit ROOM;

void create ()
{
  set ("short", "武道館");
  set ("long", @LONG
這裡是惡人谷的武道館，所有的新進小嘍嘍都得在這裡接受訓
練。道館裡充滿著汗臭味，從四處零散的兵器和牆上掛著的一幅幅
戰術演練圖(figure)，你可以想見即使是區區一個山賊也得接受嚴
格的訓練才能在惡人谷中生存。

LONG);

  set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"b5",
  "south" : __DIR__"r12",
  "east" : __DIR__"b14",
]));
  set("item_desc", ([ /* sizeof() == 1 */
  "figure" : "你看到圖上寫著：
哪來啥戰術？圍毆就對了嘛，都哪個年代了還裝大俠？
					惡人谷先祖 oda 到此一遊...:b
",
]));
  set("objects", ([ /* sizeof() == 2 */
  "/open/badman/npc/lolo" : 3,
  "/open/badman/npc/teacher" : 1,
]));
  set("light_up", 1);

  setup();
}
