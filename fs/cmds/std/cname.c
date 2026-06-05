// cname.c

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
  string tmp;

  if (!arg) return notify_fail("你要替自己取什麼名字﹖\n");
//  if (arg=="傅劍寒") return notify_fail("你不能取這個名字");
//  tmp = remove_color (arg);
	if( strlen(arg) > 14 )
	return notify_fail("你的名字真像老太婆的裹腳布﹐想一個短一點的、響亮一點的。\n");
//更動扣玩家身上的錢來支付更名費用 by Neverend
//if( me->query("bank/coin") < 100000000 )
if( !me->pay_money(1000000) )
return notify_fail(" 你的存款不足,無法支付費用.\n");
/*
// 應該能取消綽號吧... edit by lys
	if (arg == "none") {
		me->delete("nickname");
		write ("你的綽號取消了.\n");
		return 1; 
	}
*/

  //      arg = trans_color(arg);

	me->set("name", arg );
write("你花了"+CHINESE_D->cvalue(1000000)+"的代價改名為"+me->name()+"\n");
//	me->add("bank/coin", -100000000);
	tell_object(users(),HIW + "【系統】" + HIC+me->query("id")+HIW + "由現在起改名為" + HIG+me->name()+"。\n" + NOR);
	log_file("cname",sprintf("%s改名為%s於%s\n",
        me->query("id"),me->query("name"),ctime(time())));
	return 1;
}

int help(object me)
{
        write(@HELP
指令格式 : cname <自己的名字>
指令說明 :
           這個指令可以讓你為自己取一個響亮的名字。
一次需耗費一張萬倆銀票,請使用中文命名違者砍檔..

HELP
        );
        return 1;
}
