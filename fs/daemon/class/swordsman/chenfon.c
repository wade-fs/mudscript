//增加新手quest 尋找武林盟主的下落 by blazakira 2011/7/16

#include "/open/gsword/npc/attack_bloodsword.h"
#include <ansi.h>
inherit NPC;
inherit F_MASTER;

string ask_leader();

void create()
{
  set_name("張乘風", ({"chen fon","fon"}));
  set("long","鄭士欣首徒,張乘風二十餘年來行俠仗義,早已名滿天下,近十餘年,
由於掌門人鄭士欣遣心於研究仙劍劍法,仙劍派有關迎賓,接客,收
徒等事,皆由乘風負責,乘風處事得體,見識廣範,一手仙劍劍法已
達宗師火侯,看來,下任掌門非他末屬.\n");
  set("gender","男性");
  set("combat_exp",500000);
  set("attitude","heroism");
  set("age",46);
  set("class","swordsman");
  set("nickname","風雲雙俠");
  set("title","仙劍派第四代大弟子");
  create_family("仙劍派",4,"弟子");
  set("score",100000);
  set("sha-stop-1",1);
  set("force",1200);
  set("max_force",1200);
  set("force_factor",10);
//  set("kee",1500);
  set("max_kee",1500);
//  set("gin",1500);
  set("max_gin",1500);
//  set("sen",1500);
  set("max_sen",1500);
  set_skill("sha-array",80);
  set_skill("shaforce",50);       
  set_skill("force",50);
  set_skill("sha-steps",80);
  set_skill("cure",40);
  set_skill("shasword",85);
  set_skill("sword",90);
  set_skill("dodge",80);
  set_skill("parry",100);
  set_skill("move",80);
  set_skill("array",80);
  map_skill("dodge","sha-steps");
  map_skill("move","sha-steps");
  map_skill("array","sha-array");
  map_skill("sword","shasword");
  map_skill("force","shaforce");
  set("str", 30);
  set("cor", 30);
  set("per", 25);
  set("int", 30);
  set("cps",20);
  set("con", 30);
  set("spi", 15);
  set("kar", 30);
  setup();
  carry_object("/open/gsword/obj/sword-1.c")->wield();
  carry_object("/open/gsword/obj/nine_hat.c")->wear();
  add_money("gold",5);
  set("inquiry",([
    "武林盟主" : (: ask_leader() :),
  ]));
}

int accept_fight(object me)
{
  if((int)me->query("combat_exp")<=100000)
  {
    command("say 刀劍無眼，傷了你就不好了");
    return 0;
  }
  command("say 出招吧！");
  return 1;
}

void attempt_apprentice(object ob)
{
  if(!ob->query_temp("allow_1"))
  {
    command("say 師父說過，不能亂收弟子！");
    return 0;
  }
  command("smile");
  command("say 既然師父答應了，我就收你為徒吧！");
  command("recruit "+ob->query("id"));
  ob->set("marks/仙劍七俠",1);
}

void die()
{
  object head,winner = query_temp("last_damage_from");
  int j;
  if(!winner)
  {
    ::die();
    return ;
  }

  if(winner->query_temp("head") == 3 )
  { //要求解第三進職的玩家，一定要自己殺死七子之一
    //所以設下head 4，如果不是在解第三進職的玩家，並不會拿到人頭
    message_vision(HIY"可惡！居然會敗在你的手下，看來武林將有一陣腥風血雨。\n"NOR,this_object());
    message_vision("說完之後他就倒下了……\n",this_object());
    winner->set_temp("head",4);
    head=new("/open/killer/headkill/obj/sword_head.c");
    head->move(this_object());
  }
  if ((winner->query("class") == "killer") && (winner->query_temp("head") != 4))
  { //避免條件連續兩次成立（因為解headkill之謎的一定是殺手）
    //想將七子的人頭加在殺人名單中，所以是殺手來砍七子，亦可以得到人頭
    //但是因為不是在解第三進職，所以並不會設定步驟值
    message_vision(HIY"可惡！居然會敗在你的手下，看來武林將有一陣腥風血雨。\n"NOR,this_object());
    message_vision("說完之後他就倒下了……\n",this_object());
    head=new("/open/killer/headkill/obj/sword_head.c");
    head->move(this_object());
  }
  if(userp(winner) && winner->query_temp("not_robot") > time() )
  {
    if ( winner->query_temp("bless")==1 )
    {
      j=random(-1);
      if( j==7 || j==77 || j== 777 || j==1111 || j==55 || j==555 || j==1000 || j==4000 || j==3333 || j==2222 )
      {
        new("/open/sky/obj6/sun_diamond")->move(environment(winner));
        message_vision(HIM"\n從張乘風的身上掉下了一件奇怪的東西!!\n"NOR,winner);
        write_file("/log/sky/obj6/sun_diamond",sprintf("%s(%s) 讓張乘風掉下了太陽之光鑽於 %s\n",
        winner->name(1),winner->query("id"),ctime(time())));
      }
    } else {
      j=random(-1);
      if( j==5 || j==15 || j== 150 || j==1500 || j==10 || j==100 || j==1000 || j==4000 || j==6666 || j==7777 ) 
      {
        new("/open/sky/obj6/sun_diamond")->move(environment(winner));
        message_vision(HIM"\n從張乘風的身上掉下了一件奇怪的東西!!\n"NOR,winner);
        write_file("/log/sky/obj6/sun_diamond",sprintf("%s(%s) 讓張乘風掉下了太陽之光鑽於 %s\n",
        winner->name(1),winner->query("id"),ctime(time())));
      }
    }
  }
  ::die();
}

string ask_leader()
{
  object me=this_player(),npc=this_object(),ob;
  string item_kinds;
  item_kinds="sword";
  if( me->query_temp("ask_leader/start")!=3 || me->query_temp("ask_leader/teng")==1 )
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
    command("say 來拜師的嗎？我師在裡面，請進。");
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
  me->set_temp("ask_leader/teng",1); //詢問過仙劍派的紀錄mark
  return "";
}
