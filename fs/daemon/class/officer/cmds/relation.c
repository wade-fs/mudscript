#include <ansi.h>
inherit F_GUILDCMDS;
string *status = ({
	HIR "你死我亡" NOR,
	HIR "水火不容" NOR,
	RED "意見不合" NOR,
	RED "印象不好" NOR,
	BLU "初探門路" NOR,
	HIB "些微交往" NOR,
	HIB "略有往來" NOR,
	CYN "交情尚可" NOR,
	CYN "往來頻繁" NOR,
	HIC "關係非凡" NOR,
	HIC "非比尋常" NOR,
	HIW "不可告人" NOR,
	});
string get_status(int value);
int main(object me,string arg)
{
	string msg;
	string *name;
	object ob;
	int i;
        if(!arg)
                ob = me;
        else{
		if(!wizardp(me))
			return notify_fail("只有巫師才能查看玩者的關係狀況。\n");
                ob = present(arg, environment(me));
                if (!ob) ob = find_player(arg);
                if (!ob) ob = find_living(arg);
		if (!ob) return notify_fail("你要察看誰的關係狀態 ?\n");
        }

	if(!ob->query("relation"))
		return notify_fail((ob==me ? "你":ob->name())+"並沒有和任何官員建立任何關係。\n");
	name=keys(ob->query("relation"));
msg = (ob==me ? "你" : ob->name() ) + "目前和各個官員之間的關係﹕\n\n";
	for(i=0;i<sizeof(ob->query("relation"));i++)
		msg+=sprintf("  %-45s- %10s - (%d)\n",
	ob->query("relation/"+name[i]+"/name")+"("+name[i]+")",
	get_status(ob->query("relation/"+name[i]+"/value")),
	ob->query("relation/"+name[i]+"/value"));
	msg+="\n";
	write(msg);
	return 1;
}
string get_status(int value)
{
	if(value>-40&&value<70) return status[value/10+4];
	else if(value>=70) return status[11];
	else return status[0];
}
int help(object me)
{
  write(@HELP
指令格式﹕ relation

說明﹕這個指令讓你可以查看你和其它官員間的關係。
HELP
  );	
  return 1;
}
