// 幫派設定稅率指令 by Chan 05/12/99
// 修正稅率和時間 by ACKY

#include <ansi.h>
inherit F_CLEAN_UP;
int help( object me );
int main( object me,string str )
{
	int num,value,num1;
	if( !str )
		return notify_fail("指令格式：cset_tax <稅率>\n");
	if( me->query("clan/rank") > 2 )
		return notify_fail("您無權使用此指令。\n");
    num = atoi(str);
    if( num < 1 )
		return notify_fail("稅率不得低於1%。\n");
	if( num > 90 )
		return notify_fail("稅率不得高於90%。\n");
	CLAN_D->clan_set(me->query("clan/id"),"tax",num);
	CHANNEL_D->do_channel(me, "ct",
		"\n\t我 -「"HIW+me->query("clan/title")+HIY"」鄭重的宣佈……\n\t本幫稅率調為百分之"+
		CHINESE_D->chinese_number(num)+"，\n\t稅收將收入幫派錢莊，作為壯大本幫之用。"NOR);
    return 1;
}

int help( object me )

{
    write(@HELP

	cset_tax <稅率>

	設定幫派稅率(1~90)，

	定期每半個月收一次稅。
	
HELP
    );
 return 1;
}

