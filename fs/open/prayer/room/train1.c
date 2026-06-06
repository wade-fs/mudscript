//open/prayer/room/train1

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "總壇練武場");
  set ("long", @LONG

	    這裡有一個聖火教頭，正在操領著弟子們
	子，看來聖火教教主有逐鹿中原，稱霸武林的
	念頭．

LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/prayer/npc/general-officer1" : 1,		
]));
  set("exits", ([ /* sizeof() == 4 */
	"north" : "/open/prayer/room/1-door",		//`大門
	"south" : "/open/prayer/room/train1-7",		//`練武場
	"east" : "/open/prayer/room/train1-1",		//`走廊
	"west" : "/open/prayer/room/train1-3",		//`走廊
]));

  setup();
}
 
