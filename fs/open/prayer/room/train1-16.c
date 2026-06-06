//open/prayer/room/train1-16

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
  "/open/prayer/npc/trainee1" : 1,		//弟子
]));
  set("outdoors", "/open/prayer/room");
  set("exits", ([ /* sizeof() == 2 */
	"north" : "/open/prayer/room/train1-11",		//`練武場
	"west" : "/open/prayer/room/train1-17",		//`練武場
]));

  setup();
}
 
