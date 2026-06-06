inherit NPC;
#include <ansi.h>

void create()
{
	set_name(HIY"黃金守衛"NOR,({"golden guard","guard"}));
	set("long","
長久以來被眾神派首著震邪道的聖物聖靈, 由於身處震邪道的要道,
故被眾神賦予掌管所有弱勢生物的生殺大權, 你有一種直覺, 除非你
不想活了, 不然你絕對不會去挑戰他的能力...\n");
        set("gender", "男性" );
	set("combat_exp",1000000);
	set("age",10000);
	set("max_kee",10000);
	set("max_sen",10000);
	set("max_gin",10000);
	set("chat_chance",10);
	set("unarmed",100);
	set("dodge",100);
	set("force",100);
	set("parry",100);
	set("chat_msg",({
"黃金守衛：除非你有黃金印，否則別想通過～!!\n",
}));
	setup();
}

int accept_object(object me,object ob)
{
	object obj=this_object();
	me=this_player();
	if(ob->query("id")!="golden seal")
	{
		message_vision("
$N大喝一聲：破～!!"+ob->query("name")+"一瞬間化成一堆金沙，飛散四處。\n
$N大怒道：這不是我要的東西～!!\n",obj);
		destruct(ob);
		return 0;
	}
	if(!me->query_temp("evil/g_enter"))
	{
		message_vision("
$N大喝一聲：破～!!"+ob->query("name")+"一瞬間化成一堆金沙，飛散四處。\n
$N大怒道：這東西要靠自己的實力拿到!!\n",obj);
		destruct(ob);
		return 0;
	}
	message_vision("
$N全身閃耀著金光～

$n恭恭敬敬的迎接$N，護送$N進入黃金門後，隨即又將門關上～\n",me,obj);
	me->move("/u/f/firedancer/evil-area/e06");
	destruct(ob);
	return 1;
}


void die()
{
object me,ob,obj;
	ob=this_object();
	obj=new(__DIR__"golden_guard");
	me=ob->query_temp("last_damage_from");
	message_vision(HIR"
\n黃金守衛大怒：我乃管理著震邪道的〔聖靈〕-圖妥，$N膽敢冒犯我！！去死吧！！\n\n"NOR,me);
	message_vision(HIW"$N化氣成物，手中聚氣為刀，一把極其鋒利的黃金大刀挾器而來！\n
$N大喊：看我的～〔雄霸氣皇〕～
$N手持黃金大刀直撲你的心臟，你閃躲不及，接連承受了好幾刀!!\n"NOR,ob);
	me->receive_wood("kee",(int)me->query("kee")/2);
	COMBAT_D->report_status(me,1);
	COMBAT_D->report_status(me,1);
	COMBAT_D->report_status(me,1);
	message_vision(HIY"
$N再一個轉身，手持黃金大刀再度直撲你的頭部，你閃躲不及，生命已經命在旦夕!!\n"NOR,ob);
	me->set("kee",1);
	me->set("max_kee",1);
	COMBAT_D->report_status(me,1);
	COMBAT_D->report_status(me,1);
	COMBAT_D->report_status(me,1);
	message_vision(HIR"
$N瞬間高舉黃金大刀，狠狠的往你的頸部一橫劈。\n"NOR,ob);
	me->die();
	obj->move(environment(ob));
	destruct(ob);
}
