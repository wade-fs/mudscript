// open/killer/ninja/find/rx4.c
// 當玩家發生抉擇錯誤，就會受到嚴重精神傷害，退回最初點
#include "/open/open.h"
inherit ROOM;

void create ()
{
  set ("short", "心靈探索");
  set ("long", @LONG
     為了避免暗器的破空聲導致，你的所在被發現，且自己用身體去擋好像有點笨
     所以你運起殺手的超上級招式『魔氣殺』，想要將此黑影擋下來......
     然而當你氣走全身的時候，整個精神體似乎失去控制？!!!
     看來這對柴榮的心靈衝擊太大？!!   你的精神體開始潰散.......

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

