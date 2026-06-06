#include <room.h>

 inherit ROOM;

void create ()
{
	set("short", "小徑");
	set("long", "以碎石鋪成的小路，平時很少有人經過，所以長了一地的青苔，由於離
劍派也有一段距離，所以平時也鮮少有人清掃。
");

  set("exits", ([ /* sizeof() == 4 */
  "northwest" : __DIR__"alley8",
  "southeast" : __DIR__"alley6",
  "south" : __DIR__"plain11",
  "east" : __DIR__"plain13",
]) );

  set("outdoors", "/open/gsword/room" );


  setup();
}
