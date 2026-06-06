inherit NPC;
#include <ansi.h>
string flower();
string gress();
string build();

void create()
{
        set_name("海佬",({"hai lao","lao"}));
        set("long","海佬是掌管海神廟的住持，年齡已經上百歲了，發育卻像是不滿十歲的小孩子！\n");
        set("gender","男性");
        set("attitude","friendly");
        set("combat_exp",1);
        set("inquiry",([
        	"夢婆":"夢婆？你說的是「北家」的夢婆，還是「南家」的啊？\n",
        	"北家":"你說的是北家專門研究「花類」的夢婆嗎？\n",
        	"南家":"你說的是南家專門研究「草類」的夢婆嗎？\n",
        	"花類":(: flower :),
        	"草類":(: gress :),
        	"建築":(: build :),
        	]));
        set("max_gin",5000);
        set("max_kee",10000);
        set("max_sen",5000);
        set("max_force",10000);
        set("gin",5000);
        set("kee",10000);
        set("sen",5000);
        set("force",10000);
        set_temp("can_delete",1);
        set_temp("apply/armor", 100);
        set_temp("apply/defense", 100);
        set_temp("apply/damage", 100);
        set_temp("apply/attack", 100);
        set_skill("dodge",200);
        set_skill("move",200);
        set_skill("unarmed",100);
        set_skill("force",200);
        set("force_factor",30);
	set("no_kill",1);
	set("no_fight",1);
	setup();
}

string *war_msg=({
	"海佬說：這樣東西很珍貴，不可以隨便給你，不過如果你答應我一件事情，我倒是可以考慮免費送你...
海佬露出奸詐的笑臉。\n",
	"海佬說：最近野人們不曉得受誰的指揮，老是來我這兒打壞我好不容易建起來的圍牆。
海佬氣得跺腳！\n",
	"海佬說：只要你能幫我再將海神廟的圍牆再建築起來，我可以考慮看看免費送你，你所想要的東西，
海佬吃吃笑道。\n",
	"海佬說：不過，「建築」所花的費用嘛...就要你自己負擔囉～！
你心中不禁想著：真是個吃人不土骨頭的神仙... =_= \n",
});

string flower()
{
	int i,k;
	if(!this_player()->query_temp("/area/sea-temple/flower") && !this_player()->query_temp("/area/sea-temple/gress") )
	{
		tell_object(this_player()," 
海佬說：喔～那你是來跟我拿某樣東西囉？
海佬轉身思考了一下！\n");
		this_player()->set_temp("/area/sea-temple/flower",1);
		call_out("msg01",5,this_player(),0);
	}
return "";
}

string gress()
{
	int i,k;
	if(!this_player()->query_temp("/area/sea-temple/flower") && !this_player()->query_temp("/area/sea-temple/gress"))
	{
		tell_object(this_player()," 
海佬說：喔～那你是來跟我拿某樣東西囉？
海佬轉身思考了一下！\n");
		this_player()->set_temp("/area/sea-temple/gress",1);
		call_out("msg01",5,this_player(),0);
	}
return "";
}

void msg01(object me,int k)
{
	tell_object(this_player(),war_msg[k]);
	if( k++ < sizeof(war_msg))
		call_out("msg01",3,this_player(),k);
}

string build()
{
	if(this_player()->query_temp("/area/sea-temple/flower") || this_player()->query_temp("/area/sea-temple/gress"))
	{
		tell_object(this_player(),"
海佬說：其實很簡單，只要你給我一顆鑽石，我就會給你一個海佬石！
海佬說：你只要拿著海佬石到要加強的圍牆，握住(hold)海佬石就可以了！
海佬說：這樣你的內力就會注入海佬石內，轉換出新的結界！自然圍牆就會慢慢修補起來！\n");
	}
return "";
}

int accept_object(object me,object obj)
{
	object ob;
	ob=this_object();
	
	if(obj->query("id")=="diamond")
	{
		if(this_player()->query_temp("/area/sea-temple/flower") || this_player()->query_temp("/area/sea-temple/gress"))
		{
			tell_object(me,"
海佬說：謝謝～這是海佬石，給你！
你接過了海佬石。
海佬說：對了，差點忘了提醒你，如果在無法修復或是已經修復完畢的地方，繼續修復的話！
海佬說：海佬石會因為能量無法消替而壞掉喔！要小心使用啊！
海佬說：還有，依你現在的實力，千萬別跟野人們打！我可不想你還沒幫我建好就掛了！
海佬嘻嘻的笑著。
海佬說：要出去的話，在觸碰(touch)一下鏡面就可以出去了。\n");
			new(__DIR__"stone")->move(this_player());
		}
		else
			tell_object(me,"海佬說：給我？那我就收下來囉！\n");
	}
	
	destruct(obj);
	return 1;
}

void greeting(object ob)
{
	object item;
	if(!ob || environment(ob)!=environment() || ob->query("/area/sea-temple/stone")<3 ) return ;
	say("海佬說：呵呵～辛苦你了，這是你要的東西，拿去吧！\n");
	if(this_player()->query_temp("/area/sea-temple/flower"))
		item=new("/open/area/forest/obj/flower");
	if(this_player()->query_temp("/area/sea-temple/gress"))
		item=new("/open/area/forest/obj/gress");
	say("你獲得了"+item->name(1)+"。\n");
	item->move(this_player());
	this_player()->delete("/area/sea-temple/stone");
}
