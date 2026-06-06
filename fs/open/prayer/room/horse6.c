//open/prayer/room/horse6

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "馬房");
  set ("long", @LONG

	    仔細一看四周，你才發現你己來到聖火教
	的馬房了，四處傳來陣陣的馬啼聲，想必教裡
	所擁有的馬匹數量一定不少．

LONG);
  set("outdoors", "/open/prayer/room");
  set("exits", ([ /* sizeof() ==  4*/
	"out" : "/open/prayer/room/train1-2",		//`走廊
	"north" : "/open/prayer/room/horse5",		//`馬房
	"south" : "/open/prayer/room/horse7",		//`馬房
	"east" : "/open/prayer/room/horse3",		//`馬房
]));

  setup();
}
 
