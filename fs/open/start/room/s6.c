// Room: /open/start/room/s6.c

#include "../start.h"

inherit ROOM;

void create ()
{
  set ("short", "牛舍");
  set ("long", @LONG
牛一直是人類最忠實的伙伴，更是農夫們的好幫手，
吃苦耐勞的天性，使的農夫們能夠順利的耕種，也因此，
牛對於農夫們的重要性更甚於其他。
    這村子的家畜都是採集中飼養的方式，由專人照顧，
以免宵小的肆虐。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : "/open/start/room/s7",
  "north" : "/open/start/room/s4",
]));

  set("light_up", 1);

  set("objects", ([ /* sizeof() == 2 */
  "/open/start/npc/b_guard" : 1,
  "/open/start/npc/y_buffalo" : 2,
]));

  setup();
}
