inherit ROOM;
void create()
{
set ("short", "花園");
  set ("long", @LONG
   這裡種了不少奇花異草，看來有不少是藥草，但你卻不瞭解它的功用。
   隨風飄來的花香令你不禁沈醉其中，令你仔細地欣賞起花來。
   卻發現這裡，居然全部種植來自東洋的植物，看來這裡蠻值得懷疑。。。。
   不過或許是自己多疑了吧。。。。。

LONG);

  set("outdoors", "/open/main");
  set("exits", ([ /* sizeof() == 4 */
      "north" : __DIR__"outr4.c",
      "east"  : __DIR__"outr2.c",
]));
setup();
}

void init()
{
  add_action("do_search", ({"search"}));
  add_action("do_push", ({"push"}));
  add_action("do_puton", ({"puton"}));
}

int do_search(string arg)
{
  object me=this_player();
  int query;

  query=me->query_temp("herb_1");
  if (arg)
    if (query > 1) 
       return notify_fail("還想進去拿呀！小心被發現！！。\n");
  else return 0;
  message_vision("$N找來找去終於發現按鈕(button),\或\ \許\ 可以(puton)\n", me);
  return 1;
}

int do_push(string arg)
{
  object me=this_player();
  int query;

  query=me->query_temp("herb_1");
  if (arg != "button")
    return 0;
  if (query > 1) 
    return notify_fail("還想進去拿呀！小心被發現！！。\n");
  message_vision("$N按了一下，發現有樹中出現通道。\n", me);
  message_vision("但是，手一放開又合上了，\或\許該找\個\(rock) \n", me);
  return 1;
}

int do_puton(string arg)
{
  object me=this_player();
  object ob;
  int query;

  if ( arg != "rock" )
     return notify_fail ("你想拿什麼來壓呀？。\n");
  if ( present("rock",me) )
  {
    message_vision("$N用石頭壓住按鈕，發現有樹中出現通道。\n", me);
    ob=present("rock",me);
    destruct(ob);
    me->set_temp("tree_hole",1);
    set("exits/tree", __DIR__"herbrm.c");
    return 1;
  }
  return 0;
}

int valid_leave(object me, string dir)
{
  if (dir != "tree") 
  {
    this_object()->delete("exits/tree");
    return 1;
  }
  if (me->query_temp("tree_hole") != 1)
    return 0;
  this_object()->delete("exits/tree");  //只可進去一次
  return 1;
}
