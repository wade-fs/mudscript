// vagabond.c by oda
//更新天賦的判斷與顏色語法的調整 by blazakira 2010/11/8
//增加新手quest 尋找武林盟主的下落 by blazakira 2011/7/23

#include "/open/open.h"
#include <ansi.h>

inherit NPC;
inherit F_MASTER;

string ask_leader();

void create()
{
  set_name("蔣風",({"john fon","john","fon"}));
  set("family","惡人谷");
  set("nickname","百技神學");
  set("title","盜賊頭子");
  set("gender", "男性");
  set("age",52);
  set("class", "bandit");
  set("guild_master", 1);
  set("bellicosity",1000);
  set("attitude", "badman");
  set("combat_exp",1000000);
  set("spi",50);
  set("int",50);
  set("str",10);
  set("cor",10);
  set("max_gin",1200);
  set("max_kee",3200);
  set("max_sen",1200);
  set("max_force",3500);
  set("force",3500);
  set("force_factor",10);

  set_skill("array",80);
  set_skill("steal",100);
  set_skill("change",100);
  set_skill("cure",60);
  set_skill("dodge",80);
  set_skill("force",80);
  set_skill("gamble",70);
  set_skill("literate",50);
  set_skill("magic",50);
  set_skill("move",80);
  set_skill("parry",80);
  set_skill("spells",50);
  set_skill("sword",80);
  set_skill("unarmed",80);
  set_skill("blade",80);
  set_skill("riding",20);
  set_skill("poison",60);
  set_skill("stabber",80);
  set_skill("archery",80);
  set_skill("whip",80);
  set_skill("throwing",80);
  set_skill("dagger",80);
  set_skill("plan",60);
  set("inquiry",([
    "武林盟主" : (: ask_leader() :),
  ]));
  setup();
  add_money("gold",30);
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
  add_action("do_join", "join");
}

int do_join()
{
  object who;
  who = this_player();
  if( who->query("class") )
    return notify_fail("蔣風不耐煩道﹕你已經是公會成員了，別來煩我！\n");
  who->set("class", "bandit");
  tell_object(users(),HIC"惡人公會盜賊頭子蔣風縱聲大叫﹕又有個壞傢伙加入咱賊道啦！！！\n"NOR);
  return 1;
}

void greeting(object ob)
{
  if ( ob->query("class")=="bandit")
  {
    if ( ob->query("quests/steal") == 1 ) //神手妙取之術 (steal) 判斷mark
    {
      message_vision(HIW"蔣風笑道﹕嗯？偷得還過癮吧？？\n"NOR,ob);
    }
    else if (ob->query("combat_exp") > 100000 && ob->query_kar() >= 30 ) //因為可以當官後轉惡人所以增加大於30的可能 by blazakira
    {
      message_vision(HIG"蔣風像似看到稀罕物般﹕哎呦！這麼強運的人已經很少看到了，
我就特地教你怎麼偷摸（steal）別人的東西吧！\n"NOR,ob);
      ob->set("quests/steal",1);
    }
    else if(ob->query("quests/karup") == 1)
    {
      message_vision(HIG"蔣風拍了拍$N的肩說道﹕做得好啊！真是有出息，
那我就教你怎麼去偷東西吧（steal）！\n"NOR,ob);
      ob->set("quests/steal",1);
    }
    else if (ob->query_temp("marks/karup",1))
    {
      message_vision(HIG"蔣風看了看$N欲言又止的模樣﹕怎麼還是老樣子？再不努力點，我可不管你了！\n"NOR,ob);
    }
    else if (ob->query("combat_exp") > 135000 && ob->query_kar() < 30 )
    {
      message_vision(HIG"蔣風嘖嘖稱奇地對$N說道﹕嗯，看來你有資格讓我傳授你一些東西，
但你的運氣未免差了點，想辦法讓運勢再加強點吧！\n"NOR,ob);
      ob->set_temp("marks/karup",1);
    }
  }
}

string ask_leader()
{
  object me=this_player(),npc=this_object(),ob;
  string item_kinds;
  item_kinds="unarmed";
  if( me->query_temp("ask_leader/start")!=3 || me->query_temp("ask_leader/bandit")==1 )
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
    command("say 我聽說皇宮裡有人的東西遭竊，所以天子意圖攻打我們。");
  }
  else if( me->query("family")==npc->query("family") ) {
    command("say 武學之道視你勤奮的程度，期待你早日將我派揚威天下。");
    if( random(2) ) {
      command("say 這是一些盤纏，或許對你有所幫助。");
      ob=new("/obj/money/silver.c")->set_amount(random(20)+10);
      command("give silver to "+me->query("id"));
    }
    command("say 我聽說皇宮裡有人的東西遭竊，所以天子意圖攻打我們。");
    command("say 這是誣陷，你行走江湖要小心背後有人捅刀呢。");
  }
  else {
    command("say 我聽說皇宮裡有人的東西遭竊，所以天子意圖攻打我們。");
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
  me->set_temp("ask_leader/bandit",1); //詢問過惡人谷的紀錄mark
  return "";
}
