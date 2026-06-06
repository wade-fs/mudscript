//open/prayer/room/3elder4

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "戒律長老房");
  set ("long", @LONG

	    這裡有一個小石桌，在石桌的四周，叢花
	盛開，鳥語花香，使人有一種想坐下來休息休
	息的想法．

LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/prayer/npc/trainee4" : 1,		//弟子
]));
  set("exits", ([ /* sizeof() ==  2*/
	"north" : "/open/prayer/room/3elder3",		//`長老房
	"west" : "/open/prayer/room/3elder7",		//`長老房
]));
  set("light_up", 1);

  setup();
}
 
