// open/killer/ninja/find/rx5.c
// 當玩家發生抉擇錯誤，就會受到嚴重精神傷害，退回最初點
#include "/open/open.h"
inherit ROOM;

void create ()
{
  set ("short", "心靈探索");
  set ("long", @LONG
	雞婆的你，決定出面當個和事老，看看順便有沒有油水可以撈？!
	想不到你的身影才剛剛出現在兩人面前的時候，那道黑影穿過你的身體!!
	而且柴榮也一掌將你擊飛：『卑鄙小人，居然敢探查秘密？!』
	精神體在潰散中的你，怎麼也想不到，這兩人居然這麼凶暴？........

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

