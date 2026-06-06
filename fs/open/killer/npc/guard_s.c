//將他攻擊力改弱了，但防禦力增加，以免殺人過多
//增加新手quest 尋找武林盟主的下落 by blazakira 2011/6/30

#include <ansi.h>
#include "/open/open.h"
inherit NPC;

object ob1=this_object();
object ob2;
int have_say;

string ask_leader();

void create()
{
  object ob;
  set_name("楊心婷", ({"shi-tin","tin"}));
  set("long","雖然是女性，你可別小看她哦，能當上殺手侍衛長可是不簡單人物。\n");
  set("gender","女性");
  set("class","killer");
  set("combat_exp",200000);
  set("attitude","heroism");
  set("age",26);
  set("title","殺手侍衛長");
  set("max_kee",2500);
  set("kee",2500); 
  set("max_force",1200);
  set("force",1200);
  set("force_factor",3);

  set_skill("throwing", 40);
  set_skill("blackforce", 60);
  set_skill("dodge", 120);
  set_skill("force",50);
  set_skill("move", 120);
  set_skill("parry", 120);
  set_skill("shade-steps",120);
  set_skill("rain-throwing",120);
  map_skill("force","blackforce");
  map_skill("throwing","rain-throwings");
  map_skill("dodge","shade-steps");
  map_skill("move","shade-steps");
  set("inquiry",([
    "武林盟主" : (: ask_leader() :),
  ]));
  setup();
  add_money("gold",3);
  ob2=carry_object("/open/killer/obj/lustar.c");
  ob2->add_amount(200);
  ob2->wiled();
  carry_object("/open/killer/weapon/k_cloth2.c")->wear();
  carry_object("/open/killer/weapon/k_belt2.c")->wear();
  carry_object("/open/killer/weapon/k_arm2.c")->wear();
  carry_object("/open/killer/weapon/k_cap2.c")->wear();
  carry_object("/open/killer/memory/static.c")->wear();
}

int accept_fight(object who)
{
  return notify_fail("嘿……你把這裡當遊樂場嗎？\n");
}

int accept_kill(object ob)
{
  int i,j,havekill;
  object ob1, hu_fa, *all;
  ob1 = this_object();
  add_temp("kill_me",1);
  ob->set_temp("kill_tin",1);
//  havekill=ob1->query("guard");
      
  if( !present("guard", environment(ob)) ) 
  {
    tell_room(environment(ob),HIW"\n隱藏在暗處的兩位殺手侍衛突然衝出護駕!!\n\n"NOR);
 //    if(!havekill) 這邊寫的怪怪的似乎沒作用所以先拿掉
 //      ob1->set("guard",1);
 //    else
    for(i=0;i<2;i++)
    {
      hu_fa = new("/open/killer/npc/guard");
      hu_fa->move(environment(ob));
      hu_fa->command("guard behavior_elder");
      hu_fa->command("follow "+ob->query("id"));
      hu_fa->kill_ob(ob);
    }
  }
  tell_object(this_player(),HIR "殺手侍衛長楊心婷叫道：留下你的人頭！\n" NOR);
  if(query_temp("kill_me")>5)
  {
    message_vision( HIY"\n楊心婷突然殺氣大增，將在場圍觀者全部逼出戰場!!\n"NOR,ob1);
    set("title",MAG"〈殺氣騰騰〉"NOR); 
    set("attitude","aggressive");
    all = all_inventory( environment(ob1) );
    j=sizeof(all);
    for(i=0;i<j;i++)
    {
      if(all[i]->query("id")!="shi-tin" && all[i]->query("id")!="killer guard"
          && !all[i]->query_temp("kill_tin",1) 
          && !all[i]->is_corpse() && living(all[i]))
        all[i]->move("/open/killer/room/outr0.c");
    }
  }
  ob->delete_temp("kill_tin",1);          
  return 1;
}

void greeting(object ob)
{
  if(!ob) return ;
  if (present("five poison",ob) ) 
  {
    command("say 想用毒,門都沒有!!");
    kill_ob(ob);
  }
  if( ob->query("class")=="blademan" && ob->query("combat_exp") > query("combat_exp") ) //由於新增與新手quest相關 於是額外添加經驗的判斷 by blazakira
  {
    command("say 你是刀客，真是不幸的職業，一顆人頭值不了多少錢。\n");
    kill_ob(ob);
  }
}

string ask_leader()
{
  object me=this_player(),npc=this_object(),ob;
  string item_kinds;
  item_kinds="throwing";
  if( me->query_temp("ask_leader/start")!=3 || me->query_temp("ask_leader/killer")==1 )
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
    command("say 那狗天子懷疑我們與海外有所掛勾，似乎要藉機剷除我們。");
  }
  else if( me->query("family")==npc->query("family") ) {
    command("say 武學之道視你勤奮的程度，期待你早日將我派揚威天下。");
    if( random(2) ) {
      command("say 這是一些盤纏，或許對你有所幫助。");
      ob=new("/obj/money/silver.c")->set_amount(random(20)+10);
      command("give silver to "+me->query("id"));
    }
    command("say 那狗天子懷疑我們與海外有所掛勾，似乎要藉機剷除我們。");
    command("say 不過頭目準備將計就計，派人攻打來自外海的刺客。");
    command("say 這是門派任務，可將本門揚威武林，你要努力爭取呀。");
  }
  else {
    command("say 那狗天子懷疑我們與海外有所掛勾，似乎要藉機剷除我們。");
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
  me->set_temp("ask_leader/killer",1); //詢問過殺手的紀錄mark
  return "";
}
