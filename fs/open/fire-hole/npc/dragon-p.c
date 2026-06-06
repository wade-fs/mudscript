//修正心跳問題與限制exp上限並增加1/100的機會使ppl中入滅 bye cyw at 91/04/02
//修正exp上限到2500萬,與調整色龍max_kee,與色龍pill數量,調高火龍麟防火效果 by kalin 91/12/16
//將die()裡的me=this_player()改為last_damage_from 且 將receive_damage補上攻擊者 by blazakira 2011/4/11

inherit NPC;
inherit F_MASTER;
#include "/open/open.h"
#include <ansi.h>

void create()
{
  object ob;
  set_name("紫光火龍", ({ "poison dragon","dragon","poison" }) );
  set("long",
    "全身泛著紫光的火龍，守護著火龍窟的結界交點。\n");
  set("race", "野獸");
  set("title",HIM"(毒氣)"NOR);
  set("age", 49000);
  set("attitude", "aggressive");
  set("family/family_name","火龍窟");
  set("max_gin", 120000);
//  set("max_kee", 120000);
  set("max_kee", 100000);
  set("max_sen", 12000);
  set("max_force", 2000000);
  set("force", 2000000);
  set("force_factor",10);
  set("str", 99);
  set("cor", 99);
  set("spi", 99);
  set("int", 99);
  set("bellicosity",10000);
  set("limbs", ({ "頭部", "身體", "前爪", "後爪", "尾巴" }) );
  set("verbs", ({ "bite", "claw" }) );
  set_temp("apply/attack", 200);
  set_temp("apply/damage", 200);
  set("no_plan_follow",1);
  set_temp("no_die_soon",1);
  set_temp("apply/armor",  200);
  set_skill("move",150);
  set_skill("dodge",150);
  set_skill("parry",150);
  set_skill("force",500);
//  set("combat_exp", 16000000);
  set("combat_exp", 20000000);
  set_temp("no_badroar_max",1);
  set_temp("kang-power",1);
  set_temp("def_fire",1);
  set_temp("todie",3);
  setup();
  ob=carry_object("/open/fire-hole/obj/dragon_claws")->wield();
  ob=carry_object("/open/fire-hole/obj/p-pill.c");
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
    message_vision( HIR
   "\n紫光火龍燃起熾熱火焰將自身的內力倍增六成!!\n"NOR,mob);
  }

  if ( mob->query("kee")<90000 && random(200)<50 && !mob->is_busy())
  {
/*
    mob->receive_curing("kee",4000);
    mob->receive_heal("kee",4000);
*/
    message_vision( HIY "\n紫光火龍運起神功\為自身療傷，傷口也慢慢癒合了\n"NOR,mob);
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
      if (!enemy[j]->is_fighting() && enemy[j]->is_character() && !enemy[j]->is_corpse() &&
          living(enemy[j]) && enemy[j]->query("id")!="poison dragon" && userp(enemy[j]) && !wizardp(enemy[j]))
        mob->kill_ob(enemy[j]);
    }
//  }

 if(random(10) > 3)
 {
    enemy = all_inventory( environment(mob) );
    if(!enemy) return;
    i=sizeof(enemy);
    target=enemy[random(i)];
    if (mob->is_fighting())
    {
      message_vision(HIM"\n紫光火龍從口中噴出一道紫色毒霧, 充滿毒性的氣體瀰漫在四周!!\n"NOR,mob);
      for (j=0 ; j < i ; j++)
      {
        if(enemy[j]){
        if( enemy[j]->is_character() && !enemy[j]->is_corpse() && living(enemy[j])
           && enemy[j]->query("id")!="poison dragon"
           && environment(this_object())==environment(enemy[j]))
        {
          hurt = 200+random(800);
          if (enemy[j]->query("class")=="fighter" && enemy[j]->query_temp("keeup")==1)
          hurt = hurt * 3;
          if (random(100)==13){
          tell_object (enemy[j],HIG"慘了!這好像是魔界奇毒『入滅』!!\n"NOR);
          if(userp(enemy[j])) log_file("mogi/poison", sprintf("%s(%s) 中入滅之毒 on %s\n",enemy[j]->query("name"),enemy[j]->query("id"), ctime(time()) ));
          enemy[j]->apply_condition("mogi",5);}
          if (enemy[j]->query("class")!="poisoner")
          {
            enemy[j]->apply_condition("ff_poison",15);
            enemy[j]->apply_condition("flower_poison",15);
            enemy[j]->apply_condition("snake_poison",15);
            enemy[j]->apply_condition("super_snake_poison",15);
            enemy[j]->apply_condition("dark_poison",15);
            enemy[j]->apply_condition("hart",15);
            enemy[j]->apply_condition("enforce_poison",15);
            enemy[j]->apply_condition("rose_poison",15);
            enemy[j]->apply_condition("scorpion_poison",15);

            enemy[j]->set("five",1000);
            enemy[j]->set("suck",1000);}
            if (hurt < 0) hurt =50; //不增加前列之傷害 但是至少給予基礎傷害 by blazakira
            enemy[j]->receive_damage("kee",hurt,mob);
            if(!userp(enemy[j])) enemy[j]->unconcious();
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
      if( enemy[j]->is_character() && !enemy[j]->is_corpse() && living(enemy[j]) &&
          enemy[j]->query("id")!="purple dragon" && environment(this_object())==environment(enemy[j]) &&
          userp(enemy[j]) && !enemy[j]->query("shan_yun_sword") )
      {
        enemy[j]->add_temp("fight_purple",1);
      }
    }
  }
  set_heart_beat(1);
  ::heart_beat();
}

void die()
{
  int i,j,h=0,exp,pot,total_exp,total_pot,k=0;
  object *enemy,mob,me;
  me = query_temp("last_damage_from");
  mob = this_object();
  enemy = mob->query_enemy();
  i=sizeof(enemy);
  for (j=0 ; j < i ; j++)
  {
    if(enemy[j] && environment(this_object()) == environment(enemy[j]) && enemy[j]->is_character() && userp(enemy[j]) && !enemy[j]->query("shan_yun_sword") )
    {
      k = k + enemy[j]->query_temp("fight_purple");
      h = h + 1;
    }
  }
  if(h==1)
  {
    total_exp = 8000;
    total_pot = 1600;
  }
  else if(h==2)
  {
    total_exp = 13000;
    total_pot = 2900;
  }
  else if(h==3)
  {
    total_exp = 17000;
    total_pot = 3900;
  }
  else if(h==4)
  {
    total_exp = 20000;
    total_pot = 4700;
  }
   else
  {
    total_exp = 3800*h;
    total_pot = 800*h;
    if(total_exp > 28000) total_exp = 28000;
    if(total_exp > 6300) total_pot = 6300;
  }
  for (j=0 ; j < i ; j++)
  {
    if(enemy[j]){
      if(environment(this_object())==environment(enemy[j]))
      {
        if(k!=0)
        {
          exp = total_exp*(enemy[j]->query_temp("fight_purple")) / k;
          pot = total_pot*(enemy[j]->query_temp("fight_purple")) / k;
        }else{
         exp = 9000;
         pot = 1800;
        }
        if(enemy[j]->query("combat_exp") < 25000000)
        {
          tell_object(enemy[j],HIY"\n由於你的努力, 終於打倒了紫光火龍, 你辛苦的代價換來了寶貴的經驗!!\n"NOR);
          tell_object(enemy[j],HIC"你的戰鬥經驗上升 "+exp+" 點, 潛在能力上升 "+pot+" 點!!\n"NOR);
          enemy[j]->add("combat_exp",exp);
          enemy[j]->add("potential",pot);
          enemy[j]->delete_temp("fight_purple");
        }
      }
    }
  }
  if( present("dragon claws",this_object()) )
  {
    object ob = present("dragon claws",this_object());
    ob->move("/open/fire-hole/fire2");
    environment(ob)->set_temp("ko_p",1);
    destruct(ob);
  }
  environment(mob)->set("no_reset",1);
  environment(mob)->start();
  ::die();
}
