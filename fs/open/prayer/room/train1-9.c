//open/prayer/room/train1-9

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "走廊");
  set ("long", @LONG

	    聖火教總壇的大走廊，往西邊進去便是執
	法長老的房間．南邊的盡頭是廚房，往北是聖
	火教的御花園．

LONG);
  set("exits", ([ /* sizeof() == 3 */
	"south" : "/open/prayer/room/train1-14",		//`走廊
	"north" : "/open/prayer/room/train1-4",		//`走廊
	"enter" : "/open/prayer/room/2elder6",		//`長老房
]));

  setup();
}
 
