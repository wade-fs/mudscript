//增加新手quest 尋找武林盟主的下落 by blazakira 2011/7/23

#include <ansi.h>
inherit NPC;

string ask_leader();

void create()
{
  set_name("王亮",({"wang lung","wang","lung"}));
  set("long","他是丐幫布袋長老中的一員！\n");
  set("gender","男性");
  set("class","beggar");
  set("nickname",HIY"乞中游龍"NOR);
  set("combat_exp",1000000);
  set("attitude","friendly");
  set("age",40);
  set("title",HIW"八袋長老"NOR);
  set("str", 40);
  set("cor", 40);
  set("cps", 30);
  set("per", 35);
  set("spi", 40);
  set("int", 20);
  set("con", 30);
  set("kar", 30);
  set("max_gin", 5000);
  set("gin", 5000);
  set("max_kee",4000);
  set("kee", 4000);
  set("max_sen", 5000);
  set("sen", 5000);
  set("force",6000);
  set("max_force",6000);
  set("max_atman",1000);
  set("max_mana",1000);
  set("mana",1000);
  set("atman",1000); 
  set_skill("staff",120);
  set_skill("pkdog-staff",100);
  map_skill("staff","pkdog-staff");
  set_skill("force",90);
  set_skill("pkdog-force",90);
  set_skill("pkdog-force",90);
  map_skill("force","pkdog-force");
  set_skill("dodge",100);
  set_skill("move",100);
  set_skill("shift-steps",100);
  map_skill("dodge","shift-steps");
  map_skill("move","shift-steps");
  set("force_factor",10);
  set_skill("parry",90);
  set("bellicosity",1000);
  set("functions/skydog/level",80);
  set("chat_chance_combat",20);
  set("chat_msg_combat",({
    (: perform_action, "staff.skydog" :),
  }));
//  set("chat_chance",2);
  set("chat_msg", ({HIC"王亮道：最近都找不到好地方行乞！\n"NOR,}));
  set("inquiry",([
    "武林盟主" : (: ask_leader() :),
  ]));
  setup();
  carry_object("/open/beggar/obj/gstaff.c")->wield();
  carry_object("/open/beggar/obj/belt.c")->wear();
  carry_object("/open/beggar/obj/wrists.c")->wear();
}

int accept_kill (object who)
{
  command ("say 你太瞧不起乞丐了!！"); 
  command ("wear all");
  command("perform staff.skydog");
  return 1;
}

int accept_fight (object who)
{
  command("ohoh");
  command ("say 讓你瞧瞧乞丐的厲害！"); 
  command ("wear all");
  return 1;
}

string ask_leader()
{
  object me=this_player(),npc=this_object(),ob;
  string item_kinds;
  item_kinds="literate";
  if( me->query_temp("ask_leader/start")!=3 || me->query_temp("ask_leader/beggar")==1 )
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
    command("say 你不給些銀子我怎會告訴你消息呢。");
    command("hehe");
    command("say 你真給我銀子，那就是傻蛋哩。");
    command("flee");
  }
  else if( me->query("family")==npc->query("family") ) {
    command("say 武學之道視你勤奮的程度，期待你早日將我派揚威天下。");
    if( random(2) ) {
      command("say 這是一些盤纏，或許對你有所幫助。");
      ob=new("/obj/money/silver.c")->set_amount(random(20)+10);
      command("give silver to "+me->query("id"));
    }
    command("say 偷偷告訴你一個秘密，換作別人我才不告訴他呢。");
    command("say 那就是秘密不存在。");
    command("laugh");
  }
  else {
    command("say 你不給些銀子我怎會告訴你消息呢。");
    command("hehe");
    command("say 你真給我銀子，那就是傻蛋哩。");
    command("flee");
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
  me->set_temp("ask_leader/beggar",1); //詢問過丐幫的紀錄mark
  return "";
}
