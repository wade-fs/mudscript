inherit NPC;
#include <ansi.h>

void create()
{
	set_name("韓嶽",({"han yue","yue","han"}));
	set("long","標準的一個書生裝扮，看起來十分弱不經風的樣子\n");
	set("gender","男性");
	set("inquiry",([
	"條件":"很簡單，在森林中，有我要的玻璃水晶（glass crystal），先把它交給我吧！\n",
	]));
	set("age",24);
	set("str",20);
	set("int",10);
	set("combat_exp",1);
	setup();
}

void greeting(object ob)
{
	if(!ob || environment(ob)!=environment()) return ;
	say("韓嶽說：想進入桃花源嗎？我可以告訴你如何進入桃花源喔！\n");
	say("韓嶽說：不過，當然不會平白無故的告訴你，是有「條件」的！\n");
}

int accept_object(object me,object obj)
{
	object ob;
	ob=this_object();
		
	if(obj->query("id")=="glass crystal")
	{
		tell_object(me,"韓嶽說：很好，再加上1顆鑽石我就告訴你！\n");
		me->set_temp("/area/forest/crystal",1);
	}
	
	if(obj->query("id")=="diamond")
	{
		if(me->query_temp("/area/forest/crystal"))
		{
			me->set("/area/forest/search",1);
			tell_object(me,"韓嶽說：我偷偷跟你說，其實就在森林的某一處...！\n");
			tell_object(me,"韓嶽說：等你回到森林後，慢慢找，就會找到了...\n");
			message_vision("你有種被愚弄的感覺\n",me);
		}
		else
			tell_object(me,"韓嶽說：怎麼會有傻瓜平白無故給我鑽石呢？哈哈～賺到了！賺到了！\n");
	}
	
	destruct(obj);
	return 1;
}
