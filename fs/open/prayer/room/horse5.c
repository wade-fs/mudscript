//open/prayer/room/horse5

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "馬房");
  set ("long", @LONG

	    你來到一間惡臭不勘的房間，房間中沒有
	任何一匹馬匹，眼前所見的都是馬匹的排泄物
	看來須要好好整理了．

LONG);

  set("outdoors", "/open/prayer/room");
  set("exits", ([ /* sizeof() ==  2*/
	"south" : "/open/prayer/room/horse6",		//`馬房
	"east" : "/open/prayer/room/horse2",		//`馬房
]));
setup();
}
 
