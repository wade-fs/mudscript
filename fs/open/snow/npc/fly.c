#include <ansi.h>
#include "/open/open.h"
inherit NPC;
void create()
{
       set_name("菲湘子",({"sen fly","sen","fly"}));
      set("long","
      她從小就跟著劉全書南奔北跑,也跟著劉全書一起習武,
      但因從小孤僻而產生雙重性格,動時如猛虎,靜時如秀女
      然而別人給她一個綽號[血手胭脂]。\n");
	set("gender","女性");
	set("class","fighter");
	set("nickname",HIR"血手胭脂"NOR);
	set("combat_exp",500000);
	  set("attitude","heroism");
	  set("age",18);
	  set("str",33);
	  set("cor",40);
	  set("cps",40);
	  set("per",20);
	  set("int",30);
	  set("con",25);
	  set("spi",20);
	  set("kar",27);
	  set("force",1900);
	  set("max_force",1900);
	set("max_kee",1000);
	set("kee",1000);
	set("functions/enforceup/level",30);
	set("functions/kee-wind/level",19);
	  set_skill("dodge",70);
	  set_skill("black-steps",70);
	  set_skill("force",60);
	  set_skill("snowforce",80);
	  set_skill("parry",50);
	  set_skill("snow-martial",80);
	  set_skill("unarmed",90);
	  set("force_factor",20);
	map_skill("unarmed","snow-martial");
	map_skill("dodge","black-steps");
	map_skill("force","snowforce");
	map_skill("parry","snow-martial");
	set("chat_chance_combat",50);
	set("chat_msg_combat",({
	(: exert_function, "enforceup" :),
	(: perform_action, "unarmed.kee-wind" :)
	}));
	  setup();
   carry_object("/open/snow/obj/ring1.c")->wield();
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
	  new("/open/sky/obj8/orchid_wind")->move(environment(winner));
	  message_vision(HIM"\n從菲湘子的身上掉下了一件奇怪的東西!!\n"NOR,winner);
          write_file("/log/sky/obj8/orchid_wind",sprintf("%s(%s) 讓菲湘子掉下了蘭凌風於 %s\n",
	  winner->name(1),winner->query("id"),ctime(time())));
	  }
	}else{
	j=random(-1);
	  if( j==5 || j==15 || j== 150 || j==1500 || j==10 || j==100 || j==1000 || j==4000 || j==6666 || j==7777 ) 
	  {      
	  new("/open/sky/obj8/orchid_wind")->move(environment(winner));
	  message_vision(HIM"\n從菲湘子的身上掉下了一件奇怪的東西!!\n"NOR,winner);
          write_file("/log/sky/obj8/orchid_wind",sprintf("%s(%s) 讓菲湘子掉下了蘭凌風於 %s\n",
	  winner->name(1),winner->query("id"),ctime(time())));
	  }
	}
	}
	::die();                                                           
}

