//增加新手quest 尋找武林盟主的下落 by blazakira 2011/7/23

#include <ansi.h>
#include "/open/open.h"
inherit NPC;

string ask_leader();
string ask_ball()
{
  if(!this_player()->query_temp("swordtime"))
  {
    return ("對不起﹐你問的事我實在沒有印象。");
  }
  else
  {
    if (this_player()->query("class")=="scholar"&&this_player()->query_temp("swordquest/findball")==1)
    {
      this_player()->set_temp("swordquest/findball",2);
      return ("嗯....麗玉蝶蘭晶珠是顆很漂亮的寶石歐﹐可惜不知道被他拿去給誰了。\n");
    }
    else return ("對不起﹐你問的事我實在沒有印象。");
  }
}

void create()
{
  set_name("葉靈", ({ "yar leing","yar","leing" }) );
  set("title","段夫人");
  set("gender","女性");
  set("race", "人類");
  set("attitude","peaceful");
  set("age", 30);
  set("long","一個容光照人的貴婦，自幼與段雲同門學藝，據說其武功\不在段雲之下。");
  set("str", 30);
  set("per", 35);
  set("max_force", 3000);
  set("force", 3000);
  set_skill("parry",80);
  set("combat_exp",500000);
  set_skill("six-fingers", 80);
  set_skill("unarmed", 80);
  set_skill("force",60);
  set("force_factor", 10);
  map_skill("unarmed","six-fingers");
  set_skill("dodge",60);
  set_skill("linpo-steps", 60);
  map_skill("dodge","linpo-steps");
  set("inquiry",([
    "麗玉蝶蘭晶珠" : (:ask_ball:),
    "武林盟主"     : (: ask_leader() :),
  ]));
  setup();
  add_money("gold",5);
  carry_object(PING_OBJ"neck0")->wear();
}

string ask_leader()
{
  object me=this_player(),npc=this_object(),ob;
  string item_kinds;
  item_kinds="literate";
  if( me->query_temp("ask_leader/start")!=3 || me->query_temp("ask_leader/duan")==1 )
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
    command("say 我前些日子從皇后那裡回來，聽聞此事，盟主受傷是假，不過是天子想藉機收買人心而已。");
  }
  else if( me->query("family")==npc->query("family") ) {
    command("say 武學之道視你勤奮的程度，期待你早日將我派揚威天下。");
    if( random(2) ) {
      command("say 這是一些盤纏，或許對你有所幫助。");
      ob=new("/obj/money/silver.c")->set_amount(random(20)+10);
      command("give silver to "+me->query("id"));
    }
    command("say 我聽說這個任務只是聖上為了要吸引海外刺客的注意力而發佈，事實上聖上正準備攻打某座海島。");
  }
  else {
    command("say 我前些日子從皇后那裡回來，聽聞此事，盟主受傷是假，不過是天子想藉機收買人心而已。");
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
  me->set_temp("ask_leader/duan",1); //詢問過段家的紀錄mark
  return "";
}
