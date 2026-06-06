//open/prayer/room/3elder1

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "戒律長老房");
  set ("long", @LONG

	    你眼前的那位正是，聖火教總舵三位護教長
	老之一的戒律長老，在這大廳的正中央，長老正
	在與一位男子把酒言歡哩．

LONG);

  set("objects", ([ /* sizeof() == 2 */
  "/open/prayer/npc/behavior-elder" : 1,		//戒律長老
  "/open/prayer/npc/man3" : 1,  
]));
  set("exits", ([ /* sizeof() ==  1*/
	"west" : "/open/prayer/room/3elder3",		//`長老房
]));
  set("light_up", 1);
  set("valid_startroom", 2);

  setup();
}
 
