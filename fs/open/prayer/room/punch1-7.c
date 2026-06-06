//open/prayer/room/punch1-7

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "總壇大聽");
  set ("long", @LONG

    再往前走便是聖火教副教主，處理教徒門一切事務及指導弟子們武功
的大廳了，你看到不少的教徒絡繹不絕的走進走出，想必副教主是一位能
力極佳的人，才能處理教務並教導武功． 

LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/prayer/npc/vice-manager" : 1,		//弟子
]));
  set("exits", ([ /* sizeof() == 2 */
	"north" : "/open/prayer/room/punch1-3",		//`副幫主
	"south" : "/open/prayer/room/punch1-9",		//`大廳
]));

  setup();
}
 
