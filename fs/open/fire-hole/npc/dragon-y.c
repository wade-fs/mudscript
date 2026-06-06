//修正心跳問題與限制exp上限bye cyw at 91/04/02
//修正exp上限到2500萬,與調整色龍max_kee,與色龍pill數量 by kalin 91/12/16
//將掉落道具的判定改為last_damage_from 而非this_player() 且 將傷害形式改為receive_damage by blazakira 2011/4/11

inherit NPC;
inherit F_MASTER;
#include "/open/open.h"
#include <ansi.h>

void create()
{
  object ob;
  set_name("黃光火龍", ({ "yellow dragon","dragon","yellow" }) );
  set("long",
    "全身泛著黃光的火龍，守護著火龍窟的結界交點。\n");
  set("race", "野獸");
  set("title",HIY"(黃光)"NOR);
  set("age", 45000);
  set("attitude", "aggressive");
  set("family/family_name","火龍窟");
  set("max_gin", 180000);
//  set("max_kee", 180000);
  set("max_kee", 100000);
  set("max_sen", 180000);
  set("max_force", 2000000);
  set("force", 2000000);
  set("force_factor",20);
  set("str", 99);
  set("cor", 99);
  set("spi", 99);
  set("int", 99);
  set("bellicosity",10000);
  set("limbs", ({ "頭部", "身體", "前爪", "後爪", "尾巴" }) );
  set("verbs", ({ "bite", "claw" }) );
  set_temp("apply/attack", 200);
  set_temp("apply/damage", 200);
  set_temp("apply/armor",  200);
//  set("combat_exp", 18000000);
  set("combat_exp", 20000000);
  set_skill("move",150);
  set_skill("dodge",150);
  set_skill("parry",150);
  set_skill("unarmed",200);
  set_skill("force",500);
  set_temp("no_badroar_max",1);
  set_temp("kang-power",1);
  set_temp("def_fire",1);
  set("no_plan_follow",1);
  set_temp("no_die_soon",1);
  set_temp("todie",3);
  setup();
  ob=carry_object("/open/fire-hole/obj/dragon_claws")->wield();
  ob=carry_object("/open/fire-hole/obj/y-pill.c");
  ob->set_amount(5);
}

void heart_beat()
{
  object env,mob,target,obj;
  mixed enemy;
  int i,hurt,j,defire=0,ohurt;

  mob = this_object();
  env = environment(mob);
  if(!mob || !env) return ;
/*
  message_vision( "<< " + mob->query("force") + "/" +
    mob->query("force_factor") + " ==> " + mob->query("kee") + " >>\n", mob);
*/

  mob->clear_condition();

  if (query("kee") < 0) {
    mob->die();
    return ;
  }

  if (mob->query("force") < 1000000) { // 總要讓 dragon 用什麼來轉換吧？wade
    mob->set("force",1250000);
    mob->set("force_factor",40);
    message_vision(HIR"\n黃光火龍燃起熾熱火焰將自身的內力倍增六成!!\n"NOR,mob);
  }

  if (mob->query("kee")<90000 && random(200)<50 && !mob->is_busy())
  {
/*
    mob->receive_curing("kee",4000);
    mob->receive_heal("kee",4000);
*/
    message_vision(HIY"\n黃光火龍運起神功\為自身療傷，傷口也慢慢癒合了\n"NOR,mob);
    mob->receive_curing("kee",2000);
    mob->receive_heal("kee",2000);
  }
/*
  if (mob->query("kee") < mob->query("max_kee")) {
    mob->receive_curing("kee",500);
    mob->receive_heal("kee",500);
    mob->add("force",10000);
  }
*/

//  if (!mob->is_fighting() || mob->is_fighting())
//  {
  for (j=0 ; j < i ; j++)
  {
    if (!enemy[j]->is_fighting() && enemy[j]->is_character() && !enemy[j]->is_corpse()
        && living(enemy[j]) && enemy[j]->query("id")!="yellow dragon" && userp(enemy[j]) && !wizardp(enemy[j]))
      mob->kill_ob(enemy[j]);
  }
//  }

  if(random(10) > 4)
  {
    enemy = all_inventory( environment(mob) );
    if(!enemy) return;
    i=sizeof(enemy);
    target=enemy[random(i)];
    if (mob->is_fighting() && mob->query_temp("unconcious") != 1)
    {
      message_vision(HIY"\n黃光火龍雙眼一睜, 強烈的黃光由黃光火龍眼睛射出, 刺眼的光線遮蔽了你的視線!!\n"NOR,mob);
      for (j=0 ; j < i ; j++)
      {
        if(enemy[j]){
          if( enemy[j]->is_character() && !enemy[j]->is_corpse() && living(enemy[j])
             && enemy[j]->query("id")!="yellow dragon"
             && environment(this_object())==environment(enemy[j]))
          {
            hurt = 800+random(700);
            if (enemy[j]->query("class")=="fighter" && enemy[j]->query_temp("keeup")==1)
              hurt=hurt*2;
            if (enemy[j]->query("class")=="scholar" ||
                (enemy[j]->query_temp("def_fire")==1
                && enemy[j]->query_temp("def_fire1")==1
                && enemy[j]->query("ring_type")>3))
              {enemy[j]->start_busy(1);}
            else
              {enemy[j]->start_busy(2);}
            if(!userp(enemy[j])) enemy[j]->unconcious();
            if(!enemy[j]) continue;
            if (hurt < 0) hurt =50; //不增加前列之傷害 但是至少給予基礎傷害 by blazakira
            enemy[j]->receive_damage("kee",hurt,mob);
            COMBAT_D->report_status(enemy[j]);
          }
        }
      }
    }
  }
  for(j=0 ; j < i ; j++)
  {
    if(enemy[j])
    {
      if( enemy[j]->is_character() && !enemy[j]->is_corpse() && living(enemy[j])
         && enemy[j]->query("id")!="yellow dragon" && environment(this_object())==environment(enemy[j])
         && userp(enemy[j]) && !enemy[j]->query("shan_yun_sword") )
      {
        enemy[j]->add_temp("fight_yellow",1);
      }
    }
  }
  set_heart_beat(1);
  ::heart_beat();
}

void die()
{
  int i,j,h=0,exp,pot,total_exp,total_pot,k=0;
  object *enemy,mob,me,spirit;
  me = query_temp("last_damage_from");
  mob = this_object();
  enemy = mob->query_enemy();
  i=sizeof(enemy);
  for (j=0 ; j < i ; j++)
  {
    if(enemy[j] && environment(this_object()) == environment(enemy[j]) && enemy[j]->is_character() && userp(enemy[j]) && !enemy[j]->query("shan_yun_sword") )
    {
      k = k + enemy[j]->query_temp("fight_yellow");
      h = h + 1;
    }
  }
  if(h==1)
  {
    total_exp = 9000;
    total_pot = 1800;
  }
  else if(h==2)
  {
    total_exp = 14000;
    total_pot = 3000;
  }
  else if(h==3)
  {
    total_exp = 18000;
    total_pot = 3600;
  }
  else if(h==4)
  {
    total_exp = 21000;
    total_pot = 4100;
  }
  else {
    total_exp = 4000*h;
    total_pot = 900*h;
    if(total_exp > 30000) total_exp = 30000;
    if(total_exp > 6500) total_pot = 6500;
  }
  for (j=0 ; j < i ; j++)
  {
    if(enemy[j]){
      if(environment(this_object())==environment(enemy[j]))
      {
        if(k!=0)
        {
          exp = total_exp*(enemy[j]->query_temp("fight_yellow")) / k;
          pot = total_pot*(enemy[j]->query_temp("fight_yellow")) / k;
        }else{
          exp = 10000; //秒殺
          pot = 2000;
        }
        if(enemy[j]->query("combat_exp") < 25000000)
        {
          tell_object(enemy[j],HIY"\n由於你的努力, 終於打倒了黃光火龍, 你辛苦的代價換來了寶貴的經驗!!\n"NOR);
          tell_object(enemy[j],HIC"你的戰鬥經驗上升 "+exp+" 點, 潛在能力上升 "+pot+" 點!!\n"NOR);
          enemy[j]->add("combat_exp",exp);
          enemy[j]->add("potential",pot);
          enemy[j]->delete_temp("fight_yellow");
        }
      }
    }
  }
  if( present("dragon claws",this_object()) )
  {
    object ob = present("dragon claws",this_object());
    ob->move("/open/fire-hole/fire2");
    environment(ob)->set_temp("ko_y",1);
    destruct(ob);
  }
  if( random(36) == 18 && userp(me) )
  {
    spirit = new("/open/ghost-hole/obj/fire-spirit");
    spirit->move(me);
//    write_file("/log/sky/spirit/fire-spirit",sprintf("%s(%s)讓黃光火龍掉下了%s於 %s\n",me->name(1),me->query("id"),spirit->query("name"),ctime(time())));
    log_file("sky/spirit/fire-spirit",sprintf("%s(%s)讓黃光火龍掉下了%s於 %s\n",me->name(1),me->query("id"),spirit->query("name"),ctime(time())));
    message_vision(HIW"薀含在"+this_object()->query("name")+HIW"身體中的"+spirit->query("name")+HIW"飛射而出，落在$N"HIW"手中。\n"NOR,me);
  }
  environment(mob)->set("no_reset",1);
  environment(mob)->start();
  ::die();
}
