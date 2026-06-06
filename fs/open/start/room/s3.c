// Room: /open/start/room/s3.c

#include "../start.h"

inherit ROOM;

void create ()
{
  set ("short", "民舍");
  set ("long", @LONG
一個婦女正在忙著照顧強褓中的幼兒，但看著她臉上
似乎在擔心著什麼，正焦躁不安的喃喃自語。
    樸實的房舍，裡面擺著的大部份是耕種用的農具，這
婦女的丈夫應該是位農夫吧。

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "south" : "/open/start/room/s2",
]));

  set("light_up", 1);

  set("objects", ([ /* sizeof() == 2 */
  "/open/start/npc/baby" : 2,
  "/open/start/npc/woman" : 1,
]));

  setup();
}
