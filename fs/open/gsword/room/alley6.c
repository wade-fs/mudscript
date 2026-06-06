#include <room.h>

 inherit ROOM;

void create ()
{
  set ("short", "小徑");
  set ("long", @LONG
以碎石鋪成的小路，平時很少有人經過，所以長了一地的青苔，由於離
劍派也有一段距離，所以平時也鮮少有人清掃。
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "northeast" : __DIR__"alley7",
  "south" : __DIR__"alley5",
  "east" : __DIR__"plain11",
]));
  set("outdoors", "/open/gsword/room");

  setup();
}
