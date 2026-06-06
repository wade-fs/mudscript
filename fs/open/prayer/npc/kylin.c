#include <ansi.h>
inherit NPC;
void create()
{
	set_name("血麒麟", ({ "red-kylin","kylin" }) );
	set("race", "野獸");
	set("age", 200);
	set("long", "破邪洞窟中最恐怖的怪獸,全身如火炎般通紅.\n");
	set("str", 100);
	set("max_kee", 10000);
	set("kee", 10000);
	set("max_force", 10000);
	set("gin",10000);
	set("max_gin",10000);
	set("sen",10000);
	set("max_sen",10000);
	set("force",10000);
	set("force_factor",5);
	set("limbs", ({ "頭部", "腹部","身體", "前腳" , "後腳" , "尾巴" }) );
	set("verbs", ({ "bite"}));
	set("combat_exp",1500000);
	set_temp("apply/armor", 300);
	set_temp("apply/attack", 100);
	set("attitude","aggressive");
	set_skill("dodge",130);
	set("chat_chance",3);
	set("chat_msg",({				   
	(: random_move :), }));
	setup(); 
	carry_object("/open/gsword/obj/ff_item");
	carry_object("/open/gsword/obj/f_item");
	set_heart_beat(1);
}
void heart_beat()
{
  object *enemy,me;
  int i;
  me = this_object();
  if( me->is_fighting() )
  {
    if( 50 > random(200) )
    {
      enemy = me->query_enemy();
      i=random(sizeof(enemy));
      if(environment(me) == environment(enemy[i]))
      if( random(10) > 7)
      {
       message_vision(HIR+"血麒麟吐出紅色的毒霧,朝$N的方向襲捲而來!!!\n"+NOR,enemy[i]);
       enemy[i]->receive_damage("kee",450,me);
       COMBAT_D->report_status(enemy[i], 0);
      }else{
      message_vision(HIC+"血麒麟張開血盆大口咬住了$N的頭,大喝一聲:ㄏㄡ ㄉㄚ  ㄌㄚ~~ !!!!!\n"+NOR,enemy[i]);
      enemy[i]->receive_damage("kee",200,me);
      COMBAT_D->report_status(enemy[i], 0);
      me->receive_curing("kee",500);
      me->receive_heal("kee",500);
      }
     }
   }
   if( me->query("kee") < 0 )
      me->die();
   ::heart_beat();
}			      

void die()                                                                 
{    
	object winner = query_temp("last_damage_from");
	int j;

        if(!winner)
	{
	::die();
	return ;
        }
    if(userp(winner) && winner->query_temp("not_robot") > time() )
    {
	if ( winner->query_temp("bless")==1 )
	{
	j=random(-1);
	  if( j==7 || j==77 || j== 777 || j==1111 || j==55 || j==555 || j==1000 || j==4000 || j==3333 || j==2222 )
	  {      
	  new("/open/sky/obj7/kylin-order")->move(environment(winner));
	  message_vision(HIM + "\n從血麒麟的身上掉下了一件奇怪的東西!!\n" + NOR,winner);
          write_file("/log/sky/obj7/kylin_order",sprintf("%s(%s) 讓血麒麟掉下了麒麟結令於 %s\n",
	  winner->name(1),winner->query("id"),ctime(time())));
	  }
	}else{
	j=random(-1);
	  if( j==5 || j==15 || j== 150 || j==1500 || j==10 || j==100 || j==1000 || j==4000 || j==6666 || j==7777 ) 
	  {      
	  new("/open/sky/obj7/kylin-order")->move(environment(winner));
	  message_vision(HIM + "\n從血麒麟的身上掉下了一件奇怪的東西!!\n" + NOR,winner);
          write_file("/log/sky/obj7/kylin_order",sprintf("%s(%s) 讓血麒麟掉下了麒麟結令於 %s\n",
	  winner->name(1),winner->query("id"),ctime(time())));
	  }
	}
	}
	::die();                                                           
}

