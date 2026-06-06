//open/prayer/room/1elder1

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "傳功\長老房");
  set ("long", @LONG

	    聖火教總舵三位護教長老之一的傳功長老所
	專屬的辦公處．傳功長正在那裡抄寫武學的心法
	...西邊是往走廊的方向．

LONG);
  set("objects", ([ /* sizeof() == 1 */
  "/open/prayer/npc/gonfu-elder" : 1,		//傳功\長老
]));
  set("exits", ([ /* sizeof() ==  1*/
	"west" : "/open/prayer/room/1elder3",		//`長老房
]));
 set("light_up", 1);
  set("valid_startroom", 2);

  setup();
}
