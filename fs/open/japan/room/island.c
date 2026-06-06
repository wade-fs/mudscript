// Room: /open/gblade/port/room/port.c

inherit ROOM;

void do_start_ship();

void create()
{
  set("short","碼頭");
  set ("long", @LONG
南來北往的商船停滿的碼頭，遠處似乎還有不少商船排隊等待進
港。商人彼此之間討論著不同地方的消息，苦力忙碌的把船上的貨品
卸下船隻。不遠的北方銜接的南大路橋。

LONG);
  set("light_up", 1);
  set("outdoors", "/open/japan");
  set("exits", ([ /* sizeof() == 1 */
    "north" : __DIR__"j01",
  ]));
  setup();
}

init()
{
  add_action("board_ship","board");
  do_start_ship();
}

void do_start_ship()
{
  object ob1;
  if(!find_object("ship leader"))
  {
    ob1=new("/open/japan/npc/ship_leader");
    ob1->move(__DIR__"ship");
    destruct(ob1);
  }
}

int board_ship(string str)
{
  object ob;
  if(!str)
    return notify_fail("你要搭什麼？\n");
  if(!objectp(ob=present(str,environment(this_player()))))
    return notify_fail("看清楚點，有那種船嗎？\n");
  if(str=="ship") 
  {
    message_vision("$N走到岸邊，搭上了渡船！\n",this_player());
//    this_player()->move("/open/japan/room/ship");
    this_player()->move(__DIR__"ship");
    return 1;
  }
  return 0;
}
