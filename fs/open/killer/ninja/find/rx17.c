// open/killer/ninja/find/rx17.c
// 當玩家發生抉擇錯誤，就會受到嚴重精神傷害，退回最初點
#include "/open/open.h"
inherit ROOM;

void create ()
{
  set ("short", "心靈探索");
  set ("long", @LONG
  
  這麼有趣的情況，當然要好好的參與一下，你立刻縱身攔下此一隊伍。
  然而你立刻發現這是多麼愚蠢的一件事情，因為既然人家是在潛行。
  自然不會希望有人視破，就在你想通這一件事的瞬間。
  由此人身上放出排山倒海的劍氣，貫穿了你的身體.....
  在你眼前一黑之前聽到『仙劍後九式之......』
  後九式？仙劍怎麼會有後九式？.......
   
LONG);
  set("no_transmit",2);
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

