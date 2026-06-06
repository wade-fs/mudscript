// open/killer/ninja/find/rx20.c
// 當玩家發生抉擇錯誤，就會受到嚴重精神傷害，退回最初點
#include "/open/open.h"
inherit ROOM;

void create ()
{
  set ("short", "心靈探索");
  set ("long", @LONG
  
  魔氣殺在那個人身邊造成了強大的氣旋，似乎導致那人行動為之一滯
  然而其他的仙劍門徒，幾乎都離開他身邊有一丈之遠，
  你覺得這是絕佳的機會，腳採幻星步，抽離開隊伍往那人奔去。
  手中的暗器早已灌足強大的魔氣，並且再同一時間發射而出!
  然而那人身旁竟然有一股強大的防禦氣牆，將你的暗器全數反彈!
  逼不得已，趕緊利用手中的匕首將暗器一一擊落，
  正當你鬆了一口氣之時，一道強大的劍氣穿身而過，你眼前一黑!
  
   
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

