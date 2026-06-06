#include <room.h>
#include "/open/open.h"
inherit ROOM;

void create ()
{
  set ("short", "走廊");
  set ("long", @LONG
這裡是雪蒼派的走廊,藉著兩旁忽暗忽明的火把,你可看到兩旁的牆
壁顯得有些斑駁!!看起來似乎有一段歷史了!你心中暗想：不知有多少
的英雄好漢曾經過此地,心中也不禁得意自己是其中之一呢...
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : "/open/snow/room/room2",
  "north" : "/open/snow/room/room13",
]));

  set("objects", ([ /* sizeof() == 1 */
  "/open/snow/npc/greeting_child" : 1,
]));

   set("light_up",1);

  set ("資源/液體", ([
       "種類" : "水",
       "名稱" : "清水",
       "止渴" : 30
  ]) );

  setup();
}
