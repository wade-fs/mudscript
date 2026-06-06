#include "/open/open.h"
inherit ROOM;

void create ()
{
  set ("short", "花園小路");
  set ("long", @LONG
   西方傳來陣陣的花香，那裡似乎種了不少植物。
   隨風飄來的花香令你不禁沈醉其中，欣賞起身邊的植物。
   不過欣賞歸欣賞，可別忘了這裡可是殺手的總壇哦。。。。。

LONG);

  set("outdoors", "/open/main");
  set("exits", ([ /* sizeof() == 4 */
      "west" : __DIR__"outr2.c",
      "east" : __DIR__"outr0.c",
]));
  setup();
}
