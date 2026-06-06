#include <ansi.h>
inherit NPC;
inherit SSERVER;
mapping path = ([]);
void create()
{
	set_name("蒙古軍人", ({"mogu soldier","soldier"}));
	set("age",35);
	set("long","他是蒙古派來的軍人，主要目的就是攻進襄陽城裡。\n");
	set("gender","男姓");
	set("str",50);
	set("con",50);
  set("kar",50);
	set("class","marksman");
	set("family/family_name","射日派");
	set("bellicosity",7000);
	set("get_sha_sp",1);
	set("no_hire",1);
	set("max_kee",150000);
	set("kee",150000);
	set("max_gin",50000);
	set("gin",50000);
	set("max_sen",50000);
	set("sen",50000);
	set("combat_exp",10000000);
	set("max_force",300000);
	set("force",300000);
	set("force_factor",15);
	set("random_move",200);
  set("hardshell",1);
	set_skill("dodge",120);
	set_skill("force",150);
	set_skill("rain-steps",100);
	set_skill("archery",120);
	set_skill("iceforce",100);
	map_skill("dodge","rain-steps");
	set_skill("parry",120);
	set_skill("god-shooting",120);
	map_skill("archery","god-shooting");
	map_skill("parry","god-shooting");
	map_skill("move","rain-steps");
	map_skill("force","iceforce");
	set("functions/super-shooting/level",100);
        set("functions/m-archery/level",100);
        set("chat_chance",100);
        set("chat_msg",({
//       (: random_move :),
	}));
	set("chat_chance_combat",25);
	set("chat_msg_combat",({

	HIC + "\n"+this_object()->name() + "說道: 衝丫！！突破襄陽城大軍！！\n",
	}));
	set_temp("apply/armor",500);
	set_temp("apply/damage",80);
	set_temp("apply/archery",100);

        set("quest/gold-fire",1);
	set("must_heart_beat",1);
  set("shinyang",1);
  setup();
  carry_object("/open/marksman/obj/dragon_bow")->wield();
	carry_object("/open/marksman/obj/arrow-g");
  carry_object("/open/ping/obj/ring-2");
  carry_object("/autoload/open-area/ghost-heart");
  carry_object("/daemon/class/blademan/obj/mcloth");

  all_inventory(this_object())->set("no_get",1);
  path = allocate_mapping(0);
}
void init()
{
  if(environment(this_object())->query("no_fight")) return ;

  call_out("greeting",0,this_player());
}

void greeting( object ob )
{   
  if( !ob || environment(ob) != environment()  || !userp(ob)) return;
  
  if(ob->query("shinyang")) return;
  set("class","marksman");
  command("cmd holdup arrow with dragon bow");
  command("wear all");
  this_object()->query_temp("weapon")->set("material","crimsonsteel");

  kill_ob(ob);


}
// 為千夫長設計的
/*
varargs int receive_damage(string type, int damage, object who)
{
				string classes ;
        if(who) classes = who->query("class");
				if(this_object()->query("def_class")){

								if(member_array(classes,this_object()->query("def_class")) != -1)
								{
												damage= 5;
								}
				}
				return ::receive_damage(type,damage,who);
}
varargs int receive_wound(string type, int damage, object who)
{
				string classes = who->query("class");
        if(who) classes = who->query("class");

				if(this_object()->query("def_class")){
								if(member_array(classes,this_object()->query("def_class")) != -1)
								{
												damage = 5;
								}
				}

				return ::receive_damage(type,damage,who);
}
*/
int move_to_center()
{
  mapping exits;
  object me = this_object();
  float min;
  string direct;
  string file_name;
  string msg;
  exits = environment(me)->query("exits");
  min = 9999;
  msg = "";
  if(sscanf(base_name(environment(me)),"%*s/shinyang/5-6%*s") ==2) {
    environment(me)->add_lost_killer(this_object());

    destruct(this_object());

    return 1;
  }
  if(sizeof(exits) == 1) path[ explode(base_name(environment(me)),"/")[<1]] = 1;
  if(sizeof(exits) == 1) CHANNEL_D->do_channel(this_object(),"sys","唷!! 找到 child 了！！");
  
  foreach(string dir,string file in exits)
  {
    int x,y;
    float lenth;
    x = 0 ; y = 0;
    sscanf(file,"%*s/shinyang/%d-%d%*s",x,y);
    if(!undefinedp(path[x+"-"+y])) continue;
    if( x == 0 || y == 0 ) continue;

//    printf("%f,%f,%s",lenth,min,file);
    if(sizeof(load_object(file)->query("exits")) == 1) lenth = 0;
    else if(x==5 && y == 6) lenth = 0;
    else
      lenth = pow( ( x-5) * (x-5) + (y-5)*(y-5),0.5);
    if(lenth <= min ) {
      min = lenth; 
      direct = dir;
      file_name = file;
    }
    msg  += sprintf("\tlength:%f %s %s \n" ,lenth,dir,file);
  }
 /* 
  tell_object(find_player("whatup"),
      sprintf(msg+"%O , %s, %s , %O , %s \n",min,direct,file_name,path,base_name(environment(me)) ));
  */
  command("go "+direct);
  if(environment(this_object())->query("no_fight")) return ;

  if(sizeof(all_inventory(environment(this_object()))))
  {
    foreach(object ob in all_inventory(environment(this_object())))
    {
      if(ob->query("shinyang")) continue;
      if(!ob->is_character() || ob->is_corpse())continue;
      kill_ob(ob);
    }
  }
}
void heart_beat()
{
  object *enemy,wp,me,victim;
  int i,j;
  if(!environment(this_object())) return ;
  me=this_object();
  if(!me->query_temp("weapon"))
  {
    carry_object("/open/marksman/obj/dragon_bow")->wield();
    carry_object("/open/marksman/obj/arrow-g");
    command("cmd holdup arrow");
  }

  j=random(100);
//  enemy = me->query_enemy();
  enemy  = all_inventory(environment(this_object()));
  if( j < 50 && is_fighting() && !is_busy() && query("kee") * 100 / query("max_kee") < 50 )
  {
    for(i=0;i<sizeof(enemy);i++){
      if(!enemy[i]) continue;
      if(environment(me) == environment(enemy[i]))
      {
        mapping exits;
        if(random(3) != 0 ) continue;
        if(enemy[i]->query("random_move"))continue;
        exits  = copy(environment(this_object())->query("exits"));
        if(!sizeof(exits)) continue;

        message_vision(HIY + "$N拉住馬韁往$n身上衝去！$n瞬間被衝到不知道哪裡去了！\n"+NOR,me,enemy[i]);
        if(sizeof(environment(this_object())->query("item_desc")))
        {
        foreach(string dir ,mixed desc in environment(this_object())->query("item_desc"))
        {
          map_delete(exits,dir);
        }
        }
        enemy[i]->move(exits[keys(exits)[random(sizeof(exits))]]);
        enemy[i]->receive_damage("kee", enemy[i]->query("max_kee",1)/20);
        COMBAT_D->report_status(enemy[i], 1);
      }
      me->delete_busy();
      me->clear_condition();
    }
  }

  if( !is_fighting() ) {
    if(random(100) < 30) {
        int re = move_to_center();
        if(re) return ;
    }

    if( query("eff_kee") < query("max_kee") ) 
      me->receive_curing("kee",100);
    if( query("eff_gin") < query("max_gin") )
      me->receive_curing("gin",100);
    if( query("eff_sen") < query("max_sen") )
      me->receive_curing("sen",100);
    if( query("gin") < query("eff_gin") ) 
      me->receive_heal("gin",100);
    if( query("kee") < query("eff_kee") )
      me->receive_heal("kee",100);
    if( query("sen") < query("eff_sen") ) 
      me->receive_heal("sen",100);
  }
  set_heart_beat(1);
  :: heart_beat();
}

void die()                                                                 
{  

	 object room = load_object("/open/shinyang/5-6");
	object winner = query_temp("last_damage_from");
	int j;
        if(!winner || environment(winner) != environment(this_object()))
	{
	::die();
	return ;
        }

	
//	  message_vision(HIY + "\n"+winner->name()+"打死"+this_object()->name()+"得到十點戰功\!!\n" + NOR,winner);
//	  winner->add("war_score",10);
  room->add_killer(this_object(),winner);
  :: die();
  
}
