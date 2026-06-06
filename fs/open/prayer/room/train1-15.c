//open/prayer/room/train1-15

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "走廊");
  set ("long", @LONG

	    前面這個入口，便是聖火戒律廳的門口，
	門的裡面傳來陣陣的哀號聲，難到又發生弟子
	犯錯的事情了嗎．

LONG);
  set("exits", ([ /* sizeof() == 2 */
	"enter" : "/open/prayer/room/3elder6",		//`長老房
	"north" : "/open/prayer/room/train1-10",		//`走廊
]));

  setup();
}
 
