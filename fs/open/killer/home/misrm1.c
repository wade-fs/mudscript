#include <room.h>
#include "/open/open.h"
inherit ROOM;

void create ()
{
  set("short","裝備室");
  set ("long", @LONG
這裡是黑牙聯出任務領取兵器的地方﹐在這裡可以看到不少的兵器
你可以看到一個裝備箱，只有葉秀殺同意才可以拿取。
 
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "down":__DIR__"masterm.c",
  "east":__DIR__"misrm3.c",
]));

  set("objects",([
/*        "/open/killer/npc/spy1": 1, */
        "/open/killer/obj/misbox1.c": 1,
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
   
   if (me->query_temp("god")==1)
   {
    tell_room(me,""+me->query("name")+"發現路，往北邊走去。\n");
    me->set_temp("key",0);
    me->move(__DIR__"misrm2.c");
    return 1;
   }
   return 0;
}
