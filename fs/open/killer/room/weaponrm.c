#include <room.h>
#include "/open/open.h"
inherit ROOM;

void create ()
{
  set("short","兵器室");
	set( "build", 42 );
  set ("long", @LONG
這裡是黑牙聯平時儲存兵器的地方﹐在這裡可以看到不少的兵器
但是大多是暗器﹐只有黑牙聯的弟子可以在這裡領取兵器﹐但是必須
先向掌理兵器的兵器使報備(report)﹐想知道有什麼兵器就用(list)。
這裡也是存放舊玩家留下的裝備的好地方。多多照顧新人吧！
 
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "up":__DIR__"ru2.c",
]));

  set("objects",([
        "/open/killer/npc/manager": 1,
        "/open/killer/npc/young": 1,
]));
  setup();
}
void init()
{ 
   add_action("do_open","open");
}
int do_open()
{
   object me;
   me = this_player();
   
   if (me->query_temp("key")==3)
   {
    tell_room(me,""+me->query("name")+"打開門，往專用兵器室走去。\n");
    me->set_temp("key",0);
    me->move(__DIR__"haterm.c");
    return 1;
   }
   return 0;
}
