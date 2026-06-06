//open/prayer/room/punch1-2

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "聖火總壇大廳");
	set( "build", 84 );
  set ("long", @LONG

    這是聖火教的總壇大廳，幫務處理與玩家討論的地方，你可以在這留
下你對聖火教的建議，或是聖火教哪出了問題，都可以在此留言，畢竟聖
火教是為大家而開的，請大家好好愛惜它。

LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/prayer/npc/general-manager" : 1,               //弟子
]));
  set("exits", ([ /* sizeof() == 4 */
        "north" : "/open/prayer/room/punch1",           //`幫主
        "south" : "/open/prayer/room/punch1-10",                //`大廳
//      "east" : "/open/prayer/room/punch1-8",          //`大廳
//      "west" : "/open/prayer/room/punch1-10",         //`大廳
]));
  set("light_up", 1);
  setup();
  call_other("/obj/board/prayer_b", "???");
}
 
