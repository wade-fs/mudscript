//open/prayer/room/horse3

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "馬房");
  set ("long", @LONG

	    眼前有著許許多多的馬匹，雖然這些馬匹
	在聖火教中，是屬於最低層次的，這些馬匹都
	經過嚴格馴練過的．

LONG);
  set("outdoors", "/open/prayer/room");
  set("exits", ([ /* sizeof() ==  4*/
	"west" : "/open/prayer/room/horse6",		//`馬房
	"north" : "/open/prayer/room/horse2",		//`馬房
	"south" : "/open/prayer/room/horse4",		//`馬房
	"east" : "/open/prayer/room/horse1",		//`馬房
]));

  setup();
}
 
