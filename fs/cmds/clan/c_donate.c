// 幫派捐錢指令 by ACKY
// 將存在幫派錢莊的錢, 捐給幫派

#include <limit.h>
#include <ansi.h>

inherit F_CLEAN_UP;

int help( object me );
int main( object me, string arg )
{
	int o, i, num, count, scale;
	string clan_id, m;

	if( !arg )
		return help( me );

	if( !me->query("clan" ) )
		return notify_fail( "您沒有加入任何幫派。\n" );

	if( !CLAN_D->is_clan_room(me) )
		return notify_fail("此處並非貴幫之地盤。\n");

	clan_id = me->query("clan/id");

	if( file_name(environment(me)) != CLAN_D->clan_query( clan_id, "bank" ) )
		return notify_fail( "此處並非錢莊。\n" );

	num = atoi( arg );
	if( num < 1000 )
		return notify_fail("每項捐款至少要一仟兩黃金。\n");

	if( me->query("clan/bank") < num )
		return notify_fail("您在幫派錢莊內並沒有存那麼多錢。\n");

	i = me->query("combat_exp");
	for( scale=0; i>0; scale++ )
		i-= (scale)*(scale)*50;
	count = num/scale;
//	if( me->query("net_count/count") > count )
//		me->add( "net_count/count" , -count );
//	else
//		me->set( "net_count/count" , 0 );

	me->add( "clan/bank"  , -num );
	me->add( "clan/donate",  num );
	CLAN_D->add_clanset( clan_id, "member_gold", -num );

	CHANNEL_D->do_channel(me, "ct",
		"\n\t我 -「" + HIW+me->query("clan/title")+HIY + "」捐出"+
		CHINESE_D->chinese_number(num)+"兩黃金給本幫，希望本幫能夠更加強大。" + NOR);
/*
	write( HIM + "\n一陣閃光, "+me->query("clan/name")+"守護神將您的可用流量提昇為 "+(MAX_KB-me->query("net_count/count"))+" KB。\n" + NOR);

*/
	sscanf (ctime (time()), "%s %s %d %d:%d:%d %d", m, m, o, o, o, o, o);
	log_file("clan/"+clan_id+"/DONATE-"+m, sprintf("%s%8d兩黃金 by %s(%s)\n"
		,ctime(time()),num,me->query("name"),me->query("id")));

	return 1;
}

int help( object me )
{
	write("
	c_donate <數量> : 捐錢給幫派，單位 : 黃金。

");
        return 1;
}

