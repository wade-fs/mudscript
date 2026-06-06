#include "/open/open.h"
inherit ROOM;

void create ()
{
  set ("short", "道路");
  set ("long", @LONG
   這是往殺手練習場的通道，非常的筆直，路旁有許多的樹木。
   道路沿著總壇的圍牆，筆直地往練習場而去。
   然而，你總覺得樹上似乎有人在看你。

LONG);

  set("outdoors", "/open/main");
  set("exits", ([ /* sizeof() == 4 */
      "west" : __DIR__"outr0.c",
      "east" : __DIR__"outr7.c",
]));
  setup();
}
