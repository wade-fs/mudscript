#include "/open/open.h"
inherit ROOM;

void create ()
{
  set ("short", "斷崖");
  set ("long", @LONG

	天啊！！在你眼前的一個深不見底的巨大山谷，與東方的另一山脈
	形成了一個直角的垂直山谷，遠遠望去可以方現東方的山谷有一條巨大的河流
	莫非那一條河流就是莫塔湖的源河？令你不禁想一探究竟........
	
LONG);

  set("exits", ([ /* sizeof() == 3   */
     "east" : __DIR__"hr18.c",   
     "south" : __DIR__"hr16.c",   
]));

  setup();
}
