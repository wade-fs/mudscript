//open/prayer/room/2elder5

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "執法長老房");
  set ("long", @LONG

	    在前面不遠處正有一位弟子在勤練武功，
	看他練得虎虎生風，看來執法長老的武功不會
	在傳功長老之下．

LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/prayer/npc/trainee1" : 1,		//弟子
]));
  set("exits", ([ /* sizeof() ==  2*/
	"south" : "/open/prayer/room/2elder6",		//`長老房
	"west" : "/open/prayer/room/2elder2",		//`長老房
]));
  set("light_up", 1);
  setup();
}
 
