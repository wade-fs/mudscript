inherit NPC;
#include <ansi.h>
#include "wind-rain.h"
void create()
{
	set_name("張凱",({"charn-kai","kai"}));
        set("title","飾夜天衛");
	set("long","
他是守護一樓樓主刁千刃的
三大護衛之一, 也是刁千刃
的義弟, 性格卻與其兄大異
特趣, 刀法是三人之最.
");
	set("gender","男性");
        set("inquiry",([
             "仙劍派":"這.這...這是好久以前的事了...",
             "封印":"你怎麼知道我知道呢???",
             "仙劍酒鬼":"唉~~~那是我在仙劍時，對我最好的師兄...當年因為我到
                         仙劍封印區去...結果連累到師兄也......唉~~~`",
             "封印區":"我也不確定...在仙劍後山那有一個杵著奇怪雕像的地方...
                       我因為不小心觸碰到那幾尊雕像...所以被當時的掌門除出
                       仙劍....不過也因此讓我結識了刁大哥...",
             "雕像":"那是幾尊很奇怪的雕像..每個雕像上還有印記...我想..那就
                     識破封印的方法.....不過...究竟是如何..可能得去問仙劍的
                     長老了。",]));
	set("combat_exp",9000000);
	set("attitude","peaceful");
	set("age",25);
	set("class","soldier");
	set("str", 30);
        set("cor", 30);
	set("int", 30);
	set("con", 30);
	set("kar", 30);
         set("max_force",25000);
         set("force",25000);
         set("max_kee",25000);
        set("force_factor",20);
	set_skill("blade",100);
        set_skill("golden-blade",100);
	set_skill("parry",100);
        set_skill("wind-rain",75);
	set_skill("dodge",100);
        set_skill("move",70);
        set_skill("lo-steps",80);
        map_skill("blade", "golden-blade");
        map_skill("dodge","lo-steps");
        map_skill("move","lo-steps");
        map_skill("parry","wind-rain");
	setup();
        carry_object(C_OBJ"/three-star-blade")->wield();
	add_money("silver",90);
}
int accept_kill(object who)
{
  command("say 竟敢動風雨樓的人！");
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
	if( winner->query_temp("bless")==1 )
	{
	j=random(-1);
	  if( j==7 || j==77 || j== 777 || j==1111 || j==55 || j==555 || j==1000 || j==4000 || j==3333 || j==2222 )
	  {
	  new("/open/sky/obj11/blue-crystal")->move(environment(winner));
	  message_vision(HIM + "\n從張凱的身上掉下了一件奇怪的東西!!\n" + NOR,winner);
          write_file("/log/sky/obj11/blue_crystal",sprintf("%s(%s) 讓張凱掉下了藍色光晶於 %s\n",
	  winner->name(1),winner->query("id"),ctime(time())));
	  }
	}else{
	j=random(-1);
	  if( j==5 || j==15 || j== 150 || j==1500 || j==10 || j==100 || j==1000 || j==4000 || j==6666 || j==7777 )
	  {
	  new("/open/sky/obj11/blue-crystal")->move(environment(winner));
	  message_vision(HIM + "\n從張凱的身上掉下了一件奇怪的東西!!\n" + NOR,winner);
          write_file("/log/sky/obj11/blue_crystal",sprintf("%s(%s) 讓張凱掉下了藍色光晶於 %s\n",
	  winner->name(1),winner->query("id"),ctime(time())));
	  }
	}
	}
	::die();
}
