//open/prayer/room/punch1-3 

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "聖火教總壇");
	set( "build", 36 );
  set ("long", @LONG

    一進到這，你感到奇怪，為何這個房間比所有總壇的房間來得小，你
定神一看，因為一個身長八尺的巨漢正站在廳堂上，傾聽教徒們的回報，
而正在一一處理著，而這也是聖火教副教主的房間，那巨漢莫非是聖火教
的副教主了？

LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/prayer/npc/warrior" : 1,        	//副幫主
]));
  set("exits", ([ /* sizeof() == 3 */
	"enter" : "/open/prayer/room/punch1-5",		//副幫主的房間
	"south" : "/open/prayer/room/punch1-7",		//大聽
	"west" : "/open/prayer/room/punch1",		//幫主
]));
  set("light_up", 1);

  setup();
}
 
