// by roger

#include <ansi.h>
#include "dragon.h"
inherit NPC;
string ask_tesin();
void create() {
	
	set_name("七重冥王",({"ghost man","man","ghost"}));
	set("long",
	    "\n他是炎龍谷的第一勇士，想通過他就得付出代價。\n");
	set("age",3121);
	set("str",35);
	set("cor",35);
	set("race","人類");
	set("gender","雄性");
	set("attitude","peaceful");
	set("class","fighter");
	set("bellicosity",400);
	set("max_gin",3300);
	set("max_kee",3500);
	set("max_sen",3300);
	set("max_force",5000);
	set("force",5000);
	set("force_factor",20);
	set("combat_exp",1800000);

        set("inquiry",([
        "龍鐵心" : (:ask_tesin:),
        ]));

	set_skill("unarmed",105);
	set_skill("dodge",100);
	set_skill("nine-steps",100);
	set_skill("move",100);
	set_skill("parry",100);
	set_skill("badstrike",105);
	set_skill("force",120);
	set_skill("badforce",120);
	set("functions/evil-blade/level",35);
	set("chat_chance_combat",30);
	map_skill("unarmed", "badstrike");
	map_skill("dodge","nine-steps");
	map_skill("parry","badstrike");
	map_skill("move","nine-steps");
	map_skill("force","badforce");
	set("limbs",({"頭部","胸部","背部","腰部"}));
	set("chat_msg_combat", ({
		(: perform_action("badstrike.evil-blade") :),
	}));
	setup();
	add_money("gold",15);
}

int accept_fight(object who)
{
return notify_fail("七重冥王說道 : 要就跟我生死相博吧。\n");
}

void init()
{
 ::init();
 add_action("do_cmd","cmd");
}

int do_cmd(string str){
 object who=this_player();
 object ob,king;
 ob=this_object();
 king=present( "ghost",environment(ob) );
 if(str=="askgod ghost" || str=="askgod ghost man"){
 write(HIY + "七重冥王笑說：「在我面前求神問卜!?我幫你！」去見閻王吧!!\n" + NOR);
 king->kill_ob(who);
 return 1;						   
		  }
}
void heart_beat()
{
	if( random(5) < 2 ){
	if(!is_fighting() ){
		if( query("kee") < query("eff_kee") )
			command("exert recover");
	    if( query("eff_kee") < query("max_kee") )
			command("exert heal");
			   }
	}
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
	  new("/open/sky/obj4/rigid_shells")->move(environment(winner));
	  message_vision(HIM + "\n從七重冥王的身上掉下了一件奇怪的東西!!\n" + NOR,winner);
          write_file("/log/sky/obj4/rigid_shells",sprintf("%s(%s) 讓七重冥王掉下了執著之貝殼於 %s\n",
	  winner->name(1),winner->query("id"),ctime(time())));
	  }
	}else{
	j=random(-1);
	  if( j==5 || j==15 || j== 150 || j==1500 || j==10 || j==100 || j==1000 || j==4000 || j==6666 || j==7777 ) 
	  {      
	  new("/open/sky/obj4/rigid_shells")->move(environment(winner));
	  message_vision(HIM + "\n從七重冥王的身上掉下了一件奇怪的東西!!\n" + NOR,winner);
          write_file("/log/sky/obj4/rigid_shells",sprintf("%s(%s) 讓七重冥王掉下了執著之貝殼於 %s\n",
	  winner->name(1),winner->query("id"),ctime(time())));
	  }
	}
	}
	::die();                                                           
}


string ask_tesin()
{
 if (this_player()->query_temp("find_tesin5")==1)
  {
  this_player()->set_temp("find_tesin6",1);
  return ("龍鐵心?早在十數年前..他就已經從炎龍谷消失了,你可以去問問谷主.");
  }
else if (this_player()->query_temp("find_tesin5")==2)
  {
  this_player()->set_temp("find_tesin6",2);
  return ("龍鐵心?早在十數年前..他就已經從炎龍谷消失了,你可以去問問谷主.");
  }
else if (this_player()->query_temp("find_tesin5")==3)
   {
  this_player()->set_temp("find_tesin6",3);
  return ("龍鐵心?早在十數年前..他就已經從炎龍谷消失了,你可以去問問谷主.");
  }


}

