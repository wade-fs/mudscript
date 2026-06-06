//增加新手quest 尋找武林盟主的下落 by blazakira 2011/7/16

#include <ansi.h>
inherit NPC;

string ask_leader();

void create()
{
  set_name("王毓秀", ({ "shoue",}) );
  set("long", "
王家的二小姐實在不是用一個豔字所能形容的，一雙丹鳳三角眼，勾得
天下男子三魂七魄都飛了，兩灣柳葉掉梢眉；身量苗條，體格風騷；粉
面含春風威不露，丹唇未啟笑先聞。
");
        
  set("title","金刀王家二小姐");
  set("age", 19);
  set("int", 30);
  set("cps", 24);
  set("str", 23);
  set("cor", 22);
  set("spi", 29);
  set("con", 26);
  set("kar", 27);
  set("per", 29);
  set("force_factor", 5);
  set("combat_exp",100000);
  set("force",500);
  set("max_force",500);
  set_skill("blade", 60);
  set_skill("dodge", 40);
  set_skill("parry", 60);
  set_skill("unarmed",40);
  set_skill("force", 40);
  set_skill("gold-blade",70);
  set_skill("sixforce",30);
  set_skill("fly-steps",50);
  map_skill("force", "sixforce");
  map_skill("blade", "gold-blade");
  map_skill("dodge", "fly-steps");
  set( "gender", "女性");
  set("limbs", ({ "頭部",  "雙腳", "雙手", "背部" ,"腹部","腰部"}) );
  set("attitude", "peaceful");
  setup();
  carry_object("/open/gblade/obj/moon-blade")->wield();
  carry_object("/open/gblade/obj/agraffe.c")->wear();
  carry_object("/open/gblade/obj/topknot.c")->wear();
  carry_object("/open/gblade/obj/boots2.c")->wear();
  add_money("gold",15);
  set("inquiry",([
    "武林盟主" : (: ask_leader() :),
  ]));
}

string ask_leader()
{
  object me=this_player(),npc=this_object(),ob;
  string item_kinds;
  item_kinds="";
  if( me->query_temp("ask_leader/start")!=3 || me->query_temp("ask_leader/ba")==1 )
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
    command("say 幽嵐有一段時間沒見到她呢，改天去找她一起去風雨樓玩好了。");
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
  me->set_temp("ask_leader/ba",1); //詢問過金刀門的紀錄mark
  return "";
}
