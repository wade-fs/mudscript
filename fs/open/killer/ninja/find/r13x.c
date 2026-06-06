// open/killer/ninja/find/rx13.c
// 當玩家發生抉擇錯誤，就會受到嚴重精神傷害，退回最初點
#include "/open/open.h"
inherit ROOM;

void create ()
{
  set ("short", "心靈探索");
  set ("long", @LONG
  
  開玩笑，這麼強的老祖，你還擔心什魔，你決定跟老祖一起並肩作戰，
  順便看看還有沒有什麼東西可以挖，開玩笑，居然連分功\化影身法都清楚
  不好好搞清楚怎麼可以呢？搞不好還可以得到老祖親自傳授絕招.....
  老祖也為了全神灌注，而不願裡你，深知老祖個性與實力的柴榮已先行離去
  不久那股強大的壓迫感已經逼近，一道強大的劍氣搶先襲擊而來！！！
  前所未有的強大劍氣，直接由你身上貫穿而過，你根本無法反應.....
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

