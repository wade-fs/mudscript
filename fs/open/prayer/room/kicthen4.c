//open/prayer/room/kitchen4

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "廚房");
  set ("long", @LONG

	    數十名的廚師正在為聖火教的教徒門，準
	備著美味可口的大餐，看來聖火教的教徒門又
	有口褔了．

LONG);
  set("exits", ([ /* sizeof() ==  2*/
	"north" : "/open/prayer/room/kicthen7",		//`廚房
	"west" : "/open/prayer/room/kicthen3",		//`廚房
]));
   set("light_up", 1);

  setup();
}
 
