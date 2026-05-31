#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me)
{
	object ob;
seteuid(getuid());
	if( !CLAN_D->clan_query( me->query("clan/id"), "home" ) )
		return notify_fail( "您想到哪裡去?\n" );
	if( userp(me) && me->query("clan/rank") > 4 )
		return notify_fail( "您無權使用此指令。\n" );
	if( environment(me)->query("no_chome") )
	    return notify_fail( "這個地方不能用這個指令。\n");
	if( me->is_fighting() || me->is_ghost() || me->query_temp("pk_fight") )
		return notify_fail( "很抱歉, 你現在的情況不能使用這個指令。\n" );
	if( CLAN_D->what_clan_area(me)== "NULL" )
		me->set( "clan/out", file_name(environment(me)) );
	if( environment(me)->query("no_transmit") ) {
		if( me->query("food") < 200 )
			return notify_fail( "餓得全身無力, 動不了了。\n" );
        if(!wizardp(me)) //sorry,我不想一直full
		me->add( "food", -200 );
	}
	else {
        if(!wizardp(me)) //sorry,我不想一直full
		if( me->query("food") > 50 )
			me->add( "food", -50 );
		else
			return notify_fail( "餓得全身無力, 動不了了。\n" );
	}
	ob = CLAN_D->clan_query( me->query("clan/id"), "home" );
	message_vision( HIY"$N使出卓絕的輕功\, 向"HIC + trans_color(ob->query("short")) + HIY"直奔而去。\n"NOR, me );
	me->move(ob);
	tell_room( ob, HIC"一道強風襲來！！" + me->query("name") + "的身影突然出現。\n"NOR, me );
	return 1;
}

int help(object me)
{
	write(@HELP

格式說明: c_home

 	  回到幫派核心。

HELP    );
        return 1;
}
