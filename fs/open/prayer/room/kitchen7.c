//u/r/rence/room/kitchen7

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "廚房");
  set ("long", @LONG

聖火教總壇的廚房. 

LONG);
  set("outdoors", "/u/r/rence/room");
  set("exits", ([ /* sizeof() ==  2*/
	"south" : "/u/r/rence/room/kicthen4",		//`廚房
	"west" : "/u/r/rence/room/kitchen6",		//`廚房
]));

  setup();
}
 
