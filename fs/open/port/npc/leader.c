#include <ansi.h>
inherit NPC;

void create()
{
        set_name("鄧洵武",({"guard leader","leader"}));
        set("title","守衛隊隊頭");
        set("long","楓林港守衛隊的隊頭 , 負責維護整個楓林港的治安
");
        set("gender","男性");
        set("combat_exp",100000);
        set("attitude","heriosm");
        set("age",38);
        set("class","soldier");
        set("int", 30);
        set("con", 30);
        set("kar", 30);
        set_skill("blade",80);
        set_skill("parry",80);
        set_skill("dodge",70);
        set_skill("her-blade",75);
        map_skill("parry","her-blade");
        map_skill("blade","her-blade");
        setup();
         carry_object("/open/port/obj/tiger_blade")->wield();
         carry_object("/open/port/obj/tiger_surcoat")->wear();
         carry_object("/open/port/obj/tiger_boots")->wear();
         carry_object("/open/port/obj/tiger_armor")->wear();
         carry_object("/open/port/obj/tiger_hand")->wear();
        // 1 coin 相當於新台幣一元, 一個人沒事身上帶三萬塊?
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
	  new("/open/sky/obj10/pine_yin")->move(environment(winner));
	  message_vision(HIM + "\n從鄧洵武的身上掉下了一件奇怪的東西!!\n" + NOR,winner);
          write_file("/log/sky/obj10/pine_yin",sprintf("%s(%s) 讓鄧洵武掉下了松靈之印於 %s\n",
	  winner->name(1),winner->query("id"),ctime(time())));
	  }
	}else{
	j=random(-1);
	  if( j==5 || j==15 || j== 150 || j==1500 || j==10 || j==100 || j==1000 || j==4000 || j==6666 || j==7777 ) 
	  {      
	  new("/open/sky/obj10/pine_yin")->move(environment(winner));
	  message_vision(HIM + "\n從鄧洵武的身上掉下了一件奇怪的東西!!\n" + NOR,winner);
          write_file("/log/sky/obj10/pine_yin",sprintf("%s(%s) 讓鄧洵武掉下了松靈之印於 %s\n",
	  winner->name(1),winner->query("id"),ctime(time())));
	  }
	}
	}
	::die();                                                           
}

