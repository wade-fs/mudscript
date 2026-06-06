//增加新手quest 尋找武林盟主的下落 by blazakira 2011/6/29

#include <command.h>
#include <ansi.h>
inherit NPC;

string ask_leader();

void create()
{
  set_name("總管",({"general manager","manager"}));
  set("title", "聖火八天門");
  set("gender", "女性");
  set("age",50);
  set("attitude","peaceful");
  set("long",@LONG

	聖火教麾下八天門的總管, 專門負責門內的大小雜事, 見
	他忙的樣子, 真是有點想替他做些事情說!!

LONG);

  set("combat_exp",600000);
  set("str",25);
  set("con",25);
  set("int",30);
  set("per",30);
  set("cps",30);
  set("kar",30);
  set("force",1400);
  set("max_force",1400);
  set("force_factor",5);
  set("max_kee",800);
  set("kee",800);
  set("limbs",({"頭","手","腳","背","腹","腰"}));
  set_skill("unarmed",70);
  set_skill("universe",70);
  set_skill("force",80);
  set_skill("superforce",80);
  set_skill("move",80);
  set_skill("shift-steps",80);
  set_skill("parry",80);
  set_skill("dodge",80);
  map_skill("move","shift-steps");
  map_skill("dodge","shift-steps");
  map_skill("unarmed","universe");
  map_skill("parry","universe");
  map_skill("force","superforce");
  set("inquiry",([
    "武林盟主" : (: ask_leader() :),
  ]));

  setup();
  add_money("gold",5);
  carry_object("/open/prayer/obj/tiger-robe")->wear();
  carry_object("/open/prayer/obj/tiger-legging")->wear();
  carry_object("/open/prayer/obj/tiger-cape")->wear();
}

string ask_leader()
{
  object me=this_player(),npc=this_object(),ob;
  string item_kinds;
  item_kinds="unarmed";
  if( me->query_temp("ask_leader/start")!=3 || me->query_temp("ask_leader/pope")==1 )
  {
    return 0;
  }
  if( !me->query("family") && !me->query("officer_class") ) { //如果是平民的話
    switch( item_kinds ) { //判斷給予書籍的種類
      case "literate": //三字經
        command("say 聽說金刀門門裡有本三字經，可以提昇讀書識字(literate)的能力呢。");
        break;
      case "unarmed": //基礎拳譜
        command("say 聽說藏經閣裡有本基礎拳譜能提高撲擊格鬥技巧(unarmed)呢。");
        break;
      case "stabber": //基礎刺術集
        command("say 加入書生公會前有位秀才持有提高基本刺術(stabber)的書籍。");
        break;
      case "blade": //刀譜
        command("say 金刀門的白孝虹帶著一本刀譜。");
        break;
      case "sword": //基礎劍譜
        command("say 贊助幫助蜀中城的潦倒劍客一些盤纏的話，在基本劍術(sword)上可能會有精進。");
        break;
      case "spells": //易經
        command("say 天道一脈有本易經可以提高基礎咒術(spells)，但非外人不可獲得，該怎麼辦呢。");
        break;
      case "magic": //夢玄仙冊
        command("say 夢玄仙冊裡的法術(magic)除了舞者外，只有天道派能學。");
        break;
      case "whip": //鞭法入門
        new("/open/japan/obj/whip_book.c")->move(me);
        message_vision("$N給$n一本鞭法入門。\n",npc,me);
        break;
      case "throwing": //暗器入門
        new("/open/japan/obj/throwing_book.c")->move(me);
        message_vision("$N給$n一本暗器入門。\n",npc,me);
        break;
      case "archery": //箭術淺談
        new("/open/japan/obj/archery_book.c")->move(me);
        message_vision("$N給$n一本箭術淺談。\n",npc,me);
        break;
      default :
        command("say 似乎從書中學習基本技能的話，可以省一點潛能呢。");
        break;
    }
    command("say 我派遠在西域，你是不是來錯地方了！不是來拜師就趕快離開吧。");
  }
  else if( me->query("family")==npc->query("family") ) { //如果與此npc同一門派時
    command("say 武學之道視你勤奮的程度，期待你早日將我派揚威天下。");
    if( random(2) ) {
      command("say 這是一些盤纏，或許對你有所幫助。");
      ob=new("/obj/money/silver.c")->set_amount(random(20)+10);
      command("give silver to "+me->query("id"));
    }
    command("say 我聽說這個任務只是天子為了要吸引海外刺客的注意力而發佈，事實上天子正準備攻打某座海島。");
  }
  else { //其他門派時 或當過官 //既然是其他門派 那麼就機率出現忍者砍本npc吧（笑
    command("say 似乎閣下是來找麻煩的，沒事快離開。");
    if(!random(3)) {
      if(random(2))
        command("say 誰！誰在那裡！");
      else
        command("say 是刺客！");
      ob=new("/open/japan/npc/war_ninja2.c");
//      ob=new("/u/b/blazakira/killer/kon/war_ninja2.c");
      ob->set_temp("target",npc->query("id")); //紀錄本npc=目標
      ob->move(environment());
      ob->do_kill(ob,npc);
    }
  }
  me->add_temp("ask_leader/gift",1); //獎勵次數紀錄
  me->set_temp("ask_leader/pope",1); //詢問過聖火派的紀錄mark
  return "";
}
