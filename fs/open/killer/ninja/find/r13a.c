// open/killer/ninja/find/r13a.c
#include <ansi.h>
#include "/open/open.h"
inherit ROOM;

void create ()
{
  string long;
  set ("short", "心靈探索");
  long = "\n"
"     你看準對手的漏洞，利用幻星步法邊戰邊走切近兩人，\n"
"     當你一起加入戰局之後，兩人的壓力頓時減輕......\n"
"     葉秀殺趁機連續發出霸與遮魂之霸雨式，漫天的星點將對手逼退\n"
"     柴榮因為缺乏真.黑牙神功的推動，所以逼近對手將魔氣逼入對手體內\n"
"     柴榮見到葉秀殺靠內力驅動霸雨式，內心突然有所領悟......\n"
HIY + "     『小殺，幫我逼退對手!』兩人心意相連不需多加解釋，\n" + NOR
"     葉秀殺立刻將手邊的暗器配合霸雨式一起射出去，將身邊的敵人逼退\n"
"     柴榮趁此空隙，將魔氣灌注暗器之上，使用霸雨式的手法將暗器射出\n"
"     這時，你在熟悉不過『魔氣殺』由柴榮發出!!.......\n"
"     魔氣殺由柴榮全力發出果然不同凡響，身邊的敵人一一倒下.......\n"
"     剩下的敵人也畏懼這樣的威力而紛紛溜走...原來這就是魔氣殺的由來？\n"
"     全力施展的柴榮，這時候也無力的倒下來了....\n"
"     葉秀殺趕緊扶住柴榮，並且朝你走了過來...........\n"
"     雖然你想走近葉秀殺，但是精神體似乎被招喚，而逐漸抽離開這個世界。\n"
  "\n";
  set("long", long);
  set("no_transmit",2);
  setup();
}

//基本上，這是a部分，有關 殺手的一些基本設定的介紹
//但是b部分是有關分功化影的部分，所以只好要玩家在解一次
void init()
{
    object ob=this_player();
    if( interactive(ob))
	    remove_call_out("greeting");
  
  if (ob->query("ninja/apart") != 1)
  	ob->set("ninja/apart",1);
  //代表玩家還不知道，b部分的線索，所以要玩家再解
  if (ob->query("ninja/bpart") != 1)
  	call_out("greeting",5 , ob);   
  else
  {
  	call_out("finished",5 , ob);
  }  	
}

void greeting(object ob)
{
   if( ob->query_temp("firstpart")== 8)    
   { 
     tell_object(ob,"雖然這些招式的由來已經清楚\n");
     tell_object(ob,"但是你似乎有漏掉一些線索，再探索另一部分吧\n");
     ob->move(__DIR__"r1.c");
   }
    else 
     ob->move(__DIR__"r1.c");
}

void finished(object ob)
{
   if( ob->query_temp("firstpart")== 8)    
   {
     ob->set_temp("firstpart",9);
     tell_object(ob,"所有的歷史與線索已經探查完成。 \n");
     tell_object(ob,"看來要先去把綠毛金鈴找出來了。\n");
     ob->move("/open/killer/room/pillrm.c");
   }
   else 
     ob->move(__DIR__"r1.c");
}

