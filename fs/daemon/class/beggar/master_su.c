inherit NPC;
#include <ansi.h>
inherit F_MASTER;
void create()
{
  set_name("蘇乞兒",({"master su","master","su"}));
  set("long","看他的樣子一臉衰相，真懷疑他竟是一派的掌門！\n");
  set("gender","男性");
  set("class","beggar");
  set("nickname",HIW"走路踩狗屎，吃飯會噎死"NOR);
  set("combat_exp",10000000);
  set("attitude","friendly");
  set("age",40);
  set("title",HBCYN+HIW"丐幫第二代幫主"NOR);
  set("str", 40);
  set("cor", 40);
  set("cps", 30);
  set("per", 35);
  set("spi", 40);
  set("int", 20);
  set("con", 30);
  set("kar", 30);
  set("max_gin", 10000);
  set("max_kee",10000);
  set("max_sen", 10000);
  set("max_force",50000);
  set("force",50000);
  set("max_atman",10000);
  set("max_mana",10000);
  set("mana",10000);
  set("atman",10000); 
  set_skill("staff",120);
  set_skill("pkdog-staff",120);
  map_skill("staff","pkdog-staff");
  set_skill("force",100);
  set_skill("pkdog-force",120);
  map_skill("force","pkdog-force");
  set_skill("dodge",110);
  set_skill("move",100);
  set("force_factor",20);
  set_skill("unarmed",90);
  set_skill("parry",90);
  set_skill("beggar-steps",100);
  map_skill("dodge","beggar-steps");
  map_skill("move","beggar-steps");
  set("bellicosity",10000);
  set("beggar/got_secret",1);
  set("beggar/got_dogup",1);
  set("MKS",40000);
  set("chat_chance",2);
  set("functions/skydog/level",100);
  set("functions/dogup/level",100);
  set("functions/dog-phoenix/level",100);
  set("functions/dog-tiger/level",100);
  set("functions/dog-dragon/level",100);
  set("chat_chance_combat",20);
  set("chat_msg_combat",({
    (: perform_action, "staff.skydog"   :),
  }));
  set("inquiry" , ([
    "犬化四象" : "我也不會，不過有個長老似乎懂得這套心法，可惜他在多年前就失蹤了，也許\你可以去找胎鴿兄尋問。",
    "打狗秘招" : "唔．．我是一覺醒來就莫名的會了，世上還有一人會此招，就是洪七公。\n",
    "洪七公"   : "我師父他那老頭我也不曉得去哪了，可能去尋找他的寶物了吧，
               　　　　　　　去山林找找，也許\好運點可以碰到他。\n",
  ]));
  setup();
  create_family("丐幫",1,"掌門人"); 
  carry_object("/open/beggar/obj/cloudstaff1")->wield();
  //加入eq by guetenr 2003/5/11
  carry_object("/open/beggar/obj/shield")->wear();
  carry_object("/open/beggar/obj/legs")->wear();
  carry_object("/open/beggar/obj/hat")->wear();
}

void init()
{
  ::init();
  set_heart_beat(1);
  add_action("do_say","say");
}

void do_say(string arg)
{
  object me=this_player();
  if(arg == "一乞成名天下知" && me->query_temp("can_say")==1 )     
  {
   command("say 很好，你通過考驗了。");
   me->set_temp("got_inquiry",1);
  }
}


void attempt_apprentice(object ob)
{
  if(this_player()->query("class")!="beggar")
  {
    command("say 你跟我不同職業，再吵我拿大便丟你哦！\n");
    command("kok "+this_player()->query("id"));
    return ;
  }
  if(ob->query_temp("got_inquiry")==1 && ob->query("class")=="beggar")
  {
    if(ob->query("have_officer")==1)
    {
      command("kok "+ob->query("id"));
      command("say 我不想與朝庭的走狗為伍！");
    }
    else if(ob->query_cor(1)<25)
    {
      command("say 你這麼膽小也要學人行乞？\n");
    }
    else if(ob->query_spi(1) < 20 || ob->query_int(1) < 20)
    {
      command("say 你太笨了，一定學不會打狗棒法！\n");
    }
    else
    {
      command("hmm");
      command("kok "+ob->query("id"));
      command("spit");
      command("ohoh");
      command("recruit "+ob->query("id")); 
      this_player()->set("title","丐幫第三代弟子"NOR);
      message("system",
                        HIY+"蘇乞兒高聲呼道：呦　～～　　大家注意來！！\n\n　
                         "+HIW+"今天又一幸運兒"+ob->query("name")+"入我丐幫派了\n\n
                      "+HIR+"我們來恭喜 "+ob->query("name")+" 今後將成為新一代武狀元！\n"NOR,users());
    }
  }
  else
  {
    command("say 你還沒取得通關秘語，我不能收你！");
    command("say 若想入幫請say 暗號。");
  }
}

int accept_kill (object who)
{
  this_object()->delete_busy();
  command ("say 你真是討皮痛耶！"); 
  command ("wield staff");
  command ("wear all");
  command ("exert dog-phoenix");
  command ("exert dog-tiger");
  command ("exert dog-dragon");
  command ("exert dog-shanwu");
  return 1;
}

int accept_fight (object who)
{
  this_object()->delete_busy();
  command("ohoh");
  command ("say 既然如此﹐看我的狗屎攻擊！"); 
  command ("wear all");
  command ("wield staff");
  command ("exert dog-phoenix");
  command ("exert dog-tiger");
  command ("exert dog-dragon");
  command ("exert dog-shanwu");
  return 1;
}

void heart_beat()
{
  if( !is_fighting() )
  {
    if( query("force") < query("max_force") ) // 1 -> 5.035
      command ( "ex 160" );
    if( query("eff_kee") < query("max_kee") ) // 35
      command ( "10 exert heal" );
    if( query("gin") < query("eff_gin") ) // 125
      command ( "exert regenerate" );
    if( query("kee") < query("eff_kee") ) // 125 -> 300
      command ( "3 exert recover" );
    if( query("sen") < query("eff_gin") ) // 125
      command ( "exert refresh" );
  }
  if ( this_object()->is_fighting() && random(50)>25)
  {
    message_vision(HIM"$N不甘心被壓著打，一聲怒吼，解開了被封穴道！\n"NOR,this_object());
    this_object()->delete_busy();
  }
  ::heart_beat();
}

void die()
{
  object winner,spirit;
  winner = query_temp("last_damage_from");
  tell_object(users(),"\n\t\t"HIW"蘇乞兒死前大喝～～～～"NOR"\n"+
    "\n\t"HIY"想我一代武狀元！！如今居然敗於"+winner->query("name")+"，情何以堪呀！\n
                     通 通 和 我 一 起 下 地 獄 吧 ～～～～ ﹗\n

                "HIR"聲音一畢﹐天空立刻變得血紅﹐不....你眼前的一切都變得血紅...\n

                    所有的一切都在瞬間陷入火海....\n"NOR"

                "BMAG""HIW"然後你的眼前是一片黑暗....無止盡的黑暗....\n"NOR

  );
  if(present("cloud staff",this_object()))
    destruct(present("cloud staff",this_object()));
  if( random(144) == 77 && userp(winner) )
  {
    spirit = new("/open/ghost-hole/obj/ground-spirit");
    spirit->move(winner);
    log_file("/sky/spirit/ground-spirit",sprintf("%s(%s)讓蘇乞兒掉下了%s於 %s\n",winner->name(1),winner->query("id"),spirit->query("name"),ctime(time())));
    message_vision(HIW"薀含在"+this_object()->query("name")+HIW"身體中的"+spirit->query("name")+HIW"飛射而出，落在$N"HIW"手中。\n"NOR,winner);
  }
  :: die();
}

void greeting(object ob)
{
  if(!ob) return ;
  if(ob->query("family/family_name")=="丐幫")
  {
    if(!living(ob)) {command("moan");} else {command("say Pana回來囉!大家掌聲鼓勵鼓勵!!\n");}
    if(!present("durian staff",ob) && !ob->query("beggar/got_cloudstaff"))
    {
      new("/open/beggar/obj/durian")->move(ob);
      command("kok "+ob->query("id"));
      command("say 你怎麼弄丟了丐幫的杖呢 ?");
      command("say 再給你一把 , 別再弄丟囉 !");
      command("bite "+ob->query("id"));
      message_vision("蘇乞兒轉過身去，拿了一把杖交到$N手中\n",ob);
    }
    if(!present("cloud staff",ob) && ob->query("beggar/got_cloudstaff")==1)
    {
      command ("hit "+ob->query("id"));
      command ("say 你把丐幫最重要的寶物給弄丟了，自己去找七公想辦法！");
      command ("lazy "+ob->query("id"));
      ob->set_temp("need_cloud",1);
    }
    if(ob->query("beggar/got_phoenix")==1 && present("durian staff",ob))
    {
      command ("say 你已取得最終寶物，便不需要初級的入幫武器了！");
      destruct(present("durian staff",ob));
    }
    ob->set("no_recruit",1);
    if ((int)ob->query("combat_exp") > 10000000 && !(ob->query("beggar/have_nick")) )
      call_out("exp_check1",1);
  }
}

void exp_check1()
{
  object me=this_player();
  if (me->query("family/family_name")=="丐幫" && (int)me->query("combat_exp")>10000000)
  {
    command("say 唷，"+me->query("name")+"你經驗值終於一千萬啦！");
    call_out("exp_check2",1);
  }
}

void exp_check2()
{
  object me=this_player();
  if (me->query("family/family_name")=="丐幫" && (int)me->query("combat_exp")>10000000)
  {
    command("say 為師無以獎勵你，所以只好............閃你二把斬！");
    call_out("exp_check3",1);
  }
}

void exp_check3()
{
  object me=this_player();
  if (me->query("family/family_name")=="丐幫" && (int)me->query("combat_exp")>10000000)
  {
    command("slap "+me->query("id"));
    command("slap "+me->query("id"));
    call_out("exp_check4",1);
  }
}

void exp_check4()
{
  object me=this_player();
  if (me->query("family/family_name")=="丐幫" && (int)me->query("combat_exp")>10000000)
  {
    command("say 唔....不然為師就賜你這豬頭一個嚮亮的封號好了！");
    command("say 受封～～");
    call_out("exp_check5",1);
  }
}

void exp_check5()
{
  object me=this_player();
  if (me->query("family/family_name")=="丐幫" && (int)me->query("combat_exp")>10000000)
  {
    tell_object(users(),HIY"\n
                        蘇乞兒拎著"+me->query("name")+"的耳朵呵呵大笑著
\n\t      "+me->query("name")+"你學藝有成，為師就封你個稱號吧！
\n\n\t          "HIC"丐幫頭號"HIW"【"HIR"小 烏 龜"HIW"】"NOR"\n");
    me->set("title",HIC"丐幫頭號"HIW"【"HIR"小 烏 龜"HIW"】"NOR);
    me->set("beggar/have_nick",1);
  }
}
