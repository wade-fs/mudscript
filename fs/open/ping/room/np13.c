#include <ansi.h>
#include <room.h>
inherit ROOM;

void create ()
{
  set ("short", "長廊");
	set( "build", 14 );
  set ("long", @LONG
走進這裡, 是一條長廊, 往前通往大廳, 而往兩旁也各有一條走
道, 長廊上鋪著上好的大紅地毯, 襯托出一股莊嚴的氣氛。

LONG);

  set("exits", ([ /* sizeof() == 4 */
  "north" : __DIR__"p1.c",
  "south" : __DIR__"np10",
  "west" : __DIR__"np16",
  "east" : __DIR__"np14",
]));
  set("objects", ([ /* sizeof() == 2 */
  "/open/ping/npc/manager.c" : 1,
  "/open/ping/npc/duan-guard.c" : 2,
]));
  set("light_up", 1);

  setup();
}
void init ()
{
  object me=this_player ();
  if ( me->query_temp("six_sp_quest") == 7)
      {
       message_vision(HIY + "\n特上級武僧說道:請讓小僧帶路, 前往天龍寺, 拜見方丈. \n\n" + NOR,me);
       me->set_temp("six_sp_quest",8);
       me->move("/open/tailong/room/aa39.c");
      }
}
