//u/r/rence/room/kitchen6

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "廚房");
  set ("long", @LONG

聖火教總壇的廚房. 

LONG);
  set("outdoors", "/u/r/rence/room");
  set("exits", ([ /* sizeof() ==  4*/
	"out" : "/u/r/rence/room/train1-19",		//`走廊
	"east" : "/u/r/rence/room/kitchen7",		//`廚房
	"south" : "/u/r/rence/room/kicthen2",		//`廚房
	"west" : "/u/r/rence/room/kitchen5",		//`廚房
]));

  setup();
}
 
