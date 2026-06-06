//增加dancer新spell charming的quest要素 by blazakira 2010/10/16

#include <ansi.h>
#include "marksman.h"
inherit NPC;
inherit F_MASTER;
string s_att();
string ask_rock();
string sun1();
string sun2();
string sun3();
void create()
{
  set("class", "marksman");
  set_name("李廣", ({ "master lee", "master", "lee" }) );
  set("title","射日派第二代掌門人");
  set("nickname",HIC "心定穿石"NOR);
  set("gender", "男性");
  set("max_kee",5000);
  set("age", 55);
  set("attitude", "heroism");
  set("long","朝廷名將，有「百步穿楊」的射箭技術，更曾在一次打獵中，把箭射進石頭裡，天子為之讚嘆不已，
雖然射箭技巧舉世無雙，但仍心繫已失傳許\久的失傳箭術..\n");
  set("str", 18);
  set("cps", 30);
  set("per", 10);
  set("cor",30);
  set("int", 40);
  set("kar", 16);
  set("combat_exp",2000000);
  set("bellicosity",5000);
  set("force",8000);
  set("max_force",8000);
  set("max_atman",5000);
  set("atman",5000);
  set("force_factor",30);
  set("score", 200000);
  set_skill("force",80);
  set_skill("archery",120);
  set_skill("god-shooting",100);
  set_skill("magic",20);
  set_skill("move",70);
  set_skill("parry",70);
  set("functions/ten_kee/level",100);
  set("functions/m-archery/level",100);
  set_skill("dodge",70);
  set_skill("literate",40);
  set_skill("unarmed",20);
  set_skill("iceforce",100);
  set("no_lyssa",1);
  set_skill("rain-steps",100);
  set_skill("riding",80);
  map_skill("force", "iceforce");
  map_skill("dodge", "rain-steps");
  map_skill("parry", "rain-steps");
  map_skill("archery","god-shooting");
  map_skill("move","rain-steps");
  set("chat_chance_combat",100);
  set("chat_msg_combat", ({
    (: s_att :)
  }));
  create_family("射日派", 2, "掌門人");
  setup();
  carry_object(C_OBJ"/arrow-8");
  carry_object(C_OBJ"/dragon_bow")->wield();   
  set("inquiry", ([
    "百步穿楊"  :  (: ask_rock :),
    "失傳箭術"  :  (: sun1 :),
    "后羿的後裔":  (: sun2 :),
    "後裔"      :  (: sun2 :),
    "奇人"      :  (: sun3 :),
    "武林盟主"  : "去找龍雲飛。",
  ]));
  add_money("gold",10);
}

void init()
{
  add_action("do_shoot","shoot");
  ::init();
}

void attempt_apprentice(object ob)
{
  if(this_player()->query("class")!="marksman")
  {
    command("sigh");
    command("say 你不是射手﹐我不能收你。\n");
    return;
  }
  if((int)ob->query("str") <16 )
  {
    command("sigh");
    command("say 你的膂力不夠，拿起弓來一定會顫抖..\n敝人觀之"+ RANK_D->query_respect(ob) + "的資質似乎不宜！\n");
    return;
  }

  command("hmm");
  new(C_OBJ"/bow-1")->move(ob);
  command("say 給你把弓，可不要用不見啦!");   
  command("pat" + ob->query("id"));
  command("recruit "+ob->query("id"));
  message("system",HIR "李廣笑道 :\n
      "HIW"" +this_player()->name()+ ""NOR""HIR"拜入我門下 !\n
      他日必可成為一代神射手!\n
      成為武林至尊!!\n\n"NOR,users());
}

int accept_kill(object ob)
{
  if (this_object()->query_temp("quest/dancer/bewitching")!="ok")
  {
    command("say 老夫最近沒練武了，那就來動一動吧!");
    command("say 納命來!!");
    command("cmd holdup arrow with bow");
    kill_ob(ob);
    command("perform archery.ten_kee");
    command("supershoot");
  }
  else
  {
    command("cmd holdup arrow with bow");
    kill_ob(ob);
  }
  return 1;
}

int accept_fight(object ob)
{
  command("say 那好吧!!老夫就來會會你");
  command("cmd holdup arrow with bow");
  fight_ob(ob);
  command("perform archery.ten_kee");
  command("supershoot");
  return 1;
}

void heart_beat()
{
  object me,room,*target;
  int i,j;
  me=this_object();
  if( me->is_fighting() && random(100) > 60 && !me->query_temp("fast-dest") )
  {
    message_vision(HIC"\n李廣吃起藥丸補充血氣。\n"NOR,me); 
    me->receive_curing("kee",1500);
    me->receive_heal("kee",1500);
    me->delete_busy();
    me->clear_condition();
  }
  ::heart_beat();
}

void greeting(object ob)
{
  ob=this_player();
  if(ob->query("family/family_name")=="射日派")
  {
    if(!present("bow",ob))
    {
      new(C_OBJ"/bow-1")->move(ob);
      command("hmm");
      command("say 弓怎麼不見啦!!");
      command("say 再給你一把，不要弄丟啦!");
    }
  }
}

void die()                                                                 
{    
  object winner = query_temp("last_damage_from");

  tell_object(users(),HIW"
    忽然自"GRN"長沙城"HIW"之中射出一道白光，映著朝日，直竄達天際～～～\n
        射日派掌門人－"HIY"李廣"HIW"臨死前喟然嘆道～～～\n
            「啊～～～罷了...想我堂堂一名"HIC"飛將軍"HIW"，居然是如此不堪一擊...」\n
                名動天下的"HIC"「飛將軍」"HIY"李廣"HIW"，竟被"HIR"『"+winner->name()+"』"HIW"給一招擊斃於"HIY"廣義堂"HIW"內...\n
\n\n"NOR);
  ::die();
}

string s_att()
{
  if(random(2)) {
    command("perform archery.ten_kee");
    command("supershoot");
  } else {
    command("perform archery.m-archery");
    command("supershoot");
  }
}

string ask_rock()
{
  object me = this_player();
  if(me->query("class") != "marksman") return "射你大頭啦!!";
  if(!me->query_temp("find_arrow") && !me->query("marksman/punch_rock"))
  {
    me->set_temp("find_arrow",1);
    call_out("ask_rock1",10,me);
    return "嗯，那的確是值得自豪的功\夫，不過老夫最驕傲的，莫過於將箭射進石頭這件事了。";
  }else{
    return "射射射，你在這邊射什麼鳥啊  -___-||";
  }
}

int ask_rock1()
{
  object me = this_player();
  message_vision(HIR"李廣指著前方二十步左右的石頭。\n"NOR,me);
  call_out("ask_rock2",10,me);
  return 1;
}

int ask_rock2()
{
  object me = this_player();
  command("say 你若能像老夫當年一樣，將箭射(shoot)進石頭(rock)裡，老夫就傳你百步穿楊的功\夫。");
  me->set_temp("find_arrow",2);
  return 1;
}

int do_shoot(string arg)
{
  object me = this_player();
  if(arg == "rock")
  {
    if(me->query_temp("find_arrow") == 2)
    {
      message_vision(HIW"$N搭上箭，拉滿弓，「咻」的一聲射去，$N隱約見到石頭上插著一把箭。\n",me);
      call_out("shoot_rock1",10,me);
    }
  }else{
    message_vision(CYN"$N不要亂射啦，髒死了!!"NOR,me);
  }
  return 1;
}

int shoot_rock1()
{
  object me = this_player();
  message_vision(HIG"$N跑到石頭旁邊一看，發現插在石頭上的箭並不是自己的，
而剛剛自己所射的箭已經撞斷了箭頭，掉落在一旁。\n"NOR,me);
  message_vision(HIC"猶豫了一會兒，$N將兩支箭都收了起來。\n"NOR,me);
  new(C_OBJ"/good_arrow")->move(me);
  new(C_OBJ"/broken_arrow")->move(me);
  return 1;
}

int accept_object(object me,object obj)
{
  me = this_player();
  if(obj->query("id") == "broken arrow" && me->query_temp("find_arrow"))
  {
    command ("say 很好，你這個人非常誠實，我很喜歡，其實你射箭的技術已經爐火純青了，只是運勁功\夫尚未渾融而已。");
    command ("say 我這就傳你運勁發箭的法門，讓你的箭技更上一層樓。");
    message_vision(HIM"李廣對著$N指點了一番，$N豁然頓悟箇中奧妙，學會了"HIC"虛空馭天箭"HIM"之術。\n"NOR,me);
    message_vision("請以perform god-shooting.super-shooting使用並以help mark參考相關說明。\n"NOR,me);
    me->set_function("super-shooting",1);
    me->set("marksman/punch_rock",1);
    me->delete_temp("find_arrow");
  }else if(obj->query("id") == "good arrow" && me->query_temp("find_arrow"))
  {
    command ("say 唉，這箭明明就是我射的，你根本沒射中對吧。");
    command ("say 不過這代表你真的很想學這們功\夫，好吧!!我就教你吧!!");
    message_vision(HIM"李廣在$N面前演練了一遍架式，$N豁然頓悟箇中奧妙，學會了"HIC"虛空馭天箭"HIM"之術。\n"NOR,me);  
    me->set_function("super-shooting",21);
    message_vision("請以perform god-shooting.super-shooting使用並以help mark參考相關說明。\n",me);
    me->set("marksman/punch_rock",2);
    me->delete_temp("find_arrow");
  }else{
    command ("idle");
  }
  return 1;
}

string sun1()
{
  object me = this_player();
  int j,k;
  k = me->query_temp("ask-break-sun");
  j = me->query("functions/m-archery/level");
  if(!me) return"";
  if(me->query("family/family_name") != "射日派") return "你並非本派弟子，請勿過問。";
  if(me->query("break-sun")) return "你已經學到了，真是後生可畏啊～";
  if(!j || j<50) return "你的亂箭齊發還不夠熟練，無法體會更深一層的箭術!!";
  if(k) return "我說箭神的後裔啦!!";
  else {
    command("say 
話說上古時代有十個太陽，煩惱著先民的生活，當時一位箭術好手后羿將十個太陽
射下九個，解決了先民的煩惱，成為大英雄，而他所用箭招，至今已經失傳，據說
三百年前有位后羿的後裔曾學會其祖先的絕世箭術，但在他之後，已無人通曉...");
    me->set_temp("ask-break-sun",1);
  }
  return "";
}

string sun2()
{
  object me = this_player();
  int k;
  k = me->query_temp("ask-break-sun");
  if(!me) return"";
  if(me->query("family/family_name") != "射日派") return "你並非本派弟子，請勿過問。";
  if(k>1) return "奇人異士!!";
  if(me->query("break-sun")) return "我也很想見見啊～";
  if(!k) return "沒事問這做啥!?";
  else {
    command("say 
據信他的古厝就在長沙城附近，但是許\多人在這附近找了好久都一無所獲，日前我
聽說世上竟然還有一位奇人，能以古老的空間幻術，藉由扭曲的空間造成時空變異，
將人傳送到上古時代，不曉得此事究竟是真是假。");
    me->set_temp("ask-break-sun",2);
  }
  return "";
}

string sun3()
{
  object me = this_player();
  int k;
  k = me->query_temp("ask-break-sun");
  if(!me) return"";
  if(me->query("family/family_name") != "射日派") return "你並非本派弟子，請勿過問。";
  if(k>2) return "天靈靈地靈靈...!!";
  if(me->query("break-sun")) return "世上真是無奇不有...";
  if(!k || k<2) return "沒事問這做啥!?";
  else {
    command("say 
這個人的行蹤飄忽不定，很少人看過他，不過你可以往靈氣聚集的地方去找看看。
或許\找到他之後可以利用空間幻術回去后羿生活的時代，向他學習那失傳的箭術...");
    me->set_temp("ask-break-sun",3);
  }
  return "";
}
