// by ACKY 04/03/00

#include <ansi.h>
inherit F_CLEAN_UP;
int help( object me );
int main( object me,string str )
{
	int num,value,num1;
	if( !str )
		return notify_fail("指令格式：cset_gatetax <黃金>\n");
	if( me->query("clan/rank") > 3 )
		return notify_fail("您無權使用此指令。\n");
    num = atoi(str);
    if( num < 0 )
		return notify_fail("關稅不能是負的。\n");
	CLAN_D->clan_set(me->query("clan/id"),"gatetax",num);
	CHANNEL_D->do_channel(me, "ct",
		"\n\t我 -「"HIW+me->query("clan/title")+HIY"」鄭重的宣佈……\n\t本幫關稅調為"+
		CHINESE_D->chinese_number(num)+"兩黃金，\n\t稅收將收入幫派錢莊，作為壯大本幫之用。"NOR);
    return 1;
}

int help( object me )

{
    write(@HELP

	cset_gatetax <黃金>

	設定幫派關稅，收取過關所需之費用，以壯大幫派。
	
HELP
    );
 return 1;
}

