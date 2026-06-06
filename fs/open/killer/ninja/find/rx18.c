// open/killer/ninja/find/rx18.c
// 當玩家發生抉擇錯誤，就會受到嚴重精神傷害，退回最初點
#include "/open/open.h"
inherit ROOM;

void create ()
{
  set ("short", "心靈探索");
  set ("long", @LONG
  
  在怎麼笨的人也不會攔下他們，所以你決定好好的發揮你的能力
  利用秘密行動跟蹤在隊伍的後面，就是離那個人最遠的地方
  正當你得意將有機會探查到仙劍的秘密，忽然看到胸前居然穿出一把劍
  背後傳來『居然敢跟蹤我們，卻沒想到我們還有反跟蹤隊吧』
  原來自己已經落入人家的觀察當中，且給你一劍.......
  你的眼前一黑............
  
   
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

