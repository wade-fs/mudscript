inherit ROOM;
void create()
{
set("short", "莫塔湖東北東");
set("long", @LONG
	在你眼前的是一大片深不可測的湖水，傳說此湖水表面平靜
	但是內部暗潮洶湧，就連泳技高超的高手也不敢輕易嘗試
	這時你已經來到湖邊了，藉著定水珠的功效，你並沒有太大的困擾
	然而，這裡真的會有那隻大魚嗎？看來你得四處找找...........

LONG
);
set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"lk1.c",
  "east" : __DIR__"lk3.c",
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
   if (me->query_temp("find_fish")  == 5 )  //因為是要依序尋找所以用等於檢查
  {
    message_vision("$N利用定水珠的力量，在水中仔細的尋找大魚的身影。\n", me);
    message_vision("$N因為並沒有拖延時間便追到這裡，所以大魚並沒有逃遠\n",me);
    message_vision("看來大魚在劫難逃時，大魚一個翻身擊中$N，並往東南方逃去\n",me);
    me->set_temp("find_fish",6);
    return 1;
  }
   tell_object(me,"你在湖中，四處尋找，不過並沒有看到什麼東西，\n看來需要到其他地方找找\n");
   return 0;
 }
