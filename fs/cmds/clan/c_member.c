// c_member by ACKY 04/12/00

#include <ansi.h>

int main( object me, string arg )
{
	mapping clans;
	string *member, str, clan_id, char;
	object ob, user;
	int o, sum, time, now;
int bank;
	now = time();
	if( !me->query("clan" ) )
		return notify_fail( "您並無加入任何幫派。\n" );
	if( me->query("clan/rank" ) > 4 )
		return notify_fail( "您無權使用此指令。\n" );
	if( !arg )
		return notify_fail( "c_member <幫眾ID開頭字母(a~z)> <月(1~12)>\n" );
	if( sscanf( arg, "%s %d", char, time )!=2 || time<0 || time>12 )
		return notify_fail( "c_member <幫眾ID開頭字母(a~z)> <月(1~12)>\n" );
	clan_id = me->query("clan/id");
	clans = CLAN_D->query_all_clans();
	member = filter_array( clans[clan_id]["members"], "filter_id", this_object(), char );
	str = sprintf(HIC + "目前幫內總共有 %d 名幫眾, 其中ID為[%s]開頭的有 %d 名,\n打[*]號者代表已超過%s個月沒有上線 -\n"+
		HIM + "───────────────────────────────────────\n" + NOR,
		sizeof( CLAN_D->clan_query(clan_id,"members") ), char, sizeof( member ), CHINESE_D->chinese_number(time) );
	time *= 2592000;
	member = sort_array( member, "sort_keys", this_object() );
	sum = sizeof( member );
	for( o=0; o<sum; o++ )	{
        if( !user = FINGER_D->acquire_login_ob( member[o] ) ||(objectp(user) &&  wizardp(user) )) {
if(!user) bank=0; else bank=user->query("clan/bank");
             CLAN_D->clan_promote( clan_id, member[o], "banish",bank );
			continue;
		}
		str += sprintf(HIR + "%s" + HIW + "%-26s " + HIY + "捐過%9d兩黃金  " + HIC + "戰績%9d點" + NOR + "\n",( now-user->query("last_on")>time)?"[*]":"   ",
			user->name()+"("+user->query("id")+")", user->query("clan/donate"), user->query("clan/war") );
	}
	me->start_more( str );
	return 1;
}
int filter_id( string id , string first )
{
	if( id[0..0] == first )
		return 1;
	else
		return 0;
}

int sort_keys( string key1, string key2 )
{
	return strcmp( key1, key2 );
}

int help( object me )
{
	write("
	c_member <幫眾ID開頭字母(a~z)> <月(1~12)>：列出幫內幫眾名單。

						by ACKY 2000/04/12
");
        return 1;
}
