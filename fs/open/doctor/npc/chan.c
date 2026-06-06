//增加新手quest 尋找武林盟主的下落 by blazakira 2011/7/23

#include <ansi.h>
inherit NPC;

string ask_secret();
string ask_leader();

void create()
{
  set_name("張翱",({"chan au","chan","au"}));
  set("long","

     他是來自中原的行醫者，因仰慕華陀的醫術而來拜訪他也因此跟
    
     華陀學了不少的醫術，現在是華陀得力的助手，他在江湖行醫多

     年，練就了一身的好輕功\，所以得到一個綽號為行如風。而關於
     
     衝穴的傳說，他似乎知道一點點。

  ");
  set("gender","男性");
  set("class","doctor");
  set("nickname","行如風");
  set("combat_exp",450000);
  set("attitude","heroism");
  set("age",33);
  set("title","銀針門得力助手");
  set("str",15);
  set("cor",30);
  set("cps",20);
  set("kar",25);
  set("force",2000);
  set("max_force",2000);
   set("max_kee",1500);
//  set("kee",1500);
  set_skill("literate",60);
  set_skill("cure",80);
  set_skill("dodge",90);
  set_skill("move",90);
  set_skill("parry",30);
  set_skill("stabber",40);
  set_skill("force",40);
  set_skill("unarmed",20);
  set_skill("yu-needle",60);
  set_skill("seven-steps",90);
  set_skill("godcure",60);
  set_skill("shinnoforce",40);
  map_skill("stabber","yu-needle");
  map_skill("dodge","seven-steps");
  map_skill("force","shinnoforce");
  map_skill("move","seven-steps");
  map_skill("parry","yu-needle");
  map_skill("cure","godcure");
  set("force_factor",10);
  set("quest_start",1);
  set("inquiry",([
    "行如風"   : "哈哈哈～行如風就是我，想比馬拉松嗎?",
    "衝穴"     : "噓噓噓，這件事你問師父他一定不會跟你說的！但傳說中師父以前有這本秘籍，但好像之後經過一些事，就不見了。\n",
    "秘籍"     : (:ask_secret:),
    "武林盟主" : (: ask_leader() :),
  ]));
  setup();
  carry_object("/open/doctor/obj/needle5.c")->wield();
  add_money("gold",5);
}

string ask_secret()
{
  object me = this_player();
  switch(this_player()->query("family/family_name"))
  {
    case "段家":
    case "銀針門":
    case "冥蠱魔教":
      break;
    default:
      return "我想，這是本派的秘密，不能隨便跟他人說。\n";
  }
  if(me->query("quests/acupuncture"))
    return "恭喜啊！！原來你已經學會了！！！\n";
  me->set_temp("quests/acup",1);
  return "你是說衝穴秘籍嘛？這事兒只有師父知道，我是不敢問他。\n";
}

void greeting(object ob)
{
/*
  if( (string)ob->query("class") == "poisoner" ) {
    command("say 門主生平最恨毒害蒼生之人，今日我便為民除害，納命來吧！");
    kill_ob(ob);
  }
*/
}

string ask_leader()
{
  object me=this_player(),npc=this_object(),ob;
  string item_kinds;
  item_kinds="stabber";
  if( me->query_temp("ask_leader/start")!=3 || me->query_temp("ask_leader/tor")==1 )
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
    command("say 我在行醫的途中曾聽說，盟主其實是被自己人砍了一刀才被外人打倒。");
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
    command("say 我在行醫的途中曾聽說，盟主其實是被自己人砍了一刀才被外人打倒。");
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
  me->set_temp("ask_leader/tor",1); //詢問過銀針門的紀錄mark
  return "";
}
