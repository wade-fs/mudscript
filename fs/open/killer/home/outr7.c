#include "/open/open.h"
inherit ROOM;

void create ()
{
  set ("short", "道路");
  set ("long", @LONG
   這是往殺手練習場的通道，非常的筆直，路旁有許多的樹木。
   道路沿著總壇的圍牆，筆直地往練習場而去。
   看來快到練習場了，因為前方已經傳來陣陣的打殺聲。令你不禁手癢難耐。。

LONG);

  set("outdoors", "/open/main");
  set("exits", ([ /* sizeof() == 4 */
      "west" : __DIR__"outr6.c",
      "east" : __DIR__"outr8.c",
]));
  setup();
}
