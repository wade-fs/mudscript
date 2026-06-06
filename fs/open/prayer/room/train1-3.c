//open/prayer/room/train1-3

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "走廊");
  set ("long", @LONG

	    這裡是聖火教的大走廊，連接著聖火教的
	執法堂．傳功房．戒律廳等三大廳，以及聖火
	教的伙房．

LONG);
  set("exits", ([ /* sizeof() == 3 */
     "south" : "/open/prayer/room/train1-8",         //`練武場
	"west" : "/open/prayer/room/train1-4",		//`走廊
	"east" : "/open/prayer/room/train1",		//`練武場
]));

  setup();
}
 
