//排版 by blazakira 2011/8/21

inherit ROOM;

void create ()
{
  set ("short", "神祕出口");
  set ("long", @LONG
四周仍然一片黑暗，但仔細觀察似乎可以感到出口就在這
裡東方的石壁傳來晞微的光線，或許東方的石壁就有出口。
LONG);

  set("exits", ([ /* sizeof() == 3 */
    "north" : __DIR__"s1.c",
    "down" : __DIR__"s3",
  ]));

  setup();
}

void init()
{
  add_action("do_search","search");
  add_action("do_pass","pass");
}

int do_search(string str)
{
  if(str!="east") return 0;
  this_player()->set_temp("search",1);
  message_vision("$N撥動東方石壁上的碎石，出現了小小的洞口(hole)。\n",this_player());
  return 1;
}

int do_pass(string str)
{
  if(str!="hole") return 0;
  if(this_player()->query_temp("search")==0) return 0;
  message_vision("$N往洞口鑽了進去。\n",this_player());
  this_player()->set_temp("search",0);
//  this_player()->move("/open/japan/room/port.c");
  this_player()->move(__DIR__"port.c");
  return 1;
}
