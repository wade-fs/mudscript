inherit ROOM;
 void create()
{
  set ("short","破廟");
  set ("long",@LONG
這是一間看來已荒廢已久的小廟 .供桌上和藹可親的佛像也已破舊
不堪 ,從四周頹圮不已 ,年久失修的情況看來 ,這裡似乎的確是無人居
住 .
LONG);

  set("light_up", -1);
  set("exits", ([ /* sixeof() == 1 */
  "east" : __DIR__"wolf12.c",
]));

  setup();
}

void init()
{
  add_action("do_search","search");
  add_action("do_bump","bump");
}
int do_search()
{
  object who;
  who = this_player();
  if (who->query_temp("marks/karup2",1))
  {
   tell_object(who,"你到處看了看，發現在破舊的神桌旁有扇\n");
   tell_object(who,"半塌的門，由牆壁坍塌的石堆雖然將通道\n");
   tell_object(who,"堵住，但或許\可以將之撞開（bump）。\n");
   who->set_temp("marks/bump",1);
   return 1;
  }
  else
  {
  message_vision("這種破舊地方有啥好搜尋的？\n",who);
  return 1;
  }
}
int do_bump()
{
  object who;
  who = this_player();
  if (who->query_temp("marks/bump",1))
  {
   tell_object(who,"你氣沉丹田，使勁用力一撞！\n");
   tell_object(who,"磅！的一聲，你衝到了另外一個房間！！\n");
   tell_object(who,"但好景不常，你腳下一空，跌到了一個大洞中！！\n");
   who->move("/open/badman/room/bump.c");
   tell_room(this_object(),"你只看到"+who->query("name")+"往前一衝，就不見了!！\n");
   return 1;
  }
  else
  {
  message_vision("撞？你是要撞哪裡？？\n",who);
  return 1;
  }
}
