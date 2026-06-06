// open/killer/ninja/find/rx24.c
// 當玩家發生抉擇錯誤，就會受到嚴重精神傷害，退回最初點
#include "/open/open.h"
inherit ROOM;

void create ()
{
  set ("short", "心靈探索");
  set ("long", @LONG
  
  森林裡面似乎是最適合躲藏的地方，所以你快速的朝森林衝去
  果然你的判斷是非常正確的，森林果然是非常適合躲人的
  一群仙劍派的高手正好躲藏在樹林之中埋伏，你宛如肥羊一般送上門
  老祖將你往後送，自己衝上前去對付那些高手，
  正當你穩住身形，打算翻身往其他方向逃去的時候
  你的背後傳來那個人的聲音『何方小輩，居然敢干涉我仙劍的事情？』
  你也看到你的胸前已經被銀光貫穿............
   
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

