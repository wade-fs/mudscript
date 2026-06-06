inherit ITEM;
#include <ansi.h>

void create()
{
	set_name("武林帖",({"paper"}));
	set_weight(10);
	if(clonep())
		set_default_object(__FILE__);
	else
	{
		set("value",10);
		set("unit","張");
		set("long","
這是一張武林帖，你可以藉由千里傳信(send)寄給別人簽署。\n");
	}
	setup();
}

void init()
{
add_action("do_send","send");
add_action("do_sign","sign");
}

int do_send(string arg)
{
object me,ob,target;
int j;
	me=this_player();
	ob=this_object();
	if(!arg)
		return 0;
	if(ob->query_temp("paper_owner")!=me->query("id"))
		return notify_fail("你無法使用這張帖子。\n");
	if((int)ob->query_temp("paper_count_times") > 5)
		return notify_fail("你心想：簽署人數已經夠了。\n");
	for(j=1;j<7;j++)
		if(ob->query_temp("sign_id_"+j)==arg)
			return notify_fail("已經簽署過的人無法再度簽署。\n");		
	target = find_player(arg);
	if(!target)
		return notify_fail("此人目前不在線上。\n");
	if(me->query("id")==arg)
		return notify_fail("武林帖無法自己簽署。\n");
	message_vision(HIY"$N將手中的武林帖寄給了$n。\n"NOR,me,target);
	ob->set_temp("paper_send",arg);
	ob->set("long","
這是一張由"+me->query("name")+"所寄來的武林帖。

裡面寫著：

	如果你認為 "+me->query("name")+" 夠資格闖〔震邪道〕的話

		請簽上(sign)你的大名。\n
");
	ob->move(target);
	tell_object(target,HIR"\n\n你收到了一張武林帖。\n"NOR);
return 1;
}
	
int do_sign(string arg)
{
object me,ob,target;
string owner,word;
int i,j,count;
	me=this_player();
	ob=this_object();
	owner=ob->query_temp("paper_owner");
	count=(int)ob->query_temp("paper_count");
	if(me->query("id")!=ob->query_temp("paper_send"))
		return notify_fail("你無法簽署這份武林帖。\n");
	if(arg!=me->query("id"))
		return notify_fail("你簽錯了名字。\n");
	message_vision(HIW"$N簽署了武林帖後，武林帖隨即飛離$N的手中。\n"NOR,me);
	target = find_player(owner);
	if(!target)
	{
		message_vision("武林帖似乎無法回到主人的手上，一瞬間，燃起熊熊烈火，燒毀了～\n",me);
		destruct(ob);
		return 0;
	}
	ob->delete_temp("paper_send");
	ob->add_temp("paper_count_times",1);
	j=(int)ob->query_temp("paper_count_times");
	ob->set_temp("sign_name_"+j,me->query("name"));
	ob->set_temp("sign_id_"+j,me->query("id"));
	if(j==0)
		word = "\n";
	word = "簽署名單如下：\n";
	for(i=1;i<7;i++)
		if(ob->query_temp("sign_name_"+i))
			word = word + " "+ob->query_temp("sign_name_"+i)+"("+ob->query_temp("sign_id_"+i)+") \n";
	ob->set("long","
這是一張武林帖，你可以藉由千里傳信(send)寄給別人簽署。

目前有： "+ob->query_temp("paper_count_times")+" 人同意簽署。

"+word+"\n");

	ob->move(target);
	tell_object(target,HIY"武林帖再度的回到你的手中。\n"NOR);
return 1;
}
