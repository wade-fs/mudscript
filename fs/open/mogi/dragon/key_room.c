#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "柳家寶庫");
  set ("long", @LONG
一個位於叢林後的山洞，不過在山洞的入口加有一個大門，若沒有
鑰匙是不能進去的，

LONG);

  set("no_transmit", 1);
  set("light", "1");
  set("exits", ([ /* sizeof() == 1 */
  "east" : __DIR__"goroom.c",
]));

  setup();
}

int valid_leave(object me, string dir)

{
        if(dir=="east"&&present("bluekey",me))
  {
  return 1;
}
  else return 0;
}
