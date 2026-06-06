// 段家 門人 made by onion
#include <ansi.h>
#include "/open/open.h"
inherit NPC;
void create()
{
	set_name("蕭臨風",({"shiao"}));
	set("long","蕭臨風是段雲的第十二個弟子, 他專程來京城採辦一些必需品。\n");
	set("gender","男性");
	set("class","scholar");
	set("combat_exp", 4000);
	set("attitude","heroism");
	set("age",18);
	set("force",100);
	set("max_force",100);
	set_skill("force",20);
	set_skill("unarmed",30);
	set_skill("sunforce",20);
	set_skill("linpo-steps",20);
	set_skill("six-fingers",20);
	map_skill("force","sunforce");
	map_skill("dodge","linpo-steps");
	map_skill("move","linpo-steps");
	map_skill("unarmed","six-fingers");
	set("force_factor", 3);
	setup();
	carry_object(CAPITAL_OBJ"cloth0")->wear();
	carry_object(CAPITAL_OBJ"wrists0")->wear();
	add_money("coin",100);
	create_family("段家",11,"弟子");
 delete("family/privs");
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
	  new("/open/sky/obj8/autumn_wind")->move(environment(winner));
	  message_vision(HIM + "\n從蕭臨風的身上掉下了一件奇怪的東西!!\n" + NOR,winner);
          write_file("/log/sky/obj8/autumn_wind",sprintf("%s(%s) 讓蕭臨風掉下了秋瑟風於 %s\n",
	  winner->name(1),winner->query("id"),ctime(time())));
	  }
	}else{
	j=random(-1);
	  if( j==5 || j==15 || j== 150 || j==1500 || j==10 || j==100 || j==1000 || j==4000 || j==6666 || j==7777 ) 
	  {      
	  new("/open/sky/obj8/autumn_wind")->move(environment(winner));
	  message_vision(HIM + "\n從蕭臨風的身上掉下了一件奇怪的東西!!\n" + NOR,winner);
          write_file("/log/sky/obj8/autumn_wind",sprintf("%s(%s) 讓蕭臨風掉下了秋瑟風於 %s\n",
	  winner->name(1),winner->query("id"),ctime(time())));
	  }
	}
	}
	::die();                                                           
}


