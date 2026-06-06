//排版且調整解迷的判斷 by blazakira 2011/8/6

#include <ansi.h>
inherit ROOM;

void create()
{
  set("short", "莫塔湖南邊");
  set("long", @LONG
	在你眼前的是一大片深不可測的湖水，傳說此湖水表面平靜
	但是內部暗潮洶湧，就連泳技高超的高手也不敢輕易嘗試
	你想進去試看看嗎？我想還是不要吧................

LONG
  );
  set("exits", ([ /* sizeof() == 2 */
    "south" : __DIR__"hr3.c",
    "east" : __DIR__"lk7.c",
    "north" : __DIR__"lk4.c",
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
    message_vision(HIY + "$N哇勒....你是怎麼來到這裡的，作弊呀？？可惡........\n" + NOR, me);
    message_vision(HIY + "一瞬間一陣機關鳴動聲............\n" + NOR,me);
    max=me->query("kee");
    max= (int) (max/2);
    me->add("kee",-max);
    tell_object(me,HIR + "一陣衝撞力將你彈飛，落入陷阱之中一直墜落～～\n" + NOR);
    me->move("/open/killer/room/firstrm.c");
    return 1;
  }
  else if (me->query_temp("find_fish")  == 2 )  //因為是要依序尋找所以用等於檢查
  {
    message_vision("$N利用定水珠的力量，在水中仔細的尋找大魚的身影。\n", me);
    message_vision("$N再一次的發現水中有一道黑影一閃而過，但速度之快仍令人難以置信。\n",me);
    message_vision("$N心隨意轉，立刻追上去，但黑影消失在遠遠的東北方。\n",me);
    me->set_temp("find_fish",3);
    return 1;
  }
  tell_object(me,"你在湖中，四處尋找，不過並沒有看到什麼東西，\n看來需要到其他地方找找。\n");
  return 1;
}

int valid_leave(object me, string dir)
{
  int max;
  object ob2;

  if ((dir == "north")  || (dir == "east"))
  {
    if (me->query("class") != "killer")
    {
      message_vision(HIY + "$N勇敢的跳了下去，但是強大的水流將自己帶往深處。\n" + NOR,me);
      message_vision(HIY + "$N被水流不知帶往何處............\n" + NOR, me);
      max=me->query("kee");
      max= (int) (max/2);
      me->add("kee",-max);
      me->move("/open/ping/room/road4");
      return 0; //在valid_leave時使用move 需設定為return 0 非valid_leave時 則需設定為return 1
    }
    else if ( !present("static_water",me) ) //class=killer時 檢查玩家是否有定水珠
    { //如果沒有定水珠，又是MEM等於三，代表第一次來到這裡
      message_vision(HIY + "$N勇敢的跳了下去，但是強大的水流將自己帶往深處\n" + NOR,me);
      message_vision(HIY + "$N被水流不知帶往何處............\n" + NOR, me);
      if(me->query_temp("memory") < 3) //往事之謎的判定
      {
        me->move("/open/killer/room/rbd.c");
      }
//      if (me->query_temp("memory") ==3)
      else
      {
        ob2=new(__DIR__"static.c");
        ob2->move(me); //先給予定水珠
        me->set_temp("memory",4);
        me->move(__DIR__"ballrm.c");
      }
      return 0;
    }
//從其他地方取得定水珠時 可以通過
    else if(me->query_temp("memory") < 3)
    {
      return 1; //設為return 1只是跳出判斷 才能繼續動作 設為return 0則會阻擋離開
    }
    else
    {
      me->set_temp("memory",4); //當query_temp("memory")=3時 繼續下一段的quest判定
      return 1;
    }
  } //方向判斷結束
  return 1;
}
