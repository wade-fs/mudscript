// hp cmds
 
#include <ansi.h>
 
inherit F_CLEAN_UP;
 
int main(object me, string arg)
{
	object ob;
	mapping my;
	string status_desc="";
	 
	seteuid(getuid(me));
 
	if(!arg)
		ob = me;
	else if (wizardp(me)) {
		ob = present(arg, environment(me));
		if (!ob) ob = find_player(arg);
		if (!ob) ob = find_living(arg);
		if (!ob) return notify_fail("你要察看誰的狀態﹖\n");
        } else
                return notify_fail("只有巫師能察看別人的狀態。\n");


	my = ob->query_entire_dbase();

	printf(HIG+""+ob->name()+"目前的替身上限為"HIY"%d"HIG"個\n"HIC+
                      ""+ob->name()+"已經用掉的替身上限為"HIR"%d"HIC"個剩下"HIM"%d"HIC"個能用\n"HIW+
		      ""+ob->name()+"目前有"HIB"%d"HIW"個替身..\n"NOR+
          HIC"目前擂台賽勝場數剩餘可換替身數為 %d 個。\n"NOR,
		my["max_standby"],
		my["t_standby"],
		my["max_standby"] - my["t_standby"],
		my["standby"],
    (ob->query("pk_win") - ob->query("pk_convert")*50 )/50
    );
	
	return 1;
}
 
int help(object me)
{
	write(@HELP
指令格式 : ch-stdby
指令說明 : 
           這個指令可以顯示你(妳)目前替身的使用狀況
   其中最後一項目前擁有的替身數是已經算在已
   使用替身上限中..用掉他並不會增加已使用替
   身上限..而是當你換取替身時此數值才會增加
其他參考 :
          
HELP
    );
    return 1;
}
