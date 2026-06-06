//多加一個御蜂術...by firedancer ...11/3 2000//
//加入學習hellfire的設限,2000.10.16   firedancer //
//master_yua.c //cgy
//加入聖火進階解謎要素    by frequency 2003 May
//增加新手quest 尋找武林盟主的下落 by blazakira

#include <ansi.h>
#include "/open/open.h"
inherit NPC;
inherit F_MASTER;

string magic();
string ask_get_dan_sp();
string ask_get_meteor();
string ask_ribbon();
string ask_set_allow_hellfire();
string ask_orderbee();
string ask_mirror();
string ask_title();
string ask_crystal();
string ask_moon();

void create()
{
  object ob;
  set_name("月牙兒",({"master yua","yua"}));
  set("long","她是鏡月島二位美麗的島主之一，擅長舞蹈，據說
她的舞蹈之美會令人以為仙女下凡身處仙境。\n");
  set("gender","女性");
  set("class","dancer");
  set("nickname","霓裳仙子");
  set("combat_exp",5000000);
  set("attitude","heroism");
  set("allow_hellfire",1);
  set("age",20);
  set("str", 34);
  set("cor", 30);
  set("cps", 50);
  set("per", 24);
  set("int", 40);
  set("adv_dancer",1);
//  set("kee",16000);
  set("max_kee",16000);
//  set("gin",16000);
  set("max_gin",16000);
//  set("sen",16000);
  set("max_sen",16000);
  set("atman",20000);
  set("max_atman",20000);
  set("mana",14000);
  set("max_mana",14000);
  set("force",2000);
  set("max_force",2000);
  set_skill("array",60);
  set_skill("parry",60);
  set_skill("spells",50);
  set_skill("magic",120);
  set_skill("cure",60);
  set_skill("force",60);
  set_skill("literate",70);
  set_skill("move",90);
  set_skill("dodge",100);
  set_skill("sword",50);
  set_skill("unarmed",70);
  set_skill("paull-steps",130);
  set_skill("dremagic",100);
  set_skill("order-bee",120);
  set_skill("dreamforce",90);
  set_skill("dreamdance",100);
  map_skill("magic","dremagic");
  map_skill("dodge","paull-steps");
  map_skill("force","dreamforce");
  map_skill("move","paull-steps");
  map_skill("unarmed","dreamdance");
  set_temp("apply/armor",70);
  set("get_dan_sp",1);
  set("spells/reflection/level",100);
  set("spells/confuse/level",100);
  set("spells/fireball/level",100);
  set("spells/hellfire/level",75);
  set("spells/thunder/level",100);
  set("spells/mirror/level",100);
  set("spells/firedance/level",100);
  set("spells/dreamwings/level",1);

  set("force_factor",30);
  setup();
  create_family("夜夢小築",3,"宮主");
  carry_object("/open/dancer/obj/maple_ribbon.c")->wield();
  carry_object("/open/dancer/obj/yuaboots.c")->wear();
  carry_object("/open/dancer/obj/yuawaist.c")->wear();
//  add_money("diamond",1);
//  ob->set_amount(50);
  set("inquiry", ([
    "傅劍寒"      : "你說的是神龍山莊莊主傅劍寒嗎??他是我傾慕的偶像耶!!",
    "夜夢雙妖"    : "是夜夢雙星的師父。",
    "夜夢雙星"    : "哈!!那兩個肉腳，上次跑來想偷東西，被我和姊姊給轟回去了。",
    "後三式"      :(: ask_get_dan_sp :),
    "流星雨"      :(: ask_get_meteor :),
    "ribbon"      :(: ask_ribbon :),
    "蜂笛"        :(: ask_orderbee :),
//    "mirror"      :(: ask_mirror :),
    "hellfire"    :(: ask_set_allow_hellfire :),
    "地獄雷火術"  :(: ask_set_allow_hellfire :),
    "古舞使"      :(: ask_title :),
    "渾天水晶"    :(: ask_crystal :),
    "太陰虛幻神鑑":(: ask_moon :),
  ]));
  set("chat_chance_combat",60);
  set("chat_msg_combat",({
    (: magic :),
  }));
}

void init()
{
  add_action("do_join","join");
  set_heart_beat(1);
}

void heart_beat()
{
  object ob=this_object();
  if( !ob || !environment(ob) ) return;
  if( !query_temp("unconcious") ) {
    if( is_fighting() ){
      if(query_temp("ref_shield")!=1)
        command("conjure reflection");
      if(random(100)>85)
        command("conjure hellfire");
    }
    else {
      if( query("eff_kee") < query("max_kee") )
        command("conjure dreamcure");
      if( query("kee") < query("eff_kee") )
        command("exert recover");
    }
  }
  :: heart_beat();
}

void attempt_apprentice(object ob)
{
  command("l "+ob->query("id"));
  if(this_player()->query("class")!="dancer")
  {
    command("hammer"+ob->query("id"));
    command("say 先去加入舞者公會再來吧。\n");
    return;
  }
  command("smile");
  command("nod");
  command("chat 這個世界上又多了一個美麗的舞者了，希望各位多多愛護他....\n");
  ob->query("no_recruit");
  command("recruit "+ob->query("id"));
  new("/open/dancer/obj/ribbon")->move(ob);
  message_vision("月牙兒給了$N一條七彩緞帶。\n",ob);
  command("say 這是咱們夜夢小築的信物，務必妥善保存！");
}

string ask_ribbon()
{
  if(present("ribbon",this_player()))
    return "妳不是有了嗎？";
  if(this_player()->query("class")!="dancer")
    return "妳不是舞者要那個做什？？";
  else
  {
    command("say 唉，怎麼那樣不小心呢 !");
    new("/open/dancer/obj/ribbon")->move(this_player());
    return "希望妳能好好保管，別再弄不見啦！\n";
  }
}

string ask_get_dan_sp()
{
  if(this_player()->query("get_dan_sp")==1)
    return "妳不是學過了？？";
  if(this_player()->query("class")!="dancer")
  {
    command("stare"+this_player()->query("id"));
    return "妳問那麼多幹嘛？";
  }
  if((int)this_player()->query("combat_exp") < 500000)
    return "等妳經驗值高些再來吧！";
  else
  {
    command("say 很好.....我就將後三式傳授於妳...\n");
    this_player()->set("get_dan_sp",1);
    return "希望妳努力將舞者絕學發揚光大。";
  }
}

string ask_get_meteor()
{
  if(this_player()->query("spells/meteor/level")==1)
    return "妳不是學過了？？";
  if(this_player()->query("class")!="dancer")
  {
    command("stare"+this_player()->query("id"));
    return "妳問那麼多幹嘛？";
  }
  if((int)this_player()->query_temp("allow_learn")!= 1)
    return "先通過我師妹的考驗再說吧！";
  else
  {
    command("say 很好.....我就將終極火燄術流星雨傳授於妳...\n");
    this_player()->set("spells/meteor/level",1);
    message("system",HIW"月牙兒開心的說道：有了"+this_player()->name()+"的幫助定能使舞者更加發揚光大。\n"NOR,users());
    return "今後要更加努力喔。";
  }
}

string magic()
{
  command("conjure confuse");
  command("conjure fireball");
  command("conjure reflection");
  command("conjure firedance");
  command("conjure thunder");
  command("conjure dreamwings");
  return "\n";
}
 
int accept_fight(object ob)
{
  command("say 小女子怎是您的對手呢??\n");
  command("conjure reflection");
  command("conjure dreamwings");
  command("conjure confuse");
  message_vision( this_object()->name()+"一付弱不禁風的樣子。\n",ob);
  return 1;
}

int accept_kill(object ob)
{
  command("say 沒想到你忍心欺負弱小女子，那我就不客氣了!!!\n");
  command("conjure reflection");
  command("conjure confuse");
  return 1;
}

int do_join()
{
  object ob=this_player();
  command("shake"+ob->query("id"));
  return notify_fail("想當舞者要去找我師妹水靈兒才行喔!!\n");
}

string ask_set_allow_hellfire()
{
  object me=this_player();
  int i;
  i=random(2);
  if(me->query("class")!="dancer")
    return "抱歉了，這是舞者的不傳之秘，我是不會告訴外人的...";
  if(me->query("allow_hellfire"))
    return "你不是會了嗎?";
  if(me->query("combat_exp") < 4000000 )
    return "你的經驗還太淺薄了，多加磨練後再來找我吧...";
  if(me->query("spells/fireball/level")<100)
    return "你的火球術還不夠強，不能學地獄雷火術。";
  if(me->query("spells/thunder/level")<100)
    return "你的天雷術還不夠強，不能學地獄雷火術。";
  if(me->query("spells/firedance/level")<100)
    return "你的火鳳飛翔還不夠強，不能學地獄雷火術。";
  message_vision("月牙兒笑著說:看來$N已經有資格學習了，我現在就把雷火真元傳到你身上!!\n",me);
  message("system",HIW"月牙兒開心的說道：恭喜"HIC+this_player()->name()+HIG"歷盡磨練終於成為古舞者傳人。\n"NOR,users());
  me->set("allow_hellfire",1);
  me->set("adv_dancer",1);
  message_vision(HIW"一股"HIB"地獄"HIC"雷"HIR"火"HIW"真元緩緩流入$N的體內\n"NOR,me);
  if(i>0)
    me->set("title",HIG"∮"HIM"古 舞"HIG"∮"HIC"諭 雷 使"NOR) ;
  else
    me->set("title",HIG"∮"HIM"古 舞"HIG"∮"HIR"幻 火 使"NOR) ;
  me->set("spells/hellfire/level",1);
  return "恭喜你，你已經學會了地獄雷火術了!!";
}

string ask_title()
{
  object me=this_player();
  int i;
  i=random(2);
  if(me->query("class")!="dancer")
    return "妳不是舞者問這幹麼...???";
  if(!me->query("allow_hellfire"))
    return "妳還不夠資格吧，先去學學地獄雷火術吧？";
  if(me->query("title")==HIG"∮"HIM"古 舞"HIG"∮"HIC"諭 雷 使"NOR)
    return "妳已經是古舞使了吧";
  if(me->query("title")==HIG"∮"HIM"古 舞"HIG"∮"HIR"幻 火 使"NOR)
    return "妳已經是古舞使了吧";

  message_vision("月牙兒笑著說：好吧...我幫妳恢復妳的稱號!!\n",me);
  if(i>0)
    me->set("title",HIG"∮"HIM"古 舞"HIG"∮"HIC"諭 雷 使"NOR) ;
  else
    me->set("title",HIG"∮"HIM"古 舞"HIG"∮"HIR"幻 火 使"NOR) ;
  return"妳的稱號改好囉.....";
}

string ask_orderbee()
{
  object me=this_player();
  if(!me->query_skill("order-bee"))
    return "你連御蜂術都不會，給你蜂笛也沒用。\n";
  if(me->query_temp("give-order-bee"))
    return "蜂笛只能給一次，下次再來跟我要吧。\n";
  me->set_temp("give-order-bee",1);
  new("/daemon/class/dancer/bee_flute")->move(me);
  message_vision("月牙兒拿了一隻蜂笛給$N。\n",me);
  return "拿去吧，好好保管!!可不要弄丟了!!\n";
}

string ask_mirror()
{
  object me=this_player();
  if(me->query("spells/mirror"))
    return "妳不是已經學會了嗎??\n";
  me->set("spells/mirror/level",1);
  return "好吧，那我就傳授你『鏡月知術』!!";
}

void die()
{    
  object winner = query_temp("last_damage_from");
  int j;

  if(!winner)
  {
    ::die();
    return ;
  }
  tell_object(users(),HIW"\n『"HIC"葉 舞 春 憐 生 "HIM"～ 似悲又喜
\t  "HIC"雷 舞 夏 吟 頌 "HIM"～ 娛也樂乎
\t\t  "HIC"楓 舞 秋 別 恨 "HIM"～ 既多也愁
\t\t\t  "HIC"雪 舞 冬 悲 降 "HIM"～ 暗藏永久"HIW"』
\n"HIG"生在這四季的輪迴總是如夢一場 ～ 空也!!
\t想我"HIY"月牙兒"HIG"美麗的生命也逃不過這命運!!
\t\t而"HIR+winner->query("name")+HIG"也終將踏上這輪迴之道 ～ 永無止境!!\n"NOR);
  if(userp(winner) && winner->query_temp("not_robot") > time() )
  {
    if ( winner->query_temp("bless")==1 )
    {
      j=random(-1);
	  if( j==7 || j==77 || j== 777 || j==1111 || j==55 || j==555 || j==1000 || j==4000 || j==3333 || j==5555 )
	  {
        new("/open/sky/obj1/water_emblem")->move(environment(winner));
        message_vision(HIM"\n從月牙兒的身上掉下了一件奇怪的東西!!\n"NOR,winner);
        write_file("/log/sky/obj1/water_emblem",sprintf("%s(%s) 讓月牙兒掉下了水之紋章於 %s\n",
          winner->name(1),winner->query("id"),ctime(time())));
      }
    } else {
      j=random(-1);
      if( j==5 || j==15 || j== 150 || j==1500 || j==10 || j==100 || j==1000 || j==4000 || j==6666 || j==7777 )
      {
        new("/open/sky/obj1/water_emblem")->move(environment(winner));
        message_vision(HIM"\n從月牙兒的身上掉下了一件奇怪的東西!!\n"NOR,winner);
        write_file("/log/sky/obj1/water_emblem",sprintf("%s(%s) 讓月牙兒掉下了水之紋章於 %s\n",
          winner->name(1),winner->query("id"),ctime(time())));
      }
    }
  }
  ::die();
}

string ask_crystal()
{
  object me = this_player();
  if(me->query_temp("find_crystal"))
  {
    if(me->query_temp("find_crystal") == 2) me->set_temp("find_crystal",3);
      return "據說是前幾代的島主無意中在魔界發現的，詳情可能要去問我姊姊喔。\n";
  }
  else if(me->query("class") == "prayer")
  {
    message_vision(HIW"\n\n月牙兒冷笑道：「你也未免解太快了吧...」\n\n"NOR,me);
    return "零分!!";
  }
  else
  {
    command ("say 不是聖火教的問啥問啊!?去死吧！");
    kill_ob(me);
    command("conjure hellfire");
    return "殺殺殺!!";
  }
}

string ask_moon()
{
  object me = this_player();
  if(me->query_temp("find_crystal"))
  {
    command("say 林前輩一直認為這魔法和我們鏡月島有淵源，所以懷疑我們跟夜夢一派暗中串通。");
    command("say 其實他完全誤會了，雖然我們和夜夢一派同為舞者，但就像光與影一樣兩不相立。");
    if(!me->query_temp("find_moon")) me->set_temp("find_moon",1);
    return "不過我倒是蠻嚮往這套魔法的。";
  }
  else if(me->query("class") == "prayer")
  {
    message_vision(HIW"\n\n月牙兒冷笑道：「你也未免解太快了吧...」\n\n"NOR,me);
    return "零分!!";
  }
  else if(me->query("class") == "dancer")
  {
    if(!me->query_temp("find_moon")) me->set_temp("find_moon",1);
    return "我師妹瞭解得比較多，何不去問問她呢。";
  }
  else
  {
    command ("say 不是聖火教和本島的問啥問啊!?去死吧！");
    kill_ob(me);
    command("conjure hellfire");
    return "殺殺殺!!";
  }
}
