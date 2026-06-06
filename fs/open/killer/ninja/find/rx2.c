// open/killer/ninja/find/rx2.c
// 當玩家發生抉擇錯誤，就會受到嚴重精神傷害，退回最初點
#include "/open/open.h"
inherit ROOM;

void create ()
{
  set ("short", "心靈探索");
  set ("long", @LONG
     你不管柴榮是不是有辦法擋下這一招，立刻發出暗器，擋下這一招
     但是沒想到在暗器發出的同時，柴榮的身影突然消失，然後出現在你的背後
     
     『你到底是誰？你是不是東瀛派來的間諜？!!』
     正當你想回答的時候，剛才那條黑影宛如靈蛇一般，貫穿的了你的身體!!!!
     你的精神受到嚴重創傷!!神志開始昏迷不清..........

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

