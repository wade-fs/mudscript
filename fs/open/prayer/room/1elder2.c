//open/prayer/room/1elder2

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "傳功\長老房");
  set ("long", @LONG

	    這裡有一個小涼亭，在涼亭的四周，叢花
	盛開，鳥語陣陣，使人有一種想在涼亭內休息
	片刻的想法．

LONG);
  set("objects", ([ /* sizeof() == 1 */
  "/open/prayer/npc/trainee1" : 1,		//弟子
]));

  set("exits", ([ /* sizeof() ==  2*/
	"south" : "/open/prayer/room/1elder3",		//`長老房
	"west" : "/open/prayer/room/1elder5",		//`長老房
]));
 set("light_up", 1);

  setup();
}
 
