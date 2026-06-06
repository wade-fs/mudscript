//open/prayer/room/train1-19

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "走廊");
  set ("long", @LONG

	    突然有陣陣的香味傳來，原來是南方進去
	就是聖火教的伙房了，就在此時你的肚子咕嚕
	咕嚕叫了幾聲．

LONG);
  set("exits", ([ /* sizeof() == 2 */
	"enter" : "/open/prayer/room/kicthen6",		//`廚房
	"north" : "/open/prayer/room/train1-14",		//`走廊
]));
        set("objects",([ /* sizeof() == 1 */
  "/open/prayer/npc/footman" : 1,		//跑堂
   		
]));

  setup();
}
 
