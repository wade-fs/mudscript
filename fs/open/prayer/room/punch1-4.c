//open/prayer/room/punch1-4 

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "聖火教總壇");
	set( "build", 12 );
  set ("long", @LONG

    強烈的白色映入你眼簾，你注意到這裡有一個紅木窗櫺的窗子，屋子
的裡有幾個書櫃，書櫃上有著不少的寶典秘笈，而在書櫃前有一個風華絕
代的中年婦人，手中拿著一本孫子兵法，口裏念念有詞，想必是又想到絕
妙好計了。 

LONG);

  set("objects", ([ /* sizeof() == 1 */
  "/open/prayer/npc/literate" : 1,        	//軍師
]));
  set("exits", ([ /* sizeof() == 3 */
	"enter" : "/open/prayer/room/punch1-6",		//軍師的房間
	"south" : "/open/prayer/room/punch1-8",		//大聽
	"east" : "/open/prayer/room/punch1",		//幫主
]));
  set("light_up", 1);

  setup();
}
int valid_leave(object me,string dir)
{
  if(dir=="enter"&&me->query("class")!="prayer")
  return notify_fail("非聖火教徒不得進入!\n");
  return ::valid_leave(me,dir);
}

