//修正exp上限到2000萬 by kalin 91/12/16
inherit NPC;
inherit F_MASTER;
#include "/open/open.h"
#include <ansi.h>
void create()
{
        set_name("小火龍", ({ "small dragon","dragon","small" }) );
        set("long",
                "幼小的火龍, 雖然幼小, 但是其氣魄已經十分驚人。\n");
        set("race", "野獸");
        set("age", 100);
        set("attitude", "friendly");
        set("family/family_name","火龍窟");
        set("max_gin", 100000);
        set("max_kee", 100000);
        set("max_sen", 100000);
        set("max_force", 100000);
        set("force", 100000);
        set("force_factor",20);
        set("str", 99);
        set("cor", 99);
        set("spi", 99);
        set("int", 99);
        set("bellicosity",10000);
        set("limbs", ({ "頭部", "身體", "前爪", "後爪", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );
        set_temp("apply/attack", 100);
        set_temp("apply/damage", 100);
        set_temp("apply/armor",  200);
        set("combat_exp", 15000000);
        set_skill("move",150);
        set_skill("dodge",150);
        set_skill("parry",150);
        set_skill("force",350);
	set_skill("unarmed",150);
	set_skill("rabbit-combat",100);
	map_skill("unarmed","rabbit-combat");
        set_temp("kang-power",1);
        set_temp("def_fire",1);
        set_temp("todie",3);
        setup();
}
void heart_beat()
{
  object env,mob,target,obj;
  mixed enemy;
  int i,hurt,j=0,defire=0,ohurt;

  mob = this_object();
  env = environment(mob);
  if(!env) return ;
/*
  message_vision( "<< " + mob->query("force") + "/" +
    mob->query("force_factor") + " ==> " + mob->query("kee") + " >>\n", mob);
*/

  mob->clear_condition();

  if (query("kee") < 0) {
    mob->die();
    return ;
  }
  if (mob->query("force") < 50000) {
    // 總要讓 dragon 用什麼來轉換吧？wade
    mob->set("force",60000);
    mob->set("force_factor",40);
    message_vision( HIR
         "\n小火龍燃起熾熱火焰將自身的內力倍增六成!!\n"NOR,mob);
  }

  if ( mob->query("kee")<90000 &&
       random(200)<50 && !mob->is_busy())
  {
   /*
     mob->receive_curing("kee",4000);
     mob->receive_heal("kee",4000); 
   */

    message_vision( HIY "\n小火龍運起神功\為自身療傷，傷口也慢慢癒合了\n"NOR,mob);
    mob->receive_curing("kee",500);
    mob->receive_heal("kee",500); 
  }
/*
  if (mob->query("kee") < mob->query("max_kee")) {
    mob->receive_curing("kee",500);
    mob->receive_heal("kee",500);
    mob->add("force",10000);
  }
*/
 if(random(10) > 5)
 {
    enemy = all_inventory( environment(mob) );
    i=sizeof(enemy);
    target=enemy[random(i)];
    if(mob->is_fighting())
    {
        message_vision( HIR
        "\n小火龍從口中狂噴出火焰!!\n"NOR,mob);
       // mob->delete_busy()
//沒道理心跳已經夠強了還加delete_busy    by frequency
        mob->apply_condition("burn", 0);
        for (j=0 ; j < i ; j++)
        {
        if(enemy[j]){   
        if( enemy[j]->is_character() && !enemy[j]->is_corpse() && living(enemy[j])
            && enemy[j]->query("id")!="small dragon"
            && environment(this_object())==environment(enemy[j]))
        {
        hurt = 2000+random(500);
        if(!enemy[j]->query("ring_type"))
        defire=500;
        else if(enemy[j]->query("ring_type")==1)
        defire=600;
        else if(enemy[j]->query("ring_type")==2)
        defire=700;
        else if(enemy[j]->query("ring_type")==3)
        defire=800;
        else if(enemy[j]->query("ring_type")==4)
        defire=900;
        else if(enemy[j]->query("ring_type")==5)
        defire=1000;
        if (enemy[j]->query("class")=="fighter" && enemy[j]->query_temp("keeup")==1)
        hurt= 2000+random(2000);       
        if (enemy[j]->query("class")=="scholar" && enemy[j]->query("class")=="poisoner" && enemy[j]->query_temp("def_fire")!=1)
        {hurt = 1700+random(1000);
        tell_object (enemy[j],HIG"你憑著你的機制躲過了小火龍的火焰!!\n"NOR);}
        if (enemy[j]->query_temp("def_fire")==1        //增加火龍鱗與焰氣訣加乘效果
        && enemy[j]->query_temp("def_fire1")==1)           
        {hurt = hurt - defire - 700;
		tell_object (enemy[j],HIG"你身上的焰氣訣與火龍鱗發生共鳴緩和了小火龍的火焰!!\n"NOR);}
        else if (enemy[j]->query_temp("def_fire")==1 ||          
        enemy[j]->query_temp("def_fire1")==1)
        {hurt = hurt - 1000;
		tell_object (enemy[j],HIG"你身上的焰氣訣或火龍鱗發生共鳴緩和了小火龍的火焰!!\n"NOR);}
        else if (enemy[j]->query_temp("gold-fire")==1 &&   //增加極火金身也可以擋掉500點功擊
        enemy[j]->query("functions/gold-fire/level","gold-fire") == 90)
        {tell_object (enemy[j],HIG"你身上的極火金身緩和了小火龍的火焰!!\n"NOR);
		hurt = hurt -500;}       
        enemy[j]->add("kee",-hurt);
        enemy[j]->apply_condition("burn",30);
        COMBAT_D->report_status(enemy[j]);
        }}}
 }
 }   
   set_heart_beat(1);
   ::heart_beat();
   
}
void die()
{
   int i,j;
   object *enemy,mob,me;
   me = this_player();
   mob = this_object();
   enemy = mob->query_enemy();
   i=sizeof(enemy);
        
        for (j=0 ; j < i ; j++)
        {
        if(enemy[j])
         {
          if(environment(this_object())==environment(enemy[j]) && userp(enemy[j]))
           {
            if(enemy[j]->query("combat_exp") < 20000000)
             {
               int exp;
               int pot;
               if(enemy[j]->query_temp("not_robot") > time()) 
              {
                exp = 2000;
                pot = 500;
              }
              else
              {
                exp = 200;
                pot = 50;
              }
              
              tell_object(enemy[j],HIY"\n由於你的努力, 終於打倒了小火龍, 你辛苦的代價換來了寶貴的經驗!!\n"NOR);
              tell_object(enemy[j],HIC"你的戰鬥經驗上升 "+exp+" 點, 潛在能力上升 "+pot+" 點!!\n"NOR);
              enemy[j]->add("potential",pot);
              enemy[j]->add("combat_exp",exp);
             }
           }
          }
         }
   ::die();

}
