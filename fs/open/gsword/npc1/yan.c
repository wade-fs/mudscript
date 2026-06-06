inherit NPC;
#include <ansi.h>
#include "/open/open.h"
int ask_sword();
int ask_tesin();
int ask_kking();
int ask_roger();
int ask_array();
int ask_fu();
int ask_shasword();
string ask_ball();
void create()
{
        set("title","仙劍派第二代弟子"),
        set_name("風青雲",({"yan"}));
        set("nickname",HIR"劍如迴陽"NOR);
        set("class","swordsman");
        create_family("仙劍派",2,"長老");
        set("family/master_name","逍遙子");
        set("family/family_name","仙劍派");
        set("attitude","heroism");
        set("env/連擊","YES");
        set("gender","男性");
        set("age",87);
        set("str",50);
        set("con", 44);
        set("int", 60);
        set("cps", 48);
        set("cor", 48);    
        set("long","他是仙劍派第二代弟子，鄭士欣之師叔，正為對抗血魔而勤練劍術。\n");
        set("combat_exp",4000000);
        set("max_gin",10000);
        set("gin",10000);
        set("max_kee",30000);
        set("max_force",10000);
        set("force",10000);
        set("kee",30000);
        set("max_sen",10000);
        set("sen",10000);
        set("functions/swordkee/level",100);
        set("functions/sha_kee/level",100);
        set("functions/sunswordkee/level",100);
        set_skill("dodge",100);
        set_skill("unarmed",90);
        set_skill("parry",120);
        set_skill("sword",120);
        set_skill("sun_fire_sword",100);
        set_skill("sha-steps",100);
        set_skill("shaforce",150);
        set_skill("force",130);
        set_skill("array",100);
        set_skill("sha-array",100);
        map_skill("array","sha-array");
        map_skill("dodge","sha-steps");
        map_skill("move","sha-steps");
        map_skill("force","shaforce");
        map_skill("sword","sun_fire_sword");
        map_skill("parry","sun_fire_sword");
        set("force_factor",20);
        set("inquiry",([
  "仙劍連陽" : (: ask_sword :),
  "天門奇陣" : (:ask_array:),
  "李夢枕" : (:ask_roger:),
  "連陽七絕斬" : (:ask_fu:),
  "龍鐵心" : (: ask_tesin :),
  "血魔" : "當年就為了誅滅這荼毒武林的魔王,而使當時武林數大高手皆先後消失…當然包括了師父逍遙子",
  "開天三靈器" : "開天三靈器是當初師父為了對付血魔請人打造，聽說要開封印需靠三派傳人，配合三靈器才能開啟呢~",
  "逍遙子" : "就是師父嘛..當年在一次偶然間..師父傳我幾招的劍招..也就是我前一陣子傳給你的禁斷連陽七訣…這只是師父絕學的一部份..",
  "仙劍峽谷" : (:ask_shasword:),
  "連陽劍晶珠" : (:ask_ball:),
]));
set("get_sha_sp", 1);
set("quests/sunfire",1);
set("chat_msg_combat",({
        (: perform_action,"sun_fire_sword.sunswordkee" :)
  }));
        setup();
carry_object("/open/gsword/obj/dragon-sword.c")->wield();
carry_object("/open/gsword/obj1/ring.c")->wear();
carry_object("/open/gsword/obj/dragon-cloth.c")->wear();
        add_money("gold",5);
}
int accept_fight(object who)
{
 fight_ob(who);
 command("perform sun_fire_sword.sunswordkee");
 return 1;
}
int accept_kill(object who)
{
command("say 讓你知道連陽劍的厲害！\n");
set("have_kill_me",1);
 kill_ob(who);
command("perform sun_fire_sword.sunswordkee");
return 1;
}
void init() {
  object obj;
  ::init();
  if(interactive(obj=this_player()) && !is_fighting())
     {
      remove_call_out("greeting");
      call_out("greeting",1,obj);
     }
}

void greeting(object ob)
{
        command("hmm");
        command("wear all");
}

int ask_sword()
{
  object me;
  me=this_player();

command("say 那是師父的絕世寶劍ㄚ..由於斬妖無數..故已成為妖魔的剋星..不過為封印血魔..已將其分鑄成開天三靈器…我想你一定知道..。\n ");

       return 1;
}
int ask_tesin()
{
  object me;
  me=this_player();
  command("say 劍師龍鐵心也是在當年大戰後消失的英雄之一..不過我確定他在魔域。 ");
  return 1;
}

int ask_fu()
{
  object me=this_player();
  if (me->query("quests/sunfire")==1)
  command ("say 你不是已經會了?");
  else if (me->query("quests/yan")<5)
  {
  command ("say 連陽七絕斬..乃是我囚困於焚天魔域時領悟出來的...。");
  command ("say 如果你想學..你得通過仙劍峽谷，並通試練者武試..你才有資格跟我學連陽七絕斬。");
  if (me->query("quests/yan")<1) me->set("quests/yan",1);
  }
  else if(me->query("quests/yan")==5)
  {
  command ("say 既然你都得到認證了...那我就把連陽七絕斬的要領跟你說...。");
  message("system",HIY"風青雲開始將連陽七絕斬的基本功\夫傳授於"+this_player()->name()+"。\n"NOR,users());
  message_vision("$N隨著風青雲的指導將連陽七絕斬演練了一遍。\n"NOR,me);
  command ("say 以後你可以利用perform sun_fire_sword.sunswordkee 在戰鬥中使出連陽七絕斬..。");
  me->set("quests/sunfire",1);
  }
}
int ask_shasword()
{
 object me=this_player();
 command ("say 仙劍峽谷乃仙劍祖傳練劍之處..由於極為隱密..因此已經漸被淡忘.。");
 command ("say 而我也僅僅記得他在蜀山附近...確實地點..你得自行前往蜀山尋找。");
 me->set_temp("quests/yan",1);

}

int ask_array()
{
object me=this_player();
// if(!me->query("quests/sblood")) return 1;
// else

// {
command("say 天門奇陣阿....");
command("say 我在當初我到魔域就是為了要找天門奇陣的下落,就在我發現線索時,中了焚天魔王的陷阱，才會被焚天魔王所擒，至於天門奇陣真正的下落，我想..你可以自行前往魔域調查..但是據說要進入此陣需要許\多的準備，非常人所能進入的。");
// }
}
int ask_roger()
{
command("say 李夢枕....這個人跟仙劍派似乎有極大的淵源..我曾在魔域遇見過他..此人乃是武林一大傳奇，據說他是金風細雨樓大樓主，但是看他的打扮，似乎已經再外流浪許\久了...");
return 1;
}
string ask_ball()
{
 if(!this_player()->query_temp("swordtime"))
 {
  return ("聳了聳肩﹐很抱歉地說﹕無可奉告。");
  }
 else
  {
  if (this_player()->query("class")=="swordsman" && this_player()->query_temp("swordquest/findball")==2)
    {
    this_player()->set_temp("swordquest/findball",3);
    return ("連陽劍晶珠為連陽劍靈力之來源，先前曾聽李孟枕說過說，晶珠在他手上，然則，李夢枕卻已經變成武林神話了!!\n");
   }
else return ("聳了聳肩﹐很抱歉地說﹕無可奉告。");
 }
}

 void die()
{
   object winner = query_temp("last_damage_from");
if (winner->query("bloodsword")==2)
   {
   tell_object(winner,HIC"\n 唉~~無奈..狂想..世界的未..來...... ....。\n"NOR);
   winner->set_temp("ko_yan",1);
   }
 ::die();
}

