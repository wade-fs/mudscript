//open/prayer/room/1elder4

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "傳功\長老房");
  set ("long", @LONG

	    這裡就是傳功長老的辦公室了，但是沒看
	到長老的人，該不是又在練武場指導弟子門的
	功夫了．

LONG);

  set("exits", ([ /* sizeof() ==  2*/
	"north" : "/open/prayer/room/1elder3",		//`長老房
	"west" : "/open/prayer/room/1elder7",		//`長老房
])); 
 set("light_up", 1);

  setup();
}
 
