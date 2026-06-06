// Room: /open/dancer/room/r8-2.c :cgy
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create ()
{
  set ("short","民房");
  set ("long", @LONG
這裡是一間普通的民房，你可以看到屋內的擺設極為簡陋，由此
可知鏡月島人民的生活並不富裕。

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : "/open/dancer/room/r8-3.c",

]));

  set("light_up", 1);

  setup();
}
