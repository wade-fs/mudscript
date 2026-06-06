//open/prayer/room/train1-4

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "走廊");
  set ("long", @LONG

	    前方正有一坐拱門，拱門的後方就是聖火
	教的御花園，花園裡面種著許多的奇花異木，
	聽說也有珍禽猛獸的出沒．

LONG);
  set("exits", ([ /* sizeof() == 3 */
	"south" : "/open/prayer/room/train1-9",		//`走廊
	"west" : "/open/prayer/room/garden1",		//`花園
	"east" : "/open/prayer/room/train1-3",		//`走廊
]));
	
  setup();
}
 
