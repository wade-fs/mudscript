//open/prayer/room/1elder6

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "傳功\長老房");
  set ("long", @LONG

	    眼前正有一位弟子，正在練習傳功長老所
	教導的武術，只見這位弟子汗流夾背，想必是
	練習有一段時間了．

LONG);
  set("objects", ([ /* sizeof() == 1 */
  "/open/prayer/npc/trainee4" : 1,		//弟子
]));
  set("exits", ([ /* sizeof() ==  4*/
	"out" : "/open/prayer/room/train1-5",		//`走廊
	"north" : "/open/prayer/room/1elder5",		//`長老房
	"south" : "/open/prayer/room/1elder7",		//`長老房
	"east" : "/open/prayer/room/1elder3",		//`長老房
]));
 set("light_up", 1);

  setup();
}
 
