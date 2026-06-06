//open/prayer/room/1elder3

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "傳功長老房");
  set ("long", @LONG

	    往東走就到了傳功長老的大廳了，在門口
	正有一位弟子在勤練武功，看他練得虎虎生風
	，想必是傳功長老所傳授的弟子了．

LONG);
  set("objects", ([ /* sizeof() == 1 */
  "/open/prayer/npc/trainee3" : 1,		//弟子
]));
  set("exits", ([ /* sizeof() ==  4*/
	"west" : "/open/prayer/room/1elder6",		//`長老房
	"north" : "/open/prayer/room/1elder2",		//`長老房
	"south" : "/open/prayer/room/1elder4",		//`長老房
	"east" : "/open/prayer/room/1elder1",		//`長老房
]));
 set("light_up", 1);

  setup();
}
 
