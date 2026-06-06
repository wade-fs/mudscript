//open/prayer/room/1elder7

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "傳功\長老房");
  set ("long", @LONG

	    這裡有一個聖火弟子正在蹲馬步，其樣子
	看來不是在練功的感覺，莫非是做錯什麼事而
	被處罰．

LONG);
  set("objects", ([ /* sizeof() == 1 */
  "/open/prayer/npc/trainee2" : 1,		//弟子
]));
  set("exits", ([ /* sizeof() ==  2*/
	"north" : "/open/prayer/room/1elder6",		//`長老房
	"east" : "/open/prayer/room/1elder4",		//`長老房
]));
 set("light_up", 1);

  setup();
}
 
