#include "/open/gsword/npc/attack_bloodsword.h"

#include <ansi.h>
#include "/open/open.h"
inherit NPC;
int done=0;
void do_heal();
void create()
{
	set_name("風躍水", ({ "fon jump water", "fon" }) );
	set("long","你看到一個身材瘦長五十多歲的男子,你看他那穩健的步伐,以及
那有如猿猴般伶俐的動作,更加的確定他就是流星三劍客之首風躍水,他的興趣是遊山玩
水,也因此鍊就了一身獨步仙劍的輕功\,甚至連鄭士欣也自嘆不如。");
	set("gender", "男性" );
	set("class","swordsman");
	set("nickname","追星趕月");
	set("age", 55);
	create_family("仙劍派",3,"弟子");
	set("combat_exp",1500000);
		set("str", 44);
		set("cor", 24);
		set("cps", 18);
		set("per", 24);
		set("int", 42);
	set_skill("shasword",90);
	map_skill("sword","shasword");
	set_skill("shaforce",60);
	set_skill("sha-steps",80);
	set("max_force",2000);
	set("force",2000);
	set("max_gin",7000);
	set("force_factor",15);
	set("gin",7000);
	set("max_kee",7000);
	set("kee",7000);
	set("max_sen",7000);
	set("sen",7000);
	set("chat_chance_combat",40);
	set("chat_msg_combat",({
	(: do_heal :),
	(: perform_action,"sword.sha_kee" :)
	}));
	set("max_mana",100);
	set("mana",100);
	set_skill("force",40);
	set_skill("dodge",80);
	map_skill("dodge","sha-steps");
	set_skill("sword",30);
	map_skill("force","shaforce"); 
	set_skill("unarmed",90);
	setup();
	carry_object("/open/gsword/obj/spsword-4.c")->wield();
	carry_object("/open/common/obj/plaster2");
	carry_object("/open/common/obj/plaster2");
	carry_object("/open/common/obj/plaster2");
	carry_object("/open/common/obj/plaster2");
	carry_object("/open/common/obj/pill2");       
	carry_object("/open/common/obj/pill2");
	carry_object("/open/common/obj/pill2");
	carry_object("/open/common/obj/pill2"); 	       
	carry_object("/open/common/obj/pill2");
	}
 
void do_heal()
{
     if( random(7)>5 )
     if(done <5 ) 
     if(this_object()->query("kee") < 0.5*this_object()->query("max_kee") )
     {
      command("eat pill");    
      message_vision("風躍水由懷裡掏出藥膏抹在傷口上\n",this_object());
      command("apply plaster");
      done++;
     }
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
	  new("/open/sky/obj6/river_diamond")->move(environment(winner));
	  message_vision(HIM + "\n從風躍水的身上掉下了一件奇怪的東西!!\n" + NOR,winner);
          write_file("/log/sky/obj6/river_diamond",sprintf("%s(%s) 讓風躍水掉下了河川之流鑽於 %s\n",
	  winner->name(1),winner->query("id"),ctime(time())));
	  }
	}else{
	j=random(-1);
	  if( j==5 || j==15 || j== 150 || j==1500 || j==10 || j==100 || j==1000 || j==4000 || j==6666 || j==7777 ) 
	  {      
	  new("/open/sky/obj6/river_diamond")->move(environment(winner));
	  message_vision(HIM + "\n從風躍水的身上掉下了一件奇怪的東西!!\n" + NOR,winner);
          write_file("/log/sky/obj6/river_diamond",sprintf("%s(%s) 讓風躍水掉下了河川之流鑽於 %s\n",
	  winner->name(1),winner->query("id"),ctime(time())));
	  }
	}
	}
	::die();
}
