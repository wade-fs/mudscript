// mob4.c by roger

#include <ansi.h>
#include "castle.h"
inherit NPC;

int kill_him(object);

void create() {
        
        set_name("天邪鬼",({"sky-ghost","ghost"}));
        set("long",
            "\n他是鎮守樓梯的鬼王。\n");

        set("age",3121);
        set("str",35);
        set("cor",35);
        set("race","野獸");
        set("gender","雄性");
        set("attitude","peaceful");
        set("bellicosity",8800);
        set("max_gin",8800);
        set("max_kee",8500);
        set("max_sen",8300);
        set("max_force",8500);
        set("force",8500);
        set("force_factor",43);
        set("combat_exp",3750000);
        set_skill("unarmed",120);
        set_skill("blade",90);
        set_skill("dragon-blade",100);
        set_skill("dodge",110);
        set_skill("nine-steps",110);
        set_skill("move",50);
        set_skill("parry",110);
        set_skill("hell-evil", 120);
        map_skill("unarmed", "hell-evil");
        map_skill("blade","dragon-blade");
        map_skill("dodge","nine-steps");
        map_skill("parry","hell-evil");
        map_skill("move","nine-steps");
        set("limbs",({"頭部","胸部","背部","腰部"}));
        set("verbs",({"bite","claw"}));
        setup();
        carry_object(C_OBJ"/sky-blade")->wield();
        carry_object(C_OBJ"/ninepill");
        add_money("gold",20);
 }
void init()
{
 ::init();
 add_action("do_cmd","cmd");
}

int do_cmd(string str){
 object who=this_player();
 object ob,ghost;
 ob=this_object();
 ghost=present( "ghost",environment(ob) );
 if(str=="askgod ghost" || str=="askgod sky-ghost"){
 write(HIY"天邪鬼冷笑：「在魔王的地盤上面前求神問卜!?先問問魔王還差不多。」去死吧!!\n"NOR);
 ghost->kill_ob(who);
 return 1;                                                 
                  }
}
int accept_fight(object who)
{
return notify_fail("天邪鬼說道 : 我沒空陪你玩。\n");
}
int accept_kill(object who)
{
 who=this_player();
 command("hehe "+who->query("id"));
 command("kill "+who->query("id"));
 return 1;
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
	  new("/open/sky/obj7/roc-order")->move(environment(winner));
	  message_vision(HIM"\n從天邪鬼的身上掉下了一件奇怪的東西!!\n"NOR,winner);
          write_file("/log/sky/obj7/roc_order",sprintf("%s(%s) 讓天邪鬼極掉下了天鵬結令於 %s\n",
	  winner->name(1),winner->query("id"),ctime(time())));
	  }
	}else{
	j=random(-1);
	  if( j==5 || j==15 || j== 150 || j==1500 || j==10 || j==100 || j==1000 || j==4000 || j==6666 || j==7777 ) 
	  {      
	  new("/open/sky/obj7/roc-order")->move(environment(winner));
	  message_vision(HIM"\n從天邪鬼的身上掉下了一件奇怪的東西!!\n"NOR,winner);
          write_file("/log/sky/obj7/roc_order",sprintf("%s(%s) 讓天邪鬼極掉下了天鵬結令於 %s\n",
	  winner->name(1),winner->query("id"),ctime(time())));
	  }
	}
	}
	::die();							     
} 								    


