//open/prayer/room/train1-13

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "練武場");
  set ("long", @LONG

	    在二十公尺處，有三個聖火弟子在聖火教
	總壇的練武場，演練著聖火陣法，真沒想到，
	聖火教竟然還會陣法．

LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/prayer/npc/trainee2" : 3,		//弟子
]));
  set("outdoors", "/open/prayer/room");
  set("exits", ([ /* sizeof() == 3 */
	"south" : "/open/prayer/room/train1-18",		//練武場
	"north" : "/open/prayer/room/train1-8",		//`練武場
	"east" : "/open/prayer/room/train1-12",		//`練武場
]));

  setup();
}
 
