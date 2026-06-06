// Room: /open/center/room/tin4.c
#include "/open/open.h"

#include <room.h>

inherit ROOM;

void create ()
{
  set ("short", "樓梯口");
  set ("long", @LONG
和彩廳迥然不同的氣氛, 兩張雕花椅, 一幅山水的潑墨畫, 幾枝
寒梅, 安靜的綻放著傲然的氣質. 有一道樓梯通往二樓小姐的房間,
南面有一扇雕花木門.
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"tin3.c",
  "south" : __DIR__"r10.c",
  "up" : __DIR__"f2a.c",
//  "east" : __DIR__"gstore",
]));
  set("light_up", 1);
  set("objects", ([ /* sizeof() == 1 */
  "/open/center/npc/chang.c" : 1,
]));
  create_door("south", "雕花木門", "north", DOOR_CLOSED);
  setup();
}
