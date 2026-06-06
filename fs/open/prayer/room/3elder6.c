//open/prayer/room/3elder6

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "戒律長老房");
  set ("long", @LONG

	    你己來到了戒律大廳了，往南走正是戒律
	長老的辦公室，而北邊及西邊都有聖火弟子在
	練武的聲音，看來戒律長老的功夫應該不錯．

LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/prayer/npc/trainee4" :1 ,		//弟子
]));
  set("exits", ([ /* sizeof() ==  4*/
	"out" : "/open/prayer/room/train1-15",		//`走廊
	"north" : "/open/prayer/room/3elder5",		//`長老房
	"south" : "/open/prayer/room/3elder7",		//`長老房
	"east" : "/open/prayer/room/3elder3",		//`長老房
]));
  set("light_up", 1);

  setup();
}
 
