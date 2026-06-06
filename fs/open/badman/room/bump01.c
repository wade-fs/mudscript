inherit ROOM;
 void create()
{
  set ("short","廟庭中的大洞");
  set ("long",@LONG
這裡是坑洞的盡頭，之前所看到的那股藍光，因為你的更加靠近，顯
得更是耀眼！仔細一看，這股藍光竟是透過地面散出，泥地也因此透出閃
閃藍光，教人不得不讚嘆三聲！！！
LONG);
  
  set("outdoors", "/open/badman");

  set("exits", ([ /* sixeof() == 1 */
  "east" : __DIR__"bump.c",
]));

  setup();
}

void init()
{
  add_action("do_search","search");
  add_action("do_dig","dig");
}
int do_search()
{
  object who;
  who = this_player();
  message_vision("你看了看地上的泥地，鬆鬆軟軟的，好像可以挖（dig）。\n",who);
  who->set_temp("marks/dig",1);
  return 1;
}
int do_dig()
{
  object who;
  who = this_player();
  if (who->query_temp("marks/dig",1))
  {
   message_vision("你挖呀挖，忽然一陣耀眼的藍光照耀著你！
但這洞穴因為你的翻動，就快要塌了！！
突然有人抓著你衣服的後領，將你提了起來！\n",who);
  who->move("/open/badman/room/wolf17.c");
   return 1;
  }
  else
  {
  message_vision("你要挖哪裡？\n",who);
  return 1;
  }
}
