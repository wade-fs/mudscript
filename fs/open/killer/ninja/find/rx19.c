// open/killer/ninja/find/rx19.c
// 當玩家發生抉擇錯誤，就會受到嚴重精神傷害，退回最初點
#include "/open/open.h"
inherit ROOM;

void create ()
{
  set ("short", "心靈探索");
  set ("long", @LONG
  
  此時不走更待何時？利用幻星步快速切換到隊伍外圍，身影之快根本沒人發現。
  但是你想的實在太天真了，螳螂捕蟬，黃雀在後，
  一道劍氣橫過你的胸口，你的精神受到嚴重的打擊!!
  在你精神渙散前，才想到以前在秘密行動訓練中所提到的注意事項
  『一個超過五人的隊伍在潛行當中，必定是最明顯的一個目標
    在隊伍後方五丈之內，布下另一監視人員，進行反監視
    如此一來，將可以避免隊伍反而被跟蹤.....』
  唉....真是少壯不努力，老大徒傷悲...........
   
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

