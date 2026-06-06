#include <room.h>

inherit ROOM;

void create ()
{
  set ("short", "後山");
  set ("long", @LONG
這裡是雪蒼派的後山﹐在平時﹐很少人會到這來﹐在後
面似乎有一個洞穴﹐顯現出一股的神秘感﹐不知道裡面是
否暗藏什麼玄機呢 ?
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"room20",
  "enter" : __DIR__"hole",
]));
  set("light_up", 1);

  setup();
}
