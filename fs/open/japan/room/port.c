//排版 by blazakira 2011/8/21

inherit ROOM;

void create ()
{
  set ("short", "幻龍海岸");
  set ("long", @LONG
你來到一個漂亮的海岸，左邊有高山盤踞宛如飛龍在天
右方遠處有一小小的告示牌 (board)，在海的另一端似乎可
以隱隱約約的看到有一孤島。
LONG);

  set("item_desc", ([ /* sizeof() == 1 */
    "board" : "
前路茫茫無盡期，東瀛有島在眼前。
",
  ]));
  set("light_up", 1);
  set("outdoors", "/open/japan");
  set("exits", ([ /* sizeof() == 1 */
    "west" : __DIR__"s4",
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
    this_player()->move(__DIR__"ship");
    return 1;
  }
  return 0;
}
