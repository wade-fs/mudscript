//open/prayer/room/kitchen6

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "廚房");
  set ("long", @LONG

	    這裡就是聖火教的伙房了，四周傳來陣陣
	的香味，使你不自覺的肚子餓了起來，真想進
	到伙房裡面大快碩耳一下．

LONG);
  set("exits", ([ /* sizeof() ==  4*/
	"out" : "/open/prayer/room/train1-19",		//`走廊
	"east" : "/open/prayer/room/kicthen7",		//`廚房
	"south" : "/open/prayer/room/kicthen3",		//`廚房
	"west" : "/open/prayer/room/kicthen5",		//`廚房
]));
   set("light_up", 1);

  setup();
}
 
