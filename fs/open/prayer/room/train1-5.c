//open/prayer/room/train1-5

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "走廊");
  set ("long", @LONG

	    在東邊有一扇門，這裡正是通往傳功房的
	唯一入口，北方可以通往馬房，而南方正是接
	往戒律廳的通路．

LONG);
  set("exits", ([ /* sizeof() == 3 */
	"south" : "/open/prayer/room/train1-10",		//`走廊
	"north" : "/open/prayer/room/train1-2",		//`走廊
	"enter" : "/open/prayer/room/1elder6",		//`長老房
]));

  setup();
}
 
