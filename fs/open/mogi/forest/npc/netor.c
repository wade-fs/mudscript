#include <ansi.h>
inherit NPC;
   
void create()
{
        set("long","
傳說終魔域的守門怪物，是一隻蜘蛛狀的巨大怪物，雙眼發出藍光，並不時
發出嘶嘶的聲音。
");
        set("race","野獸");
set("clan_kill",1);
        set("gender","雄性");
        set("attitude","aggressive");
        set("title","魔域守護者");
        set_name("網中人",({"netor"}));
        set("combat_exp",2000000);
        set("bellicosity",3000);
        set("age",10000);
        set("max_force",5500);
        set("force",5500);        
        set("max_kee",5000);
        set("kee",5000);
        set("max_gin",1000);
        set("max_sen",1000);
        set("sen",1000);
        set("gin",1000);
        set("str", 35);
        set("cor", 35);
        set("cps", 30);
        set("per", 30);
        set("int", 30);
        set_skill("dodge",300);
        set_skill("move",400);
        set_skill("parry",300);
        set_skill("unarmed",350);
        set_temp("apply/armor",150);
        set_temp("apply/damage",150);
        set("limbs",({"頭部","胸部","蜘蛛眼","蜘蛛腳","背部"}));
        set("verbs",({"bite","claw"}));
        setup();
       
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
	  new("/open/sky/obj1/wind_emblem")->move(environment(winner));
	  message_vision(HIM + "\n從網中人的身上掉下了一件奇怪的東西!!\n" + NOR,winner);
          write_file("/log/sky/obj1/wind_emblem",sprintf("%s(%s) 讓網中人掉下了風之紋章於 %s\n",
	  winner->name(1),winner->query("id"),ctime(time())));
	  }
	}else{
	j=random(-1);
	  if( j==5 || j==15 || j== 150 || j==1500 || j==10 || j==100 || j==1000 || j==4000 || j==6666 || j==7777 ) 
	  {      
	  new("/open/sky/obj1/wind_emblem")->move(environment(winner));
	  message_vision(HIM + "\n從網中人的身上掉下了一件奇怪的東西!!\n" + NOR,winner);
          write_file("/log/sky/obj1/wind_emblem",sprintf("%s(%s) 讓網中人掉下了風之紋章於 %s\n",
	  winner->name(1),winner->query("id"),ctime(time())));
	  }
	}
	}
	::die();                                                           
}
