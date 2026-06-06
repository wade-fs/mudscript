//open/prayer/room/train1-11

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "練武場");
  set ("long", @LONG

	    眼前的聖火教總壇練武場上，你看到許多
	聖火弟子拼命的勤練武功．看來聖火教的早晚
	會進駐中原． 

LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/prayer/npc/trainee3" : 1,		//弟子
]));
  set("outdoors", "/open/prayer/room");
  set("exits", ([ /* sizeof() == 3 */
	"south" : "/open/prayer/room/train1-16",		//練武場
	"north" : "/open/prayer/room/train1-6",		//`練武場
	"west" : "/open/prayer/room/train1-12",		//`練武場
]));

  setup();
}
 
