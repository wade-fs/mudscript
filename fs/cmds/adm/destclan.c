// destclan.c by acky 06.22.00

#include <ansi.h>

inherit F_CLEAN_UP;

int main( object me, string clan_id )
{
	int	i, n;
	string	player_id, *dir, *player;
	object	ob, ob_temp;

	if( !clan_id )
		return notify_fail("您要滅掉那一個幫派?\n");

	if( wiz_level(me)<6 )
		return notify_fail("您沒有滅幫的權利。\n");

	if( !CLAN_D->have_clan( clan_id ) )
		return notify_fail("無此幫派。\n");

	CHANNEL_D->do_channel( me, "mud", HIR + "\n忽然一道黑色火焰呼嘯著衝上雲端...\n" + NOR );
/*
	直接處裡玩家資料, 但所費時間滿長的, 有必要時才使用!
	dir = get_dir( "/data/login/" );
	i = sizeof(dir);
	while(i--) {
		write( dir[i] );
		player = get_dir( "/data/login/" + dir[i] + "/" );
		n    = sizeof( player );
		while(n--) {
			reset_eval_cost();
			if( sscanf( player[n], "%s.o", player_id ) !=1 )
				continue;
			if( !ob = FINGER_D->acquire_login_ob( player_id ) )
				continue;				
			if( !ob = find_player( player_id ) ) {
				ob_temp = "/adm/daemons/cappointd.c" -> get_user_ob( player_id );
				ob      = "/adm/daemons/cappointd.c" -> get_user_body( ob_temp );
				ob      -> set_temp( "link_ob", ob_temp );
				ob      -> setup();
			}
			if( ob->query("clan/id") == clan_id ) {
				ob -> delete( "clan" );
				ob -> save();
			}
			if( !find_player( player_id ) )
				destruct(ob);
		}
        }
*/
	"/adm/daemons/arthurd"->remove_all_dir( "/open/clan/" + clan_id );
	call_out( "step2", 5, me, clan_id );
	return 1;
}

void step2( object me, string clan_id )
{
	CHANNEL_D->do_channel( me, "mud", sprintf( 
	     HIR + "\n天上突然傳來震耳欲聾的聲音, %s喊道:\n\n" +
		"\t\t哼! 無知的%s, 全部通通給我下地獄去吧!\n\n" + NOR,
		me->query("name"), CLAN_D->clan_query( clan_id, "name" ) ) );
	call_out( "step3", 5, me, clan_id );
}

void step3( object me, string clan_id )
{
	CHANNEL_D->do_channel( me, "mud", sprintf( 
	     HIB + "\n【%s】受到" + HIW + "天譴" + HIB + ", 消失於狂想空間。\n\n" + NOR,
		CLAN_D->clan_query( clan_id, "name" ) ) );
	log_file( "clan/DESTCLAN", sprintf( "%s %s(%s)將【%s】徹底毀滅。\n",
		ctime(time()), me->query("name"), me->query("id"), CLAN_D->clan_query( clan_id, "name" ) ) );
	CLAN_D->dest_clan( clan_id );
}

int help( object me )
{
	write("
	destclan <幫派英文名稱>: 毀滅某個幫派。

						by ACKY 2000/06/22\n");
        return 1;
}

