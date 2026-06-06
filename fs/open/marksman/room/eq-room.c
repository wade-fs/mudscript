// Room: /open/marksman/room/eq-room.c
inherit ROOM;
#include <ansi.h>

void create ()
{
  set ("short", "射手EQ室");
	set( "build", 15 );
  set ("long", @LONG
這是一間師兄姐要給新加入門派的師弟妹EQ時，都會放在這裡
給後進的弟子們使用，當然後進的弟子可要勤練功才行，不姑負大
家的期許。

LONG);

  set("no_fight", 1);
  set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"room1-31",
]));
  set("light_up", 1);

  setup();
}
