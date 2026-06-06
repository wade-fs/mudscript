//open/prayer/room/punch1-13

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "總壇大聽");
	set( "build", 42 );
  set ("long", @LONG

    你一進到聖火教總壇的大廳，突然有一種眼前一亮的感覺，原來正如
聖火之名，在這大廳的四周有著無數的火把，並在大廳的中心有一座聖火
座，難怪會如此光亮． 

LONG);
  set("exits", ([ /* sizeof() == 4 */
	"north" : "/open/prayer/room/punch1-10",	//`大廳
	"east" : "/open/prayer/room/punch1-12",		//`大廳
	"west" : "/open/prayer/room/punch1-14",		//`大廳
	"out" : "/open/prayer/room/1-door",	//`大門
]));
  set("light_up", 1);

  setup();
}
 
