//open/prayer/room/3elder5

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "戒律長老房");
  set ("long", @LONG

	    你的正前方有兩個弟子正在相互套招，兩
	人練得大汗淋漓，但兩人似乎沒有要停下來休
	息的意思．

LONG);

  set("objects", ([ /* sizeof() == 2 */
  "/open/prayer/npc/trainee4" :  1,		//弟子
  "/open/prayer/npc/trainee1" :  1,		//弟子

]));
  set("exits", ([ /* sizeof() ==  2*/
	"south" : "/open/prayer/room/3elder6",		//`長老房
	"east" : "/open/prayer/room/3elder2",		//`長老房
]));
  set("light_up", 1);

  setup();
}
 
