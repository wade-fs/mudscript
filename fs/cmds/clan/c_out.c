// c_out.c by ACKY

#include <ansi.h>
#include <login.h>

inherit F_CLEAN_UP;

int main( object me )
{
	int i;
	object from, *count;
	string filep, gate;

	seteuid(getuid());
	filep = me->query("clan/out");
    if(!filep) filep="/open/common/room/inn.c";
	if( !me->query("clan") )
		return 0;
	if( me->is_fighting() )
		return notify_fail( "您正忙於戰鬥！！\n" );
	if( CLAN_D->what_clan_area(me) == "NULL" )
		return notify_fail( "此處並非幫派區域。\n" );
	gate = CLAN_D->clan_query( CLAN_D->what_clan_area(me), "gate" );
	if( base_name(environment(me)) == CLAN_D->clan_query( me->query("clan/id"), "jail" ) )
		return notify_fail( "幫派監獄是逃不出去的。\n" );
	if( !CLAN_D->is_clan_room(me) )	{
		if( file_name(environment(me)) != gate )
			return notify_fail( "此處並非幫派閘門。\n" );
	}
	else if( me->query("clan/rank") > 4 )
		if( file_name(environment(me)) != gate )
			return notify_fail( "此處並非幫派閘門。\n" );
	from = environment(me);
	message_vision( HIY + "$N運勁全身, 使出絕世輕功\, 向" + HIC + trans_color(filep->query("short")) + HIY + "飛奔而去。\n" + NOR, me );
	me->move(filep);
	tell_room( filep, HIW + "一道人影！！閃了過去！！"+me->query("name")+"突然出現在眼前……\n" + NOR, me );
/*	if( me->query("clan/rank") < 5 &&
		base_name(from)==CLAN_D->clan_query(me->query("clan/id"), "gate" ) &&
		filep->query("no_transmit")!=1 ) {
		count = all_inventory(from);
		i = sizeof( count );
		while(i--) {
			if( !count[i]->is_fighting() &&
				living(count[i]) &&
				count[i]->query_leader()==me &&
				count[i]->query("clan/out")->query("no_transmit")!=1 ) {
				message_vision( HIY + "$N運勁全身, 使出絕世輕功\, 尾隨" + me->query("name") + "飛奔而去。\n" + NOR, count[i] );
				count[i]->move(filep);
				count[i]->set( "food", 0 );
				count[i]->start_busy(random(20)+1);
				tell_room( filep, HIW + "一道人影！！閃了過去！！"+count[i]->query("name")+"突然出現在眼前……\n" + NOR, count[i] );
			}
		}   
	} */
	return 1;
}

int help( object me )
{
	write("
	c_out: 離開幫派。

	       階級五以下: 限制於幫派閘門才能離開。

	       階級四以上: 可於幫派閘門帶領幫眾離開。

							by ACKY 2000/02/23

");
        return 1;
}
