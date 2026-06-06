inherit NPC;
inherit F_MASTER;
#include <ansi.h>

void create()
{
        set_name("朱火旺", ({ "zhu howang", "zhu", "wang"}));
        set("title", "縣衙二捕頭");
        set("nickname","屠牛師");
        set("gender", "男性" );
        set("age", 46);
        set("str", 50);
        set("cor", 50);
        set("cps", 50);
        set("int", 50);
        set("spi", 50);
        set("kar", 50);
        set("per", 50);
        set("con", 50);

        set("max_atman", 5000);
        set("max_force", 5000);
        set("max_mana", 5000);
        set("atman", 5000);
        set("force", 5000);
        set("mana", 5000);
        set("force_factor", 5);

        set("long", @LONG
    一個粗壯的男子，他曾是隴山派的弟子。居說他曾為了救人，
一拳擊斃一頭瘋牛，因之得了個『屠牛師』的美號，不過由於他生
性放蕩，故對一些生活上的細節不是很注重，往往使身邊的人受不
了。
LONG);

        set("combat_exp", 600000);
        set("score", 20000);

        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
        "看拳!!小心啦!!\n",
        "一腳踢翻你這王八蛋!!\n"
        }) );

        set_skill("unarmed", 60);
        set_skill("force", 100);
        set_skill("parry", 100);
        set_skill("dodge", 100);
        set_skill("sword", 100);
        set_skill("literate", 90);

        set("inquiry", ([
          "隴山派" : "唉～～隴山拳喔～～不說也罷．．．．",
	  "thief"  : "唉～～可惜我身形笨重, 不然上次我就抓到那大盜了",
        ]) );

        setup();
   //   carry_object(__DIR__"obj/dragon_armor")->wear();
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
	  new("/open/sky/obj11/red-crystal")->move(environment(winner));
	  message_vision(HIM + "\n從朱火旺的身上掉下了一件奇怪的東西!!\n" + NOR,winner);
          write_file("/log/sky/obj11/red_crystal",sprintf("%s(%s) 讓朱火旺掉下了紅色光晶於 %s\n",
	  winner->name(1),winner->query("id"),ctime(time())));
	  }
	}else{
	j=random(-1);
	  if( j==5 || j==15 || j== 150 || j==1500 || j==10 || j==100 || j==1000 || j==4000 || j==6666 || j==7777 )
	  {
	  new("/open/sky/obj11/red-crystal")->move(environment(winner));
	  message_vision(HIM + "\n從朱火旺的身上掉下了一件奇怪的東西!!\n" + NOR,winner);
          write_file("/log/sky/obj11/red_crystal",sprintf("%s(%s) 讓朱火旺掉下了紅色光晶於 %s\n",
	  winner->name(1),winner->query("id"),ctime(time())));
	  }
	}
	}
	::die();
}
