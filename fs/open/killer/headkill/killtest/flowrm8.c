#include <room.h>
#include <ansi.h>
inherit ROOM;
string str;

void create ()
{
   set ("short","幸運之間");
   set ("long", @LONG
	度過一次又一次的相同景色後，終於來到有點不一樣的地方了。
	但是，這裡居然沒有任何特殊的事物，也沒有守關的敵人。
	在你眼前的只有四個方向，不過這裡似乎沒有被封印起來。
	難不成可以叫賣東西？看來可以補充一下裝備了！
	但是，你終究必須選擇一個方向前去。。。。。
 	   (請打move east,north,south,west任一方向)
	
LONG);
  set("no_fight",1);
  set("no_magic", 1);
  set("no_transmit",1);
  setup();
}

void init()
{//設定這一次的正確方向
  int i;

  i=random(4);
  
  switch(i)
  {
	case 0: str="north";
		break;
	case 1: str="east";
		break;
	case 2: str="west";
		break;
	case 3: str="south";
		break;
  }
  add_action("do_move", "move");
}

int do_move(string arg)
{
  int way;
  object me=this_player();

  if (!arg)
     return notify_fail("選擇一個你要去的方向吧。\n");

  if (arg != str)
  {
    message_vision("$N感到一陣眼花撩亂，看來是走錯方向了！\n", me);
    me->set_temp("killrun",0);
    me->move(__DIR__"flowrm1.c");
    return 1;
  }
  message_vision(HIW + "一道光芒射向$N，一道黑氣由$N身上離去了，看來他的罪業消失了！\n" + NOR, me);
  me->delete("title");
  me->delete("killyar");
  me->move("/open/killer/room/masterm.c");
  me->save();
  return 1;
}
