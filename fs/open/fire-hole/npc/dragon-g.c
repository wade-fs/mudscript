//修正心跳問題與限制exp上限bye cyw at 91/04/02
//修正exp上限到2500萬,與調整色龍回氣量,與色龍pill數量,調高火龍麟防火效果 by kalin 91/12/16
//將die()裡的me=this_player()改為last_damage_from 且 將傷害形式改為receive_damage by blazakira 2011/4/11

inherit NPC;
inherit F_MASTER;
#include "/open/open.h"
#include <ansi.h>

void create()
{
  object ob;
  set_name("綠光火龍", ({ "green dragon","dragon","green" }) );
  set("long",
    "全身泛著綠光的火龍，守護著火龍窟的結界交點。\n");
  set("race", "野獸");
  set("title",HIG + "(綠光)" + NOR);
  set("age", 50000);
  set("attitude", "aggressive");
  set("family/family_name","火龍窟");
  set("max_gin", 180000);
//  set("max_kee", 180000);
  set("max_kee", 150000);
  set("max_sen", 180000);
  set("max_force", 2000000);
  set("force", 2000000);
  set("force_factor",40);
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
  set_skill("unarmed",200);
  set_skill("force",500);
//  set("combat_exp", 13000000);
  set("combat_exp", 20000000);
  set_temp("no_badroar_max",1);
  set_temp("kang-power",1);
  set_temp("def_fire",1);
  set_temp("todie",3);
  setup();
  ob=carry_object("/open/fire-hole/obj/dragon_claws")->wield();
  ob=carry_object("/open/fire-hole/obj/g-pill.c");
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
    message_vision(HIR + "\n綠光火龍燃起熾熱火焰將自身的內力倍增六成!!\n" + NOR,mob);
  }

  if ( mob->query("kee")<70000 &&
       random(200)<50 && !mob->is_busy())
  {
/*
    mob->receive_curing("kee",4000);
    mob->receive_heal("kee",4000); 
*/

    message_vision( HIY + "\n綠光火龍運起神功\為自身療傷，傷口也慢慢癒合了\n" + NOR,mob);
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

//  if (!mob->is_fighting() || mob->is_fighting()) 不知原作者為何這樣寫,好像有點多此一舉
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
      message_vision(HIG + "\n綠光火龍大吼一聲, 一道強烈的綠光龍捲氣勁襲擊你的身體!!\n" + NOR,mob);
//      mob->delete_busy(); // 理由同小火龍 沒道理心跳已經夠強了還加delete_busy by frequency
      for (j=0 ; j < i ; j++)
      {
        if(enemy[j]){
          if( enemy[j]->is_character() && !enemy[j]->is_corpse() && living(enemy[j]) &&
              enemy[j]->query("id")!="green dragon" &&
              environment(this_object())==environment(enemy[j]))
          {
            hurt = 2000+random(1000);
            if(!enemy[j]->query("ring_type"))
              defire=500;
            else if(enemy[j]->query("ring_type")==1)
              defire=1000;
            else if(enemy[j]->query("ring_type")==2)
              defire=1250;
            else if(enemy[j]->query("ring_type")==3)
              defire=1500;
            else if(enemy[j]->query("ring_type")==4)
              defire=1750;
            else if(enemy[j]->query("ring_type")==5)
              defire=2000;   
            if (enemy[j]->query("class")=="fighter" && enemy[j]->query_temp("keeup")==1)
            { hurt = 3000+random(3000); }
            //kalin 91-12-22 避免將來有新門派的出現,所以修正這裡,只做有無extra kee的區分
            if (!enemy[j]->query_temp("keeup"))
            { hurt = 3000+random(500); }
/*            if (enemy[j]->query("class")=="scholar")
            { hurt = 2500+random(500); }
            if (enemy[j]->query("class")=="blademan" ||
                enemy[j]->query("class")=="swordsman" ||
                enemy[j]->query("class")=="killer" ||
                enemy[j]->query("class")=="bandit")
            { hurt = 2000+random(1500); }
*/
            ohurt=hurt; 
            if (enemy[j]->query_temp("def_fire")==1 && //增加火龍鱗與焰氣訣加乘效果
                enemy[j]->query_temp("def_fire1")==1)
            {
              hurt = hurt - defire - 700;
              tell_object (enemy[j],HIG + "你身上的焰氣訣與火龍鱗發生共鳴緩和了綠光火龍的火焰!!\n" + NOR);}
            else if (enemy[j]->query_temp("def_fire")==1)
            {
              hurt = hurt - 1000;
              tell_object (enemy[j],HIG + "你身上的焰氣訣緩和了綠光火龍的火焰!!\n" + NOR);}
            else if (enemy[j]->query_temp("def_fire1")==1)
            {
              hurt = hurt - defire*1.2;
              tell_object (enemy[j],HIG + "你身上的火龍鱗緩和了綠光火龍的火焰!!\n" + NOR);}
            else if (enemy[j]->query_temp("gold-fire")==1 &&   //增加極火金身也可以擋掉500點功擊
                     enemy[j]->query("functions/gold-fire/level","gold-fire") == 90)
            {
              hurt = hurt -500;
              tell_object (enemy[j],HIG + "你身上的極火金身緩和了綠光火龍的火焰!!\n" + NOR);
            }
//            message_vision( HIG + "\n火龍鱗耐火值為"+defire+",火龍原始害值為"+ohurt+",最後傷害值為"+hurt+"!!\n" + NOR,mob);
            if (hurt < 0) hurt =50; //不增加前列之傷害 但是至少給予基礎傷害 by blazakira
            enemy[j]->receive_damage("kee",hurt,mob);
            enemy[j]->apply_condition("no_power_f",5);
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
          enemy[j]->query("id")!="green dragon" &&
          environment(this_object())==environment(enemy[j]) && userp(enemy[j]) && !enemy[j]->query("shan_yun_sword") )
      {
        enemy[j]->add_temp("fight_green",1);
      }
    }
  }
  set_heart_beat(1);
  ::heart_beat();
}

void die()
{
  int i,h=0,j,exp,pot,total_exp,total_pot,k=0;
  object *enemy,mob,me;
  me = query_temp("last_damage_from");
  mob = this_object();
  enemy = mob->query_enemy();
  i=sizeof(enemy);
  for (j=0 ; j < i ; j++)
  {
    if(enemy[j] && environment(this_object()) == environment(enemy[j]) && enemy[j]->is_character() && userp(enemy[j]) && !enemy[j]->query("shan_yun_sword") )
    {
      k = k + enemy[j]->query_temp("fight_green");
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
    total_exp = 12000;
    total_pot = 2800;
  }
  else if(h==3)
  {
    total_exp = 15000;
    total_pot = 3600;
  }
  else if(h==4)
  {
    total_exp = 18000;
    total_pot = 4200;
  }
  else
  {
    total_exp = 3600*h;
    total_pot = 650*h;
    if(total_exp > 26000) total_exp = 26000;
    if(total_exp > 6000) total_pot = 6000;
  }
  for (j=0 ; j < i ; j++)
  {
    if(enemy[j]){
      if(environment(this_object())==environment(enemy[j]))
      {
        if(k!=0)
        {
          exp = total_exp*(enemy[j]->query_temp("fight_green")) / k;
          pot = total_pot*(enemy[j]->query_temp("fight_green")) / k;
        }else{
          exp = 9000;
          pot = 1800;
        }
        if(enemy[j]->query("combat_exp") < 25000000)
        {
          tell_object(enemy[j],HIY + "\n由於你的努力, 終於打倒了綠光火龍, 你辛苦的代價換來了寶貴的經驗!!\n" + NOR);
          tell_object(enemy[j],HIC + "你的戰鬥經驗上升 "+exp+" 點, 潛在能力上升 "+pot+" 點!!\n" + NOR);
          enemy[j]->add("combat_exp",exp);
          enemy[j]->add("potential",pot);
          enemy[j]->delete_temp("fight_green");
        }
      }
    }
  }
  if( present("dragon claws",this_object()) )
  {
    object ob = present("dragon claws",this_object());
    ob->move("/open/fire-hole/fire2");
    environment(ob)->set_temp("ko_g",1); 
    destruct(ob);
  }
  environment(mob)->set("no_reset",1);
  environment(mob)->start();
  ::die();
}
