// open/killer/ninja/find/rx14.c
// 當玩家發生抉擇錯誤，就會受到嚴重精神傷害，退回最初點
#include "/open/open.h"
inherit ROOM;

void create ()
{
  set ("short", "心靈探索");
  set ("long", @LONG
  
  既然連老祖都對付不了的人，你留下來也僅僅是炮灰而已，所以當然快走
  但是走了沒幾步後，覺得有戲不看多可惜呀.........
  目送柴榮離去後，你躲在不遠的樹上看戲......
  然而沒多久，那股強大的氣息的主人，已經來到附近，
  在人影還沒到之前，一股強大的劍氣已經襲擊而來！！！
  雖然你離老祖有很遠的一段距離，但是依舊被強大的劍氣波及到！！
  
  在你眼前一黑之前，隱隱約約聽到老祖說
  『太小看我了吧，居然才用仙劍後九式的第五式對我......』
  
  仙劍後九式？？？仙劍不是才有後三式而已嗎？？？  
  
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

