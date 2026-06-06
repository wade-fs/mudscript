#include <ansi.h>
inherit NPC;
int step=1;
int done=0;
void create()
{
	set_name("將軍夫人", ({ "general's wife","wife" }) );
	set("gender","女性");
	set("race", "人類");
	set("age", 55);
	set("long", "蜀中將軍的老婆.她似乎懂些妖術,你可不要小看她.\n");
	set("str", 30);
	set("max_gin",400);
	set("max_kee", 2400);
	set("kee", 2400);
	set("max_force", 300);
	set("force", 300);
	set_skill("parry",100); // 防五毒掌用...
	set("combat_exp",200000);
	set_skill("six-fingers", 20);
	set_skill("unarmed", 30);
	set_skill("force",60);
	set("force_factor", 10);
	map_skill("unarmed","six-fingers");	
	set_skill("dodge",60);
	set_skill("linpo-steps", 60);
	map_skill("dodge","linpo-steps");
	setup(); 
	carry_object("/open/doctor/item/sick_item");
	set_heart_beat(1);
}
void heart_beat()
{
  object *enemy,me;
  int i,blood;
  me = this_object();
  if( me->is_fighting() )
  {
   
    if( 80 > random(200) && (step == 1) )
    {
	   say("將軍夫人開始喃喃念咒...\n");
	   done=1;
    }	
    
    if( step == 2)
	  command("close door");
       
    if( step == 4 )
    {	  
	 say("只見四周空間開始扭曲,陣陣妖氣隱隱襲來...\n");
    }
    
    if( step == 5 )
	  command("close door");
   
    if( step == 6 )
    {
	 step = 1;
	 done = 0;
	 enemy = me->query_enemy();
	 i=random(sizeof(enemy));
	 if(environment(me) == environment(enemy[i]))
	 {
	   message_vision(HIR+"只見一陣紅霧環繞著$N,抽光$N全身血液!!!\n"+NOR,enemy[i]);
	   blood = enemy[i]->query("kee",1) * 0.7;
	   enemy[i]->receive_damage("kee", blood,me);
	   COMBAT_D->report_status(enemy[i], 0);
	 }else{
	   say("但是什麼也沒發生...\n");
	 }
    }
    if(done)
	      step++;
  }else{
    step = 1;
    done = 0;
  }
  
  if( me->query("kee") < 0 )
     me->die();
  :: heart_beat();
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
	  new("/open/sky/obj9/happiness-charm")->move(environment(winner));
	  message_vision(HIM + "\n從將軍夫人的身上掉下了一件奇怪的東西!!\n" + NOR,winner);
          write_file("/log/sky/obj9/happiness_charm",sprintf("%s(%s) 讓將軍夫人掉下了幸福之符於 %s\n",
	  winner->name(1),winner->query("id"),ctime(time())));
	  }
	}else{
	j=random(-1);
	  if( j==5 || j==15 || j== 150 || j==1500 || j==10 || j==100 || j==1000 || j==4000 || j==6666 || j==7777 )
	  {
	  new("/open/sky/obj9/happiness-charm")->move(environment(winner));
	  message_vision(HIM + "\n從將軍夫人的身上掉下了一件奇怪的東西!!\n" + NOR,winner);
          write_file("/log/sky/obj9/happiness_charm",sprintf("%s(%s) 讓將軍夫人掉下了幸福之符於 %s\n",
	  winner->name(1),winner->query("id"),ctime(time())));
	  }
	}
	}
	::die();
}
