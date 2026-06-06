//open/prayer/room/horse4

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "馬房");
  set ("long", @LONG

	    你來到了聖火八門，門主專屬的馬匹集中
	所了，匹匹精壯的駿馬，顯示出聖火教的階級
	及層次的劃分，有多注重了．

LONG);
  set("outdoors", "/open/prayer/room");
  set("exits", ([ /* sizeof() ==  2*/
	"north" : "/open/prayer/room/horse3",		//`馬房
	"west" : "/open/prayer/room/horse7",		//`馬房
]));

  setup();
}
 
