// open/killer/ninja/find/rx25.c
// 當玩家發生抉擇錯誤，就會受到嚴重精神傷害，退回最初點
#include "/open/open.h"
inherit ROOM;

void create ()
{
  set ("short", "心靈探索");
  set ("long", @LONG
  
  你本來就是來探索的，還跟他客氣，不然怎麼知道分工化影之謎呢？
  所以你躡手躡腳的走到北方的墓，想要看看老祖到底再做什麼？
  但是居然沒有看到老祖在哪裡？怎麼可能？？？
  正當你懷疑的時候，背後傳來一聲歎氣聲：
  『唉....想不到連你也無法信任，.........』
  一股強大的魔氣在你體內爆發，讓你連反擊的機會都沒有....
   
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

