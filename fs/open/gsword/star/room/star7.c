// Room: /u/b/blue/room/star1.c
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "天樞樓");
  set ("long", @LONG
這是七星塔中的最後一層, 看了看四周, 心中深感不可思議, 
周圍盡是一堆堆的白骨, 白骨旁散落著一堆堆的武器及裝備, 你
正打算將功力凝聚到十成時, 樓主已經衝到你的身邊, 以下了重
手,令你此時不知所措。
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "up" : "/open/gsword/room/g5-1.c",
  "out" : __DIR__"room14.c",
]));
  set("light_up", 1);
  set("objects", ([ /* sizeof() == 1 */
  "/open/gsword/star/npc/star2.c" : 1,
]));

  setup();
}
