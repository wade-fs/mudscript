//open/prayer/room/punch1-10

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "總壇大聽");
	set( "build", 33 );
  set ("long", @LONG

    你站在象徵聖火教的聖火座面前，突然產生一莫名的尊敬，因為這座
聖火座有九尺之高，而且本身是由一塊花岡石天然成形的，沒有絲毫加工
過，似乎是老天給聖火教的賀禮． 

LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/prayer/npc/general-officer" : 1,		//弟子
]));
  set("exits", ([ /* sizeof() == 4 */
	"north" : "/open/prayer/room/punch1-2",		//`大廳
	"south" : "/open/prayer/room/punch1-13",	//`大廳
	"west" : "/open/prayer/room/punch1-11",		//`大廳
	"east" : "/open/prayer/room/punch1-9",		//`大廳

]));
  set("light_up", 1);
  setup();
}
 
