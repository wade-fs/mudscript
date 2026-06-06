//open/prayer/room/2elder7

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "執法長老房");
  set ("long", @LONG

	    這裡就是執法長老的辦公室了，但是沒看
	到長老的人，看來又有人處犯了教規，而長老
	又在執法了．

LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/prayer/npc/trainee2" : 1,		//弟子
]));
  set("exits", ([ /* sizeof() ==  2*/
	"north" : "/open/prayer/room/2elder6",		//`長老房
	"west" : "/open/prayer/room/2elder4",		//`長老房
]));
  set("light_up", 1);

  setup();
}
 
