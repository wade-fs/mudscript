//open/prayer/room/3elder7

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "戒律長老房");
  set ("long", @LONG

	    這裡有一個聖火弟子，正被戒律長老處罰
	在蹲馬步，看來這位聖火弟子又做錯事而被處
	罰．

LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/prayer/npc/trainee1" : 1,		//弟子
]));
  set("exits", ([ /* sizeof() ==  2*/
	"north" : "/open/prayer/room/3elder6",		//`長老房
	"east" : "/open/prayer/room/3elder4",		//`長老房
]));
  set("light_up", 1);

  setup();
}
 
