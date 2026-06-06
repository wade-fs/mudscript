//open/prayer/room/2elder4

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "執法長老房");
  set ("long", @LONG

	    前面有一個聖火弟子正在蹲馬步，看來又
	是做錯了什麼小事，而被執法長老處罰，真不
	敢想要是犯了大錯會如何．

LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/prayer/npc/trainee1" : 1,		//弟子
]));
  set("exits", ([ /* sizeof() ==  2*/
	"north" : "/open/prayer/room/2elder3",		//`長老房
	"east" : "/open/prayer/room/2elder7",		//`長老房
]));
  set("light_up", 1);

  setup();
}
 
