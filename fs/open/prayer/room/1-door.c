//open/prayer/room/1-door

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "總壇玄關");
  set ("long", @LONG

    你現在所在的位置，正是聖火教主的房間，這是教主與教主夫人休息
    這是一條窄長的走道，再往北走就會到達，震驚中原武林的～聖火教
總壇了，在這條走廊的盡頭傳來一陣光亮的火光，莫非聖火教真的名如其
實，燃著不滅的聖火！！ 

LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/prayer/npc/major-officer" : 1,		
]));
  set("exits", ([ /* sizeof() == 2 */
	"enter" : "/open/prayer/room/punch1-13",		//`大廳
	"south" : "/open/prayer/room/train1",		//`練武場
]));

  setup();
}
 
