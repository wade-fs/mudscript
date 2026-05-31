#include <ansi.h>
inherit F_CLEAN_UP;

string *status = ({
        BLU "初學乍練" NOR,
        HIB "粗通皮毛" NOR,
        HIB "半生不熟" NOR,
        HIB "馬馬虎虎" NOR,
        HIB "駕輕就熟" NOR,
        CYN "出類拔萃" NOR,
        CYN "神乎其技" NOR,
        CYN "出神入化" NOR,
        HIC "登峰造極" NOR,
        HIC "一代宗師" NOR,
        HIW "深不可測" NOR
	});
string get_status(int value);

varargs int main( object me, string arg, int mode )
{
	string msg;
	string *name;
	object ob;
	int i;
        if(!arg)
                ob = me;
        else{		
              	ob = present(arg, environment(me));
                if(wizardp(me)) {
		  if (!ob) ob = find_player(arg);
                  if (!ob) ob = find_living(arg);
		  if (!ob) ob = me;
                }
	  if( !ob && !wizardp(me) ) return notify_fail("這裡沒這個人。\n");

	}

	if ( ob!=me && !wizardp(me) && !ob->is_apprentice_of(me) &&
		!ob->query("guild_master") &&
		!me->is_apprentice_of(ob) )
	{
	  return notify_fail("只有巫師或有師徒關係的人能察看他人的技能。\n");
	}
	
	if( mode==1 )	
		ob = me->query_temp("pal");

	if(!ob->query("spells"))
		return notify_fail((ob==me ? "你" : ob->name())+"目前並沒有學會任何法術。\n");
	name=keys(ob->query("spells"));
	msg= ob->name()+"\n目前法術一覽表-------------------------------------------------------------\n\n";
	for(i=0;i<sizeof(name);i++)
		msg+=sprintf("[ %3d]%-40s熟練度 :%5d    - %10s -\n",
	ob->query("spells/"+name[i]+"/level"),
	to_chinese(name[i])+"("+name[i]+")",
	ob->query("spells/"+name[i]+"/learned"),
	get_status(ob->query("spells/"+name[i]+"/level")));
	
	msg+="\n";
	write(msg);
	return 1;
}
string get_status(int value)
{
        if(value > 100) return status[10];
        return status[value/10];
}
int help()
{
write(@HELP
指令格式 : spells
指令說明 :
           這個指令用來查詢你學會的法術。
HELP);
	return 1;
}
