//open/prayer/room/train1-2

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "走廊");
  set ("long", @LONG

	    這裡有一個門，裡面正是聖火教的馬房，
	裡有許許多多的馬匹，南方是通往傳功房及戒
	律廳的路．

LONG);
  set("exits", ([ /* sizeof() == 3 */
	"south" : "/open/prayer/room/train1-5",		//`走廊
	"enter" : "/open/prayer/room/horse6",		//`馬房
	"west" : "/open/prayer/room/train1-1",		//`練武場
]));

  setup();
}
 
