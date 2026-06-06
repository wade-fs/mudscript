//open/prayer/room/kitchen5

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "廚房");
  set ("long", @LONG

	    你看到許許多多的瓶瓶罐罐，這些瓶瓶罐
	罐內，所裝的正是材．米．油．鹽．醬．醋．
	茶一類的東西．

LONG);
  set("exits", ([ /* sizeof() ==  2*/
	"south" : "/open/prayer/room/kicthen2",		//`廚房
	"east" : "/open/prayer/room/kicthen6",		//`廚房
]));
   set("light_up", 1);

  setup();
}
 
