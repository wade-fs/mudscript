//open/prayer/room/train1-6

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "練武場");
  set ("long", @LONG

	    在聖火教總壇的練武場，你看到許多聖火
	弟子拼命的勤練武功．看來聖火教的入主中原
	野心不小． 

LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/prayer/npc/trainee1" : 3,
]));
  set("outdoors", "/open/prayer/room");
  set("exits", ([ /* sizeof() == 2 */
	"south" : "/open/prayer/room/train1-11",		//練武場
	"west" : "/open/prayer/room/train1-7",		//`練武場
]));

  setup();
}
 
