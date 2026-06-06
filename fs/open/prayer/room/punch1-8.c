//open/prayer/room/punch1-8

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "總壇大聽");
	set( "build", 12 );
  set ("long", @LONG

    看來前面就是聖火教軍師的大廳了，來這裡的教徒似乎並不多，可能
只在有傳達命令及軍師的嫡傳弟子才會經過，和副教主比較起來真的是天
讓之別...... 

LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/prayer/npc/vice-manager" : 1,		//弟子
]));
  set("exits", ([ /* sizeof() == 3 */
	"north" : "/open/prayer/room/punch1-4",		//`軍師
	"south" : "/open/prayer/room/punch1-11",	//`大廳
]));

  setup();
}
 
