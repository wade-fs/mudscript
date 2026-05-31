// c_set.c by ACKY
#include <ansi.h>
#include <clanf.h>
string msg;

int main( object me )
{
	if( !me->query("clan") ) return 0;
	if( me->query("clan/rank") > 2 )
		return notify_fail( "您無權使用此指令。\n" );
	if( !CLAN_D->is_clan_room(me) )
		return notify_fail( "此區域並非本幫之地盤。\n" );

	msg = "
	[0] 放棄設定
	[1] 幫派錢莊
	[2] 幫派兵營
	[3] 幫派閘門
	[4] 幫派核心
	[5] 幫派監獄

	欲將此區域設為? [0~5] : ";

	write(msg);
	input_to( "ask", 0, me );

	return 1;
}

void ask( string arg, object me )
{
	int  n;

	if( sscanf( arg, "%d", n )!=1 || n<0 || n>5 ) {
		tell_object( me, CLR );
		write(msg);
		input_to( "ask", 0, me );
		return;
	}

	switch( n ) {
	case 0 :
		return;
	case 1 :
		arg = "bank";
		msg = "錢莊";
		break;
	case 2 :
		arg = "npc_room";
		msg = "兵營";
		break;
	case 3 :
		arg = "gate";
		msg = "閘門";
		break;
	case 4 :
		arg = "home";
		msg = "核心";
		C_ROOM->update_room( CLAN_D->clan_query( me->query("clan/id"), "home" ) );
		CLAN_D->clan_set( me->query("clan/id"), arg, base_name(environment(me)) );
		C_ROOM->update_keep( "/open/clan/" + me->query("clan/id") + "/room/hall" );
		break;
	case 5 :
		arg = "jail";
		msg = "監獄";
	}

	CLAN_D->clan_set( me->query("clan/id"), arg, base_name(environment(me)) );
	CHANNEL_D->do_channel( me, "ct",
			"\n\t我 -「"HIW + me->query("clan/title") + HIY"」鄭重的宣佈……\n\t" +
			"將本幫之"HIG + msg + HIY"設於"HIC + environment(me)->short() + HIY"。"NOR );
}

int help( object me )
{
	write( "
	c_set: 設定幫派區域。

                                                         by ACKY 2000/08/17
" );
	return 1;
}

