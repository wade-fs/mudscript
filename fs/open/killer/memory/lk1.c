//調整解迷的判斷 by blazakira 2011/8/6

#include <ansi.h>
inherit ROOM;

void create()
{
  set("short", "莫塔湖北邊");
  set("long", @LONG
	在你眼前的是一大片深不可測的湖水，傳說此湖水表面平靜
	但是內部暗潮洶湧，就連泳技高超的高手也不敢輕易嘗試
	你想進去試看看嗎？我想還是不要吧................

LONG
  );
  set("exits", ([ /* sizeof() == 2 */
    "south" : __DIR__"lk4.c",
    "east" : __DIR__"lk2.c",
    "up" : __DIR__"hr20.c",
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
  else if (me->query_temp("memory") < 4)
  {
    message_vision(HIY + "$N哇勒....你是怎麼來到這裡的，作弊呀？？可惡........\n" + NOR, me);
    message_vision(HIY + "一瞬間一陣機關鳴動聲............\n" + NOR,me);
    max=me->query("kee");
    max= (int) (max/2);
//    me->add("kee",-max);
    me->receive_damage("kee", max, me);
    tell_object(me,HIY + "一陣衝撞力將你彈飛，落入陷阱之中一直墜落～～\n" + NOR);
    COMBAT_D->report_status(me);
    me->move("/open/killer/room/firstrm.c");
  }
  else if (me->query_temp("find_fish") == 4) //因為是要依序尋找所以用等於檢查
  {
    message_vision("$N利用定水珠的力量，在水中仔細的尋找大魚的身影。\n", me);
    message_vision("$N發現一條巨大的魚體閃過眼前，不過速度之快，仍然令人難以置信。\n",me);
    message_vision("$N伸出雙手打算捕捉它，但它迅速的逃到不遠的東方。\n",me);
    me->set_temp("find_fish",5);
  }
  else
    tell_object(me,"你在湖中，四處尋找，不過並沒有看到什麼東西，\n看來需要到其他地方找找。\n");
  return 1;
}

int valid_leave(object me, string dir)
{
  int max;
  object ob2;

  if ((dir == "south") || (dir == "east") || (dir == "up"))
  {
    if (me->query("class") != "killer")
    {
      message_vision("$N勇敢的跳了下去，但是強大的水流將自己帶往深處。\n",me);
      message_vision("$N被水流不知帶往何處............\n", me);
      max=me->query("kee");
      max= (int) (max/2);
      me->add("kee",-max);
      me->move("/open/ping/room/road4");
      COMBAT_D->report_status(me);
      return 0;
    }
    else if ( !present("static_water",me) )  //檢查玩家是否有定水珠
    { //如果沒有定水珠，又是MEM等於三，代表第一次來到這裡
      message_vision("$N勇敢的跳了下去，但是強大的水流將自己帶往深處。\n",me);
      message_vision("$N被水流不知帶往何處............\n", me);
      if(me->query_temp("memory") < 3)
        me->move("/open/killer/room/rbd.c");
//      if (me->query_temp("memory") ==3)
      else
      {
        ob2=new(__DIR__"static.c");
        ob2->move(me);
        me->set_temp("memory",4);
        me->move(__DIR__"ballrm.c");
      }
      return 0;
    }
    //如果有定水珠就代表可以通過
//    else if(me->query_temp("memory") <= 3)
//      return 0;
//    return 1;
    return ::valid_leave(me,dir);
  }
//  return 1;
}
