//open/prayer/room/train1-8

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "練武場");
  set ("long", @LONG

	    前方十公尺處有兩個聖火弟子，正在聖火
	教總壇的練武場，相互的套招，仔細一看原來
	是在打混摸魚．

LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/prayer/npc/trainee2" : 2,		//弟子
]));
  set("outdoors", "/open/prayer/room");
  set("exits", ([ /* sizeof() == 3 */
	"south" : "/open/prayer/room/train1-13",		//練武場
	"north" : "/open/prayer/room/train1-3",		//`走廊
	"east" : "/open/prayer/room/train1-7",		//`練武場
]));

  setup();
}
 
