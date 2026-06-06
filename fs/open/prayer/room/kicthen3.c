//open/prayer/room/kicthen3

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "廚房");
  set ("long", @LONG

	    在前面的桌子上，有著許多道美味可口的
	名菜，陣陣的香味，使你突然感覺肚子真有點
	餓了，真想偷偷吃它一下．

LONG);
  set("exits", ([ /* sizeof() ==  4*/
	"east" : "/open/prayer/room/kicthen4",		//`廚房
	"north" : "/open/prayer/room/kicthen6",		//`廚房
	"south" : "/open/prayer/room/kicthen1",		
	"west" : "/open/prayer/room/kicthen2",		
]));
   set("light_up", 1);

  setup();
}
 
