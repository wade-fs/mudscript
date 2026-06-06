#include <ansi.h>
#include "/open/open.h"
inherit NPC;
string ask_yao();
string ask_quest();
string ask_broken();
string ask_ball();
string ask_gball();
string ask_fireball();
string ask_waterball();
string ask_woodball();
string ask_soilball();
void create()
{
        set_name(HIR + "刀神"+HIC"龍震元" + NOR,({"blademan","man"}));
        set("long","仙魔戰中刀神元靈所換化的守護神,負責阻止閒雜人等進入魔封地。\n");
        set("gender","男性");
        set("class","blademan");
        set("combat_exp",10000000);
        set("attitude","heroism");
        set("env/連擊","YES");
        set("age", 70);
        set("str", 35);
        set("cor", 30);
        set("cps", 30);
        set("per", 40);
        set("int", 40);
        set("max_gin", 30000);
        set("gin", 30000);
        set("max_kee", 50000);
        set("kee", 50000);
        set("max_sen", 30000);
        set("sen", 30000);
        set("max_force",40000);
        set("force",40000);
        set("bellicosity",10000);
        set("functions/fight/level",100);
        set("functions/gold-dest/level",100);
        set_temp("apply/armor",100);
        set_skill("literate",40);
        set_skill("magic",120);
        set_skill("spells",120);
        set_skill("move",120);
        set_skill("force",290);
        set_skill("dodge",160);
        set_skill("unarmed",450);
        set_skill("celestrike",300);
        set_skill("parry",190);
        set_skill("blade",220);
        set_skill("gold-blade",100);
        set_skill("riding",200);
        set_skill("fly-steps",100);
        set_skill("fly-blade",200);
        set_skill("fiendforce",200);
        set_skill("cure", 100);
        map_skill("blade","fly-blade");
        map_skill("parry","fly-blade");
        map_skill("dodge","fly-steps");
        map_skill("move","fly-steps");
        map_skill("force","fiendforce");
        map_skill("unarmed","celestrike");
        set_temp("apply/armor",100);
        set("force_factor",20);
        set("chat_chance_combat",80);
        set("family/family_name","金刀門");
        set("inquiry",([
  "血魔" : (:ask_quest:),
  "逍遙子" : (:ask_yao:),
  "開天三才陣" : "開天三才陣乃是當年逍遙子為封印血魔而去向大破魔師於蘭天武習得的陣法，是一極強的封印術法。",
  "破陣之道" : (:ask_broken:),
  "元力晶珠" : (:ask_ball:),
  "晶珠所在" : (:ask_gball:),
  "尋找晶珠" : (:ask_fireball:),
  "連陽劍晶珠" : (:ask_waterball:),
        ]));
        set("chat_chance_combat",80);
        setup();
        carry_object("/daemon/class/blademan/obj/gold-blade")->wield();
        carry_object("/open/gsword/obj1/bladeball.c");
}
void heart_beat()
{
     if( is_fighting()&& is_busy() && random(50)>10)
     {
        enemy=query_enemy();
         if( random(50)>10 )
          {
          delete_busy();
          message_vision(HIW + "雷虎聖者大喊:刀神附體..破封殺敵!!\n只見無數光芒向其聚集....瞬間衝破被封之穴道\n" + NOR);
        }
  }
::heart_beat();
}

int accept_fight(object who)
{
 command("cmd god_kee");
 command("perform fiendforce.fight");
 fight_ob(who);
 return 1;
}
int accept_kill(object who)
{
 command("say 這是你自找的.....！\n");
 command("cmd god_kee");
 command("perform fiendforce.fight");
 set("have_kill_me",1);
 kill_ob(who);
 return 1;
}
 void die()
{
   object winner = query_temp("last_damage_from");
   int i;
   mapping skl;
   i=sizeof(skl);
//      if(winner->query("family/family_name")=="仙劍派" )
//   winner->set_temp("killtiger",1);
if (winner->query_temp("swordquest/findball")<7 )
{
tell_object(winner,HIC + "\n
唉~~無奈..狂想..世界的未..來.... .... ....。\n" + NOR);
::die();
}
else
{
  tell_object(winner,HIC + "\n
  一代新人..換舊人，既然你已可殺敗我，那我想你已經擁有足夠能力判斷是非..狂想..世界的未..來就操控在....你的決定了。\n" + NOR);
  destruct (this_object ());
}
}
string ask_yao()
{
  return ("你說逍遙子好友阿，在百年前的仙魔大戰後，就已經消失無蹤了!!");
 }

string ask_quest()
{
  return ("本陣之宗旨便在困住血魔這萬惡魔頭!!然則隨著開天三靈器靈力的消逝，此開天三才陣封印力量亦大幅降低。");
}

string ask_broken()
 {
  this_player()->set_temp("swordquest/ball",1);
  return ("欲破開天三才陣，必須收集開天三靈器之元力晶珠方有機會破陣。");
}
string ask_ball()
{
 if(!this_player()->query_temp("swordquest/ball"))
 {
  return ("聳了聳肩﹐很抱歉地說﹕無可奉告。");
  }
 else
  {
  this_player()->set_temp("swordquest/ball",2);
  return ("元力晶珠為三靈器靈力之來源，然則因封印血魔所需，因此在三靈器流傳狂想世界大陸時，晶珠早已不在靈器中，故三靈器並無法發揮應有之威力。");
 }
}
string ask_gball()
{
 if(this_player()->query_temp("swordquest/ball")!=2)
 {
  return ("聳了聳肩﹐很抱歉地說﹕無可奉告。");
  }
 else
  {
  this_player()->set_temp("swordquest/ball",3);
  return ("元力晶珠在逍遙子架構完開天三才陣後，隨著逍遙子的消失已經失去消息，但是你可以試試看去狂想世界搜尋，如果需要的話你可以在詢問我有關[尋找晶珠]的事，我會送你回狂想大陸。");
}
}
string ask_fireball()
{
 if(this_player()->query_temp("swordquest/ball")!=3)
 {
  return ("聳了聳肩﹐很抱歉地說﹕無可奉告。");
  }
  else if (!this_player()->query("swordquest/findball"))
  {
   this_player()->set_temp("swordtime",1);
   this_player()->apply_condition("swordtime",50);
   this_player()->set_temp("swordquest/fball",1);
   this_player()->delete_temp("swordquest/ball");
   this_player()->move("/open/common/room/inn.c");
   return ("嗯，你現在已經回到狂想世界了，記住，你要找的是夜千鳥晶珠，而你的時間只有一個時辰，屆時我會將你召回!!");
  }
 else return ("你不是找過了!!");

}


string ask_waterball()
{
 if(!this_player()->query_temp("swordquest/fball"))
 {
  return ("聳了聳肩﹐很抱歉地說﹕無可奉告。");
  }
 else if ((this_player()->query_temp("swordquest/findball"))<7)
  return ("....給你時間你做不好，晶珠在我身上，你除了殺了我之外你沒機會拿到晶珠!!");
 else
  {
  return ("嗯﹐做的好~現在..這是你最後一個試練了!!殺敗我你便能進入");
  }
}

