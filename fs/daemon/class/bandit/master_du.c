// dusa.c by oda
//增加新手quest 尋找武林盟主的下落 by blazakira 2011/7/23

#include "/open/open.h"
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

string do_ask();
string do_ask2();
string ask_ball();
string ask_hand();
string ask_book();
string do_title();
string ask_leader();

void create()
{
  set_name("杜殺", ({ "du sa", "du", "sa" }) );
  set("nickname", "血手");
  set("title", "惡人谷大頭目");
  set("gender", "男性");
  set("age", 41);
  set("class", "bandit");
  set("guild_master", 1);
  set("bellicosity", 2500);
  set("attitude", "badman");
  set("combat_exp", 3000000);
  set("long","這個人身子又瘦又長，一身雪白的長袍，他的臉就跟他的衣服一樣蒼白。
仔細一看，你才發現他的左手已經斷了，並且裝上了一個鋒利的鋼鉤。他就是惡人谷中
最令人畏懼的十大惡人之首﹣「血手」杜殺。\n如果稱謂不見了，你可以問他有關title的事。");

  set("str", 40);
  set("cor", 40);
  set("int", 24);
  set("spi", 22);
  set("cps", 30);
  set("con", 30);
  set("per", 16);
  set("max_gin", 10000);
  set("max_kee", 10000);
  set("max_sen", 10000);
  set("gin", 10000);
  set("kee", 10000);
  set("sen", 10000);
  set("max_force",5000);
  set("force",5000);
  set("force_factor", 10);

  set_skill("array",80);
  set_skill("magic",20);
  set_skill("spells",20);
  set_skill("bad-array",100);
  set_skill("change",100);
  set_skill("dodge", 80);
  set_skill("sword",80);
  set_skill("ghost-steps",100);
  set_skill("force", 70);
  set_skill("badforce",100);
  set_skill("counter",80);
  set_skill("move", 80);
  set_skill("parry",70);
  set_skill("unarmed",80);
  set_skill("cure",50);
  set_skill("badstrike",100);
  set_skill("gamble", 50);
  set_skill("literate",30);
  map_skill("unarmed", "badstrike");
  map_skill("array", "bad-array");
  map_skill("parry", "badstrike");
  map_skill("force", "badforce");
  map_skill("dodge", "ghost-steps");
  map_skill("move", "ghost-steps");
  set("quests/badroar",1);
  set("functions/evil-blade/level",100);
  set("functions/badroar/level",50);

  set("chat_chance_combat", 60);
  set("chat_msg_combat", ({
    (: perform_action, "unarmed.evil-blade" :),
    (: perform_action, "unarmed.badroar" :),
  }) );
  set("inquiry",([
    "title"        : (: do_title :),
    "瑞獸"         : "就是麒麟呀!!",
    "天道魔經"     : "那是傳說中的夢幻魔功\啊!!",
    "左手"         : (: do_ask :),
    "惡人森林"     : (: do_ask2 :),
    "麗玉蝶蘭晶珠" : (:ask_ball:),
    "血手"         : (:ask_hand:),
    "血池"         : (:ask_book:),
    "武林盟主"     : "蔣風既是盜賊頭子也是本谷的情報通，你去他那打聽消息吧。",
  ]));

  setup();
  create_family("惡人谷",1,"大頭目");
  set("family/next_title", "小嘍嘍");
  add_money("gold", 10);
  carry_object(BAD_OBJ"badhelmet")->wear();
  carry_object(BAD_OBJ"evil_claw.c")->wield();
}

void init()
{
  add_action("do_join", "join");
}

int accept_fight(object who)
{
  message_vision("杜殺冷冷的瞄了$N一眼。\n", who);
  command("say 哼，不自量力的傢伙。\n");
  return 1;
}

void attempt_apprentice(object who)
{
  if( !who->query("class") ) {
    command("shake "+who->query("id"));
    command("say 等你加入(join)盜賊這一行再說吧。");
    return;
  }
  if( who->query("class")!="bandit" ) {
    command("stare "+who->query("id"));
    command("say 惡人谷是幹強盜的，你們這些善良老百姓還是快滾吧！");
    return;
  }
  if(!who->query("quests/badman_license")) {
    tell_object(who,"杜殺冷冷的看著你說：就憑你也想加入惡人谷？等你除掉燕南天這傢伙再說吧！\n");
    who->delete_temp("pending/apprentice");
    return;
  }
  command("look "+who->query("id"));
  command("say 好！我就收你這個徒弟。");
  command("recruit "+who->query("id"));
  tell_object(who,"杜殺說道：記住，惡人谷認證不認人，要是惡人證遺失的話就再去找你師兄司馬煙拿。\n");
  command("say 不過既然你加入了惡人谷，就永遠別想脫離這裡，否則....");
  command("hehe "+who->query("id"));
  if (who->query("quests/badroar",1))
  {
    tell_object(who,"嗯 ,底子不錯嘛 !好 ,你可以不用從基層幹起!!!\n");
    who->set("title","大壞蛋");
    return;
  }
}

string do_title()
{
  if(this_player()->query("family/family_name") != "惡人谷") return "你在說什麼，我怎麼都不知道？";
  if(!this_player()->query("quests/badroar",1)) return "你在說什麼，我怎麼都不知道？";
  this_player()->set("title","\e[33m大\e[31m壞\e[32m蛋\e[0m");
  return "乖，你還是很壞的，你放心";
}

int do_join()
{
  object who;
  who = this_player();

  if( !who->query("class"))
    return notify_fail("要加入本谷就去找盜賊頭子點頭！\n");
  return 1;

/*
  if( who->query("class") )
    return notify_fail("你已經加入其他工會了。\n");
  who->set("class", "bandit");
  message("system", HIW + "杜殺仰天狂嘯：咱們盜賊又多了一個極惡之徒﹣" + HIR+who->query("name")+HIW + "\n大家要小心啦！哈哈哈哈！\n" + NOR, users());

  return 1;
*/
}

void die()
{
/*
  object weapon;
  weapon = present("hook", this_object());
  destruct(weapon);
*/
  object winner = query_temp("last_damage_from");        
  int j;
  if(!winner)
  {
    ::die();
    return ;
  }
  if(userp(winner) && winner->query_temp("not_robot") > time() )
  {
    if ( winner->query_temp("bless")==1 )
    {
      j=random(-1);
      if( j==7 || j==77 || j== 777 || j==1111 || j==55 || j==555 || j==1000 || j==4000 || j==3333 || j==2222 )
      {
        new("/open/sky/obj2/soil_stone")->move(environment(winner));
        message_vision(HIM + "\n從杜殺的身上掉下了一件奇怪的東西!!\n" + NOR,winner);
        write_file("/log/sky/obj2/soil_stone",sprintf("%s(%s) 讓杜殺掉下了地尊石於 %s\n",
        winner->name(1),winner->query("id"),ctime(time())));
      }
    } else {
      j=random(-1);
      if( j==5 || j==15 || j== 150 || j==1500 || j==10 || j==100 || j==1000 || j==4000 || j==6666 || j==7777 ) 
      {
        new("/open/sky/obj2/soil_stone")->move(environment(winner));
        message_vision(HIM + "\n從杜殺的身上掉下了一件奇怪的東西!!\n" + NOR,winner);
        write_file("/log/sky/obj2/soil_stone",sprintf("%s(%s) 讓杜殺掉下了地尊石於 %s\n",
        winner->name(1),winner->query("id"),ctime(time())));
      }
    }
  }
  tell_object(users(),"" + RED + "惡人谷" + HIY + "傳來撕天裂地的怒吼：\n
                   " + HIY + "「" + HIR + "天魔雙刀血立濺，混殺一吼魂飛滅！" + HIY + "」\n
                　唉～～想我「" + HIR + "血手" + HIY + "」" + HIG + "杜殺" + HIY + "闖蕩江湖三十餘年...\n
                         一生所殺之人已不可計數...\n
                  而今日卻失手命葬於" + HIW+winner->query("family/family_name")+HIY + "小賊－"+HIC+winner->query("name")+HIY+"之手...\n
                     " + RED + "一世惡名" + HIY + "如今毀於一旦，真是可恨啊！\n" + NOR);
  ::die();
}

int accept_object(object me,object ob)
{
  if(ob->query("id")=="sa`s hand")
  {
    if(me->query("quests/badroar"))
    {
      command("say 我不是傳你混殺吼了嗎 ?還想要謝禮啊 !");
      destruct(ob);
      return 1;
    }
    if(me->query("class")!="bandit")
    {
      kill_ob(this_player());
      destruct(ob);
      command("say 你不咱惡人谷的 ,怎麼能到森林去找我的左手!?");
    }
    if (me->query_temp("marks/allow")!=1)
    {
      destruct(ob);
      command("say 喔,謝啦!不過下次別再隨便亂跑禁區!!!");
    }
    else {
      command("nod "+me->query("id"));
      me->set("quests/badroar",1);
      destruct(ob);
      command("say 不愧\是咱們惡人谷的模範 !這樣吧 ,我也沒什麼好東西能給你 ,便傳你\n我們惡人在外行走江湖的口訣--窮兇惡極 ,神哭鬼嚎....就這樣 ,\n我倆以後可互不相欠！");
      tell_object(me,"你稍微領悟了這八字的意義 ,心中殺氣一聚 ,混殺吼(badroar)的功\力增加了!!\n");
      me->set("title","大壞蛋");
    }
    return 1;
  }
}

string do_ask()
{
  int me;
  object who;
  who = this_player();
  if(who->query("quests/badroar")!=1)
  {
    if(who->query_temp("marks/hand_again")!=1)
    {
      who->set_temp("marks/hand",1);
      return "你這個混蛋 !區區一個小囉嘍還敢管本大爺閒事 !還不快滾 ?\n";
    }
    else
    {
      who->set_temp("marks/allow",1);
      return "沒想到你的意志這麼堅定 .好吧 ,就告訴你 .我的左手是當初我們惡人谷眾多惡人將燕南天引誘到惡人森林時 ,不小心被燕南天給砍斷的 .只是沒想到他卻被你這麼一個小伙子給殺了....對了 !既然你能將燕南天給殺了 ,那找回我那隻斷手應該也不是難事吧 ?至於在哪裡嘛....你就去問問那個只會做藥的老頭子吧 .\n";
    }
  }
  else
  {
    return "你不是拿回來了..?還想幹嘛..?\n";
  }
}

string do_ask2()
{
  int me;
  object who;
  who = this_player();
  if(who->query("quests/badroar")!=1)
  {
    return "一個小囉嘍還想到森林去 ?送死啊!?\n";
  }
  else
  {
    who->set_temp("marks/allow",1);
    return "想去森林 ?好 ,沒問題 !去跟軒轅三光那賭鬼說吧 !\n";
  }
}

string ask_ball()
{
  if(!this_player()->query_temp("swordtime"))
  {
    return ("對不起﹐你問的事我實在沒有印象。");
  }
  else
  {
    if (this_player()->query("class")=="scholar"&&this_player()->query_temp("swordquest/findball")==5)
    {
      this_player()->set_temp("swordquest/findball",6);
      return ("沒錯!!當初就是我去皇城偷的﹐但是那是顆有靈性的晶珠﹐過不了多久他就自己消失了﹐或許\你可以到他主人居住的地點找找。\n");
    }
    else return ("對不起﹐你問的事我實在沒有印象。");
  }
}

string ask_hand()
{
  if(this_player()->query("class") != "bandit")
  {
    return ("不是我們惡人谷的弟兄問這幹麻!?");
  }
  if(!this_player()->query("quests/badroar"))
    return ("你還不夠邪惡，沒資格詢問這檔事!!");
  if(this_player()->query("combat_exp") < 5555555)
    return ("你的實力還不夠強大，再去多加修行吧!!");
  this_player()->set_temp("know_book",1);
  return ("還不都是為了尋找天道魔經，才在血池中弄成這副模樣的。");
}

string ask_book()
{
  if(!this_player()->query_temp("know_book"))
  {
    return ("不對喔，你並不知道這本書。");
  }
  return ("那該死的血池就在西域，不過有一頭瑞獸把守著。");
}
