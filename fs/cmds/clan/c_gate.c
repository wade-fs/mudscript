// c_gate.c

#include <ansi.h>

int help( object me );

int main( object me , string arg )
{
	int n;

	if( !me->query("clan") ) return 0;
	if( me->query("clan/rank") > 2 )
		return notify_fail( "您無權使用此指令。\n" );
	if( !CLAN_D->is_clan_room(me) )
		return notify_fail( "此處並非貴幫之地盤。\n" );
	if( !arg )
		return help(me);
	if( sscanf( arg, "%d", n )!=1 || n<1 || n>4 )
		return notify_fail( "狀態只能輸入(1~4)。\n" );

	switch( n ) {
	case 1:
		CHANNEL_D->do_channel( me, "ct",
			"\n\t我 -「" + HIW+me->query("clan/title")+HIY + "」鄭重的宣佈……\n\t" +
			"將本幫閘門警戒層級設為" + HIC + "[關閉]" + HIY + "，以防閒雜人等隨意進入。" + NOR );
		break;
	case 2:
		CHANNEL_D->do_channel( me, "ct",
			"\n\t我 -「" + HIW + me->query("clan/title") + HIY + "」鄭重的宣佈……\n\t" +
			"將本幫閘門警戒層級設為" + HIC + "[幫眾]" + HIY + "，只准許\本幫幫眾進出。" + NOR );
		break;
	case 3:
		CHANNEL_D->do_channel( me, "ct",
			"\n\t我 -「" + HIW + me->query("clan/title") + HIY + "」鄭重的宣佈……\n\t" +
			"將本幫閘門警戒層級設為" + HIC + "[盟友]" + HIY + "，讓盟友可自由進出，以便交流互通有無。\n" + NOR );
		break;
	case 4:
		CHANNEL_D->do_channel( me, "ct",
			"\n\t我 -「" + HIW + me->query("clan/title") + HIY + "」鄭重的宣佈……\n\t" +
			"將本幫閘門警戒層級設為" + HIC + "[開放]" + HIY + "，讓各幫各派可自由進出，以便交流互通有無。\n" + NOR);
		break;
	default :
	}

	CLAN_D->clan_set( me->query("clan/id"), "gate_level", n );

	return 1;
}

int help( object me )
{
	write("
	c_gate <狀態>: 設定幫派閘門狀態。

	[狀態１] 關閉
	[狀態２] 幫眾
	[狀態３] 盟友
	[狀態４] 開放

					by ACKY 2000/03/28
");
        return 1;
}
