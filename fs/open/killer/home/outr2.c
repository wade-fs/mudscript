#include "/open/open.h"
inherit ROOM;

void create ()
{
  set ("short", "花園");
  set ("long", @LONG
   這裡種了不少奇花異草，看來有不少是藥草，但你卻不瞭解它的功用。
   隨風飄來的花香令你不禁沈醉其中，令你仔細地欣賞起花來。
   卻發現這裡，似乎有不少是屬於來自東洋的植物。。。。。。。
   不過，可得小心這裡可是殺手的總壇哦。。。。。

LONG);

  set("outdoors", "/open/main");
  set("exits", ([ /* sizeof() == 4 */
      "north" : __DIR__"outr3.c",
      "west"  : __DIR__"outr5.c",
      "east"  : __DIR__"outr1.c",
]));
  setup();
}
