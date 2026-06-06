#include "/open/open.h"
inherit ROOM;

void create ()
{
  set ("short", "交叉路口");
	set( "build", 12 );
  set ("long", @LONG

   穿過山道之後，你來到了一個廣大的山谷之中。前方似乎有一個建築物。
   東方傳來武器的碰撞聲，且殺聲連天，看來有人在那裡交手，
   西方傳來陣陣的花香，那裡似乎種了不少植物。

LONG);

  set("outdoors", "/open/main");
  set("exits", ([ /* sizeof() == 4 */
      "west" : __DIR__"outr1.c",
      "east" : __DIR__"outr6.c",
     "north" : __DIR__"doorm.c",
      "back" : __DIR__"firstrm.c",
]));
  setup();
}
