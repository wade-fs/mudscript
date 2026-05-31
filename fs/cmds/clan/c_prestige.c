// by ACKY
#include <ansi.h>
inherit F_CLEAN_UP;
int main( object me, string str )
{
	int num;
	if( me->query("clan/rank") > 3 )
		return notify_fail("您無權使用此指令。\n");
	if( !str )
		return notify_fail("指令格式：c_prestige <基金>\n");
	if( !CLAN_D->is_clan_room(me) )
		return notify_fail("此處並非貴幫之地盤。\n");
	num = atoi(str);
	if( num > 10 )
		return notify_fail("建立幫派威望的經費不得超過十萬兩黃金。\n");
	num = num*10000;
	if(CLAN_D->clan_query(me->query("clan/id"),"gold") < num)
		return notify_fail("目前幫內並無那麼多錢。\n");
	CLAN_D->clan_set(me->query("clan/id"),"prestige",num);
	CHANNEL_D->do_channel(me, "ct",
		"\n\t我 - "HIW+me->query("clan/title")+HIY
		"鄭重地宣佈\n\t將投注"HIC+CHINESE_D->chinese_number(num)+HIY"兩黃金, 用來建立本幫之威望。"NOR);
	return 1;
}

int help( object me )
{
	write(
"\n\tc_prestige: 設定用於建立幫派威望的經費。
\n\t單位: 萬兩黃金
\n\t幫派威望愈高, 能佔領的地盤愈大。\n\n"
	);
	return 1;
}
