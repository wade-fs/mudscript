inherit ROOM;

void create ()
{
  set ("short", "不知名的空間");
  set ("long", @LONG
這是一個神祕的地方，四周不斷的有人影在閃動
你能感覺到你來到一個未知的空間，並且被監視中，
或許迅速離開這個地方是你最好的選擇，你可以試著
使用輕功離開。
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"s3",
  "south" : __DIR__"s1",
  "north" : __DIR__"s2.c",
  "northwest" : __DIR__"s3",
]));

  setup();
}

void init()
{
  add_action("do_jump","jump");
  add_action("do_search","search");
}

int do_search(string str)
{
  message_vision("試著用輕功(jump)離開吧。\n",this_player());
  return 1;
}

int do_jump()
{
  if(this_player()->query_skill("dodge",1)<10) return 0;
  message_vision("$N施展獨門輕功一縱而上，離開了神祕空間。\n",this_player());
  this_player()->move("/open/killer/memory/hr20.c");
  return 1;
}
