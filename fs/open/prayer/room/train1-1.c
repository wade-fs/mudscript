//open/prayer/room/train1-1

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "走廊");
  set ("long", @LONG

	    這裡是聖火教的大走廊，連接著聖火教的
	三大廳，有一個拳師正朝著你沖沖走來，好像
	發生了什麼事一般．

LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/prayer/npc/puncher1" : 1,		
]));
  set("exits", ([ /* sizeof() == 2 */
//	"south" : "/open/prayer/room/train1-6",		//練武場
	"east" : "/open/prayer/room/train1-2",		//`走廊
	"west" : "/open/prayer/room/train1",		//`練武場
]));

  setup();
}
 
