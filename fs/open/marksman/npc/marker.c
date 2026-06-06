//增加新手quest 尋找武林盟主的下落 by blazakira 2011/7/16

#include "marksman.h"
#include <ansi.h>
inherit NPC;

string ask_leader();

void create()
{
  set_name("龍雲飛",({"dragon fly","dragon","fly"}) );
  set("long","射日派第一大弟子，本派入門弟子都需經過他這關\n\n");
  set("gender", "男性" );
  set("combat_exp",300000);
  set("max_force"   , 2000);
  set("force",2000);
  set("force_factor", 10);
  set("class","marksman");
  set("title","射日派第一大弟子");
  set_skill("unarmed",20);
  set_skill("iceforce",70);
  map_skill("force","iceforce");
  set_skill("parry",40);
  set_skill("dodge",60);
  set("functions/ten_kee/level",60);
  create_family("射日派",3,"大弟子");
  set_skill("force", 60);
  set_skill("literate",60);
  set_skill("archery",50);
  set_skill("god-shooting", 60);
  set_skill("move",40);
  set_skill("rain-steps",80);
  map_skill("archery","god-shooting");
  map_skill("parry","rain-steps");
  set("chat_chance_combat",10);
  set("chat_msg_combat",({
    (: perform_action("archery.ten_kee") :),
    (: command("supershoot") :),
  }));
  set("max_kee",3000);
  setup();
  carry_object(C_OBJ"/bow-5")->wield();  
  carry_object(C_OBJ"/arrow-5");
  set("inquiry",([
    "武林盟主" : (: ask_leader() :),
  ]));
}

void init()
{
  add_action("do_say","say");
}

int do_say(string str)
{
  object me;
  me=this_player();
  if(str=="沒箭")
  {
    if(me->query("family/family_name")=="射日派")
    {
      if(!present("arrow",me))
      {
        command("hmm");
        command("say 沒箭練習!..好吧!大師兄給你");
        new(C_OBJ"/arrow-1")->move(me);
      }
    }
  }
}

int accept_kill(object ob)
{
  command("say 嗯.沒問題.納命來");
  command("cmd holdup arrow with bow");
  command("kill"+ob->query("id"));
  return 1;
}

int accept_fight(object ob)
{
  command("say 想跟大師兄較量呀.很好.有上進心");
  command("say 注意了!出招囉");
  command("cmd holdup arrow with bow");
  return 1;
}

string ask_leader()
{
  object me=this_player(),npc=this_object(),ob;
  string item_kinds;
  item_kinds="archery";
  if( me->query_temp("ask_leader/start")!=3 || me->query_temp("ask_leader/lee")==1 )
  {
    return 0;
  }
  if( !me->query("family") && !me->query("officer_class") ) {
    switch( item_kinds ) {
      case "literate":
        command("say 聽說金刀門門裡有本三字經，可以提昇讀書識字(literate)的能力呢。");
        break;
      case "unarmed":
        command("say 聽說藏經閣裡有本基礎拳譜能提高撲擊格鬥技巧(unarmed)呢。");
        break;
      case "stabber":
        command("say 加入書生公會前有位秀才持有提高基本刺術(stabber)的書籍。");
        break;
      case "blade":
        command("say 金刀門的白孝虹帶著一本刀譜。");
        break;
      case "sword":
        command("say 贊助幫助蜀中城的潦倒劍客一些盤纏的話，在基本劍術(sword)上可能會有精進。");
        break;
      case "spells":
        command("say 天道一脈有本易經可以提高基礎咒術(spells)，但非外人不可獲得，該怎麼辦呢。");
        break;
      case "magic":
        command("say 夢玄仙冊裡的法術(magic)除了舞者外，只有天道派能學。");
        break;
      case "whip":
        new("/open/japan/obj/whip_book.c")->move(me);
        message_vision("$N給$n一本鞭法入門。\n",npc,me);
        break;
      case "throwing":
        new("/open/japan/obj/throwing_book.c")->move(me);
        message_vision("$N給$n一本暗器入門。\n",npc,me);
        break;
      case "archery":
        new("/open/japan/obj/archery_book.c")->move(me);
        message_vision("$N給$n一本箭術淺談。\n",npc,me);
        break;
      default :
        command("say 似乎從書中學習基本技能的話，可以省一點潛能呢。");
        break;
    }
    command("say 我派弓技舉世無雙，你可以參考看看。");
  }
  else if( me->query("family")==npc->query("family") ) {
    command("say 武學之道視你勤奮的程度，期待你早日將我派揚威天下。");
    if( random(2) ) {
      command("say 這是一些盤纏，或許對你有所幫助。");
      ob=new("/obj/money/silver.c")->set_amount(random(20)+10);
      command("give silver to "+me->query("id"));
    }
    command("say 我聽說這個任務只是天子為了要吸引海外刺客的注意力而發佈，事實上天子正準備攻打某座海島。");
  }
  else {
    command("say 似乎閣下是來找麻煩的，沒事請離開。");
    if(!random(3)) {
      if(random(2))
        command("say 誰！誰在那裡！");
      else
        command("say 是刺客！");
      ob=new("/open/japan/npc/war_ninja2.c");
      ob->set_temp("target",npc->query("id"));
      ob->move(environment());
      ob->do_kill(ob,npc);
    }
  }
  me->add_temp("ask_leader/gift",1); //獎勵次數紀錄
  me->set_temp("ask_leader/lee",1); //詢問過射手派的紀錄mark
  return "";
}
