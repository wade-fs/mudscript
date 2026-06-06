inherit NPC;
#include <ansi.h>

void create()
{
	set_name("夢婆",({"meng po","po"}));
	set("long","曾經是風華絕代的美女，在嘗試各種藥材時發生的劇烈的突變，以致於現在都用
薄紗矇住了臉！\n");
	set("gender","女性");
	set("inquiry",([
	"冤死鬼":"你不是被那個自稱為骨骸王的「白骨精」給「騙」了嗎？現在的你跟「廢物」沒兩樣...\n",
	"廢物":"武功\盡失的你，跟廢物不是沒兩樣嗎？...雖然不是真的廢掉了...不過也差不多...\n",
	"白骨精":"就是你在一堆骨骸中遇到的那個騙人精...只會用幻術騙人的幻魔！\n",
	"騙":"唉～毛頭小子，你只是被他的幻術給蒙蔽了心靈，不過，強大的幻術催眠，也會讓人變成廢物...\n",
	"幻術催眠":"沒錯，那個白骨精只是用幻術催眠，讓你自認為武功\盡失，還是有方法可以恢復，不過...\n",
	"恢復":"在海神廟裡，有幾朵不為人知的藥材花草，你先到海神廟裡去找裡面的住持，說我叫去你的就行了！\n",
	"海神廟":"自己找啊～年輕人這麼沒腦袋，頭腦都長在嘴巴上啊！\n",
	]));
	set("age",32);
	set("str",20);
	set("int",10);
	set("combat_exp",1);
	setup();
}

void greeting(object me)
{
	if(!me || environment(me)!=environment() || !me->query("/area/underpass/leave") ) return ;
	say("夢婆哼了一聲！\n");
	say("夢婆說：又是一個「冤死鬼」來著...！\n");
}

int accept_object(object me,object obj)
{
	object ob;
	ob=this_object();
		
	if(obj->query("id")=="glass flower")
	{
		tell_object(me,"夢婆說：很好，再加上1顆鑽石當手工費！\n");
		me->set_temp("/area/forest/flower",1);
	}
	
	if(obj->query("id")=="diamond")
	{
		if(me->query_temp("/area/forest/flower"))
		{
			me->set("/area/forest/flower",1);
			tell_object(me,"夢婆說：這樣就行了...\n");
			tell_object(me,"夢婆說：再來你去山上山找某一個人，遇不遇的到，就看你的機緣了...\n");
			message_vision("你有種被愚弄的感覺\n",me);
		}
		else
			tell_object(me,"夢婆說：既然你送給我，我當然就收下來了...\n");
	}
	
	destruct(obj);
	return 1;
}
