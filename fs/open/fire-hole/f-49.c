#include <ansi.h>
#include "firestorm.c"
inherit ROOM;
void create ()
{
  set ("short", "火龍幻界邊緣");
  set ("long", @LONG
這裡是結界的邊緣, 這裡的魔法力就沒那麼的強烈了, 天候溫度跟平
常一樣, 但還未離開幻界的控制範圍, 這裡有一根直達雲際, 十分奇怪的
巨石, 這個也是拿來鞏固結界用的吧! 
LONG);

  set("outdoors", 1);
  set("no_transmit",1);
  set("no_chome",1);
  set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"f-47.c",
  "northeast" : __DIR__"f-48.c",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/fire-hole/npc/small-dragon.c" : 1,
]));

  setup();
}
