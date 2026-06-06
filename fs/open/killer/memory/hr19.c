#include "/open/open.h"
inherit ROOM;

void create ()
{
  set ("short", "莫塔湖源河邊");
  set ("long", @LONG
	
	在你眼前所呈現的是一條壯闊的河流，水勢不急但是卻絲毫無魚？！
	但是隨後，在河中有一個石頭宛如飛劍一般，快速的隨水而流逝！！
	原來此河暗潮洶湧，水勢湍急！！一般魚蝦根本無法在其中游泳！
	在南方似乎有小路可以沿著河邊行走.........

LONG);

  set("exits", ([ /* sizeof() == 3   */
     "south" : __DIR__"hr20.c",   
     "west" : __DIR__"hr18.c",   
]));

  setup();
}
