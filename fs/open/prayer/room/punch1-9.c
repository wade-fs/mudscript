//open/prayer/room/punch1-9

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "總壇大聽");
  set ("long", @LONG

    在你身旁的花岡牆上，刻著許許多多用行書寫的文字，並且井然有序
，頭緒分明，上面寫的正是聖火教的教規，看來聖火教是一個非常有制度
，教規深嚴的組織．

LONG);
  set("exits", ([ /* sizeof() == 3 */
	"north" : "/open/prayer/room/punch1-7",		//`大廳
	"south" : "/open/prayer/room/punch1-12",	//`大廳
	"west" : "/open/prayer/room/punch1-10",		//`大廳
]));

  setup();
}
 
