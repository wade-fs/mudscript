// c_banish.c 將幫眾逐出幫派
#include <ansi.h>

inherit F_CLEAN_UP;

int help(object me);
int check_aviable(object me,string id)
{
	string clan ;
	
	clan = me->query("clan/id");
	
	CLAN_D-> clan_promote(clan,id,"banish",0);
}
int main( object me, string id )
{
	mapping clans;
	object  ob, user;
	string clan_id;

	if( !me->query("clan" ) )
		return notify_fail( "您沒有加入任何幫派。\n" );
	if( !id )
		return notify_fail( "請問您想將誰逐出幫派?\n" );
	if( me->query("clan/rank" ) > 3 )
		return notify_fail( "您無權使用此指令。\n" );
	if( me->query("id" ) == id )
		return notify_fail( "無法自行將自己逐出幫派。\n" );

	clans = CLAN_D->query_all_clans();
	clan_id = me->query("clan/id");

	if( !user = FINGER_D->acquire_login_ob( id ) ){
		check_aviable(me,id);
		return notify_fail( "無此人。\n" );
	}
	if( wizardp(user))  // cgy 只改自己的?真自私..-.- by avgirl
	    return 0;
	if( !user = find_player( id ) ) {
		ob   = "/adm/daemons/cappointd.c" -> get_user_ob( id );
		user = "/adm/daemons/cappointd.c" -> get_user_body( ob );
		user -> set_temp( "link_ob", ob );
		user -> setup();
if(sizeof(all_inventory(user))) all_inventory(user)->set("autoload",1);
	}

	if( user->query("clan/id") != clan_id ){
		check_aviable(me,id);
		return notify_fail( "此人並非貴幫之幫眾。\n" );
	}
	if( me -> query( "clan/rank" ) >= user -> query( "clan/rank" ) )
		return notify_fail( "只能將位階比您低的幫眾逐出。\n" );
	CHANNEL_D->do_channel(me, "ct",
		"\n\t我 -「"HIW+me->query("clan/title")+HIY"」遺憾地宣佈……\n\t將"+
		HIR+ user->query("name")+HIY"("HIR+user->query("id")+HIY")逐出"+me->query("clan/name")+"。"NOR);
	CLAN_D->clan_promote( clan_id, user->query("id"), "banish", user->query("clan/bank") );
	user -> delete( "clan" );
	user -> save();
	log_file("clan/cbanish", sprintf("[%s] %s cbanish <%s> .\n",
ctime(time())[0..15], me->query("id"),user->query("id")));
	if( !find_player( id ) )
		destruct(user);
	return 1;
}

int help( object me )
{
	write("
	c_banish <ID>：將某人逐出幫派。

	   	       只能逐出位階比您低的幫眾。

						by ACKY 2000/03/28
");
        return 1;
}
