//open/prayer/room/train1-17

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "總壇練武場");
  set ("long", @LONG

	    你一入目的是一個非常壯觀的畫面，因為
	你放眼過去在聖火教總壇的練武場，有著許多
	聖火弟子拼命的勤練武功．看來聖火教真有實
	力遂鹿中原武林． 

LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/prayer/npc/trainee3" : 3,
]));
  set("outdoors", "/open/prayer/room");
  set("exits", ([ /* sizeof() == 4 */
	"north" : "/open/prayer/room/train1-12",		//`練武場
	"out" : "/open/prayer/room/1-door2",		//`大門
	"east" : "/open/prayer/room/train1-16",		//`練武場
	"west" : "/open/prayer/room/train1-18",		//`練武場
]));

  setup();
}
 
