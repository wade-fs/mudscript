// open/killer/ninja/find/r13b.c
#include <ansi.h>
#include "/open/open.h"
inherit ROOM;

void create ()
{
  string long;
  set ("short", "心靈探索");
  long = "\n"
"     為了表示對老祖的尊重，所以你決定在原地好好等待，\n"
HIG"     沒有多久後，老祖由北方回來，欣慰的對你說：\n"
"     『看來你真的是可以信任的人....不，應該說是精神體吧\n"
"     既然小如會施展心靈探索，代表你是值得信任的，事實也證明如此\n"
"     我在北方設下一個結界，你回去後，只要到墓碑那裡\n"
"     唸出(intone) 《耶西西凹安骯》後你將可以取得綠毛金鈴\n"
"     有了它之後，柴榮才會教你，分功\化影身法........\n"
"     快走吧....我想你是對付不了那個老鬼的.........』\n"NOR
"     你本想繼續奮戰的，但是精神體似乎被招喚，而逐漸抽離開這個世界。\n"
  "\n";
  set("long", long);
  set("no_transmit",2);
  setup();
}

//基本上，這是b部分，有關分功化影的部分
//但是b部分是，有關 殺手的一些基本設定的介紹 所以只好要玩家在解一次
void init()
{
    object ob=this_player();
    if( interactive(ob))
	    remove_call_out("greeting");
  
  if (ob->query("ninja/bpart") != 1)
  	ob->set("ninja/bpart",1);
  	
  //代表玩家還不知道，a部分的線索，所以要玩家再解
  if (ob->query("ninja/apart") != 1)
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
     tell_object(ob,"雖然綠毛金鈴由來已經清楚\n");
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
