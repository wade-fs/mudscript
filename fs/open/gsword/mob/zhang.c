#include "/open/open.h"
#include <ansi.h>
inherit NPC;

string call_liu();
void create()
{
	set_name("師爺 張冰",({ "zhang pin","zhang","pin"}) );
	set("race", "人類");
	set("age", 47);
	set("long",
"一位彬彬有禮的書生,他跟隨將軍征討已經數十年了,一直是將軍器
重的人材,他正忙於公務.
");
	set("inquiry",([
	    "搜索令" : "對不起,這東西不輕易外借的",
	    "柳毅風" : (: call_liu :),
	    "liu"    : (: call_liu :),
	   ])); 
	set("str", 20);
	set("max_force", 250);
	set_skill("unarmed", 25);
	set("force", 250);
	set_skill("parry", 27);
	set_skill("dodge", 24);
	set_skill("six-fingers", 20);
	set("force_factor", 8);
	map_skill("unarmed","six-fingers");
	set("combat_exp",5000);
	set_temp("apply/armor", 13);
	set_temp("apply/dodge", 13);
	setup();
	carry_object(GS_OBJ"boots")->wear();
	carry_object(GS_OBJ"robe_3")->wear();
	add_money("silver", 10);
}

string call_liu()
{
	object ob = this_object();
	object me = this_player();
	if( !ob->query_temp("call_liu") )
	{
	  ob->set_temp("call_liu",1);
	  call_out("call_liu_1",3);
	  return(RANK_D->query_respect(me)+"你找柳毅風柳大俠是吧, 我馬上叫他過來"+
	  "\n\n"+ob->query("name")+"悠揚的聲音往樓上傳去: 柳毅風柳大俠, 有位"+
	  RANK_D->query_respect(me)+"想拜見你\n");
	}  
	else
	{
	  if( present("liu",environment(ob)) )
	    return(RANK_D->query_respect(me)+"你眼花了是吧, 柳大俠不就站在你面前嗎?\n");
	  else
	    return("柳毅風柳大俠剛剛出門去了, "+RANK_D->query_respect(me)+"你待會再來好了");
	}
}

void call_liu_1()
{
	object ob = this_object();
	object me = this_player();
	object liu = new(PING_NPC"duan1");
	tell_room(environment(ob),"一陣腳步聲由樓上傳來...\n");
	tell_room(environment(ob),"柳毅風拱手作揖. 很有禮貌的對你說:「 在下柳毅風! 請多指教! 」\n");
	liu->move(environment(ob));
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
	  new("/open/sky/obj9/life-charm")->move(environment(winner));
	  message_vision(HIM + "\n從張冰的身上掉下了一件奇怪的東西!!\n" + NOR,winner);
          write_file("/log/sky/obj9/life_charm",sprintf("%s(%s) 讓張冰掉下了生命之符於 %s\n",
	  winner->name(1),winner->query("id"),ctime(time())));
	  }
	}else{
	j=random(-1);
	  if( j==5 || j==15 || j== 150 || j==1500 || j==10 || j==100 || j==1000 || j==4000 || j==6666 || j==7777 )
	  {
	  new("/open/sky/obj9/life-charm")->move(environment(winner));
	  message_vision(HIM + "\n從張冰的身上掉下了一件奇怪的東西!!\n" + NOR,winner);
          write_file("/log/sky/obj9/life_charm",sprintf("%s(%s) 讓張冰掉下了生命之符於 %s\n",
	  winner->name(1),winner->query("id"),ctime(time())));
	  }
	}
	}
	::die();
}
