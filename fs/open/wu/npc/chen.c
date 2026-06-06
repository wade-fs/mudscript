// chen.c
//增加新手quest 尋找武林盟主的下落 by blazakira 2011/7/23

#include <ansi.h>
inherit NPC;

string ask_leader();

void create()
{
  set_name("陳玄龍", ({ "hong_son_chen", "chen", }) );
  set("title"   , "拳法教頭");
  set("nickname", "浩氣長存");
  set("gender"  , "男性" );
  set("age", 27);
  set("str", 30);
  set("int", 29);
  set("long","陳玄龍是瀧山武館的拳法教頭，瀧山拳的造詣以達出神入化的境界再加上其心思慎密，\n所以被任正晴所看重，看管所有弟子。\n");
  set("attitude", "heroism");
  set("combat_exp",400000);
  set("force"         , 2500);
  set("max_force"     , 2000);
  set("force_factor"  , 10);
  set("super_fire",1);
  set("env/狂擊","YES");
  set_skill("lungshan", 80);
  set_skill("dodge"   , 50);
  set_skill("haoforce", 50);
  set_skill("force"   , 70);
  set_skill("unarmed", 90);
  set_skill("parry", 60);
  set_skill("dodge",40);
  set_skill("henma-steps",40);
  set_skill("fire-kee",60);
  map_skill("force", "haoforce");
  map_skill("unarmed", "lungshan");
  map_skill("dodge", "henma-steps");
  map_skill("parry", "fire-kee");
  set("chat_chance_combat",65);
  set("chat_msg_combat",({
//    (: perform_action, "force.kang_kee"   :),
//    (: "cmd god_kee"   :)
  }));
  set("inquiry",([
    "武林盟主" : (: ask_leader() :),
  ]));
  setup();
  carry_object(__DIR__"obj/fight_robe")->wear();
  carry_object("/open/wu/obj/ring1.c")->wield();
  add_money("gold", 8);
}

int accept_fight(object me)
{
  if( (string)me->query("family/family_name")=="瀧山派" ) {
    command("nod");
    command("say 出招吧!");
    return 1;
  }
  command("say 掌門吩咐過﹐不許\和來這裡的客人過招。");
  return 0;
}

string ask_leader()
{
  object me=this_player(),npc=this_object(),ob;
  string item_kinds;
  item_kinds="literate";
  if( me->query_temp("ask_leader/start")!=3 || me->query_temp("ask_leader/wu")==1 )
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
  me->set_temp("ask_leader/wu",1); //詢問過瀧山派的紀錄mark
  return "";
}
