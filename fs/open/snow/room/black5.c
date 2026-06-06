#include <room.h>
#include "../../open.h"
inherit ROOM;

void create ()
{
  set("short","兵器庫");
  set ("long", @LONG
這裡是黑牙聯平時儲存兵器的地方﹐在這裡可以看到不少的兵器
但是大多是暗器﹐只有黑牙聯的弟子可以在這裡領取兵器﹐但是必須
先向掌理兵器的兵器使報備(report)﹐想知道有什麼兵器就用(list)。
 
LONG);

  set("exits", ([ /* sizeof() == 3 */
	"west":__DIR__"black4",
]));

  set("objects",([
	"/open/snow/npc/manager":1,
	]));

  setup();
}
void init()
{ 
   add_action("do_search","search");
}
int do_search()
{
   object me;
   me = this_player();
   tell_object(me,"你找到了機關,發現一條出路 \n");
    set("exits", ([
    "west":__DIR__"black4",
     ]));
   return 1;
}
