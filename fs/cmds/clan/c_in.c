// c_in.c by ACKY 05/24/00

inherit F_CLEAN_UP;

#include <ansi.h>

int clan_ally( string clan_id, string clan )
{
	string *ally;

	ally = CLAN_D->clan_query( clan, "ally" );

	if( !ally ) {
		write( "貴幫目前並沒有與此幫會結盟。\n" );
       		return 0;
	}

	if( member_array( clan_id, ally ) == -1 ) {
		write( "貴幫目前並沒有與此幫會結盟。\n" );
       		return 0;
       	}
       	else
       		return 1;
}

int main( object me, string clan )
{
        string clan_id;
        int num, war, level, gate;
        object to, from;

        if( !clan )
                return notify_fail("您想到哪裡去?\n");
	if( !CLAN_D->have_clan( clan ) )
		return notify_fail( "無此幫派。\n" );
	if( me->is_fighting() || me->is_ghost() || me->query_temp("pk_fight") )
		return notify_fail( "很抱歉, 你現在的情況不能使用這個指令。\n" );
    if( environment(me)->query("no_transmit") || environment(me)->query("no_chome"))
		return notify_fail( "這個地方不能用此功\能喔......。\n" );
	if( base_name(environment(me)) == CLAN_D->clan_query( me->query("clan/id"), "jail" ) )
		return notify_fail( "幫派監獄是逃不出去的。\n" );

	to = CLAN_D->clan_query( clan , "gate" );
	gate = CLAN_D->clan_query( clan , "gate_level" );
	clan_id = me->query("clan/id");

	if( clan_id == clan )
		level = 2;
	else if( clan_ally( clan_id, clan ) )
		level = 3;
	else
		level = 4;
	if( level > gate && !wizardp(me) )
		return notify_fail("所要前往的幫派不允許\你進入。\n");
	if( environment(me)->query("no_transmit") ) {
		if( me->query("food") < 200 )
			return notify_fail( "餓得全身無力, 動不了了。\n" );
		me->add( "food", -200 );
	}
	else {
		if( me->query("food") > 50 )
			me->add( "food", -50 );
		else
			return notify_fail( "餓得全身無力, 動不了了。\n" );
	}
	message_vision( HIY + "$N使出卓絕的輕功\, 向" + HIC +
		( to ? trans_color( to->short() ) : CLAN_D->clan_query( clan , "name" ) )
		+ HIY + "直奔而去。\n" + NOR, me );
	from = environment(me);
	if( CLAN_D->what_clan_area(me)== "NULL" )
		me->set( "clan/out", file_name(from) );
	me->move(to);
	tell_room( to, HIC + "一道強風襲來！！" + me->query("name") + "的身影突然出現。\n" + NOR, me );
	war = CLAN_D->clan_query( clan , "war" );
	if( !war ) {
		num = CLAN_D->clan_query( clan , "gatetax");
                if( me->query("clan/id") != clan )      {
                        if( me->query("bank/coin") < num*10000 && !wizardp(me) ){
                                message_vision(HIY + "幫派閘門守衛說道：沒錢還敢來？！\n" + NOR,me);
                                message_vision(NOR + "幫派閘門守衛運勁用力一踢，$N被踢得又高又遠～～\n" + NOR,me);
                                me->move(from);
                                message_vision(HIR + "$N突然從天上墬了下來！！！\n" + NOR,me);

                                return 1;
                        }
                        if( !wizardp(me) )      {
                                me->add("bank/coin",-num*10000);
                                CLAN_D->add_money( clan , num );
                        }
                        message_vision(HIY + "幫派閘門守衛向$N收取關稅"+CHINESE_D->chinese_number(num)+"兩黃金。\n" + NOR,me);
                }
        }

        return 1;
}

int help( object me )
{
        write( "
	c_in <幫派英文名稱>: 移動到某幫派之閘門。

                                        by ACKY 05/24/2000
");
	return 1;

}
