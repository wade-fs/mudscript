//open/prayer/room/2elder3

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "執法長老房");
  set ("long", @LONG

	    從西邊的大門進去就到了執法長老的大廳
	了，在門口有二位弟子正奉命把守大門，看來
	執法廳又在執行教規了．

LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/prayer/npc/trainee3" :2,		//弟子
]));
  set("exits", ([ /* sizeof() ==  4*/
	"east" : "/open/prayer/room/2elder6",		//`長老房
	"north" : "/open/prayer/room/2elder2",		//`長老房
	"south" : "/open/prayer/room/2elder4",		//`長老房
	"west" : "/open/prayer/room/2elder1",		//`長老房
]));
  set("light_up", 1);
  setup();
}
 
