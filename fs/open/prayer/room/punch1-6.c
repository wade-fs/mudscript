//open/prayer/room/punch1-6

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "軍師的房間");
  set ("long", @LONG

    你突然聞到一股書香味，仔細一看這房間書櫃的書，比聖火教軍師所
在的房間裡的書還要多上好幾倍，真的使人覺得軍師對文學的造詣，有著
種深不可測的感覺． 

LONG);

  set("light_up",1);
  set("no_fight",1);
  set("exits", ([ /* sizeof() == 1 */
	"out" : "/open/prayer/room/punch1-4",		//`軍師
]));

  setup();
}
 
