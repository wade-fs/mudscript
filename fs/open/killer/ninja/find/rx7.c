// open/killer/ninja/find/rx6.c
// 我想玩家應該會選重這一項，所以順便送點謎題的引子
// 當玩家發生抉擇錯誤，就會受到嚴重精神傷害，退回最初點
#include "/open/open.h"
inherit ROOM;

void create ()
{
  set ("short", "心靈探索");
  set ("long", @LONG
  從一開始，你就沒有去干涉到這個時空裡面的一切，現在居然被人家發現了？
  你決定，立刻反擊，避免事情的惡化下去!!! 反身立刻推出一掌!!
  
  然而你立刻發現你的決定有多麼的愚蠢!! 因為對方居然施展出『幻星步』？!
  而且身法遠超過你想像中的快!且帶有特殊的幻影存在!!!
  並且一股，暨熟悉又陌生的氣勁向自己席捲而來，並且聽到『魔氣殺』!!
  氣勁裡面居然帶有一股凍氣？這是魔氣殺嗎？？？!
  
  你並沒有機會想太多，因為你的眼前已經看不到東西了..............

LONG);
  setup();
}

void init()
{
    object ob=this_player();
    if( interactive(ob))
	    remove_call_out("greeting");
  call_out("greeting",3 , ob);   
}

void greeting(object ob)
{
   if( ob->query_temp("firstpart")== 8)    
   {
     ob->set_temp("firstpart",7);
     ob->set("sen",1);
     ob->set("gin",1);
     tell_object(ob," 你感到精神逐漸渙散....逐漸陷入昏迷狀態..... \n");
     ob->move("/open/killer/room/pillrm.c");
    }
    // 基本上是很不合理啦，就當成巫師測試用，一到最初點
    else 
     ob->move(__DIR__"r1.c");
}

