// open/killer/ninja/find/rx10.c
// 當玩家發生抉擇錯誤，就會受到嚴重精神傷害，退回最初點
#include "/open/open.h"
inherit ROOM;

void create ()
{
  set ("short", "心靈探索");
  set ("long", @LONG
  
  你朝著那群魔教徒走去,想說乾脆還是投降會比較好一點，畢竟他們應該可以活很久
  但是你卻忽略了，你卻不一定能活那麼久。因為，正當你想要說話的時候，
  對方的手中，卻對你灑出毒粉，讓你失去先機！！
  然後，所有人同時出手，在你還來不及反應的時候，已經眼前一黑
  
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

