inherit ROOM;
void create()
{
set("short", "莫塔湖湖心");
set("long", @LONG
	在你眼前的是一大片深不可測的湖水，傳說此湖水表面平靜
	但是內部暗潮洶湧，就連泳技高超的高手也不敢輕易嘗試
	這時你已經來到湖心了，藉著定水珠的功效，你並沒有太大的困擾
	然而，這裡真的會有那隻大魚嗎？看來你得四處找找...........

LONG
);
set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"lk5.c",
  "eastnorth" : __DIR__"lk3.c",
]));
setup();
}

void init()
{
  add_action("do_search", "search");
}

int do_search(string arg)
{
  object me=this_player();
  int max;

  if (arg)
  	return 0;
  if (me->query_temp("memory")  < 4 )
  {
    message_vision("$N哇勒....你是怎麼來到這裡的，作弊呀？？  可惡........。\n", me);
    message_vision("一瞬間一陣機關鳴動聲............\n",me);
    max=me->query("kee");
    max= (int) (max/2);
    me->add("kee",-max);
    tell_object(me,"一陣衝撞力將你彈飛，落入陷阱之中一直墜落。。。。。\n");
    me->move("/open/killer/room/firstrm.c");
    return 0;
  }
   if (me->query_temp("memory")  == 4 )
  {
    message_vision("$N利用定水珠的力量，在水中仔細的尋找大魚的身影。\n", me);
    message_vision("$N忽然發現水中有一道黑影一閃而過，速度之快令人難以置信\n",me);
    message_vision("$N正想定睛看清楚時，黑影已經消失在東南方\n",me);
    me->set_temp("find_fish",1);
    me->set_temp("memory",5);   //防止有人在同一地方重複尋找

				  //FIND﹍FISH是用來檢查追蹤大魚的
    return 1;
  }
  if (me->query_temp("memory")  == 5 )
  {
    message_vision("$N利用定水珠的力量，在水中仔細的尋找大魚的身影。\n", me);
    message_vision("$N發現水中，有一大群黑影往你攻擊而來\n",me);
    me->set_temp("find_fish",10);
me->set_temp("memory",6);
				  //FIND﹍FISH是用來檢查追蹤大魚的
    	new("/open/killer/memory/big_fish.c")->move("/open/killer/memory/lk9.c");
	new("/open/killer/memory/small_fish.c")->move("/open/killer/memory/lk9.c");
	new("/open/killer/memory/small_fish.c")->move("/open/killer/memory/lk9.c");
	new("/open/killer/memory/small_fish.c")->move("/open/killer/memory/lk9.c");
	new("/open/killer/memory/small_fish.c")->move("/open/killer/memory/lk9.c");
	new("/open/killer/memory/small_fish.c")->move("/open/killer/memory/lk9.c");
 new("/open/killer/memory/small_fish.c")->move("/open/killer/memory/lk2");
    new("/open/killer/memory/small_fish.c")->move("/open/killer/memory/lk3");
	new("/open/killer/memory/small_fish.c")->move("/open/killer/memory/lk5");
	new("/open/killer/memory/small_fish.c")->move("/open/killer/memory/lk8");
	new("/open/killer/memory/small_fish.c")->move("/open/killer/memory/lk7");
	new("/open/killer/memory/small_fish.c")->move("/open/killer/memory/lk4");
    return 1;
  }
   tell_object(me,"你在湖中，四處尋找，不過並沒有看到什麼東西，\n看來需要到其他地方找找\n");
   return 0;
 }
