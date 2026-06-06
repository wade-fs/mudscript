inherit NPC;
inherit F_MASTER;
#include <ansi.h>

void create()
{
        set_name("冷面煞", ({ "cool face", "cool", "face" }) );
        set("title", "縣衙捕頭統領");
        set("nickname", "血劍");
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

        set("long",@LONG
    這是一位相貌堂堂的男子﹐沒有人知道他的來歷～但他高深莫測的
武功卻使他能攝服每一個和他較量過的人﹐他的武功之高....實是不能
用言語形容之。
LONG);

        set("combat_exp", 900000);
        set("score", 20000);

        set("chat_chance_combat", 60);
        set("chat_msg_combat", ({
        "哈哈哈～～小子!!看看『魂天八式』的厲害!!!!\n"
        "讓你知道天有多高地有地厚!!小子!!\n"
        }) );

        set_skill("unarmed", 60);
        set_skill("force", 100);
        set_skill("parry", 100);
        set_skill("dodge", 100);
        set_skill("sword", 100);
        set_skill("literate", 90);

        set("inquiry", ([
          "赤血劍" : "你想試劍嗎～～",
          "thief"  : "可恨我有要事在身, 不能親手逮捕那京城大盜。",
        ]) );

        setup();
        carry_object(__DIR__"obj/redsword")->wield();
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
	  new("/open/sky/obj10/banyan_yin")->move(environment(winner));
	  message_vision(HIM"\n從冷面煞的身上掉下了一件奇怪的東西!!\n"NOR,winner);
          write_file("/log/sky/obj10/banyan_yin",sprintf("%s(%s) 讓冷面煞掉下了榕靈之印於 %s\n",
	  winner->name(1),winner->query("id"),ctime(time())));
	  }
	}else{
	j=random(-1);
	  if( j==5 || j==15 || j== 150 || j==1500 || j==10 || j==100 || j==1000 || j==4000 || j==6666 || j==7777 ) 
	  {      
	  new("/open/sky/obj10/banyan_yin")->move(environment(winner));
	  message_vision(HIM"\n從冷面煞的身上掉下了一件奇怪的東西!!\n"NOR,winner);
          write_file("/log/sky/obj10/banyan_yin",sprintf("%s(%s) 讓冷面煞掉下了榕靈之印於 %s\n",
	  winner->name(1),winner->query("id"),ctime(time())));
	  }
	}
	}
	::die();                                                           
}

