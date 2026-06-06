//open/prayer/room/train1-14

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "走廊");
  set ("long", @LONG

	    再往南走就是戒律房了，北方是傳功房及
	通往聖火教的各部門的路，面前有一個值班弟
	子正在巡查．

LONG);
  set("objects", ([ /* sizeof() == 1 */
  "/open/prayer/npc/duty" : 1,		
]));
  set("exits", ([ /* sizeof() == 2 */
	"south" : "/open/prayer/room/train1-19",		//`走廊
	"north" : "/open/prayer/room/train1-9",		//`走廊
]));

  setup();
}
 
