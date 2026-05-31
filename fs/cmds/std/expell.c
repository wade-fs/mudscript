// expell.c

#include <skill.h>

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

int main(object me, string arg)
{
	object ob;
	string *skname;
	mapping skills;
	int i;

	if( !arg || !ob = present(lower_case(arg), environment(me)) )
		return notify_fail("你要將誰逐出師門﹖\n");

	if( !ob->is_character() )
		return notify_fail("你要開革「誰」﹖\n");

	if( !userp(ob) )
		return notify_fail("你只能開革玩家所扮演的人物。\n");

	if( me->query("family/privs")==-1
	&&	(string)me->query("family/family_name")==(string)ob->query("family/family_name") ) {
		message_vision("\n$N對著$n說道﹕從今天起﹐你再也不是我"
			+ me->query("family/family_name") + "的弟子了﹐你走吧﹗\n\n",
			me, ob);
		tell_object(ob, "\n你被" + me->query("family/title") + "開革出師門了﹗\n\n");
	} else if( ob->is_apprentice_of(me) ) {
		message_vision("\n$N對著$n說道﹕從今天起﹐你我師徒恩斷情絕﹐你走吧﹗\n\n",
			me, ob);
		tell_object(ob, "\n你被師父開革出師門了﹗\n\n");
	} else
		return notify_fail("這個人不是你的弟子。\n");

	if( me->query("人際關係/"+ob->query("id"))) me->delete("人際關係/"+ob->query("id"));
        if( ob->query("人際關係/"+me->query("id"))) ob->delete("人際關係/"+me->query("id"));
        log_file("apprentice",sprintf("%s(%s)被%s的%s(%s)逐出師門於%s\n",ob->name(1),ob->query("id"),me->query("family/family_name"),me->name(1),me->query("id"),ctime(time())));
        ob->delete("family");
	ob->delete("title");
	ob->set("score", 0);
	skills = ob->query_skills();

	if( mapp(skills) ) {
		skname = keys(skills);
		for(i=0; i<sizeof(skname); i++)
			skills[skname[i]] /= 2;
	}

	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : expell <某人>
指令說明 : 
           這個指令可以讓你開除不成才的弟子﹐被開除的
         弟子所有技能都會降到原來的一半﹐請你在開除一
         名弟子之前務必審慎考慮。
HELP
	);
	return 1;
}
