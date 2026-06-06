//open/prayer/room/horse7

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "馬房");
  set ("long", @LONG

	    只是一間堆放雜物的房間，在這間倉庫有
	許許多多騎馬的基本裝備，及飼養馬匹所須的
	一些工具．

LONG);
  set("outdoors", "/open/prayer/room");
  set("exits", ([ /* sizeof() ==  2*/
	"north" : "/open/prayer/room/horse6",		//`馬房
	"east" : "/open/prayer/room/horse4",		//`馬房
]));

  setup();
}
 
