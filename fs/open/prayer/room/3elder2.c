//open/prayer/room/3elder2

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "戒律長老房");
  set ("long", @LONG

	    這裡就是戒律長老的辦公室了，但是沒看
	到長老的人，在書櫃上擺著不少的書，想必那
	書上記載著有關教規的資料．

LONG);
  set("exits", ([ /* sizeof() ==  2*/
	"south" : "/open/prayer/room/3elder3",		//`長老房
	"west" : "/open/prayer/room/3elder5",		//`長老房
]));
  set("light_up", 1);

  setup();
}
 
