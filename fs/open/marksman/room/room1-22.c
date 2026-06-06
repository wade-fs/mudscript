#include <ansi.h>
#include <room.h>
inherit ROOM;
#include "marksman.h"
void create ()
{
  set ("short", "將軍府");
  set ("long", @LONG
這裡是李廣的住處，設計規劃巧奪天工的大觀園，雖後門亦不含
糊，光彩逼人。最豪華繁麗的建築物，只見崇閣巍峨，層樓高起，面
面琳宮合抱，迢迢複道縈紆，青松撫簷，玉蘭繞砌，金輝獸面，彩煥
璃頭。你可以看到一群全副武裝的武士守備著自己的位子，你似乎看
到一扇大門(open door)。
LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "enter" : (: look_door,     "enter" :),
]));
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"room1-21",
  "enter" : __DIR__"room1-23",
]));
  set("light_up", 1);
  set("objects", ([ /* sizeof() == 1 */
  "/open/marksman/npc/guard" : 2,
]));

  setup();
}
