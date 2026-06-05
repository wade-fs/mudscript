#include <ansi.h>

inherit NPC;

int call_soldier(string call_class)
{
	object obj,me=this_player();
	string str;
	mapping call_need_lv=this_object()->query("soldier_lv");
	if(!call_need_lv[call_class])
		return notify_fail("沒有這種兵種。\n");
	if(me->query("officer_power")<call_need_lv[call_class])
		return notify_fail("你的權力不夠﹐無法招喚這種兵種。\n");
	if(this_object()->query("be-call")>10) 
		return notify_fail("現在兵員不足﹐新兵未到。\n");
	me->add("officer_power",-1*call_need_lv[call_class]);
	obj=new("obj/soldier/"+call_class);
	obj->move(environment(me));
	this_object()->add("be-call",1);
	obj->set_temp("id",me->query("id"));
	me->set_temp("p_"+obj->query("name"));
	obj->set_leader(me);
	str = obj->name();
	message_vision(
	CYN + "$N說道﹕我需要一名"+str+"﹐馬上給我辦妥。\n" + NOR+this_object()->name()+"立刻叫人去找人。\n"+
	"$n接到命令﹐急急忙忙的跑來這裡。\n"+
	CYN + "$n對著$N說道﹕大人 ! 有任何差遣﹐找小的就是。\n" + NOR,me,obj);
	obj->set("commander",me->query("id") );
	obj->set("name",me->name()+"的"+str);
	return 1;
}

int do_list()
{
	int i;
	mapping list;
	string *name;
    if(this_player()->query("class")!="officer" && !wizardp(this_player()))
		return 0;
	list=this_object()->query("soldier_list");
	name=keys(list);
tell_object(this_player(),"\n    "+this_object()->name()+"所掌管的部隊種類有﹕\n");
	for(i=0;i<sizeof(list);i++)
		tell_object(this_player(),"    "+list[name[i]]+"\n");
	return 1;
}

void init()
{
    add_action("do_list","view");
	add_action("call_soldier","callout");
}
