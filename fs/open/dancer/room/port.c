// Room: /open/dancer/room/port.c :cgy
#include <room.h>
#include <ansi.h>

inherit ROOM;
void do_start_ship();

void create ()
{
  set ("short","鏡月港");
  set ("long", @LONG
這裡是鏡月島上唯一的港口，也是你出入鏡月島的必經之地，向
東你可以展開你的鏡月島旅程，當然你也可以在此地搭船離開這座鏡
月島。

LONG);

  set("exits", ([ /* sizeof() == 1 */
  "east" : "/open/dancer/room/r7-2.c",
]));
  set("light_up", 1);

  setup();
}

void init()
{
  add_action("board_ship","board");
  do_start_ship();
}

void do_start_ship()
{
  object ob1;
  if(!find_object("ship girl"))
  {
  ob1=new("/open/dancer/npc/ship_girl");
  ob1->move("/open/dancer/room/ship");
  destruct(ob1);
  }
}

int board_ship(string str)
{
  object ob;
  if(!str) { return notify_fail("你要搭什麼？\n"); }
  if(!objectp(ob=present(str,environment(this_player()))))
    { return notify_fail("對不起，沒這種船耶。\n"); }
  if(str=="ship") {
    message_vision("$N走到岸邊，搭上了彎月舫！\n",this_player());
    this_player()->move("/open/dancer/room/ship");
    return 1;
  }
  return 0;
}

int valid_leave(object me, string dir)
{
  if( dir=="east" && me->query("gender")!="女性" && !me->query("quests/moon") )
    return notify_fail("你還沒解開鏡月島之謎不能進入喔！\n");
  return ::valid_leave(me,dir);
}
