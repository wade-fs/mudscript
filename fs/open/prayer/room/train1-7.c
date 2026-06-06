//open/prayer/room/train1-7

#include <ansi.h>
inherit ROOM;

void create ()
{
 set ("short", "總壇練武場");
  set ("long", @LONG

	    你看到聖火弟子，在聖火教總壇的練武場
	上，拼命的勤練武功．面前這個弟子還練得有
	模有樣的．

LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/prayer/npc/trainee4" : 1,		//弟子
]));
  set("outdoors", "/open/prayer/room");
  set("exits", ([ /* sizeof() == 4 */
	"north" : "/open/prayer/room/train1",		//`練武場
	"south" : "/open/prayer/room/train1-12",		//`練武場
	"east" : "/open/prayer/room/train1-6",		//`練武場
	"west" : "/open/prayer/room/train1-8",		//`練武場
]));

  setup();
}
 
