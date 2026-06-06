// Room: /open/start/room/s7.c

#include "../start.h"

inherit ROOM;

void create ()
{
  set ("short", "養雞房");
	set( "build", 262 );
  set ("long", @LONG
咯咯咯！此起彼落的雞叫聲不絕於耳，這裡是村人們
飼養雞畜的地方，吵雜的聲音與外面安靜的村落形成截然
不同的兩個世界，這裡可能是凌雲村中最熱鬧的地方吧！

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : "/open/start/room/s6",
]));

  set("light_up", 1);

  set("objects", ([ /* sizeof() == 2 */
  "/open/start/npc/chicken" : 3,
  "/open/start/npc/hen" : 3,    //hen add by nako
]));

  setup();
}
