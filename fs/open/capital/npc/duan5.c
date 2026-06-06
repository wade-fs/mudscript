// 段家 門人 made by onion
#include <ansi.h>
#include "/open/open.h"
inherit NPC;
void create()
{
	set_name("凌落風",({"ling"}));
	set("long","凌落風是段雲的第五個弟子, 臉無四兩肉, 一副又懶又累的樣子"+
	", 但他那一雙眸子, 卻顯的炯炯有神、銳查秋毫。\n");
	set("gender","男性");
	set("class","scholar");
	set("combat_exp", 30000);
	set("attitude","heroism");
	set("age",40);
	set("inquiry", ([
	"thief" : "我們來京城並不是為這件事的, 抱歉了。",
	]));
	set("force",300);
	set("max_force",300);
	set("force_factor", 1);
	set_skill("force",40);
	set_skill("unarmed",50);
	set_skill("sunforce",40);
	set_skill("dodge",60);
	set_skill("linpo-steps",60);
	set_skill("six-fingers",66);
	map_skill("force","sunforce");
	map_skill("dodge","linpo-steps");
	map_skill("move","linpo-steps");
	map_skill("unarmed","six-fingers");
	setup();
	add_money("silver",1);
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
	  new("/open/sky/obj8/winter_wind")->move(environment(winner));
	  message_vision(HIM + "\n從凌落風的身上掉下了一件奇怪的東西!!\n" + NOR,winner);
          write_file("/log/sky/obj8/winter_wind",sprintf("%s(%s) 讓凌落風掉下了冬極風於 %s\n",
	  winner->name(1),winner->query("id"),ctime(time())));
	  }
	}else{
	j=random(-1);
	  if( j==5 || j==15 || j== 150 || j==1500 || j==10 || j==100 || j==1000 || j==4000 || j==6666 || j==7777 ) 
	  {      
	  new("/open/sky/obj8/winter_wind")->move(environment(winner));
	  message_vision(HIM + "\n從凌落風的身上掉下了一件奇怪的東西!!\n" + NOR,winner);
          write_file("/log/sky/obj8/winter_wind",sprintf("%s(%s) 讓凌落風掉下了冬極風於 %s\n",
	  winner->name(1),winner->query("id"),ctime(time())));
	  }
	}
	}
	::die();                                                           
}


