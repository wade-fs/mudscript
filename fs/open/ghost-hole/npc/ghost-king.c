//新增銀針門doctor_book quest的關鍵道具的相關動作 by blazakira 2011/1/21
//將add("kee")調整為receive_damage的攻擊參數並補上攻擊方之參數 by blazakira 2011/4/23

inherit NPC;
#include <killed.fun>       // 7.21.93 by Firedancer
#include <count-time.fun>   // 7.21.93 by Firedancer
#include <ansi.h>

void create()
{
  set_name("死靈骨魔", ({ "death ghost king","death","ghost","king" }) );
  set("long",
  "他是死靈幽谷的玄冥之氣所匯集而成的魔物，憑著己身強大的力量，把死靈界
掌握於手中，其『玄冥神掌』更是讓人不敢恭維。\n");
  set("gender","男性");
  set("title",BLU + "玄冥魔神" + NOR);
  set("age", 100000);
  set("class", "bandit");
  set("attitude", "aggressive");
  set("max_gin", 300000);
  set("max_kee", 500000);
  set("max_sen", 300000);
  set("max_force", 200000);
  set("force", 200000);
  set("force_factor",20);
  set("str", 99);
  set("cor", 99);
  set("spi", 99);
  set("int", 99);
  set("bellicosity",10000);
  set_temp("apply/attack", 200);
  set_temp("apply/damage", 200);
  set("no_plan_follow",1);
  set_temp("no_die_soon",1);
  set_temp("apply/armor",  200);
  set_skill("move",150);
  set_skill("dodge",150);
  set_skill("parry",150);
  set_skill("force",500);
  set_skill("sword",120);
  set_skill("badstrike",120);
  set_skill("badforce",300);
  set_skill("ghost-steps",120);
  set_skill("fire-kee",120);
  set_skill("badsword",120);
  set("fire_strike",1);
  set("super_fire",1);
  set("del_delay",1);
  set("sec_kee","tiger");
  map_skill("force", "badforce");
  map_skill("unarmed", "badstrike");
  map_skill("sword", "badsword");
  map_skill("parry", "fire-kee");
  set("functions/badroar/level",300);
  set("quests/badroar",1);
  set("combat_exp", 25000000);
  set("chat_chance_combat",20);
  set("chat_msg_combat",({
    (: perform_action, "unarmed.badroar" :),
  }));

  setup();
  carry_object("/open/badman/obj/yensword.c")->wield();
}

void heart_beat()
{
  object env,mob,target,obj;
  mixed enemy;
  int i,hurt,j=0;
  int yun=0;
  mob = this_object();
  env = environment(mob);
  if(!env) return ;
  enemy = all_inventory( environment(mob) );
  i=sizeof(enemy);

  if(mob->query("kee") < 250000 && random(100) < 50)
  {
    message_vision( HIR + "\n死靈骨魔大吼一聲，吐出幾口瘀血，臉色看起來好多了。\n" + NOR,mob);
    mob->receive_curing("kee",1000);
    mob->receive_heal("kee",1000); 
  }
  if (mob->query("force") < 100000) 
  {
    mob->set("force",150000);
    mob->set("force_factor",10);
    message_vision( HIG + "\n死靈骨魔趁大家不注意的時候，偷偷吞下一顆雪蓮丹!!\n" + NOR,mob);
  }

//  if (!mob->is_fighting() || mob->is_fighting()) //<<<<這是什麼判斷？？ 不解 暫時取消 by blazakira
//  {
  for (j=0 ; j < i ; j++) //看起來這判斷是在抓煉妖壺的軒轅劍俠 by blazakira
  { //既然enemy設定為房間內所有人 就不是取得戰鬥中的敵人(query_enemy) 那就不用判斷戰鬥與否吧 by blazakira
    if (!enemy[j]->is_fighting() && enemy[j]->is_character() && !enemy[j]->is_corpse() &&
        living(enemy[j]) && enemy[j]!=mob && !wizardp(enemy[j])) 
      mob->kill_ob(enemy[j]);
    if(enemy[j]->query("id") == "shan yun") yun = yun + 1;
  }
//  }

  if(random(10) > 5 || yun > 4)
  {
    if (mob->is_fighting())
    {
      for (j=0 ; j < i ; j++)
      {
        if( enemy[j]->is_character() && !enemy[j]->is_corpse() && living(enemy[j]) &&
            enemy[j]->query("id")!="death ghost king")
        {
          message_vision( HIB + "\n一股玄冥之氣排山倒海而來，強大的氣力壓得你喘不過氣來！！\n" + NOR,mob);
          enemy[j]->receive_damage("kee",2000,mob);
          enemy[j]->start_busy(random(2));
          if(yun > 4 && enemy[j]->query("id") == "shan yun") enemy[j]->receive_wound("kee",enemy[j]->query("max_kee"),mob);
          COMBAT_D->report_status(enemy[j]);
        }
      }
    }
  }
  set_heart_beat(1);
  ::heart_beat();
}

void die()
{
  object me,ob,ob1;
  me=query_temp("last_damage_from");
//  ob=new(__DIR__"test01");
//  ob1=new(__DIR__"test02");
  ob=new("/open/ghost-hole/obj/jug.c");
  me->set_temp("ko_ghost_king",1);
  tell_object(users(),HIW + "
                ～～" + HIB + "死靈幽谷傳來一陣淒涼的哀嚎聲" + HIW + "～～

                    " + HIB + "死靈骨魔大吼：好個 "+me->query("name")+" ～～ 

                      本王一定會再回來人間的 ～～
" + NOR);
  if ( kill_jobs(5,me,this_object(),"area/hole_stone") ) finish_time(me,"area/hole_stone"); else start_time(me,"area/hole_stone"); // 7.21.93 by Firedancer
  if( random(100) < (int)me->query_kar() )
  {
    tell_object(me,HIY + "\n骨魔幻滅後～地上掉落了一件物品！\n\n" + NOR);
    ob->move("/open/ghost-hole/g-s06.c");
  }
  if( me->query("clan/id") ) CLAN_D->add_clanset( me->query("clan/id"), "develop" , 20 );

//加入銀針門神農quest所需 temp by blazakira
  if (me && me->query("family/family_name")=="銀針門" && random(100) > 30 && query_temp("record_damage/"+me->query("id")) > query("max_kee")/5) {
    me->set_temp("spiritup",query("id"));
  }

  ::die();
}

void record_damage(int damage, object who)
{
  if(!who) return ;
  if(who && !userp(who)) return ;
  add_temp("record_damage/"+who->query("id") , damage);
}
varargs int receive_damage(string type, int damage, object who)
{
  ::receive_damage(type,damage,who);
  who = query_temp("last_damage_from");
  record_damage(damage,who);
}
varargs int receive_wound(string type, int damage, object who)
{
  ::receive_wound(type,damage,who);
  who = query_temp("last_damage_from");
  record_damage(damage,who);
}
