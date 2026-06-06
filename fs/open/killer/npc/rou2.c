// open/killer/npc/rou2.c	2001/12/11
// 這一個版本的柴榮是針對幻之忍殺開發出來的
// 因為柴榮將在幻之忍殺之後的殺手佔有很重要的部分
// 為了降低程式的複雜度，所以另外做一個版本
//修正錯字 by blazakira 2011/10/8

#include <ansi.h>
#include "/open/open.h"
inherit NPC;

string do_trial();
string ask_step();

int accept_object (object me,object ob)
{//到時候這裡要處理有關綠毛密令的部分，所以先不砍掉
  object ob2;

  if (me->query_temp("firstpart") != 11)
  {
    command ("say 神經病，你給我這個幹嘛！\n");
    return 0;
  }
  if(ob->query("id") == "green_ring") 
  {
     message_vision(" 柴榮將金鈴收下來，仔細的檢查了一下。\n",me);
     message_vision(" 點點頭說，沒錯，這就是失落十幾年的金鈴。\n",me);
     message_vision(" 就讓我傳授你分功\化影身法吧....\n",me);
     message_vision(" 說完後柴榮快速的將身法的要點指導給你，並且演練。\n",me);
     message_vision(" 因為你早有幻星步的基礎，所以很快的就大有領悟\n",me);
     me->set_skill("dark-steps",50);
     command("say 為了要通過東瀛神風，你可以使用清風術來度過。");
     command("say 你可以使用 perform dark-steps.wind-steps 來驅動。");
     command("say 我想到此，第一階段的謎題已經完成。");
     destruct(ob);
     me->set("ninja/firstpart",1);
     me->set("dark-steps/wind-steps",1);
     return 1;
  }
  return 0;
}

void create()
{
  set_name("柴榮",({"chil-rou","rou"}));
  set("long","傳說此人曾為魔教的一員，後來因故加入黑牙聯，又因故脫離。\n"+
    "\t因此擅長兩家之長，又會殺手密技--霸雨式。\n");
  set("gender","男性");
  set("class","poisoner");
  set("nickname", HIR "神秘殺手" NOR);
  set("combat_exp",1000000);
  set("attitude","heroism");
  set("age",27);
  set("str", 50);
  set("cor", 35);
  set("cps", 18);
  set("per", 30);
  set("int", 20);
  set("force",1000);
  set("max_force",800);
  set_skill("move",90);
  set_skill("force",60);
  set_skill("dodge",80);
  set_skill("parry",80);
  set_skill("poison",80);
  set_skill("whip",40);
  set_skill("throwing",100);
  set_skill("rain-throwing",110);
  set_skill("poisonforce",40);
  set("force_factor",10);
  set_skill("coldpoison",80);
  set_skill("nine-steps",80);
  map_skill("throwing","rain-throwing");
  map_skill("dodge","nine-steps");
  map_skill("move","nine-steps");
  set_skill("ming-snake",60);
  set("inquiry",([
    "試煉" : (: do_trial :),
    "特殊身法" : (: ask_step :),
  ]));
  setup();
  carry_object("/open/killer/obj/lustar")->set_amount(100);
  add_money("gold",20);
}

string do_trial()
{
  object me = this_player();

  if(!me->query("ninja/firstpart"))
  { //玩家必須要解過第一部份才可以解試煉的部分
    command("say 你想太多了，就連分功\化影都的清風術都沒學到，你想接受試煉？\n");
    return"say 好好的把該學的學到再說吧。\n";
  }
  else
  {
   	command("sm "+me->query("id"));
   	//移動到練妖壺內的世界
   	//me->move("/open/killer/ninja/trailbeginrm.c");
   	return "哼！不知道。\n";
  }
}

string ask_step()
{
  object me = this_player();

  if(me->query_temp("firstpart") ==11)
  { //玩家必須要解過第一部份才可以解試煉的部分
    command("say 想要知道？把綠毛金鈴給我再說。\n");
    return"give green_ring to rou\n";
  }
  else
  {
   	command("sm "+me->query("id"));
   	me->set_temp("firstpart",6);
   	command("say 我不知道，你滾吧！\n");
   	me->move("/open/killer/room/pillrm.c");
   	return "你別想知道!!!!\n";
  }
}

void init()
{
  object ob;
  ::init();
  if( interactive(ob = this_player())&& !is_fighting() ) {
    remove_call_out("greeting");
    call_out("greeting",1 , ob);
  }
}

void greeting(object ob)
{
  if((ob->query_temp ("firstpart") !=5) && (ob->query_temp ("firstpart") !=11))
  {
    command("sm "+ob->query("id"));
    command("say 你怎麼來到這裡的？說!!");
  }
  else
    command("say 找我幹嘛？\t");
}
