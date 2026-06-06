// open/killer/ninja/find/rx10.c
// 當玩家發生抉擇錯誤，就會受到嚴重精神傷害，退回最初點
#include "/open/open.h"
inherit ROOM;

void create ()
{
  set ("short", "心靈探索");
  set ("long", @LONG
  
  為了避免干擾到過去的事情，你決定拒絕掉綠毛老祖要求。
  『抱歉，前輩，我不能幫助你，告辭!』你便轉身想要離去。
  豈知，老祖抓住你的手：『小子，沒有人可以拒絕我!!!』
  忽然，你覺得你體內的血液似乎由你體內飛奔而出........
  但是你卻沒有看到有任何血液流出？？但是柴容那失血過多的臉上，
  卻逐漸的出現血色.....在你眼前一黑之前....聽到老祖說
  『魔.氣.殺.....之....血變!』
  
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

