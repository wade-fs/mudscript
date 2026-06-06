// Room: /u/f/fire/room/room1-27.c
inherit ROOM;
#include <ansi.h>
#include "marksman.h"
void create ()
{
  set ("short", "強者之道");
  set ("long", @LONG
這裡的四周的牆上張貼著數百幅畫像，有很大的有很小的，全部
都是多年前英雄圖像。從天花板垂下來的鐘擺，不時搖擺著發出滴答
滴答的聲音，在生命之泉的另一邊御房也是有掛一個。
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "south" : __DIR__"room1-25.c",
  "west" : __DIR__"room1-24",
  "north" : __DIR__"room1-29.c",
]));
  set("objects", ([ /* sizeof() == 1 */
C_NPC"/bowman1.c" : 2,
]));

  setup();
}
