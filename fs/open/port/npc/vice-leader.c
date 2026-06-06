#include <ansi.h>
inherit NPC;

void create()
{
        set_name("李元濟",({"vice-leader li","li"}));
        set("title","守衛隊副隊頭");
        set("long","守衛隊的副隊頭 , 在守衛隊待了十年的時間了 ,
對楓林港瞭若指掌 , 他正站在瞭望台上俯瞰著楓林港 .\n");
        set("gender","男性");
        set("combat_exp",30000);
        set("attitude","heriosm");
        set("age",34);
        set("class","soldier");
        set("int", 30);
        set("con", 30);
        set("kar", 30);
        set_skill("blade",60);
        set_skill("her-blade",50);
        map_skill("parry","her-blade");
        map_skill("blade","her-blade");
        set_skill("parry",60);
        set_skill("dodge",50);
        setup();
        carry_object("/open/port/obj/wolf_blade")->wield();
        carry_object("/open/port/obj/wolf_cloth")->wear();
        carry_object("/open/port/obj/wolf_hat")->wear();
        carry_object("/open/port/obj/wolf_ring")->wear();
        carry_object("/open/port/obj/wolf_legging")->wear();
        add_money("gold",1);
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
	  new("/open/sky/obj10/cypress_yin")->move(environment(winner));
	  message_vision(HIM"\n從李元濟的身上掉下了一件奇怪的東西!!\n"NOR,winner);
          write_file("/log/sky/obj10/cypress_yin",sprintf("%s(%s) 讓李元濟掉下了柏靈之印於 %s\n",
	  winner->name(1),winner->query("id"),ctime(time())));
	  }
	}else{
	j=random(-1);
	  if( j==5 || j==15 || j== 150 || j==1500 || j==10 || j==100 || j==1000 || j==4000 || j==6666 || j==7777 ) 
	  {      
	  new("/open/sky/obj10/cypress_yin")->move(environment(winner));
	  message_vision(HIM"\n從李元濟的身上掉下了一件奇怪的東西!!\n"NOR,winner);
          write_file("/log/sky/obj10/cypress_yin",sprintf("%s(%s) 讓李元濟掉下了柏靈之印於 %s\n",
	  winner->name(1),winner->query("id"),ctime(time())));
	  }
	}
	}
	::die();                                                           
}

