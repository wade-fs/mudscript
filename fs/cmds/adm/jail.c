// jail.c
#include <ansi.h>
#define JAIL_ROOM "/open/wiz/jail.c"

int main(object me, string arg)
{
	object ob;
	string player,reason;
	int days;

	//seteuid(getuid());

	if (!arg) return notify_fail("<Syntax>: jail <使用者id> <時間> because <原因>\n");

	if( sscanf(arg, "%s %d because %s", player, days, reason)!=3 ) {
		return notify_fail("<Syntax>: jail <使用者id> <時間> because <原因>\n");
	}
	if (days<=0) days=1;

	if ( ! (ob = find_player(player)) )
		return notify_fail("咦... 有這個人嗎?\n");
	tell_room(environment(ob),"天空中伸出一隻大手把"+
		(string)ob->query("name")+"抓了起來, 然後不見了.\n", ob);
	tell_object(ob,"一隻手把你抓了起來, 你眼前一陣黑....\n");
	ob->move(JAIL_ROOM);
	ob->set("startroom", base_name(environment(ob)));
	message("system",HIY + "\t\t"+(string)ob->query("name")+" 因為 "+
		reason + " 被 "+
		(string)me->query("name")+" 抓去關到監牢關"+days+"天\n" + NOR,users());
	log_file("JAIL",sprintf("%s 因為 %s 關 %s(%s) %d天 於%s\n",
	me->name(1), reason,ob->name(1), geteuid(ob), days, ctime(time()) ) );

        ob->set("tmp_title", ob->query("title"));
       ob->set("title",HIG + "犯了" + HIR + "[" + HIW+reason+HIR + "]" + HIG + "的犯人" + NOR);
	tell_object(me, "你把"+(string)ob->query("name")+"抓到監牢關起來.\n");
	tell_object(ob,".... 醒來時發現是"+(string)me->query("name")+
		"把你關到監牢.\n");
	tell_room(environment(ob),(string)ob->query("name")+"突然出現"+
		"在你眼前\n",({me,ob}));
	//ob->set("out_jail_time",ob->query("mud_age")+days*60*1);//一天86400分
	ob->set("jail_time",ob->query("mud_age")+days*60*60*24);//一天86400分
	ob->save();
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式﹕jail <使用者id> <時間> because <原因>

把不乖的 user 關起來。
HELP
	);
	return 1;
}
