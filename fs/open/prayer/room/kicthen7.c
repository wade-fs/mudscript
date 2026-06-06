//open/prayer/room/kitchen7

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "廚房");
  set ("long", @LONG

	    在旁邊有著堆積如山的菜，及各式各樣的
	肉類，和許多正要處理的食物，光看到這些菜
	量，就可以知道聖火教是一個非常龐大的組織
	了．

LONG);
  set("exits", ([ /* sizeof() ==  2*/
	"south" : "/open/prayer/room/kicthen4",		//`廚房
	"west" : "/open/prayer/room/kicthen6",		//`廚房
]));
   set("light_up", 1);

  setup();
}
