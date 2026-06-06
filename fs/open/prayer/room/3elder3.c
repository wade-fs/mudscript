//open/prayer/room/3elder3

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "戒律長老房");
  set ("long", @LONG

	    從東邊的大門進去就到了戒律廳了，在門
	口有二位弟子正奉命把守大門，看來弁律長老
	又在執行教規了．

LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/prayer/npc/trainee1" : 2,		//弟子
]));
  set("exits", ([ /* sizeof() ==  4*/
	"west" : "/open/prayer/room/3elder6",		//`長老房
	"north" : "/open/prayer/room/3elder2",		//`長老房
	"south" : "/open/prayer/room/3elder4",		//`長老房
	"east" : "/open/prayer/room/3elder1",		//`長老房
]));
  set("light_up", 1);

  setup();
}
 
