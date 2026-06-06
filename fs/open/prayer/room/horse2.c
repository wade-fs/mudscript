//open/prayer/room/horse2

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "馬房");
  set ("long", @LONG

	    這間的駿馬是專屬副教主及軍師的，放眼
	看去都是一些聞名的駿馬，看來西域的良駒不
	亞於中原的馬匹．

LONG);
  set("outdoors", "/open/prayer/room");
  set("exits", ([ /* sizeof() ==  2*/
	"south" : "/open/prayer/room/horse3",		//`馬房
	"west" : "/open/prayer/room/horse5",		//`馬房
    //  "north" : "/open/killer/home/sdr1",
]));

  setup();
}
 
