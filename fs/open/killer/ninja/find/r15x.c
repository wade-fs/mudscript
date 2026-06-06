// open/killer/ninja/find/rx15.c
//『』
// 當玩家發生抉擇錯誤，就會受到嚴重精神傷害，退回最初點
#include "/open/open.h"
inherit ROOM;

void create ()
{
  set ("short", "心靈探索");
  set ("long", @LONG
  
  在眾人圍攻之下，只好各自保命，各出奇招看看是否可以殺出一條血路
  但是沒多久，你已經離兩人越來越遠，曾幾何時就連金刀武士也找上你了？
  想不到魔教徒跟金刀武士的聯手，居然可以發揮強大的攻防能力，
  讓你就算使出全力也逐漸落居下風，看著自己的鮮血逐漸往外流
  讓你很難相信，這樣的痛楚，應該只是幻覺.....你的眼前一黑.........
  
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

