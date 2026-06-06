// open/killer/ninja/find/rx6.c
// 當玩家發生抉擇錯誤，就會受到嚴重精神傷害，退回最初點
#include "/open/open.h"
inherit ROOM;

void create ()
{
  set ("short", "心靈探索");
  set ("long", @LONG
	你根本不敢回頭看背後的人，僅小聲得回答了：『我在看戲.....』
	『看戲？哈哈....看戲當然要到前面才好看呀!!!』
	
	話語一落，你感到一陣強大的勁力，將你推到兩人之間!!
	
	並且聽到『有人要看戲哦....你們好好表演呀!!!!』
	
	你根本不敢去看兩人的表情，其實也沒什麼機會看啦......
	
	因為你已經眼前一黑................................

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

