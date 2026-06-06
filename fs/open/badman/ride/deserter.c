#include "/open/open.h"
#include <ansi.h>

inherit NPC;

string do_want();
string do_ask();
void create()
{
  set_name("沙老",({ "desert elder","desert","elder"}));
  set("title","塞外漠民");
  set("gender", "男性");
  set("age",65);
  set("attitude", "peaceful");
  set("no_kill",1);
  set("no_fight",1);
  set("long","一個在炎熱的沙漠中獨自生活的老頭。他正在灑掃堆積
在帳篷前的吹沙。從他的膚色及五官分布來看，應該是
來自塞北大漠的住民。\n");
  set("chat_chance",6);
  set("chat_msg", ({
  "唉，又吹了這麼多沙子，真是該死的駱駝！\n",
  }) );
  set("inquiry",([
  "駱駝" : (: do_ask :),
  ]));

setup();
}

string do_ask()
{
  int me;
  object who;
  who = this_player();
  if (who->query("quests/r_camel",1)) {
  return "真感謝你幫我馴了駱駝！\n"; 
  }
  else if (who->query("quests/w_camel",1)) {
  return "你要跟我要（want）駱駝嗎？\n";
  }
  else if (who->query_temp("marks/f_c",1)) {
  return "我不是跟你講過了嗎？\n";
  }
  else {
  who->set_temp("marks/f_c",1);
  who->set_temp("marks/f_c_ent",1);
  return "什麼駱駝？唉，這說來話長啊
！老朽暫不將原由告訴你，在老朽身後帳
篷的木板床中，你去將木板掀開。裡頭有
條暗道，暗道盡頭處老朽養著一匹駱駝。
這駱駝可厲害了！別的駱會吐吐口水就罷
了，我這駱又叫塵沙駱，可是從西方傳來
的珍奇至寶！牠啥不會，就吹沙吹得緊！
偶而呢，也會吐吐砂粒，砂粒一多，就成
了道牆。這牆可謂刀槍不入，能擋神兵！
但這駱就是不聽話。少俠看你年紀尚可，
但臉色異常紅潤，想必功夫十分到家。想
來這也是個緣份，您就進去蓬中，掀開板
子，入了暗道，看能否馴了這匹駱駝吧！\n";
  }
}

void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player())&& !is_fighting() )
 {
        remove_call_out("greeting");
        call_out("greeting",1 , ob);
 }
}

void greeting(object ob)
{
  if (ob->query("quests/r_camel",1))
  {
   message_vision("少俠真是本事高啊！\n",ob);
  }
  else if (ob->query("quests/w_camel",1))
  {
   message_vision("少俠想要（want）騎駱嗎？\n",ob);
  }
  else if( ob->query("class")==!"bandit" && ob->query_temp("marks/f_camel",1))
  {
   message_vision("少俠本領果然足夠！
老朽沒啥麼好送的，這有幾十兩銀子，少俠就收下吧！\n",ob);
   ob->add_money("gold",25);
   ob->set("quests/r_camel",1);
  }
  else if (ob->query("class")=="bandit" && ob->query_temp("marks/f_camel",1))
  {
   message_vision("沒想到少俠果真馴了這駱駝！
看樣子這也是個緣份，老朽這有個不中聽的建議，望請少俠採納，
老朽這駱取回來已過相當時日。本來呢，這駱是老朽要騎的，無
奈武功不濟，馴不得這駱。如今少俠既得這緣份，就算和老朽結
識一場，少俠想騎駱呢，便來跟老朽講一聲（want），自不會跟
少俠做何為難的！好罷？\n",ob);
  ob->set("quests/w_camel",1);
  }
  else if (ob->query_temp("marks/k_camel",1))
  {
   message_vision("唉喲！少俠居然把牠殺了！\n",ob);
   message_vision("你....你這樣子我該怎麼辦啊？\n",ob);
   this_object()->kill_ob(ob);
  }
}

void die()
 {
  object killer;
  killer=query_temp("last_damage_from");
  message_vision("啊，少俠武功果。。。果然高強啊。。。。\n",killer);
  killer->delete_temp("marks/k_camel");
  ::die();
 }
