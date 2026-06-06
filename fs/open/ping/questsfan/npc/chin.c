//by dhk 2000.5.23
//增加少林後山任務的起始線索 by blazakira 2011/3/7
#include "/open/open.h"
#include <ansi.h>
inherit F_VENDOR;

void create()
{
  set_name("秦厲害",({"vendor chin","vendor","chin"}));
  set("title","" + HIR + "火龍神探" + NOR + "");
  set("gender", "男性" );
  set("age", 27);
  set("long", @LONG
四處設攤賣些不知道〔真的〕還是〔假的〕的情報的人,你可以列出(list)他賣些什麼...
LONG
  );
  set("combat_exp",800);
  set("no_fight",1);
  set("no_kill",1);
  set("attitude", "friendly");
  set_skill("dodge", 25);
  set_skill("hammer", 17);
  set_skill("parry", 27);
  set("vendor_goods", ({
    "/open/ping/questsfan/obj/paper1",
    "/open/doctor/doctor_book/obj/paper1",
  }) );
  setup();
  add_money("gold",135);
}

void greeting(object ob)
{
  int gender,per;
  gender = 0;
  per = ob->query_per();
  if( !ob || environment(ob) != environment() ) return;
  if( ob->query("gender") == "女性")
    gender = 1;
  switch( random(3) ) {
    case 0:
    if( per < 18 && gender)
      say("秦厲害靠近你小聲的說: 唉! "+ob->name(1)
         +",也許\妳該去一下媚登峰!\n");

      say("秦厲害靠近你小聲的說: 這位"+RANK_D->query_respect(ob)
         +"其實我是狂想情報總經銷!\n");
      break;
    case 1:
    if( per > 22 )
      say("秦厲害嘶聲么\喝道: "+ob->name(1)
         +"長的好像電影明星喔!\n");

      say("秦厲害嘶聲么\喝道: "+RANK_D->query_respect(ob)
         +",我知道好多神秘的內幕呦!! 要買嗎!?\n");
      break;
    case 2:
    if( per < 15)
      say("秦厲害小聲的說: "+ob->name(1)+",請具備一點公德心好嗎? 人長的"
         +"醜就不要上街嚇人.\n");
    if( per > 26 && gender)
      say("秦厲害讚嘆道: 哇! 大美女"+ob->name(1)
         +",妳可真是天仙下凡呀!!\n");

      say("秦厲害高聲喊道: 端午節大優待,"+RANK_D->query_respect(ob)
         +"要的話，我可以算便宜一點喔!一份1000 gold!!!\n");
      break;
   }
}

void init()
{ 
  ::init();
  add_action("do_nod","nod");
  remove_call_out("check_tensanmark");
  call_out("check_tensanmark",1,this_player());
}

void check_tensanmark(object me)
{
  if(present("tensan mark",me))
  {
    command("say 這不是天山通行令嗎？我早就想進天山看看但一直不得其門而入。");
    command("hmm");
    command("say 我用高價向你收購，你願意割愛賣給我嗎？");
    me->set_temp("tensan/wait_answer",1);
  }
}

int do_nod()
{
  object me,ob,money;
  me = this_player();
  ob = present("tensan mark",me);
  money=new("/obj/money/diamond");
  money->set_amount(1+random(3));
  if(me->query_temp("tensan/wait_answer")==1)
  {
    command("say 太好了！那就銀貨兩契不得反悔，拿去吧！這是你應得的。");
    destruct(ob);
    money->move(me);
    me->delete_temp("tensan/wait_answer",1);
  }
  return 0;
}
